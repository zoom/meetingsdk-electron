//
//  ZMIMScreenShotMgrProtocol.h
//  zChatBase
//
//  Moved/Extracted from zChatComponent to decouple clients (e.g. zVideoUI)
//  from zChatComponent when only screenshot capability is needed.
//
//  Keep this header lightweight (no heavy UI imports).
//

#ifndef ZMIMScreenShotMgrProtocol_h
#define ZMIMScreenShotMgrProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMScreenshotCallback;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMScreenshotType) {
    ZMScreenshotTypeNoset,
    ZMScreenshotTypeWithZoomWindow,
};

@protocol ZMScreenshotConnectionProtocol <NSObject>

- (void)captureDidSucceed:(NSData *)imageData;
- (void)captureFailed;
- (void)captureDidDownload:(NSData *)imageData;

@optional
- (void)captureDidSucceed:(NSData *)imageData withQualityLevel:(NSInteger)qualityLevel;
- (void)recordDidSucceed:(NSString *)filePath;
- (void)recordFailed:(NSError *)error;
- (void)capturePinned;

/// Validate a shared IPC token. Returns YES if the token is accepted.
- (BOOL)validateIPCToken:(NSString *)token;

@end

@protocol ZMScreenshotAppProtocol <NSObject>
- (void)startNewCapture:(BOOL)recordMode;
@optional
- (void)startNewCapture:(BOOL)recordMode qualityLevel:(NSInteger)qualityLevel;
- (void)startNewCapture:(BOOL)recordMode qualityLevel:(NSInteger)qualityLevel excludeWindowIDs:(NSArray<NSNumber *> *)excludeWindowIDs;

/// Called by the main ZOOM client when the user switches accounts.
/// The screenshot process saves its state and terminates; the client
/// is expected to relaunch it with the new accountId.
- (void)terminateForAccountSwitch;

/// Authenticate the caller with a shared secret token.
/// Returns YES if the token matches the one received at launch.
- (BOOL)authenticateWithToken:(NSString *)token;
@end

@protocol ZMIMScreenShotMgrProtocol <NSObject>

/// Indicates whether a screenshot is currently being captured
@property (nonatomic, assign, readonly) BOOL capturingImage;

/// Indicates whether a video recording is currently in progress
@property (nonatomic, assign, readonly) BOOL capturingVideo;

- (void)cleanUp;

- (void)screenshotWithSystemApp;
- (void)screenshotRecordWithSystemApp;

/// Current switch status
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
- (BOOL)startCaptureWithCallback:(nullable id<ZMScreenshotCallback>)callback;

/// This will make screenshot and check if need hidden zoom chat window with specific flag: hideChatWindow
- (BOOL)startCaptureWithCallback:(nullable id<ZMScreenshotCallback>)callback hideChatWindow:(BOOL)hideChatWindow;
- (BOOL)startCaptureWithCallback:(nullable id<ZMScreenshotCallback>)callback qualityLevel:(NSInteger)qualityLevel;
- (BOOL)startCaptureWithCallback:(nullable id<ZMScreenshotCallback>)callback hideChatWindow:(BOOL)hideChatWindow qualityLevel:(NSInteger)qualityLevel;

- (void)addDefaultCallback:(id<ZMScreenshotCallback>)callback;
- (void)removeCallback:(id<ZMScreenshotCallback>)callback;

/// Terminate the screenshot subprocess when the ZOOM account switches.
/// The next screenshot launch will carry the new account context.
- (void)terminateScreenshotForAccountSwitch;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMIMScreenShotMgrProtocol_h */

