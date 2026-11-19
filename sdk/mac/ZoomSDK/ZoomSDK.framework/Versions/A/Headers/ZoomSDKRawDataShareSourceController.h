/**
 * @file ZoomSDKRawDataShareSourceController.h
 * @brief Interfaces for external share source and audio source in Zoom SDK.
 */

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKShareSender
 * @brief Sends external share content into the meeting.
 */
@interface ZoomSDKShareSender : NSObject

/**
 * @brief Sends share raw data in meeting.
 * @param frameBuffer The data's buffer to send.
 * @param width The data's width to send.
 * @param height The data's height to send.
 * @param frameLength The data's length to send.
 * @param format The format of frame data.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendShareFrame:(char* _Nonnull)frameBuffer width:(unsigned int)width height:(unsigned int)height frameLength:(unsigned int)frameLength format:(ZoomSDKFrameDataFormat)format;
@end


/**
 * @protocol ZoomSDKShareSourceDelegate
 * @brief Callback interface for external share source.
 */
@protocol ZoomSDKShareSourceDelegate <NSObject>
/**
 * @brief Notify to start send share source.
 * @param sender The object of ZoomSDKShareSender to send share source.
 */
- (void)onStartSend:(ZoomSDKShareSender*_Nullable)sender;

/**
 * @brief Notify to stop send share source.
 */
- (void)onStopSend;
@end

/**
 * @class ZoomSDKShareAudioSender
 * @brief Sends external share audio content into the meeting.
 */
@interface ZoomSDKShareAudioSender : NSObject

/**
 * @brief Sends audio raw data.
 * @param data The audio data's address.
 * @param length The audio data's length, in even numbers.
 * @param rate The audio data's sampling rate.
 * @param channel The channel type, default is ZoomSDKAudioChannel_Mono.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Support sample rate: 44100 / 48000 / 50000 / 50400.
 * @note
 * 1. The size of a single input must not exceed the number of bytes corresponding to 100 ms of audio. Exceeding this limit returns ZoomSDKError_SendTooMuchDataInSingleTime.
 * 2. Variable-length input is supported; it is recommended to send audio data in 10 ms, 20 ms, or 30 ms chunks (not exceeding 100 ms).
 * 3. If ZoomSDKError_TooFrequentCall is returned, this is not a genuine error; please wait briefly before retrying—for example, sleep for 10 ms before attempting to send the data again.
 */
- (ZoomSDKError)sendShareAudio:(char* _Nonnull)data dataLength:(unsigned int)length sampleRate:(int)rate audioChannel:(ZoomSDKAudioChannel)channel;
@end

/**
 * @protocol ZoomSDKShareAudioSourceDelegate
 * @brief Callback interface for external share audio source.
 */
@protocol ZoomSDKShareAudioSourceDelegate <NSObject>

/**
 * @brief Callback for audio source to start sending raw data.
 * @param shareAudioSender The object of ZoomSDKShareAudioSender to send share audio source.
 */
- (void)onStartSendAudio:(ZoomSDKShareAudioSender*_Nullable)shareAudioSender;

/**
 * @brief Callback for audio source to stop sending audio raw data.
 */
- (void)onStopSendAudio;
@end


/**
 * @class ZoomSDKRawDataShareSourceController
 * @brief Manage external source for share video and share audio in meeting.
 */
@interface ZoomSDKRawDataShareSourceController : NSObject

/**
 * @brief Starts sharing external source.
 * @param shareSource The external source object pointer.
 * @param audioSource The pointer of external audio source object.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If audioSource is non-null, it indicates sharing user-defined audio at the same time.
 */
- (ZoomSDKError)setExternalShareSource:(id<ZoomSDKShareSourceDelegate> _Nonnull)shareSource shareAudioSource:(id<ZoomSDKShareAudioSourceDelegate> _Nullable)audioSource;

/**
 * @brief Starts sharing pure external audio source.
 * @param audioSource The pointer of external audio source object.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The feature is similar to sharing computer audio, except that the shared content is user-defined.
 */
- (ZoomSDKError)setSharePureAudioSource:(id<ZoomSDKShareAudioSourceDelegate> _Nonnull)audioSource;
@end
NS_ASSUME_NONNULL_END
