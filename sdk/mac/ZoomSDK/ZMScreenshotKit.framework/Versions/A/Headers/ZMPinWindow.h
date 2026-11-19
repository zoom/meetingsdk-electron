//
//  ZMPinWindow.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>
#import "ZMSCFeatureFlags.h"

#if ZM_FEATURE_AI
@class ZMSCAIResultPanelView;
@class ZMSCAIImageEditPanel;
#endif
@class ZMCaptureDocument;
@class ZMCanvasItem;

NS_ASSUME_NONNULL_BEGIN

@interface ZMPinWindow : NSPanel

- (nullable instancetype)initWithDocument:(ZMCaptureDocument *)document onScreen:(NSScreen *)screen screenRect:(NSRect)screenRect;

@property (nonatomic, strong, nullable) ZMCanvasItem *canvasItem;

#pragma mark - Context Menu Callbacks

/// Called when user selects "Add to Notebook" from the context menu.
/// Upper layers set this to wire up the Notebook business logic without coupling.
@property (nonatomic, copy, nullable) void (^addToTodoBlock)(ZMPinWindow *window);

/// Called when user selects "Delete" from the context menu.
/// If nil, the default close behaviour is used.
@property (nonatomic, copy, nullable) void (^deleteBlock)(ZMPinWindow *window);

#if ZM_FEATURE_AI
#pragma mark - AI Panel

@property (nonatomic, readonly, nullable) ZMSCAIResultPanelView *aiPanelView;
@property (nonatomic, readonly) BOOL aiPanelVisible;

- (void)showAIPanel;
- (void)hideAIPanel;

@property (nonatomic, readonly, nullable) ZMSCAIImageEditPanel *imageEditPanelView;
@property (nonatomic, readonly) BOOL imageEditPanelVisible;

- (void)showImageEditPanel;
- (void)hideImageEditPanel;
#endif

- (nullable NSData *)originalImageData;
- (void)replaceImageWithNewImage:(NSImage *)newImage;

/// Performs internal cleanup (toolbar, panels, content VC) without closing the window.
/// Called by the window manager before forcibly removing the window.
- (void)prepareForRemoval;

@end

NS_ASSUME_NONNULL_END
