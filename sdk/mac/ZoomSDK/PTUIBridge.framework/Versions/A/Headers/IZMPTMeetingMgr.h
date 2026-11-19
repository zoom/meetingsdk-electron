//
//  IZMPTMeetingMgr.h
//  PTUIBridge
//
//  Created by Davies Zhao on 2025/7/15.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZPMeetingItemProtocol.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMCallUpgradeDialogInfo;
@protocol ZPInvitationItemProtocol;
@protocol ZMPTCMCMeetingInfoProtocol <NSObject>

@property (nonatomic, copy) NSString *CMCID;
@property (nonatomic, copy) NSString *channelID;
@property (nonatomic, assign) NSInteger CMCMeetingNumber;
@property (nonatomic, assign) BOOL enableJumpCMC;
@property (nonatomic, assign) long long CMCMeetingNumBeforeSignIn;

@end

@protocol IZMPTMeetingMgr <ZMPTCMCMeetingInfoProtocol>

- (void)webJoin:(id)meetingItem;
- (void)switchForStartSchdule:(id)meetingItem;
- (void)switchForJoinSchdule:(id)meetingItem;
- (void)checkMeetingWhenNeedDirectShare;

- (void)showHUDWindowWithFriendId:(NSString *)friendId
                            title:(NSString *)name
                             desc:(NSString *)message
                      messageType:(ConfPoppingUpTipType)messageType;
- (void)showHUDWindowWithFriendId:(NSString *)friendId
                            title:(NSString *)name
                             desc:(NSString *)message
                      messageType:(ConfPoppingUpTipType)messageType
                           target:(id)target
                           action:(SEL)action;

- (void)showLoginOrQuitSubProcessIfNeeded;

- (void)showPerformanceTestErrorAlert;

- (int)acceptVideoCall:(id<ZPInvitationItemProtocol>)invitationProtocol template:(NSString*)invitationMsgTemplate;
- (void)webJoinConfirm:(id<ZPMeetingItemProtocol>)hangout join:(BOOL)join;
- (void)showConfirmJoinExternalMeeting:(void * _Nullable)meetingItem;
@end

NS_ASSUME_NONNULL_END
