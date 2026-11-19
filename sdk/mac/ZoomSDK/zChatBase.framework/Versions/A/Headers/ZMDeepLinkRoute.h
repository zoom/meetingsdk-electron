//
//  ZMDeepLinkRoute.h
//  zChatBase
//
//  Route facade for Meeting -> PT deep-link UI navigation over ZMXProcEventBus.
//  The open* deep-link actions drive the PT main window (ZMPTUIApi/ZMMainTabsMgr/
//  ...), which does not exist in the Meeting subprocess, so they are published to
//  PT. Method prefix PT_ marks the target process.
//
//  Mirrors ZMInviteChatRoute. The PT-side receiver registers via @zm_request /
//  @zm_action (see ZMDeepLinkRouteUIHelper in ChatUI).
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDeepLinkRoute : NSObject

// Consumed by the PT-side receiver's @zm_request / @zm_action registration.
@property (class, nonatomic, readonly) NSString *feature;
@property (class, nonatomic, readonly) NSString *openLink;
@property (class, nonatomic, readonly) NSString *openSession;
@property (class, nonatomic, readonly) NSString *openSessionID;
@property (class, nonatomic, readonly) NSString *openMessage;
@property (class, nonatomic, readonly) NSString *directJoinSubCMC;
@property (class, nonatomic, readonly) NSString *openEmail;

// Fire-and-forget navigation. PT brings its main window forward and navigates.
+ (void)PT_openLink:(nullable NSString *)url sessionId:(nullable NSString *)sessionId;
+ (void)PT_openSession:(nullable NSString *)sessionID;
+ (void)PT_openSessionID:(nullable NSString *)sessionID;   // jumpAction cannot cross the bus; PT navigates on its own.
+ (void)PT_openMessage:(nullable NSString *)messageID sessionID:(nullable NSString *)sessionID serverTime:(unsigned long long)serverTime;
+ (void)PT_openMessage:(nullable NSString *)messageID
             sessionID:(nullable NSString *)sessionID
            serverTime:(unsigned long long)serverTime
         openSessionID:(nullable NSString *)openSessionID
             isComment:(BOOL)isComment
              threadID:(nullable NSString *)threadID
      threadServerTime:(unsigned long long)threadServerTime
   highlightBackground:(BOOL)highlightBackground
       highlightBubble:(BOOL)highlightBubble
     shouldCleanUnread:(BOOL)shouldCleanUnread;
+ (void)PT_directJoinSubCMC:(nullable NSString *)subCMCSessionId;

// openEmail returns BOOL on the PT side; relayed back via the bus completion (main thread, once).
+ (void)PT_openEmail:(nullable NSString *)email completion:(nullable void(^)(BOOL ok))completion;

@end

NS_ASSUME_NONNULL_END
