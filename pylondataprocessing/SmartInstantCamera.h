//-----------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2025 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Contains an instant camera class extension that uses a pylon data processing recipe as additional last processing stage.
*/
#pragma once
#include <pylon/PylonLinkage.h>
#include <pylon/Platform.h>
#include <pylon/stdinclude.h>
#include <pylon/InstantCamera.h>
#include <pylon/ThreadPriority.h>
#include <pylondataprocessing/AcquisitionMode.h>
#include <pylondataprocessing/BuildersRecipe.h>
#include <pylondataprocessing/PylonDataProcessing.h>
#include <pylondataprocessing/IOutputObserver.h>
#include <pylondataprocessing/RegionUserBufferEventHandler.h>
#include <pylondataprocessing/Update.h>
#include <pylondataprocessing/VariantContainer.h>
#include <pylondataprocessing/VariantContainerType.h>
#include <pylondataprocessing/VariantDataType.h>
#include <pylondataprocessing/Variant.h>
#include <pylondataprocessing/SmartResult.h>
#include <pylondataprocessing/SmartResultEventHandler.h>

#include <list>
#include <chrono>
#include <thread>
#include <memory> //for std::shared_ptr

namespace Pylon
{
    namespace DataProcessing
    {
        /*!
        \class  CSmartInstantCameraT
        \brief  Provides convenient access to a camera device and pylon data processing using a recipe as appended processing stage.

        Extends an Instant Camera class and uses the CBuildersRecipe internally.
        */
        template <typename BaseInstantCameraT, typename SmartInstantCameraResultT = SSmartInstantCameraResultT<typename BaseInstantCameraT::GrabResultPtr_t>>
        class CSmartInstantCameraT : public BaseInstantCameraT
        {
        public:
            /// The camera type this smart camera class is derived from.
            typedef BaseInstantCameraT BaseInstantCamera_t;
            /// The type of this extension depending on the instant camera class and result class used.
            typedef CSmartInstantCameraT<BaseInstantCameraT, SmartInstantCameraResultT> SmartInstantCamera_t;
            /// The type of result produced by this class.
            typedef SmartInstantCameraResultT SmartInstantCameraResult_t;
            /// The type of grab result produced by this class.
            typedef typename BaseInstantCameraT::GrabResultPtr_t GrabResultPtr_t;
            /// The type of result event handler usable with this class.
            typedef CSmartResultEventHandlerT<BaseInstantCameraT, SmartInstantCameraResult_t> SmartResultEventHandler_t;

            /*!
            \brief Creates a Smart Instant Camera object with no attached %Pylon device and no recipe configured.

            \error
                Does not throw C++ exceptions.
            */
            CSmartInstantCameraT()
                : m_pLock(&BaseInstantCameraT::GetLock())
                , m_smartResultReadyWaitObject(WaitObjectEx::Create())
                , m_smartResultStopWaitObject(WaitObjectEx::Create(true))
                , m_pRecipe(new CBuildersRecipe)
                , m_recipeOutputObserver(this)
            {
                m_smartResultReadyOrStop.Add(m_smartResultReadyWaitObject);
                m_smartResultReadyOrStop.Add(m_smartResultStopWaitObject);
                m_pRecipe->Unload(); // A builders recipe is initially in state loaded, but it is empty.
            }


            /*!
            \brief Creates a Smart Instant Camera object and calls Attach(). No recipe is configured.

            See Attach() for more information.

            \param[in]  pDevice The %Pylon device to attach.
            \param[in]  cleanupProcedure If cleanupProcedure equals Cleanup_Delete, the %Pylon device is destroyed when the Instant Camera object is destroyed.

            \error
                May throw an exception if the passed %Pylon device is open.
                Does not throw C++ exceptions if the passed %Pylon device is closed or NULL.
            */
            CSmartInstantCameraT(IPylonDevice* pDevice, ECleanup cleanupProcedure = Cleanup_Delete)
                : BaseInstantCameraT(pDevice, cleanupProcedure)
                , m_pLock(&BaseInstantCameraT::GetLock())
                , m_smartResultReadyWaitObject(WaitObjectEx::Create())
                , m_smartResultStopWaitObject(WaitObjectEx::Create(true))
                , m_pRecipe(new CBuildersRecipe)
                , m_recipeOutputObserver(this)
            {
                m_smartResultReadyOrStop.Add(m_smartResultReadyWaitObject);
                m_smartResultReadyOrStop.Add(m_smartResultStopWaitObject);
                m_pRecipe->Unload(); // A builders recipe is initially in state loaded, but it is empty.
            }

            /*!
            \brief Creates a Smart Instant Camera object and calls Attach(). Sets the filename of the recipe to
                   be loaded when Open() is called.

            See Attach() for more information.

            \param[in]  pDevice The %Pylon device to attach.
            \param[in]  filename The name and path of the recipe loaded at every call to Open().
            \param[in]  cleanupProcedure If cleanupProcedure equals Cleanup_Delete, the %Pylon device is destroyed when the Instant Camera object is destroyed.


            \error
                May throw an exception if the passed %Pylon device is open.
                Does not throw C++ exceptions if the passed %Pylon device is closed or NULL.
            */
            CSmartInstantCameraT(IPylonDevice* pDevice, const String_t& filename , ECleanup cleanupProcedure = Cleanup_Delete)
                : BaseInstantCameraT(pDevice, cleanupProcedure)
                , m_pLock(&BaseInstantCameraT::GetLock())
                , m_smartResultReadyWaitObject(WaitObjectEx::Create())
                , m_smartResultStopWaitObject(WaitObjectEx::Create(true))
                , m_pRecipe(new CBuildersRecipe)
                , m_recipeFileName(filename)
                , m_recipeOutputObserver(this)
            {
                m_smartResultReadyOrStop.Add(m_smartResultReadyWaitObject);
                m_smartResultReadyOrStop.Add(m_smartResultStopWaitObject);
                m_pRecipe->Unload(); // A builders recipe is initially in state loaded, but it is empty.
            }


            /*!
            \brief Destroys a Smart Instant Camera object.

             <ul>
                <li> Stops the grab to stop data processing. </li>
                <li> Calls Attach(NULL) for destroying or removing a %Pylon device depending on the passed cleanup procedure. </li>
             </ul>

            \error
                Does not throw C++ exceptions.
            */
            ~CSmartInstantCameraT() override
            {
                // Stop the grabbing and the data processing inside the recipe.
                if (this->IsGrabbing())
                {
                    StopGrabbing();
                }

                // Unload and delete the recipe. This also deregisters all event handlers.
                if (m_pRecipe)
                {
                    m_pRecipe->Unload();
                    delete m_pRecipe;
                    m_pRecipe = nullptr;
                }

                // If the thread is still running wait for it to stop.
                JoinWithGrabLoopThreadDataProcessingIfNeeded();
            }


            /*!
            \brief Sets the filename of the recipe to be loaded when Open() is called.

            If the filename is empty not recipe is opened. The recipe does not change its state.

            \param[in]  filename The name and path of the recipe loaded at every call to Open().

            \error
                Does not throw C++ exceptions.
            */
            virtual void SetRecipeFilename(const String_t& filename)
            {
                AutoLock lock(*m_pLock);
                m_recipeFileName = filename;
            }


            /*!
            \brief Retrieves the filename of the recipe that will be loaded when Open() is called.

            \return Provides the filename of the recipe that will be loaded when Open() is called.

            \error
                Does not throw C++ exceptions.
            */
            virtual String_t GetRecipeFilename() const
            {
                AutoLock lock(*m_pLock);
                return m_recipeFileName;
            }


            /*!
            \brief Opens the attached %Pylon device.

            <ul>
            <li> Opened by user flag is set, preventing closing of the device on StopGrabbing(). </li>
            <li> If the %Pylon device is already open, nothing more is done. </li>
            <li> The OnOpen configuration event is fired. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> The %Pylon device is opened and a connection to the camera device is established. </li>
            <li> The instant camera migration mode setting is applied to the %Pylon device transport layer node map. </li>
            <li> A device removal call back is registered at the %Pylon device. </li>
            <li> Callbacks for camera events are registered at the camera node map. </li>
            <li> The OnOpened configuration event is fired if the %Pylon device has been opened successfully. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> If the recipe filename is not empty and the recipe is not loaded, the recipe is loaded using that filename. Alternatively you can load the recipe separately using one of the load methods. </li>
            <li> If the recipe filename is not empty and the recipe has been loaded, a flag is set to unload the recipe on camera close. </li>
            </ul>

            \pre A %Pylon device is attached.

            \post
            <ul>
            <li> The %Pylon device is open and a connection to the camera device has been established. </li>
            <li> Opened by user flag is set, preventing closing of the %Pylon device on StopGrabbing(). </li>
            <li> If the recipe filename is not empty and the recipe is not loaded, the recipe is loaded. </li>
            </ul>

            \error
                The Instant Camera object is still valid after error.
                The %Pylon device open may throw.
                Configuration event calls may throw.
                Callback registrations may throw.
                The %Pylon device is closed with Close() if the OnOpened event call triggers an exception.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            void Open() override
            {
                AutoLock lock(*m_pLock);
                bool cameraInitiallyOpen = this->IsOpen();
                BaseInstantCameraT::Open();
                try
                {
                    if (!m_recipeFileName.empty())
                    {
                        if (m_pRecipe && !m_pRecipe->IsLoaded())
                        {
                            m_pRecipe->Unload();
                            m_pRecipe->Load(m_recipeFileName);
                            m_pRecipe->RegisterAllOutputsObserver(&m_recipeOutputObserver, RegistrationMode_ReplaceAll);
                            m_unloadRecipeOnCameraClose = true;
                        }
                    }
                }
                catch(...)
                {
                    if (!cameraInitiallyOpen)
                    {
                        this->BaseInstantCameraT::Close();
                    }
                    throw;
                }
            }


            /*!
             \brief Checks whether a recipe is loaded.
             \return  \c true if a recipe is loaded.
             \error Doesn't throw C++ exceptions.
             \threading This method is synchronized using the lock provided by \c GetLock() of the recipe.
            */
            virtual bool IsLoaded() const
            {
                return m_pRecipe && m_pRecipe->IsLoaded();
            }


            /*!
             \brief
                Loads a recipe from disk and creates the objects of the design described by the recipe. Relative paths
                , i.e., relative to the directory the recipe file is located in, are used for loading external recipe components, e.g., images.

             \param[in] filename The name and path of the recipe.
             \param[in] unloadOnCameraClose If set to true the recipe is unloaded when the camera is closed.

             \pre
                <ul>
                    <li> The given file name must be a valid file path of an existing file containing valid recipe data. </li>
                </ul>

             \post
                <ul>
                    <li> A recipe is loaded. You can use \c IsLoaded() to check whether a recipe is loaded. Implicitly called \c Unload() and unregisters all observers already connected. </li>
                </ul>

             \error
                Throws an exception if the recipe can't be loaded. No recipe is loaded if an error occurred.

             \threading
                This method is synchronized using the lock provided by \c GetLock().
            */
            virtual void Load(const String_t& filename, bool unloadOnCameraClose = false)
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->Unload();
                    m_pRecipe->Load(filename);
                    m_pRecipe->RegisterAllOutputsObserver(&m_recipeOutputObserver, RegistrationMode_ReplaceAll);
                }
                else
                {
                    throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                }
                m_unloadRecipeOnCameraClose = unloadOnCameraClose;
            }


            /*!
             \brief
                Loads a recipe from binary buffer and creates the objects of the design described by the recipe.
                Relative paths, i.e., relative to the current directory, are used for loading external recipe components, e.g., images.

             \param[in] pBuffer    Buffer pointer to binary recipe.
             \param[in] bufferSize Buffer size for binary recipe buffer in bytes.
             \param[in] unloadOnCameraClose If set to true the recipe is unloaded when the camera is closed.

             \pre
                <ul>
                    <li> The buffer specified by pBuffer and bufferSize must contain valid recipe data. </li>
                </ul>

             \post
                <ul>
                    <li> A recipe is loaded. You can use \c IsLoaded() to check whether a recipe is loaded. Implicitly called \c Unload() and unregisters all observers already connected. </li>
                </ul>

             \error
                Throws an exception if the recipe can't be loaded. No recipe is loaded if an error occurred.

             \threading
                This method is synchronized using the lock provided by \c GetLock().
            */
            virtual void LoadFromBinary(const void* pBuffer, size_t bufferSize, bool unloadOnCameraClose = false)
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->Unload();
                    m_pRecipe->LoadFromBinary(pBuffer, bufferSize);
                    m_pRecipe->RegisterAllOutputsObserver(&m_recipeOutputObserver, RegistrationMode_ReplaceAll);
                }
                else
                {
                    throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                }
                m_unloadRecipeOnCameraClose = unloadOnCameraClose;
            }


            /*!
             \brief Loads a recipe from binary buffer and creates the objects of the design described by the recipe.

             \param[in] pBuffer    Buffer pointer to binary recipe.
             \param[in] bufferSize Buffer size for binary recipe buffer in bytes.
             \param[in] directory External recipe components, e.g., images, will be loaded relative to this directory.
             \param[in] unloadOnCameraClose If set to true the recipe is unloaded when the camera is closed.

             \pre
                <ul>
                    <li> The buffer specified by pBuffer and bufferSize must contain valid recipe data. </li>
                </ul>

             \post
                <ul>
                    <li> A recipe is loaded. You can use \c IsLoaded() to check whether a recipe is loaded. Implicitly calls \c Unload() and unregisters all observers already connected. </li>
                </ul>

             \error
                Throws an exception if the recipe can't be loaded. No recipe is loaded if an error occurred.

             \threading
                This method is synchronized using the lock provided by \c GetLock().
            */
            virtual void LoadFromBinary(const void* pBuffer, size_t bufferSize, const String_t& directory, bool unloadOnCameraClose = false)
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->Unload();
                    m_pRecipe->LoadFromBinary(pBuffer, bufferSize, directory);
                    m_pRecipe->RegisterAllOutputsObserver(&m_recipeOutputObserver, RegistrationMode_ReplaceAll);
                }
                else
                {
                    throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                }
                m_unloadRecipeOnCameraClose = unloadOnCameraClose;
            }


            /*!
             \brief Optional method to pre-allocate resources of the recipe used.

             All resources that could be allocated successfully stay allocated until a call to \c DeallocateResources().

             \pre
                <ul>
                    <li> A recipe is loaded. </li>
                    <li> The recipe must not be started. </li>
                </ul>

             \post
                <ul>
                    <li> All resources are allocated. </li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li> The preconditions aren't met. </li>
                    <li> The resources couldn't be allocated. </li>
                </ul>

             \threading
                This method is synchronized using the lock provided by \c GetLock().
            */
            virtual void PreAllocateResources()
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->PreAllocateResources();
                }
                else
                {
                    throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                }
            }


            /*!
             \brief
                Deallocates all resources used by the recipe.

                Calls recipes \c Stop() method if the design described by the recipe has been started.

             \post
                <ul>
                    <li> No resources are allocated. </li>
                </ul>

             \error
                Doesn't throw C++ exceptions.

             \threading
                This method is synchronized using the lock provided by \c GetLock().
            */
            virtual void DeallocateResources()
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->DeallocateResources();
                }
                // not exception here, no recipe is in not allocated state.
            }


            /*!
             \brief Unloads the recipe currently loaded.

             Calls \c DeallocateResources() if the design described by the recipe has allocated resources. Unregisters all observers that have been connected.

             \pre
               <ul>
                 <li> Data received via \c IOutputObserver::OutputDataPush must be freed. </li>
               </ul>

             \post
               <ul>
                 <li> No recipe is loaded. </li>
               </ul>

             \error
               Doesn't throw C++ exceptions.

             \threading
               This method is synchronized using the lock provided by \c GetLock().
             */
            virtual void Unload()
            {
                AutoLock lock(*m_pLock);
                if (m_pRecipe)
                {
                    m_pRecipe->Unload();
                }
                // not exception here, no recipe is in not loaded state.
            }


            /*!
            \brief Closes the attached %Pylon device. Can unload the recipe.

            <ul>
            <li> If no %Pylon device is attached, nothing is done. </li>
            <li> If the %Pylon device is already closed, nothing is done. </li>
            <li> If a grab is in progress, it is stopped by calling StopGrabbing(). </li>
            <li> The configuration event OnClose is fired. Possible C++ exceptions from event calls are caught and ignored. All event handlers are notified. </li>
            <li> The connection to the camera device is closed and the %Pylon device is closed. </li>
            <li> The configuration event OnClosed is fired if the %Pylon device has been closed successfully. Possible C++ exceptions from event calls are caught and ignored. All event handlers are notified. </li>
            <li> If the unload flag is set the recipe is unloaded. </li>
            </ul>

            \post The connection to the camera device is closed and the %Pylon device is closed.

            \error
                Does not throw C++ exceptions. Possible C++ exceptions are caught and ignored.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            void Close()  override
            {
                AutoLock lock(*m_pLock);
                BaseInstantCameraT::Close();
                if (m_unloadRecipeOnCameraClose && m_pRecipe)
                {
                    m_pRecipe->Unload();
                    m_unloadRecipeOnCameraClose = false;
                }
            }


            /*!
            \brief Starts the grabbing of images.

            <ul>
            <li> If a grab loop thread has been used in the last grab session, the grab loop thread context is joined with the caller's context. </li>
            <li> If the %Pylon device is not already open, it is opened by calling Open(). </li>
            <li> The configuration event OnGrabStart is fired. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> Grab-specific parameters of the camera object are locked, e.g. MaxNumBuffer. </li>
            <li> If the camera device parameter ChunkModeActive is enabled, the Instant Camera chunk parsing support is initialized. </li>
            <li> If the Instant Camera parameter GrabCameraEvents is enabled, the Instant Camera event grabbing support is initialized. </li>
            <li> The grabbing is started. </li>
            <li> The AcquisitionStart command of the camera device is executed. </li>
            <li> The configuration event OnGrabStarted is fired if the grab has been started successfully. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is started calling RetrieveResult( GrabLoopThreadTimeout, smartResult) in a loop. </li>
            </ul>

            \param[in]  strategy The grab strategy. See Pylon::EGrabStrategy for more information
            \param[in]  grabLoopType If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the grab loop.
                                     This grab loop type is also used for the data processing grab loop.

            \pre
            <ul>
            <li> A %Pylon device is attached. </li>
            <li> The stream grabber of the %Pylon device is closed. </li>
            <li> The grabbing is stopped. </li>
            <li> The attached %Pylon device supports grabbing. </li>
            <li> Must not be called while holding the lock provided by GetLock() when using the grab loop thread. </li>
            </ul>

            \post
            <ul>
            <li> The grabbing is started. </li>
            <li> Grab-specific parameters of the camera object are locked, e.g. MaxNumBuffer. </li>
            <li> If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is running that calls RetrieveResult( GrabLoopThreadTimeout, grabResult) in a loop. Images are processed by registered image event handlers. </li>
            <li> Operating the stream grabber from outside the camera object will result in undefined behavior. </li>
            </ul>

            \error
                The Instant Camera object is still valid after error. Open() may throw. Configuration event calls may throw. The grab implementation may throw.
                The grabbing is stopped with StopGrabbing() if the OnGrabStarted event call triggers an exception. Throws a C++ exception, if Upcoming Image grab strategy
                is used together with USB camera devices.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            void StartGrabbing(EGrabStrategy strategy = GrabStrategy_OneByOne, EGrabLoop grabLoopType = GrabLoop_ProvidedByUser) override
            {
                StartGrabbingImpl(true /*start recipe*/, 0, false /* do not use maxImages */, strategy, grabLoopType /* used for instant camera base */, grabLoopType /* used for data processing */);
            }


            /*!
            \brief Starts the grabbing for a maximum number of images.

            Extends the StartGrabbing(EStrategy, EGrabLoop) by a number of images to grab. If the passed count of images has been reached, StopGrabbing is called
            automatically. The images are counted according to the grab strategy. Skipped images are not taken into account.

            The amount of allocated buffers is reduced to maxImages when grabbing fewer images
            than according to the value of the CInstantCamera MaxNumBuffer parameter
            and the grab strategy is GrabStrategy_OneByOne.

            \param[in]  maxImages The count of images to grab. This value must be larger than zero.
            \param[in]  strategy The grab strategy. See Pylon::InstantCamera::EStrategy for more information.
            \param[in]  grabLoopType If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the grab loop.
                                     This grab loop type is also used for the data processing grab loop.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            void StartGrabbing(size_t maxImages, EGrabStrategy strategy = GrabStrategy_OneByOne, EGrabLoop grabLoopType = GrabLoop_ProvidedByUser) override
            {
                StartGrabbingImpl(true /*start recipe*/, maxImages, true /* do use maxImages */, strategy, grabLoopType /* used for instant camera base */, grabLoopType /* used for data processing */);
            }


            /*!
            \brief Starts the grabbing. This method is an overload that with additional parameters.

            See the corresponding StartGrabbing() method for more information.

            \param[in]  startRecipe If true the data processing using the recipe is started otherwise it is bypassed, e.g. for setting up the camera only.
            \param[in]  strategy The grab strategy. See Pylon::InstantCamera::EStrategy for more information.
            \param[in]  grabLoopType If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the grab loop.
            \param[in]  grabLoopTypeDataProcessing If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the data processing loop.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            virtual void StartGrabbing( bool startRecipe, EGrabStrategy strategy, EGrabLoop grabLoopType, EGrabLoop grabLoopTypeDataProcessing)
            {
                StartGrabbingImpl(startRecipe, 0, false /* do not use maxImages */, strategy, grabLoopType /* used for instant camera base */, grabLoopTypeDataProcessing);
            }


            // Also available
            using BaseInstantCameraT::RetrieveResult;

            /*!
            \brief Starts the grabbing for a maximum number of images. This method is an overload that with additional parameters.

            See the corresponding StartGrabbing() method for more information.

            \param[in]  startRecipe If true the data processing using the recipe is started otherwise it is bypassed, e.g. for setting up the camera only.
            \param[in]  maxImages The count of images to grab. This value must be larger than zero.
            \param[in]  strategy The grab strategy. See Pylon::InstantCamera::EStrategy for more information.
            \param[in]  grabLoopType If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the grab loop.
            \param[in]  grabLoopTypeDataProcessing If grabLoopType equals GrabLoop_ProvidedByInstantCamera, an additional grab loop thread is used to run the data processing loop.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            virtual void StartGrabbing( bool startRecipe, size_t maxImages, EGrabStrategy strategy, EGrabLoop grabLoopType, EGrabLoop grabLoopTypeDataProcessing)
            {
                StartGrabbingImpl(startRecipe, maxImages, true /* do use maxImages */, strategy, grabLoopType /* used for instant camera base */, grabLoopTypeDataProcessing);
            }


            /*!
            \brief Retrieves a smart result according to the strategy, waits if it is not yet available

            <ul>
            <li> The content of the passed smart result is released. </li>
            <li> If no %Pylon device is attached or the grabbing is not started, the method returns immediately "false". </li>
            <li> Wait for a smart result if it is not yet available. The access to the camera is not locked during waiting. Camera events are handled. </li>
            <li> Only if camera events are used: Incoming camera events are handled. </li>
            <li> One smart result is retrieved per call according to the strategy applied. </li>
            <li> Only if chunk mode is used: The chunk data parsing is performed. The smart result data is updated using chunk data. </li>
            <li> The image event OnImagesSkipped is fired if grab results have been skipped according to the strategy. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> The image event OnImageGrabbed is fired if a grab result becomes available. The notification of event handlers stops when an event call triggers an exception. </li>
            <li> The smart result event OnResult is fired. </li>
            <li> Stops the grabbing by calling StopGrabbing() if the maximum number of images has been grabbed. </li>
            </ul><br>

            It needs to be checked whether the grab represented by the smart result has been successful, see CGrabResultData::GrabSucceeded().

            \param[in]  timeoutMs  A timeout value in ms for waiting for a smart result, or the INFINITE value.
            \param[out] result  Receives the smart result.
            \param[in]  timeoutHandling  If timeoutHandling equals TimeoutHandling_ThrowException, a timeout exception is thrown on timeout.

            \return True if the call successfully retrieved a smart result, false otherwise.

            \pre
            <ul>
            <li> There is no other thread waiting for a result. This will be the case when the Instant Camera grab loop thread is used. </li>
            </ul>

            \post
            <ul>
            <li> If a smart result has been retrieved, one image is removed from the output queue and is returned in the grabResult parameter. </li>
            <li> If no smart result has been retrieved, an empty smart result is returned in the result parameter. </li>
            <li> If the maximum number of images has been grabbed, the grabbing is stopped. </li>
            <li> If camera event handling is enabled and camera events were received, at least one or more camera event messages have been processed. </li>
            </ul>

            \error
                The Instant Camera object is still valid after error. The grabbing is stopped if an exception is thrown.

            \threading
                This method is synchronized using the lock provided by GetLock() while not waiting.
            */
            virtual bool RetrieveResult(unsigned int timeoutMs, SmartInstantCameraResult_t& result, ETimeoutHandling timeoutHandling = TimeoutHandling_ThrowException)
            {
                // Waiting for a smart result if it is not yet available. The access to the camera is not locked during waiting. Camera events are handled.
                // no AutoLock lock(*m_pLock);
                bool isSuccessful = false;

                // Clearing can release buffers or other data needed for grabbing, e.g. when working with one buffer only.
                result.Release();

                // Not currently grabbing return false.
                if (!this->IsGrabbing())
                {
                    return false;
                }

                // A result is already available?
                if (PopSmartResultData(result))
                {
                    isSuccessful = true;
                }
                else
                {
                    unsigned int timeElapsedMs = 0;
                    if (m_grabLoopType == GrabLoop_ProvidedByUser && (timeoutMs == INFINITE || timeoutMs == 0))
                    {
                        // Get one image and trigger data processing via the registered sticky image event handler.
                        CGrabResultPtr ptrGrabResult;
                        isSuccessful = BaseInstantCameraT::RetrieveResult(timeoutMs, ptrGrabResult, timeoutHandling);
                    }
                    if (m_grabLoopType == GrabLoop_ProvidedByUser)
                    {
                        // Get one image and trigger data processing via the registered sticky image event handler.
                        CGrabResultPtr ptrGrabResult;
                        std::chrono::time_point<std::chrono::high_resolution_clock> beginWaiting = std::chrono::high_resolution_clock::now();
                        isSuccessful = BaseInstantCameraT::RetrieveResult(timeoutMs, ptrGrabResult, timeoutHandling);
                        std::chrono::time_point<std::chrono::high_resolution_clock> endWaiting = std::chrono::high_resolution_clock::now();
                        timeElapsedMs = static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::milliseconds>(endWaiting - beginWaiting).count());
                    }
                    else
                    {
                        isSuccessful = true;
                    }
                    unsigned int waitObjectIndex = 0;
                    if (isSuccessful && timeElapsedMs <= timeoutMs && m_smartResultReadyOrStop.WaitForAny(timeoutMs - timeElapsedMs) && PopSmartResultData(result))
                    {
                        // Info: resultDataOut can originate from a previously grabbed image due to the use of queues.
                        // Only if all queues were empty the smart result data corresponds to the grab result grabbed above.
                        isSuccessful = true;
                    }
                    else if (waitObjectIndex != 1 /* grab stop */)
                    {
                        isSuccessful = false;
                        if (timeoutHandling == TimeoutHandling_ThrowException)
                        {
                            throw TIMEOUT_EXCEPTION("Grab and data processing timed out.");
                        }
                    }
                }
                if (isSuccessful)
                {
                    ++m_countOfResultsDelivered;
                    // Notify smart result event handler.
                    try
                    {
                        OnResult(result);
                    }
                    catch(...)
                    {
                        // Stop grabbing if count of results has been produced.
                        if (isSuccessful && m_maxNumberOfResultsToBeDelivered && m_countOfResultsDelivered >= m_maxNumberOfResultsToBeDelivered)
                        {
                            StopGrabbing();
                        }
                        throw;
                    }
                    // Stop grabbing if count of results has been produced.
                    if (isSuccessful && m_maxNumberOfResultsToBeDelivered && m_countOfResultsDelivered >= m_maxNumberOfResultsToBeDelivered)
                    {
                        StopGrabbing();
                    }
                }

                return isSuccessful;
            }


            /*!
            \brief
                Returns a parameter collection to access the parameters of the recipe.

            \note
                The \c IParameterCollection returns objects based on \c CParameter that can be used while a recipe is loaded. Before unloading a recipe, the parameter objects must be cleared by
                calling \c CParameter::Release(). For parameters that become available only when resources are allocated, e.g., a camera, \c CParameter::Release() must be called before
                deallocating a resource.

            \return
                A reference to the \c IParameterCollection.

            \pre
                <ul>
                    <li> A recipe is loaded. </li>
                </ul>

            \error
                Throws an exception if the preconditions aren't met.

            \threading
                This method is synchronized using the lock provided by \c GetLock() of the recipe.
            */
            virtual IParameterCollection& GetParameters()
            {
                if (m_pRecipe)
                {
                    return m_pRecipe->GetParameters();
                }
                else
                {
                    throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                }
            }


            /*!
            \brief Stops the grabbing of smart results.

            <ul>
            <li> Nothing is done if the Instant Camera is not currently grabbing. </li>
            <li> The configuration event OnGrabStop is fired. Possible C++ exceptions from event calls are caught and ignored. All event handlers are notified. </li>
            <li> The AcquisitionStop command of the camera device is executed. </li>
            <li> The grabbing is stopped. </li>
            <li> All buffer queues of the Smart Instant Camera are cleared. </li>
            <li> The OnGrabStopped configuration event is fired if the grab has been stopped successfully. Possible C++ exceptions from event calls are caught and ignored. All event handlers are notified. </li>
            <li> If the Instant Camera has been opened by StartGrabbing, it is closed by calling Close(). </li>
            <li> Grab-specific parameters of the camera object are unlocked, e.g. MaxNumBuffer. </li>
            </ul>

            \post
            <ul>
            <li> The grabbing is stopped. </li>
            <li> If the %Pylon device has been opened by StartGrabbing and no other camera object service requires it to be open, it is closed. </li>
            <li> Grab specific parameters of the camera object are unlocked, e.g. MaxNumBuffer. </li>
            </ul>

            \error
                Does not throw C++ exceptions. Possible C++ exceptions are caught and ignored.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            void StopGrabbing() override
            {
                StopGrabbingImpl(INFINITE);
            }


            /*!
            \brief Stops the grabbing of smart results. This method is an overload that with an additional parameters.

             See the other StopGrabbing overload for more information.

            \error
                Does not throw C++ exceptions. Possible C++ exceptions are caught and ignored.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            virtual void StopGrabbing(unsigned int dpTimeoutMs)
            {
                StopGrabbingImpl(dpTimeoutMs);
            }


            /*!
            \brief Grabs one image.

            The following code shows a simplified version of what is done (happy path):

            \code
                //grab one image
                StartGrabbing( 1, GrabStrategy_OneByOne, GrabLoop_ProvidedByUser);

                //grab is stopped automatically due to maxImages = 1
                return RetrieveResult( timeoutMs, grabResult, timeoutHandling) && grabResult->GrabSucceeded();
            \endcode

            GrabOne() can be used to together with the CAcquireSingleFrameConfiguration.

            \note Using GrabOne is more efficient if the %Pylon device is already open, otherwise the %Pylon device is opened and closed for each call.

            \note Grabbing single images using Software Trigger (CSoftwareTriggerConfiguration) is recommended if you want to maximize frame rate.
                  This is because the overhead per grabbed image is reduced compared to Single Frame Acquisition.
                  The grabbing can be started using StartGrabbing().
                  Images are grabbed using the WaitForFrameTriggerReady(), ExecuteSoftwareTrigger() and RetrieveResult() methods instead of using GrabOne.
                  The grab can be stopped using StopGrabbing() when done.

            \param[in]  timeoutMs  A timeout value in ms for waiting for a grab result, or the INFINITE value.
            \param[out] grabResult  Receives the grab result.
            \param[in]  timeoutHandling  If timeoutHandling equals TimeoutHandling_ThrowException, a timeout exception is thrown on timeout.

            \return Returns true if the call successfully retrieved a grab result and the grab succeeded (CGrabResultData::GrabSucceeded()).

            \pre Must meet the preconditions of start grabbing.
            \post Meets the postconditions of stop grabbing.

            \error
                The Instant Camera object is still valid after error. See StartGrabbing(), RetrieveResult(), and StopGrabbing() .
                In the case of exceptions after StartGrabbing() the grabbing is stopped using StopGrabbing().
            */
            bool GrabOne( unsigned int timeoutMs, GrabResultPtr_t& grabResult, ETimeoutHandling timeoutHandling = TimeoutHandling_ThrowException ) override
            {
                bool successfullyRetrievedAGrabResult = false;
                try
                {
                    successfullyRetrievedAGrabResult = BaseInstantCameraT::GrabOne(timeoutMs, grabResult, timeoutHandling);
                }
                catch(...)
                {
                    StopGrabbing();
                    throw;
                }
                StopGrabbing();
                return successfullyRetrievedAGrabResult;
            }


            /*!
            \brief Grabs one smart result.

            The following code shows a simplified version of what is done (happy path):

            \code
                //grab one image
                StartGrabbing( 1, GrabStrategy_OneByOne, GrabLoop_ProvidedByUser);

                //grab is stopped automatically due to maxImages = 1
                return RetrieveResult( timeoutMs, grabResult, timeoutHandling) && grabResult->GrabSucceeded();
            \endcode

            GrabOne() can be used to together with the CAcquireSingleFrameConfiguration.

            \note Using GrabOne is more efficient if the %Pylon device is already open, otherwise the %Pylon device is opened and closed for each call.

            \note Grabbing single images using Software Trigger (CSoftwareTriggerConfiguration) is recommended if you want to maximize frame rate.
                  This is because the overhead per grabbed image is reduced compared to Single Frame Acquisition.
                  The grabbing can be started using StartGrabbing().
                  Images are grabbed using the WaitForFrameTriggerReady(), ExecuteSoftwareTrigger() and RetrieveResult() methods instead of using GrabOne.
                  The grab can be stopped using StopGrabbing() when done.

            \param[in]  startRecipe If true the data processing using the recipe is started otherwise it is bypassed, e.g. for setting up the camera only.
            \param[in]  timeoutMs  A timeout value in ms for waiting for a smart result, or the INFINITE value.
            \param[out] result  Receives the smart result.
            \param[in]  timeoutHandling  If timeoutHandling equals TimeoutHandling_ThrowException, a timeout exception is thrown on timeout.

            \return Returns true if the call successfully retrieved a smart result and the grab succeeded (CGrabResultData::GrabSucceeded()).

            \pre Must meet the preconditions of start grabbing.
            \post Meets the postconditions of stop grabbing.

            \error
                The Instant Camera object is still valid after error. See StartGrabbing(), RetrieveResult(), and StopGrabbing() .
                In the case of exceptions after StartGrabbing() the grabbing is stopped using StopGrabbing().
            */
            virtual bool GrabOne(bool startRecipe, unsigned int timeoutMs, SmartInstantCameraResult_t& result, ETimeoutHandling timeoutHandling = TimeoutHandling_ThrowException)
            {
                // Waiting for a smart result if it is not yet available. The access to the camera is not locked during waiting. Camera events are handled.
                // no AutoLock lock(*m_pLock);
                bool isSuccessful = false;
                StartGrabbing(startRecipe, 1, GrabStrategy_OneByOne, GrabLoop_ProvidedByUser, GrabLoop_ProvidedByUser); //grab one image and process it
                try
                {
                    if (!RetrieveResult( timeoutMs, result, TimeoutHandling_Return )) //wait for the image and the processing
                    {
                        StopGrabbing(); //grab timed out, stop the grabbing as this is not done automatically
                        if (timeoutHandling == TimeoutHandling_ThrowException)
                        {
                            throw TIMEOUT_EXCEPTION("Grab and data processing timed out.");
                        }
                        isSuccessful = false; //the grabbing and processing failed
                    }
                    else
                    {
                        isSuccessful = true;
                    }
                }
                catch (...)
                {
                    StopGrabbing();
                    throw;
                }

                return isSuccessful;
            }


            /*!
            \brief Provides access to a wait object indicating available smart results.

            \return A wait object indicating available smart results.

            \error
                Does not throw C++ exceptions.

            \threading
                This method is synchronized using the lock provided by GetLock().
            */
            const WaitObject& GetSmartResultWaitObject()
            {
                return m_smartResultReadyWaitObject;
            }


            /*!
            \brief Adds an smart result event handler to the list of registered smart result event handler objects.

            <ul>
            <li> If mode equals RegistrationMode_ReplaceAll, the list of registered smart result event handlers is cleared. </li>
            <li> If pointer \c pImageEventHandler is not NULL, it is appended to the list of smart result event handlers. </li>
            </ul>

            \param[in]  pSmartResultEventHandler  The receiver of smart result events.
            \param[in]  mode  Indicates how to register the new smartResultEventHandler.
            \param[in]  cleanupProcedure  If cleanupProcedure equals Cleanup_Delete, the passed event handler is deleted when no longer needed.

            \post The \c pSmartResultEventHandler is registered and called on data processing related events.

            \error
                Does not throw C++ exceptions, except when memory allocation fails.

            \threading
                This method is synchronized using the internal smart result event handler registry lock.
            */
            virtual void RegisterSmartResultEventHandler( SmartResultEventHandler_t* pSmartResultEventHandler, ERegistrationMode mode, ECleanup cleanupProcedure )
            {
                AutoLock lock(m_smartResultHandlerRegistryLock);
                if (mode == RegistrationMode_ReplaceAll)
                {
                    m_eventHandlerList.clear();
                }
                if (pSmartResultEventHandler)
                {
                    m_eventHandlerList.emplace_back(std::make_shared<SmartResultEventHandlerData>(pSmartResultEventHandler, cleanupProcedure));
                }
            }


            /*!
            \brief Removes an smart result event handler from the list of registered smart result event handler objects.

            If the smart result event handler is not found, nothing is done.

            \param[in]  pSmartResultEventHandler  The registered receiver of configuration events.

            \return True if successful

            \post
            <ul>
            <li> The smartResultEventHandler is deregistered. </li>
            <li> If the smart result event handler has been registered by passing a pointer and the cleanup procedure is Cleanup_Delete, the event handler is deleted. </li>
            </ul>

            \error
                Does not throw C++ exceptions.

            \threading
                This method is synchronized using the internal smart result event handler registry lock.
            */
            virtual bool DeregisterSmartResultEventHandler( SmartResultEventHandler_t* pSmartResultEventHandler )
            {
                AutoLock lock(m_smartResultHandlerRegistryLock);
                for (auto it = m_eventHandlerList.rbegin(); it != m_eventHandlerList.rend(); ++it)
                {
                    if ((*it)->isHandler(pSmartResultEventHandler))
                    {
                        m_eventHandlerList.erase(--it.base());
                        return true;
                    }
                }
                return false;
            }


            /*!
            \brief Provides access to a wait object indicating that the grabbing has stopped.

            \return A wait object indicating that the grabbing has stopped.

            \error
                        Does not throw C++ exceptions.

            \threading
            This method is synchronized using the lock provided by GetLock().
            */
            const WaitObject& GetGrabStopWaitObject() override
            {
                return m_smartResultStopWaitObject;
            }

        protected:
            // internal
            // This class is used to queue a result/update pair.
            struct ResultWithUpdate
            {
                ResultWithUpdate() = default;
                ResultWithUpdate(CUpdate& update, SmartInstantCameraResult_t&& result)
                {
                    Update = update;
                    Result = std::move(result);
                }
                CUpdate Update;
                SmartInstantCameraResult_t Result;
            };


            // internal
            // This event handler receives all images that have been grabbed in all modes of operation.
            class CStickyEventHandler : public CImageEventHandler
            {
            public:
                CStickyEventHandler(bool isSticky = true)
                    : m_isSticky(isSticky)
                {
                }

                void SetIsSticky(bool isSticky)
                {
                    m_isSticky = isSticky;
                }

                void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& grabResult) override
                {
                    static_cast<SmartInstantCamera_t&>(camera).OnImageGrabbed(grabResult);
                }

                void OnImageEventHandlerDeregistered(CInstantCamera& camera) override
                {
                    if (m_isSticky)
                    {
                        // The CInstantCamera event handlers support the concept of stickiness.
                        // We do not want this event handler to be removed, when the user changes something.
                        // That's why we register it again. So that it is not removed.
                        // Info: While the camera is destroyed this call will be ignored.
                        // Info: This can change the order in which the event handlers are called.
                        camera.RegisterImageEventHandler(this, RegistrationMode_Append, Cleanup_None);
                    }
                }

            private:
                bool m_isSticky; //!< When this handler is deregistered it registers itself again, when set to true.
            };


            // internal
            // COutputObserver is a helper object that redirects the data to the smart instant camera class.
            class COutputObserver : public IOutputObserver
            {
            public:
                COutputObserver(SmartInstantCamera_t* pSmartCamera = nullptr)
                    : m_pSmartCamera(pSmartCamera)
                {
                }

                // Implements IOutputObserver::OutputDataPush.
                // This method is called when an output of the CRecipe pushes data out.
                // The call of the method can be performed by any thread of the thread pool of the recipe.
                // C++ exceptions from this call are logged and ignored.
                void OutputDataPush(
                    CRecipe& recipe,
                    CVariantContainer valueContainer,
                    const CUpdate& update,
                    intptr_t userProvidedId) override
                {
                    if (m_pSmartCamera)
                    {
                        m_pSmartCamera->OutputDataPush(recipe, valueContainer, update, userProvidedId);
                    }
                }

            private:
                SmartInstantCamera_t* m_pSmartCamera; //!< This smart instant camera class.
            };


            // internal
            // Running on the thread that calls CInstantCamera::RetrieveResult().
            // This can be a user thread or the internal grab loop thread of the CInstantCamera.
            virtual void OnImageGrabbed(const CGrabResultPtr& grabResult)
            {
                SmartInstantCameraResult_t newResultInProgress;
                CUpdate newUpdate;
                newResultInProgress.SetGrabResult(grabResult);
                {
                    AutoLock lock(*m_pLock);

                    // Only feed the recipe with images if it is started
                    if (m_pRecipe && m_pRecipe->IsStarted())
                    {
                        // This lock is needed here because the result may already be pushed to OutputDataPush while we are here.
                        AutoLock queuelock(m_resultQueueLock);

                        // We are not checking m_recipe.CanTriggerUpdate() here. If the recipe cannot accept the
                        // input data an exception is thrown. Exceptions thrown from this callback will stop the grab.
                        // To manage this, you can switch the queue mode in the connections from the input terminal to the vTools to buffering mode.
                        newUpdate = m_pRecipe->TriggerUpdateAsync(GrabResultToInputCollection(grabResult));
                        newResultInProgress.SetInitialUpdate(newUpdate);

                        // Processing is on, we park the result in the intermediate queue, to match grab result and processing output
                        m_queueOfGrabResultsBeingProcessed.emplace_back(newUpdate, std::move(newResultInProgress));
                    }
                }

                if (!newResultInProgress.Update.IsValid())
                {
                    // Processing is off, we directly transfer the result to the output queue
                    PushSmartResultData(std::move(newResultInProgress));
                }
            }


            // You can override this method to inject additional data or use different Pin names
            virtual CVariantContainer GrabResultToInputCollection(const GrabResultPtr_t& grabResult) const
            {
                CPylonImage image;
                // Creates an invalid image if the grabResult is invalid or not successfully grabbed.
                // This will result in output data in result.Container flagged with an error that you can handle.
                image.AttachGrabResultBuffer(grabResult);
                CVariantContainer inputCollection;
                inputCollection["Image"] = image;
                return inputCollection;
            }


            // internal
            // Running on a thread from the recipe thread pool
            // C++ exceptions thrown by this method are caught and ignored.
            virtual void OutputDataPush(
                CRecipe& recipe,
                CVariantContainer& valueContainer,
                const CUpdate& update,
                intptr_t userProvidedId)
            {
                PYLON_UNUSED(recipe);
                PYLON_UNUSED(userProvidedId);

                AutoLock lock(m_resultQueueLock);
                bool dataHandled = false;
                for (auto it = m_queueOfGrabResultsBeingProcessed.begin(); it != m_queueOfGrabResultsBeingProcessed.end(); ++it)
                {
                    if (it->Update.IsValid() && (it->Update == update || update.HasBeenTriggeredBy(it->Update)))
                    {
                        dataHandled = true;
                        it->Result.SetVariantContainer(update, std::move(valueContainer));
                        PushSmartResultData(std::move(it->Result));
                        m_queueOfGrabResultsBeingProcessed.erase(it);
                        break;
                    }
                }
                PYLON_ASSERT(dataHandled); // We expect one output per image. You can add a dummy output if your recipe has no outputs.
                                           // If this fails the cause may be a vTool that does not handle preceding updates correctly.
                PYLON_UNUSED(dataHandled);
            }


            // internal
            virtual void ClearResultQueues()
            {
                AutoLock lock(m_resultQueueLock);
                m_queueOfGrabResultsBeingProcessed.clear();
                m_smartResultQueue.clear();
                m_smartResultReadyWaitObject.Reset();
            }


            // internal
            virtual void PushSmartResultData(SmartInstantCameraResult_t&& resultDataOut)
            {
                AutoLock lock(m_resultQueueLock);
                m_smartResultQueue.push_back(std::move(resultDataOut));
                m_smartResultReadyWaitObject.Signal();
            }


            // internal
            // Get one result data object from the queue.
            virtual bool PopSmartResultData(SmartInstantCameraResult_t& resultDataOut)
            {
                AutoLock lock(m_resultQueueLock);
                if (m_smartResultQueue.empty())
                {
                    return false;
                }

                resultDataOut = std::move(m_smartResultQueue.front());
                m_smartResultQueue.pop_front();
                if (m_smartResultQueue.empty())
                {
                    m_smartResultReadyWaitObject.Reset();
                }
                return true;
            }


            // internal
            virtual void OnDataProcessingError( const char* errorMessage )
            {
                AutoLock lock(m_smartResultHandlerRegistryLock);
                for (auto& handler : m_eventHandlerList)
                {
                    handler->OnDataProcessingError(*this, errorMessage);
                }
            }

            // internal
            virtual void OnResult( const SmartInstantCameraResult_t& result )
            {
                AutoLock lock(m_smartResultHandlerRegistryLock);
                for (auto& handler : m_eventHandlerList)
                {
                    handler->OnResult(*this, result);
                }
            }

            // internal
            // The run method of the grab thread
            void GrabLoopThreadDataProcessingRun()
            {
                try
                {
                    unsigned int timeout = static_cast<unsigned int>(this->GrabLoopThreadTimeout.GetValue());
                    bool priorityOverride = this->GrabLoopThreadPriorityOverride.GetValue();
                    int priority = static_cast<int>(this->GrabLoopThreadPriority.GetValue());

                    if (priorityOverride)
                    {
                        #if defined(PYLON_UNIX_BUILD)
                            Pylon::SetRTThreadPriority(pthread_self(), priority);
                        #elif defined(PYLON_WIN_BUILD)
                            Pylon::SetRTThreadPriority(Pylon::GetCurrentThreadHandle(), priority);
                        #else
                        #   error ("Unsupported platform.")
                        #endif
                    }

                    //retrieve the grab results
                    SmartInstantCameraResult_t result;
                    while (this->IsGrabbing())
                    {
                        RetrieveResult(timeout, result, TimeoutHandling_ThrowException);
                    }
                }
                catch (const GenICam::GenericException& e)
                {
                    // Notify the through event handlers.
                    {
                        AutoLock lock(*m_pLock);
                        if (this->IsGrabbing())
                        {
                            OnDataProcessingError(e.what());
                        }
                    }
                    // Stop the grab session.
                    if (this->IsGrabbing())
                    {
                        StopGrabbing();
                    }
                }
                catch (const std::exception& e)
                {
                    // Notify the through event handlers.
                    {
                        AutoLock lock(*m_pLock);
                        if (this->IsGrabbing())
                        {
                            OnDataProcessingError(e.what());
                        }
                    }
                    // Stop the grab session.
                    if (this->IsGrabbing())
                    {
                        StopGrabbing();
                    }
                }
                catch (...)
                {
                    // Notify the through event handlers
                    {
                        AutoLock lock(*m_pLock);
                        if (this->IsGrabbing())
                        {
                            OnDataProcessingError("Unknown exception caught in data processing grab loop thread.");
                        }
                    }
                    // Stop the grab session.
                    if (this->IsGrabbing())
                    {
                        StopGrabbing();
                    }
                }
            }


            // internal
            // Grab thread start for data processing.
            // Must be called inside the smart instant camera lock.
            virtual void StartGrabLoopThreadForDataProcessing()
            {
                //start the new thread
                std::shared_ptr<std::thread> newGrabLoopThread = std::make_shared<std::thread>(&SmartInstantCamera_t::GrabLoopThreadDataProcessingRun, this);
                m_ptrGrabLoopThreadDataProcessing = newGrabLoopThread;
            }


            // internal
            // Wait to join with grab loop thread.
            // Should be called outside the smart instant camera lock.
            virtual void JoinWithGrabLoopThreadDataProcessingIfNeeded()
            {
                std::shared_ptr<std::thread> ptrOldGrabLoopThread;
                {
                    // Acquire the smart instant camera lock.
                    AutoLock lock(*m_pLock);

                    // If not grabbing get the old thread.
                    if (!this->IsGrabbing())
                    {
                        ptrOldGrabLoopThread = m_ptrGrabLoopThreadDataProcessing;
                    }
                }

                // Wait for grab loop thread to stop.
                if (ptrOldGrabLoopThread && ptrOldGrabLoopThread->joinable())
                {
                    ptrOldGrabLoopThread->join();
                }
            }


            // internal
            virtual void StartGrabbingImpl(bool startRecipe, size_t maxImages, bool useMaxImages, EGrabStrategy strategy, EGrabLoop grabLoopType, EGrabLoop grabLoopTypeDataProcessing)
            {
                if (useMaxImages && maxImages == 0)
                {
                    throw OUT_OF_RANGE_EXCEPTION( "Maximum count of images to grab cannot be 0." );
                }

                // Do this outside of the lock to prevent potential deadlocks if possible (depends on the call stack).
                JoinWithGrabLoopThreadDataProcessingIfNeeded();

                AutoLock lock(*m_pLock);

                // Open() can load the recipe. We need to do this first.
                m_startGrabbingOpenedCamera = false;
                if (!this->IsOpen())
                {
                    this->Open();
                    m_startGrabbingOpenedCamera = true;
                }

                // Configure number of buffers and images to grab.
                m_countOfResultsDelivered = 0;
                m_maxNumberOfResultsToBeDelivered = useMaxImages ? maxImages : 0;
                m_maxNumBuffersOnGrabStart = this->MaxNumBuffer.GetValue();
                if (m_maxNumberOfResultsToBeDelivered && m_maxNumberOfResultsToBeDelivered < static_cast<size_t>(m_maxNumBuffersOnGrabStart))
                {
                    this->MaxNumBuffer.SetValue(static_cast<int64_t>(m_maxNumberOfResultsToBeDelivered));
                }

                // Start the recipe.
                if (startRecipe)
                {
                    if (m_pRecipe)
                    {
                        m_pRecipe->Start();
                    }
                    else
                    {
                        throw RUNTIME_EXCEPTION("Internal error. No recipe created.");
                    }
                }

                m_grabLoopTypeDataProcessing = grabLoopTypeDataProcessing;
                if (grabLoopTypeDataProcessing == GrabLoop_ProvidedByInstantCamera)
                {
                    StartGrabLoopThreadForDataProcessing();
                }

                // Start the grabbing.
                try
                {
                    m_stickyImageEventHandler.SetIsSticky(true);
                    BaseInstantCameraT::RegisterImageEventHandler(&m_stickyImageEventHandler, RegistrationMode_Append, Cleanup_None);

                    m_grabLoopType = grabLoopType;
                    if (m_maxNumberOfResultsToBeDelivered)
                    {
                        BaseInstantCameraT::StartGrabbing(strategy, grabLoopType);
                        // BaseInstantCameraT::StartGrabbing(m_maxNumberOfResultsToBeDelivered, strategy, grabLoopType); <- calls stop grabbing too early
                    }
                    else
                    {
                        BaseInstantCameraT::StartGrabbing(strategy, grabLoopType);
                    }

                    m_smartResultStopWaitObject.Reset();
                }
                // Cleanup if starting the grabbing failed.
                catch (...)
                {
                    m_stickyImageEventHandler.SetIsSticky(false);
                    BaseInstantCameraT::DeregisterImageEventHandler(&m_stickyImageEventHandler);

                    if (m_pRecipe && m_pRecipe->IsStarted())
                    {
                        // StartGrabbing failed, clean up and stop the recipe.
                        m_pRecipe->Stop();
                    }
                    throw;
                }
            }


            // internal
            virtual void StopGrabbingImpl(unsigned int dpTimeoutMs = INFINITE)
            {
                AutoLock lock(*m_pLock);

                // Deregister the image event handler.
                m_stickyImageEventHandler.SetIsSticky(false);
                BaseInstantCameraT::DeregisterImageEventHandler(&m_stickyImageEventHandler);

                // First stop grabbing so that no more images are grabbed. The recipe may still process the last image.
                // This also signals the stop wait object (this->GetGrabStopWaitObject()) any thread waiting in RetrieveResult will exit.
                BaseInstantCameraT::StopGrabbing();

                // Restore MaxNumBuffer value if needed.
                try
                {
                    if (m_maxNumBuffersOnGrabStart != this->MaxNumBuffer.GetValue())
                    {
                        this->MaxNumBuffer.SetValue(m_maxNumBuffersOnGrabStart);
                    }
                }
                catch(...)
                {
                    // ignore, should not happen
                }

                // Second stop the recipe.
                if (m_pRecipe)
                {
                    m_pRecipe->Stop(dpTimeoutMs);
                }

                m_smartResultStopWaitObject.Signal();

                // After the grab stops all output queues are empty.
                ClearResultQueues();

                // StartGrabbing opened the camera. Close it now.
                if (m_startGrabbingOpenedCamera)
                {
                    this->Close();
                }
            }

            // The camera state lock
            CLock* m_pLock;

            // Result queue members.
            CLock m_resultQueueLock;                                            //!< The result lock is required to ensure thread-safe access to the queue data member variables.
            std::list<ResultWithUpdate> m_queueOfGrabResultsBeingProcessed;     //!< This needed to match grab results with their updates.
            std::list<SmartInstantCameraResult_t> m_smartResultQueue;           //!< The queue of ready SmartInstantCameraResult_t objects.
            WaitObjectEx m_smartResultReadyWaitObject;                          //!< Signals that ResultData is available. It is set when m_smartResultQueue is not empty.
            WaitObjectEx m_smartResultStopWaitObject;                           //!< Signals that grabbing has stopped. This is later than indicated by the CInstantCamera stop.

            // Members used to control grab behavior.
            bool m_startGrabbingOpenedCamera = false;
            WaitObjects m_smartResultReadyOrStop;             //!< Used for waiting for results or for stopping.
            size_t m_countOfResultsDelivered = 0;             //!< The number of results to deliver until we automatically stop the grabbing.
            size_t m_maxNumberOfResultsToBeDelivered = 0;     //!< The number of results to grab or zero if unlimited.
            int64_t m_maxNumBuffersOnGrabStart = 0;           //!< Used to restore MaxNumBuffer value if the grabbing stops, in case we changed it when starting the grab.

            // The recipe used for data processing.
            CRecipe* m_pRecipe;                         //!< The recipe. You can derive from this class to create, add, or connect a different recipe.
                                                        //!< You can downcast to CBuildersRecipe for using the builders recipe API to create a recipe programmatically.
            bool m_unloadRecipeOnCameraClose = false;   //!< Used as flag to indicate that a call to Open() has loaded the recipe.
            String_t m_recipeFileName;                  //!< The filename passed in the constructor of the smart instant camera class.

            // Members used for implementing the result data handling.
            std::shared_ptr<std::thread> m_ptrGrabLoopThreadDataProcessing;     //!< Performs data processing after grabbing (IsGrabbing/RetrieveResult loop)
            COutputObserver m_recipeOutputObserver;                             //!< Adapter for forwarding the output of the recipe to the smart camera.
            EGrabLoop m_grabLoopType = GrabLoop_ProvidedByUser;                 //!< Used to remember if an CInstantCamera internal grab loop is running.
            EGrabLoop m_grabLoopTypeDataProcessing = GrabLoop_ProvidedByUser;   //!< Used to remember if an grab loop is running in smart instant camera.
            CStickyEventHandler m_stickyImageEventHandler;                      //!< This event handler receives all images that have been grabbed in all modes of operation.

            // internal
            // Members used for implementing the SmartResultEventHandler registry.
            CLock m_smartResultHandlerRegistryLock;    //!< The result lock is required to ensure thread-safe access to the event handler registry.
            class SmartResultEventHandlerData
            {
            public:
                SmartResultEventHandlerData() = default;
                SmartResultEventHandlerData(SmartResultEventHandler_t* pEventHandler, ECleanup cleanUpMode)
                    : m_pEventHandler(pEventHandler)
                    , m_cleanUpMode(cleanUpMode)
                {
                }

                ~SmartResultEventHandlerData()
                {
                    if (m_cleanUpMode == Cleanup_Delete)
                    {
                        // If you get run into problems here check that the event handler
                        // has not constructed on the stack or has already been deleted somewhere else.
                        delete m_pEventHandler;
                    }
                }

                bool isHandler(SmartResultEventHandler_t* pEventHandler)
                {
                    return m_pEventHandler == pEventHandler;
                }

                void OnResult( BaseInstantCameraT& camera, const SmartInstantCameraResult_t& result)
                {
                    if (m_pEventHandler)
                    {
                        // If you run into problems here check that the event handler has not been destroyed while it is registered.
                        // If you place the event handler as member or on the stack it must be declared before the smart instant camera class.
                        m_pEventHandler->OnResult(camera, result);
                    }
                }

                void OnDataProcessingError( BaseInstantCameraT& camera, const char* errorMessage )
                {
                    if (m_pEventHandler)
                    {
                        try
                        {
                            // If you run into problems here check that the event handler has not been destroyed while it is registered.
                            // If you place the event handler as member or on the stack it must be declared before the smart instant camera class.
                            m_pEventHandler->OnDataProcessingError(camera, errorMessage);
                        }
                        catch(...)
                        {
                            // ignore
                        }
                    }
                }

            private:
                SmartResultEventHandler_t* m_pEventHandler = nullptr;
                ECleanup m_cleanUpMode = Cleanup_None;
            };
            std::list<std::shared_ptr<SmartResultEventHandlerData>> m_eventHandlerList; //!< Stores all registered smart result event handlers.
        };

        /// The result type of the smart instant camera based on CInstantCamera.
        typedef SSmartInstantCameraResultT<CGrabResultPtr> SSmartInstantCameraResult;
        /// A smart instant camera based on CInstantCamera.
        typedef CSmartInstantCameraT<CInstantCamera, SSmartInstantCameraResult> CSmartInstantCamera;
    }
}
