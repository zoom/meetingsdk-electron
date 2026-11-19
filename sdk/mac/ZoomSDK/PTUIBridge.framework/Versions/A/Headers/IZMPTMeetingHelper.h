//
//  IZMPTMeetingHelper.h
//  PTUIBridge
//
//  Created by fistice on 6/27/25.
//

#ifndef IZMPTMeetingHelper_h
#define IZMPTMeetingHelper_h

#ifdef __cplusplus
#import <zPTApp/SaasBeePTAppInterface.h>
#endif
/// MeetingStartEntranceType
typedef NS_ENUM(int, ZMStartMeetingEntrance) {
    /// MeetingStartEntrance_Unknown = 0,
    ZMStartMeetingEntranceanceUnknown = 0,
    /// MeetingStartEntrance_Home = 1,
    ZMStartMeetingEntranceanceHome = 1,
    /// MeetingStartEntrance_Dm = 2,
    ZMStartMeetingEntranceanceDM = 2,
    /// MeetingStartEntrance_Channel = 3,
    ZMStartMeetingEntranceanceChannel = 3,
    /// MeetingStartEntrance_Dm_Sidebar = 4,
    ZMStartMeetingEntranceanceDMSideBar = 4,
    /// MeetingStartEntrance_Channel_Sidebar = 5,
    ZMStartMeetingEntranceanceChannelSidebar = 5,
    /// MeetingStartEntrance_Missed_Call = 6,
    ZMStartMeetingEntranceanceMissedCall = 6,
    /// MeetingStartEntrance_Contacts = 7,
    ZMStartMeetingEntranceanceContacts = 7,
    /// MeetingStartEntrance_Channel_Member_List = 8,
    ZMStartMeetingEntranceanceChannelMemberList = 8,
    /// MeetingStartEntrance_Profile_Card = 9,
    ZMStartMeetingEntranceanceProfileCard = 9,
    /// MeetingStartEntrance_Muc = 10,
    ZMStartMeetingEntranceanceMuc = 10,
    /// MeetingStartEntrance_Muc_Sidebar = 11,
    ZMStartMeetingEntranceanceMucSidebar = 11
};
@protocol ZPInvitationItemProtocol;

@protocol IZMPTMeetingHelper <NSObject>
//sip call warning
- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andParam:(id)idParam;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate userJID:(NSString*)jid openVideo:(BOOL)open;

- (BOOL)try2ShowDlgBeforeEnterMeeting:(id)pDelegate andCallBack:(NSString*)strCallBack andCancelCallBack:(NSString*)strCancelCallBack andParam:(id)idParam andIsJoinMeeting:(BOOL)isJoinMeeting;
//meeting
#ifdef __cplusplus
- (void)webJoinConfirmInSIP:(ISBMeetingItem *)meetingItem join:(BOOL)join;
- (void)confirmJoinExternalMeeting:(ISBMeetingItem *)meetingItem join:(BOOL)join;
#endif
- (BOOL)checkMeetingStartUp;
- (void)joinMeeting;
- (void)startMeeting;
- (void)startMeetingWithZMEntrance:(ZMStartMeetingEntrance)entrance videoOn:(BOOL)videoOn;
- (void)closeMeetingAlertView;

// Meeting status and control
- (BOOL)canJoinByIDNow;
- (BOOL)joinFromIconTray:(int)reason;
- (void)setJoinMeetingScenarioLocation;
- (void)setStartMeetingScenarioLocation;
- (BOOL)isInMeeting;
- (int)getCallStatus;
- (BOOL)IsEnableJoinMultiMeeting;
- (nullable NSNumber *)getActiveMeetingNo;
- (BOOL)isMultiJoinSubProcess;
- (BOOL)canAccessZoomWebservice;
- (BOOL)isLaunchedByWebJoin;
- (BOOL)isLoginFacebook;
- (BOOL)isLoginGoogle;
- (BOOL)logout:(int)option;
- (BOOL)isNoMeetingLicenseUser;
- (BOOL)isEnableHideMeetingScheduleEditActions;
- (nullable NSString *)getLocalizedTermServiceURL;
- (nullable NSString *)getLocalizedPolicyURL;
- (BOOL)isPlaySoundForIMMessage;
- (BOOL)isMeetingDarkMode;
// === Meeting Management ===
- (void)notifyMissedCallWithMeetingInfo:(id<ZPInvitationItemProtocol>)meetingInfo;
- (void)declineVideoCall:(nullable id<ZPInvitationItemProtocol>)meetingInfo withMessage:(BOOL)hasMessage;
// H323/SIP Room System Methods
- (nullable NSArray *)getAllRoomDevices;
- (BOOL)startVideoCallWithRoomSystem:(id)device;
- (void)setVideoCallWithRoomSystemPrepareStatus:(BOOL)status;
- (nullable NSString*)getBOSessionName;
- (void)forceLeavingCurrentConference;
- (void)clearRejoinMeetingParams;
- (void)cancelReloginAndRejoin;

// === User & Authentication ===
- (nullable NSString *)getMySelfJID;
- (BOOL)isLoginZoomus;
- (nullable NSString *)getNormalBuddyJIDForEmail:(nullable NSString *)email;
- (BOOL)isConnectionGood;

- (BOOL)canRenameWhenJoinMeeting;

// === UI Helpers ===
- (NSInteger)getPopUpWindowLevel;
- (nullable NSString *)getAvatarImagePath:(nullable NSString *)userId;

- (nullable NSString*)getEmail;
- (nullable NSString*)myEmail;
- (BOOL)isGovUser;

@end
#endif /* IZMPTMeetingHelper_h */
