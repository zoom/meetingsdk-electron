//
//  ZMDeepLinkLocalProtocol.h
//  zChatBase
//
//  Deep-link methods whose implementation does NOT depend on ChatUI and can run
//  in-process inside the Meeting subprocess. The concrete implementation lives in
//  zChatComponent (ZMDeepLinkLocalModule) and is registered via @routerable, so
//  ZMShareDeepLinkLocal resolves in both the PT and the Meeting process.
//
//  Background: ZMDeepLinkProtocol is implemented by ChatUI's
//  ZMUniversalDeepLinkManager, which only exists in the PT process. In the Meeting
//  subprocess ZMShareDeepLinkProtocol resolves to nil. The link-judgement /
//  link-info / entity / link-generation methods declared here were split out so
//  meeting-side deep-link parsing & preview keep working in-process. UI navigation
//  (open*) stays in PT and is reached via ZMDeepLinkRoute over ZMXProcEventBus.
//
//  NOTE: keep signatures identical to ZMDeepLinkProtocol so existing call sites
//  compile unchanged after switching to ZMShareDeepLinkLocal.
//

#ifndef ZMDeepLinkLocalProtocol_h
#define ZMDeepLinkLocalProtocol_h

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>   // ZMUniversalDeepLinkType

// ZMUniversalDeepLinkInfo is defined in ZMDeepLinkProtocol.h. Forward-declare here to avoid a
// circular import (ZMDeepLinkProtocol.h imports this header so the macros are available wherever
// ZMShareDeepLinkProtocol is).
@class ZMUniversalDeepLinkInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMDeepLinkLocalProtocol <NSObject>

@optional

// Link judgement / info — pure SDK (IDeepLinkV2Manager via the session-aware messenger),
// no ChatUI dependency, so they run in-process in both PT and Meeting.
- (BOOL)isDeepLink:(NSString *)url sessionId:(nullable NSString *)sessionId;
- (BOOL)shouldShowDeepLinkFormatForURL:(NSString *)url sessionID:(nullable NSString *)sessionID;

- (ZMUniversalDeepLinkType)getDeepLinkType:(NSString *)url sessionId:(nullable NSString *)sessionId;
- (nullable ZMUniversalDeepLinkInfo *)getLinkInfo:(NSString *)forLink sessionId:(nullable NSString *)sessionId;

- (BOOL)isDeepLinkEnabledForSessionID:(NSString *)sessionID messageID:(nullable NSString *)messageID serverTime:(long long)serverTime;

@end

#ifndef ZMShareDeepLinkLocal
#define ZMShareDeepLinkLocal (id<ZMDeepLinkLocalProtocol>)ZMSharedFor(ZMDeepLinkLocalProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMDeepLinkLocalProtocol_h */
