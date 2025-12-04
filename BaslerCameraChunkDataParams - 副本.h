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

#ifndef BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H
#define BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H

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
namespace BaslerCameraChunkDataParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for ChunkCounterSelector
    enum ChunkCounterSelectorEnums
    {
        ChunkCounterSelector_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for ChunkGainSelector
    enum ChunkGainSelectorEnums
    {
        ChunkGainSelector_Todo  //!< TODO - Applies to: acA2440-35uc
    };


    
    
    //**************************************************************************************************
    // Parameter class BaslerCameraChunkDataParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA2440-35uc

    Sources:
    acA2440-35uc 107209-25;U;acA2440_35uc;V1.5-2;1
    */
    class BaslerCameraChunkDataParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCameraChunkDataParams(void);

            //! Destructor
            ~BaslerCameraChunkDataParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCameraChunkDataParams_Data;
        BaslerCameraChunkDataParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Sets which counter to retrieve chunk data from - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ChunkCounterValue

    */
    Pylon::IEnumParameterT<ChunkCounterSelectorEnums>& ChunkCounterSelector;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the selected chunk counter - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: ChunkCounterSelector

    */
    Pylon::IIntegerEx& ChunkCounterValue;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Exposure time used to acquire the image - Applies to: acA2440-35uc

    
        Visibility: Beginner

    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Gain used during image acquisition - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: ChunkGainSelector

    */
    Pylon::IFloatEx& ChunkGain;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Sets which gain channel to retrieve chunk data from - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ChunkGain

    */
    Pylon::IEnumParameterT<ChunkGainSelectorEnums>& ChunkGainSelector;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA2440-35uc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief CRC checksum of the acquired image - Applies to: acA2440-35uc

        CRC checksum of the acquired image. The checksum is calculated using all of the image data and all of the appended chunks except for the checksum itself.
    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Index of the active sequencer set - Applies to: acA2440-35uc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkSequencerSetActive;

    //@}


    //! \name Categories: ChunkData
    //@{
    /*!
        \brief Value of the timestamp when the image was acquired - Applies to: acA2440-35uc

    
        Visibility: Beginner

    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCameraChunkDataParams(BaslerCameraChunkDataParams&);

            //! not implemented assignment operator
            BaslerCameraChunkDataParams& operator=(BaslerCameraChunkDataParams&);

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
        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkCounterSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkCounterSelectorEnums>
        {
        public:
            ChunkCounterSelectorEnumParameter()
            {
            }

            virtual ~ChunkCounterSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkGainSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkGainSelectorEnums>
        {
        public:
            ChunkGainSelectorEnumParameter()
            {
            }

            virtual ~ChunkGainSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BaslerCameraChunkDataParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCameraChunkDataParams::BaslerCameraChunkDataParams_Data
    {
    public:
        EnumParameterClasses::ChunkCounterSelectorEnumParameter ChunkCounterSelector;
        Pylon::CIntegerParameter ChunkCounterValue;
        Pylon::CFloatParameter ChunkExposureTime;
        Pylon::CFloatParameter ChunkGain;
        EnumParameterClasses::ChunkGainSelectorEnumParameter ChunkGainSelector;
        Pylon::CIntegerParameter ChunkLineStatusAll;
        Pylon::CIntegerParameter ChunkPayloadCRC16;
        Pylon::CIntegerParameter ChunkSequencerSetActive;
        Pylon::CIntegerParameter ChunkTimestamp;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraChunkDataParams::BaslerCameraChunkDataParams(void)
        : m_pData(new BaslerCameraChunkDataParams_Data())
        , ChunkCounterSelector(m_pData->ChunkCounterSelector)
        , ChunkCounterValue(m_pData->ChunkCounterValue)
        , ChunkExposureTime(m_pData->ChunkExposureTime)
        , ChunkGain(m_pData->ChunkGain)
        , ChunkGainSelector(m_pData->ChunkGainSelector)
        , ChunkLineStatusAll(m_pData->ChunkLineStatusAll)
        , ChunkPayloadCRC16(m_pData->ChunkPayloadCRC16)
        , ChunkSequencerSetActive(m_pData->ChunkSequencerSetActive)
        , ChunkTimestamp(m_pData->ChunkTimestamp)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraChunkDataParams::~BaslerCameraChunkDataParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BaslerCameraChunkDataParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->ChunkCounterSelector.Attach(pNodeMap, "ChunkCounterSelector");
        m_pData->ChunkCounterValue.Attach(pNodeMap, "ChunkCounterValue");
        m_pData->ChunkExposureTime.Attach(pNodeMap, "ChunkExposureTime");
        m_pData->ChunkGain.Attach(pNodeMap, "ChunkGain");
        m_pData->ChunkGainSelector.Attach(pNodeMap, "ChunkGainSelector");
        m_pData->ChunkLineStatusAll.Attach(pNodeMap, "ChunkLineStatusAll");
        m_pData->ChunkPayloadCRC16.Attach(pNodeMap, "ChunkPayloadCRC16");
        m_pData->ChunkSequencerSetActive.Attach(pNodeMap, "ChunkSequencerSetActive");
        m_pData->ChunkTimestamp.Attach(pNodeMap, "ChunkTimestamp");
    }

    //! \endcond

} // namespace Pylon
} // namespace BaslerCameraChunkDataParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERACHUNKDATAPARAMS_H