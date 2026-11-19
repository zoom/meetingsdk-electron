//
//  ZMBuddyProfileCardModule.h
//  zChatComponent
//
//  In-process implementation of ZMBuddyProfileCardProtocol for the Meeting
//  subprocess. The profile-card UI must render in-process (showing PT UI over a
//  meeting causes focus/window issues), so this wraps the ChatUI-free web popover
//  ZMUserProfileMgr. add-contact / unblock are standalone native ChatUI panels and
//  are routed to PT via ZMBuddyProfileRoute.
//
//  Registers as the ZMBuddyProfileCardProtocol singleton ONLY in non-PT processes;
//  in PT, ChatUI's ZMUserManager remains the implementor (native float preserved).
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMBuddyProtocal.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMBuddyProfileCardModule : NSObject <ZMBuddyProfileCardProtocol>

+ (instancetype)shared;

@end

NS_ASSUME_NONNULL_END
