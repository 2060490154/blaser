//-----------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2025 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief Contains a result data type of a smart instant camera.
*/
#pragma once
#include <pylondataprocessing/Update.h>
#include <pylondataprocessing/VariantContainer.h>

namespace Pylon
{
    namespace DataProcessing
    {
        /*!
        \struct SSmartInstantCameraResultT

        You can create your own result data type using duck typing.
        A smart result class needs the methods:
        void SetGrabResult(const CGrabResultPtr& ptrGrabResult);
        void SetInitialUpdate(const CUpdate& update);
        void SetVariantContainer(const CUpdate& update, CVariantContainer&& container);
        void Release();

        Depending on your use case you can:
        <ul>
            <li> Keep or discard the update object. </li>
            <li> Keep or discard the grab result. </li>
            <li> Unpack the variant container in SetVariantContainer. </li>
        </ul>

         Configure you smart instant camera like this
         typedef CSmartInstantCameraT<CInstantCamera, CMyResultObject> CSmartInstantCamera;

        \brief
            A container for smart camera output data.
        */
        template <typename GrabResultPtrT>
        struct SSmartInstantCameraResultT
        {
            /*!
            \brief Sets the grab result.

            \param[in]  ptrGrabResult The grab result data.

            \error
                Exceptions thrown from this call will stop the grab.

            \threading
                This method is called outside the lock of the camera object but inside the lock of the image event handler registry.
                The thread calling this method is the thread calling RetrieveResult().
                This can be a user thread or the internal grab loop thread of the CInstantCamera.
            */
            void SetGrabResult(const CGrabResultPtr& ptrGrabResult)
            {
                GrabResult = ptrGrabResult;
                PYLON_ASSERT2( GrabResult.IsValid(), "Unexpected condition that the grab result is not convertible." );
            }

            /*!
            \brief Sets the update returned by CRecipe::TriggerUpdateAsync() or an invalid Update if the recipe is not started.

            \param[in]  update The update.

            \error
                Exceptions thrown from this call will stop the grab.

            \threading
                This method is called outside the lock of the camera object but inside the lock of the image event handler registry.
                The thread calling this method is the thread calling RetrieveResult().
                This can be a user thread or the internal grab loop thread of the CInstantCamera.
            */
            void SetInitialUpdate(const CUpdate& update)
            {
                Update = update;
            }

            /*!
            \brief Moves the variant container that contains the result from data processing to this object.

            \param[in]  update The update (from IOutputObserver::OutputDataPush()).
            \param[in]  container The data processing result data (from IOutputObserver::OutputDataPush()).

            \error
                Exceptions thrown from this call will stop the grab.
            \threading
                Running on a thread from the recipe thread pool.
                C++ exceptions thrown by this method are caught and ignored.
            */
            void SetVariantContainer(const CUpdate& update, CVariantContainer&& container)
            {
                PYLON_UNUSED(update);
                Container = container;
                // Info: Instead of storing the container you can unbox the content in your version of the grab result.
                // You can consider using the code generated from the recipe code generator in the pylon Viewer to do that.
            }

            /*!
            \brief The currently held data is released.

            \post The currently held data is released.

            \error
                Still valid after error.

            \threading
                This method is called outside the lock of the camera object.
                The thread calling this method is usually the thread calling RetrieveResult().
                This can be a user thread or the internal grab loop thread of the CInstantCamera.
            */
            void Release()
            {
                Update = CUpdate();
                Container.clear();
                GrabResult.Release();
            }

            CUpdate Update;  //!< The update the output belongs to.
                             //!< Can be used for ordering the results in the order of processing.
                             //!< You can check IsValid() if data processing has been run. It will return false, e.g. if no recipe has been loaded.
            CVariantContainer Container; //!< The output data of the recipe.
            GrabResultPtrT GrabResult;   //!< The grab result that has been used to generate the data in Container;
        };
    }
}
