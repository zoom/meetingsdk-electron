//
//  ZMBuddyProfileRoute.h
//  zChatBase
//
//  Route facade for Meeting -> PT add-contact / unblock panels over ZMXProcEventBus.
//  These are standalone native ChatUI VCs (ZMAddContactViewController /
//  ZMUnBlockUsersViewController) — NOT the web profile card — so they are presented
//  in PT. (The in-meeting web profile card itself renders in-process via
//  ZMUserProfileMgr / ZMBuddyProfileCardModule.) Method prefix PT_ marks the target.
//
//  Mirrors ZMInviteChatRoute / ZMDeepLinkRoute. PT-side receiver:
//  ZMBuddyProfileRouteUIHelper (ChatUI).
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBuddyProfileRoute : NSObject

@property (class, nonatomic, readonly) NSString *feature;
@property (class, nonatomic, readonly) NSString *addContactByEmail;
@property (class, nonatomic, readonly) NSString *addContactByEmailWithNote;
@property (class, nonatomic, readonly) NSString *addContactByJid;
@property (class, nonatomic, readonly) NSString *addContactByJidWithSource;
@property (class, nonatomic, readonly) NSString *unblockUser;

+ (void)PT_showAddContactWithEmail:(nullable NSString *)email addTip:(BOOL)addTip;
+ (void)PT_showAddContactWithEmail:(nullable NSString *)email note:(nullable NSString *)note source:(NSInteger)source;
+ (void)PT_showAddingContactWithJid:(nullable NSString *)jid;
+ (void)PT_showAddingContactWithJid:(nullable NSString *)jid source:(NSInteger)source;
+ (void)PT_showUnBlockUser;

@end

NS_ASSUME_NONNULL_END
