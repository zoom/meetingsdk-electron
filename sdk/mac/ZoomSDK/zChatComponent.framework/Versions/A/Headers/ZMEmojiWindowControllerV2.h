//
//  ZMEmojiWindowControllerV2.h
//  zChatComponent
//

#import <Cocoa/Cocoa.h>

@class ZMEmojiV2Configuration;
@class ZMEmojiV2PanelViewController;
@class ZMSysEmojiMgr;
@protocol ZMChatEmojiOperationDelegate;

NS_ASSUME_NONNULL_BEGIN

/// Standalone-window host for the V2 emoji panel. Internally instantiates
/// a `ZMEmojiV2PanelViewController` and embeds it in a
/// `ZMEmojiV2PanelWindow`. This controller handles only window-scoped
/// concerns: position, outside-click dismiss, ESC dismiss, auto-close
/// timer. All UI and selection logic lives in the VC.
///
/// To embed the panel inside an existing window instead of using this
/// floating-panel host, instantiate `ZMEmojiV2PanelViewController`
/// directly and attach `vc.view` to your container.
@interface ZMEmojiWindowControllerV2 : NSWindowController

@property (nonatomic, weak) id<ZMChatEmojiOperationDelegate> delegate;
@property (nonatomic, strong, readonly) ZMSysEmojiMgr *sysEmojiMgr;

/// The underlying content VC. Exposed so callers can reach the
/// configuration / emoji mgr without poking at the window controller.
@property (nonatomic, strong, readonly) ZMEmojiV2PanelViewController *panelViewController;

- (instancetype)initWithConfiguration:(ZMEmojiV2Configuration *)configuration;
- (instancetype)initWithConfiguration:(ZMEmojiV2Configuration *)configuration emojiMgr:(nullable ZMSysEmojiMgr *)emojiMgr;

- (void)showWithPositionView:(NSView *)positionView;
- (void)showWithPositionView:(NSView *)positionView rect:(NSRect)rect;
- (void)dismiss;
- (void)schedule2CloseEmojiWnd;
- (void)cancel2CloseEmojiWnd;

@end

NS_ASSUME_NONNULL_END
