//
//  IZMPresenceMgr.h
//  PTUIBridge
//
//  Created by Cursor on 2025/1/30.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPTRouterCenter.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMPresenceMgr <ZMPTRoutableObject>

@property (readonly) BOOL isSDKScreenLocked;
@property (readonly) BOOL netWorkNotConnect;

- (void)onConnectReturn:(int)err;
- (void)notifyIMSDKLockScreenState:(BOOL)isScreenLocked;

@end

NS_ASSUME_NONNULL_END

