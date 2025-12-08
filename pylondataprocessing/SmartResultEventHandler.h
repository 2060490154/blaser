//-----------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2025 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/**
\file
\brief Contains the smart result event handler base class.
*/
#pragma once
#include <pylon/stdinclude.h>
#include <pylondataprocessing/SmartResult.h>

namespace Pylon
{
    class CInstantCamera;

    namespace DataProcessing
    {
        /*!
        \class  SmartResultEventHandler
        \brief The configuration event handler base class.
        */
        template <typename BaseInstantCameraT, typename SmartInstantCameraResultT>
        class CSmartResultEventHandlerT
        {
        public:
            //! The type of result produced by this class.
            typedef SmartInstantCameraResultT SmartInstantCameraResult_t;
            virtual ~CSmartResultEventHandlerT()
            {
            }

            /*!
            \brief This method is called when a data processing result is ready.

            \param[in]  camera The source of the call. You can use a downcast to get your specific smart instant camera.
            \param[in]  grabResult The grab result data.

            \error
                Exceptions from this call will propagate through. The notification of event handlers stops when an exception is triggered.

            \code
                // You can use a downcast to get your specific smart instant camera.
                PYLON_ASSERT2( dynamic_cast<MyCamera*>(&camera) != NULL, "Unexpected camera type passed." );
                MyCamera& myCamera = static_cast<MyCamera&>(camera);
            \endcode

            \threading
                This method is called outside the lock of the camera object but inside the lock of the smart result event handler registry.
            */
            virtual void OnResult( BaseInstantCameraT& camera, const SmartInstantCameraResult_t& result)
            {
                PYLON_UNUSED( camera );
                PYLON_UNUSED( result );
            }

            /*!
            \brief This method is called when an exception has been triggered using the data processing recipe.

            An exception has been triggered by the data processing grab loop thread. The grab will be stopped after this event call.

            \param[in]  camera The source of the call. You can use a downcast to get your specific smart instant camera.
            \param[in]  errorMessage The message of the exception that signaled an error during grabbing.

            \error
                C++ exceptions from this call will be caught and ignored. All event handlers are notified.

            \code
                // You can use a downcast to get your specific smart instant camera.
                PYLON_ASSERT2( dynamic_cast<MyCamera*>(&camera) != NULL, "Unexpected camera type passed." );
                MyCamera& myCamera = static_cast<MyCamera&>(camera);
            \endcode

            \threading
                This method is called inside the lock of the camera object.
            */
            virtual void OnDataProcessingError( BaseInstantCameraT& camera, const char* errorMessage )
            {
                PYLON_UNUSED( camera );
                PYLON_UNUSED( errorMessage );
            }
        };
    }
}
