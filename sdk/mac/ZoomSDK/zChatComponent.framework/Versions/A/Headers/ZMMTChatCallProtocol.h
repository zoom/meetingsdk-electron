//
//  ZMMTChatCallProtocol.h
//  zChatComponent
//
//  Created by Devl on 1/24/24.
//

#ifndef ZMMTChatCallProtocol_h
#define ZMMTChatCallProtocol_h

#import <Cocoa/Cocoa.h>
#import <Prism/ZMRoutableObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMChatAppContext;
@class ZMFileEntity;
@class ZMMessageAdapter;
@class ZMToast;
@class ZMMTBuddyModel;
@class ZMChatMsgItemInfo;
@class ZMBuddyAdapter;

@protocol ZMMTChatCallProtocol <ZMRoutableObject>

- (BOOL)mtChatIsLogin;
- (BOOL)mtChatCanChat:(NSString*)sessionID;
- (BOOL)mtChatCanSendFile;
- (BOOL)mtChatCanDeleteHybridItem:(ZMFileEntity *)fileItem;
- (BOOL)mtChatAmIHostCohost;
- (BOOL)mtChatInSilentMode;
- (BOOL)mtChatIsCMCEnabled:(NSString*)sessionID;
- (BOOL)mtChatIsValidMessage:(ZMMessageAdapter*)adapter;
- (BOOL)mtChatCanEditMessage:(ZMMessageAdapter*)adapter;
- (BOOL)mtChatCanPinMessage:(ZMMessageAdapter*)adapter;
- (BOOL)mtChatCanStarMessage:(ZMMessageAdapter*)adapter;
- (BOOL)mtChatNeedShowReceiver:(ZMMessageAdapter*)adapter;
- (BOOL)mtChatCanPreviewHoverLink:(NSString*)sessionID;
- (BOOL)mtChatCanShowFusion:(NSString*)sessionID;
- (BOOL)mtChatCanShowMentionCount:(NSString*)sessionID;

- (BOOL)mtChatCheckError:(NSString*)sessionID threadID:(NSString*)threadID;
- (BOOL)mtChatCanSendChatTo:(NSDictionary*)info;
- (void)mtChatSelectChatTo:(NSDictionary*)info;

- (BOOL)mtChatCheckFileSizeFailed:(unsigned long long)size isScreenshot:(BOOL)isScreenshot;
- (BOOL)mtChatCheckFileTypeFailed:(NSString*)path isScreenshot:(BOOL)isScreenshot;
- (unsigned long long)mtChatGetMaxFileSize;

- (BOOL)mtChatCheckRespond2Message:(NSString*)messageID sessionID:(NSString*)sessionID;

- (NSString*)mtChatGetAccountID;
- (NSString*)mtChatGetCurrentSessionID;
- (nullable NSViewController*)mtChatGetMessageController;

- (NSInteger)mtChatGetPlistCount:(NSString*)sessionID;
- (NSString*)mtChatGetSendUserID:(NSString*)sessionID threadID:(NSString*)threadID;
- (NSInteger)mtChatGetSendMsgType:(NSString*)sessionID threadID:(NSString*)threadID;
- (NSInteger)mtChatGetMsgNodeID:(NSString*)sessionID threadID:(NSString*)threadID;

- (NSImage*)mtChatGetAvatarByBuddy:(ZMBuddyAdapter*)buddy;
- (NSImage*)mtChatGetAvatarByMTBuddy:(ZMMTBuddyModel*)buddy;
- (NSImage*)mtChatGetAvatarByMessage:(ZMMessageAdapter*)adapter;
- (NSImage*)mtChatGetMyAvatar;

- (nullable NSArray<ZMMTBuddyModel*>*)mtChatGetAtMentionSortedList:(NSString*)sessionID
                                                          threadID:(nullable NSString*)threadID
                                                               key:(nullable NSString*)key
                                                           hasMore:(nullable BOOL*)hasMore
                                                         requestID:(NSString*_Nullable*_Nullable)requestID;

- (void *)mtChatGetZAppModuleAPI;
- (void *)mtChatGetPTAppAPI;

- (void)mtChatLoadChatDBReady;
- (void)mtChatLoadChatDataReady;
- (void)mtChatRefreshChatDataReady;

- (void)mtChatShowDeletedByDlpAlert;
- (void)mtChatOpenAppInvitation:(ZMChatAppContext*)context;
- (BOOL)mtChatIsZoomInternalURL:(NSString *)url;
- (BOOL)mtChatOpenZoomInternalLink:(NSString *)url;

- (BOOL)mtChatOpenURL:(NSString*)url;

- (void)mtChatDeliverToast:(ZMToast*)toast;
- (void)mtChatErrorOccured:(NSString*)errorMsg;

- (BOOL)mtChatAddEmojiForMessage:(NSString*)sessionID msgID:(NSString*)msgID emoji:(NSString*)emoji fileID:(NSString*)fileID requestID:(NSString*_Nullable*_Nullable)requestID;
- (BOOL)mtChatRemoveEmojiForMessage:(NSString*)sessionID msgID:(NSString*)msgID emoji:(NSString*)emoji fileID:(NSString*)fileID requestID:(NSString*_Nullable*_Nullable)requestID;

- (NSAttributedString *)mtChatGetNameAttributedString:(ZMChatMsgItemInfo *)itemInfo;
- (nullable NSString *)mtChatGetUserNameByJoinIndex:(NSUInteger)joinIndex;

- (BOOL)mtChatIsMeetingWindowKey;
- (void)mtChatExcludeMeetingWindows:(BOOL)excluded;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMTChatCallProtocol_h */
