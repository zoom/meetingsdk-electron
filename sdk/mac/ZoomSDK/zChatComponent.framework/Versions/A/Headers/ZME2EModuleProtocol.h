//
//  ZME2EModuleProtocol.h
//  zChatComponent
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZME2EModuleProtocol <NSObject>
@required
- (BOOL)isEditE2EMessageEnabledForSession:(NSString* _Nullable)sessionId;
@end

#ifndef ZMShareE2EModuleProtocol
#define ZMShareE2EModuleProtocol ((id <ZME2EModuleProtocol>)ZMSharedFor(ZME2EModuleProtocol))
#endif

NS_ASSUME_NONNULL_END
