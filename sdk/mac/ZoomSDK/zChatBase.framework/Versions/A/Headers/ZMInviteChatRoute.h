//
//  ZMInviteChatRoute.h
//  zChatBase
//
//  Route facade for Meeting -> PT "open team chat" calls over ZMXProcEventBus.
//  Method prefix marks the target process: PT_ sends to PT.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMInviteChatRoute : NSObject

// Consumed by the PT-side receiver's @zm_request / @zm_action registration.
@property (class, nonatomic, readonly) NSString *feature;
@property (class, nonatomic, readonly) NSString *startChat;

// sessionID is the target user/session id; opens the PT team-chat window for it.
+ (void)PT_startChatWithSessionID:(nullable NSString *)sessionID;

@end

NS_ASSUME_NONNULL_END
