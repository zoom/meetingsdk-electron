/**
 * @file ZoomSDKRawDataAudioSourceController.h
 * @brief Interfaces for sending custom raw audio data into the Zoom SDK as a virtual microphone source.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKRawDataController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKAudioRawDataSender
 * @brief Sends external raw audio data to the Zoom meeting.
 */
@interface ZoomSDKAudioRawDataSender : NSObject

/**
 * @brief Sends audio raw data, Audio sample bits must be 16-bit audio.
 * @param data The audio data‘s address.
 * @param length The audio data’s length. Must be an even number.
 * @param rate The audio data's sampling rate. When the channel is mono, supported sample rates are 8000, 11025, 16000, 32000, 44100, 48000, 50000, 50400, 96000, 192000, or 2822400. When the channel is stereo, supported sample rates are 8000, 16000, 32000, 44100, 48000, 50000, 50400, 96000, or 192000.
 * @param channel Identifies the audio data channel type, default is ZoomSDKAudioChannel_Mono.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note
 * 1. The size of a single input must not exceed the number of bytes corresponding to 100 ms of audio. Exceeding this limit returns ZoomSDKError_SendTooMuchDataInSingleTime.
 * 2. Variable-length input is supported; it is recommended to send audio data in 10 ms, 20 ms, or 30 ms chunks (not exceeding 100 ms).
 * 3. If ZoomSDKError_TooFrequentCall is returned, this is not a genuine error; please wait briefly before retrying—for example, sleep for 10 ms before attempting to send the data again.
 */
- (ZoomSDKError)send:(char*)data dataLength:(unsigned int)length sampleRate:(int)rate channel:(ZoomSDKAudioChannel)channel;
@end


/**
 * @protocol ZoomSDKVirtualAudioMicDelegate
 * @brief Callback protocol for handling virtual microphone events.
 */
@protocol ZoomSDKVirtualAudioMicDelegate <NSObject>
/**
 * @brief Callback for virtual audio mic to do some initialization.
 * @param rawdataSender A object of audio sender, you can send audio data based on this object.
 */
- (void)onMicInitialize:(ZoomSDKAudioRawDataSender*_Nullable)rawdataSender;
/**
 * @brief Callback for virtual audio mic can send raw data with 'rawdataSender'.
 */
- (void)onMicStartSend;
/**
 * @brief Callback for virtual audio mic should stop send raw data.
 */
- (void)onMicStopSend;
/**
 * @brief Callback for virtual audio mic is uninitialized.
 */
- (void)onMicUninitialized;
@end


/**
 * @class ZoomSDKRawDataAudioSourceController
 * @brief Configure external audio source as virtual microphone input.
 */
@interface ZoomSDKRawDataAudioSourceController : NSObject

/**
 * @brief Subscribe audio mic raw data with a callback.
 * @param audioMicDelegate The delegate to receive callback.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setExternalAudioSource:(id <ZoomSDKVirtualAudioMicDelegate> _Nullable)audioMicDelegate;
@end

NS_ASSUME_NONNULL_END
