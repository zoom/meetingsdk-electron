//
//  ZMVEVideoPreviewController.h
//  ZoomSetting
//
//  Created by vinson.wang on 2025/12/12.
//

#import "ZMVideoPreviewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMVEVideoPreviewController : ZMVideoPreviewController

- (void)updateView;

@end

@interface ZMVEVideoPreviewController (MeetingSDK)

@property (nonatomic, strong, readonly) ZMBaseView *pickColorBgView;

- (void)setVBColorSelectMode:(BOOL)VBColorSelectMode;
- (void)updatePickColorView;
- (void)endSelectReplaceVBColorWithPoint:(NSPoint)point;

@end

NS_ASSUME_NONNULL_END
