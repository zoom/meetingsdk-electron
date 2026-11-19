//
//  ZMIMScreenShotMgr.h
//  SaasBeePTUIModule
//
//  Created by john on 04/12/2017.
//  Copyright © 2017 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMScreenShotMgrProtocol.h>

#define zoomIdentifier @"us.zoom.xos"

@interface ZMIMScreenShotMgr : NSObject <ZMScreenshotConnectionProtocol, ZMIMScreenShotMgrProtocol>
{
    NSString*           _identifier;
    
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    NSConnection*       _connection;
#pragma clang diagnostic pop
    
    NSString *          _uuid;
}

/// Indicates whether a screenshot is currently being captured
@property (nonatomic, assign, readonly) BOOL capturingImage;

/// Indicates whether a video recording is currently in progress
@property (nonatomic, assign, readonly) BOOL capturingVideo;

+ (instancetype)shared;

- (void)cleanUp;

- (void)screenshotWithSystemApp;
- (void)screenshotRecordWithSystemApp;

/// current switch status
- (BOOL)hideChatWindow;

//will call startCaptureFromHotkey:ZMScreenshotTypeNoset
- (BOOL)startCaptureFromHotkey;

/// The following APIs (startCaptureFromHotkey, startCapture, startCaptureWithCallback:)
/// will make screenshot and check if need hidden zoom chat window from native setting
/// `[[NSUserDefaults standardUserDefaults] boolForKey:kCaptureWithoutChatWindow]`.
/// if type == ZMScreenshotTypeNoset will flow [[NSUserDefaults standardUserDefaults] boolForKey:kCaptureWithoutChatWindow]
/// if type == ZMScreenshotTypeWithZoomWindow, will not hide zoom window, ignore [[NSUserDefaults standardUserDefaults] boolForKey:kCaptureWithoutChatWindow]

- (BOOL)startCaptureFromHotkey:(ZMScreenshotType)type;
- (BOOL)startCaptureRecord;
- (BOOL)startCapture;
- (BOOL)startCaptureWithWindow;
- (BOOL)startCaptureWithCallback:(id <ZMScreenshotCallback>)callback;

/// this will make screenshot and check if need hidden zoom chat window with specific flag: hideChatWindow
- (BOOL)startCaptureWithCallback:(id <ZMScreenshotCallback>)callback hideChatWindow:(BOOL)hideChatWindow;
- (BOOL)startCaptureWithCallback:(id <ZMScreenshotCallback>)callback qualityLevel:(NSInteger)qualityLevel;

- (void)addDefaultCallback:(id <ZMScreenshotCallback>)callback;

- (void)removeCallback:(id <ZMScreenshotCallback>)callback;


@end
