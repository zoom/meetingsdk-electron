//
//  ZMVideoPreviewController.h
//  ZoomSetting
//
//  Created by vinson.wang on 2025/12/12.
//

#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMConfSession;

@interface ZMVideoPreviewController : ZMBaseViewController

@property (nonatomic, strong, readonly) ZMBaseView *videoPreview;
@property (nonatomic, assign) BOOL previewing;
@property (nonatomic, strong, readonly) ZMConfSession *confSession; // Keep same session to destroy render properly

// Subclasses can override this method to initialize subviews
- (void)initSubviews;

// Subclasses can override this method to perform custom updates (called when previewing state changes)
- (void)updateView;

@end

NS_ASSUME_NONNULL_END
