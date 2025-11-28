//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2023 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for acA2440-35uc

Sources:
acA2440-35uc 107209-25;U;acA2440_35uc;V1.5-2;1
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BASLERCAMERAEVENTPARAMS_H
#define BASLER_PYLON_BASLERCAMERAEVENTPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for acA2440-35uc
namespace Pylon
{
namespace BaslerCameraEventParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class BaslerCameraEventParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA2440-35uc

    Sources:
    acA2440-35uc 107209-25;U;acA2440_35uc;V1.5-2;1
    */
    class BaslerCameraEventParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCameraEventParams(void);

            //! Destructor
            ~BaslerCameraEventParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCameraEventParams_Data;
        BaslerCameraEventParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: Root
    //@{
    /*!
        \brief Number of buffers to be used - Applies to: acA2440-35uc

        Number of Buffers that are going to be used receiving events.
    
        Visibility: Expert

    */
    Pylon::IIntegerEx& NumBuffer;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Maximum number of USB request blocks (URBs) to be enqueued simultaneously - Applies to: acA2440-35uc

    
        Visibility: Guru

    */
    Pylon::IIntegerEx& NumMaxQueuedUrbs;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Count of processed events with an error status - Applies to: acA2440-35uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Failed_Event_Count;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Status code of the last failed event buffer - Applies to: acA2440-35uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Last_Failed_Event_Buffer_Status;

    //@}


    //! \name Categories: Statistic
    //@{
    /*!
        \brief Total count of processed events - Applies to: acA2440-35uc

    
        Visibility: Expert

    */
    Pylon::IIntegerEx& Statistic_Total_Event_Count;

    //@}


    //! \name Categories: Root
    //@{
    /*!
        \brief Priority of the thread that handles USB requests from the stream interface - Applies to: acA2440-35uc

    
        Visibility: Guru

    */
    Pylon::IIntegerEx& TransferLoopThreadPriority;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCameraEventParams(BaslerCameraEventParams&);

            //! not implemented assignment operator
            BaslerCameraEventParams& operator=(BaslerCameraEventParams&);

        //! \endcond
    };

    //**************************************************************************************************
    // Enumeration support classes
    //**************************************************************************************************
    //! \cond HIDE_CLASS_METHODS

    ///////////////////////////////////////////////////////////////////////////
    //
    namespace EnumParameterClasses
    {
    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BaslerCameraEventParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCameraEventParams::BaslerCameraEventParams_Data
    {
    public:
        Pylon::CIntegerParameter NumBuffer;
        Pylon::CIntegerParameter NumMaxQueuedUrbs;
        Pylon::CIntegerParameter Statistic_Failed_Event_Count;
        Pylon::CIntegerParameter Statistic_Last_Failed_Event_Buffer_Status;
        Pylon::CIntegerParameter Statistic_Total_Event_Count;
        Pylon::CIntegerParameter TransferLoopThreadPriority;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraEventParams::BaslerCameraEventParams(void)
        : m_pData(new BaslerCameraEventParams_Data())
        , NumBuffer(m_pData->NumBuffer)
        , NumMaxQueuedUrbs(m_pData->NumMaxQueuedUrbs)
        , Statistic_Failed_Event_Count(m_pData->Statistic_Failed_Event_Count)
        , Statistic_Last_Failed_Event_Buffer_Status(m_pData->Statistic_Last_Failed_Event_Buffer_Status)
        , Statistic_Total_Event_Count(m_pData->Statistic_Total_Event_Count)
        , TransferLoopThreadPriority(m_pData->TransferLoopThreadPriority)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraEventParams::~BaslerCameraEventParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BaslerCameraEventParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->NumBuffer.Attach(pNodeMap, "NumBuffer");
        m_pData->NumMaxQueuedUrbs.Attach(pNodeMap, "NumMaxQueuedUrbs");
        m_pData->Statistic_Failed_Event_Count.Attach(pNodeMap, "Statistic_Failed_Event_Count");
        m_pData->Statistic_Last_Failed_Event_Buffer_Status.Attach(pNodeMap, "Statistic_Last_Failed_Event_Buffer_Status");
        m_pData->Statistic_Total_Event_Count.Attach(pNodeMap, "Statistic_Total_Event_Count");
        m_pData->TransferLoopThreadPriority.Attach(pNodeMap, "TransferLoopThreadPriority");
    }

    //! \endcond

} // namespace Pylon
} // namespace BaslerCameraEventParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERAEVENTPARAMS_H