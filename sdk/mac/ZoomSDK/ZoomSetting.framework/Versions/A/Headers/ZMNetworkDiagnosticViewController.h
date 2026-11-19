//
//  ZMNetworkDiagnosticViewController.h
//  ZoomSetting
//
//  Created by Ethan Wu on 2024/10/18.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("hidden")))
@interface ZMNetworkDiagnosticViewController : NSViewController

- (void)initWebview;
- (void)vcForceStopDiagnostic;
- (void)postDiagnosticMessageToWebview:(NSString*)messageStr;
- (void)showFileExplorer:(NSString*)pathStr;
- (NSString*)getWebViewGuid;
#if defined(BUILD_FOR_DOGFOOD) || ( !defined(__ZOOM_NO_CLIENT_LOG) && !defined(ZOOM_TROUBLESHOOT) )
+ (void)profilerOpenDiagnosticWindow;
#endif

@end

NS_ASSUME_NONNULL_END
