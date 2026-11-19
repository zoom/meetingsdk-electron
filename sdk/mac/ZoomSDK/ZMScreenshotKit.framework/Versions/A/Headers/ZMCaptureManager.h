//
//  CaptureManager.h
//  ScreenCapture
//
//  Created by Sky on 2017/11/6.
//  Copyright © 2017 ZOOM. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMSCConstants.h"
#import "ZMSCFeatureFlags.h"
#import "ZMRecordingService.h"

typedef enum : NSUInteger {
    ZMScreenCaptureErrorCancelled,
} ZMScreenCaptureError;

@class ZMCaptureManager;

@protocol ZMCaptureManagerDelegate <NSObject>

@optional
- (void)captureDidSucceed:(NSData *)imageData;
- (void)captureDidSucceed:(NSData *)imageData withQualityLevel:(ZMImageQualityLevel)qualityLevel;
- (void)captureFailedWithError:(NSError *)error;
- (void)recordDidSucceed:(NSString *)filePath;
- (void)recordFailedWithError:(NSError *)error;
- (void)captureDidDownload:(NSData *)imageData;
- (void)captureDidPin;
- (void)captureDidAddToNote;

#if ZM_FEATURE_TA
/// TA mode: a window was confirmed via autoselect, OCR ran automatically, and the
/// full sample data is ready. `json` is the { "window", "ocr" } payload.
- (void)taCaptureDidSucceedWithImageData:(NSData *)imageData
                                    json:(NSString *)json;
- (void)taCaptureFailedWithError:(NSError *)error;
#endif

@end

@interface ZMCaptureManager : NSObject

@property (nonatomic, weak) id<ZMCaptureManagerDelegate> delegate;
@property (nonatomic, assign) ZMImageQualityLevel qualityLevel;
@property (nonatomic, assign) NSUInteger maxImageBytes;
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *excludeWindowIDs;

/// Optional pre-flight block called before the capture window appears.
/// Use this to perform Security.framework access (e.g., Keychain reads) that may
/// show a password dialog — those dialogs must be visible before the high-level
/// capture window is shown. Call `completion()` when the pre-flight is done.
/// If nil, capture starts immediately.
@property (nonatomic, copy, nullable) void (^preflightBlock)(void (^completion)(void));

#if ZM_FEATURE_TA
/// When YES, the next capture session runs as a TA (Test Automation) session:
/// autoselect-only, automatic OCR on confirm, and one-shot {imageData, windowInfo, ocrData} result.
@property (nonatomic, assign) BOOL taMode;
#endif

+ (instancetype)sharedManager;
- (void)startCapture:(BOOL)recordMode;
- (void)endCurrentSession;
- (void)handleDownloadCapture:(NSData *)imageData scaleFactor:(CGFloat)scaleFactor;

/// Cancels a recorder while replacing a capture session. This is intentionally
/// separate from user cancellation: it only owns the recorder until its async
/// cleanup callback, and does not notify the capture delegate or terminate.
- (void)cancelRecordingServiceForSessionReplacement:(id<ZMRecordingServicing>)recordingService;

/// Cancels a recorder for an explicit user cancellation. The manager retains
/// the recorder until its completion, then completes the pending termination.
- (void)cancelRecordingServiceForSessionTermination:(id<ZMRecordingServicing>)recordingService;

/// Recording cancellation is asynchronous while the capture UI is torn down
/// immediately. The recording screen calls this right before closing the UI so the
/// manager (which outlives the per-screen window/controller) owns the pending
/// termination: it waits for `recordingCancelDidComplete` or a guard timeout, then
/// notifies the delegate so the process can quit.
- (void)beginWaitingForRecordingCancel;

/// Called when the asynchronous recording cancellation finished, so the manager can
/// finalize termination if it is still waiting.
- (void)recordingCancelDidComplete;

#if ZM_FEATURE_TA
/// Start an interactive TA capture session (autoselect only).
- (void)startTACapture;

/// Finish an interactive TA capture after the overlay has been closed: prompt for a
/// dump path (PNG save panel), write the image, assemble the { window, image, ocr }
/// JSON, and notify the delegate (taCaptureDidSucceed.../taCaptureFailed...).
- (void)taConfirmCaptureWithImageData:(NSData *)imageData
                           windowInfo:(NSDictionary *)windowInfo
                              ocrData:(NSArray *)ocrData;

/// Re-acquire the same window's data (image + OCR) without any UI, locating the
/// window by the "window" identity object { id, idSource, owner } carried in
/// `windowInfo`. The captured image is dumped to `dumpPath` (a .png file path, or a
/// directory in which case an auto name is used; nil falls back to a default dir).
/// `json` in the completion is the { "window", "image", "ocr" } payload.
/// Used to compare manual vs automatic results for consistency.
- (void)taQueryWithWindowInfo:(NSDictionary *)windowInfo
                     dumpPath:(nullable NSString *)dumpPath
                   completion:(void (^)(NSData * _Nullable imageData,
                                        NSString * _Nullable json,
                                        NSError * _Nullable error))completion;
#endif

@end
