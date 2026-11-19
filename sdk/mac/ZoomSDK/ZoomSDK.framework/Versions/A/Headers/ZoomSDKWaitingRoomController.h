/**
 * @file ZoomSDKWaitingRoomController.h
 * @brief Interfaces for managing and customizing the waiting room in Zoom SDK.
 */


NS_ASSUME_NONNULL_BEGIN
@class ZoomSDKUserInfo;

/**
 * @class ZoomSDKWaitingRoomBrandingPageColor
 * @brief Branding background color configuration for the waiting room.
 */
@interface ZoomSDKWaitingRoomBrandingPageColor : NSObject
/**
 * @brief The background color.
 */
@property(retain, nonatomic, readonly,nullable)NSColor* backgroundColor;
@end


/**
 * @class ZoomSDKWaitingRoomBrandingTextColor
 * @brief Branding text color configuration for the waiting room.
 */
@interface ZoomSDKWaitingRoomBrandingTextColor : NSObject
/**
 * @brief The primary color.
 */
@property(retain, nonatomic, readonly, nullable)NSColor* primaryColor;
/**
 * @brief The secondary color.
 */
@property(retain, nonatomic, readonly,nullable)NSColor* secondaryColor;
/**
 * @brief The paragraph color.
 */
@property(retain, nonatomic, readonly,nullable)NSColor* paragraphColor;
/**
 * @brief The hyper link color.
 */
@property(retain, nonatomic, readonly,nullable)NSColor* hyperlinkColor;
@end


/**
 * @class ZoomSDKWaitingRoomBrandingButtonColor
 * @brief Branding button color configuration for the waiting room.
 */
@interface ZoomSDKWaitingRoomBrandingButtonColor : NSObject
/**
 * @brief The primary Button color.
 */
@property(retain, nonatomic, readonly,nullable)NSColor* primaryButtonColor;
@end


/**
 * @class ZoomSDKCustomWaitingRoomData
 * @brief Custom data configuration for the waiting room.
 */
@interface ZoomSDKCustomWaitingRoomData : NSObject
/**
 * @brief The title.
 */
@property (copy, nonatomic, readonly, nullable) NSString* title;
/**
 * @brief The description.
 */
@property (copy, nonatomic, readonly, nullable) NSString* dataDescription;
/**
 * @brief The path of logo image.
 */
@property (copy, nonatomic, readonly, nullable) NSString* logoPath;
/**
 * @brief The path of video file.
 */
@property (copy, nonatomic, readonly, nullable) NSString* videoPath;
/**
 * @brief The path of image file.
 */
@property (copy, nonatomic, readonly, nullable) NSString* imagePath;
/**
 * @brief The type.
 */
@property (assign, nonatomic, readonly) ZoomSDKWaitingRoomLayoutType type;
/**
 * @brief The status.
 */
@property (assign, nonatomic, readonly) ZoomSDKCustomWaitingRoomDataStatus status;
/**
 * @brief The object of waiting room branding page color.
 */
@property (retain, nonatomic, readonly) ZoomSDKWaitingRoomBrandingPageColor* pageColor;
/**
 * @brief The object of waiting room branding text color.
 */
@property (retain, nonatomic, readonly) ZoomSDKWaitingRoomBrandingTextColor* textColor;
/**
 * @brief The object of waiting room branding button color.
 */
@property (retain, nonatomic, readonly) ZoomSDKWaitingRoomBrandingButtonColor* buttonColor;
@end


/**
 * @class ZoomSDKWaitingRoomDataDownloadHandler
 * @brief Handler for retrying or ignoring waiting room custom data download failures.
 */
@interface ZoomSDKWaitingRoomDataDownloadHandler : NSObject
/**
 * @brief Retry to download the waiting room customize data information in the waiting room.
 */
- (void)retry;
/**
 * @brief Ignore to downloade the waiting room customize data information in the waiting room.
 */
- (void)ignore;
@end


/**
 * @protocol ZoomSDKWaitingRoomDelegate
 * @brief Protocol for receiving events related to the waiting room.
 */
@protocol ZoomSDKWaitingRoomDelegate <NSObject>
/**
 * @brief Callback of that user joins waiting room.
 * @param userid The ID of user who joins waiting room.
 */
- (void)onUserJoinWaitingRoom:(unsigned int)userid;
/**
 * @brief Callback of that user leaves waiting room.
 * @param userid The ID of user who leaves waiting room.
 */
- (void)onUserLeftWaitingRoom:(unsigned int)userid;

/**
 * @brief During the waiting room, this callback event triggers when host change audio status.
 * @param audioCanTurnOn YES if audio can be turned on, NO otherwise.
 */
- (void)onWaitingRoomPresetAudioStatusChanged:(BOOL)audioCanTurnOn;

/**
 * @brief During the waiting room, this callback event triggers when host change video status.
 * @param videoCanTurnOn YES if video can be turned on, NO otherwise.
 */
- (void)onWaitingRoomPresetVideoStatusChanged:(BOOL)videoCanTurnOn;

/**
 * @brief Callback of that customize data info updated.
 * @param bData The object of ZoomSDKCustomWaitingRoomData.
 * @param handle The object of ZoomSDKWaitingRoomDataDownloadHandler to handle download failed.
 */
- (void)onCustomWaitingRoomDataUpdated:(ZoomSDKCustomWaitingRoomData*_Nullable)bData handle:(ZoomSDKWaitingRoomDataDownloadHandler*_Nullable)handle;

/**
 * @brief Callback indicating that the name of a user in the waiting room has changed.
 * @param userID The user's ID whose user name has changed.
 * @param userName The new user name.
 */
- (void)onWaitingRoomUserNameChanged:(unsigned int)userID userName:(NSString *)userName;

/**
 * @brief This callback event triggers when host or cohost enables or disables waiting room entrance.
 * @param enabled YES to enable waiting room entrance, NO to disable waiting room entrance.
 */
- (void)onWaitingRoomEntranceEnabled:(BOOL)enabled;
@end


/**
 * @class ZoomSDKWaitingRoomController
 * @brief Interface for managing the waiting room during a meeting.
 */
@interface ZoomSDKWaitingRoomController : NSObject
{
    id<ZoomSDKWaitingRoomDelegate> _delegate;
}
/**
 * @brief Sets the delegate to receive waiting room events.
 */
@property (assign, nonatomic, nullable) id<ZoomSDKWaitingRoomDelegate> delegate;
/**
 * @brief Query if the meeting supports waiting room.
 * @return YES if supported. Otherwise, NO.
 */
- (BOOL)isSupportWaitingRoom;

/**
 * @brief Query if \link ZoomSDKWaitingRoomController::enableWaitingRoomOnEntry: \endlink feature locked.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isWaitingRoomOnEntryLocked;

/**
 * @brief Query if waiting room is enabled in current meeting.
 * @return YES if enabled. Otherwise, NO.	
 */
- (BOOL)isEnableWaitingRoomOnEntry;
/**
 * @brief Sets to enable or disable waiting room.
 * @param enable YES if enabled, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableWaitingRoomOnEntry:(BOOL)enable;
/**
 * @brief Gets the list of users in the waiting room.
 * @return If the function succeeds, it returns a NSArray. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getWaitRoomUserList;
/**
 * @brief Gets the information of users in the waiting room.
 * @param userid The ID of user who is in the waiting room.
 * @return If the function succeeds, it returns the object of ZoomSDKUserInfo for the specified user. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKUserInfo*_Nullable)getWaitingRoomUserInfo:(unsigned int)userid;
/**
 * @brief Admit user to join meeting.
 * @param userid The ID of user who joins meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)admitToMeeting:(unsigned int)userid;

/**
 * @brief  Permit all of the users currently in the waiting room to join the meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)admitAllToMeeting;

/**
 * @brief Put user into waiting room.
 * @param userid The ID of user who is put into waiting room by host or co-host.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)putIntoWaitingRoom:(unsigned int)userid;

/**
 * @brief Determines if the attendee is enabled to turn on audio when joining the meeting.
 * @return YES if enable to turn on. Otherwise, NO.
 */
- (BOOL)isAudioEnabledInWaitingRoom;

/**
 @brief Pre-set audio mute or unmute status in waiting room.
 @param muteAudio Pre-set audio mute or unmute status.
 @return @c ZoomSDKError_Success means the pre-set success. Otherwise, this function returns an error.
 @warning Only worked out of meeting.
 */
- (ZoomSDKError)presetAudioInWaitingRoom:(BOOL)muteAudio;

/**
 @brief Gets the audio pre-set mute or unmute status in waiting room.
 @return YES if pre-set unmute. Otherwise, NO.
 @warning Only worked out of meeting.
 */
- (BOOL)isPresetAudioUnmuteInWaitingRoom;

/**
 * @brief Determines if the attendee is enabled to turn on video when joining the meeting.
 * @return YES if enable to turn on. Otherwise, NO.
 */
- (BOOL)isVideoEnabledInWaitingRoom;

/**
 @brief Pre-set video mute or unmute status in waiting room.
 @param muteVideo Pre-set video mute or unmute status.
 @return @c ZoomSDKError_Success means the pre-set succeeded. Otherwise, this function returns an error.
 @warning Only worked out of meeting.
 */
- (ZoomSDKError)presetVideoInWaitingRoom:(BOOL)muteVideo;

/**
 @brief Gets the video pre-set mute or unmute status in waiting room.
 @return YES if pre-set unmute. Otherwise, NO.
 @warning Only worked out of meeting.
 */
- (BOOL)isPresetVideoUnmuteInWaitingRoom;

/**
 * @brief Gets the WaitingRoom CustomizeData information in the waiting room.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestCustomWaitingRoomData;

/**
 * @brief Determines if the host or cohost can rename users in the waiting room.
 * @return YES if the host or cohost can rename users in the waiting room. Otherwise, NO.
 */
- (BOOL)canRenameUser;

/**
 * @brief Change a screen name of the user in the waiting room.
 * @param userID The ID of users put into the waiting room by a host or cohost.
 * @param userName The new user name.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)renameUser:(unsigned int)userID newUserName:(NSString *)userName;

/**
 * @brief Determines if a host or cohost can expel users in the waiting room.
 * @return YES if that a host or cohost can expel users in the waiting room. Otherwise, NO.
 */
- (BOOL)canExpelUser;

/**
 * @brief Removes a specified user from the waiting room.
 * @param userID The user's ID  removed from the waiting room by a host or cohost.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)expelUser:(unsigned int)userID;
@end
NS_ASSUME_NONNULL_END
