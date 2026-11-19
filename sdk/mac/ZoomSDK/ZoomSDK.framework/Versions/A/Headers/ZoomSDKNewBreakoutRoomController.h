/**
 * @file ZoomSDKNewBreakoutRoomController.h
 * @brief Zoom SDK breakout room (BO) management interfaces.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKBOMeetingInfo
 * @brief Breakout room meeting information interface.
 */
@interface ZoomSDKBOMeetingInfo : NSObject

/**
 * @brief Gets breakout meeting ID.
 * @return The breakout meeting ID. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getBOID;

/**
 * @brief Gets breakout meeting nmae.
 * @return The breakout meeting name. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getBOName;

/**
 * @brief Gets breakout meeting user list.
 * @return If the function succeeds, will get the breakout meeting user list. Otherwise, this function fails and returns nil.
 */
- (NSArray *_Nullable)getBOUserlist;

/**
 * @brief Gets breakout meeting user status.
 * @param userID The user ID.
 * @return The user status.
 */
- (ZoomSDKBOUserStatus)getBOUserStatusWithUserID:(NSString *)userID;
@end


/**
 * @class ZoomSDKBOOption
 * @brief Defines breakout room configuration options.
 * For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0062540#h_1660846b-7d2d-4a87-b8a6-efe29a61759a>.
 */
@interface ZoomSDKBOOption : NSObject

/**
 * @brief Sets the countdown after closing breakout room.
 */
@property(nonatomic,assign)ZoomSDKBOStopCountDown  countDown;

/**
 * @brief Enables or disable that participant can choose breakout room.
 */
@property(nonatomic,assign)BOOL  isParticipantCanChooseBO;

/**
 * @brief Enables or disable that participant can return to main session at any time.
 */
@property(nonatomic,assign)BOOL  isParticipantCanReturnToMainSessionAtAnyTime;

/**
 * @brief Enables or disable that auto move all assigned participants to breakout room.
 */
@property(nonatomic,assign)BOOL  isAutoMoveAllAssignedParticipantsEnabled;

/**
 * @brief YES if it's timer BO, NO otherwise.
 */
@property(nonatomic,assign)BOOL  isBOTimerEnabled;

/**
 * @brief YES if time is up, stops BO auto, NO otherwise.
 */
@property(nonatomic,assign)BOOL  isTimerAutoStopBOEnabled;

/**
 * @brief Minutes of BO timer duration, NOTE: when nTimerDurationMinutes is 0, it means that the BO duration is 30 minutes.
 */
@property(nonatomic,assign)unsigned int  nTimerDurationMinutes;

//  WebinarBo
/**
 * @brief Enables or disable webinar attendee join webinar BO. When it changes, the BO data is reset.
 */
@property(nonatomic,assign) BOOL isAttendeeContained;

/**
 * @brief Enables or disable that panelist can choose breakout room.
 */
@property(nonatomic,assign) BOOL isPanelistCanChooseBO;

/**
 * @brief Enables or disable that Attendee can choose breakout room, invalid when attendee is not contained.
 */
@property(nonatomic,assign) BOOL isAttendeeCanChooseBO;

/**
 * @brief Enables or disable that max roomUser limits in BO room.
 */
@property(nonatomic,assign) BOOL isUserConfigMaxRoomUserLimitsEnabled;

/**
 * @brief Numbers of max roomUser limits in BO room, default is 20.
 */
@property(nonatomic,assign) unsigned int nUserConfigMaxRoomUserLimits;

/**
 * @brief Enables or disables AI Companion in breakout rooms.
 * @note If set to YES and ZoomSDKBOMeetingCreator::isAICompanionSupported returns YES, AI Companion
 *       auto-starts for host or cohost when they enter the breakout room, provided that AI Companion
 *       is already active in the main meeting. Default NO (opt-in).
 *       Setting this to YES when IsAICompanionSupported returns NO has no effect.
 */
@property(nonatomic,assign) BOOL isAICompanionEnabled;

/**
 * @brief Enables or disables transcription in breakout rooms.
 * @note If set to YES and ZoomSDKBOMeetingCreator::isTranscriptionSupported() returns YES, transcription
 *       auto-starst for all participants when they enter the breakout room, provided that transcription
 *       is already active in the main meeting. Default NO (opt-in).
 *       Setting this to YES when isTranscriptionSupported returns NO has no effect.
 */
@property(nonatomic,assign) BOOL isTranscriptionEnabled;

@end


/**
 * @protocol ZoomSDKBOMeetingCreatorDelegate
 * @brief Delegate protocol for breakout room creation related callbacks.
 */
@protocol ZoomSDKBOMeetingCreatorDelegate <NSObject>
@optional

/**
 * @brief When the pre-assigned data download status changes, triggers the event.
 * @param status Download status.
 */
- (void)onWebPreAssignBODataDownloadStatusChanged:(ZoomSDKPreAssignBODataStatus)status;

/**
 * @brief Triggers the event when the option changes.
 * @param newOption The new bo option.
 */
- (void)onBOOptionChanged:(ZoomSDKBOOption*)newOption;

/**
 * @brief The callback notification of "-createBreakoutRoom:".
 * @param bSuccess Indicate whether the creation is actually successful, YES indicates success, NO indicates failure.
 * @param boID If the creation is successful, its value is the breakout room's ID, otherwise the value is nil.
 */
- (void)onCreateBOResponse:(BOOL)bSuccess boID:(NSString *)boID;

/**
 * @brief The callback notification of ''-removeBO:'.
 * @param bSuccess Used to indicate whether the creation is actually successful, YES indicates success, NO indicates failure.
 * @param boID Identifies which breakout room is being removed.
 */
- (void)onRemoveBOResponse:(BOOL)bSuccess boID:(NSString *)boID;

/**
 * @brief The callback notification of "-updateBOName:BOID".
 * @param bSuccess Used to indicate whether the creation is actually successful, YES indicates success, NO indicates failure.
 * @param boID Identifies which breakout room is being updated.
 */
- (void)onUpdateBONameResponse:(BOOL)bSuccess boID:(NSString *)boID;
@end

/**
 * @class ZoomSDKBOMeetingCreator
 * @brief Interface for creating and managing breakout rooms.
 */
@interface ZoomSDKBOMeetingCreator : NSObject
/**
 * @brief Sets or get the delegate to receive breakout room creation callbacks.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKBOMeetingCreatorDelegate>  delegate;

/**
 * @brief Creates a breakout room.
 * @param name The breakout room name.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 * @note 1. This function is compatible with meeting breakout rooms and webinar breakout rooms.  2. This function is asynchronous, onCreateBOResponse is the corresponding callback notification. 3. Webinar breakout room only support Zoomui Mode.
 */
- (BOOL)createBreakoutRoom:(NSString *)name;

/**
 * @brief Creator breakout meeting in batch.
 * @param nameList Breakout meeting name list, the element of nameList should less than 50 characters.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)createBOWithBONameList:(NSArray<NSString *>*_Nullable)nameList;

/**
 * @brief Updates breakout meeting information. '-onUpdateBONameResponse:boID:' is the corresponding callback notification.
 * @param newName Breakout meeting new name.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)updateBOName:(NSString*)newName  BOID:(NSString *)ID;

/**
 * @brief Removes breakout meeting by ID. '-onRemoveBOResponse:boID:' is the corresponding callback notification.
 * @param BOID Need remove breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeBO:(NSString*)BOID;

/**
 * @brief Assign user to Breakout meeting.
 * @param userID Assigned user ID.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)assignUserToBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 * @brief Removed user from Breakout meeting.
 * @param userID Removed user ID.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeUserFromBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 * @brief Sets BO option.
 * @param boOption The option that you want to set.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setBOOption:(ZoomSDKBOOption *_Nullable)boOption;

/**
 * @brief Gets BO option.
 * @return If the function succeeds, it returns the bo option object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKBOOption *_Nullable)getBOOption;

/**
 * @brief Checks whether web enabled the pre-assigned option when scheduling a meeting.
 * @return If return YES if enabled. Otherwise, NO.
 */
- (BOOL)isWebPreAssignBOEnabled;

/**
 * @brief Request web pre-assigned data and create those rooms.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestAndUseWebPreAssignBOList;

/**
 * @brief Gets the downloading status of pre-assigned data.
 * @return The web pre-assigned data download status.
 */
- (ZoomSDKPreAssignBODataStatus)getWebPreAssignBODataStatus;

/**
 * @brief Determines if AI Companion is supported in breakout rooms.
 * @return YES if AI Companion is supported. Otherwise, NO.
 * @note Meaningful only before starting a breakout session. When YES, setting
 *       ZoomSDKBOOption::isAICompanionEnabled to YES auto-starts AI Companion for
 *       host or cohost upon entering the breakout room, provided that AI Companion is
 *       already active in the main meeting.
 */
- (BOOL)isAICompanionSupported;

/**
 * @brief Determines if transcription is supported in breakout rooms.
 * @return YES if transcription is supported. Otherwise, NO.
 * @note Meaningful only before starting a breakout session. When YES, setting
 *       ZoomSDKBOOption::isTranscriptionEnabled to YES auto-starts
 *       transcription for  all participants upon entering the breakout room,
 *       provided that transcription is already active in the main meeting.
 */
- (BOOL)isTranscriptionSupported;
@end


/**
 * @protocol ZoomSDKBOMeetingAdminDelegate
 * @brief Delegate to receive breakout room admin callbacks.
 */
@protocol ZoomSDKBOMeetingAdminDelegate <NSObject>
@optional
/**
 * @brief Host recieves this callback when attendee request for help.
 * @param userID The ID of user who request for help.
 */
- (void)onHelpRequestReceived:(NSString *)userID;

/**
 * @brief Callback of start breakout room fail.
 * @param errCode The reason of fail.
 */
- (void)onStartBOError:(ZoomSDKBOControllerError)errCode;

/**
 * @brief If it's timer BO, after start BO, you receives the event.
 * @param remaining Remaining time before bo end, the unit is seconds.
 * @param isTimesUpNotice If the isTimesUpNotice is YES, the bo meeting will end automatically. Otherwise not.
 */
- (void)onBOEndTimerUpdated:(unsigned int)remaining isTimesUpNotice:(BOOL)isTimesUpNotice;

/**
 * @brief The callback notification of "-startBO".
 * @param bSuccess Indicates whether the startup is actually successful. YES indicates success, and NO indicates failure.
 */
- (void)onStartBOResponse:(BOOL)bSuccess;

/**
 * @brief The callback notification of "-stopBO".
 * @param bSuccess Indicates whether the stop is actually successful. YES indicates success, and NO indicates failure.
 */
- (void)onStopBOResponse:(BOOL)bSuccess;
@end

/**
 * @class ZoomSDKBOMeetingAdmin
 * @brief A controller for managing breakout room operations as the admin.
 */
@interface ZoomSDKBOMeetingAdmin : NSObject
/**
 * @brief Sets or get the delegate to receive breakout room admin callbacks.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKBOMeetingAdminDelegate>  delegate;
/**
 * @brief Starts breakout meeting. '-onStartBOResponse:' is the corresponding callback notification.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startBO;

/**
 * @brief Stops breakout meeting. '-onStopBOResponse:' is the corresponding callback notification.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopBO;

/**
 * @brief Assign user to is runing breakout meeting.
 * @param userID Assigned user ID.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)assignNewUserToRunningBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 * @brief Switch Assigned user to differnt Breakout meeting(BO-A to BO-B).
 * @param userID Assigned user ID.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchAssignedUserToRunningBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 * @brief Determines if the user can start breakout room.
 * @return If returns YES, can start breakout room. Otherwise, NO.
 */
- (BOOL)canStartBO;

/**
 * @brief User request to join breakout room.
 * @param requestUserID The user ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)joinBOByUserRequest:(NSString *)requestUserID;

/**
 * @brief Notify attendee request help result.
 * @param userID The user ID of requested help.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)ignoreUserHelpRequest:(NSString *)userID;

/**
 * @brief Broadcast message.
 * @param message The broadcast context.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)broadcastMessage:(NSString *)message;

/**
 * @brief Host invite user return to main session, When BO is started and user is in BO.
 * @param userID The user ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inviteBOUserReturnToMainSession:(NSString *)userID;

/**
 * @brief Query if the current meeting supports broadcasting host's voice to BO.
 * @return YES if the meeting supports this. Otherwise, NO.
 */
- (BOOL)isBroadcastVoiceToBOSupport;

/**
 * @brief Query if the host now has the ability to broadcast voice to BO.
 * @return YES if the host now has the ability. Otherwise, NO.
 */
- (BOOL)canBroadcastVoiceToBO;

/**
 * @brief Starts or stop broadcasting voice to BO.
 * @param start YES for start and NO for stop.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)broadcastVoiceToBO:(BOOL)start;
@end


/**
 * @class ZoomSDKBOMeetingAssistant
 * @brief Manages operations for joining and leaving breakout meetings as an assistant.
 */
@interface ZoomSDKBOMeetingAssistant : NSObject

/**
 * @brief Join Breakout meeting by Breakout meeting ID.
 * @param ID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)joinBO:(NSString*)ID;

/**
 * @brief Leave Breakout meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)leaveBO;
@end


/**
 * @protocol ZoomSDKBOMeetingAttendeeDelegate
 * @brief Delegate to receive breakout room attendee callbacks.
 */
@protocol ZoomSDKBOMeetingAttendeeDelegate <NSObject>
@optional
/**
 * @brief Notify current user the request for help result.
 * @param result It is the request for help result.
 */
- (void)onHelpRequestHandleResultReceived:(ZoomSDKRequest4HelpResult)result;

/**
 * @brief Notify the host join current breakout room.
 */
- (void)onHostJoinedThisBOMeeting;

/**
 * @brief Notify the host leave current breakout room.
 */
- (void)onHostLeaveThisBOMeeting;

@end


/**
 * @class ZoomSDKBOMeetingAttendee
 * @brief Manages operations for attendees in breakout meetings.
 */
@interface ZoomSDKBOMeetingAttendee : NSObject
/**
 * @brief Sets or get the delegate to receive breakout room attendee callbacks.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKBOMeetingAttendeeDelegate>  delegate;
/**
 * @brief Join Breakout meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)joinBO;

/**
 * @brief Leave breakout meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)leaveBO;

/**
 * @brief Gets breakout meeting name.
 * @return If the function succeeds, it returns breakout meeting name. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getBOName;

/**
 * @brief Request for help when user in breakout room.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestForHelp;

/**
 * @brief Determines if the host is in this breakout room.
 * @return YES if the host in breakout room. Otherwise, NO.
 */
- (BOOL)isHostInThisBO;

/**
 * @brief Determines if participant can return to main session.
 * @return YES if participant can return to main session. Otherwise, NO.
 */
- (BOOL)isCanReturnMainSession;

@end

/**
 * @protocol ZoomSDKBOMeetingDataHelpDelegate
 * @brief Delegate to receive breakout room data helper callbacks.
 */
@protocol ZoomSDKBOMeetingDataHelpDelegate <NSObject>
@optional

/**
 * @brief If breakout meeting info changed, receives the callback.
 * @param boID Breakout meeting ID.
 */
- (void)onBOMeetingInfoUpdated:(NSString *)boID;

/**
 * @brief If the unassigned user changed, receives the callback.
 */
- (void)onUnAssignedUserUpdated;

/**
 * @brief If breakout meeting list changed, receives the callback.
 */
- (void)onBOListInfoUpdated;
@end


/**
 * @class ZoomSDKBOMeetingDataHelp
 * @brief Provides data helper functions for breakout meetings.
 */
@interface ZoomSDKBOMeetingDataHelp : NSObject

/**
 * @brief Sets or get the delegate to receive breakout room data helper callbacks.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKBOMeetingDataHelpDelegate>  delegate;

/**
 * @brief Gets unassigned user list.
 * @return If the function succeeds, it returns unassigned user array. Otherwise, this function fails and returns nil.
 */
- (NSArray *_Nullable)getUnassignedUserList;

/**
 * @brief Gets breakout meeting ID list.
 * @return If the function succeeds, it returns breakout meeting ID array. Otherwise, this function fails and returns nil.
 */
- (NSArray *_Nullable)getBOMeetingIDList;

/**
 * @brief Gets breakout meeting user name.
 * @param userID The user ID.
 * @return If the function succeeds, it returns user name. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getBOUserNameWithUserID:(NSString *)userID;

/**
 * @brief Gets breakout meeting info.
 * @param BOID Breakout meeting ID.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingInfo object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKBOMeetingInfo *_Nullable)getBOMeetingInfoWithBOID:(NSString *)BOID;

/**
 * @brief Determines if it is yourself by userID.
 * @param userid The user ID.
 * @return YES if yourself is in the breakout meeting. Otherwise, NO.
 */
- (BOOL)isMyselfInBo:(NSString *)userid;

/**
 * @brief Gets breakout meeting name.
 * @return The current breakout meeting's name. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getCurrentBoName;
@end


/**
 * @class ZoomSDKBOMeetingReturnToMainSessionHandler
 * @brief Handler class to manage returning to main session from breakout meeting.
 */
@interface ZoomSDKBOMeetingReturnToMainSessionHandler : NSObject

/**
 * @brief Return to main session.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)returnToMainSession;

/**
 * @brief Ignore the return invitation, after call this api, please don't use the handler unless you receive the invitation again.
 */
- (void)ignore;

@end


/**
 * @protocol ZoomSDKNewBreakoutRoomControllerDelegate
 * @brief Delegate protocol to receive new breakout room controller events and permission changes.
 */
@protocol ZoomSDKNewBreakoutRoomControllerDelegate <NSObject>
@optional

/**
 * @brief If the creator's permissions change, receives the callback.
 * @param creatorObject ZoomSDKBOMeetingCreator class object.
 */
- (void)onHasCreatorPermission:(ZoomSDKBOMeetingCreator *_Nullable)creatorObject;

/**
 * @brief If the admin's permissions change, receives the callback.
 * @param adminObject ZoomSDKBOMeetingAdmin object.
 */
- (void)onHasAdminPermission:(ZoomSDKBOMeetingAdmin *_Nullable)adminObject;

/**
 * @brief If the assistant's permissions change, receives the callback.
 * @param assistantObject ZoomSDKBOMeetingAssistant object.
 */
- (void)onHasAssistantPermission:(ZoomSDKBOMeetingAssistant *_Nullable)assistantObject;

/**
 * @brief If the attendee's permissions change, receives the callback.
 * @param attendeeObject ZoomSDKBOMeetingAttendee object.
 */
- (void)onHasAttendeePermission:(ZoomSDKBOMeetingAttendee *_Nullable)attendeeObject;

/**
 * @brief If the dataHelper's permissions change, receives the callback.
 * @param dataHelpObject ZoomSDKBOMeetingDataHelp object.
 */
- (void)onHasDataHelperPermission:(ZoomSDKBOMeetingDataHelp *_Nullable)dataHelpObject;

/**
 * @brief If lost creator's permissions change, receives the callback.
 */
- (void)onLostCreatorPermission;

/**
 * @brief If lost admin's permissions change, receives the callback.
 */
- (void)onLostAdminPermission;

/**
 * @brief If lost assistant's permissions change, receives the callback.
 */
- (void)onLostAssistantPermission;

/**
 * @brief If lost attendee's permissions change, receives the callback.
 */
- (void)onLostAttendeePermission;

/**
 * @brief If lost dataHelper's permissions change, receives the callback.
 */
- (void)onLostDataHelperPermission;

/**
 * @brief If host broadcast message,all attendee revieves this callback.
 * @param message The broadcast message context.
 * @param userid The sender message user ID.
 * @param senderName The sender message user name.
*/
- (void)onNewBroadcastMessageReceived:(NSString *)message senderUserId:(unsigned int)userid senderName:(NSString*)senderName;

/**
 * @brief If countDown != ZoomSDKBOStopCountDown_Not, host stop BO and all users receive the event.
 * @param countDown The countdown seconds.
 */
- (void)onBOMeetingStopCountDown:(unsigned int)countDown;

/**
 * @brief If you are in BO, host invite you return to main session, you receives the event.
 * @param userName The host name.
 * @param handler The ZoomSDKBOMeetingReturnToMainSessionHandler object.
 */
- (void)onHostInviteReturnToMainSession:(NSString*)userName handler:(ZoomSDKBOMeetingReturnToMainSessionHandler*)handler;

/**
 * @brief When host change the BO status, all users receive the event.
 * @param status Current status of BO.
 */
- (void)onBOControlStatusChanged:(ZoomSDKBOStatus)status;

/**
 * @brief Whenever the host switches you to another BO while you are assigned but haven't joined the BO, you receives this event.
 * @param newBOName The new BO name.
 * @param newBOID The new BO ID. If the current user is ZoomSDKBOMeetingAttendee, then the 2nd parameter strNewBOID returns nil.
 */
- (void)onBOSwitchRequestReceived:(NSString*)newBOName newBOID:(NSString*_Nullable)newBOID;

/**
 * @brief The status of broadcasting voice to BO has been changed.
 * @param start YES for start and NO for stop.
 */
- (void)onBroadcastBOVoiceStatus:(BOOL)start;

/**
 * @brief You receives this event when you are in a breakout room, and someone shares from the main session to the breakout room.
 * @param sharingID The sharing ID.
 * @param status The sharing status.
 * @param shareAction The pointer of share action object.
 */
- (void)onShareFromMainSession:(unsigned int)sharingID status:(ZoomSDKShareStatus)status shareAction:(ZoomSDKShareAction *)shareAction;
@end



/**
 * @class ZoomSDKNewBreakoutRoomController
 * @brief Controller class to manage breakout room features and permissions.
 */
@interface ZoomSDKNewBreakoutRoomController : NSObject
/**
 * @brief Delegate to receive breakout room controller callbacks.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKNewBreakoutRoomControllerDelegate>  delegate;

/**
 * @brief Gets ZoomSDKBOMeetingCreator Class object.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingCreator object. Otherwise, this function fails and returns nil.
 * @note Only host can get this object.
 */
- (ZoomSDKBOMeetingCreator *_Nullable)getBOMeetingCreator;

/**
 * @brief Gets ZoomSDKBOMeetingAdmin Class object.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingAdmin object. Otherwise, this function fails and returns nil.
 * @note Host in master meeting or breakout meeting can get this object.
 */
- (ZoomSDKBOMeetingAdmin *_Nullable)getBOMeetingAdmin;

/**
 * @brief Gets ZoomSDKBOMeetingAssistant Class object.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingAssistant object. Otherwise, this function fails and returns nil.
 * @note Host in master or breakout meeting or cohost in breakmeeting can get this object.
 */
- (ZoomSDKBOMeetingAssistant *_Nullable)getBOMeetingAssistant;

/**
 * @brief Gets ZoomSDKBOMeetingAttendee Class object.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingAttendee object. Otherwise, this function fails and returns nil.
 * @note If you are CoHost or attendee, and are assigned to BO, you will get this object.
 */
- (ZoomSDKBOMeetingAttendee *_Nullable)getBOMeetingAttendee;

/**
 * @brief Gets ZoomSDKBOMeetingDataHelp Class object.
 * @return If the function succeeds, it returns ZoomSDKBOMeetingDataHelp object. Otherwise, this function fails and returns nil.
 * @note Host in master or breakout meeting or cohost in breakmeeting can get this object.
 */
- (ZoomSDKBOMeetingDataHelp *_Nullable)getBOMeetingDataHelp;

/**
 * @brief Determines if breakout meeting is start.
 * @return YES if bo is started. Otherwise, NO.
 */
- (BOOL)isBOStart;

/**
 * @brief Determines if breakout meeting is enable.
 * @return YES if bo is enabled. Otherwise, NO.
 */
- (BOOL)isBOEnable;

/**
 * @brief Determines if user is in breakout meeting.
 * @return YES if user is in bo meeting. Otherwise, NO.
 */
- (BOOL)isInBOMeeting;

/**
 * @brief Gets current BO status.
 * @return The value is a enum for bo status.
 */
- (ZoomSDKBOStatus)getBOStatus;

/**
 * @brief Query if the host is broadcasting voice to BO.
 * @return YES if the host is broadcasting. Otherwise, NO.
 */
- (BOOL)isBroadcastingVoiceToBO;

/**
 * @brief Gets the BO's name you are going to.
 * @return The value is join bo name which you are going to.
 * @note When you enter a BO or are switched to another BO by the host, maybe you need the BO name to display on transfer UI. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getJoiningBOName;
@end

NS_ASSUME_NONNULL_END
