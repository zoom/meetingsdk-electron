//
//  ZMScreenRecorder.h
//  ZMScreenshotKit
//
//  Created by Javenlee.Li on 2025/9/1.
//  Copyright © 2025 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMRecordingState) {
    ZMRecordingStateIdle,
    ZMRecordingStateRecording,
    ZMRecordingStatePaused,
    ZMRecordingStateStopped
};

@protocol ZMScreenRecorderDelegate <NSObject>
@optional
- (void)screenRecorder:(id)recorder didStartRecording:(BOOL)success error:(nullable NSError *)error;
- (void)screenRecorder:(id)recorder didFinishRecording:(NSURL *)outputURL error:(nullable NSError *)error;
- (void)screenRecorder:(id)recorder recordingProgressUpdate:(NSTimeInterval)duration;
- (void)screenRecorder:(id)recorder recordingStateUpdate:(ZMRecordingState)state;
@end

typedef NS_ENUM(NSUInteger, ZMRecordOutputFormatObjC) {
    ZMRecordOutputFormatMP4 = 0,
    ZMRecordOutputFormatGIF = 1
};

@interface ZMRecordConfig : NSObject

@property (nonatomic, assign) BOOL includeAudio;
@property (nonatomic, assign) BOOL showCursor;
@property (nonatomic, assign) CGDirectDisplayID displayID;

@property (nonatomic, assign) CGRect cropRect;
@property (nonatomic, assign) CGFloat scaleFactor;
@property (nonatomic, assign) NSUInteger frameRate; // default 30fps
@property (nonatomic, assign) NSUInteger quality; // 0-10, default 8
@property (nonatomic, strong) NSURL *outputURL;
@property (nonatomic, assign) ZMRecordOutputFormatObjC outputFormat;
@end

@interface ZMScreenRecorder : NSObject

@property (nonatomic, weak) id<ZMScreenRecorderDelegate> delegate;
@property (nonatomic, readonly) ZMRecordingState recordingState;
@property (nonatomic, readonly) NSTimeInterval currentDuration;

- (BOOL)startRecordingWithConfig:(ZMRecordConfig *)config error:(NSError **)error;
- (void)stopRecording;
- (void)pauseRecording;
- (void)resumeRecording;
- (void)cancelRecordingAndDeleteFile;

+ (NSURL *)defaultOutputURL;
+ (NSURL *)defaultGIFOutputURL;
+ (NSString *)recordingDirectory;
+ (BOOL)ensureRecordingDirectoryExists;
+ (BOOL)checkRecordingPermission;
+ (void)requestRecordingPermission:(void(^)(BOOL granted))completion;

@end

NS_ASSUME_NONNULL_END
