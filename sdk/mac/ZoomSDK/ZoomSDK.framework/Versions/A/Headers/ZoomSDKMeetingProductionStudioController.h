/**
 * @file ZoomSDKMeetingProductionStudioController.h
 * @brief Interface for managing Zoom Meeting Production Studio mode and sending video or audio data.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKPSSender
 * @brief Provides APIs to send video and audio data to the production studio.
 */
@interface ZoomSDKPSSender : NSObject

/**
 * @brief Sends video to production studio.
 * @param frameBuffer The data to send.
 * @param width The data's width to send.
 * @param height The data's height to send.
 * @param frameLength The data's length to send.
 * @param format The format of frame data.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The video's width and height data sent are same with the width and height in \link ZoomSDKPSVideoSourceCapability \endlink, which is passed in when calling \link startPSMode \endlink. If they are not same, returns ZoomSDKError_InvalidParameter.
 */
- (ZoomSDKError)sendVideoFrame:(char*)frameBuffer width:(unsigned int)width height:(unsigned int)height frameLength:(unsigned int)frameLength format:(ZoomSDKFrameDataFormat)format;

/**
 * @brief Sends audio to production studio.
 * @param data The audio data's address.
 * @param length The audio data's length, in even numbers.
 * @param rate The audio data's sampling rate. 
 * @param channel The channel type, default is ZoomSDKAudioChannel_Mono.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendAudio:(char*)data dataLength:(unsigned int)length sampleRate:(int)rate channel:(ZoomSDKAudioChannel)channel;

@end


/**
 * @class ZoomSDKPSVideoSourceCapability
 * @brief Describes video source capabilities for production studio mode.
 */
@interface ZoomSDKPSVideoSourceCapability : NSObject

/**
 * @brief The width of send video data.
 */
@property (nonatomic, assign) int width;

/**
 * @brief The height of send video data.
 */
@property (nonatomic, assign) int height;

/**
 * @brief The format of send video data.
 */
@property (nonatomic, assign) ZoomSDKFrameDataFormat format;
@end


/**
 * @protocol ZoomSDKMeetingProductionStudioControllerDelegate
 * @brief Delegate to receive callbacks related to production studio mode events.
 */
@protocol ZoomSDKMeetingProductionStudioControllerDelegate <NSObject>

/**
 * @brief Notify the result of starting production studio mode.
 * @param success YES if PS mode is started successfully, NO otherwise.
 */
- (void)onStartPSModeResult:(BOOL)success;

/**
 * @brief This callback is received when production studio starts.
 * @param sender The object of send video or audio data.
 */
- (void)onStartSend:(ZoomSDKPSSender* _Nullable)sender;

/**
 * @brief This callback is received when production studio stops.
 */
- (void)onStopSend;

@optional
/**
 * @brief This callback is received when the production studio user starts and stops.
 * @param userId The production studio user ID.
 * @param bStart YES if the production studio user starts sending video and audio, NO if the production studio user stopped sending video and audio.
 */
- (void)onPSUserStatusChanged:(unsigned int)userId isStart:(BOOL)start;
@end



/**
 * @class ZoomSDKMeetingProductionStudioController
 * @brief Provides control and status APIs for Zoom meeting production studio mode.
 */
@interface ZoomSDKMeetingProductionStudioController : NSObject

@property(nonatomic, assign, nullable)id<ZoomSDKMeetingProductionStudioControllerDelegate> delegate;

/**
 * @brief Returns if production studio mode is supported.
 * @return YES if production studio mode is supported. Otherwise, NO.
 */
- (BOOL)isSupportPSMode;

/**
 * @brief Determines if you have permission to start production studio mode. Only the host or cohost can start production studio mode.
 * @return If you have permission to start production studio mode, return YES. Otherwise return NO.
 */
- (BOOL)canStartPSMode;

/**
 * @brief Starts production studio mode. After starting, send data to video and audio publication to production studio through the \link ZoomSDKPSSender \endlink interface.
 * @param capability Format description of the video data sent.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startPSMode:(ZoomSDKPSVideoSourceCapability*)capability;

/**
 * @brief Stops production studio mode.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopPSMode;

/**
 * @brief Determines if production studio mode has started.
 * @return YES if production studio mode is started. Otherwise, NO.
 */
- (BOOL)isPSModeStarted;

/**
 * @brief Returns the current production studio user ID.
 * @return The user ID of current production studio user.
 */
- (unsigned int)getPSUserID;
@end

NS_ASSUME_NONNULL_END
