/**
 * @file ZoomSDKPremeetingService.h
 * @brief Interfaces for Zoom SDK direct sharing and premeeting service.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKDirectShareHandler
 * @brief Handle input meeting number or sharing key for direct share.
 */
@interface ZoomSDKDirectShareHandler: NSObject
/**
 * @brief Input meeting number to share the screen directly. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)inputMeetingNumber:(NSString*)meetingNumber;
/**
 * @brief Input pairing code in ZOOM Rooms to share the screen directly. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)inputSharingKey:(NSString*)shareKey;
/**
 * @brief Designated to cancel input action.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @class ZoomSDKDirectShareSpecifyContentHandler
 * @brief Handle specify content sharing in direct share for custom ui.
 */
@interface ZoomSDKDirectShareSpecifyContentHandler: NSObject

/**
 * @brief Designated to get the supported direct share types.
 * @return If the function succeeds, it returns an array contains NSNumber with ZoomSDKShareContentType. Otherwise, this function fails and returns nil.
 */
- (NSArray<NSNumber *>*)getSupportedDirectShareType;

/**
 * @brief Designated to direct share application.
 * @param windowID The Application's window ID to be shared.
 * @param shareSound Enable or disable share computer sound.
 * @param optimizeVideoClip Enable or disable optimizing for full screen video clip.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)tryShareApplication:(CGWindowID)windowID shareSound:(BOOL)shareSound optimizeVideoClip:(BOOL)optimizeVideoClip;

/**
 * @brief Designated to direct share desktop.
 * @param monitorID The monitor's ID that to be shared.
 * @param shareSound Enable or disable share computer sound.
 * @param optimizeVideoClip Enable or disable optimizing for full screen video clip.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)tryShareDesktop:(CGDirectDisplayID)monitorID shareSound:(BOOL)shareSound optimizeVideoClip:(BOOL)optimizeVideoClip;

/**
 * @brief Designated to direct share frame.
 * @param shareSound Enable or disable share computer sound.
 * @param optimizeVideoClip Enable or disable optimizing for full screen video clip.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)tryShareFrame:(BOOL)shareSound optimizeVideoClip:(BOOL)optimizeVideoClip;

/**
 * @brief Designated to cancel the action.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @protocol ZoomSDKDirectShareHelperDelegate
 * @brief Delegate protocol for direct share status and content specify notifications.
 */
@protocol ZoomSDKDirectShareHelperDelegate <NSObject>
/**
 * @brief Notification if the status of direct sharing changes. 
 * @param status The status of direct sharing.
 * @param handler The handler works only when the value of status is DirectShareStatus_NeedMeetingIDOrSharingKey, DirectShareStatus_WrongMeetingIDOrSharingKey or DirectShareStatus_NeedInputNewPairingCode
 */
- (void)onDirectShareStatusReceived:(DirectShareStatus)status DirectShareReceived:(ZoomSDKDirectShareHandler*_Nullable)handler;

/**
 * @brief Notification share specify share content.
 * @param handler The handler works only when the value of status is DirectShareStatus_Prepared.
 */
- (void)onDirectShareSpecifyContent:(ZoomSDKDirectShareSpecifyContentHandler*)handler;
@end


/**
 * @class ZoomSDKDirectShareHelper
 * @brief Helper class to manage direct share via ultrasonic proximity signal.
 */
@interface ZoomSDKDirectShareHelper: NSObject
{
    id<ZoomSDKDirectShareHelperDelegate> _delegate;
}
/**
 * @brief The delegate to receive direct share events.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKDirectShareHelperDelegate> delegate;
/**
 * @brief Query if user can auto-share directly by using ultrasonic proximity signal.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)canDirectShare;
/**
 * @brief Starts direct sharing by using ultrasonic proximity signal. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)startDirectShare;
/**
 * @brief Stops direct sharing by using ultrasonic proximity signal. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)stopDirectShare;
@end



/**
 * @class ZoomSDKPremeetingService
 * @brief Service class for pre-meeting settings and direct share helper.
 */
@interface ZoomSDKPremeetingService : NSObject
{
    ZoomSDKDirectShareHelper* _directShareHelper;
}

/**
 * @brief Turn on the video of participant when he joins the meeting. 
 * @param enable YES if enabled, NO otherwise.
 */
- (void)enableForceAutoStartMyVideoWhenJoinMeeting:(BOOL)enable;

/**
 * @brief Turn off the video of participant when he joins the meeting.
 * @param enable YES if enabled, NO otherwise.
 */
- (void)enableForceAutoStopMyVideoWhenJoinMeeting:(BOOL)enable;

/**
 * @brief Sets the dialog's visibility SELECT JOIN AUDIO when joining meeting. Default: enabled.
 * @param disable YES if disabled, NO otherwise.
 */
- (void)disableAutoShowSelectJoinAudioDlgWhenJoinMeeting:(BOOL)disable;

/**
 * @brief Query if the current user is forced to enable video when joining the meeting.
 * @return YES to force the current user to enable video. Otherwise, NO. 
 */
- (BOOL)isUserForceStartMyVideoWhenInMeeting;

/**
 * @brief Query if the current user is forced to turn off video when joining the meeting.
 * @return YES if the current user's video is forced to stop. Otherwise, NO. 
 */
- (BOOL)isUserForceStopMyVideoWhenInMeeting;

/**
 * @brief Query if the feature that hide the dialog of joining meeting with audio in the meeting is enabled.
 * @return YES if hiding the dialog. Otherwise, NO.
 */
- (BOOL)isUserForceDisableShowJoinAudioDlgWhenInMeeting;

/**
 * @brief Gets the helper to share directly.
 * @return If the function succeeds, it returns a ZoomSDKDirectShareHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKDirectShareHelper*)getDirectShareHelper;
@end
NS_ASSUME_NONNULL_END
