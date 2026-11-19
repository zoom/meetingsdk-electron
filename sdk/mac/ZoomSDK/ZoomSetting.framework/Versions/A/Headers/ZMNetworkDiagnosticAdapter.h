//
//  ZMPNetworkDiagnosticWindowMgr.h
//  ZoomSetting
//
//  Created by Cooper.Chen on 2022/9/22.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class ZMPureWindow;

NS_ASSUME_NONNULL_BEGIN

@interface ZMNetworkDiagnosticAdapter: NSObject

+ (instancetype)shared;

+ (void)setupNetworkDiagnostic;

+ (BOOL)diagnosticBundleInstalled;

- (void)loadDiagnosticEnviroment;

+ (BOOL)enableDiagnostic;

+ (void)notifyDiagnosticOnDemand;

+ (BOOL)diagnosticEnviromentReady;

+ (BOOL)onWebMessageRecieved:(NSString *)messageBody;

+ (BOOL)notifyTestMeeting;

+ (void)notifyTestCert:(NSString *)requestUrl;

+ (void)notifyOpenDataViewerTab;

+ (void)clearHistory;

+ (void)forceStopDiagnostic;

+(NSString *)diagnosticComponetsPath;

+ (NSString *)webSocketWhilteListJsStr;

@end

NS_ASSUME_NONNULL_END
