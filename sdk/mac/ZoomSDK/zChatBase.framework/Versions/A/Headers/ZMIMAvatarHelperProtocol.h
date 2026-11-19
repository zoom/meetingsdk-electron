//
//  ZMIMAvatarHelperProtocol.h
//  zChatBase
//
//  Avatar helper protocol for decoupling UI modules (e.g. zVideoUI)
//  from zChatComponent's concrete helper implementation.
//
//  Keep this header lightweight (no zChatComponent model imports).
//

#ifndef ZMIMAvatarHelperProtocol_h
#define ZMIMAvatarHelperProtocol_h

#import <Cocoa/Cocoa.h>

@protocol ZMBuddyBaseProtocol;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMIMAvatarHelperProtocol <NSObject>

/// Default avatar (implementation-defined size, typically 32x32).
- (nullable NSImage *)getUserAvatarByID:(NSString *)JID;

/// Get an avatar URL for a JID (implementation may return file:// or bundle:// URLs).
- (nullable NSURL *)getUserAvatarURLByID:(NSString *)JID;

/// Avatar with specific size.
- (nullable NSImage *)getUserAvatarByID:(NSString *)JID avatarSize:(CGSize)avatarSize;

/// Avatar for a buddy model (prefer passing a concrete adapter; protocol fallback may be limited).
- (nullable NSImage *)getUserAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo;
- (nullable NSImage *)getUserAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo avatarSize:(CGSize)avatarSize;
- (nullable NSImage *)getUserBigAvatarByBuddyInfo:(id<ZMBuddyBaseProtocol>)buddyInfo avatarSize:(CGSize)avatarSize;

/// MCC Messages will not always get a buddy adapter through JID.
/// In that case, draw avatar using userName.
- (nullable NSImage *)getUserAvatarByID:(nullable NSString *)JID
                               userName:(nullable NSString *)userName
                             avatarSize:(CGSize)avatarSize;

/// Create avatar for Bot App with JID or name.
- (nullable NSImage *)getChatAppAvataByJID:(NSString *)JID
                                   appName:(nullable NSString *)name;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMIMAvatarHelperProtocol_h */

