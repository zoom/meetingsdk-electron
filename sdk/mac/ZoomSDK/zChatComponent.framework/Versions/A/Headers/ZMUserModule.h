//
//  ZMUserModule.h
//  zChatUI
//
//  Created by groot.ding on 2018/4/25.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMBuddyProtocal.h>
#import <ZoomUnit/ZMLoginProtocol.h>

@interface ZMUserModule : NSObject <ZMBuddyProtocol,ZMLoginProtocol>

+ (nonnull instancetype)shareInstance;
+ (nonnull instancetype)sharedInstance;

@property (nonatomic,assign) int connectType;

// Expose minimal APIs used by other compilation units under -Werror=objc-method-access.
- (BOOL)isExternalLabelDisabled;

// Used by group/search helpers.
- (BOOL)isRealSameOrg:(NSString *)jid1 with:(NSString *)jid2;
- (void)didAssignGroupSearchBuddy:(NSUInteger)result key:(NSString *)key jids:(NSArray<NSString *> *)jids;
- (void)didSearchBuddy:(NSUInteger)result key:(NSString *)key jids:(NSArray<NSString *> *)jids reqId:(NSString *)reqId;

// Used by zChatComponent internal listeners (e.g. ZMPTUserAvatarMgr).
- (void)addListenMySelfBuddyUpdateByTarget:(id)target completion:(ZMBuddyListenCompletion)completion;
- (void)addListenAllBuddyListUpdateByTarget:(id)target completion:(ZMBuddyListenCompletion)completion;

// Used by message/content modules.
- (void)didBuddyPresenceUpdate:(NSString *)jid;
- (void)addListenBlockUsersUpdateByTarget:(id)target completion:(ZMBuddyListenCompletion)completion;
@end
