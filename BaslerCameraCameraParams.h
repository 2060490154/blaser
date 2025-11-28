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

#ifndef BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H
#define BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H

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
namespace BaslerCameraCameraParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_Continuous,  //!< The acquisition mode is set to Continuous - Applies to: acA2440-35uc
        AcquisitionMode_SingleFrame  //!< The acquisition mode is set to Single Frame - Applies to: acA2440-35uc
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_FrameBurstTriggerWait,  //!< A check determines whether the camera is currently waiting for a frame burst trigger - Applies to: acA2440-35uc
        AcquisitionStatusSelector_FrameTriggerWait  //!< A check determines whether the camera is currently waiting for a frame trigger - Applies to: acA2440-35uc
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_MinimizeExposureTime,  //!< Exposure time is kept as low as possible - Applies to: acA2440-35uc
        AutoFunctionProfile_MinimizeGain  //!< Gain is kept as low as possible - Applies to: acA2440-35uc
    };

    //! Valid values for AutoFunctionROISelector
    enum AutoFunctionROISelectorEnums
    {
        AutoFunctionROISelector_ROI1,  //!< Auto function ROI 1 can be configured - Applies to: acA2440-35uc
        AutoFunctionROISelector_ROI2  //!< Auto function ROI 2 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialPortBaudRate
    enum BLCSerialPortBaudRateEnums
    {
        BLCSerialPortBaudRate_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialPortParity
    enum BLCSerialPortParityEnums
    {
        BLCSerialPortParity_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialPortSource
    enum BLCSerialPortSourceEnums
    {
        BLCSerialPortSource_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialPortStopBits
    enum BLCSerialPortStopBitsEnums
    {
        BLCSerialPortStopBits_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialReceiveQueueStatus
    enum BLCSerialReceiveQueueStatusEnums
    {
        BLCSerialReceiveQueueStatus_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BLCSerialTransmitQueueStatus
    enum BLCSerialTransmitQueueStatusEnums
    {
        BLCSerialTransmitQueueStatus_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Blue,  //!< Balance ratio is applied to the blue channel - Applies to: acA2440-35uc
        BalanceRatioSelector_Green,  //!< Balance ratio is applied to the green channel - Applies to: acA2440-35uc
        BalanceRatioSelector_Red  //!< Balance ratio is applied to the red channel - Applies to: acA2440-35uc
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Continuous,  //!< White balance is adjusted continuously while images are being acquired - Applies to: acA2440-35uc
        BalanceWhiteAuto_Off,  //!< The Balance White Auto auto function is disabled - Applies to: acA2440-35uc
        BalanceWhiteAuto_Once  //!< White balance is adjusted automatically to reach the specified target value - Applies to: acA2440-35uc
    };

    //! Valid values for BinningHorizontalMode
    enum BinningHorizontalModeEnums
    {
        BinningHorizontalMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BinningVerticalMode
    enum BinningVerticalModeEnums
    {
        BinningVerticalMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All  //!< The black level value is applied to all sensor taps - Applies to: acA2440-35uc
    };

    //! Valid values for BslContrastMode
    enum BslContrastModeEnums
    {
        BslContrastMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightControlErrorStatus
    enum BslLightControlErrorStatusEnums
    {
        BslLightControlErrorStatus_Device1,  //!< Light device 1 is experiencing problems - Applies to: acA2440-35uc
        BslLightControlErrorStatus_Device2,  //!< Light device 2 is experiencing problems - Applies to: acA2440-35uc
        BslLightControlErrorStatus_Device3,  //!< Light device 3 is experiencing problems - Applies to: acA2440-35uc
        BslLightControlErrorStatus_Device4,  //!< Light device 4 is experiencing problems - Applies to: acA2440-35uc
        BslLightControlErrorStatus_MultipleDevices,  //!< Multiple light devices are experiencing problems - Applies to: acA2440-35uc
        BslLightControlErrorStatus_NoError  //!< No error was detected - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightControlMode
    enum BslLightControlModeEnums
    {
        BslLightControlMode_Off,  //!< The light control features are disabled - Applies to: acA2440-35uc
        BslLightControlMode_On  //!< The light control features are enabled - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightControlSource
    enum BslLightControlSourceEnums
    {
        BslLightControlSource_Line3,  //!< Line 3 is used to control the light features - Applies to: acA2440-35uc
        BslLightControlSource_Line4,  //!< Line 4 is used to control the light features - Applies to: acA2440-35uc
        BslLightControlSource_Off  //!< No line is used to control the light features - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightControlStatus
    enum BslLightControlStatusEnums
    {
        BslLightControlStatus_Idle,  //!< No light device has been detected - Applies to: acA2440-35uc
        BslLightControlStatus_Off,  //!< The light control mode is disabled - Applies to: acA2440-35uc
        BslLightControlStatus_Ready,  //!< The light device is ready for use - Applies to: acA2440-35uc
        BslLightControlStatus_Searching,  //!< The controller ist searching for light devices connected to your camera - Applies to: acA2440-35uc
        BslLightControlStatus_Updating  //!< Parameters are being updated - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightControlTriggerMode
    enum BslLightControlTriggerModeEnums
    {
        BslLightControlTriggerMode_ExposureActive,  //!< The Exposure Active signal is used to trigger the light in strobe mode - Applies to: acA2440-35uc
        BslLightControlTriggerMode_FlashWindow  //!< The Flash Window signal is used to trigger the light in strobe mode - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceChangeID
    enum BslLightDeviceChangeIDEnums
    {
        BslLightDeviceChangeID_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceControlMode
    enum BslLightDeviceControlModeEnums
    {
        BslLightDeviceControlMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceLastError
    enum BslLightDeviceLastErrorEnums
    {
        BslLightDeviceLastError_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceOperationMode
    enum BslLightDeviceOperationModeEnums
    {
        BslLightDeviceOperationMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceSelector
    enum BslLightDeviceSelectorEnums
    {
        BslLightDeviceSelector_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslLightDeviceStrobeMode
    enum BslLightDeviceStrobeModeEnums
    {
        BslLightDeviceStrobeMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for BslUSBSpeedMode
    enum BslUSBSpeedModeEnums
    {
        BslUSBSpeedMode_HighSpeed,  //!< The USB port is operating at High Speed - Applies to: acA2440-35uc
        BslUSBSpeedMode_SuperSpeed  //!< The USB port is operating at SuperSpeed - Applies to: acA2440-35uc
    };

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

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_CounterValue,  //!< The Counter Value chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_ExposureTime,  //!< The Exposure Time chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_Gain,  //!< The Gain chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_LineStatusAll,  //!< The Line Status All chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_PayloadCRC16,  //!< The CRC Checksum chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_SequencerSetActive,  //!< The Sequencer Set Active chunk can be enabled - Applies to: acA2440-35uc
        ChunkSelector_Timestamp  //!< The Timestamp chunk can be enabled - Applies to: acA2440-35uc
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Blue,  //!< Colors with a predominant blue component can be adjusted - Applies to: acA2440-35uc
        ColorAdjustmentSelector_Cyan,  //!< Colors with a predominant cyan component can be adjusted - Applies to: acA2440-35uc
        ColorAdjustmentSelector_Green,  //!< Colors with a predominant green component can be adjusted - Applies to: acA2440-35uc
        ColorAdjustmentSelector_Magenta,  //!< Colors with a predominant magenta component can be adjusted - Applies to: acA2440-35uc
        ColorAdjustmentSelector_Red,  //!< Colors with a predominant red component can be adjusted - Applies to: acA2440-35uc
        ColorAdjustmentSelector_Yellow  //!< Colors with a predominant yellow component can be adjusted - Applies to: acA2440-35uc
    };

    //! Valid values for ColorSpace
    enum ColorSpaceEnums
    {
        ColorSpace_RGB,  //!< The color space is set to RGB - Applies to: acA2440-35uc
        ColorSpace_sRGB  //!< The color space is set to sRGB - Applies to: acA2440-35uc
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB  //!< Color transformation from RGB to RGB will be performed - Applies to: acA2440-35uc
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Gain00,  //!< The desired color transformation value can be entered at the position row 0 and column 0 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain01,  //!< The desired color transformation value can be entered at the position row 0 and column 1 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain02,  //!< The desired color transformation value can be entered at the position row 0 and column 2 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain10,  //!< The desired color transformation value can be entered at the position row 1 and column 0 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain11,  //!< The desired color transformation value can be entered at the position row 1 and column 1 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain12,  //!< The desired color transformation value can be entered at the position row 1 and column 2 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain20,  //!< The desired color transformation value can be entered at the position row 2 and column 0 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain21,  //!< The desired color transformation value can be entered at the position row 2 and column 1 - Applies to: acA2440-35uc
        ColorTransformationValueSelector_Gain22  //!< The desired color transformation value can be entered at the position row 2 and column 2 - Applies to: acA2440-35uc
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameStart  //!< The selected counter counts the number of Frame Start events - Applies to: acA2440-35uc
    };

    //! Valid values for CounterResetActivation
    enum CounterResetActivationEnums
    {
        CounterResetActivation_RisingEdge  //!< The counter is reset on the rising edge of the signal - Applies to: acA2440-35uc
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Counter2End,  //!< The selected counter can be reset by a Counter End 2 signal - Applies to: acA2440-35uc
        CounterResetSource_Line1,  //!< The selected counter can be reset by a signal applied to Line 1 - Applies to: acA2440-35uc
        CounterResetSource_Line3,  //!< The selected counter can be reset by a signal applied to Line 3 - Applies to: acA2440-35uc
        CounterResetSource_Line4,  //!< The selected counter can be reset by a signal applied to Line 4 - Applies to: acA2440-35uc
        CounterResetSource_Off,  //!< The counter reset is disabled - Applies to: acA2440-35uc
        CounterResetSource_Software  //!< The selected counter can be reset by a software command - Applies to: acA2440-35uc
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1,  //!< Counter 1 can be configured - Applies to: acA2440-35uc
        CounterSelector_Counter2  //!< Counter 2 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for DemosaicingMode
    enum DemosaicingModeEnums
    {
        DemosaicingMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for DeviceLinkThroughputLimitMode
    enum DeviceLinkThroughputLimitModeEnums
    {
        DeviceLinkThroughputLimitMode_Off,  //!< The Device Link Throughput Limit parameter is disabled - Applies to: acA2440-35uc
        DeviceLinkThroughputLimitMode_On  //!< The Device Link Throughput Limit parameter is enabled - Applies to: acA2440-35uc
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!< The camera has an area scan sensor - Applies to: acA2440-35uc
        DeviceScanType_Linescan  //!< The camera has a line scan sensor - Applies to: acA2440-35uc
    };

    //! Valid values for DeviceTemperatureSelector
    enum DeviceTemperatureSelectorEnums
    {
        DeviceTemperatureSelector_Coreboard  //!< The temperature is measured on the core board - Applies to: acA2440-35uc
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!< Event notifications are disabled - Applies to: acA2440-35uc
        EventNotification_On  //!< Event notifications are enabled - Applies to: acA2440-35uc
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_CriticalTemperature,  //!< Event notifications for the Critical Temperature event can be enabled - Applies to: acA2440-35uc
        EventSelector_ExposureEnd,  //!< Event notifications for the Exposure End event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameBurstStart,  //!< Event notifications for the Frame Burst Start event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameBurstStartOvertrigger,  //!< Event notifications for the Frame Burst Start Overtrigger event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameBurstStartWait,  //!< Event notifications for the Frame Burst Start Wait event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameStart,  //!< Event notifications for the Frame Start event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameStartOvertrigger,  //!< Event notifications for the Frame Start Overtrigger event can be enabled - Applies to: acA2440-35uc
        EventSelector_FrameStartWait,  //!< Event notifications for the Frame Start Wait event can be enabled - Applies to: acA2440-35uc
        EventSelector_OverTemperature  //!< Event notifications for the Over Temperature event can be enabled - Applies to: acA2440-35uc
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1,  //!< Expert Feature 1 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature10,  //!< Expert Feature 10 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature11,  //!< Expert feature 11 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature2,  //!< Expert Feature 2 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature3,  //!< Expert Feature 3 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature4,  //!< Expert Feature 4 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature5,  //!< Expert Feature 5 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature6,  //!< Expert Feature 6 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature7,  //!< Expert Feature 7 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature8,  //!< Expert Feature 8 can be configured - Applies to: acA2440-35uc
        ExpertFeatureAccessSelector_ExpertFeature9  //!< Expert Feature 9 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Continuous,  //!< The exposure time is adjusted continuously while images are being acquired - Applies to: acA2440-35uc
        ExposureAuto_Off,  //!< Automatic exposure time adjustment is disabled - Applies to: acA2440-35uc
        ExposureAuto_Once  //!< The exposure time is adjusted automatically to reach the specified target value - Applies to: acA2440-35uc
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!< The exposure mode is set to Timed - Applies to: acA2440-35uc
        ExposureMode_TriggerWidth  //!< The exposure mode is set to Trigger Width - Applies to: acA2440-35uc
    };

    //! Valid values for ExposureOverlapTimeMode
    enum ExposureOverlapTimeModeEnums
    {
        ExposureOverlapTimeMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for ExposureTimeMode
    enum ExposureTimeModeEnums
    {
        ExposureTimeMode_Standard,  //!< The exposure time mode is set to Standard - Applies to: acA2440-35uc
        ExposureTimeMode_UltraShort  //!< The exposure time mode is set to Ultra Short - Applies to: acA2440-35uc
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!< Files are opened in read-only mode - Applies to: acA2440-35uc
        FileOpenMode_Write  //!< Files are opened in write-only mode - Applies to: acA2440-35uc
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Close,  //!< The currently selected file can be closed - Applies to: acA2440-35uc
        FileOperationSelector_Open,  //!< The currently selected file can be opened - Applies to: acA2440-35uc
        FileOperationSelector_Read,  //!< The currently selected file can be read - Applies to: acA2440-35uc
        FileOperationSelector_Write  //!< The currently selected file can be written to - Applies to: acA2440-35uc
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Failure,  //!< The file operation has failed - Applies to: acA2440-35uc
        FileOperationStatus_Success  //!< The file operation was successful - Applies to: acA2440-35uc
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_ExpertFeature7File,  //!< The Expert Feature 7 File file is selected - Applies to: acA2440-35uc
        FileSelector_UserData,  //!< The User Data file is selected - Applies to: acA2440-35uc
        FileSelector_UserGainShading1,  //!< The User Gain Shading 1 file is selected - Applies to: acA2440-35uc
        FileSelector_UserGainShading2,  //!< The User Gain Shading 2 file is selected - Applies to: acA2440-35uc
        FileSelector_UserOffsetShading1,  //!< The User Offset Shading 1 file is selected - Applies to: acA2440-35uc
        FileSelector_UserOffsetShading2,  //!< The User Offset Shading 2 file is selected - Applies to: acA2440-35uc
        FileSelector_UserSet1,  //!< The User Set 1 file is selected - Applies to: acA2440-35uc
        FileSelector_UserSet2,  //!< The User Set 2 file is selected - Applies to: acA2440-35uc
        FileSelector_UserSet3,  //!< The User Set 3 file is selected - Applies to: acA2440-35uc
        FileSelector_VignettingCorrection  //!< The 'VignettingCorrection' file is set - Applies to: acA2440-35uc
    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Continuous,  //!< The gain is adjusted continuously while images are being acquired - Applies to: acA2440-35uc
        GainAuto_Off,  //!< Automatic gain adjustment is disabled - Applies to: acA2440-35uc
        GainAuto_Once  //!< The gain is adjusted automatically to reach the specifed target value - Applies to: acA2440-35uc
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All  //!< Changes to the gain will be applied universally - Applies to: acA2440-35uc
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance  //!< The luminance lookup table can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for LightSourcePreset
    enum LightSourcePresetEnums
    {
        LightSourcePreset_Daylight5000K,  //!< The light source preset for image acquisitions with daylight of 5000 K is selected - Applies to: acA2440-35uc
        LightSourcePreset_Daylight6500K,  //!< The light source preset for image acquisitions with daylight of 6500 K is selected - Applies to: acA2440-35uc
        LightSourcePreset_Off,  //!< No light source preset is selected - Applies to: acA2440-35uc
        LightSourcePreset_Tungsten2800K  //!< The light source preset for image acquisitions with tungsten incandescent light (2800 K) is selected - Applies to: acA2440-35uc
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_OptoCoupled,  //!< The line is opto-coupled - Applies to: acA2440-35uc
        LineFormat_TTL  //!< The line is currently accepting or sending TTL level signals - Applies to: acA2440-35uc
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Negative,  //!< The line logic of the currently selected line is negative - Applies to: acA2440-35uc
        LineLogic_Positive  //!< The line logic of the currently selected line is positive - Applies to: acA2440-35uc
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!< The selected physical line can be used to input an electrical signal - Applies to: acA2440-35uc
        LineMode_Output  //!< The selected physical line can be used to output an electrical signal - Applies to: acA2440-35uc
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!< Line 1 can be configured - Applies to: acA2440-35uc
        LineSelector_Line2,  //!< Line 2 can be configured - Applies to: acA2440-35uc
        LineSelector_Line3,  //!< Line 3 can be configured - Applies to: acA2440-35uc
        LineSelector_Line4  //!< Line 4 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for PgiMode
    enum PgiModeEnums
    {
        PgiMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_BayerBG,  //!< The Bayer filter has a BG/GR alignment to the pixels in the acquired images - Applies to: acA2440-35uc
        PixelColorFilter_BayerGB,  //!< The Bayer filter has a GB/RG alignment to the pixels in the acquired images - Applies to: acA2440-35uc
        PixelColorFilter_BayerGR,  //!< The Bayer filter has a GR/BG alignment to the pixels in the acquired images - Applies to: acA2440-35uc
        PixelColorFilter_BayerRG,  //!< The Bayer filter has an RG/GB alignment to the pixels in the acquired images - Applies to: acA2440-35uc
        PixelColorFilter_None  //!< The camera doesn't have a Bayer filter - Applies to: acA2440-35uc
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_BGR8,  //!< The pixel format is set to BGR 8 - Applies to: acA2440-35uc
        PixelFormat_BayerBG12,  //!< The pixel format is set to Bayer BG 12 - Applies to: acA2440-35uc
        PixelFormat_BayerBG12p,  //!< The pixel format is set to Bayer BG 12p - Applies to: acA2440-35uc
        PixelFormat_BayerBG8,  //!< The pixel format is set to Bayer BG 8 - Applies to: acA2440-35uc
        PixelFormat_BayerGB12,  //!< The pixel format is set to Bayer GB 12 - Applies to: acA2440-35uc
        PixelFormat_BayerGB12p,  //!< The pixel format is set to Bayer GB 12p - Applies to: acA2440-35uc
        PixelFormat_BayerGB8,  //!< The pixel format is set to Bayer GB 8 - Applies to: acA2440-35uc
        PixelFormat_BayerGR12,  //!< The pixel format is set to Bayer GR 12 - Applies to: acA2440-35uc
        PixelFormat_BayerGR12p,  //!< The pixel format is set to Bayer GR 12p - Applies to: acA2440-35uc
        PixelFormat_BayerGR8,  //!< The pixel format is set to Bayer GR 8 - Applies to: acA2440-35uc
        PixelFormat_BayerRG12,  //!< The pixel format is set to Bayer RG 12 - Applies to: acA2440-35uc
        PixelFormat_BayerRG12p,  //!< The pixel format is set to Bayer RG 12p - Applies to: acA2440-35uc
        PixelFormat_BayerRG8,  //!< The pixel format is set to Bayer RG 8 - Applies to: acA2440-35uc
        PixelFormat_Mono8,  //!< The pixel format is set to Mono 8 - Applies to: acA2440-35uc
        PixelFormat_RGB8,  //!< The pixel format is set to RGB 8 - Applies to: acA2440-35uc
        PixelFormat_YCbCr422_8  //!< The pixel format is set to YCbCr 422 - Applies to: acA2440-35uc
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp10,  //!< The pixel depth in the acquired images is 10 bits per pixel - Applies to: acA2440-35uc
        PixelSize_Bpp12,  //!< The pixel depth in the acquired images is 12 bits per pixel - Applies to: acA2440-35uc
        PixelSize_Bpp16,  //!< The pixel depth in the acquired images is 16 bits per pixel - Applies to: acA2440-35uc
        PixelSize_Bpp24,  //!< The pixel depth in the acquired images is 24 bits per pixel - Applies to: acA2440-35uc
        PixelSize_Bpp8  //!< The pixel depth in the acquired images is 8 bits per pixel - Applies to: acA2440-35uc
    };

    //! Valid values for ROIZoneMode
    enum ROIZoneModeEnums
    {
        ROIZoneMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for ROIZoneSelector
    enum ROIZoneSelectorEnums
    {
        ROIZoneSelector_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for RemoveParameterLimitSelector
    enum RemoveParameterLimitSelectorEnums
    {
        RemoveParameterLimitSelector_Gain  //!< The factory limits of the Gain parameter can be removed - Applies to: acA2440-35uc
    };

    //! Valid values for SensorReadoutMode
    enum SensorReadoutModeEnums
    {
        SensorReadoutMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };

    //! Valid values for SequencerConfigurationMode
    enum SequencerConfigurationModeEnums
    {
        SequencerConfigurationMode_Off,  //!< The sequencer can't be configured - Applies to: acA2440-35uc
        SequencerConfigurationMode_On  //!< The sequencer can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for SequencerMode
    enum SequencerModeEnums
    {
        SequencerMode_Off,  //!< Image acquisitions can't be controlled by the sequencer - Applies to: acA2440-35uc
        SequencerMode_On  //!< Image acquisitions will be controlled by the sequencer - Applies to: acA2440-35uc
    };

    //! Valid values for SequencerTriggerActivation
    enum SequencerTriggerActivationEnums
    {
        SequencerTriggerActivation_LevelHigh  //!< The sequence set will advance when the source signal is high - Applies to: acA2440-35uc
    };

    //! Valid values for SequencerTriggerSource
    enum SequencerTriggerSourceEnums
    {
        SequencerTriggerSource_Counter2End,  //!< Sequencer set advance is controlled using Counter 2 End - Applies to: acA2440-35uc
        SequencerTriggerSource_FrameStart,  //!< Sequencer set advance is controlled using Frame Start signals - Applies to: acA2440-35uc
        SequencerTriggerSource_Line1,  //!< Sequencer set advance is controlled using Line 1 - Applies to: acA2440-35uc
        SequencerTriggerSource_Line3,  //!< Sequencer set advance is controlled using Line 3 - Applies to: acA2440-35uc
        SequencerTriggerSource_Line4,  //!< Sequencer set advance is controlled using Line 4 - Applies to: acA2440-35uc
        SequencerTriggerSource_SoftwareSignal1,  //!< Sequencer set advance is controlled using software signal 1 - Applies to: acA2440-35uc
        SequencerTriggerSource_SoftwareSignal2,  //!< Sequencer set advance is controlled using software signal 2 - Applies to: acA2440-35uc
        SequencerTriggerSource_SoftwareSignal3  //!< Sequencer set advance is controlled using software signal 3 - Applies to: acA2440-35uc
    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_Global  //!< The shutter opens and closes at the same time for all pixels - Applies to: acA2440-35uc
    };

    //! Valid values for SoftwareSignalSelector
    enum SoftwareSignalSelectorEnums
    {
        SoftwareSignalSelector_SoftwareSignal1,  //!< Software signal 1 can be executed - Applies to: acA2440-35uc
        SoftwareSignalSelector_SoftwareSignal2,  //!< Software signal 2 can be executed - Applies to: acA2440-35uc
        SoftwareSignalSelector_SoftwareSignal3  //!< Software signal 3 can be executed - Applies to: acA2440-35uc
    };

    //! Valid values for TemperatureState
    enum TemperatureStateEnums
    {
        TemperatureState_Critical,  //!< The temperature is critical - Applies to: acA2440-35uc
        TemperatureState_Error,  //!< The temperature state could not be retrieved - Applies to: acA2440-35uc
        TemperatureState_Ok  //!< The temperature is normal - Applies to: acA2440-35uc
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!< The camera doesn't display a test image - Applies to: acA2440-35uc
        TestImageSelector_Testimage1,  //!< The camera generates a test image with the test image 1 pattern - Applies to: acA2440-35uc
        TestImageSelector_Testimage2,  //!< The camera generates a test image with the test image 2 pattern - Applies to: acA2440-35uc
        TestImageSelector_Testimage3,  //!< The camera generates a test image with the test image 3 pattern - Applies to: acA2440-35uc
        TestImageSelector_Testimage4,  //!< The camera generates a test image with the test image 4 pattern - Applies to: acA2440-35uc
        TestImageSelector_Testimage5,  //!< The camera generates a test image with the test image 5 pattern - Applies to: acA2440-35uc
        TestImageSelector_Testimage6  //!< The camera generates a test image with the test image 6 pattern - Applies to: acA2440-35uc
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1  //!< Timer 1 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart  //!< The timer will start at an Exposure Start signal - Applies to: acA2440-35uc
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_FallingEdge,  //!< The selected trigger is activated by the falling edge of the source signal - Applies to: acA2440-35uc
        TriggerActivation_RisingEdge  //!< The selected trigger is activated by the rising edge of the source signal - Applies to: acA2440-35uc
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!< The currently selected trigger is turned off - Applies to: acA2440-35uc
        TriggerMode_On  //!< The currently selected trigger is turned on - Applies to: acA2440-35uc
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameBurstStart,  //!< The Frame Burst Start trigger can be configured - Applies to: acA2440-35uc
        TriggerSelector_FrameStart  //!< The Frame Start trigger can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Line1,  //!< The source signal for the selected trigger is set to Line 1 - Applies to: acA2440-35uc
        TriggerSource_Line3,  //!< The source signal for the selected trigger is set to Line 3 - Applies to: acA2440-35uc
        TriggerSource_Line4,  //!< The source signal for the selected trigger is set to Line 4 - Applies to: acA2440-35uc
        TriggerSource_Software,  //!< The source signal for the selected trigger is set to software triggering - Applies to: acA2440-35uc
        TriggerSource_SoftwareSignal1,  //!< The source signal for the selected trigger is set to software signal 1 - Applies to: acA2440-35uc
        TriggerSource_SoftwareSignal2,  //!< The source signal for the selected trigger is set to software signal 2 - Applies to: acA2440-35uc
        TriggerSource_SoftwareSignal3  //!< The source signal for the selected trigger is set to software signal 3 - Applies to: acA2440-35uc
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!< The user-defined value 1 can be configured - Applies to: acA2440-35uc
        UserDefinedValueSelector_Value2,  //!< The user-defined value 2 can be configured - Applies to: acA2440-35uc
        UserDefinedValueSelector_Value3,  //!< The user-defined value 3 can be configured - Applies to: acA2440-35uc
        UserDefinedValueSelector_Value4,  //!< The user-defined value 4 can be configured - Applies to: acA2440-35uc
        UserDefinedValueSelector_Value5  //!< The user-defined value 5 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!< The user-settable output signal 1 can be configured - Applies to: acA2440-35uc
        UserOutputSelector_UserOutput2,  //!< The user-settable output signal 2 can be configured - Applies to: acA2440-35uc
        UserOutputSelector_UserOutput3  //!< The user-settable output signal 3 can be configured - Applies to: acA2440-35uc
    };

    //! Valid values for UserSetDefault
    enum UserSetDefaultEnums
    {
        UserSetDefault_AutoFunctions,  //!< The Auto Functions factory set is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_ColorRaw,  //!< The Color Raw factory set is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_Default,  //!< The Default User Set factory set is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_HighGain,  //!< The High Gain factory set is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_UserSet1,  //!< User set 1 is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_UserSet2,  //!< User set 2 is set as the default startup set - Applies to: acA2440-35uc
        UserSetDefault_UserSet3  //!< User set 3 is set as the default startup set - Applies to: acA2440-35uc
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_AutoFunctions,  //!< The Auto Functions factory set can be loaded - Applies to: acA2440-35uc
        UserSetSelector_ColorRaw,  //!< The Color Raw factory set can be loaded - Applies to: acA2440-35uc
        UserSetSelector_Default,  //!< The Default User Set factory set can be loaded - Applies to: acA2440-35uc
        UserSetSelector_HighGain,  //!< The High Gain factory set can be loaded - Applies to: acA2440-35uc
        UserSetSelector_UserSet1,  //!< User set 1 can be saved, loaded, or configured - Applies to: acA2440-35uc
        UserSetSelector_UserSet2,  //!< User set 2 can be saved, loaded, or configured - Applies to: acA2440-35uc
        UserSetSelector_UserSet3  //!< User set 3 can be saved, loaded, or configured - Applies to: acA2440-35uc
    };

    //! Valid values for VignettingCorrectionMode
    enum VignettingCorrectionModeEnums
    {
        VignettingCorrectionMode_Todo  //!< TODO - Applies to: acA2440-35uc
    };


    
    
    //**************************************************************************************************
    // Parameter class BaslerCameraCameraParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for acA2440-35uc

    Sources:
    acA2440-35uc 107209-25;U;acA2440_35uc;V1.5-2;1
    */
    class BaslerCameraCameraParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BaslerCameraCameraParams(void);

            //! Destructor
            ~BaslerCameraCameraParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BaslerCameraCameraParams_Data;
        BaslerCameraCameraParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Number of frames to acquire for each Frame Burst Start trigger - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionBurstFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionBurstFrameCount;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Acquisition frame rate of the camera in frames per second - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRate;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Enables setting the camera's acquisition frame rate to a specified value - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionFrameRateEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the image acquisition mode - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionModeEnums>& AcquisitionMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Starts the acquisition of images - Applies to: acA2440-35uc

        Starts the acquisition of images. If the camera is configured for single frame acquisition, it will start the acquisition of one frame. If the camera is configured for continuous frame acquisition, it will start the continuous acquisition of frames.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStart;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Indicates whether the camera is waiting for trigger signals - Applies to: acA2440-35uc

        Indicates whether the camera is waiting for trigger signals. You should only use this feature if the camera is configured for software triggering. If the camera is configured for hardware triggering, monitor the camera's Trigger Wait signals instead.
    
        Visibility: Expert

        Selected by: AcquisitionStatusSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionStatus;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the signal whose status you want to check - Applies to: acA2440-35uc

        Sets the signal whose status you want to check. Its status can be checked by reading the Acquisition Status parameter value.
    
        Visibility: Expert

        Selecting Parameters: AcquisitionStatus

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatusSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionStatusSelectorEnums>& AcquisitionStatusSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Stops the acquisition of images - Applies to: acA2440-35uc

        Stops the acquisition of images if a continuous image acquisition is in progress.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStop" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStop;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Lower limit of the Exposure Time parameter when the Exposure Auto auto function is active - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeLowerLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Upper limit of the Exposure Time parameter when the Exposure Auto auto function is active - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeUpperLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Sets how gain and exposure time will be balanced when the camera is making automatic adjustments - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionProfile" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionProfileEnums>& AutoFunctionProfile;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Height of the auto function ROI (in pixels) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIHeight;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Horizontal offset of the auto function ROI from the left side of the sensor (in pixels) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetX;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Vertical offset from the top of the sensor to the auto function ROI (in pixels) - Applies to: acA2440-35uc

        Vertical offset of the auto function ROI from the top of the sensor (in pixels).
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetY;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Sets which auto function ROI can be configured - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selecting Parameters: AutoFunctionROIWidth, AutoFunctionROIHeight, AutoFunctionROIOffsetX, AutoFunctionROIOffsetY, AutoFunctionROIUseBrightness and AutoFunctionROIUseWhiteBalance

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionROISelectorEnums>& AutoFunctionROISelector;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Assigns the Gain Auto and the Exposure Auto auto functions to the currently selected auto function ROI - Applies to: acA2440-35uc

        Assigns the Gain Auto and the Exposure Auto auto functions to the currently selected auto function ROI. For this parameter, Gain Auto and Exposure Auto are considered as a single auto function named 'Brightness'.
    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseBrightness;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Assigns the Balance White Auto auto function to the currently selected auto function ROI - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseWhiteBalance;

    //@}


    //! \name Categories: AutoFunctionROIControl
    //@{
    /*!
        \brief Width of the auto function ROI (in pixels) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIWidth;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Lower limit of the Gain parameter when the Gain Auto auto function is active - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainLowerLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Upper limit of the Gain parameter when the Gain Auto auto function is active - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainUpperLimit;

    //@}


    //! \name Categories: AutoFunctionControl
    //@{
    /*!
        \brief Target brightness for the Gain Auto and the Exposure Auto auto functions - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoTargetBrightness;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief A serial framing error occurred on reception - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialFramingError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& BLCSerialFramingError;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief A serial parity error occurred on reception - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialParityError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& BLCSerialParityError;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the baud rate of the serial communication module - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortBaudRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortBaudRateEnums>& BLCSerialPortBaudRate;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Clears the error flags of the serial communication module - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortClearErrors" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortClearErrors;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the parity bit configuration of the serial communication module - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortParity" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortParityEnums>& BLCSerialPortParity;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reads and removes the front byte value from the serial communication receive queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortReceiveCmd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortReceiveCmd;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Last byte value read from the serial communication receive queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortReceiveValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BLCSerialPortReceiveValue;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Sets the signal source for the serial communication module - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortSourceEnums>& BLCSerialPortSource;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the number of stop bits used by the serial communication module - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortStopBits" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialPortStopBitsEnums>& BLCSerialPortStopBits;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Writes the current byte value to the transmit queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortTransmitCmd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BLCSerialPortTransmitCmd;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Byte value to be written to the transmit queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialPortTransmitValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BLCSerialPortTransmitValue;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the status of the serial communication receive queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialReceiveQueueStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialReceiveQueueStatusEnums>& BLCSerialReceiveQueueStatus;

    //@}


    //! \name Categories: BLCSerialPortControl
    //@{
    /*!
        \brief Reports the status of the serial communication transmit queue - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BLCSerialTransmitQueueStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BLCSerialTransmitQueueStatusEnums>& BLCSerialTransmitQueueStatus;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Balance Ratio value to be applied to the currently selected channel - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatio" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceRatio;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which color channel can be adjusted when performing manual white balance - Applies to: acA2440-35uc

        Sets which color channel can be adjusted when performing manual white balance. All changes to the Balance Ratio parameter will be applied to the selected color channel.
    
        Visibility: Beginner

        Selecting Parameters: BalanceRatio

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceRatioSelectorEnums>& BalanceRatioSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the operation mode of the Balance White Auto auto function - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceWhiteAutoEnums>& BalanceWhiteAuto;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Number of adjacent horizontal pixels to be summed - Applies to: acA2440-35uc

        Number of adjacent horizontal pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningHorizontal;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the binning mode for horizontal binning - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningHorizontalModeEnums>& BinningHorizontalMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Number of adjacent vertical pixels to be summed - Applies to: acA2440-35uc

        Number of adjacent vertical pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningVertical;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the binning mode for vertical binning - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVerticalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningVerticalModeEnums>& BinningVerticalMode;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Black level value to be applied to the currently selected sensor tap - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevel" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BlackLevel;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Sets which sensor tap can be configured - Applies to: acA2440-35uc

        Sets which sensor tap can be configured. All changes to the Black Level parameter will be applied to the selected sensor tap.
    
        Visibility: Beginner

        Selecting Parameters: BlackLevel

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BlackLevelSelectorEnums>& BlackLevelSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Brightness value to be applied - Applies to: acA2440-35uc

        Adjusting the brightness lightens or darkens the entire image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslBrightness;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Contrast value to be applied - Applies to: acA2440-35uc

        Adjusting the contrast increases the difference between light and dark areas in the image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrast" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslContrast;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the contrast mode - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrastMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslContrastModeEnums>& BslContrastMode;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue shift value to be applied - Applies to: acA2440-35uc

        Adjusting the hue shifts the colors of the image. This can be useful, e.g., to correct minor color shifts or to create false-color images.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslHue;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Searches for light devices connected to your camera - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlEnumerateDevices" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BslLightControlEnumerateDevices;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates whether any of the light devices are currently experiencing problems - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlErrorStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlErrorStatusEnums>& BslLightControlErrorStatus;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Enables/disables the light control features - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlModeEnums>& BslLightControlMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which line is used to control the light features - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlSourceEnums>& BslLightControlSource;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates the current state of the control mode - Applies to: acA2440-35uc

        Indicates the current state of the light control mode.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlStatusEnums>& BslLightControlStatus;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which signal is used to trigger the light in strobe mode - Applies to: acA2440-35uc

        Sets which signal is used to trigger the light in strobe mode. The default setting is Exposure Active.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightControlTriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightControlTriggerModeEnums>& BslLightControlTriggerMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Brightness of the light in percent of total brightness available - Applies to: acA2440-35uc

        Brightness of the light in percent of total brightness available. Setting this parameter to 100 % means that the light device draws the maximum current as specified by the the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceBrightness;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Changes the ID of the currently selected light device - Applies to: acA2440-35uc

        Changes the ID of the currently selected light device. The new ID will be assigned immediately.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceChangeID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceChangeIDEnums>& BslLightDeviceChangeID;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Clears the last light device error - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceClearLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BslLightDeviceClearLastError;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets how the light device is controlled - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceControlMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceControlModeEnums>& BslLightDeviceControlMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Version of the light device's firmware   - Applies to: acA2440-35uc

        Version of the light device's firmware.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslLightDeviceFirmwareVersion;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Indicates the last light device error - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceLastErrorEnums>& BslLightDeviceLastError;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current that the light device is going to use - Applies to: acA2440-35uc

        Maximum current that the light device is going to use. The value should not exceed the power rating of the device. To change the setting, the Light Device Operation Mode parameter must be set to Off.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceMaxCurrent" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceMaxCurrent;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Name of the light device model - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslLightDeviceModelName;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets the operation mode of the light device - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceOperationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceOperationModeEnums>& BslLightDeviceOperationMode;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Maximum current to be used when operating the light device in overdrive - Applies to: acA2440-35uc

        Maximum current to be used when operating the light device in overdrive. This parameter value is relative to the value of the Light Device Max Current parameter.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceOverdriveLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceOverdriveLimit;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets which light device can be configured - Applies to: acA2440-35uc

        Sets which light device can be configured. To populate the list, use the Light Control Enumerate Devices command first. All subsequent parameter changes in this category will be applied to the device selected here.
    
        Visibility: Expert

        Selecting Parameters: BslLightDeviceControlMode, BslLightDeviceMaxCurrent, BslLightDeviceBrightness, BslLightDeviceOperationMode, BslLightDeviceStrobeMode, BslLightDeviceStrobeDuration, BslLightDeviceOverdriveLimit, BslLightDeviceLastError, BslLightDeviceClearLastError, BslLightDeviceChangeID, BslLightDeviceModelName and BslLightDeviceFirmwareVersion

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceSelectorEnums>& BslLightDeviceSelector;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Duration of the individual strobe pulses - Applies to: acA2440-35uc

        Duration of the individual strobe pulses. The maximum value is 655 350 microseconds.
    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceStrobeDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslLightDeviceStrobeDuration;

    //@}


    //! \name Categories: BslLightControl
    //@{
    /*!
        \brief Sets the strobe mode of the light device - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: BslLightDeviceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslLightDeviceStrobeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslLightDeviceStrobeModeEnums>& BslLightDeviceStrobeMode;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation value to be applied - Applies to: acA2440-35uc

        Adjusting the saturation changes the colorfulness (intensity) of the colors. A higher saturation, for example, makes colors easier to distinguish.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslSaturation;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Indicates the speed mode of the USB port - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslUSBSpeedMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslUSBSpeedModeEnums>& BslUSBSpeedMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Centers the image horizontally - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Centers the image vertically - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterY;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Sets which counter to retrieve chunk data from - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ChunkCounterValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkCounterSelectorEnums>& ChunkCounterSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Value of the selected chunk counter - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: ChunkCounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkCounterValue;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Includes the currently selected chunk in the payload data - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: ChunkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkEnable;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Exposure time used to acquire the image - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkExposureTime;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Gain used during image acquisition - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: ChunkGainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkGain;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Sets which gain channel to retrieve chunk data from - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ChunkGain

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkGainSelectorEnums>& ChunkGainSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineStatusAll;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Enables the chunk mode - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkModeActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkModeActive;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief CRC checksum of the acquired image - Applies to: acA2440-35uc

        CRC checksum of the acquired image. The checksum is calculated using all of the image data and all of the appended chunks except for the checksum itself.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPayloadCRC16" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;

    //@}


    //! \name Categories: ChunkDataControl
    //@{
    /*!
        \brief Sets which chunk can be enabled - Applies to: acA2440-35uc

        Sets which chunk can be enabled. The chunk can be enabled using the Chunk Enable parameter.
    
        Visibility: Beginner

        Selecting Parameters: ChunkEnable

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkSelectorEnums>& ChunkSelector;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Index of the active sequencer set - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSequencerSetActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkSequencerSetActive;

    //@}


    //! \name Categories: ChunkDataControl and ChunkData
    //@{
    /*!
        \brief Value of the timestamp when the image was acquired - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTimestamp;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Hue adjustment value to be applied to the currently selected color channel - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentHue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Saturation adjustment value to be applied to the currently selected color channel - Applies to: acA2440-35uc

        Saturation adjustment value  to be applied to the currently selected color channel.
    
        Visibility: Expert

        Selected by: ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentSaturation;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which color in your images will be adjusted - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ColorAdjustmentHue and ColorAdjustmentSaturation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorAdjustmentSelectorEnums>& ColorAdjustmentSelector;

    //@}


    //! \name Categories: AnalogControl and ImageQualityControl
    //@{
    /*!
        \brief Sets the color space for image acquisitions - Applies to: acA2440-35uc

        Sets the color space for image acquisitions. Note that the gamma correction value also influences the perception of brightness in the resulting images.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorSpace" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorSpaceEnums>& ColorSpace;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which type of color transformation will be performed - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selecting Parameters: ColorTransformationValueSelector and ColorTransformationValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationSelectorEnums>& ColorTransformationSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Transformation value for the selected element in the color transformation matrix - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selected by: ColorTransformationSelector and ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationValue;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets which element will be entered in the color transformation matrix - Applies to: acA2440-35uc

        Sets which element will be entered in the color transformation matrix. Depending on the camera model, some elements in the color transformation matrix may be preset and can't be changed.
    
        Visibility: Guru

        Selected by: ColorTransformationSelector

        Selecting Parameters: ColorTransformationValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationValueSelectorEnums>& ColorTransformationValueSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Number of times a sequencer set is used before the Counter End event is generated - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CounterDuration;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets which event that increases the currently selected counter - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterEventSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterEventSourceEnums>& CounterEventSource;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Immediately resets the selected counter - Applies to: acA2440-35uc

        Immediately resets the selected counter. The counter starts counting again immediately after the reset.
    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& CounterReset;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets which type of signal transition will reset the counter - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetActivationEnums>& CounterResetActivation;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets which source signal will reset the currently selected counter - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetSourceEnums>& CounterResetSource;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets which counter can be configured - Applies to: acA2440-35uc

        Sets which counter can be configured. All changes to the counter settings will be applied to the selected counter.
    
        Visibility: Beginner

        Selecting Parameters: CounterEventSource, CounterResetSource, CounterResetActivation, CounterReset and CounterDuration

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterSelectorEnums>& CounterSelector;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Horizontal decimation factor - Applies to: acA2440-35uc

        Horizontal decimation factor. This specifies the extent of horizontal sub-sampling of the acquired frame, i.e., it defines how many pixel columns are left out of transmission. This has the net effect of reducing the horizontal resolution (width) of the image by the specified decimation factor. A value of 1 means that the camera performs no horizontal decimation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationHorizontal;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Vertical decimation factor - Applies to: acA2440-35uc

        Vertical decimation factor. This specifies the extent of vertical sub-sampling of the acquired frame, i.e., it defines how many rows are left out of transmission. This has the net effect of reducing the vertical resolution (height) of the image by the specified decimation factor. A value of 1 means that the camera performs no vertical decimation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationVertical;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Sets the demosaicing mode - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DemosaicingMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DemosaicingModeEnums>& DemosaicingMode;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Version of the camera's firmware - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFirmwareVersion;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Actual bandwidth the camera will use - Applies to: acA2440-35uc

        Actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data with the current camera settings.
    
        Visibility: Expert

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkCurrentThroughput" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkCurrentThroughput;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Device link to be configured - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: DeviceLinkCurrentThroughput, DeviceLinkThroughputLimit, DeviceLinkThroughputLimitMode and DeviceLinkSpeed

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Speed of transmission negotiated on the selected link - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSpeed" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSpeed;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Bandwidth limit for data transmission (in bytes per second) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkThroughputLimit;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Enables/disables the device link throughput limit - Applies to: acA2440-35uc

        Enables/disables the device link throughput limit. If disabled, the bandwidth used is determined by the settings of various other parameters, e.g., exposure time or frame rate.
    
        Visibility: Beginner

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimitMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceLinkThroughputLimitModeEnums>& DeviceLinkThroughputLimitMode;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Additional information from the vendor about the camera - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Model name of the camera - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Immediately resets and restarts the camera - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceReset;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Major version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-35uc

        Major version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMajor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Minor version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-35uc

        Minor version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Subminor version number of the SFNC specification that the camera is compatible with - Applies to: acA2440-35uc

        Subminor version number of the Standard Features Naming Convention (SFNC) specification that the camera is compatible with.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionSubMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionSubMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the scan type of the camera's sensor (area or line scan) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceScanType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceScanTypeEnums>& DeviceScanType;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Serial number of the camera - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSerialNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceSerialNumber;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Temperature at the selected location in the camera (in degrees centigrade) - Applies to: acA2440-35uc

        Temperature at the selected location in the camera (in degrees centigrade). The temperature is measured at the location specified by the Device Temperature Selector parameter.
    
        Visibility: Expert

        Selected by: DeviceTemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& DeviceTemperature;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Sets the location in the camera where the temperature will be measured - Applies to: acA2440-35uc

        Sets the location in the camera where the temperature will be measured. The temperature can be retrieved using the Device Temperature parameter.
    
        Visibility: Expert

        Selecting Parameters: DeviceTemperature

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTemperatureSelectorEnums>& DeviceTemperatureSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief User-settable ID of the camera - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceUserID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceUserID;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Name of the camera vendor - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Version of the camera - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVersion;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Digital shift to be applied - Applies to: acA2440-35uc

        Digital shift allows you to multiply the pixel values in an image. This increases the brightness of the image. If the parameter is set to zero, digital shift is disabled.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DigitalShift" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DigitalShift;

    //@}


    //! \name Categories: EventCriticalTemperatureData
    //@{
    /*!
        \brief Unique identifier of the Critical Temperature event - Applies to: acA2440-35uc

        Unique identifier of the Critical Temperature event. Use this parameter to get notified when the event occurs.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventCriticalTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventCriticalTemperature;

    //@}


    //! \name Categories: EventCriticalTemperatureData
    //@{
    /*!
        \brief Timestamp of the Critical Temperature event - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventCriticalTemperatureTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventCriticalTemperatureTimestamp;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Unique identifier of the Exposure End event - Applies to: acA2440-35uc

        Unique identifier of the Exposure End event. Use this parameter to get notified when the event occurs.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEnd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEnd;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Frame ID of the Exposure End event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndFrameID;

    //@}


    //! \name Categories: EventExposureEndData
    //@{
    /*!
        \brief Timestamp of the Exposure End event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndTimestamp;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Unique identifier of the Frame Burst Start event - Applies to: acA2440-35uc

        Unique identifier of the Frame Burst Start event. Use this parameter to get notified when the event occurs.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStart;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Frame ID of the Frame Burst Start event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartFrameID;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Unique identifier of the Frame Burst Start Overtrigger event - Applies to: acA2440-35uc

        Unique identifier of the Frame Burst Start Overtrigger event. Use this parameter to get notified when the event occurs.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertrigger;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Frame ID of the Frame Burst Start Overtrigger event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerFrameID;

    //@}


    //! \name Categories: EventFrameBurstStartOvertriggerData
    //@{
    /*!
        \brief Timestamp of the Frame Burst Start Overtrigger event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerTimestamp;

    //@}


    //! \name Categories: EventFrameBurstStartData
    //@{
    /*!
        \brief Timestamp of the Frame Burst Start event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartTimestamp;

    //@}


    //! \name Categories: EventFrameBurstStartWaitData
    //@{
    /*!
        \brief Unique identifier of the Frame Burst Start Wait event - Applies to: acA2440-35uc

        Unique identifier of the Frame Burst Start Wait event. Use this parameter to get notified when the event occurs.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartWait" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartWait;

    //@}


    //! \name Categories: EventFrameBurstStartWaitData
    //@{
    /*!
        \brief Timestamp of the Frame Burst Start Wait event - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartWaitTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartWaitTimestamp;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Unique identifier of the Frame Start event - Applies to: acA2440-35uc

        Unique identifier of the Frame Start event. Use this parameter to get notified when the event occurs.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStart;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Frame ID of the Frame Start event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartFrameID;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Unique identifier of the Frame Start Overtrigger event - Applies to: acA2440-35uc

        Unique identifier of the Frame Start Overtrigger event. Use this parameter to get notified when the event occurs.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertrigger;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Frame ID of the Frame Start Overtrigger event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerFrameID;

    //@}


    //! \name Categories: EventFrameStartOvertriggerData
    //@{
    /*!
        \brief Timestamp of the Frame Start Overtrigger event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerTimestamp;

    //@}


    //! \name Categories: EventFrameStartData
    //@{
    /*!
        \brief Timestamp of the Frame Start event - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartTimestamp;

    //@}


    //! \name Categories: EventFrameStartWaitData
    //@{
    /*!
        \brief Unique identifier of the Frame Start Wait event - Applies to: acA2440-35uc

        Unique identifier of the Frame Start Wait event. Use this parameter to get notified when the event occurs.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartWait" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartWait;

    //@}


    //! \name Categories: EventFrameStartWaitData
    //@{
    /*!
        \brief Timestamp of the Frame Start Wait event - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartWaitTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartWaitTimestamp;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Enables event notifications for the currently selected event - Applies to: acA2440-35uc

        Enables event notifications for the currently selected event. The event can selected using the Event Selector parameter.
    
        Visibility: Expert

        Selected by: EventSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventNotification" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventNotificationEnums>& EventNotification;

    //@}


    //! \name Categories: EventOverTemperatureData
    //@{
    /*!
        \brief Unique identifier of the Over Temperature event - Applies to: acA2440-35uc

        Unique identifier of the Over Temperature event. Use this parameter to get notified when the event occurs.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverTemperature;

    //@}


    //! \name Categories: EventOverTemperatureData
    //@{
    /*!
        \brief Timestamp of the Over Temperature event - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverTemperatureTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverTemperatureTimestamp;

    //@}


    //! \name Categories: EventControl
    //@{
    /*!
        \brief Sets the event notification to be enabled - Applies to: acA2440-35uc

        Sets the event notification to be enabled. The notification can be enabled using the Event Notification parameter.
    
        Visibility: Expert

        Selecting Parameters: EventNotification

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventSelectorEnums>& EventSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Key for making the selected expert feature available - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExpertFeatureAccessKey;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Sets the expert feature to be made available - Applies to: acA2440-35uc

        Sets the expert feature to be made available. All changes will be applied to the selected feature.
    
        Visibility: Guru

        Selecting Parameters: ExpertFeatureEnable and ExpertFeatureAccessKey

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExpertFeatureAccessSelectorEnums>& ExpertFeatureAccessSelector;

    //@}


    //! \name Categories: ExpertFeatureAccess
    //@{
    /*!
        \brief Enables the currently selected expert feature - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selected by: ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ExpertFeatureEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the operation mode of the Exposure Auto auto function - Applies to: acA2440-35uc

        Sets the operation mode of the Exposure Auto auto function. The Exposure Auto auto function automatically adjusts the exposure time within set limits until a target brightness value has been reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureAutoEnums>& ExposureAuto;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the exposure mode - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureModeEnums>& ExposureMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Maximum overlap of the sensor exposure with sensor readout in Trigger Width exposure mode (in microseconds) - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureOverlapTimeMax;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the exposure overlap time mode - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureOverlapTimeModeEnums>& ExposureOverlapTimeMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Exposure time of the camera in microseconds - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTime;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the exposure time mode - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureTimeModeEnums>& ExposureTimeMode;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Access buffer for file operations - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& FileAccessBuffer;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Number of bytes read from the file into the file access buffer or written to the file from the file access buffer - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessLength;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Number of bytes after which FileAccessLength bytes are read from the file into the file access buffer or are written to the file from the file access buffer - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessOffset;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the access mode in which a file is opened in the camera - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOpenMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOpenModeEnums>& FileOpenMode;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Executes the operation selected by File Operation Selector parameter - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationExecute" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& FileOperationExecute;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief File operation result - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationResult" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileOperationResult;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the target operation for the currently selected file - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        Selecting Parameters: FileOperationExecute, FileOperationResult, FileOperationStatus, FileAccessLength and FileAccessOffset

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationSelectorEnums>& FileOperationSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Indicates the file operation execution status - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationStatusEnums>& FileOperationStatus;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Sets the target file in the camera - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selecting Parameters: FileOperationExecute, FileSize, FileOperationResult, FileOperationStatus, FileAccessLength, FileAccessOffset, FileAccessBuffer, FileOpenMode and FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileSelectorEnums>& FileSelector;

    //@}


    //! \name Categories: FileAccessControl
    //@{
    /*!
        \brief Size of the currently selected file in bytes - Applies to: acA2440-35uc

        Basler advises against using this parameter. Use the appropriate feature for file access operations instead.
    
        Visibility: Guru

        Selected by: FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileSize;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Value of the currently selected gain in dB - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gain;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Sets the operation mode of the Gain Auto auto function - Applies to: acA2440-35uc

        Sets the operation mode of the Gain Auto auto function. The Gain Auto auto function automatically adjusts the gain within set limits until a target brightness value has been reached.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainAutoEnums>& GainAuto;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Sets the gain type to be adjusted - Applies to: acA2440-35uc

        Sets the gain type to be adjusted. All changes to the Gain parameter will be applied to the selected gain type.
    
        Visibility: Beginner

        Selecting Parameters: Gain

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainSelectorEnums>& GainSelector;

    //@}


    //! \name Categories: AnalogControl
    //@{
    /*!
        \brief Gamma correction to be applied - Applies to: acA2440-35uc

        Gamma correction to be applied. Gamma correction allows you to optimize the brightness of acquired images for display on a monitor.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gamma" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gamma;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Height of the camera's region of interest (area of interest) in pixels - Applies to: acA2440-35uc

        Height of the camera's region of interest (area of interest) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Height" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Height;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum height of the region of interest (area of interest) in pixels - Applies to: acA2440-35uc

        Maximum height of the region of interest (area of interest) in pixels. The value takes into account any features that may limit the maximum height, e.g., binning.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeightMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeightMax;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Enables the selected lookup table (LUT) - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LUTEnable;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Pixel value to be replaced with the LUT Value pixel value - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selected by: LUTSelector

        Selecting Parameters: LUTValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTIndex;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief Sets the lookup table (LUT) to be configured - Applies to: acA2440-35uc

        Sets the lookup table (LUT) to be configured. All changes to the LUT settings will be applied to the selected LUT.
    
        Visibility: Expert

        Selecting Parameters: LUTEnable, LUTIndex, LUTValue and LUTValueAll

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LUTSelectorEnums>& LUTSelector;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief New pixel value to replace the LUT Index pixel value - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selected by: LUTSelector and LUTIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTValue;

    //@}


    //! \name Categories: LUTControl
    //@{
    /*!
        \brief A single register that lets you access all LUT entries - Applies to: acA2440-35uc

        A single register that lets you access all LUT entries. In many cases, this is faster than repeatedly changing individual entries in the LUT.
    
        Visibility: Guru

        Selected by: LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& LUTValueAll;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the light source preset - Applies to: acA2440-35uc

        Sets the light source preset. The colors in the image will be corrected so that they are appropriate for the selected light source.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LightSourcePreset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LightSourcePresetEnums>& LightSourcePreset;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Line debouncer time in microseconds - Applies to: acA2440-35uc

        Line debouncer time in microseconds. The Line Debouncer allows you to filter out invalid hardware signals by specifying a minimum signal length.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineDebouncerTime;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates the electrical configuration of the currently selected line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineFormatEnums>& LineFormat;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Enables the signal inverter function for the currently selected input or output line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineInverter;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates the line logic of the currently selected line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineLogic" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineLogicEnums>& LineLogic;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Minimum signal width of an output signal (in microseconds) - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMinimumOutputPulseWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineMinimumOutputPulseWidth;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the mode for the selected line - Applies to: acA2440-35uc

        Sets the mode for the selected line. This controls whether the physical line is used to input or output a signal.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineModeEnums>& LineMode;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates whether an overload condition has been detected on the selected line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineOverloadStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineOverloadStatus;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the I/O line to be configured - Applies to: acA2440-35uc

        Sets the I/O line to be configured. All changes to the line settings will be applied to the selected line.
    
        Visibility: Beginner

        Selecting Parameters: LineMode, LineFormat, LineLogic, LineSource, LineInverter, LineDebouncerTime, LineMinimumOutputPulseWidth, LineOverloadStatus and LineStatus

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSelectorEnums>& LineSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the source signal for the currently selected line - Applies to: acA2440-35uc

        Sets the source signal for the currently selected line. The currently selected line must be an output line.
    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSourceEnums>& LineSource;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Indicates the current logical state of the selected line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineStatus;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Single bit field indicating the current logical state of all available line signals at time of polling - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStatusAll;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Amount of noise reduction to be applied - Applies to: acA2440-35uc

        Amount of noise reduction to be applied. The higher the value, the less chroma noise will be visible in your images. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReduction" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& NoiseReduction;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Horizontal offset of the region of interest (area of interest) from the left side of the sensor (in pixels) - Applies to: acA2440-35uc

        Horizontal offset from the left side of the sensor to the region of interest (area of interest) (in pixels).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Vertical offset of the region of interest (area of interest) from the top of the sensor (in pixels) - Applies to: acA2440-35uc

        Vertical offset from the top of the sensor to the region of interest (area of interest) (in pixels).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetY;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Size of the payload in bytes - Applies to: acA2440-35uc

        Size of the payload in bytes. This is the total number of bytes sent in the payload.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadSize;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Enables Basler PGI image optimizations - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PgiMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PgiModeEnums>& PgiMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the alignment of the camera's Bayer filter to the pixels in the acquired images - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelColorFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelColorFilterEnums>& PixelColorFilter;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum possible pixel value that can be transferred from the camera - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMax;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Minimum possible pixel value that can be transferred from the camera - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMin;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the format of the pixel data transmitted by the camera - Applies to: acA2440-35uc

        Sets the format of the pixel data transmitted by the camera. The available pixel formats depend on the camera model and whether the camera is monochrome or color.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelFormatEnums>& PixelFormat;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Indicates the depth of the pixel values in the image (in bits per pixel) - Applies to: acA2440-35uc

        Indicates the depth of the pixel values in the image (in bits per pixel). The potential values depend on the pixel format setting.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelSizeEnums>& PixelSize;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables or disables the currently selected ROI zone - Applies to: acA2440-35uc

        Enables the output of color-improved raw image data. If enabled, color transformation and color adjustment will be applied to Bayer pixel formats.
    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneModeEnums>& ROIZoneMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Vertical offset of the currently selected ROI zone - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneOffset;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the ROI zone that can be configured - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selecting Parameters: ROIZoneMode, ROIZoneSize and ROIZoneOffset

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneSelectorEnums>& ROIZoneSelector;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Height of the currently selected ROI zone - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneSize;

    //@}


    //! \name Categories: RemoveParameterLimitControl
    //@{
    /*!
        \brief Removes the factory-set limit of the selected parameter - Applies to: acA2440-35uc

        Removes the factory-set limit of the selected parameter. If the factory limits are removed, a wider range of parameter values is available and only subect to technical restrictions. Choosing parameter values outside of the factory limits may affect image quality.
    
        Visibility: Guru

        Selected by: RemoveParameterLimitSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& RemoveParameterLimit;

    //@}


    //! \name Categories: RemoveParameterLimitControl
    //@{
    /*!
        \brief Sets the parameter whose factory limits can be removed - Applies to: acA2440-35uc

        Sets the parameter whose factory limits can be removed. The factory limits can be removed using the Remove Limits parameter.
    
        Visibility: Guru

        Selecting Parameters: RemoveParameterLimit

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimitSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<RemoveParameterLimitSelectorEnums>& RemoveParameterLimitSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Maximum frame acquisition rate with current camera settings - Applies to: acA2440-35uc

        Maximum frame acquisition rate with current camera settings (in frames per second).
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFrameRate;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables horizontal mirroring of the image - Applies to: acA2440-35uc

        Enables horizontal mirroring of the image. The pixel values of every line in a captured image will be swapped along the line's center. You can use the ROI feature when using the Reverse X feature. The position of the ROI relative to the sensor remains the same.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Enables vertical mirroring of the image - Applies to: acA2440-35uc

        Enables vertical mirroring of the image. The pixel values of every column in a captured image will be swapped along the column's center. You can use the ROI feature when using the Reverse Y feature. The position of the ROI relative to the sensor remains the same.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseY;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief For information only  May be required when contacting Basler support - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer1Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer1Size;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief For information only  May be required when contacting Basler support - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer2Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer2Size;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief For information only  May be required when contacting Basler support - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferCount;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief For information only  May be required when contacting Basler support - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferSize;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Horizontal scaling factor - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingHorizontal;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Vertical scaling factor - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingVertical;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Height of the camera's sensor in pixels - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorHeight;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the sensor readout mode - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorReadoutModeEnums>& SensorReadoutMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sensor readout time with current settings - Applies to: acA2440-35uc

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorReadoutTime;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Width of the camera's sensor in pixels - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorWidth;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sets whether the sequencer can be configured - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerConfigurationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerConfigurationModeEnums>& SequencerConfigurationMode;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sets whether the sequencer can be used for image acquisition - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerModeEnums>& SequencerMode;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sequencer path to be used - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: SequencerSetSelector

        Selecting Parameters: SequencerSetNext, SequencerTriggerSource and SequencerTriggerActivation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerPathSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerPathSelector;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Index number of the currently active sequencer set - Applies to: acA2440-35uc

        Index number of the current sequencer set, i.e., of the sequencer set whose parameter values are currently in the active set.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetActive;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Loads the parameter values of a sequencer set into the active set - Applies to: acA2440-35uc

        Loads the parameter values of a sequencer set into the active set. The sequencer set will then be the current set.
    
        Visibility: Expert

        Selected by: SequencerSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequencerSetLoad;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sequencer set that follows the current sequence set - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: SequencerSetSelector and SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetNext" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetNext;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Saves the sequencer parameter values that are currently in the active set - Applies to: acA2440-35uc

        Saves the sequencer parameter values that are currently in the active set. The values will be saved in the sequencer set whose sequencer set index number is currently selected.
    
        Visibility: Expert

        Selected by: SequencerSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequencerSetSave;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief The sequencer set to be configured - Applies to: acA2440-35uc

        The sequencer set to be configured. Sequencer sets are identified by their sequencer set index numbers.
    
        Visibility: Expert

        Selecting Parameters: SequencerTriggerActivation, SequencerTriggerSource, SequencerSetNext, SequencerPathSelector, SequencerSetSave and SequencerSetLoad

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetSelector;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sequencer set that will be used with the first Frame Start trigger after the Sequencer Mode parameter was set to On - Applies to: acA2440-35uc

        Sequencer set that will be used with the first Frame Start trigger after the Sequencer Mode parameter was set to On. Only sequencer set 0 is available.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetStart;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sets the logical state that makes the sequencer advance to the next - Applies to: acA2440-35uc

        Sets the logical state that makes the sequencer advance to the next. Currently, only High is available.
    
        Visibility: Expert

        Selected by: SequencerSetSelector and SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerTriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerTriggerActivationEnums>& SequencerTriggerActivation;

    //@}


    //! \name Categories: SequencerControl
    //@{
    /*!
        \brief Sets the trigger source for sequencer set advance - Applies to: acA2440-35uc

        Sets the trigger source for sequencer set advance with the currently selected path.
    
        Visibility: Expert

        Selected by: SequencerSetSelector and SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerTriggerSourceEnums>& SequencerTriggerSource;

    //@}


    //! \name Categories: PGIControl
    //@{
    /*!
        \brief Sharpening value to be applied - Applies to: acA2440-35uc

        Sharpening value to be applied. The higher the sharpness, the more distinct the image subject's contours will be. However, excessively high values may result in image information loss.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancement" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SharpnessEnhancement;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the shutter mode of the camera - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShutterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShutterModeEnums>& ShutterMode;

    //@}


    //! \name Categories: SoftwareSignalControl
    //@{
    /*!
        \brief Executes the selected software signal - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: SoftwareSignalSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalPulse" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SoftwareSignalPulse;

    //@}


    //! \name Categories: SoftwareSignalControl
    //@{
    /*!
        \brief Sets the software signal to be executed - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selecting Parameters: SoftwareSignalPulse

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SoftwareSignalSelectorEnums>& SoftwareSignalSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the temperature state - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureState" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureStateEnums>& TemperatureState;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Allows you to turn a moving test image into a fixed one - Applies to: acA2440-35uc

        Allows you to turn a moving test image into a fixed one. The test image will be displayed at its starting position and will stay fixed.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageResetAndHold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TestImageResetAndHold;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Sets the test image to display - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TestImageSelectorEnums>& TestImageSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Delay of the currently selected timer in microseconds - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelay;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Duration of the currently selected timer in microseconds - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDuration;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets the timer to be configured - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selecting Parameters: TimerDuration, TimerDelay and TimerTriggerSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSelectorEnums>& TimerSelector;

    //@}


    //! \name Categories: CounterAndTimerControl
    //@{
    /*!
        \brief Sets the internal camera signal used to trigger the selected timer - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerSourceEnums>& TimerTriggerSource;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Latches the current timestamp counter and stores its value in TimestampLatchValue - Applies to: acA2440-35uc

        Latches the current timestamp counter and stores its value in the Timestamp Latch Value parameter.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TimestampLatch;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Latched value of the timestamp counter - Applies to: acA2440-35uc

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatchValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimestampLatchValue;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the type of signal transition that will activate the selected trigger - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerActivationEnums>& TriggerActivation;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Trigger delay time in microseconds - Applies to: acA2440-35uc

        Trigger delay time in microseconds. The delay is applied after the trigger has been received and before effectively activating the trigger.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TriggerDelay;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the mode for the currently selected trigger - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerModeEnums>& TriggerMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the trigger type to be configured - Applies to: acA2440-35uc

        Sets the trigger type to be configured. All changes to the trigger settings will be applied to the selected trigger.
    
        Visibility: Expert

        Selecting Parameters: TriggerMode, TriggerSoftware, TriggerSource and TriggerActivation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSelectorEnums>& TriggerSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Generates a software trigger signal - Applies to: acA2440-35uc

        Generates a software trigger signal. The software trigger signal will be used if the Trigger Source parameter is set to Trigger Software.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSoftware" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerSoftware;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the source signal for the selected trigger - Applies to: acA2440-35uc

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSourceEnums>& TriggerSource;

    //@}


    //! \name Categories: UserDefinedValueControl
    //@{
    /*!
        \brief User-defined value - Applies to: acA2440-35uc

        User-defined value. The value can serve as storage location for the camera user. It has no impact on the operation of the camera.
    
        Visibility: Guru

        Selected by: UserDefinedValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserDefinedValue;

    //@}


    //! \name Categories: UserDefinedValueControl
    //@{
    /*!
        \brief Sets the user-defined value to set or read - Applies to: acA2440-35uc

    
        Visibility: Guru

        Selecting Parameters: UserDefinedValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserDefinedValueSelectorEnums>& UserDefinedValueSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the user-settable output signal to be configured - Applies to: acA2440-35uc

        Sets the user-settable output signal to be configured. All changes to the user-settable output signal settings will be applied to the selected user-settable output signal.
    
        Visibility: Beginner

        Selecting Parameters: UserOutputValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserOutputSelectorEnums>& UserOutputSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Enables the selected user-settable output line - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: UserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& UserOutputValue;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Single bit field that sets the state of all user-settable output signals in one access - Applies to: acA2440-35uc

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserOutputValueAll;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Sets the user set or the factory set to be used as the startup set - Applies to: acA2440-35uc

        Sets the user set or the factory set to be used as the startup set. The startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetDefault" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetDefaultEnums>& UserSetDefault;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Loads the selected set into the camera's volatile memory and makes it the active configuration set - Applies to: acA2440-35uc

        Loads the selected set into the camera's volatile memory and makes it the active configuration set. After the selected set has been loaded, the parameters in that set will control the camera.
    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetLoad;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Saves the current active set as the selected user set - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selected by: UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetSave;

    //@}


    //! \name Categories: UserSetControl
    //@{
    /*!
        \brief Sets the user set or the factory set to load, save, or configure - Applies to: acA2440-35uc

    
        Visibility: Beginner

        Selecting Parameters: UserSetSave and UserSetLoad

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetSelectorEnums>& UserSetSelector;

    //@}


    //! \name Categories: VignettingCorrectionControl
    //@{
    /*!
        \brief Loads the vignetting correction data - Applies to: acA2440-35uc

        Loads the vignetting correction data into the camera.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VignettingCorrectionLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& VignettingCorrectionLoad;

    //@}


    //! \name Categories: VignettingCorrectionControl
    //@{
    /*!
        \brief Enables/disables the vignetting correction - Applies to: acA2440-35uc

        The Vignetting Correction feature allows you to remove vignetting artifacts from your images. To do this, you first have to create vignetting correction data. For more information, see the Basler Product Documentation.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VignettingCorrectionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<VignettingCorrectionModeEnums>& VignettingCorrectionMode;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Width of the camera's region of interest (area of interest) in pixels - Applies to: acA2440-35uc

        Width of the camera's region of interest (area of interest) in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Width" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Width;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum width of the region of interest (area of interest) in pixels - Applies to: acA2440-35uc

        Maximum width of the region of interest (area of interest) in pixels. The value takes into account any function that may limit the maximum width.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WidthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WidthMax;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BaslerCameraCameraParams(BaslerCameraCameraParams&);

            //! not implemented assignment operator
            BaslerCameraCameraParams& operator=(BaslerCameraCameraParams&);

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
        class AcquisitionModeEnumParameter : public Pylon::CEnumParameterT<AcquisitionModeEnums>
        {
        public:
            AcquisitionModeEnumParameter()
            {
            }

            virtual ~AcquisitionModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("SingleFrame", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class AcquisitionStatusSelectorEnumParameter : public Pylon::CEnumParameterT<AcquisitionStatusSelectorEnums>
        {
        public:
            AcquisitionStatusSelectorEnumParameter()
            {
            }

            virtual ~AcquisitionStatusSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameBurstTriggerWait", 22),
                    TableItem_t("FrameTriggerWait", 17)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class AutoFunctionProfileEnumParameter : public Pylon::CEnumParameterT<AutoFunctionProfileEnums>
        {
        public:
            AutoFunctionProfileEnumParameter()
            {
            }

            virtual ~AutoFunctionProfileEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("MinimizeExposureTime", 21),
                    TableItem_t("MinimizeGain", 13)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class AutoFunctionROISelectorEnumParameter : public Pylon::CEnumParameterT<AutoFunctionROISelectorEnums>
        {
        public:
            AutoFunctionROISelectorEnumParameter()
            {
            }

            virtual ~AutoFunctionROISelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ROI1", 5),
                    TableItem_t("ROI2", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BLCSerialPortBaudRateEnumParameter : public Pylon::CEnumParameterT<BLCSerialPortBaudRateEnums>
        {
        public:
            BLCSerialPortBaudRateEnumParameter()
            {
            }

            virtual ~BLCSerialPortBaudRateEnumParameter()
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
        class BLCSerialPortParityEnumParameter : public Pylon::CEnumParameterT<BLCSerialPortParityEnums>
        {
        public:
            BLCSerialPortParityEnumParameter()
            {
            }

            virtual ~BLCSerialPortParityEnumParameter()
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
        class BLCSerialPortSourceEnumParameter : public Pylon::CEnumParameterT<BLCSerialPortSourceEnums>
        {
        public:
            BLCSerialPortSourceEnumParameter()
            {
            }

            virtual ~BLCSerialPortSourceEnumParameter()
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
        class BLCSerialPortStopBitsEnumParameter : public Pylon::CEnumParameterT<BLCSerialPortStopBitsEnums>
        {
        public:
            BLCSerialPortStopBitsEnumParameter()
            {
            }

            virtual ~BLCSerialPortStopBitsEnumParameter()
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
        class BLCSerialReceiveQueueStatusEnumParameter : public Pylon::CEnumParameterT<BLCSerialReceiveQueueStatusEnums>
        {
        public:
            BLCSerialReceiveQueueStatusEnumParameter()
            {
            }

            virtual ~BLCSerialReceiveQueueStatusEnumParameter()
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
        class BLCSerialTransmitQueueStatusEnumParameter : public Pylon::CEnumParameterT<BLCSerialTransmitQueueStatusEnums>
        {
        public:
            BLCSerialTransmitQueueStatusEnumParameter()
            {
            }

            virtual ~BLCSerialTransmitQueueStatusEnumParameter()
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
        class BalanceRatioSelectorEnumParameter : public Pylon::CEnumParameterT<BalanceRatioSelectorEnums>
        {
        public:
            BalanceRatioSelectorEnumParameter()
            {
            }

            virtual ~BalanceRatioSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Blue", 5),
                    TableItem_t("Green", 6),
                    TableItem_t("Red", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BalanceWhiteAutoEnumParameter : public Pylon::CEnumParameterT<BalanceWhiteAutoEnums>
        {
        public:
            BalanceWhiteAutoEnumParameter()
            {
            }

            virtual ~BalanceWhiteAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BinningHorizontalModeEnumParameter : public Pylon::CEnumParameterT<BinningHorizontalModeEnums>
        {
        public:
            BinningHorizontalModeEnumParameter()
            {
            }

            virtual ~BinningHorizontalModeEnumParameter()
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
        class BinningVerticalModeEnumParameter : public Pylon::CEnumParameterT<BinningVerticalModeEnums>
        {
        public:
            BinningVerticalModeEnumParameter()
            {
            }

            virtual ~BinningVerticalModeEnumParameter()
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
        class BlackLevelSelectorEnumParameter : public Pylon::CEnumParameterT<BlackLevelSelectorEnums>
        {
        public:
            BlackLevelSelectorEnumParameter()
            {
            }

            virtual ~BlackLevelSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("All", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslContrastModeEnumParameter : public Pylon::CEnumParameterT<BslContrastModeEnums>
        {
        public:
            BslContrastModeEnumParameter()
            {
            }

            virtual ~BslContrastModeEnumParameter()
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
        class BslLightControlErrorStatusEnumParameter : public Pylon::CEnumParameterT<BslLightControlErrorStatusEnums>
        {
        public:
            BslLightControlErrorStatusEnumParameter()
            {
            }

            virtual ~BslLightControlErrorStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Device1", 8),
                    TableItem_t("Device2", 8),
                    TableItem_t("Device3", 8),
                    TableItem_t("Device4", 8),
                    TableItem_t("MultipleDevices", 16),
                    TableItem_t("NoError", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslLightControlModeEnumParameter : public Pylon::CEnumParameterT<BslLightControlModeEnums>
        {
        public:
            BslLightControlModeEnumParameter()
            {
            }

            virtual ~BslLightControlModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslLightControlSourceEnumParameter : public Pylon::CEnumParameterT<BslLightControlSourceEnums>
        {
        public:
            BslLightControlSourceEnumParameter()
            {
            }

            virtual ~BslLightControlSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("Off", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslLightControlStatusEnumParameter : public Pylon::CEnumParameterT<BslLightControlStatusEnums>
        {
        public:
            BslLightControlStatusEnumParameter()
            {
            }

            virtual ~BslLightControlStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Idle", 5),
                    TableItem_t("Off", 4),
                    TableItem_t("Ready", 6),
                    TableItem_t("Searching", 10),
                    TableItem_t("Updating", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslLightControlTriggerModeEnumParameter : public Pylon::CEnumParameterT<BslLightControlTriggerModeEnums>
        {
        public:
            BslLightControlTriggerModeEnumParameter()
            {
            }

            virtual ~BslLightControlTriggerModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExposureActive", 15),
                    TableItem_t("FlashWindow", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class BslLightDeviceChangeIDEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceChangeIDEnums>
        {
        public:
            BslLightDeviceChangeIDEnumParameter()
            {
            }

            virtual ~BslLightDeviceChangeIDEnumParameter()
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
        class BslLightDeviceControlModeEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceControlModeEnums>
        {
        public:
            BslLightDeviceControlModeEnumParameter()
            {
            }

            virtual ~BslLightDeviceControlModeEnumParameter()
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
        class BslLightDeviceLastErrorEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceLastErrorEnums>
        {
        public:
            BslLightDeviceLastErrorEnumParameter()
            {
            }

            virtual ~BslLightDeviceLastErrorEnumParameter()
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
        class BslLightDeviceOperationModeEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceOperationModeEnums>
        {
        public:
            BslLightDeviceOperationModeEnumParameter()
            {
            }

            virtual ~BslLightDeviceOperationModeEnumParameter()
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
        class BslLightDeviceSelectorEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceSelectorEnums>
        {
        public:
            BslLightDeviceSelectorEnumParameter()
            {
            }

            virtual ~BslLightDeviceSelectorEnumParameter()
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
        class BslLightDeviceStrobeModeEnumParameter : public Pylon::CEnumParameterT<BslLightDeviceStrobeModeEnums>
        {
        public:
            BslLightDeviceStrobeModeEnumParameter()
            {
            }

            virtual ~BslLightDeviceStrobeModeEnumParameter()
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
        class BslUSBSpeedModeEnumParameter : public Pylon::CEnumParameterT<BslUSBSpeedModeEnums>
        {
        public:
            BslUSBSpeedModeEnumParameter()
            {
            }

            virtual ~BslUSBSpeedModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("HighSpeed", 10),
                    TableItem_t("SuperSpeed", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


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


        ///////////////////////////////////////////////////////////////////////////
        //
        class ChunkSelectorEnumParameter : public Pylon::CEnumParameterT<ChunkSelectorEnums>
        {
        public:
            ChunkSelectorEnumParameter()
            {
            }

            virtual ~ChunkSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CounterValue", 13),
                    TableItem_t("ExposureTime", 13),
                    TableItem_t("Gain", 5),
                    TableItem_t("LineStatusAll", 14),
                    TableItem_t("PayloadCRC16", 13),
                    TableItem_t("SequencerSetActive", 19),
                    TableItem_t("Timestamp", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorAdjustmentSelectorEnumParameter : public Pylon::CEnumParameterT<ColorAdjustmentSelectorEnums>
        {
        public:
            ColorAdjustmentSelectorEnumParameter()
            {
            }

            virtual ~ColorAdjustmentSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Blue", 5),
                    TableItem_t("Cyan", 5),
                    TableItem_t("Green", 6),
                    TableItem_t("Magenta", 8),
                    TableItem_t("Red", 4),
                    TableItem_t("Yellow", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorSpaceEnumParameter : public Pylon::CEnumParameterT<ColorSpaceEnums>
        {
        public:
            ColorSpaceEnumParameter()
            {
            }

            virtual ~ColorSpaceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RGB", 4),
                    TableItem_t("sRGB", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorTransformationSelectorEnumParameter : public Pylon::CEnumParameterT<ColorTransformationSelectorEnums>
        {
        public:
            ColorTransformationSelectorEnumParameter()
            {
            }

            virtual ~ColorTransformationSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RGBtoRGB", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ColorTransformationValueSelectorEnumParameter : public Pylon::CEnumParameterT<ColorTransformationValueSelectorEnums>
        {
        public:
            ColorTransformationValueSelectorEnumParameter()
            {
            }

            virtual ~ColorTransformationValueSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 9;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Gain00", 7),
                    TableItem_t("Gain01", 7),
                    TableItem_t("Gain02", 7),
                    TableItem_t("Gain10", 7),
                    TableItem_t("Gain11", 7),
                    TableItem_t("Gain12", 7),
                    TableItem_t("Gain20", 7),
                    TableItem_t("Gain21", 7),
                    TableItem_t("Gain22", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterEventSourceEnumParameter : public Pylon::CEnumParameterT<CounterEventSourceEnums>
        {
        public:
            CounterEventSourceEnumParameter()
            {
            }

            virtual ~CounterEventSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameStart", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterResetActivationEnumParameter : public Pylon::CEnumParameterT<CounterResetActivationEnums>
        {
        public:
            CounterResetActivationEnumParameter()
            {
            }

            virtual ~CounterResetActivationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("RisingEdge", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterResetSourceEnumParameter : public Pylon::CEnumParameterT<CounterResetSourceEnums>
        {
        public:
            CounterResetSourceEnumParameter()
            {
            }

            virtual ~CounterResetSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 6;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Counter2End", 12),
                    TableItem_t("Line1", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("Off", 4),
                    TableItem_t("Software", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class CounterSelectorEnumParameter : public Pylon::CEnumParameterT<CounterSelectorEnums>
        {
        public:
            CounterSelectorEnumParameter()
            {
            }

            virtual ~CounterSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Counter1", 9),
                    TableItem_t("Counter2", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DemosaicingModeEnumParameter : public Pylon::CEnumParameterT<DemosaicingModeEnums>
        {
        public:
            DemosaicingModeEnumParameter()
            {
            }

            virtual ~DemosaicingModeEnumParameter()
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
        class DeviceLinkThroughputLimitModeEnumParameter : public Pylon::CEnumParameterT<DeviceLinkThroughputLimitModeEnums>
        {
        public:
            DeviceLinkThroughputLimitModeEnumParameter()
            {
            }

            virtual ~DeviceLinkThroughputLimitModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceScanTypeEnumParameter : public Pylon::CEnumParameterT<DeviceScanTypeEnums>
        {
        public:
            DeviceScanTypeEnumParameter()
            {
            }

            virtual ~DeviceScanTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Areascan", 9),
                    TableItem_t("Linescan", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceTemperatureSelectorEnumParameter : public Pylon::CEnumParameterT<DeviceTemperatureSelectorEnums>
        {
        public:
            DeviceTemperatureSelectorEnumParameter()
            {
            }

            virtual ~DeviceTemperatureSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Coreboard", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class EventNotificationEnumParameter : public Pylon::CEnumParameterT<EventNotificationEnums>
        {
        public:
            EventNotificationEnumParameter()
            {
            }

            virtual ~EventNotificationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class EventSelectorEnumParameter : public Pylon::CEnumParameterT<EventSelectorEnums>
        {
        public:
            EventSelectorEnumParameter()
            {
            }

            virtual ~EventSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 9;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CriticalTemperature", 20),
                    TableItem_t("ExposureEnd", 12),
                    TableItem_t("FrameBurstStart", 16),
                    TableItem_t("FrameBurstStartOvertrigger", 27),
                    TableItem_t("FrameBurstStartWait", 20),
                    TableItem_t("FrameStart", 11),
                    TableItem_t("FrameStartOvertrigger", 22),
                    TableItem_t("FrameStartWait", 15),
                    TableItem_t("OverTemperature", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExpertFeatureAccessSelectorEnumParameter : public Pylon::CEnumParameterT<ExpertFeatureAccessSelectorEnums>
        {
        public:
            ExpertFeatureAccessSelectorEnumParameter()
            {
            }

            virtual ~ExpertFeatureAccessSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 11;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExpertFeature1", 15),
                    TableItem_t("ExpertFeature10", 16),
                    TableItem_t("ExpertFeature11", 16),
                    TableItem_t("ExpertFeature2", 15),
                    TableItem_t("ExpertFeature3", 15),
                    TableItem_t("ExpertFeature4", 15),
                    TableItem_t("ExpertFeature5", 15),
                    TableItem_t("ExpertFeature6", 15),
                    TableItem_t("ExpertFeature7", 15),
                    TableItem_t("ExpertFeature8", 15),
                    TableItem_t("ExpertFeature9", 15)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExposureAutoEnumParameter : public Pylon::CEnumParameterT<ExposureAutoEnums>
        {
        public:
            ExposureAutoEnumParameter()
            {
            }

            virtual ~ExposureAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExposureModeEnumParameter : public Pylon::CEnumParameterT<ExposureModeEnums>
        {
        public:
            ExposureModeEnumParameter()
            {
            }

            virtual ~ExposureModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Timed", 6),
                    TableItem_t("TriggerWidth", 13)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ExposureOverlapTimeModeEnumParameter : public Pylon::CEnumParameterT<ExposureOverlapTimeModeEnums>
        {
        public:
            ExposureOverlapTimeModeEnumParameter()
            {
            }

            virtual ~ExposureOverlapTimeModeEnumParameter()
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
        class ExposureTimeModeEnumParameter : public Pylon::CEnumParameterT<ExposureTimeModeEnums>
        {
        public:
            ExposureTimeModeEnumParameter()
            {
            }

            virtual ~ExposureTimeModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Standard", 9),
                    TableItem_t("UltraShort", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOpenModeEnumParameter : public Pylon::CEnumParameterT<FileOpenModeEnums>
        {
        public:
            FileOpenModeEnumParameter()
            {
            }

            virtual ~FileOpenModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Read", 5),
                    TableItem_t("Write", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOperationSelectorEnumParameter : public Pylon::CEnumParameterT<FileOperationSelectorEnums>
        {
        public:
            FileOperationSelectorEnumParameter()
            {
            }

            virtual ~FileOperationSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Close", 6),
                    TableItem_t("Open", 5),
                    TableItem_t("Read", 5),
                    TableItem_t("Write", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileOperationStatusEnumParameter : public Pylon::CEnumParameterT<FileOperationStatusEnums>
        {
        public:
            FileOperationStatusEnumParameter()
            {
            }

            virtual ~FileOperationStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Failure", 8),
                    TableItem_t("Success", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class FileSelectorEnumParameter : public Pylon::CEnumParameterT<FileSelectorEnums>
        {
        public:
            FileSelectorEnumParameter()
            {
            }

            virtual ~FileSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 10;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExpertFeature7File", 19),
                    TableItem_t("UserData", 9),
                    TableItem_t("UserGainShading1", 17),
                    TableItem_t("UserGainShading2", 17),
                    TableItem_t("UserOffsetShading1", 19),
                    TableItem_t("UserOffsetShading2", 19),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9),
                    TableItem_t("VignettingCorrection", 21)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class GainAutoEnumParameter : public Pylon::CEnumParameterT<GainAutoEnums>
        {
        public:
            GainAutoEnumParameter()
            {
            }

            virtual ~GainAutoEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11),
                    TableItem_t("Off", 4),
                    TableItem_t("Once", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class GainSelectorEnumParameter : public Pylon::CEnumParameterT<GainSelectorEnums>
        {
        public:
            GainSelectorEnumParameter()
            {
            }

            virtual ~GainSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("All", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LUTSelectorEnumParameter : public Pylon::CEnumParameterT<LUTSelectorEnums>
        {
        public:
            LUTSelectorEnumParameter()
            {
            }

            virtual ~LUTSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Luminance", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LightSourcePresetEnumParameter : public Pylon::CEnumParameterT<LightSourcePresetEnums>
        {
        public:
            LightSourcePresetEnumParameter()
            {
            }

            virtual ~LightSourcePresetEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Daylight5000K", 14),
                    TableItem_t("Daylight6500K", 14),
                    TableItem_t("Off", 4),
                    TableItem_t("Tungsten2800K", 14)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineFormatEnumParameter : public Pylon::CEnumParameterT<LineFormatEnums>
        {
        public:
            LineFormatEnumParameter()
            {
            }

            virtual ~LineFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("OptoCoupled", 12),
                    TableItem_t("TTL", 4)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineLogicEnumParameter : public Pylon::CEnumParameterT<LineLogicEnums>
        {
        public:
            LineLogicEnumParameter()
            {
            }

            virtual ~LineLogicEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Negative", 9),
                    TableItem_t("Positive", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineModeEnumParameter : public Pylon::CEnumParameterT<LineModeEnums>
        {
        public:
            LineModeEnumParameter()
            {
            }

            virtual ~LineModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Input", 6),
                    TableItem_t("Output", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSelectorEnumParameter : public Pylon::CEnumParameterT<LineSelectorEnums>
        {
        public:
            LineSelectorEnumParameter()
            {
            }

            virtual ~LineSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line1", 6),
                    TableItem_t("Line2", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSourceEnumParameter : public Pylon::CEnumParameterT<LineSourceEnums>
        {
        public:
            LineSourceEnumParameter()
            {
            }

            virtual ~LineSourceEnumParameter()
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
        class PgiModeEnumParameter : public Pylon::CEnumParameterT<PgiModeEnums>
        {
        public:
            PgiModeEnumParameter()
            {
            }

            virtual ~PgiModeEnumParameter()
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
        class PixelColorFilterEnumParameter : public Pylon::CEnumParameterT<PixelColorFilterEnums>
        {
        public:
            PixelColorFilterEnumParameter()
            {
            }

            virtual ~PixelColorFilterEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BayerBG", 8),
                    TableItem_t("BayerGB", 8),
                    TableItem_t("BayerGR", 8),
                    TableItem_t("BayerRG", 8),
                    TableItem_t("None", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PixelFormatEnumParameter : public Pylon::CEnumParameterT<PixelFormatEnums>
        {
        public:
            PixelFormatEnumParameter()
            {
            }

            virtual ~PixelFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 16;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("BGR8", 5),
                    TableItem_t("BayerBG12", 10),
                    TableItem_t("BayerBG12p", 11),
                    TableItem_t("BayerBG8", 9),
                    TableItem_t("BayerGB12", 10),
                    TableItem_t("BayerGB12p", 11),
                    TableItem_t("BayerGB8", 9),
                    TableItem_t("BayerGR12", 10),
                    TableItem_t("BayerGR12p", 11),
                    TableItem_t("BayerGR8", 9),
                    TableItem_t("BayerRG12", 10),
                    TableItem_t("BayerRG12p", 11),
                    TableItem_t("BayerRG8", 9),
                    TableItem_t("Mono8", 6),
                    TableItem_t("RGB8", 5),
                    TableItem_t("YCbCr422_8", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PixelSizeEnumParameter : public Pylon::CEnumParameterT<PixelSizeEnums>
        {
        public:
            PixelSizeEnumParameter()
            {
            }

            virtual ~PixelSizeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Bpp10", 6),
                    TableItem_t("Bpp12", 6),
                    TableItem_t("Bpp16", 6),
                    TableItem_t("Bpp24", 6),
                    TableItem_t("Bpp8", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ROIZoneModeEnumParameter : public Pylon::CEnumParameterT<ROIZoneModeEnums>
        {
        public:
            ROIZoneModeEnumParameter()
            {
            }

            virtual ~ROIZoneModeEnumParameter()
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
        class ROIZoneSelectorEnumParameter : public Pylon::CEnumParameterT<ROIZoneSelectorEnums>
        {
        public:
            ROIZoneSelectorEnumParameter()
            {
            }

            virtual ~ROIZoneSelectorEnumParameter()
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
        class RemoveParameterLimitSelectorEnumParameter : public Pylon::CEnumParameterT<RemoveParameterLimitSelectorEnums>
        {
        public:
            RemoveParameterLimitSelectorEnumParameter()
            {
            }

            virtual ~RemoveParameterLimitSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Gain", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SensorReadoutModeEnumParameter : public Pylon::CEnumParameterT<SensorReadoutModeEnums>
        {
        public:
            SensorReadoutModeEnumParameter()
            {
            }

            virtual ~SensorReadoutModeEnumParameter()
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
        class SequencerConfigurationModeEnumParameter : public Pylon::CEnumParameterT<SequencerConfigurationModeEnums>
        {
        public:
            SequencerConfigurationModeEnumParameter()
            {
            }

            virtual ~SequencerConfigurationModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SequencerModeEnumParameter : public Pylon::CEnumParameterT<SequencerModeEnums>
        {
        public:
            SequencerModeEnumParameter()
            {
            }

            virtual ~SequencerModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SequencerTriggerActivationEnumParameter : public Pylon::CEnumParameterT<SequencerTriggerActivationEnums>
        {
        public:
            SequencerTriggerActivationEnumParameter()
            {
            }

            virtual ~SequencerTriggerActivationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("LevelHigh", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SequencerTriggerSourceEnumParameter : public Pylon::CEnumParameterT<SequencerTriggerSourceEnums>
        {
        public:
            SequencerTriggerSourceEnumParameter()
            {
            }

            virtual ~SequencerTriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 8;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Counter2End", 12),
                    TableItem_t("FrameStart", 11),
                    TableItem_t("Line1", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("SoftwareSignal1", 16),
                    TableItem_t("SoftwareSignal2", 16),
                    TableItem_t("SoftwareSignal3", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ShutterModeEnumParameter : public Pylon::CEnumParameterT<ShutterModeEnums>
        {
        public:
            ShutterModeEnumParameter()
            {
            }

            virtual ~ShutterModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Global", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class SoftwareSignalSelectorEnumParameter : public Pylon::CEnumParameterT<SoftwareSignalSelectorEnums>
        {
        public:
            SoftwareSignalSelectorEnumParameter()
            {
            }

            virtual ~SoftwareSignalSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("SoftwareSignal1", 16),
                    TableItem_t("SoftwareSignal2", 16),
                    TableItem_t("SoftwareSignal3", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TemperatureStateEnumParameter : public Pylon::CEnumParameterT<TemperatureStateEnums>
        {
        public:
            TemperatureStateEnumParameter()
            {
            }

            virtual ~TemperatureStateEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Critical", 9),
                    TableItem_t("Error", 6),
                    TableItem_t("Ok", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TestImageSelectorEnumParameter : public Pylon::CEnumParameterT<TestImageSelectorEnums>
        {
        public:
            TestImageSelectorEnumParameter()
            {
            }

            virtual ~TestImageSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("Testimage1", 11),
                    TableItem_t("Testimage2", 11),
                    TableItem_t("Testimage3", 11),
                    TableItem_t("Testimage4", 11),
                    TableItem_t("Testimage5", 11),
                    TableItem_t("Testimage6", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TimerSelectorEnumParameter : public Pylon::CEnumParameterT<TimerSelectorEnums>
        {
        public:
            TimerSelectorEnumParameter()
            {
            }

            virtual ~TimerSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Timer1", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TimerTriggerSourceEnumParameter : public Pylon::CEnumParameterT<TimerTriggerSourceEnums>
        {
        public:
            TimerTriggerSourceEnumParameter()
            {
            }

            virtual ~TimerTriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("ExposureStart", 14)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerActivationEnumParameter : public Pylon::CEnumParameterT<TriggerActivationEnums>
        {
        public:
            TriggerActivationEnumParameter()
            {
            }

            virtual ~TriggerActivationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FallingEdge", 12),
                    TableItem_t("RisingEdge", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerModeEnumParameter : public Pylon::CEnumParameterT<TriggerModeEnums>
        {
        public:
            TriggerModeEnumParameter()
            {
            }

            virtual ~TriggerModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSelectorEnumParameter : public Pylon::CEnumParameterT<TriggerSelectorEnums>
        {
        public:
            TriggerSelectorEnumParameter()
            {
            }

            virtual ~TriggerSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameBurstStart", 16),
                    TableItem_t("FrameStart", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSourceEnumParameter : public Pylon::CEnumParameterT<TriggerSourceEnums>
        {
        public:
            TriggerSourceEnumParameter()
            {
            }

            virtual ~TriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line1", 6),
                    TableItem_t("Line3", 6),
                    TableItem_t("Line4", 6),
                    TableItem_t("Software", 9),
                    TableItem_t("SoftwareSignal1", 16),
                    TableItem_t("SoftwareSignal2", 16),
                    TableItem_t("SoftwareSignal3", 16)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserDefinedValueSelectorEnumParameter : public Pylon::CEnumParameterT<UserDefinedValueSelectorEnums>
        {
        public:
            UserDefinedValueSelectorEnumParameter()
            {
            }

            virtual ~UserDefinedValueSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 5;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Value1", 7),
                    TableItem_t("Value2", 7),
                    TableItem_t("Value3", 7),
                    TableItem_t("Value4", 7),
                    TableItem_t("Value5", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserOutputSelectorEnumParameter : public Pylon::CEnumParameterT<UserOutputSelectorEnums>
        {
        public:
            UserOutputSelectorEnumParameter()
            {
            }

            virtual ~UserOutputSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("UserOutput1", 12),
                    TableItem_t("UserOutput2", 12),
                    TableItem_t("UserOutput3", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserSetDefaultEnumParameter : public Pylon::CEnumParameterT<UserSetDefaultEnums>
        {
        public:
            UserSetDefaultEnumParameter()
            {
            }

            virtual ~UserSetDefaultEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("ColorRaw", 9),
                    TableItem_t("Default", 8),
                    TableItem_t("HighGain", 9),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserSetSelectorEnumParameter : public Pylon::CEnumParameterT<UserSetSelectorEnums>
        {
        public:
            UserSetSelectorEnumParameter()
            {
            }

            virtual ~UserSetSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 7;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("AutoFunctions", 14),
                    TableItem_t("ColorRaw", 9),
                    TableItem_t("Default", 8),
                    TableItem_t("HighGain", 9),
                    TableItem_t("UserSet1", 9),
                    TableItem_t("UserSet2", 9),
                    TableItem_t("UserSet3", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class VignettingCorrectionModeEnumParameter : public Pylon::CEnumParameterT<VignettingCorrectionModeEnums>
        {
        public:
            VignettingCorrectionModeEnumParameter()
            {
            }

            virtual ~VignettingCorrectionModeEnumParameter()
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
    // Parameter class BaslerCameraCameraParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BaslerCameraCameraParams::BaslerCameraCameraParams_Data
    {
    public:
        Pylon::CIntegerParameter AcquisitionBurstFrameCount;
        Pylon::CFloatParameter AcquisitionFrameRate;
        Pylon::CBooleanParameter AcquisitionFrameRateEnable;
        EnumParameterClasses::AcquisitionModeEnumParameter AcquisitionMode;
        Pylon::CCommandParameter AcquisitionStart;
        Pylon::CBooleanParameter AcquisitionStatus;
        EnumParameterClasses::AcquisitionStatusSelectorEnumParameter AcquisitionStatusSelector;
        Pylon::CCommandParameter AcquisitionStop;
        Pylon::CFloatParameter AutoExposureTimeLowerLimit;
        Pylon::CFloatParameter AutoExposureTimeUpperLimit;
        EnumParameterClasses::AutoFunctionProfileEnumParameter AutoFunctionProfile;
        Pylon::CIntegerParameter AutoFunctionROIHeight;
        Pylon::CIntegerParameter AutoFunctionROIOffsetX;
        Pylon::CIntegerParameter AutoFunctionROIOffsetY;
        EnumParameterClasses::AutoFunctionROISelectorEnumParameter AutoFunctionROISelector;
        Pylon::CBooleanParameter AutoFunctionROIUseBrightness;
        Pylon::CBooleanParameter AutoFunctionROIUseWhiteBalance;
        Pylon::CIntegerParameter AutoFunctionROIWidth;
        Pylon::CFloatParameter AutoGainLowerLimit;
        Pylon::CFloatParameter AutoGainUpperLimit;
        Pylon::CFloatParameter AutoTargetBrightness;
        Pylon::CBooleanParameter BLCSerialFramingError;
        Pylon::CBooleanParameter BLCSerialParityError;
        EnumParameterClasses::BLCSerialPortBaudRateEnumParameter BLCSerialPortBaudRate;
        Pylon::CCommandParameter BLCSerialPortClearErrors;
        EnumParameterClasses::BLCSerialPortParityEnumParameter BLCSerialPortParity;
        Pylon::CCommandParameter BLCSerialPortReceiveCmd;
        Pylon::CIntegerParameter BLCSerialPortReceiveValue;
        EnumParameterClasses::BLCSerialPortSourceEnumParameter BLCSerialPortSource;
        EnumParameterClasses::BLCSerialPortStopBitsEnumParameter BLCSerialPortStopBits;
        Pylon::CCommandParameter BLCSerialPortTransmitCmd;
        Pylon::CIntegerParameter BLCSerialPortTransmitValue;
        EnumParameterClasses::BLCSerialReceiveQueueStatusEnumParameter BLCSerialReceiveQueueStatus;
        EnumParameterClasses::BLCSerialTransmitQueueStatusEnumParameter BLCSerialTransmitQueueStatus;
        Pylon::CFloatParameter BalanceRatio;
        EnumParameterClasses::BalanceRatioSelectorEnumParameter BalanceRatioSelector;
        EnumParameterClasses::BalanceWhiteAutoEnumParameter BalanceWhiteAuto;
        Pylon::CIntegerParameter BinningHorizontal;
        EnumParameterClasses::BinningHorizontalModeEnumParameter BinningHorizontalMode;
        Pylon::CIntegerParameter BinningVertical;
        EnumParameterClasses::BinningVerticalModeEnumParameter BinningVerticalMode;
        Pylon::CFloatParameter BlackLevel;
        EnumParameterClasses::BlackLevelSelectorEnumParameter BlackLevelSelector;
        Pylon::CFloatParameter BslBrightness;
        Pylon::CFloatParameter BslContrast;
        EnumParameterClasses::BslContrastModeEnumParameter BslContrastMode;
        Pylon::CFloatParameter BslHue;
        Pylon::CCommandParameter BslLightControlEnumerateDevices;
        EnumParameterClasses::BslLightControlErrorStatusEnumParameter BslLightControlErrorStatus;
        EnumParameterClasses::BslLightControlModeEnumParameter BslLightControlMode;
        EnumParameterClasses::BslLightControlSourceEnumParameter BslLightControlSource;
        EnumParameterClasses::BslLightControlStatusEnumParameter BslLightControlStatus;
        EnumParameterClasses::BslLightControlTriggerModeEnumParameter BslLightControlTriggerMode;
        Pylon::CFloatParameter BslLightDeviceBrightness;
        EnumParameterClasses::BslLightDeviceChangeIDEnumParameter BslLightDeviceChangeID;
        Pylon::CCommandParameter BslLightDeviceClearLastError;
        EnumParameterClasses::BslLightDeviceControlModeEnumParameter BslLightDeviceControlMode;
        Pylon::CStringParameter BslLightDeviceFirmwareVersion;
        EnumParameterClasses::BslLightDeviceLastErrorEnumParameter BslLightDeviceLastError;
        Pylon::CFloatParameter BslLightDeviceMaxCurrent;
        Pylon::CStringParameter BslLightDeviceModelName;
        EnumParameterClasses::BslLightDeviceOperationModeEnumParameter BslLightDeviceOperationMode;
        Pylon::CFloatParameter BslLightDeviceOverdriveLimit;
        EnumParameterClasses::BslLightDeviceSelectorEnumParameter BslLightDeviceSelector;
        Pylon::CFloatParameter BslLightDeviceStrobeDuration;
        EnumParameterClasses::BslLightDeviceStrobeModeEnumParameter BslLightDeviceStrobeMode;
        Pylon::CFloatParameter BslSaturation;
        EnumParameterClasses::BslUSBSpeedModeEnumParameter BslUSBSpeedMode;
        Pylon::CBooleanParameter CenterX;
        Pylon::CBooleanParameter CenterY;
        EnumParameterClasses::ChunkCounterSelectorEnumParameter ChunkCounterSelector;
        Pylon::CIntegerParameter ChunkCounterValue;
        Pylon::CBooleanParameter ChunkEnable;
        Pylon::CFloatParameter ChunkExposureTime;
        Pylon::CFloatParameter ChunkGain;
        EnumParameterClasses::ChunkGainSelectorEnumParameter ChunkGainSelector;
        Pylon::CIntegerParameter ChunkLineStatusAll;
        Pylon::CBooleanParameter ChunkModeActive;
        Pylon::CIntegerParameter ChunkPayloadCRC16;
        EnumParameterClasses::ChunkSelectorEnumParameter ChunkSelector;
        Pylon::CIntegerParameter ChunkSequencerSetActive;
        Pylon::CIntegerParameter ChunkTimestamp;
        Pylon::CFloatParameter ColorAdjustmentHue;
        Pylon::CFloatParameter ColorAdjustmentSaturation;
        EnumParameterClasses::ColorAdjustmentSelectorEnumParameter ColorAdjustmentSelector;
        EnumParameterClasses::ColorSpaceEnumParameter ColorSpace;
        EnumParameterClasses::ColorTransformationSelectorEnumParameter ColorTransformationSelector;
        Pylon::CFloatParameter ColorTransformationValue;
        EnumParameterClasses::ColorTransformationValueSelectorEnumParameter ColorTransformationValueSelector;
        Pylon::CIntegerParameter CounterDuration;
        EnumParameterClasses::CounterEventSourceEnumParameter CounterEventSource;
        Pylon::CCommandParameter CounterReset;
        EnumParameterClasses::CounterResetActivationEnumParameter CounterResetActivation;
        EnumParameterClasses::CounterResetSourceEnumParameter CounterResetSource;
        EnumParameterClasses::CounterSelectorEnumParameter CounterSelector;
        Pylon::CIntegerParameter DecimationHorizontal;
        Pylon::CIntegerParameter DecimationVertical;
        EnumParameterClasses::DemosaicingModeEnumParameter DemosaicingMode;
        Pylon::CStringParameter DeviceFirmwareVersion;
        Pylon::CIntegerParameter DeviceLinkCurrentThroughput;
        Pylon::CIntegerParameter DeviceLinkSelector;
        Pylon::CIntegerParameter DeviceLinkSpeed;
        Pylon::CIntegerParameter DeviceLinkThroughputLimit;
        EnumParameterClasses::DeviceLinkThroughputLimitModeEnumParameter DeviceLinkThroughputLimitMode;
        Pylon::CStringParameter DeviceManufacturerInfo;
        Pylon::CStringParameter DeviceModelName;
        Pylon::CCommandParameter DeviceReset;
        Pylon::CIntegerParameter DeviceSFNCVersionMajor;
        Pylon::CIntegerParameter DeviceSFNCVersionMinor;
        Pylon::CIntegerParameter DeviceSFNCVersionSubMinor;
        EnumParameterClasses::DeviceScanTypeEnumParameter DeviceScanType;
        Pylon::CStringParameter DeviceSerialNumber;
        Pylon::CFloatParameter DeviceTemperature;
        EnumParameterClasses::DeviceTemperatureSelectorEnumParameter DeviceTemperatureSelector;
        Pylon::CStringParameter DeviceUserID;
        Pylon::CStringParameter DeviceVendorName;
        Pylon::CStringParameter DeviceVersion;
        Pylon::CIntegerParameter DigitalShift;
        Pylon::CIntegerParameter EventCriticalTemperature;
        Pylon::CIntegerParameter EventCriticalTemperatureTimestamp;
        Pylon::CIntegerParameter EventExposureEnd;
        Pylon::CIntegerParameter EventExposureEndFrameID;
        Pylon::CIntegerParameter EventExposureEndTimestamp;
        Pylon::CIntegerParameter EventFrameBurstStart;
        Pylon::CIntegerParameter EventFrameBurstStartFrameID;
        Pylon::CIntegerParameter EventFrameBurstStartOvertrigger;
        Pylon::CIntegerParameter EventFrameBurstStartOvertriggerFrameID;
        Pylon::CIntegerParameter EventFrameBurstStartOvertriggerTimestamp;
        Pylon::CIntegerParameter EventFrameBurstStartTimestamp;
        Pylon::CIntegerParameter EventFrameBurstStartWait;
        Pylon::CIntegerParameter EventFrameBurstStartWaitTimestamp;
        Pylon::CIntegerParameter EventFrameStart;
        Pylon::CIntegerParameter EventFrameStartFrameID;
        Pylon::CIntegerParameter EventFrameStartOvertrigger;
        Pylon::CIntegerParameter EventFrameStartOvertriggerFrameID;
        Pylon::CIntegerParameter EventFrameStartOvertriggerTimestamp;
        Pylon::CIntegerParameter EventFrameStartTimestamp;
        Pylon::CIntegerParameter EventFrameStartWait;
        Pylon::CIntegerParameter EventFrameStartWaitTimestamp;
        EnumParameterClasses::EventNotificationEnumParameter EventNotification;
        Pylon::CIntegerParameter EventOverTemperature;
        Pylon::CIntegerParameter EventOverTemperatureTimestamp;
        EnumParameterClasses::EventSelectorEnumParameter EventSelector;
        Pylon::CIntegerParameter ExpertFeatureAccessKey;
        EnumParameterClasses::ExpertFeatureAccessSelectorEnumParameter ExpertFeatureAccessSelector;
        Pylon::CBooleanParameter ExpertFeatureEnable;
        EnumParameterClasses::ExposureAutoEnumParameter ExposureAuto;
        EnumParameterClasses::ExposureModeEnumParameter ExposureMode;
        Pylon::CFloatParameter ExposureOverlapTimeMax;
        EnumParameterClasses::ExposureOverlapTimeModeEnumParameter ExposureOverlapTimeMode;
        Pylon::CFloatParameter ExposureTime;
        EnumParameterClasses::ExposureTimeModeEnumParameter ExposureTimeMode;
        Pylon::CArrayParameter FileAccessBuffer;
        Pylon::CIntegerParameter FileAccessLength;
        Pylon::CIntegerParameter FileAccessOffset;
        EnumParameterClasses::FileOpenModeEnumParameter FileOpenMode;
        Pylon::CCommandParameter FileOperationExecute;
        Pylon::CIntegerParameter FileOperationResult;
        EnumParameterClasses::FileOperationSelectorEnumParameter FileOperationSelector;
        EnumParameterClasses::FileOperationStatusEnumParameter FileOperationStatus;
        EnumParameterClasses::FileSelectorEnumParameter FileSelector;
        Pylon::CIntegerParameter FileSize;
        Pylon::CFloatParameter Gain;
        EnumParameterClasses::GainAutoEnumParameter GainAuto;
        EnumParameterClasses::GainSelectorEnumParameter GainSelector;
        Pylon::CFloatParameter Gamma;
        Pylon::CIntegerParameter Height;
        Pylon::CIntegerParameter HeightMax;
        Pylon::CBooleanParameter LUTEnable;
        Pylon::CIntegerParameter LUTIndex;
        EnumParameterClasses::LUTSelectorEnumParameter LUTSelector;
        Pylon::CIntegerParameter LUTValue;
        Pylon::CArrayParameter LUTValueAll;
        EnumParameterClasses::LightSourcePresetEnumParameter LightSourcePreset;
        Pylon::CFloatParameter LineDebouncerTime;
        EnumParameterClasses::LineFormatEnumParameter LineFormat;
        Pylon::CBooleanParameter LineInverter;
        EnumParameterClasses::LineLogicEnumParameter LineLogic;
        Pylon::CFloatParameter LineMinimumOutputPulseWidth;
        EnumParameterClasses::LineModeEnumParameter LineMode;
        Pylon::CBooleanParameter LineOverloadStatus;
        EnumParameterClasses::LineSelectorEnumParameter LineSelector;
        EnumParameterClasses::LineSourceEnumParameter LineSource;
        Pylon::CBooleanParameter LineStatus;
        Pylon::CIntegerParameter LineStatusAll;
        Pylon::CFloatParameter NoiseReduction;
        Pylon::CIntegerParameter OffsetX;
        Pylon::CIntegerParameter OffsetY;
        Pylon::CIntegerParameter PayloadSize;
        EnumParameterClasses::PgiModeEnumParameter PgiMode;
        EnumParameterClasses::PixelColorFilterEnumParameter PixelColorFilter;
        Pylon::CIntegerParameter PixelDynamicRangeMax;
        Pylon::CIntegerParameter PixelDynamicRangeMin;
        EnumParameterClasses::PixelFormatEnumParameter PixelFormat;
        EnumParameterClasses::PixelSizeEnumParameter PixelSize;
        EnumParameterClasses::ROIZoneModeEnumParameter ROIZoneMode;
        Pylon::CIntegerParameter ROIZoneOffset;
        EnumParameterClasses::ROIZoneSelectorEnumParameter ROIZoneSelector;
        Pylon::CIntegerParameter ROIZoneSize;
        Pylon::CBooleanParameter RemoveParameterLimit;
        EnumParameterClasses::RemoveParameterLimitSelectorEnumParameter RemoveParameterLimitSelector;
        Pylon::CFloatParameter ResultingFrameRate;
        Pylon::CBooleanParameter ReverseX;
        Pylon::CBooleanParameter ReverseY;
        Pylon::CIntegerParameter SIPayloadFinalTransfer1Size;
        Pylon::CIntegerParameter SIPayloadFinalTransfer2Size;
        Pylon::CIntegerParameter SIPayloadTransferCount;
        Pylon::CIntegerParameter SIPayloadTransferSize;
        Pylon::CFloatParameter ScalingHorizontal;
        Pylon::CFloatParameter ScalingVertical;
        Pylon::CIntegerParameter SensorHeight;
        EnumParameterClasses::SensorReadoutModeEnumParameter SensorReadoutMode;
        Pylon::CFloatParameter SensorReadoutTime;
        Pylon::CIntegerParameter SensorWidth;
        EnumParameterClasses::SequencerConfigurationModeEnumParameter SequencerConfigurationMode;
        EnumParameterClasses::SequencerModeEnumParameter SequencerMode;
        Pylon::CIntegerParameter SequencerPathSelector;
        Pylon::CIntegerParameter SequencerSetActive;
        Pylon::CCommandParameter SequencerSetLoad;
        Pylon::CIntegerParameter SequencerSetNext;
        Pylon::CCommandParameter SequencerSetSave;
        Pylon::CIntegerParameter SequencerSetSelector;
        Pylon::CIntegerParameter SequencerSetStart;
        EnumParameterClasses::SequencerTriggerActivationEnumParameter SequencerTriggerActivation;
        EnumParameterClasses::SequencerTriggerSourceEnumParameter SequencerTriggerSource;
        Pylon::CFloatParameter SharpnessEnhancement;
        EnumParameterClasses::ShutterModeEnumParameter ShutterMode;
        Pylon::CCommandParameter SoftwareSignalPulse;
        EnumParameterClasses::SoftwareSignalSelectorEnumParameter SoftwareSignalSelector;
        EnumParameterClasses::TemperatureStateEnumParameter TemperatureState;
        Pylon::CBooleanParameter TestImageResetAndHold;
        EnumParameterClasses::TestImageSelectorEnumParameter TestImageSelector;
        Pylon::CFloatParameter TimerDelay;
        Pylon::CFloatParameter TimerDuration;
        EnumParameterClasses::TimerSelectorEnumParameter TimerSelector;
        EnumParameterClasses::TimerTriggerSourceEnumParameter TimerTriggerSource;
        Pylon::CCommandParameter TimestampLatch;
        Pylon::CIntegerParameter TimestampLatchValue;
        EnumParameterClasses::TriggerActivationEnumParameter TriggerActivation;
        Pylon::CFloatParameter TriggerDelay;
        EnumParameterClasses::TriggerModeEnumParameter TriggerMode;
        EnumParameterClasses::TriggerSelectorEnumParameter TriggerSelector;
        Pylon::CCommandParameter TriggerSoftware;
        EnumParameterClasses::TriggerSourceEnumParameter TriggerSource;
        Pylon::CIntegerParameter UserDefinedValue;
        EnumParameterClasses::UserDefinedValueSelectorEnumParameter UserDefinedValueSelector;
        EnumParameterClasses::UserOutputSelectorEnumParameter UserOutputSelector;
        Pylon::CBooleanParameter UserOutputValue;
        Pylon::CIntegerParameter UserOutputValueAll;
        EnumParameterClasses::UserSetDefaultEnumParameter UserSetDefault;
        Pylon::CCommandParameter UserSetLoad;
        Pylon::CCommandParameter UserSetSave;
        EnumParameterClasses::UserSetSelectorEnumParameter UserSetSelector;
        Pylon::CCommandParameter VignettingCorrectionLoad;
        EnumParameterClasses::VignettingCorrectionModeEnumParameter VignettingCorrectionMode;
        Pylon::CIntegerParameter Width;
        Pylon::CIntegerParameter WidthMax;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraCameraParams::BaslerCameraCameraParams(void)
        : m_pData(new BaslerCameraCameraParams_Data())
        , AcquisitionBurstFrameCount(m_pData->AcquisitionBurstFrameCount)
        , AcquisitionFrameRate(m_pData->AcquisitionFrameRate)
        , AcquisitionFrameRateEnable(m_pData->AcquisitionFrameRateEnable)
        , AcquisitionMode(m_pData->AcquisitionMode)
        , AcquisitionStart(m_pData->AcquisitionStart)
        , AcquisitionStatus(m_pData->AcquisitionStatus)
        , AcquisitionStatusSelector(m_pData->AcquisitionStatusSelector)
        , AcquisitionStop(m_pData->AcquisitionStop)
        , AutoExposureTimeLowerLimit(m_pData->AutoExposureTimeLowerLimit)
        , AutoExposureTimeUpperLimit(m_pData->AutoExposureTimeUpperLimit)
        , AutoFunctionProfile(m_pData->AutoFunctionProfile)
        , AutoFunctionROIHeight(m_pData->AutoFunctionROIHeight)
        , AutoFunctionROIOffsetX(m_pData->AutoFunctionROIOffsetX)
        , AutoFunctionROIOffsetY(m_pData->AutoFunctionROIOffsetY)
        , AutoFunctionROISelector(m_pData->AutoFunctionROISelector)
        , AutoFunctionROIUseBrightness(m_pData->AutoFunctionROIUseBrightness)
        , AutoFunctionROIUseWhiteBalance(m_pData->AutoFunctionROIUseWhiteBalance)
        , AutoFunctionROIWidth(m_pData->AutoFunctionROIWidth)
        , AutoGainLowerLimit(m_pData->AutoGainLowerLimit)
        , AutoGainUpperLimit(m_pData->AutoGainUpperLimit)
        , AutoTargetBrightness(m_pData->AutoTargetBrightness)
        , BLCSerialFramingError(m_pData->BLCSerialFramingError)
        , BLCSerialParityError(m_pData->BLCSerialParityError)
        , BLCSerialPortBaudRate(m_pData->BLCSerialPortBaudRate)
        , BLCSerialPortClearErrors(m_pData->BLCSerialPortClearErrors)
        , BLCSerialPortParity(m_pData->BLCSerialPortParity)
        , BLCSerialPortReceiveCmd(m_pData->BLCSerialPortReceiveCmd)
        , BLCSerialPortReceiveValue(m_pData->BLCSerialPortReceiveValue)
        , BLCSerialPortSource(m_pData->BLCSerialPortSource)
        , BLCSerialPortStopBits(m_pData->BLCSerialPortStopBits)
        , BLCSerialPortTransmitCmd(m_pData->BLCSerialPortTransmitCmd)
        , BLCSerialPortTransmitValue(m_pData->BLCSerialPortTransmitValue)
        , BLCSerialReceiveQueueStatus(m_pData->BLCSerialReceiveQueueStatus)
        , BLCSerialTransmitQueueStatus(m_pData->BLCSerialTransmitQueueStatus)
        , BalanceRatio(m_pData->BalanceRatio)
        , BalanceRatioSelector(m_pData->BalanceRatioSelector)
        , BalanceWhiteAuto(m_pData->BalanceWhiteAuto)
        , BinningHorizontal(m_pData->BinningHorizontal)
        , BinningHorizontalMode(m_pData->BinningHorizontalMode)
        , BinningVertical(m_pData->BinningVertical)
        , BinningVerticalMode(m_pData->BinningVerticalMode)
        , BlackLevel(m_pData->BlackLevel)
        , BlackLevelSelector(m_pData->BlackLevelSelector)
        , BslBrightness(m_pData->BslBrightness)
        , BslContrast(m_pData->BslContrast)
        , BslContrastMode(m_pData->BslContrastMode)
        , BslHue(m_pData->BslHue)
        , BslLightControlEnumerateDevices(m_pData->BslLightControlEnumerateDevices)
        , BslLightControlErrorStatus(m_pData->BslLightControlErrorStatus)
        , BslLightControlMode(m_pData->BslLightControlMode)
        , BslLightControlSource(m_pData->BslLightControlSource)
        , BslLightControlStatus(m_pData->BslLightControlStatus)
        , BslLightControlTriggerMode(m_pData->BslLightControlTriggerMode)
        , BslLightDeviceBrightness(m_pData->BslLightDeviceBrightness)
        , BslLightDeviceChangeID(m_pData->BslLightDeviceChangeID)
        , BslLightDeviceClearLastError(m_pData->BslLightDeviceClearLastError)
        , BslLightDeviceControlMode(m_pData->BslLightDeviceControlMode)
        , BslLightDeviceFirmwareVersion(m_pData->BslLightDeviceFirmwareVersion)
        , BslLightDeviceLastError(m_pData->BslLightDeviceLastError)
        , BslLightDeviceMaxCurrent(m_pData->BslLightDeviceMaxCurrent)
        , BslLightDeviceModelName(m_pData->BslLightDeviceModelName)
        , BslLightDeviceOperationMode(m_pData->BslLightDeviceOperationMode)
        , BslLightDeviceOverdriveLimit(m_pData->BslLightDeviceOverdriveLimit)
        , BslLightDeviceSelector(m_pData->BslLightDeviceSelector)
        , BslLightDeviceStrobeDuration(m_pData->BslLightDeviceStrobeDuration)
        , BslLightDeviceStrobeMode(m_pData->BslLightDeviceStrobeMode)
        , BslSaturation(m_pData->BslSaturation)
        , BslUSBSpeedMode(m_pData->BslUSBSpeedMode)
        , CenterX(m_pData->CenterX)
        , CenterY(m_pData->CenterY)
        , ChunkCounterSelector(m_pData->ChunkCounterSelector)
        , ChunkCounterValue(m_pData->ChunkCounterValue)
        , ChunkEnable(m_pData->ChunkEnable)
        , ChunkExposureTime(m_pData->ChunkExposureTime)
        , ChunkGain(m_pData->ChunkGain)
        , ChunkGainSelector(m_pData->ChunkGainSelector)
        , ChunkLineStatusAll(m_pData->ChunkLineStatusAll)
        , ChunkModeActive(m_pData->ChunkModeActive)
        , ChunkPayloadCRC16(m_pData->ChunkPayloadCRC16)
        , ChunkSelector(m_pData->ChunkSelector)
        , ChunkSequencerSetActive(m_pData->ChunkSequencerSetActive)
        , ChunkTimestamp(m_pData->ChunkTimestamp)
        , ColorAdjustmentHue(m_pData->ColorAdjustmentHue)
        , ColorAdjustmentSaturation(m_pData->ColorAdjustmentSaturation)
        , ColorAdjustmentSelector(m_pData->ColorAdjustmentSelector)
        , ColorSpace(m_pData->ColorSpace)
        , ColorTransformationSelector(m_pData->ColorTransformationSelector)
        , ColorTransformationValue(m_pData->ColorTransformationValue)
        , ColorTransformationValueSelector(m_pData->ColorTransformationValueSelector)
        , CounterDuration(m_pData->CounterDuration)
        , CounterEventSource(m_pData->CounterEventSource)
        , CounterReset(m_pData->CounterReset)
        , CounterResetActivation(m_pData->CounterResetActivation)
        , CounterResetSource(m_pData->CounterResetSource)
        , CounterSelector(m_pData->CounterSelector)
        , DecimationHorizontal(m_pData->DecimationHorizontal)
        , DecimationVertical(m_pData->DecimationVertical)
        , DemosaicingMode(m_pData->DemosaicingMode)
        , DeviceFirmwareVersion(m_pData->DeviceFirmwareVersion)
        , DeviceLinkCurrentThroughput(m_pData->DeviceLinkCurrentThroughput)
        , DeviceLinkSelector(m_pData->DeviceLinkSelector)
        , DeviceLinkSpeed(m_pData->DeviceLinkSpeed)
        , DeviceLinkThroughputLimit(m_pData->DeviceLinkThroughputLimit)
        , DeviceLinkThroughputLimitMode(m_pData->DeviceLinkThroughputLimitMode)
        , DeviceManufacturerInfo(m_pData->DeviceManufacturerInfo)
        , DeviceModelName(m_pData->DeviceModelName)
        , DeviceReset(m_pData->DeviceReset)
        , DeviceSFNCVersionMajor(m_pData->DeviceSFNCVersionMajor)
        , DeviceSFNCVersionMinor(m_pData->DeviceSFNCVersionMinor)
        , DeviceSFNCVersionSubMinor(m_pData->DeviceSFNCVersionSubMinor)
        , DeviceScanType(m_pData->DeviceScanType)
        , DeviceSerialNumber(m_pData->DeviceSerialNumber)
        , DeviceTemperature(m_pData->DeviceTemperature)
        , DeviceTemperatureSelector(m_pData->DeviceTemperatureSelector)
        , DeviceUserID(m_pData->DeviceUserID)
        , DeviceVendorName(m_pData->DeviceVendorName)
        , DeviceVersion(m_pData->DeviceVersion)
        , DigitalShift(m_pData->DigitalShift)
        , EventCriticalTemperature(m_pData->EventCriticalTemperature)
        , EventCriticalTemperatureTimestamp(m_pData->EventCriticalTemperatureTimestamp)
        , EventExposureEnd(m_pData->EventExposureEnd)
        , EventExposureEndFrameID(m_pData->EventExposureEndFrameID)
        , EventExposureEndTimestamp(m_pData->EventExposureEndTimestamp)
        , EventFrameBurstStart(m_pData->EventFrameBurstStart)
        , EventFrameBurstStartFrameID(m_pData->EventFrameBurstStartFrameID)
        , EventFrameBurstStartOvertrigger(m_pData->EventFrameBurstStartOvertrigger)
        , EventFrameBurstStartOvertriggerFrameID(m_pData->EventFrameBurstStartOvertriggerFrameID)
        , EventFrameBurstStartOvertriggerTimestamp(m_pData->EventFrameBurstStartOvertriggerTimestamp)
        , EventFrameBurstStartTimestamp(m_pData->EventFrameBurstStartTimestamp)
        , EventFrameBurstStartWait(m_pData->EventFrameBurstStartWait)
        , EventFrameBurstStartWaitTimestamp(m_pData->EventFrameBurstStartWaitTimestamp)
        , EventFrameStart(m_pData->EventFrameStart)
        , EventFrameStartFrameID(m_pData->EventFrameStartFrameID)
        , EventFrameStartOvertrigger(m_pData->EventFrameStartOvertrigger)
        , EventFrameStartOvertriggerFrameID(m_pData->EventFrameStartOvertriggerFrameID)
        , EventFrameStartOvertriggerTimestamp(m_pData->EventFrameStartOvertriggerTimestamp)
        , EventFrameStartTimestamp(m_pData->EventFrameStartTimestamp)
        , EventFrameStartWait(m_pData->EventFrameStartWait)
        , EventFrameStartWaitTimestamp(m_pData->EventFrameStartWaitTimestamp)
        , EventNotification(m_pData->EventNotification)
        , EventOverTemperature(m_pData->EventOverTemperature)
        , EventOverTemperatureTimestamp(m_pData->EventOverTemperatureTimestamp)
        , EventSelector(m_pData->EventSelector)
        , ExpertFeatureAccessKey(m_pData->ExpertFeatureAccessKey)
        , ExpertFeatureAccessSelector(m_pData->ExpertFeatureAccessSelector)
        , ExpertFeatureEnable(m_pData->ExpertFeatureEnable)
        , ExposureAuto(m_pData->ExposureAuto)
        , ExposureMode(m_pData->ExposureMode)
        , ExposureOverlapTimeMax(m_pData->ExposureOverlapTimeMax)
        , ExposureOverlapTimeMode(m_pData->ExposureOverlapTimeMode)
        , ExposureTime(m_pData->ExposureTime)
        , ExposureTimeMode(m_pData->ExposureTimeMode)
        , FileAccessBuffer(m_pData->FileAccessBuffer)
        , FileAccessLength(m_pData->FileAccessLength)
        , FileAccessOffset(m_pData->FileAccessOffset)
        , FileOpenMode(m_pData->FileOpenMode)
        , FileOperationExecute(m_pData->FileOperationExecute)
        , FileOperationResult(m_pData->FileOperationResult)
        , FileOperationSelector(m_pData->FileOperationSelector)
        , FileOperationStatus(m_pData->FileOperationStatus)
        , FileSelector(m_pData->FileSelector)
        , FileSize(m_pData->FileSize)
        , Gain(m_pData->Gain)
        , GainAuto(m_pData->GainAuto)
        , GainSelector(m_pData->GainSelector)
        , Gamma(m_pData->Gamma)
        , Height(m_pData->Height)
        , HeightMax(m_pData->HeightMax)
        , LUTEnable(m_pData->LUTEnable)
        , LUTIndex(m_pData->LUTIndex)
        , LUTSelector(m_pData->LUTSelector)
        , LUTValue(m_pData->LUTValue)
        , LUTValueAll(m_pData->LUTValueAll)
        , LightSourcePreset(m_pData->LightSourcePreset)
        , LineDebouncerTime(m_pData->LineDebouncerTime)
        , LineFormat(m_pData->LineFormat)
        , LineInverter(m_pData->LineInverter)
        , LineLogic(m_pData->LineLogic)
        , LineMinimumOutputPulseWidth(m_pData->LineMinimumOutputPulseWidth)
        , LineMode(m_pData->LineMode)
        , LineOverloadStatus(m_pData->LineOverloadStatus)
        , LineSelector(m_pData->LineSelector)
        , LineSource(m_pData->LineSource)
        , LineStatus(m_pData->LineStatus)
        , LineStatusAll(m_pData->LineStatusAll)
        , NoiseReduction(m_pData->NoiseReduction)
        , OffsetX(m_pData->OffsetX)
        , OffsetY(m_pData->OffsetY)
        , PayloadSize(m_pData->PayloadSize)
        , PgiMode(m_pData->PgiMode)
        , PixelColorFilter(m_pData->PixelColorFilter)
        , PixelDynamicRangeMax(m_pData->PixelDynamicRangeMax)
        , PixelDynamicRangeMin(m_pData->PixelDynamicRangeMin)
        , PixelFormat(m_pData->PixelFormat)
        , PixelSize(m_pData->PixelSize)
        , ROIZoneMode(m_pData->ROIZoneMode)
        , ROIZoneOffset(m_pData->ROIZoneOffset)
        , ROIZoneSelector(m_pData->ROIZoneSelector)
        , ROIZoneSize(m_pData->ROIZoneSize)
        , RemoveParameterLimit(m_pData->RemoveParameterLimit)
        , RemoveParameterLimitSelector(m_pData->RemoveParameterLimitSelector)
        , ResultingFrameRate(m_pData->ResultingFrameRate)
        , ReverseX(m_pData->ReverseX)
        , ReverseY(m_pData->ReverseY)
        , SIPayloadFinalTransfer1Size(m_pData->SIPayloadFinalTransfer1Size)
        , SIPayloadFinalTransfer2Size(m_pData->SIPayloadFinalTransfer2Size)
        , SIPayloadTransferCount(m_pData->SIPayloadTransferCount)
        , SIPayloadTransferSize(m_pData->SIPayloadTransferSize)
        , ScalingHorizontal(m_pData->ScalingHorizontal)
        , ScalingVertical(m_pData->ScalingVertical)
        , SensorHeight(m_pData->SensorHeight)
        , SensorReadoutMode(m_pData->SensorReadoutMode)
        , SensorReadoutTime(m_pData->SensorReadoutTime)
        , SensorWidth(m_pData->SensorWidth)
        , SequencerConfigurationMode(m_pData->SequencerConfigurationMode)
        , SequencerMode(m_pData->SequencerMode)
        , SequencerPathSelector(m_pData->SequencerPathSelector)
        , SequencerSetActive(m_pData->SequencerSetActive)
        , SequencerSetLoad(m_pData->SequencerSetLoad)
        , SequencerSetNext(m_pData->SequencerSetNext)
        , SequencerSetSave(m_pData->SequencerSetSave)
        , SequencerSetSelector(m_pData->SequencerSetSelector)
        , SequencerSetStart(m_pData->SequencerSetStart)
        , SequencerTriggerActivation(m_pData->SequencerTriggerActivation)
        , SequencerTriggerSource(m_pData->SequencerTriggerSource)
        , SharpnessEnhancement(m_pData->SharpnessEnhancement)
        , ShutterMode(m_pData->ShutterMode)
        , SoftwareSignalPulse(m_pData->SoftwareSignalPulse)
        , SoftwareSignalSelector(m_pData->SoftwareSignalSelector)
        , TemperatureState(m_pData->TemperatureState)
        , TestImageResetAndHold(m_pData->TestImageResetAndHold)
        , TestImageSelector(m_pData->TestImageSelector)
        , TimerDelay(m_pData->TimerDelay)
        , TimerDuration(m_pData->TimerDuration)
        , TimerSelector(m_pData->TimerSelector)
        , TimerTriggerSource(m_pData->TimerTriggerSource)
        , TimestampLatch(m_pData->TimestampLatch)
        , TimestampLatchValue(m_pData->TimestampLatchValue)
        , TriggerActivation(m_pData->TriggerActivation)
        , TriggerDelay(m_pData->TriggerDelay)
        , TriggerMode(m_pData->TriggerMode)
        , TriggerSelector(m_pData->TriggerSelector)
        , TriggerSoftware(m_pData->TriggerSoftware)
        , TriggerSource(m_pData->TriggerSource)
        , UserDefinedValue(m_pData->UserDefinedValue)
        , UserDefinedValueSelector(m_pData->UserDefinedValueSelector)
        , UserOutputSelector(m_pData->UserOutputSelector)
        , UserOutputValue(m_pData->UserOutputValue)
        , UserOutputValueAll(m_pData->UserOutputValueAll)
        , UserSetDefault(m_pData->UserSetDefault)
        , UserSetLoad(m_pData->UserSetLoad)
        , UserSetSave(m_pData->UserSetSave)
        , UserSetSelector(m_pData->UserSetSelector)
        , VignettingCorrectionLoad(m_pData->VignettingCorrectionLoad)
        , VignettingCorrectionMode(m_pData->VignettingCorrectionMode)
        , Width(m_pData->Width)
        , WidthMax(m_pData->WidthMax)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BaslerCameraCameraParams::~BaslerCameraCameraParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BaslerCameraCameraParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->AcquisitionBurstFrameCount.Attach(pNodeMap, "AcquisitionBurstFrameCount");
        m_pData->AcquisitionFrameRate.Attach(pNodeMap, "AcquisitionFrameRate");
        m_pData->AcquisitionFrameRateEnable.Attach(pNodeMap, "AcquisitionFrameRateEnable");
        m_pData->AcquisitionMode.Attach(pNodeMap, "AcquisitionMode");
        m_pData->AcquisitionStart.Attach(pNodeMap, "AcquisitionStart");
        m_pData->AcquisitionStatus.Attach(pNodeMap, "AcquisitionStatus");
        m_pData->AcquisitionStatusSelector.Attach(pNodeMap, "AcquisitionStatusSelector");
        m_pData->AcquisitionStop.Attach(pNodeMap, "AcquisitionStop");
        m_pData->AutoExposureTimeLowerLimit.Attach(pNodeMap, "AutoExposureTimeLowerLimit");
        m_pData->AutoExposureTimeUpperLimit.Attach(pNodeMap, "AutoExposureTimeUpperLimit");
        m_pData->AutoFunctionProfile.Attach(pNodeMap, "AutoFunctionProfile");
        m_pData->AutoFunctionROIHeight.Attach(pNodeMap, "AutoFunctionROIHeight");
        m_pData->AutoFunctionROIOffsetX.Attach(pNodeMap, "AutoFunctionROIOffsetX");
        m_pData->AutoFunctionROIOffsetY.Attach(pNodeMap, "AutoFunctionROIOffsetY");
        m_pData->AutoFunctionROISelector.Attach(pNodeMap, "AutoFunctionROISelector");
        m_pData->AutoFunctionROIUseBrightness.Attach(pNodeMap, "AutoFunctionROIUseBrightness");
        m_pData->AutoFunctionROIUseWhiteBalance.Attach(pNodeMap, "AutoFunctionROIUseWhiteBalance");
        m_pData->AutoFunctionROIWidth.Attach(pNodeMap, "AutoFunctionROIWidth");
        m_pData->AutoGainLowerLimit.Attach(pNodeMap, "AutoGainLowerLimit");
        m_pData->AutoGainUpperLimit.Attach(pNodeMap, "AutoGainUpperLimit");
        m_pData->AutoTargetBrightness.Attach(pNodeMap, "AutoTargetBrightness");
        m_pData->BLCSerialFramingError.Attach(pNodeMap, "BLCSerialFramingError");
        m_pData->BLCSerialParityError.Attach(pNodeMap, "BLCSerialParityError");
        m_pData->BLCSerialPortBaudRate.Attach(pNodeMap, "BLCSerialPortBaudRate");
        m_pData->BLCSerialPortClearErrors.Attach(pNodeMap, "BLCSerialPortClearErrors");
        m_pData->BLCSerialPortParity.Attach(pNodeMap, "BLCSerialPortParity");
        m_pData->BLCSerialPortReceiveCmd.Attach(pNodeMap, "BLCSerialPortReceiveCmd");
        m_pData->BLCSerialPortReceiveValue.Attach(pNodeMap, "BLCSerialPortReceiveValue");
        m_pData->BLCSerialPortSource.Attach(pNodeMap, "BLCSerialPortSource");
        m_pData->BLCSerialPortStopBits.Attach(pNodeMap, "BLCSerialPortStopBits");
        m_pData->BLCSerialPortTransmitCmd.Attach(pNodeMap, "BLCSerialPortTransmitCmd");
        m_pData->BLCSerialPortTransmitValue.Attach(pNodeMap, "BLCSerialPortTransmitValue");
        m_pData->BLCSerialReceiveQueueStatus.Attach(pNodeMap, "BLCSerialReceiveQueueStatus");
        m_pData->BLCSerialTransmitQueueStatus.Attach(pNodeMap, "BLCSerialTransmitQueueStatus");
        m_pData->BalanceRatio.Attach(pNodeMap, "BalanceRatio");
        m_pData->BalanceRatioSelector.Attach(pNodeMap, "BalanceRatioSelector");
        m_pData->BalanceWhiteAuto.Attach(pNodeMap, "BalanceWhiteAuto");
        m_pData->BinningHorizontal.Attach(pNodeMap, "BinningHorizontal");
        m_pData->BinningHorizontalMode.Attach(pNodeMap, "BinningHorizontalMode");
        m_pData->BinningVertical.Attach(pNodeMap, "BinningVertical");
        m_pData->BinningVerticalMode.Attach(pNodeMap, "BinningVerticalMode");
        m_pData->BlackLevel.Attach(pNodeMap, "BlackLevel");
        m_pData->BlackLevelSelector.Attach(pNodeMap, "BlackLevelSelector");
        m_pData->BslBrightness.Attach(pNodeMap, "BslBrightness");
        m_pData->BslContrast.Attach(pNodeMap, "BslContrast");
        m_pData->BslContrastMode.Attach(pNodeMap, "BslContrastMode");
        m_pData->BslHue.Attach(pNodeMap, "BslHue");
        m_pData->BslLightControlEnumerateDevices.Attach(pNodeMap, "BslLightControlEnumerateDevices");
        m_pData->BslLightControlErrorStatus.Attach(pNodeMap, "BslLightControlErrorStatus");
        m_pData->BslLightControlMode.Attach(pNodeMap, "BslLightControlMode");
        m_pData->BslLightControlSource.Attach(pNodeMap, "BslLightControlSource");
        m_pData->BslLightControlStatus.Attach(pNodeMap, "BslLightControlStatus");
        m_pData->BslLightControlTriggerMode.Attach(pNodeMap, "BslLightControlTriggerMode");
        m_pData->BslLightDeviceBrightness.Attach(pNodeMap, "BslLightDeviceBrightness");
        m_pData->BslLightDeviceChangeID.Attach(pNodeMap, "BslLightDeviceChangeID");
        m_pData->BslLightDeviceClearLastError.Attach(pNodeMap, "BslLightDeviceClearLastError");
        m_pData->BslLightDeviceControlMode.Attach(pNodeMap, "BslLightDeviceControlMode");
        m_pData->BslLightDeviceFirmwareVersion.Attach(pNodeMap, "BslLightDeviceFirmwareVersion");
        m_pData->BslLightDeviceLastError.Attach(pNodeMap, "BslLightDeviceLastError");
        m_pData->BslLightDeviceMaxCurrent.Attach(pNodeMap, "BslLightDeviceMaxCurrent");
        m_pData->BslLightDeviceModelName.Attach(pNodeMap, "BslLightDeviceModelName");
        m_pData->BslLightDeviceOperationMode.Attach(pNodeMap, "BslLightDeviceOperationMode");
        m_pData->BslLightDeviceOverdriveLimit.Attach(pNodeMap, "BslLightDeviceOverdriveLimit");
        m_pData->BslLightDeviceSelector.Attach(pNodeMap, "BslLightDeviceSelector");
        m_pData->BslLightDeviceStrobeDuration.Attach(pNodeMap, "BslLightDeviceStrobeDuration");
        m_pData->BslLightDeviceStrobeMode.Attach(pNodeMap, "BslLightDeviceStrobeMode");
        m_pData->BslSaturation.Attach(pNodeMap, "BslSaturation");
        m_pData->BslUSBSpeedMode.Attach(pNodeMap, "BslUSBSpeedMode");
        m_pData->CenterX.Attach(pNodeMap, "CenterX");
        m_pData->CenterY.Attach(pNodeMap, "CenterY");
        m_pData->ChunkCounterSelector.Attach(pNodeMap, "ChunkCounterSelector");
        m_pData->ChunkCounterValue.Attach(pNodeMap, "ChunkCounterValue");
        m_pData->ChunkEnable.Attach(pNodeMap, "ChunkEnable");
        m_pData->ChunkExposureTime.Attach(pNodeMap, "ChunkExposureTime");
        m_pData->ChunkGain.Attach(pNodeMap, "ChunkGain");
        m_pData->ChunkGainSelector.Attach(pNodeMap, "ChunkGainSelector");
        m_pData->ChunkLineStatusAll.Attach(pNodeMap, "ChunkLineStatusAll");
        m_pData->ChunkModeActive.Attach(pNodeMap, "ChunkModeActive");
        m_pData->ChunkPayloadCRC16.Attach(pNodeMap, "ChunkPayloadCRC16");
        m_pData->ChunkSelector.Attach(pNodeMap, "ChunkSelector");
        m_pData->ChunkSequencerSetActive.Attach(pNodeMap, "ChunkSequencerSetActive");
        m_pData->ChunkTimestamp.Attach(pNodeMap, "ChunkTimestamp");
        m_pData->ColorAdjustmentHue.Attach(pNodeMap, "ColorAdjustmentHue");
        m_pData->ColorAdjustmentSaturation.Attach(pNodeMap, "ColorAdjustmentSaturation");
        m_pData->ColorAdjustmentSelector.Attach(pNodeMap, "ColorAdjustmentSelector");
        m_pData->ColorSpace.Attach(pNodeMap, "ColorSpace");
        m_pData->ColorTransformationSelector.Attach(pNodeMap, "ColorTransformationSelector");
        m_pData->ColorTransformationValue.Attach(pNodeMap, "ColorTransformationValue");
        m_pData->ColorTransformationValueSelector.Attach(pNodeMap, "ColorTransformationValueSelector");
        m_pData->CounterDuration.Attach(pNodeMap, "CounterDuration");
        m_pData->CounterEventSource.Attach(pNodeMap, "CounterEventSource");
        m_pData->CounterReset.Attach(pNodeMap, "CounterReset");
        m_pData->CounterResetActivation.Attach(pNodeMap, "CounterResetActivation");
        m_pData->CounterResetSource.Attach(pNodeMap, "CounterResetSource");
        m_pData->CounterSelector.Attach(pNodeMap, "CounterSelector");
        m_pData->DecimationHorizontal.Attach(pNodeMap, "DecimationHorizontal");
        m_pData->DecimationVertical.Attach(pNodeMap, "DecimationVertical");
        m_pData->DemosaicingMode.Attach(pNodeMap, "DemosaicingMode");
        m_pData->DeviceFirmwareVersion.Attach(pNodeMap, "DeviceFirmwareVersion");
        m_pData->DeviceLinkCurrentThroughput.Attach(pNodeMap, "DeviceLinkCurrentThroughput");
        m_pData->DeviceLinkSelector.Attach(pNodeMap, "DeviceLinkSelector");
        m_pData->DeviceLinkSpeed.Attach(pNodeMap, "DeviceLinkSpeed");
        m_pData->DeviceLinkThroughputLimit.Attach(pNodeMap, "DeviceLinkThroughputLimit");
        m_pData->DeviceLinkThroughputLimitMode.Attach(pNodeMap, "DeviceLinkThroughputLimitMode");
        m_pData->DeviceManufacturerInfo.Attach(pNodeMap, "DeviceManufacturerInfo");
        m_pData->DeviceModelName.Attach(pNodeMap, "DeviceModelName");
        m_pData->DeviceReset.Attach(pNodeMap, "DeviceReset");
        m_pData->DeviceSFNCVersionMajor.Attach(pNodeMap, "DeviceSFNCVersionMajor");
        m_pData->DeviceSFNCVersionMinor.Attach(pNodeMap, "DeviceSFNCVersionMinor");
        m_pData->DeviceSFNCVersionSubMinor.Attach(pNodeMap, "DeviceSFNCVersionSubMinor");
        m_pData->DeviceScanType.Attach(pNodeMap, "DeviceScanType");
        m_pData->DeviceSerialNumber.Attach(pNodeMap, "DeviceSerialNumber");
        m_pData->DeviceTemperature.Attach(pNodeMap, "DeviceTemperature");
        m_pData->DeviceTemperatureSelector.Attach(pNodeMap, "DeviceTemperatureSelector");
        m_pData->DeviceUserID.Attach(pNodeMap, "DeviceUserID");
        m_pData->DeviceVendorName.Attach(pNodeMap, "DeviceVendorName");
        m_pData->DeviceVersion.Attach(pNodeMap, "DeviceVersion");
        m_pData->DigitalShift.Attach(pNodeMap, "DigitalShift");
        m_pData->EventCriticalTemperature.Attach(pNodeMap, "EventCriticalTemperature");
        m_pData->EventCriticalTemperatureTimestamp.Attach(pNodeMap, "EventCriticalTemperatureTimestamp");
        m_pData->EventExposureEnd.Attach(pNodeMap, "EventExposureEnd");
        m_pData->EventExposureEndFrameID.Attach(pNodeMap, "EventExposureEndFrameID");
        m_pData->EventExposureEndTimestamp.Attach(pNodeMap, "EventExposureEndTimestamp");
        m_pData->EventFrameBurstStart.Attach(pNodeMap, "EventFrameBurstStart");
        m_pData->EventFrameBurstStartFrameID.Attach(pNodeMap, "EventFrameBurstStartFrameID");
        m_pData->EventFrameBurstStartOvertrigger.Attach(pNodeMap, "EventFrameBurstStartOvertrigger");
        m_pData->EventFrameBurstStartOvertriggerFrameID.Attach(pNodeMap, "EventFrameBurstStartOvertriggerFrameID");
        m_pData->EventFrameBurstStartOvertriggerTimestamp.Attach(pNodeMap, "EventFrameBurstStartOvertriggerTimestamp");
        m_pData->EventFrameBurstStartTimestamp.Attach(pNodeMap, "EventFrameBurstStartTimestamp");
        m_pData->EventFrameBurstStartWait.Attach(pNodeMap, "EventFrameBurstStartWait");
        m_pData->EventFrameBurstStartWaitTimestamp.Attach(pNodeMap, "EventFrameBurstStartWaitTimestamp");
        m_pData->EventFrameStart.Attach(pNodeMap, "EventFrameStart");
        m_pData->EventFrameStartFrameID.Attach(pNodeMap, "EventFrameStartFrameID");
        m_pData->EventFrameStartOvertrigger.Attach(pNodeMap, "EventFrameStartOvertrigger");
        m_pData->EventFrameStartOvertriggerFrameID.Attach(pNodeMap, "EventFrameStartOvertriggerFrameID");
        m_pData->EventFrameStartOvertriggerTimestamp.Attach(pNodeMap, "EventFrameStartOvertriggerTimestamp");
        m_pData->EventFrameStartTimestamp.Attach(pNodeMap, "EventFrameStartTimestamp");
        m_pData->EventFrameStartWait.Attach(pNodeMap, "EventFrameStartWait");
        m_pData->EventFrameStartWaitTimestamp.Attach(pNodeMap, "EventFrameStartWaitTimestamp");
        m_pData->EventNotification.Attach(pNodeMap, "EventNotification");
        m_pData->EventOverTemperature.Attach(pNodeMap, "EventOverTemperature");
        m_pData->EventOverTemperatureTimestamp.Attach(pNodeMap, "EventOverTemperatureTimestamp");
        m_pData->EventSelector.Attach(pNodeMap, "EventSelector");
        m_pData->ExpertFeatureAccessKey.Attach(pNodeMap, "ExpertFeatureAccessKey");
        m_pData->ExpertFeatureAccessSelector.Attach(pNodeMap, "ExpertFeatureAccessSelector");
        m_pData->ExpertFeatureEnable.Attach(pNodeMap, "ExpertFeatureEnable");
        m_pData->ExposureAuto.Attach(pNodeMap, "ExposureAuto");
        m_pData->ExposureMode.Attach(pNodeMap, "ExposureMode");
        m_pData->ExposureOverlapTimeMax.Attach(pNodeMap, "ExposureOverlapTimeMax");
        m_pData->ExposureOverlapTimeMode.Attach(pNodeMap, "ExposureOverlapTimeMode");
        m_pData->ExposureTime.Attach(pNodeMap, "ExposureTime");
        m_pData->ExposureTimeMode.Attach(pNodeMap, "ExposureTimeMode");
        m_pData->FileAccessBuffer.Attach(pNodeMap, "FileAccessBuffer");
        m_pData->FileAccessLength.Attach(pNodeMap, "FileAccessLength");
        m_pData->FileAccessOffset.Attach(pNodeMap, "FileAccessOffset");
        m_pData->FileOpenMode.Attach(pNodeMap, "FileOpenMode");
        m_pData->FileOperationExecute.Attach(pNodeMap, "FileOperationExecute");
        m_pData->FileOperationResult.Attach(pNodeMap, "FileOperationResult");
        m_pData->FileOperationSelector.Attach(pNodeMap, "FileOperationSelector");
        m_pData->FileOperationStatus.Attach(pNodeMap, "FileOperationStatus");
        m_pData->FileSelector.Attach(pNodeMap, "FileSelector");
        m_pData->FileSize.Attach(pNodeMap, "FileSize");
        m_pData->Gain.Attach(pNodeMap, "Gain");
        m_pData->GainAuto.Attach(pNodeMap, "GainAuto");
        m_pData->GainSelector.Attach(pNodeMap, "GainSelector");
        m_pData->Gamma.Attach(pNodeMap, "Gamma");
        m_pData->Height.Attach(pNodeMap, "Height");
        m_pData->HeightMax.Attach(pNodeMap, "HeightMax");
        m_pData->LUTEnable.Attach(pNodeMap, "LUTEnable");
        m_pData->LUTIndex.Attach(pNodeMap, "LUTIndex");
        m_pData->LUTSelector.Attach(pNodeMap, "LUTSelector");
        m_pData->LUTValue.Attach(pNodeMap, "LUTValue");
        m_pData->LUTValueAll.Attach(pNodeMap, "LUTValueAll");
        m_pData->LightSourcePreset.Attach(pNodeMap, "LightSourcePreset");
        m_pData->LineDebouncerTime.Attach(pNodeMap, "LineDebouncerTime");
        m_pData->LineFormat.Attach(pNodeMap, "LineFormat");
        m_pData->LineInverter.Attach(pNodeMap, "LineInverter");
        m_pData->LineLogic.Attach(pNodeMap, "LineLogic");
        m_pData->LineMinimumOutputPulseWidth.Attach(pNodeMap, "LineMinimumOutputPulseWidth");
        m_pData->LineMode.Attach(pNodeMap, "LineMode");
        m_pData->LineOverloadStatus.Attach(pNodeMap, "LineOverloadStatus");
        m_pData->LineSelector.Attach(pNodeMap, "LineSelector");
        m_pData->LineSource.Attach(pNodeMap, "LineSource");
        m_pData->LineStatus.Attach(pNodeMap, "LineStatus");
        m_pData->LineStatusAll.Attach(pNodeMap, "LineStatusAll");
        m_pData->NoiseReduction.Attach(pNodeMap, "NoiseReduction");
        m_pData->OffsetX.Attach(pNodeMap, "OffsetX");
        m_pData->OffsetY.Attach(pNodeMap, "OffsetY");
        m_pData->PayloadSize.Attach(pNodeMap, "PayloadSize");
        m_pData->PgiMode.Attach(pNodeMap, "PgiMode");
        m_pData->PixelColorFilter.Attach(pNodeMap, "PixelColorFilter");
        m_pData->PixelDynamicRangeMax.Attach(pNodeMap, "PixelDynamicRangeMax");
        m_pData->PixelDynamicRangeMin.Attach(pNodeMap, "PixelDynamicRangeMin");
        m_pData->PixelFormat.Attach(pNodeMap, "PixelFormat");
        m_pData->PixelSize.Attach(pNodeMap, "PixelSize");
        m_pData->ROIZoneMode.Attach(pNodeMap, "ROIZoneMode");
        m_pData->ROIZoneOffset.Attach(pNodeMap, "ROIZoneOffset");
        m_pData->ROIZoneSelector.Attach(pNodeMap, "ROIZoneSelector");
        m_pData->ROIZoneSize.Attach(pNodeMap, "ROIZoneSize");
        m_pData->RemoveParameterLimit.Attach(pNodeMap, "RemoveParameterLimit");
        m_pData->RemoveParameterLimitSelector.Attach(pNodeMap, "RemoveParameterLimitSelector");
        m_pData->ResultingFrameRate.Attach(pNodeMap, "ResultingFrameRate");
        m_pData->ReverseX.Attach(pNodeMap, "ReverseX");
        m_pData->ReverseY.Attach(pNodeMap, "ReverseY");
        m_pData->SIPayloadFinalTransfer1Size.Attach(pNodeMap, "SIPayloadFinalTransfer1Size");
        m_pData->SIPayloadFinalTransfer2Size.Attach(pNodeMap, "SIPayloadFinalTransfer2Size");
        m_pData->SIPayloadTransferCount.Attach(pNodeMap, "SIPayloadTransferCount");
        m_pData->SIPayloadTransferSize.Attach(pNodeMap, "SIPayloadTransferSize");
        m_pData->ScalingHorizontal.Attach(pNodeMap, "ScalingHorizontal");
        m_pData->ScalingVertical.Attach(pNodeMap, "ScalingVertical");
        m_pData->SensorHeight.Attach(pNodeMap, "SensorHeight");
        m_pData->SensorReadoutMode.Attach(pNodeMap, "SensorReadoutMode");
        m_pData->SensorReadoutTime.Attach(pNodeMap, "SensorReadoutTime");
        m_pData->SensorWidth.Attach(pNodeMap, "SensorWidth");
        m_pData->SequencerConfigurationMode.Attach(pNodeMap, "SequencerConfigurationMode");
        m_pData->SequencerMode.Attach(pNodeMap, "SequencerMode");
        m_pData->SequencerPathSelector.Attach(pNodeMap, "SequencerPathSelector");
        m_pData->SequencerSetActive.Attach(pNodeMap, "SequencerSetActive");
        m_pData->SequencerSetLoad.Attach(pNodeMap, "SequencerSetLoad");
        m_pData->SequencerSetNext.Attach(pNodeMap, "SequencerSetNext");
        m_pData->SequencerSetSave.Attach(pNodeMap, "SequencerSetSave");
        m_pData->SequencerSetSelector.Attach(pNodeMap, "SequencerSetSelector");
        m_pData->SequencerSetStart.Attach(pNodeMap, "SequencerSetStart");
        m_pData->SequencerTriggerActivation.Attach(pNodeMap, "SequencerTriggerActivation");
        m_pData->SequencerTriggerSource.Attach(pNodeMap, "SequencerTriggerSource");
        m_pData->SharpnessEnhancement.Attach(pNodeMap, "SharpnessEnhancement");
        m_pData->ShutterMode.Attach(pNodeMap, "ShutterMode");
        m_pData->SoftwareSignalPulse.Attach(pNodeMap, "SoftwareSignalPulse");
        m_pData->SoftwareSignalSelector.Attach(pNodeMap, "SoftwareSignalSelector");
        m_pData->TemperatureState.Attach(pNodeMap, "TemperatureState");
        m_pData->TestImageResetAndHold.Attach(pNodeMap, "TestImageResetAndHold");
        m_pData->TestImageSelector.Attach(pNodeMap, "TestImageSelector");
        m_pData->TimerDelay.Attach(pNodeMap, "TimerDelay");
        m_pData->TimerDuration.Attach(pNodeMap, "TimerDuration");
        m_pData->TimerSelector.Attach(pNodeMap, "TimerSelector");
        m_pData->TimerTriggerSource.Attach(pNodeMap, "TimerTriggerSource");
        m_pData->TimestampLatch.Attach(pNodeMap, "TimestampLatch");
        m_pData->TimestampLatchValue.Attach(pNodeMap, "TimestampLatchValue");
        m_pData->TriggerActivation.Attach(pNodeMap, "TriggerActivation");
        m_pData->TriggerDelay.Attach(pNodeMap, "TriggerDelay");
        m_pData->TriggerMode.Attach(pNodeMap, "TriggerMode");
        m_pData->TriggerSelector.Attach(pNodeMap, "TriggerSelector");
        m_pData->TriggerSoftware.Attach(pNodeMap, "TriggerSoftware");
        m_pData->TriggerSource.Attach(pNodeMap, "TriggerSource");
        m_pData->UserDefinedValue.Attach(pNodeMap, "UserDefinedValue");
        m_pData->UserDefinedValueSelector.Attach(pNodeMap, "UserDefinedValueSelector");
        m_pData->UserOutputSelector.Attach(pNodeMap, "UserOutputSelector");
        m_pData->UserOutputValue.Attach(pNodeMap, "UserOutputValue");
        m_pData->UserOutputValueAll.Attach(pNodeMap, "UserOutputValueAll");
        m_pData->UserSetDefault.Attach(pNodeMap, "UserSetDefault");
        m_pData->UserSetLoad.Attach(pNodeMap, "UserSetLoad");
        m_pData->UserSetSave.Attach(pNodeMap, "UserSetSave");
        m_pData->UserSetSelector.Attach(pNodeMap, "UserSetSelector");
        m_pData->VignettingCorrectionLoad.Attach(pNodeMap, "VignettingCorrectionLoad");
        m_pData->VignettingCorrectionMode.Attach(pNodeMap, "VignettingCorrectionMode");
        m_pData->Width.Attach(pNodeMap, "Width");
        m_pData->WidthMax.Attach(pNodeMap, "WidthMax");
    }

    //! \endcond

} // namespace Pylon
} // namespace BaslerCameraCameraParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BASLERCAMERACAMERAPARAMS_H