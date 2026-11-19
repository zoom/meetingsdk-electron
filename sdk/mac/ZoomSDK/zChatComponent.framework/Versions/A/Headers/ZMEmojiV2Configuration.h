//
//  ZMEmojiV2Configuration.h
//  zChatComponent
//

#import <Cocoa/Cocoa.h>

@class ZMEmojiModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZMEmojiV2FeedbackItem : NSObject

@property (nonatomic, copy) NSString *key;
@property (nonatomic, strong) NSImage *image;
@property (nonatomic, copy) NSString *displayName;

+ (instancetype)itemWithKey:(NSString *)key image:(NSImage *)image displayName:(NSString *)displayName;

@end

/// Bitmask describing which top-level tabs the V2 panel should expose.
/// Matches Figma's panel variants:
///   - Meeting frame (241:8654): `ZMEmojiV2VisibleTabAll` — Frequently
///     Used + Emoji + top tab bar visible. NO GIF tab — meeting
///     ReactionUI does not surface Giphy.
///   - Menu frame (241:8056): `ZMEmojiV2VisibleTabEmoji` only — top tab
///     bar hidden, search and content occupy the freed space.
///   - Chat frame: chat consumers can OR-in `ZMEmojiV2VisibleTabGif` to
///     surface the GIF tab (Giphy). The panel uses the existing
///     `ZMChatEmojiOperationDelegate.didSelectedGiyph:` callback to
///     notify the host — mirroring V1's contract — so chat input
///     controllers continue to receive GIF picks without code changes.
typedef NS_OPTIONS(NSUInteger, ZMEmojiV2VisibleTab) {
    ZMEmojiV2VisibleTabFrequentlyUsed = 1 << 0,
    ZMEmojiV2VisibleTabEmoji          = 1 << 1,
    ZMEmojiV2VisibleTabGif            = 1 << 2,
    ZMEmojiV2VisibleTabAll            = ZMEmojiV2VisibleTabFrequentlyUsed | ZMEmojiV2VisibleTabEmoji | ZMEmojiV2VisibleTabGif,
};

typedef NS_ENUM(NSInteger, ZMEmojiV2InteractionType) {
    ZMEmojiV2InteractionTypeAnimatedEmoji = 0,
    ZMEmojiV2InteractionTypeFrequentlyUsedEmoji,
    ZMEmojiV2InteractionTypePopularCustomEmoji,
    ZMEmojiV2InteractionTypeFeedback,
    ZMEmojiV2InteractionTypeEmojiTab,
    ZMEmojiV2InteractionTypeSkinTone,
};

typedef void (^ZMEmojiV2InteractionHandler)(ZMEmojiV2InteractionType type,
                                             NSString * _Nullable itemKey);

@interface ZMEmojiV2Configuration : NSObject

@property (nonatomic, copy, nullable) NSArray<ZMEmojiV2FeedbackItem *> *feedbackItems;
@property (nonatomic, copy, nullable) NSArray<ZMEmojiModel *> *zoomAnimatedEmojis;

/// Which top-level tabs are visible. Defaults to `ZMEmojiV2VisibleTabAll`.
/// When the mask resolves to a single tab, the top tab bar is hidden and
/// the panel collapses its top inset (per Figma node 241:8056).
@property (nonatomic, assign) ZMEmojiV2VisibleTab visibleTabs;

/// VoiceOver title for the window hosting the panel. The panel VC applies
/// this to its window's `accessibilityTitle` so VoiceOver announces e.g.
/// "Reactions, window" / "Emojis, window" instead of the generic host
/// chrome ("menu window"). Defaults to "Emojis" when nil/empty; meeting
/// ReactionUI sets "Reactions".
@property (nonatomic, copy, nullable) NSString *accessibilityTitle;

/// Compact 6-default-selected UI (`ZMEmojiUnicodeData.selectedEmojiStringArray`:
/// 👏 👍 😂 😯 ❤️ 🎉). When `YES`:
///   1. custom emoji is suppressed everywhere (Emoji tab + Frequently Used);
///   2. the Emoji tab hides search and the category bar, keeping the skin-tone bar;
///   3. Recently Used intersects with that 6-glyph set.
/// Distinct from meeting *reaction* Allowed Emojis (`ZMMTSysEmojiMgr.meetingAllowedEmojis`),
/// which filters the data source but keeps full panel chrome. Hosts must set this
/// flag themselves. Meeting hosts: chat selected-emoji AND no Allowed Emojis.
/// Defaults to `NO`.
@property (nonatomic, assign) BOOL restrictsTo6DefaultSelectedEmojis;

/// Optional host callback for typed panel interactions. `itemKey` is populated
/// only for feedback items; emoji content and custom emoji identifiers are
/// intentionally not exposed through this callback.
@property (nonatomic, copy, nullable) ZMEmojiV2InteractionHandler interactionHandler;

@end

NS_ASSUME_NONNULL_END
