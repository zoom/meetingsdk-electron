//
//  ZMIMAvatarHelper.h
//  ChatUI
//
//  Created by Groot Ding on 2022/4/25.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMAvatarHelperProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMIMAvatarHelper : NSObject <ZMIMAvatarHelperProtocol>

/// For ZMRouterCenter singleton routing (ZMSharedFor).
+ (instancetype)shared;

- (nullable NSImage *)getUserAvatarByID:(NSString*)JID;

- (nullable NSURL *)getUserAvatarURLByID:(NSString *)JID;

- (nullable NSImage *)getUserAvatarByID:(NSString*)JID avatarSize:(CGSize)avatarSize;

- (nullable NSImage *)getUserAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo;

- (nullable NSImage *)getUserAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo avatarSize:(CGSize)avatarSize;

- (nullable NSImage *)getUserBigAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo avatarSize:(CGSize)avatarSize;

/*  MCC Messages will not always get a ZMBuddyAdapter through JID. So, draw draw user avata using userName. */
- (nullable NSImage *)getUserAvatarByID:(nullable NSString*)JID
                               userName:(nullable NSString*)userName
                             avatarSize:(CGSize)avatarSize;

///  Create Avata for Bot App with JID or Name. When the app can not be searched by JID, drawing avata with App name is more suitable.
/// - Parameters:
///   - JID: Bot App JID
///   - name: Bot App Name
- (nullable NSImage *)getChatAppAvataByJID:(nonnull NSString*)JID
                                   appName:(nullable NSString*)name;

@end

NS_ASSUME_NONNULL_END
