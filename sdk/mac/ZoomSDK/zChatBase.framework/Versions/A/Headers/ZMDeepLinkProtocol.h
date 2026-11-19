//
//  ZMDeepLinkProtocol.h
//  zChatBase
//
//  Moved from zChatComponent to zChatBase to decouple consumers that only need
//  the deep-link protocol declarations.
//
//  NOTE:
//  - Avoid importing zChatComponent model headers; forward declare instead.
//  - Keep C++ types guarded under __cplusplus.
//

#ifndef ZMDeepLinkProtocol_h
#define ZMDeepLinkProtocol_h

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>

#if defined(__cplusplus)
#include <zPTApp/SaasBeePTAppInterface.h>
#endif

@class ZMMessageAdapter;
@class ZMDeepLinkEntity;

NS_ASSUME_NONNULL_BEGIN

@interface ZMUniversalDeepLinkInfo : NSObject
@property (nonatomic) ZMUniversalDeepLinkType linkType;
@property (nonatomic, nullable, retain) NSString *messageID;
@property (nonatomic, nullable, retain) NSString *sessionID;
@end

@protocol ZMDeepLinkProtocol <NSObject>

@optional

- (BOOL)isDeepLink:(NSString *)url sessionId:(nullable NSString *)sessionId;
- (BOOL)shouldShowDeepLinkFormatForURL:(NSString *)url sessionID:(nullable NSString *)sessionID;

- (void)openLink:(NSString *)url sessionId:(nullable NSString *)sessionId;

- (ZMUniversalDeepLinkType)getDeepLinkType:(NSString *)url sessionId:(nullable NSString *)sessionId;
- (nullable ZMUniversalDeepLinkInfo *)getLinkInfo:(NSString *)forLink sessionId:(nullable NSString *)sessionId;

/// FeaturePhase_1
- (BOOL)isDeepLinkEnabled;
#if defined(__cplusplus)
- (BOOL)isDeepLinkEnabledForPhase:(NS_ZOOM_MESSAGER::IDeepLinkV2Manager::FeaturePhase)phase;
#endif
- (BOOL)isDeepLinkEnabledForSessionID:(NSString *)sessionID messageID:(nullable NSString *)messageID serverTime:(long long)serverTime;

/// V4 channel invite links
- (BOOL)isDeeplinkV4Enabled;

- (nullable ZMDeepLinkEntity *)getEntity:(NSString *)forLink sessionId:(nullable NSString *)sessionId;

- (void)makeLinkFromMessageAdapter:(ZMMessageAdapter *)adapter
                          callback:(void(^_Nullable)(NSString *_Nonnull, NSUInteger))callback;

- (void)makeLinkFromSessionID:(NSString *)session_id
                    messageID:(nullable NSString *)message_id
             messageTimestamp:(NSUInteger)message_timestamp
                     callback:(void(^_Nullable)(NSString *_Nonnull, NSUInteger))callback;

- (BOOL)approveJoinRequest:(ZMMessageAdapter *)message
            resultCallback:(void (^_Nullable)(UInt32 xmppResult, UInt32 joinBlockReason))resultCallback;

- (BOOL)declineJoinRequest:(ZMMessageAdapter *)message
            resultCallback:(void (^_Nullable)(UInt32 xmppResult))resultCallback;

- (void)openSessionID:(NSString *)sessionID jumpAction:(void (^)(NSString *sessionId))jumpAction;
- (void)openMessage:(NSString *)messageID sessionID:(NSString *)sessionID serverTime:(unsigned long long)serverTime;
- (void)openMessage:(NSString *)messageID sessionID:(NSString *)sessionID serverTime:(unsigned long long)serverTime jumpAction:(void (^)(NSString *sessionId))jumpAction;
- (void)openSession:(NSString *)sessionID;

- (void)directJoinSubCMC:(NSString *)subCMCSessionId;

- (BOOL)openEmail:(NSString *)email;
- (void)getInviteLinkForSessionId:(NSString *)sessionId callback:(void(^)(NSString *_Nullable))callback;
- (void)resetInviteLinkForChannel:(NSString *)sessionId;

- (BOOL)shouldShowShareLinkModalOnboardingForChannel:(NSString *)sessionId;
- (void)didShowShareLinkModalOnboarding;

- (void)makeMyDirectChatLinkWithCallback:(void(^_Nullable)(NSString *_Nonnull, NSUInteger))callback;

@end

#ifndef ZMShareDeepLinkProtocol
#define ZMShareDeepLinkProtocol (id<ZMDeepLinkProtocol>)ZMSharedFor(ZMDeepLinkProtocol)
#endif

NS_ASSUME_NONNULL_END

// Multi-process split: the ChatUI-free judgement/info subset (ZMShareDeepLinkLocal) and the
// Meeting -> PT navigation facade (ZMDeepLinkRoute) are made available wherever the deep-link
// protocol is imported, so meeting-side call sites need no extra imports.
#import <zChatBase/ZMDeepLinkLocalProtocol.h>
#import <zChatBase/ZMDeepLinkRoute.h>

#endif /* ZMDeepLinkProtocol_h */

