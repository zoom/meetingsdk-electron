


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKShareScreenSetting
 * @brief Interface for configuring share screen settings.
 */
@interface ZoomSDKShareScreenSetting : NSObject

/**
 * @brief Determines if it is able to silence system notifications when sharing desktop.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isDoNotDisturbInSharingOn;

/**
 * @brief Enables or disable silence system notifications when sharing desktop.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableDoNotDisturbInSharing:(BOOL)enable;

/**
 * @brief Determines if it is able to show green border when sharing.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isGreenBorderOn;

/**
 * @brief Enables or disable show green border when sharing.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableGreenBorder:(BOOL)enable;

/**
 * @brief Determines if it is able to share selected app window only.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isShareSelectedWndOnlyOn;

/**
 * @brief Enables or disable share selected app window only.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableShareSelectedWndOnly:(BOOL)enable;

/**
 * @brief Determines if it is able to using tcp connection for screen sharing.
 * @return YES if disabled. Otherwise, NO.
 */
- (BOOL)isTCPConnectionOn;

/**
 * @brief Enables or disable  use tcp connection for screen sharing.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableTCPConnection:(BOOL)enable;

/**
 * @brief Sets screen capture mode.
 * @param mode The mode to be set.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setScreenCaptureMode:(ZoomSDKScreenCaptureMode)mode;

/**
 * @brief Gets screen capture mode
 * @return The current screen capture mode.
 */
- (ZoomSDKScreenCaptureMode)getScreenCaptureMode;

/**
 * @brief Enables or disable meeting settings by command.
 * @param enable YES to enable, NO otherwise.
 * @param shareCmd Is a enumeration to set different share screen.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableSetShareScreen:(BOOL)enable  SettingCmd:(shareSettingCmd)shareCmd;

/**
 * @brief Gets the setting item current status.
 * @param sharingCmd Is a enumeration.
 * @return  If return YES is enable. Otherwise, NO.
 */
- (BOOL)isEnableToSettingShare:(shareSettingCmd)sharingCmd;

/**
 * @brief Get current FPS value.
 * @return The fps value.
 */
- (int)getLimitFPSValue;

/**
 * @brief Set the value of fps limit.
 * @param value Is a number of user to set.
 */
- (ZoomSDKError)setLimitedFPSValue:(ZoomSDKFPSValue)value;
/**
 * @brief  Enables to set limited fps.
 * @return Return YES is enable. Otherwise, NO.
 */
- (BOOL)isEnableToSetLimitFPS;

/**
 * @brief Enables or disenable to set Limit fps value.
 * @param enable Yes means to set otherwise is not.
 */
- (ZoomSDKError)setEnableLimitFPS:(BOOL)enable;

/**
 * @brief Determines if support show zoom meeting window when share.
 * @return YES if support. Otherwise, NO.
 */
- (BOOL)isSupportShowZoomWindowWhenShare;
/**
 * @brief Sets enable show zoom meeting window when share.
 * @param show YES to show, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setShowZoomWindowWhenShare:(BOOL)show;

/**
 * @brief Determines if show zoom meeting window when share.
 * @return YES to show. Otherwise, NO.
 */
- (BOOL)isShowZoomWindowWhenShare;
/**
 * @brief Determines if enable share desktop.
 * @return YES to enable. Otherwise, NO.
 */
- (BOOL)isShareDesktopEnabled;
/**
 * @brief Sets the share option when share appliaction.
 * @param shareOption It is a enumeration of share option.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setShareOptionWhenShareApplication:(ZoomSDKSettingShareScreenShareOption)shareOption;
/**
 * @brief Gets the option of share application.
 * @return The value is a enumeration of share option.
 */
- (ZoomSDKSettingShareScreenShareOption)getShareOptionWhenShareApplication;
/**
 * @brief Sets the share option when share in meeting.
 * @param shareOption It is a enumeration of share option.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setShareOptionwWhenShareInMeeting:(ZoomSDKSettingShareScreenShareOption)shareOption;
/**
 * @brief Gets the option of share in meeting.
 * @return The value is a enumeration of share option.
 */
- (ZoomSDKSettingShareScreenShareOption)getShareOptionwWhenShareInMeeting;
/**
 * @brief Sets the share option when share in direct share.
 * @param shareOption It is a enumeration of share option.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setShareOptionwWhenShareInDirectShare:(ZoomSDKSettingShareScreenShareOption)shareOption;
/**
 * @brief Gets the option of share in direct share.
 * @return The value is a enumeration of share option.
 */
- (ZoomSDKSettingShareScreenShareOption)getShareOptionwWhenShareInDirectShare;

/**
 * @brief Enable or Disable the GPU acceleration when a user shares video.
 * @param bEnable YES indicates to enable the acceleration, NO indicates to not enable acceleration.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
*/
- (ZoomSDKError)enableHardwareAcceleratedVideoSharing:(BOOL)bEnable;

/**
 * @brief Determines if GPU acceleration is enabled when a user shares video.
 * @return YES if the GPU acceleration is enabled. Otherwise, NO.
 */
- (BOOL)isVideoSharingHardwareAccelerated;

/**
 * @brief Enables or disable Zoom Docs features in custom UI. This is disabled by default.
 * @param enable YES to enable the Zoom Docs feature, NO otherwise.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableZoomDocs:(BOOL)enable;

/**
 * @brief Enable or disable automatic dimming when sharing flashing content.
 * @param enable YES to enable automatic dimming, NO to disable it.
 * @return If the function is success returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note When enabled, the video automatically dimmed when the shared content contains flashing elements.
*/
-(ZoomSDKError)enableShareContentFlashDetection:(BOOL)enable;

/**
 * @brief Determines if automatic dimming of video when sharing content flashes is enabled.
 * @return YES if the feature is enabled, NO otherwise.
*/
-(BOOL)isShareContentFlashDetectionEnabled;
@end
NS_ASSUME_NONNULL_END
