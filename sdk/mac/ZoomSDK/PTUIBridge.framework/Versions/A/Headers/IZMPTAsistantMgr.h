//
//  IZMPTAsistantMgr.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/25.
//

#ifndef IZMPTAsistantMgr_h
#define IZMPTAsistantMgr_h

@protocol ZMPPTDataProtocol;
@protocol IZMPTAsistantMgr
- (id<ZMPPTDataProtocol>)eventCenter;
- (void)registerPTWebserviceSink;

- (BOOL)isScheduleAdapterInstalled;
- (void)copyPMINumberToPasteBoard;
- (void)editPMIMeeting;
- (void)copyPMIInvitationToPasteBoard;
- (BOOL)isPMIItemHostVideoOff;
- (BOOL)hasPMIItem;
- (void)scheduleNewMeeting;
- (void)scheduleNewMeetingOnHome;
- (void)startDiagnosticMeeting:(void*)content;
- (void)openReleaseNote;

- (BOOL)isRecording;
- (BOOL)isPlayingIMAudio;

- (void)checkPromoteChatGuidanceIfNeedsCheckShowTip:(BOOL)needsCheckTip
                        needsCheckPromoteChatWindow:(BOOL)needsCheckPromoteChatWindow
                        needsCheckCallUpgradeWindow:(BOOL)needsCheckCallUpgradeWindow;

- (BOOL)canZoomChatDisplaySize;

- (BOOL)isAICompanionPlusEnabled;

- (void)startChatByUserId:(nullable NSString *)uid;

- (void)onPromoteChatAfterMeetingStartClicked;

- (id<ZMNotificationProtocol>)notificationDelegate;
@end
//ZMSharedFor(IZMPTAsistantMgr)
#endif /* IZMPTAsistantMgr_h */
