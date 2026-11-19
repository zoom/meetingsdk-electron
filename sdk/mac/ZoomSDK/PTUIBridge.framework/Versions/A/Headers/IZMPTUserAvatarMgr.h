//
//  IZMPTUserAvatarMgr.h
//  PTUIBridge
//
//  Created by fistice on 7/25/25.
//

#ifndef IZMPTUserAvatarMgr_h
#define IZMPTUserAvatarMgr_h
#import <PTUIBridge/ZMPTRouterCenter.h>

@protocol IZMPTUserAvatarMgr <ZMPTRoutableObject>

- (NSString*)getUserName;
- (NSString*)getEmail;
- (BOOL)IMEnable;
- (BOOL)isIMChatEnabled;
- (BOOL)isAccountChatDisable;
- (int)getLoginType;
- (BOOL)isEnableShowPlansBilling;
- (void)onChatModuleInstalled;
@end

#endif /* IZMPTUserAvatarMgr_h */
