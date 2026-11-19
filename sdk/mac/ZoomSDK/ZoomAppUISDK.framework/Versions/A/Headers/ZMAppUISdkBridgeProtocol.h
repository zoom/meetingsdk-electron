//
//  ZMAppSdkBridgeProtocol.h
//  ChatUI
//
//  Created by Peter Xu on 2021/9/17.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism.h>
#import <Cocoa/Cocoa.h>

@protocol ZMAppSdkBridgeProtocol <ZMRoutableObject>
- (void *)getZappCommonApi;
- (void *)getPTApi;
- (BOOL)isSupportZmdf:(NSString *)appId;
- (void)isSupportZmdf:(NSString *)appId
           completion:(void (^)(BOOL available, BOOL supported))completion;
- (void)couldJoinMeetingWithURL:(NSString *)url
                     completion:(void (^)(BOOL available, BOOL handled))completion;
- (void)showClientForceUpdateDialog;
- (void)showWebViewForceUpdateDialog:(NSString *)webVersion;
- (void *)getZAppModuleAPI;
- (void *)getPTZappAPI:(NSInteger)runningEnv;
- (void *)getZappJSRegister;
- (NSString *)webViewCacheIdentity;
@end

@protocol ZMAppSdkConfBridgeProtocol <ZMRoutableObject>
- (void *)getZappCommonApi;
- (void *)getConfApi;
- (void)isSupportZmdf:(NSString *)appId
           completion:(void (^)(BOOL available, BOOL supported))completion;
- (void)couldJoinMeetingWithURL:(NSString *)url
                     completion:(void (^)(BOOL available, BOOL handled))completion;
- (void)showClientForceUpdateDialog;
- (void)showWebViewForceUpdateDialog:(NSString *)webVersion;
- (void *)getZAppModuleAPI;
- (void *)getConfZappAPI;
- (NSString *)webViewCacheIdentity;
@end
