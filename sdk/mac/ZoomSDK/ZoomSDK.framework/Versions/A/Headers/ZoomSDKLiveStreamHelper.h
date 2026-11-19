/**
 * @file ZoomSDKLiveStreamHelper.h
 * @brief Interfaces for managing standard and raw live streaming in Zoom meetings.
 */


#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKLiveStreamItem
 * @brief Represents a standard live stream target with URL and description.
 */
@interface ZoomSDKLiveStreamItem : NSObject
/**
 * @brief Gets live stream URL.
 * @return If the function succeeds, it returns the live stream URL. Otherwise, this function fails and returns nil.
 */
- (NSString*)getLiveStreamURL;

/**
 * @brief Gets the live's viewer URL stream meeting.
 * @return If the function succeeds, it returns the live's viewer URL stream meeting. Otherwise, this function fails and returns nil.
 */
- (NSString*)getLiveStreamViewerURL;

/**
 * @brief Gets description of live stream URL.
 * @return If the function succeeds, it returns the descriptions of live stream URL. Otherwise, this function fails and returns nil.
 */
- (NSString*)getLiveStreamURLDescription;
@end

/**
 * @class ZoomSDKRawLiveStreamInfo
 * @brief Information of an active raw live stream.
 */
@interface ZoomSDKRawLiveStreamInfo : NSObject
/**
 * @brief Gets the user ID.
 */
@property(nonatomic, assign, readonly) unsigned int userID;
/**
 * @brief Gets the broadcast URL.
 */
@property(nonatomic, copy, readonly) NSString *broadcastUrl;
/**
 * @brief Gets the broadcast name.
 */
@property(nonatomic, copy, readonly) NSString *broadcastName;
@end


/**
 * @class ZoomSDKRequestRawLiveStreamPrivilegeHandler
 * @brief Process after the host receives the requirement from the user to give the raw live stream privilege.
 */
@interface ZoomSDKRequestRawLiveStreamPrivilegeHandler : NSObject
/**
 * @brief Gets the request ID.
 */
@property(nonatomic, copy, readonly, nullable) NSString *requestId;
/**
 * @brief Gets the user ID who requested privilege.
 */
@property(nonatomic, assign, readonly) unsigned int requesterId;
/**
 * @brief Gets the user name who requested privileges.
 */
@property(nonatomic, copy, readonly, nullable) NSString *requesterName;
/**
 * @brief Gets the broadcast URL.
 */
@property(nonatomic, copy, readonly, nullable) NSString *broadcastUrl;
/**
 * @brief Gets the broadcast name.
 */
@property(nonatomic, copy, readonly, nullable) NSString *broadcastName;

/**
 * @brief Allows the user to start raw live stream and finally self-destroy.
 * @return If the function succeeds, it returns ZoomSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)grantRawLiveStreamPrivilege;

/**
 * @brief Denies the user permission to start raw live stream and finally self-destroy.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)denyRawLiveStreamPrivilege;
@end

/**
 * @protocol ZoomSDKLiveStreamHelperDelegate
 * @brief Protocol for receiving live stream-related events and updates.
 */
@protocol ZoomSDKLiveStreamHelperDelegate <NSObject>
/**
 * @brief Callback event when live stream status changes.
 * @param status The live streaming status.
 */
- (void)onLiveStreamStatusChange:(LiveStreamStatus)status;

/**
 * @brief Callback event when the current user's raw live streaming privilege changes.
 * @param bHasPrivilege Specify whether or not the user has privilege.
 */
- (void)onRawLiveStreamPrivilegeChanged:(BOOL)bHasPrivilege;

/**
 * @brief Callback event when the current user's request has times out.
 */
- (void)onRawLiveStreamPrivilegeRequestTimeout;

/**
 * @brief Callback event when another user's raw live streaming privilege changes.
 * @param userID The user's ID whose privilege changed.
 * @param bHasPrivilege Specify whether or not the user has privilege.
 */
- (void)onUserRawLiveStreamPrivilegeChanged:(unsigned int)userID hasPrivilege:(BOOL)bHasPrivilege;

/**
 * @brief Callback event when a user requests raw live streaming privilege.
 * @param handler A pointer to the ZoomSDKRequestRawLiveStreamPrivilegeHandler.
 */
- (void)onRawLiveStreamPrivilegeRequested:(ZoomSDKRequestRawLiveStreamPrivilegeHandler*_Nullable)handler;

/**
 * @brief Callback event when users start or stop raw live streaming.
 * @param liveStreamList A list of users with an active raw live stream.
 */
- (void)onUserRawLiveStreamingStatusChanged:(NSArray<ZoomSDKRawLiveStreamInfo*>*_Nullable)liveStreamList;

/**
 * @brief Callback event when the live stream reminder enable status changes.
 * @param enable YES if the live stream reminder is enabled, NO otherwise.
 */
- (void)onLiveStreamReminderStatusChanged:(BOOL)enable;

/**
 * @brief Callback event when the live stream reminder enable status change fails.
 */
- (void)onLiveStreamReminderStatusChangeFailed;

/**
 * @brief Callback event when the meeting or webinar user has nearly reached the meeting capacity, like 80% or 100% for the meeting or webinar capacity.
 * The host can start live stream to let unjoined users to watch live stream.
 * @param percent Proportion of joined users to the total capacity.
 */
- (void)onUserThresholdReachedForLiveStream:(int)percent;
@end


/**
 * @class ZoomSDKLiveStreamHelper
 * @brief Interface for managing standard and raw live streams in a meeting.
 */
@interface ZoomSDKLiveStreamHelper : NSObject
{
    id<ZoomSDKLiveStreamHelperDelegate> _delegate;
}
/**
 * @brief Sets or get the delegate to receive live stream event callbacks.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKLiveStreamHelperDelegate> delegate;
/**
 * @brief Query if it is able for the user to enable live stream.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */

- (ZoomSDKError)canStartLiveStream;

/**
 * @brief Gets the list of live stream information items in the current meeting.
 * @return If the function succeeds, it returns the the live stream item list. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKLiveStreamItem*>*_Nullable)getSupportLiveStreamItems;

/**
 * @brief Gets the current live stream object.
 * @return If the function succeeds, it returns the current live stream object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKLiveStreamItem*_Nullable)getCurrentLiveStreamItem;

/**
 * @brief Starts a live stream.
 * @param item The item of live stream supported by the SDK.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startLiveStream:(ZoomSDKLiveStreamItem*)item;

/**
 * @brief Starts a live stream with the URL customized by user.
 * @param streamURL The URL of customized live stream.
 * @param key The key of customized stream stream.
 * @param broadcastURL Everyone who uses this link can watch the live broadcast.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startLiveStreamByURL:(NSString*)streamURL StreamKey:(NSString*)key BroadcastURL:(NSString*)broadcastURL;

/**
 * @brief Stops a live stream.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopLiveStream;

/**
 * @brief Gets the status of current live stream.
 * @return If the function succeeds, it returns the LiveStreamStatus_InProgress. Otherwise, this function returns an error.
 */
- (LiveStreamStatus)getLiveStreamStatus;

/**
 * @brief Query Whether the meeting supports raw live streams.
 * @return Yes if supported, Otherwise, NO.
 */
- (BOOL)isRawLiveStreamSupported;

/**
 * @brief Whether if the current user is able to start raw live streaming.
 * @return If the current user is able to start raw live streaming, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canStartRawLiveStream;

/**
 * @brief Sends a request to enable the SDK to start a raw live stream.
 * @param broadcastURL The live stream's broadcast URL.
 * @param broadcastName The live stream's broadcast name.
 * @return If the function succeeds, it returns ZoomSDKError_Success and the SDK will send the request. Otherwise, this function returns an error and the request will not be sent.
 */
- (ZoomSDKError)requestRawLiveStreaming:(NSString*)broadcastURL broadcastName:(NSString*)broadcastName;

/**
 * @brief Starts raw live streaming.
 * @param broadcastURL The live stream's broadcast URL
 * @param broadcastName The live stream's broadcast name.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startRawLiveStreaming:(NSString *)broadcastURL broadcastName:(NSString*)broadcastName;

/**
 * @brief Stops raw live streaming.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopRawLiveStream;

/**
 * @brief Removes the raw live stream privilege.
 * @param userID Specify the user's ID whose privilege will be removed.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeRawLiveStreamPrivilege:(unsigned int)userID;

/**
 * @brief Gets a list of current active raw live streams.
 * @return If the function succeeds, it returns a pointer to the NSArray object. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKRawLiveStreamInfo*>*_Nullable)getRawLiveStreamingInfoList;

/**
 * @brief Gets the list of users’ IDs who have raw live stream privileges.
 * @return If the function succeeds, it returns a pointer to the NSArray object. Otherwise, this function fails and returns nil.
 */
- (NSArray<NSNumber*>*_Nullable)getRawLiveStreamPrivilegeUserList;
/**
 * @brief Checks if the live stream reminder is enabled.
 * When the live stream reminder is enabled, the new join user is notified that the meeting is at capacity but that they can watch the meeting live stream with the callback \link ZoomSDKMeetingServiceDelegate::onMeetingFullToWatchLiveStream: \endlink when the meeting user has reached the meeting capacity.
 * @return YES if the live stream reminder is enabled. Otherwise, NO.
 */
- (BOOL)isLiveStreamReminderEnabled;

/**
 * @brief Checks if the current user can enable or disable the live stream reminder.
 * @return YES if the current user can enable or disable the live stream reminder. Otherwise, NO.
 */
- (BOOL)canEnableLiveStreamReminder;

/**
 * @brief Enables or disable the live stream reminder.
 * @param enable YES to enable the live stream reminder, NO to disable the live stream reminder.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableLiveStreamReminder:(BOOL)enable;
@end
NS_ASSUME_NONNULL_END
