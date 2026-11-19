//
//  ZMCaptureViewController.h
//  ZMScreenshotKit
//
//  Created by Javenlee.Li on 2024/8/6.
//  Copyright © 2024 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMSCImageModel.h"
#import "ZMSCConstants.h"
#import "ZMSCFeatureFlags.h"

@class ZMCaptureDocument;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMCaptureViewDelegate <NSObject>
@optional
- (void)captureFinish:(NSData *)imageData;
- (void)downloadCapture:(NSData *)imageData;
- (void)showCaptureToolPalette:(NSViewController *)viewCtrl;
- (void)captureCancel;
- (void)pinCaptureWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (void)noteCaptureWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (void)aiAnalyzeCaptureWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (void)aiImageEditCaptureWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (NSString *)captureTitle;

// record
- (void)recordingDidStart:(BOOL)success error:(NSError *)error;
- (void)recordingDidFinish:(NSURL *)outputURL error:(NSError *)error;
- (void)recordingProgressUpdate:(NSTimeInterval)duration;
- (void)recordingDidCancel;

#if ZM_FEATURE_TA
// TA mode: window confirmed via autoselect, OCR already done. The delegate is
// expected to close the capture overlay first (like the download flow), then ask
// for the dump path and assemble/report the result.
- (void)taCaptureConfirmWithImageData:(NSData *)imageData
                           windowInfo:(NSDictionary *)windowInfo
                              ocrData:(NSArray *)ocrData;
- (void)taCaptureFailWithError:(NSError *)error;
#endif

- (void)closeAllWindows;
@end

@interface ZMCaptureViewController : NSViewController

@property (nonatomic, assign, readonly) ZMCaptureMode       currentMode;
@property (nonatomic, assign, readonly) BOOL                isRecording;
@property (nonatomic, assign) BOOL                           drawSelectInfo;
#if ZM_FEATURE_TA
@property (nonatomic, assign) BOOL                           taMode;
#endif
@property (nonatomic, strong) NSMutableArray                *windowInfo;
@property (nonatomic, weak, nullable) id <ZMCaptureViewDelegate>     delegate;
- (instancetype)initWithModel:(ZMSCImageModel *)model;
- (void)transitionToMode:(ZMCaptureMode)mode;
- (void)startCaptureModel;
- (void)cancelCapture;
- (NSData *)getSelectedCaptureImage;
- (NSData *)getSelectedCaptureImageWithQuality:(ZMImageQualityLevel)qualityLevel;
- (void)closePopup;
- (void)cleanUp;
@end

NS_ASSUME_NONNULL_END
