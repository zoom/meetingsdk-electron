//
//  ZMIMInputCustomButtonMgrProtocol.h
//  zChatBase
//
//  Moved from zChatComponent to zChatBase to avoid cyclic module deps.
//

#ifndef ZMIMInputCustomButtonMgrProtocol_h
#define ZMIMInputCustomButtonMgrProtocol_h

#import <Foundation/Foundation.h>
#import <Prism/ZMRouterCenterProtocols.h>
#import <zChatBase/ZMIMCommonDefine.h>

@class ZMIMInputCustomButtonItem;
@class ZMChatAppInfo;

@protocol ZMIMInputCustomButtonMgrProtocol <NSObject>

- (nullable NSArray<ZMIMInputCustomButtonItem*> *)getCustomizedComposeShortcutsWithSessionId:(nullable NSString *)sessionId;

- (nullable ZMChatAppInfo*)getChatAppInfoFromAppJID:(nonnull NSString *)appJID sessionId:(nullable NSString *)sessionId;

- (BOOL)updateCustomizedComposeShortcutsConfig:(nullable NSArray<ZMIMInputCustomButtonItem*> *)customizedShortsItems;

- (BOOL)resetCustomizedComposeShortcutsConfig;

@end

#ifndef ZMShareInputCustomButtonMgrProtocol
#define ZMShareInputCustomButtonMgrProtocol (id<ZMIMInputCustomButtonMgrProtocol>)ZMSharedFor(ZMIMInputCustomButtonMgrProtocol)
#endif

#endif /* ZMIMInputCustomButtonMgrProtocol_h */
