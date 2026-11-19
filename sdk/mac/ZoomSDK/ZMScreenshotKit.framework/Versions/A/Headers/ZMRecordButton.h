//
//  ZMRecordButton.h
//  ZMScreenshotKit
//
//  Created by Javenlee.Li on 2025/9/1.
//  Copyright © 2025 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMCaptureButton.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMRecordButtonState) {
    ZMRecordButtonStateIdle,
    ZMRecordButtonStateRecording,
    ZMRecordButtonStatePaused,
    ZMRecordButtonStateStopped,
    ZMRecordButtonStateWarning
};

@interface ZMRecordButton : ZMBackgroundButton

@property (nonatomic, assign) ZMRecordButtonState recordState;
@property (nonatomic, assign) NSTimeInterval recordingDuration;
@property (nonatomic, assign) BOOL isAnimating;

- (void)setRecordingState:(ZMRecordButtonState)state;
- (void)updateRecordingTime:(NSTimeInterval)duration;
- (void)resetToIdleState;

- (void)updateWithRecordingState:(NSUInteger)recordingState;
- (void)updateWithRecordingState:(NSUInteger)recordingState duration:(NSTimeInterval)duration;

- (void)startWarningAnimation;
- (void)stopWarningAnimation;

@end

NS_ASSUME_NONNULL_END
