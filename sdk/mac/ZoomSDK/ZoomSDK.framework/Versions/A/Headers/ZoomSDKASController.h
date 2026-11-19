/**
 * @file ZoomSDKASController.h
 * @brief Interface for managing share and Zoom UI annotation functionalities.
 */

#import <ZoomSDK/ZoomSDKErrors.h>
#import <ZoomSDK/ZoomSDKCustomizedAnnotationCtr.h>
#import <ZoomSDK/ZoomSDKShareContainer.h>
#import <ZoomSDK/ZoomSDKRemoteControllerHelper.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Video sharing quality options.
 */
typedef NS_ENUM(NSUInteger, ZoomSDKVideoSharingQuality) {
    /** Not set or invalid value. */
    ZoomSDKVideoSharingQuality_None,
    /** 720p at 30fps quality option. */
    ZoomSDKVideoSharingQuality_720p_30fps,
    /** 720p at 60fps quality option. */
    ZoomSDKVideoSharingQuality_720p_60fps,
    /** 1080p at 30fps quality option. */
    ZoomSDKVideoSharingQuality_1080p_30fps,
    /** 1080p at 60fps quality option. */
    ZoomSDKVideoSharingQuality_1080p_60fps,
};

/**
 * @class ZoomSDKAnnotationController
 * @brief Controls Zoom UI annotation features in Zoom meetings, including setting tools, clearing annotations, and managing annotation states.
 * For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0067931>.
 */
@interface ZoomSDKAnnotationController :NSObject

/**
 * @brief Determines if annotation disabled.
 * @return YES if annotation is disabled. Otherwise, NO.
 */
- (BOOL)isAnnotationDisable;

/**
 * @brief Sets annotation tool type.
 * @param type The specify annotation tool type.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @warning The tool type AnnotationToolType_Picker and AnnotationToolType_SpotLight are not support for viewer.
 */
- (ZoomSDKError)setTool:(AnnotationToolType)type onScreen:(ScreenType)screen;

/**
 * @brief Clears the annotation of share screen.
 * @param type Specify the type of clear annotation.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)clear:(AnnotationClearType)type onScreen:(ScreenType)screen;

/**
 * @brief Sets annotation color.
 * @param red Red color component, range is 0 to 255.
 * @param green Green color component, range is 0 to 255.
 * @param blue Blue color component, range is 0 to 255.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setColor:(float)red green:(float)green blue:(float)blue onScreen:(ScreenType)screen;

/**
 * @brief Sets the line's width for the annotation.
 * @param lineWidth The line width.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setLineWidth:(long)lineWidth onScreen:(ScreenType)screen;

/**
 * @brief Undo annotation.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)undo:(ScreenType)screen;

/**
 * @brief Redo annotation.
 * @param screen Select the screen where you want to operate on.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)redo:(ScreenType)screen;

/**
 * @brief Determines whether the legal notice for annotation is available.
 * @return YES if the legal notice for annotation transcript is available. Otherwise, NO.
 */
- (BOOL)isAnnotationLegalNoticeAvailable;

/**
 * @brief Gets the annotation legal notices prompt.
 * @return If the function succeeds, it returns the annotation legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getAnnotationLegalNoticesPrompt;

/**
 * @brief Gets the annotation legal notices explained.
 * @return If the function succeeds, it returns the annotation legal notices explained. Otherwise, this function fails and returns nil.
 */
- (NSString *)getAnnotationLegalNoticesExplained;
@end


/**
 * @class ZoomSDKSharingSourceInfo
 * @brief Represents information about a sharing source.
 */
@interface ZoomSDKSharingSourceInfo: NSObject
/**
 * @brief Unique ID of the sharing source.
 */
@property(nonatomic, assign, readonly) unsigned int              shareSourceID;
/**
 * @brief User ID of the sharer.
 */
@property(nonatomic, assign, readonly) unsigned int              userID;
/**
 * @brief Content type of the shared source.
 * @note In early share status callbacks，for example, ZoomSDKShareStatus_SelfBegin or ZoomSDKShareStatus_OtherBegin,
 *       this value can be ZoomSDKShareContentType_UNKNOWN temporarily. The finalized content type is available after
 *       -onShareContentChanged: is received.
 */
@property(nonatomic, assign, readonly) ZoomSDKShareContentType   contentType;
/**
 * @brief Current status of the sharing.
 */
@property(nonatomic, assign, readonly) ZoomSDKShareStatus        status;
/**
 * @brief Window ID of the shared application.
 */
@property(nonatomic, assign, readonly) CGWindowID                windowID;
/**
 * @brief Display ID of the shared desktop.
 */
@property(nonatomic, assign, readonly) CGDirectDisplayID         displayID;
/**
 * @brief Indicates if the content is shown on the first screen (Zoom UI mode only).
 */
@property(nonatomic, assign, readonly) BOOL                      isShowInFirstScreen;
/**
 * @brief Indicates if the content is shown on the second screen (Zoom UI mode only).
 */
@property(nonatomic, assign, readonly) BOOL                      isShowInSecondScreen;
/**
 * @brief Indicates whether the shared content can be remote controlled.
 */
@property(nonatomic, assign, readonly) BOOL                      canBeRemoteControl;
/**
 * @brief Determines if optimizing video sharing is enabled.
 */
@property(nonatomic, assign, readonly) BOOL                      bEnableOptimizingVideoSharing;

/**
 * @brief Gets the window ID of the shared APP.
 * @param windowID A pointer to CGWindowID.
 */
- (ZoomSDKError)getWindowID:(CGWindowID*)windowID;

/**
* @brief Gets the display ID on which that user wants to share the content.
* @param displayID A pointer of CGDirectDisplayID.
*/
- (ZoomSDKError)getDisplayID:(CGDirectDisplayID*)displayID;
@end


/**
 * @class ZoomSDKSplitScreenInfo
 * @brief Provides information about Zoom SDK split screen mode support and status.
 */
@interface ZoomSDKSplitScreenInfo : NSObject
{
    BOOL _isInSplitScreenMode;
    BOOL _isSupportSplitScreenMode;
}
/**
 * @brief Determines whether the current mode is split screen.
 * @return YES if in split screen mode. Otherwise, NO.
 */
- (BOOL)isInSplitScreenMode;

/**
 * @brief Determines whether split screen mode is supported.
 * @return YES if split screen mode is supported. Otherwise, NO.
 */
- (BOOL)isSupportSplitScreenMode;
@end

/**
 * @protocol ZoomSDKASControllerDelegate
 * @brief Delegate protocol for annotation and sharing events.
 */
@protocol ZoomSDKASControllerDelegate <NSObject>
@optional
/**
 * @brief Notification of the sharing status in the meeting.
 * @param shareInfo The object of ZoomSDKSharingSourceInfo.
 * @note When status is ZoomSDKShareStatus_SelfBegin or ZoomSDKShareStatus_OtherBegin, shareInfo.contentType can be
 *       ZoomSDKShareContentType_UNKNOWN temporarily. Do not treat UNKNOWN at this stage as the finalized share
 *       content type. Wait for -onShareContentChanged: to get the finalized content type.
 */
- (void)onSharingStatusChanged:(ZoomSDKSharingSourceInfo*)shareInfo;

/**
 * @brief Notification of failure to start sharing.
 */
- (void)onFailedToStartShare;

/**
 * @brief Notification of shared content is changed.
 * @param shareInfo The shared content, including window ID and monitor ID.
 */
- (void)onShareContentChanged:(ZoomSDKSharingSourceInfo*)shareInfo;

/**
 * @brief Designated for Zoom Meeting notify the sharing user has changed the viewer's annotation privilage.
 * @param isSupportAnnotation YES indicates the share source user enable the viewer do annotations, NO otherwise.
 * @param shareSourceID The share source ID that is sharing.
 */
- (void)onAnnotationSupportPropertyChanged:(BOOL)isSupportAnnotation shareSourceID:(unsigned int)shareSourceID;

/**
 * @brief Designated for Zoom Meeting notify the share Settings type changes.
 * @param type The share setting type.
 */
- (void)onShareSettingTypeChanged:(ZoomSDKShareSettingType)type;

/**
 * @brief The shared video’s playback has completed.
 */
- (void)onSharedVideoEnded;

/**
 * @brief Designated for the video file playback error.
 * @param error The error type.
 */
- (void)onVideoFileSharePlayError:(ZoomSDKVideoFileSharePlayError)error;

/**
 * @brief Designated for the optimize video property have changed.
 * @param shareInfo The share source information that has changed.
 */
- (void)onOptimizingShareForVideoClipStatusChanged:(ZoomSDKSharingSourceInfo*)shareInfo;

/**
 * @brief Notification when the video sharing quality has changed.
 * @param quality The new quality in effect.
 */
- (void)onVideoSharingQualityChanged:(ZoomSDKVideoSharingQuality)quality;
@end



/**
 * @class ZoomSDKASController
 * @brief The Zoom share controller responsible for managing screen sharing, annotation, and remote control functionalities.
 */
@interface ZoomSDKASController : NSObject
{
    id<ZoomSDKASControllerDelegate> _delegate;
    ZoomSDKShareContainer* _shareContainer;
    ZoomSDKAnnotationController* _annotationController;
    ZoomSDKCustomizedAnnotationCtr* _customizedAnnotationCtr;
    ZoomSDKRemoteControllerHelper*  _remoteControllerHelper;
}
/**
 * @brief The delegate to receive sharing and annotation event callbacks.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKASControllerDelegate> delegate;
/**
 * @brief Enables or disable the shared computer sound, Applied when starting the share session.
*/
@property(nonatomic, assign, readwrite) BOOL enableShareComputerSound;
/**
 * @brief Enables or disable optimizing screen sharinge for a video clip, Applied when starting the share session.
*/
@property(nonatomic, assign, readwrite) BOOL enableOptimizingScreenShareForVideoClip;

/**
 * @brief Starts to share application. 
 * @param windowID The App window ID to be shared.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startAppShare:(CGWindowID)windowID;

/**
 * @brief Determines if the application's window ID can be shared.
 * @return YES if the current application window can be shared. Otherwise means the app's window handle can't be shared.
 */
- (BOOL)isShareAppValid:(CGWindowID)windowID;

/**
 * @brief Starts to share desktop.
 * @param monitorID The monitor's ID that you want to display the shared content.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startMonitorShare:(CGDirectDisplayID)monitorID;

/**
 * @brief Stops the current share.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopShare;

/**
 * @brief Gets the ID of users who are sharing. 
 * @return If the function succeeds, it returns an NSArray of user ID of all users who are sharing. Otherwise, this function fails and returns nil.
 */
- (NSArray<NSNumber *>* _Nullable)getViewableSharingUserList;

/**
 * @brief Gets the list of sharing source info.
 * @param userID The user's ID who is sharing.
 * @return If the function succeeds, it returns a pointer to the NSArray<ZoomSDKSharingSourceInfo*>. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKSharingSourceInfo *>* _Nullable)getSharingSourceInfoList:(unsigned int)userID;

/**
 * @brief Determines whether the current meeting can start sharing.
 * @param reason The reason that no one can start sharing.
 * @return YES if you can start sharing. Otherwise, NO.
 */
- (BOOL)canStartShare:(ZoomSDKCannotShareReasonType*)reason;


/**
 * @brief Determines if it is able to share desktop in the current meeting.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isDesktopSharingEnabled;

/**
 * @brief Gets the controller of annotation tools.
 * @return If the function succeeds, it returns the object of ZoomSDKAnnotationController. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAnnotationController*_Nullable)getAnnotationController;

/**
 * @brief Gets the controller of annotation tools used in user custom interface mode.
 * @return If the function succeeds, it returns the object of ZoomSDKCustomizedAnnotationCtr. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKCustomizedAnnotationCtr*_Nullable)getCustomizedAnnotationCtr;

/**
 * @brief Gets custom share container. 
 * @return If the function succeeds, it returns the object of ZoomSDKShareContainer. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKShareContainer*_Nullable)getShareContainer;

/**
 * @brief Gets the class object of ZoomSDKRemoteControllerHelper.
 * @return If the function succeeds, it returns the object of ZoomSDKRemoteControllerHelper. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKRemoteControllerHelper*_Nullable)getRemoteControllerHelper;

/**
 * @brief Starts annotation.
 * @param screen Specify the view where you want to place the annotation toolbar.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startAnnotation:(ScreenType)screen;

/**
 * @brief Stops annotation.
 * @param screen Specify the view on which you want to stop annotating.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopAnnotation:(ScreenType)screen;

/**
 * @brief Gets the information of split screen when viewing the share in the meeting.
 * @return If the function succeeds, it returns a pointer to a ZoomSDKSplitScreenInfo object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSplitScreenInfo*_Nullable)getCurrentSplitScreenModeInfo;

/**
 * @brief Switch to split screen mode, which means that the shared content and the video are separated in different column, the video won't cover the shared content.
 * @param switchTo YES to enable side by side mode, NO otherwise.
 * @return If the function succeeds, it returns @c ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchSplitScreenMode:(BOOL)switchTo;

/**
 * @brief Clean up as-controller object.
 */
- (void)cleanUp;

/**
 * @brief Share white-board.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startWhiteBoardShare;

/**
 * @brief Starts sharing a portion of screen by a frame. User can resize the shared range during sharing.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startFrameShare;

/**
 * @brief Share audio.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startAudioShare;

/**
 * @brief Share camera, only available for custom UI.
 * @param deviceID The camera's ID to be shared.
 * @param window The view on which you want to show camera content.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startShareCamera:(NSString*)deviceID displayWindow:(NSWindow*)window;

/**
 * @brief Share camera, only available for zoom UI.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startShareCamera;

/**
 * @brief Determines if the user can share the next camera.
 * @return YES if can. Otherwise, NO.
 */
- (BOOL)canSwitchToShareNextCamera;
/**
 * @brief Share the next camera.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchToShareNextCamera;

/**
 * @brief Share video file.
 * @param filePath Specify the video file path. Only supports mov, mp4, or avi format.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startVideoFileShare:(NSString*)filePath;

/**
 * @brief Share video file. Only available for custom UI.
 * @param filePath Specify the video file path. Only supports mov, mp4, or avi format.
 * @param window The view where you want to show share content.
 * @return If the function succeeds, it returns ZoomSDKError_Succuss. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startVideoFileShare:(NSString*)filePath displayWindow:(NSWindow*)window;

/**
 * @brief Determines if user can share white-board.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isAbleToShareWhiteBoard;
/**
 * @brief Determines if user can share a potion of screen.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isAbleToShareFrame;
/**
 * @brief Determines if user can share computer audio.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isAbleToShareComputerAudio;
/**
 * @brief Determines if user can share camera.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isAbleToShareCamera;

/**
 * @brief Determines if users can share video files.
 * @return YES if can. Otherwise, NO.
 */
- (BOOL)canShareVideoFile;

/**
 * @brief Determines whether the user can share to the breakout room.
 * @return YES if the user can share to the breakout room. Otherwise, NO.
 * @note Valid for user custom interface mode only.
 */
- (BOOL)canEnableShareToBO;

/**
 * @brief Determines if sharing to the breakout room is enabled.
 * @return YES if sharing is locked. Otherwise, NO.
 * @note Valid for user custom interface mode only.
 */
- (BOOL)isShareToBOEnabled;

/**
 * @brief Sets to enable sharing to the breakout room
 * @param bEnable YES indicates to enable, NO indicates that sharing to the breakout room is not enabled.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Valid for user custom interface mode only.
 */
- (ZoomSDKError)enableShareToBO:(BOOL)bEnable;

/**
 * @brief This method uses for the sharing user to disable or enable viewer's privilege of annotation.
 * @param screenType Select the screen where you want to operate on.
 * @param disable YES indicates disable viewer's annotation privilege, NO indicates enable.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)disableViewerAnnotation:(ScreenType)screenType disable:(BOOL)disable;

/**
 * @brief Determines whether the viewer's annotate privilege is locked.
 * @param screenType Select the screen where you want to operate on.
 * @param locked A point to A BOOL, if function call successfully, the value of 'locked' means whether viewer's annotate privilege is locked, YES indicates viewer's annotate privilege is locked, NO otherwise.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)isViewerAnnotationLocked:(ScreenType)screenType isLocked:(BOOL*)locked;

/**
 * @brief Determines if it is able for user to disable viewer's annotation privilege.
 * @param screenType Select the screen where you want to operate on.
 * @param canDisable A point to A BOOL, if function call successfully, the value of 'canDisable' means whether the user can disable viewer's annotation, YES indicates can disable, NO indicates cannot.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canDisableViewerAnnotation:(ScreenType)screenType canDisabled:(BOOL*)canDisable;

/**
 * @brief Determines if it is able for user to do annotation.
 * @param screenType Select the screen where you want to operate on.
 * @param canAnnotate A point to A BOOL, if function call successfully, the value of 'canAnnotate' means whether the user can do annotation, YES indicates can do annotation, NO indicates cannot.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canDoAnnotation:(ScreenType)screenType canAnnotate:(BOOL*)canAnnotate;

/**
 * @brief Determines if support enable or disable optimizing for full screen video clip.
 * @return If supported, this returns YES. Otherwise returns NO.
 */
- (BOOL)isSupportEnableOptimizeForFullScreenVideoClip;

/**
 * @brief Determines if sharing computer sound option is on or off for the current sharing session.
 * @return If enabled, this returns YES. Otherwise returns NO.
 */
- (BOOL)isEnableShareComputerSoundOnWhenSharing;

/**
 * @brief Determines if optimizing for full screen video clip option is on or off for the current sharing session.
 * @return If enabled, this returns YES. Otherwise returns NO.
 */
- (BOOL)isEnableOptimizeForFullScreenVideoClipOnWhenSharing;

/**
 * @brief Determines if the specified share type supports sharing with computer sound.
 * @param type The type of shring content.
 * @return If supported, this return YES. Otherwise return NO.
 */
- (BOOL)isSupportShareWithComputerSound:(ZoomSDKShareContentType)type;

/**
 * @brief Determines if current share support sharing with computer sound.
 * @return If supported, this return YES. Otherwise return NO.
 */
- (BOOL)isCurrentSharingSupportShareWithComputerSound;

/**
 * @brief Determines enable share computer sound.
 * @param enable Enable or disable share computer sound.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableShareComputerSound:(BOOL)enable;

/**
 * @brief Determines enable optimizing for full screen video clip.
 * @param enable Enable or disable optimizing for full screen video clip.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableOptimizingScreenShareForVideoClip:(BOOL)enable;

/**
 * @brief Sets the audio share mode.
 * @param mode The mode for audio share.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setAudioShareMode:(ZoomSDKAudioShareMode)mode;

/**
 * @brief Gets the audio share mode.
 * @param mode The mode for audio share.
 * @return If the function succeeds, it returns ZoomSDKError_Success, the param mode will be the current audio share mode. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getAudioShareMode:(ZoomSDKAudioShareMode*)mode;

/**
 * @brief Determines enable share computer sound when shaing.
 * @param enable Enable or disable share computer sound.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableShareComputerSoundWhenSharing:(BOOL)enable;

/**
 * @brief Determines enable optimizing for full screen video clip when shaing.
 * @param enable Enable or disable optimizing for full screen video clip.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableOptimizingScreenShareForVideoClipWhenSharing:(BOOL)enable;

/**
 * @brief Determines whether the legal notice for whiteboard is available.
 * @return YES if the legal notice for whiteboard is available. Otherwise, NO.
 */
- (BOOL)isWhiteboardLegalNoticeAvailable;

/**
 * @brief Gets the whiteboard legal notices prompt.
 * @return If the function succeeds, it returns the whiteboard legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getWhiteboardLegalNoticesPrompt;

/**
 * @brief Gets the whiteboard legal notices explained.
 * @return If the function succeeds, it returns the whiteboard legal notices explained. Otherwise, this function fails and returns nil.
 */
- (NSString *)getWhiteboardLegalNoticesExplained;

/**
 * @brief Switch the window size by the function when watching the share on the specified view.
 * @param shareSourceID Specify the sharing source ID that you want to switch the zoom ratio.
 * @param zoomRatio Specify the size you want to set. The default is ZoomSDKShareViewZoomRatio_50, which means share content will zoom-out to 50%.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchZoomRatioWhenViewShare:(unsigned int)shareSourceID zoomRatio:(ZoomSDKShareViewZoomRatio)zoomRatio;

/**
 * @brief Enables following the presenter's pointer by the function when watching the shared content on the specified view.
 * @param shareSourceID Specify the sharing source ID that you want to follow the presenter's pointer.
 * @param enable YES indicates to enable following the pointer, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableFollowPresenterPointerWhenViewShare:(unsigned int)shareSourceID enable:(BOOL)enable;

/**
 * @brief Determines if you can enable following the presenter's pointer when watching the share on the specified view.
 * @param shareSourceID Specify the sharing source ID that you want to follow the presenter's pointer.
 * @param bCan YES indicates that following the pointer can be enabled, NO indicates that it can't.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
*/
- (ZoomSDKError)canEnableFollowPresenterPointerWhenViewShare:(unsigned int)shareSourceID bCan:(BOOL*)bCan;

/**
 * @brief Checks if the specified quality can be set for the given share type.
 * @param quality The quality to check. Cannot be ZoomSDKVideoSharingQuality_None.
 * @param shareType The type of sharing content.
 * @return YES if supported, otherwise NO.
 * @note Returns NO unless either enableOptimizingScreenShareForVideoClip is YES,
 *       or optimize-for-video-sharing is currently on during an active share.
 */
- (BOOL)canSetVideoSharingQuality:(ZoomSDKVideoSharingQuality)quality
                     forShareType:(ZoomSDKShareContentType)shareType;

/**
 * @brief Sets the video sharing quality.
 * @param quality The quality to set. Cannot be ZoomSDKVideoSharingQuality_None.
 * @return ZoomSDKError_Success on success, otherwise an error code.
 * @note Can be called before or during sharing. The actual quality may be downgraded.
 * @note Returns ZoomSDKError_WrongUsage unless either
 *       enableOptimizingScreenShareForVideoClip is YES, or optimize-for-video-sharing
 *       is currently on during an active share.
 */
- (ZoomSDKError)setVideoSharingQuality:(ZoomSDKVideoSharingQuality)quality;

/**
 * @brief Gets the current video sharing quality.
 * @return The current quality, or ZoomSDKVideoSharingQuality_None if not set or if
 *         both enableOptimizingScreenShareForVideoClip is NO and optimize-for-video-sharing
 *         is not currently on during an active share.
 */
- (ZoomSDKVideoSharingQuality)getVideoSharingQuality;

@end
NS_ASSUME_NONNULL_END
