/**
 * @file ZoomSDKRawDataVideoSourceController.h
 * @brief Interfaces for managing virtual video source and raw video preprocessing in Zoom SDK.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKRawDataController.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKYUVProcessDataI420
 * @brief Represents I420 YUV video frame data.
 */
@interface ZoomSDKYUVProcessDataI420 : NSObject
/**
 * @brief Gets the width of this data.
 * @return If the function succeeds, it returns the width of this data. Otherwise, returns 0.
 */
- (unsigned int)getWidth;

/**
 * @brief Gets the height of this data.
 * @return If the function succeeds, it returns the height of this data. Otherwise, returns 0.
 */
- (unsigned int)getHeight;

/**
 * @brief Gets the Y buffer of this data.
 * @return If the function succeeds, it returns the Y buffer of this data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getYBuffer:(unsigned int)lineNum;

/**
 * @brief Gets the U buffer of this data.
 * @return If the function succeeds, it returns the U buffer of this data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getUBuffer:(unsigned int)lineNum;

/**
 * @brief Gets the V buffer of this data.
 * @return If the function succeeds, it returns the V buffer of this data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getVBuffer:(unsigned int)lineNum;

/**
 * @brief Gets the V stride of this data.
 * @return If the function succeeds, it returns the V stride of this data. Otherwise, returns 0.
 */
- (unsigned int)getYStride;

/**
 * @brief Gets the U stride of this data.
 * @return If the function succeeds, it returns the U stride of this data. Otherwise, returns 0.
 */
- (unsigned int)getUStride;

/**
 * @brief Gets the V stride of this data.
 * @return If the function succeeds, it returns the V stride of this data. Otherwise, returns 0.
 */
- (unsigned int)getVStride;

/**
 * @brief Gets the rotation of this data.
 * @return If the function succeeds, it returns the rotation of this data. Otherwise, returns 0.
 */
- (unsigned int)getRotation;

/**
 * @brief Gets if this data is limited I420.
 * @return If it is limited I420, it returns YES. Otherwise, NO.
 */
- (BOOL)isLimitedI420;
@end


/**
 * @class ZoomSDKVideoCapabilityItem
 * @brief Represents video capability information.
 */
@interface ZoomSDKVideoCapabilityItem : NSObject
/**
 * @brief Gets the width of this data.
 * @return If the function succeeds, it returns the width of this data. Otherwise, returns 0.
 */
- (unsigned int)getWidth;

/**
 * @brief Gets the height of this data.
 * @return If the function succeeds, it returns the height of this data. Otherwise, returns 0.
 */
- (unsigned int)getHeight;

/**
 * @brief Gets the frame of this data.
 * @return If the function succeeds, it returns the frame of this data. Otherwise, returns 0.
 */
- (unsigned int)getFrame;
@end


/**
 * @class ZoomSDKRawDataSender
 * @brief Sends raw video frame data into the meeting.
 */
@interface ZoomSDKRawDataSender : NSObject

/**
 * @brief Sends raw video data in meeting.
 * @param data The data to send.
 * @param width The data's width to send.
 * @param height The data's height to send.
 * @param length The data's length to send.
 * @param rotation The data's rotation to send.
 * @brief Sends raw video data in meeting.
 * @param data The data to send.
 * @param width The data's width to send.
 * @param height The data's height to send.
 * @param length The data's length to send.
 * @param rotation The data's rotation to send.
 */
- (void)sendRawData:(char*)data width:(unsigned int)width height:(unsigned int)height dataLength:(unsigned int)length rotation:(ZoomSDKLocalVideoDeviceRotation)rotation;
@end

/**
 * @protocol ZoomSDKVirtualVideoSourceDelegate
 * @brief Callback interface for managing virtual video source.
 */
@protocol ZoomSDKVirtualVideoSourceDelegate <NSObject>
/**
 * @brief Callback when the virtual video source is initialized.
 * @param sender The sender object used to send raw video data.
 * @param capabilityList List of supported video capabilities.
 * @param suggestCap The suggested video capability for the current device.
 */
- (void)onInitialize:(ZoomSDKRawDataSender*_Nullable)sender supportedCapabilityList:(NSArray*_Nullable)capabilityList suggestCapability:(ZoomSDKVideoCapabilityItem*_Nullable)suggestCap;

/**
 * @brief Callback when the virtual video source property changes.
 * @param supportedCapabilityList List of updated supported video capabilities.
 * @param suggestCap The updated suggested video capability.
 */
- (void)onPropertyChange:(NSArray*_Nullable)supportedCapabilityList suggestCapability:(ZoomSDKVideoCapabilityItem*_Nullable)suggestCap;

/**
 * @brief Callback to indicate the start of video data sending.
 */
- (void)onStartSend;

/**
 * @brief Callback to indicate the stop of video data sending.
 */
- (void)onStopSend;

/**
 * @brief Callback when the virtual video source is uninitialized.
 */
- (void)onUninitialize;
@end

/**
 * @protocol ZoomSDKRawDataSendDelegate
 * @brief Callback for preprocessing raw video frames before rendering or transmission.
 */
@protocol ZoomSDKRawDataSendDelegate <NSObject>
/**
 * @brief Notify the delegate to preprocess a raw data.
 * @param data The raw YUV data.
 */
- (void)onPreProcessRawData:(ZoomSDKYUVProcessDataI420*_Nullable)data;
@end

/**
 * @class ZoomSDKRawDataVideoSourceController
 * @brief Controller for sending raw video frame data into the meeting.
 */
@interface ZoomSDKRawDataVideoSourceController : NSObject
/**
 * @brief Register the delegate of raw data preprocessor.
 * @param delegate The delegate to receive callback.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)registerRawDataPreProcessor:(id<ZoomSDKRawDataSendDelegate>)delegate;

/**
 * @brief UnRegister the delegate of raw data preprocessor.
 * @param delegate The delegate to receive callback.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)unRegisterRawDataPreProcessor:(id<ZoomSDKRawDataSendDelegate>)delegate;

/**
 * @brief Sets the delegate of virtual video source.
 * @brief Sets the delegate of virtual video source and video data format.
 * @param videoSource The delegate to receive callback. Pass nil to clear external source.
 * @param format The external source frame format.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setExternalVideoSource:(id <ZoomSDKVirtualVideoSourceDelegate> _Nullable)videoSource videoDataFormat:(ZoomSDKFrameDataFormat)format;
@end
NS_ASSUME_NONNULL_END
