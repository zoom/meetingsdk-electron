
#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKWallpaperItem
 * @brief Represents a wallpaper item.
 */
@interface ZoomSDKWallpaperItem : NSObject
/**
 * @brief Wall-paper ID
 */
@property (copy, nonatomic, readonly, nullable) NSString *wallpaperId;
/**
 * @brief The title.
 */
@property (copy, nonatomic, readonly, nullable) NSString *title;
/**
 * @brief Thumbnail path.
 */
@property (copy, nonatomic, readonly, nullable) NSString *thumbnailPath;
/**
 * @brief Full image path.
 */
@property (copy, nonatomic, readonly, nullable) NSString *path;
/**
 * @brief 0 ~ 255, -1 means no transparency. Only possible in Meeting wall-paper.
 */
@property (assign, nonatomic, readwrite) int transparency;
/**
 * @brief Layout mode of the wall-paper.
 */
@property (assign, nonatomic, readwrite) ZoomSDKWallpaperLayoutMode layoutMode;
@end

/**
 * @protocol ZoomSDKWallpaperControllerDelegate
 * @brief Delegate for wallpaper events.
 */
@protocol ZoomSDKWallpaperControllerDelegate <NSObject>
/**
 * @brief The personal wall-paper change.
 * @param item The changed item.
 */
- (void)onPersonalWallpaperChanged:(ZoomSDKWallpaperItem * _Nullable)item;
/**
 * @brief The status of personal wall-paper download.
 * @param status The wall-paper image download status.
 * @param wallpaperId The downloaded wall-paper image ID.
 */
- (void)onPersonalWallpaperImageDownloadStatus:(ZoomSDKWallpaperSettingStatus)status wallpaper:(NSString *)wallpaperId;
/**
 * @brief The meeting wall-paper change.
 * @param item The  changed item.
 */
- (void)onMeetingWallpaperChanged:(ZoomSDKWallpaperItem * _Nullable)item;
/**
 * @brief The status of meeting wall-paper download.
 * @param status The wall-paper image download status.
 * @param wallpaperId The download wall-paper image ID.
 */
- (void)onMeetingWallpaperImageDownloadStatus:(ZoomSDKWallpaperSettingStatus)status wallpaper:(NSString *)wallpaperId;
@end


/**
 * @class ZoomSDKWallpaperController
 * @brief Controller for managing wallpapers.
 */
@interface ZoomSDKWallpaperController : NSObject
/**
 * @brief Delegate object for handling wallpaper events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKWallpaperControllerDelegate> delegate;

/**
 * @brief Determines if the personal wall-paper feature enabled by OP.
 * @return YES if the feature enabled. Otherwise, NO.
 */
- (BOOL)isPersonalWallpaperEnabled;
/**
 * @brief Gets the current user's persional wall-paper config.
 * @return If the function succeeds, it returns the current user's personal wall-paper. Otherwise, this function fails and returns nil.
 * @note Only login user have this config, if select None, the wall-paper ID is empty.
 */
- (ZoomSDKWallpaperItem *)getCurrentPersonalWallpaperItem;
/**
 * @brief Gets the current user's persional wall-paper config list.
 * @return If the function succeeds, it returns the current user's personal wall-paper list. Otherwise, this function fails and returns nil.
 * @note Only login user have this config list.
 */
- (NSArray <ZoomSDKWallpaperItem *>* _Nullable)getPersonalWallpaperList;
/**
 * @brief Sets the current user's persional wall-paper config.
 * @param item Wall-paper item need to set.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only login user have this config list.
 */
- (ZoomSDKError)setPersonalWallpaper:(ZoomSDKWallpaperItem *)item;
/**
 * @brief Gets the persional wall-paper config by wall-paper ID.
 * @return If the function succeeds, it returns the personal wall-paper with the wall-paper ID. Otherwise, this function fails and returns nil.
 * @warning Only login user have this feature.
 */
- (ZoomSDKWallpaperItem * _Nullable)getPersonalWallpaperItemById:(NSString *)wallpaperId;
/**
 * @brief Determines if the meeting wall-paper feature enabled by OP.
 * @return YES if the feature enabled. Otherwise, NO.
 */
- (BOOL)isMeetingWallpaperEnabled;
/**
 * @brief Determines if meeting wall-paper thumbnail ready.
 * @return YES if ready. Otherwise, NO.
 */
- (BOOL)isMeetingWallpaperThumbsReady;
/**
 * @brief Gets the meeting wall-paper config.
 * @return If the function succeeds, it returns the current used meeting wall-paper. Otherwise, this function fails and returns nil.
 * @warning if select None, the wall-paper ID is empty.
 */
- (ZoomSDKWallpaperItem * _Nullable)getCurrentMeetingWallpaperItem;
/**
 * @brief Gets the meeting wall-paper config list.
 * @return If the function succeeds, it returns the meeting wall-paper list. Otherwise, this function fails and returns nil.
 */
- (NSArray <ZoomSDKWallpaperItem *>* _Nullable)getMeetingWallpaperList;
/**
 * @brief Sets the meeting wall-paper config.
 * @param item Wall-paper item need to set.
 * @return SDK error of the set opration. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setMeetingWallpaper:(ZoomSDKWallpaperItem *)item;
/**
 * @brief Gets the meeting wall-paper config by wall-paper ID.
 * @return If the function succeeds, it returns the meeting wall-paper with the wall-paper ID. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKWallpaperItem *)getMeetingWallpaperById:(NSString *)wallpaperId;
@end

/**
 * @class ZoomSDKGeneralSetting
 * @brief General settings interface for controlling meeting behaviors and UI customizations.
 */
@interface ZoomSDKGeneralSetting: NSObject
/**
 * @brief Enables or disable meeting settings by command.
 * @param enable YES to enable, NO otherwise.
 * @param cmd An enumeration of commands that you can enable or disable them in the meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableMeetingSetting:(BOOL)enable SettingCmd:(MeetingSettingCmd)cmd;
/**
 * @brief Sets custom link for invitation.
 * @param inviteURL The URL for invitation by which user can join meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustomInviteURL:(NSString*)inviteURL;

/**
 * @brief Hides setting components.
 * @param component An enumeration of components for controlling meeting.
 * @param hide YES to hide, NO to show.
 */
- (void)hideSettingComponent:(SettingComponent)component hide:(BOOL)hide;

/**
 * @brief Sets default URL for setting components.
 * @param urlType A enum specify the url you want to modify.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustomURL:(SDKURLType)urlType urlString:(NSString*)urlString;

/**
 * @brief Gets the current status of show meeting time
 * @return Yes is means show meeting time. Otherwise, NO.
 */
- (BOOL)isShowLockMeetingTime;

/**
 * @brief Enables or disenable to set show meeting time
 * @param enable YES means show meeting time otherwise is hidden
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableToShowMeetingTime:(BOOL)enable;

/**
 * @brief Determines if can copy invite url after start meeting.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableCopyInviteURL;

/**
 * @brief To set meeting invite url can copy.
 * @param enable YES if can copy, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCopyMeetingInviteURL:(BOOL)enable;
/**
 * @brief Determines if can comfire when leaving meeting.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableConfirmLeavingMeeting;

/**
 * @brief To set confirm when user leaving meeting.
 * @param enable Yes means will confirm when user leaving meeting.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setConfirmLeavingMeeting:(BOOL)enable;

/**
 * @brief To set the appearance of ui.
 * @param appearance The enum of appearance.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setUIAppearance:(ZoomSDKUIAppearance)appearance;

/**
 * @brief Gets the UI appearance type.
 * @return The UI appearance type.
 */
- (ZoomSDKUIAppearance)getUIAppearance;

/**
 * @brief Determines if support set ui theme.
 * @return If support, it returns YES. Otherwise, NO.
 */
- (BOOL)isSupportSetUITheme;

/**
 * @brief Sets the theme of ui.
 * @param theme The enum of theme.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setUITheme:(ZoomSDKUITheme)theme;

/**
 * @brief Query the theme of ui.
 * @return The theme of ui.
 */
- (ZoomSDKUITheme)getUITheme;

/**
 * @brief Stops my video and audio when my display is off or screen saver begins.
 * @param enable YES is means mute video and aodio when lock screen,otherewise not, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setMuteVideoAndAudioWhenLockScreen:(BOOL)enable;

/**
 * @brief Determines if mute video and aodio when lock screen.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isMutedVideoAndAudioWhenLockScreen;

/**
 * @brief Sets the reaction's skintone.
 * @param skinTone The enum of skintone.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setReactionSkinTone:(ZoomSDKEmojiReactionSkinTone)skinTone;

/**
 * @brief Gets the reaction's skintone.
 * @return The current's value reaction skintone.
 */
- (ZoomSDKEmojiReactionSkinTone)getReactionSkinTone;

/**
 * @brief Hides checkbox of automatically copy invite link when meeting start.
 * @param hide YES to hide the checkbox, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hideAutoCopyInviteLinkCheckBox:(BOOL)hide;
/**
 * @brief Mute attendees when they join the meeting.
 * @param bEnable YES if attendees join the meeting is muted, NO otherwise.
 * @param allow YES if attendee can unmute self, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableMuteOnEntry:(BOOL)bEnable allowUnmuteBySelf:(BOOL)allow;
/**
 * @brief Gets the object of set wallpaper controller.
 * @return If the function succeeds, it returns a ZoomSDKWallpaperController object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKWallpaperController*)getWallpaperController;
@end


NS_ASSUME_NONNULL_END
