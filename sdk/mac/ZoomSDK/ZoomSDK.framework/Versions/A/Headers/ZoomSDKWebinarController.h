/**
 * @file ZoomSDKWebinarController.h
 * @brief Interfaces for managing webinar features in Zoom SDK.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKWebinarMeetingStatus
 * @brief Status information of the current webinar.
 */
@interface ZoomSDKWebinarMeetingStatus : NSObject
{
    BOOL _allowPanellistStartVideo;
    BOOL _allowAttendeeChat;
    BOOL _allowRaiseHand;
}
/**
 * @brief Query if panelist is allowed to start video.
 * @return YES if panelist is allowed to enable video. Otherwise, NO.
 */
- (BOOL)isAllowPanellistStartVideo;
/**
 * @brief Query if attendee is allowed to chat.
 * @return YES if attendee is allowed to chat. Otherwise, NO.
 */
- (BOOL)isAllowAttendeeChat;
/**
 * @brief Query if attendee raise hand status.
 * @return If it is enabled, it returns YES. Otherwise, NO.
 */
- (BOOL)isAllowRaiseHand;

/**
 * @brief Determines if current webinar supports emoji reactions.
 * @return YES if the current webinar supports emoji reactions. Otherwise, NO.
 */
- (BOOL)isWebinarEmojiReactionSupported;
/**
 * @brief Query if emoji reactions status.
 * @return If it is enabled, it returns YES. Otherwise, NO.
 */
- (BOOL)isWebinarEmojiReactionAllowed;

/**
 * @brief Query if attendee to view the participant count status.
 * @return If this is enabled, it returns YES. Otherwise NO.
 */
- (BOOL)canAttendeesViewParticipantCount;
@end


/**
 * @class ZoomSDKWebinarRegisterHelper
 * @brief Helper class for webinar registration.
 */
@interface ZoomSDKWebinarRegisterHelper :NSObject
{
    WebinarRegisterType   _webinarRegisterType;
}
/**
 * @brief Gets type of user registers webinar.
 * @return The type of user to register webinar.
 */
- (WebinarRegisterType)getWebinarRegisterType;
/**
 * @brief Gets URL of user registers webinar.
 * @return If the function succeeds, it returns the url for user to register webinar. Otherwise, this function fails and returns nil.	
 */
- (NSURL*_Nullable)getWebinarRegisterURL;
/**
 * @brief Input email and screen name to register webinar. 
 * @param email The email to register webinar
 * @param name The display name to register webinar.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inputEmail:(NSString*)email screenName:(NSString*)name;
/**
 * @brief Cancels to register webinar.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @class ZoomSDKWebinarInputScreenNameHandler
 * @brief Handler for entering screen name when joining a webinar.
 */
@interface ZoomSDKWebinarInputScreenNameHandler :NSObject
/**
 * @brief Input screen name to join the webinar.
 * @param name The display name for the webinar.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inputName:(NSString*)name;
/**
 * @brief Cancels to join webinar.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @protocol ZoomSDKWebinarControllerDelegate
 * @brief Protocol for receiving webinar events and callbacks.
 */
@protocol ZoomSDKWebinarControllerDelegate <NSObject>
@optional
/**
 * @brief Callback of users are allowed to talk in webinar. User needs to enable the mic in the view-only mode of webinar if he wants to talk.
 */
- (void)onSelfAllowTalkNoti;
/**
 * @brief Callback of users are disallowed to talk in webinar. 
 */
- (void)onSelfDisallowTalkNoti;
/**
 * @brief Callback to promote attendee to panelist.
 * @param result The result of promotion. If the promotion is successful, the result is zero(0), otherwise it is an error code.
 */
- (void)onPromoteAttendee2PanelistResultNoti:(unsigned int)result;
/**
 * @brief Callback to demote panelist to attendee.
 * @param result The result of demotion. If the promotion is successful, the result is zero(0), otherwise it is an error code.
 */
- (void)onDepromotePanelist2AttendeeResultNoti:(unsigned int)result;
/**
 * @brief Callback to enable the panelist to start the video.
 */
- (void)onAllowPanelistStartVideoNoti;
/**
 * @brief Callback to disable the panelist to start the video.
 */
- (void)onDisAllowPanelistStartVideoNoti;
/**
 * @brief Panelist receives this callback if the attendee's audio status changed. 
 * @param userid The user ID of attendee whose audio status changes.
 * @param is_muted YES if the user is muted, NO otherwise.
 */
- (void)onAttendeeAudioStatusNoti:(unsigned int)userid canTalk:(BOOL)can_talk isMuted:(BOOL)is_muted;
/**
 * @brief During the webinar, this callback triggers if the user needs to register.
 * @param webinarRegisterHelper An object used by user to complete all the related operations.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)onWebinarNeedRegisterResponse:(ZoomSDKWebinarRegisterHelper*_Nullable)webinarRegisterHelper;
/**
 * @brief Panelist receives this callback if the attendee's audio status changed.
 * @param userid The user ID of attendee whose promote.
 * @param agree YES if the user agrees to join webinar as panelist, NO otherwise.
 */
- (void)onAttendeePromoteConfirmResult:(unsigned int)userid isAgree:(BOOL)agree;

/**
 * @brief Callback for when the host enables or disables emoji reactions.
 * @param isAllowed If the reaction is allowed, the value of isAllow is YES, NO otherwise.
 */
- (void)onAllowWebinarReactionStatusChanged:(BOOL)isAllowed;

/**
 * @brief Callback to attendee raise hand status changed.
 * @param isAllowed If the raise hand is allowed, the result is YES. If not, the result is NO.
 */
- (void)onAllowAttendeeRaiseHandStatusChanged:(BOOL)isAllowed;

/**
 * @brief Callback to attendee view the participant count status changed.
 * @param isAllowed If attendees are allowed to view the participant count, the result is YES. Otherwise, NO.
 */
- (void)onAllowAttendeeViewTheParticipantCountStatusChanged:(BOOL)isAllowed;

/**
 * @brief When join the webinar, this callback is triggered if the user needs to input username.
 * @param handler An object used by user to complete all the related operations.
 */
- (void)onWebinarNeedInputScreenName:(ZoomSDKWebinarInputScreenNameHandler*_Nullable)handler;
@end


/**
 * @class ZoomSDKWebinarController
 * @brief Controller for managing webinar-specific functions.
 */
@interface ZoomSDKWebinarController : NSObject
{
    id<ZoomSDKWebinarControllerDelegate> _delegate;
    ZoomSDKWebinarMeetingStatus* _webinarMeetingStatus;
}

/**
 * @brief Sets the webinar controller delegate.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKWebinarControllerDelegate> delegate;
/**
 * @brief Gets the webinar meeting status.
 */
@property(nonatomic, retain)ZoomSDKWebinarMeetingStatus* webinarMeetingStatus;

/**
 * @brief Promote the specified attendee to panelist.
 * @param userId The specified's ID attendee.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)PromoteAttendee2Panelist:(unsigned int)userId;

/**
 * @brief Demote the specified panelist to attendee.
 * @param userId The specified's ID panelist. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)DepromotePanelist2Attendee:(unsigned int)userId;

/**
 * @brief The attendee is permitted to use the audio device.
 * @param userId Specify the permitted user ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)AllowAttendeeTalk:(unsigned int)userId;

/**
 * @brief Forbid the attendee to use the audio device.
 * @param userId Specify the forbidden user ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)DisallowAttendeeTalk:(unsigned int)userId;

/**
 * @brief The panelist is permitted to start the video.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)AllowPanelistStartVideo;

/**
 * @brief Forbid the panelist to start video.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)DisallowPanelistStartVideo;

/**
 * @brief Gets the webinar status.
 * @return If the function succeeds, it returns an object of ZoomSDKWebinarMeetingStatus. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKWebinarMeetingStatus*_Nullable)getZoomSDKWebinarMeetingStatus;

/**
 * @brief Gets the list of attendees in the meeting.
 * @return If the function succeeds, it returns an NSArray of attendees. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAttendeeList;

/**
 * @brief Sets the panelist's chat privilege.
 * @param privilege The panelist's chat privilege.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setPanelistChatPrivilege:(ZoomSDKPanelistChatPrivilege)privilege;

/**
 * @brief Gets the panelist's chat privilege.
 * @param privilege The panelist's chat privilege. It validates only when it returns ZoomSDKError_Success.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getPanelistChatPrivilege:(ZoomSDKPanelistChatPrivilege*)privilege;

/**
 * @brief Sets the attendee's view mode.
 * @param mode The attendee's view mode.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setAttendeeViewMode:(ZoomSDKAttendeeViewMode)mode;

/**
 * @brief Gets the attendee's view mode.
 * @return The attendee's view mode.
 */
- (ZoomSDKAttendeeViewMode)getAttendeeViewMode;

/**
 * @brief Permitted to use emoji reactions.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowWebinarReactionStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)allowWebinarEmojiReaction;

/**
 * @brief Forbid use of emoji reactions.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowWebinarReactionStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)disallowWebinarEmojiReaction;

/**
 * @brief The attendees can raise their hands.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowAttendeeRaiseHandStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)allowAttendeeRaiseHand;

/**
 * @brief Do not let the attendee to raise their hand.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowAttendeeRaiseHandStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)disallowAttendeeRaiseHand;

/**
 * @brief The attendee is permitted to view the participant count.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowAttendeeViewTheParticipantCountStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)allowAttendeeViewTheParticipantCount;

/**
 * @brief Forbid the attendee to view the participant count.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user receives the '- (void)onAllowAttendeeViewTheParticipantCountStatusChanged:(BOOL)isAllowed' callback event. Available only for the host.
 */
- (ZoomSDKError)disallowAttendeeViewTheParticipantCount;

/**
 * @brief Gets the participant count.
 * @return The participant count of.
 */
- (int)getParticipantCount;

/**
 * @brief Gets the webinal legal notices prompt.
 * @return If the function succeeds, it returns the webinal legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getWebinarRegistrationLegalNoticesPrompt;

/**
 * @brief Gets the webinal legal notices explained.
 * @return If the function succeeds, it returns the webinal legal notices explained. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKWebinarRegistrationExplainInfo *)getWebinarRegistrationLegalNoticesExplained;

/**
 * @brief Check if the current user can start the webinar.
 * @return YES if the webinar can be started, otherwise NO.
 * @note Only returns YES when in Practice Session mode or Backstage mode. In other modes, the webinar starts automatically.
 */
- (BOOL)canStartWebinar;

/**
 * @brief Start the webinar broadcast.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note In Practice Session mode, this exits practice session and starts broadcasting. In Backstage mode, this starts broadcasting without exiting backstage.
 */
- (ZoomSDKError)startWebinar;

/**
 * @brief Check if the webinar has already started broadcasting.
 * @return YES if the webinar is broadcasting, otherwise NO.
 * @note Returns NO only when in Practice Session or Backstage mode and not yet started. Otherwise returns YES.
 */
- (BOOL)isWebinarStarted;

@end
NS_ASSUME_NONNULL_END
