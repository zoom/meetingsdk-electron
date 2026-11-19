/**
 * @file ZoomSDKTalkbackController.h
 * @brief Interfaces for the Zoom SDK Talkback module.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKTalkbackChannel
 * @brief Represents a talkback channel object.
 */
@interface ZoomSDKTalkbackChannel : NSObject

/**
 * @brief Gets the channel's ID.
 */
@property(nonatomic, copy, readonly) NSString *channelID;

/**
 * @brief Gets the list of user IDs in the channel.
 */
@property(nonatomic, retain, readonly, nullable) NSArray<NSNumber*> *userIDList;


@end

/**
 * @protocol ZoomSDKTalkbackControllerDelegate
 * @brief Callback events for the talkback controller.
 */
@protocol ZoomSDKTalkbackControllerDelegate <NSObject>

@optional

/**
 * @brief Callback event when the create channel response is received.
 * @param channelID Specify the channel ID.
 * @param error Specify the error code.
 * @note Determine whether the channel is successfully created. createChannel: is asynchronous, so check this callback to verify the creation result.
 */
- (void)onCreateChannelResponse:(NSString *)channelID error:(ZoomSDKTalkbackError)error;

/**
 * @brief Callback event when the destroy channel response is received.
 * @param channelID Specify the channel ID.
 * @param error Specify the error code.
 * @note Determine whether the channel is successfully destroyed. destroyChannels: is asynchronous, so check this callback to verify the destruction result.
 */
- (void)onDestroyChannelResponse:(NSString *)channelID error:(ZoomSDKTalkbackError)error;

/**
 * @brief Callback event when the user joined channel response is received.
 * @param channelID Specify the channel ID.
 * @param userID Specify the user ID who joined the channel.
 * @param error Specify the error code.
 * @note Determine whether the user is successfully invited. inviteUsersToChannel:userIDList: is asynchronous, so check this callback to verify the invitation result.
 */
- (void)onChannelUserJoinResponse:(NSString *)channelID userID:(unsigned int)userID error:(ZoomSDKTalkbackError)error;

/**
 * @brief Callback event when the user left channel response is received.
 * @param channelID Specify the channel ID.
 * @param userID Specify the user ID who left the channel.
 * @param error Specify the error code.
 * @note Determine whether the user is successfully removed. removeUsersFromChannel:userIDList: is asynchronous, so check this callback to verify the removal result.
 */
- (void)onChannelUserLeaveResponse:(NSString *)channelID userID:(unsigned int)userID error:(ZoomSDKTalkbackError)error;

/**
 * @brief Callback event when the current user has joined the talkback channel.
 * @param inviterID Specify the user ID that was invited to join the channel.
 * @note This event notifies you that you have already entered the talkback channel, and the inviter ID is inviterID.
 */
- (void)onJoinTalkbackChannel:(unsigned int)inviterID;

/**
 * @brief Callback event when the current user has left the talkback channel.
 * @param inviterID Specify the user ID that left the channel.
 * @note This event notifies you that you have left the talkback channel.
 */
- (void)onLeaveTalkbackChannel:(unsigned int)inviterID;

/**
 * @brief Callback event for inviter audio level in talkback channel.
 * @param inviterID Specify the inviter user ID.
 * @param audioLevel Inviter audio volume, range 0-15.
 */
- (void)onInviterAudioLevel:(unsigned int)inviterID audioLevel:(unsigned int)audioLevel;

@end

/**
 * @class ZoomSDKTalkbackController
 * @brief Provides interfaces to manage talkback session in Zoom meeting.
 */
@interface ZoomSDKTalkbackController : NSObject

/**
 * @brief Gets or sets the delegate that receives talkback-related callback events.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKTalkbackControllerDelegate> delegate;

/**
 * @brief Determines whether the meeting supports talkback.
 * @return YES if the meeting supports talkback. Otherwise, NO.
 */
- (BOOL)isMeetingSupportTalkBack;

/**
 * @brief Creates talkback channels.
 * @param count Specify the number of channels to create. Supports a maximum of 16 channels.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note createChannel: is asynchronous. To determine whether the channel is successfully created, check the onCreateChannelResponse: error: event callback. 
 */
- (ZoomSDKError)createChannel:(unsigned int)count;

/**
 * @brief Gets a talkback channel by channel ID.
 * @param channelID Specify the channel ID to query.
 * @return If the function succeeds, it returns a ZoomSDKTalkbackChannel object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKTalkbackChannel* _Nullable)getChannelByID:(NSString *)channelID;

/**
 * @brief Gets the list of all talkback channels.
 * @return If the function succeeds, it returns an NSArray of talkback channel objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKTalkbackChannel*> * _Nullable)getChannelList;

/**
 * @brief Destroys talkback channels in batches.
 * @param channelIDs The array of channel IDs to destroy.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This operation is asynchronous. Check onDestroyChannelResponse:error: to verify the result.
 */
- (ZoomSDKError)destroyChannels:(NSArray<NSString*> *)channelIDs;

/**
 * @brief Invites users to a talkback channel in batches.
 * @param channelID The channel's ID to invite users to.
 * @param userIDList The array of user IDs to invite.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This operation is asynchronous. Check onChannelUserJoinResponse:userID:error: to verify the result. A channel can have at most 10 users.
 */
- (ZoomSDKError)inviteUsersToChannel:(NSString*)channelID userIDList:(NSArray<NSNumber*> *)userIDs;

/**
 * @brief Removes users from a talkback channel in batches.
 * @param channelID The channel's ID to remove users from.
 * @param userIDList The array of user IDs to remove.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This operation is asynchronous. Check onChannelUserLeaveResponse:userID:error: to verify the result.
 */
- (ZoomSDKError)removeUsersFromChannel:(NSString*)channelID userIDList:(NSArray<NSNumber*> *)userIDs;

/**
 * @brief Sends audio data to a talkback channel.
 * @param channelID Specify the channel ID.
 * @param audioData Specify the audio data buffer.
 * @param dataLength Specify the length of audio data in bytes.
 * @param sampleRate Specify the sample rate of the audio data like 32000 or 48000.
 * @param channel Specify the audio channel type either mono or stereo.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 *         If the return value is ZoomSDKError_TooFrequentCall, please slow down the sending frequency.
 * @note The audio data format should be PCM, 16-bit, mono or stereo. Sample rate 32kHz or 48kHz is recommended.
 *  1. The size of a single input must not exceed the number of audio bytes for 80 ms of audio.
 *  2. Variable-length input is supported. However, each input is recommended to contain at least 5 ms of audio data to avoid overly frequent system calls.
 *  3. The long-term average input rate must match the real-time rate; that is, N seconds of audio data should be provided within every N-second interval.
 *     Simply put, here are some easy-to-understand examples:
 *     Send 10 ms of audio data every 10 ms:
 *         32 kHz mono, 16-bit  : 32000 / 100 x 2 x 1 bytes per 10 ms
 *         32 kHz stereo, 16-bit: 32000 / 100 x 2 x 2 bytes per 10 ms
 *
 *     Send 20 ms of audio data every 20 ms:
 *         32 kHz mono, 16-bit  : 32000 / 50 x 2 x 1 bytes per 20 ms
 *         32 kHz stereo, 16-bit: 32000 / 50 x 2 x 2 bytes per 20 ms
 *  4. Common sample rates are supported, including 8 kHz, 16 kHz, 32 kHz, 44.1 kHz, and 48 kHz.
 *  5. Both mono and stereo audio input are supported.
 */
- (ZoomSDKError)sendAudioDataToChannel:(NSString *)channelID audioData:(char *)audioData dataLength:(unsigned int)dataLength sampleRate:(unsigned int)sampleRate channel:(ZoomSDKAudioChannel)channel;

/**
 * @brief Sets the background volume, the main meeting audio that people in the talkback channel can hear.
 * @param channelID Specify the channel ID. If you want people in the channel to hear the channel audio more clearly, decrease the backgroundVolume.
 * @param backgroundVolume Specify the background volume, from 0.0 to 2.0. If you want people in the channel to hear the channel audio more clearly, decrease the backgroundVolume.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setChannelBackgroundVolume:(NSString *)channelID backgroundVolume:(float)backgroundVolume;

@end

NS_ASSUME_NONNULL_END

