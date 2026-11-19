//
//  ZMEmojiV2PanelViewController.h
//  zChatComponent
//

#import <Cocoa/Cocoa.h>

@class ZMEmojiV2Configuration;
@class ZMSysEmojiMgr;
@protocol ZMChatEmojiOperationDelegate;

NS_ASSUME_NONNULL_BEGIN

/// Self-contained V2 emoji panel content. Owns every subview on the
/// Figma panel (top tab bar, shared search bar, Frequently Used / Emoji /
/// GIF tabs, skin tone bar) plus all delegate plumbing and the
/// `ZMSysEmojiMgr` / `ZMGiphyMgr` shared between them.
///
/// Two supported hosting modes:
///
/// 1. **Standalone panel window** — use `ZMEmojiWindowControllerV2`
///    which wraps this VC in a `ZMEmojiV2PanelWindow`, positions it
///    against a source view, and handles outside-click / ESC dismiss.
///    Existing meeting ReactionUI and chat callers use this mode.
///
/// 2. **Embedded subview** — instantiate the VC directly, attach
///    `vc.view` into any existing window's view hierarchy, install a
///    `dismissHandler` block, and call
///    `prepareForPresentationWithDarkAppearance:` once before the view
///    becomes visible. The VC has no opinion about its container — no
///    window placement, no global event monitor, no auto-close timer.
///    The host owns those.
///
/// The VC's `view` is sized at `+panelSize` (312×476) by default. Hosts
/// in embed mode may resize it freely; the inner layout uses fixed
/// pixel offsets matching the Figma spec and is NOT autoresizing.
@interface ZMEmojiV2PanelViewController : NSViewController

@property (nonatomic, weak, nullable) id<ZMChatEmojiOperationDelegate> delegate;
@property (nonatomic, strong, readonly) ZMSysEmojiMgr *sysEmojiMgr;
@property (nonatomic, strong, readonly) ZMEmojiV2Configuration *configuration;

/// Invoked after the user picks an emoji / GIF / animated emoji / feedback,
/// i.e. whenever the panel would self-dismiss. Hosts use this to close
/// whatever container they put the VC in (window, popover, inline
/// container view). Optional in embed mode; not called by the VC itself
/// for the standalone window mode (`ZMEmojiWindowControllerV2` doesn't
/// install one and instead calls its own `dismiss` from delegate methods).
@property (nonatomic, copy, nullable) void (^dismissHandler)(void);

/// Canonical panel size baked into the Figma spec. Hosts in embed mode
/// should use this to size the slot they're putting `view` into.
@property (class, nonatomic, readonly) CGSize panelSize;

/// The panel's preferred height for the *currently active* tab. Equals
/// `panelSize.height` for every tab except the Emoji tab while in
/// selected-emoji mode, where the grid collapses to a single row and the
/// panel only needs room for the tab bar + that row + the skin-tone bar.
/// Hosts read this once after construction to size their slot before the
/// view is shown.
@property (nonatomic, readonly) CGFloat preferredPanelHeight;

/// Fired whenever `preferredPanelHeight` changes (currently only when
/// entering/leaving the Emoji tab in selected-emoji mode). Embed-mode hosts
/// use this to resize their slot and the enclosing menu window. Never fired
/// for the standalone window mode.
@property (nonatomic, copy, nullable) void (^preferredHeightChangeHandler)(CGFloat preferredHeight);

- (instancetype)initWithConfiguration:(ZMEmojiV2Configuration *)configuration;
- (instancetype)initWithConfiguration:(ZMEmojiV2Configuration *)configuration
                             emojiMgr:(nullable ZMSysEmojiMgr *)emojiMgr NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithNibName:(nullable NSNibName)nibNameOrNil
                         bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

/// Call once right before the view becomes visible. Forwards the
/// appearance to every child view that has a force-dark-mode hook,
/// kicks the Giphy hot-list fetch (if the GIF tab is enabled), and
/// refreshes the active tab.
///
/// Idempotent — the Giphy mgr short-circuits when the hot list is
/// already warm.
- (void)prepareForPresentationWithDarkAppearance:(BOOL)darkAppearance;

@end

NS_ASSUME_NONNULL_END
