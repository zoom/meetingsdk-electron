//
//  ZMSCConstants.h
//  ZMScreenshotKit
//
//  Created by Javenlee.Li on 2025/9/1.
//  Copyright © 2025 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

#define UIColorFromHex(hexValue, alphaValue) \
[NSColor colorWithRed:((hexValue >> 16) & 0xFF)/255.0 \
                green:((hexValue >> 8) & 0xFF)/255.0 \
                 blue:(hexValue & 0xFF)/255.0 \
                alpha:(alphaValue)]

#pragma mark - Capture Mode

typedef NS_ENUM(NSInteger, ZMCaptureMode) {
    ZMCaptureModeCapture,       // Screenshot annotation
    ZMCaptureModeRecordReady,   // Record mode selected, clear window, awaiting start
    ZMCaptureModeRecording,     // Actively recording screen
};

#pragma mark - Image Quality Level

typedef NS_ENUM(NSInteger, ZMImageQualityLevel) {
    ZMImageQualityLevelHigh,    // Original resolution, PNG lossless
    ZMImageQualityLevelMedium,  // Original resolution, JPEG quality 0.9
    ZMImageQualityLevelLow,     // 50% resolution, JPEG quality 0.8
    ZMImageQualityLevelAuto,    // Best quality that fits within maxImageBytes
};

#pragma mark - Recording Constants

FOUNDATION_EXPORT const NSTimeInterval ZMRecordingMaxDuration;           // max recording time (180 seconds)
FOUNDATION_EXPORT const NSTimeInterval ZMRecordingWarningThreshold;      // warning time (170 seconds)

#pragma mark - Notification Names

FOUNDATION_EXPORT NSNotificationName const ZMSCNeedsTranslationSettingsNotification;

NS_ASSUME_NONNULL_END
