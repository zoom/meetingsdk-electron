//
//  ZMSysEmojiItemView.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/16.
//

#import <Cocoa/Cocoa.h>
#import <zChatBase/ZMCustomEmojiView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMCenterVerticalLabel;

///This is NOT a new class, just move it form ZMSysEmojiMgr.

@interface ZMSysEmojiItemView : NSView

@property(nonatomic, assign) BOOL isHovered;
@property(nonatomic, assign) BOOL isCurrentSelected;
@property(nonatomic, strong) ZMEmojiModel *emoji;
@property(nonatomic, assign) NSInteger toneIndex;

/// Exposed so V2 subclasses can re-style the unicode glyph (e.g. bump to
/// 30/36pt for the V2 emoji panel) without resorting to KVC. The label is
/// lazily created — accessing the getter from outside instantiates it.
@property(nonatomic, strong, readonly) ZMCenterVerticalLabel *unicodeEmojiLabel;
/// Exposed so V2 subclasses can re-apply masonry constraints to the custom
/// emoji view (V1 hard-codes 23/30pt; V2 needs 30/36pt). Lazily created.
@property(nonatomic, strong, readonly) ZMCustomEmojiView *customEmojiView;

- (void)updateEmojiModel:(ZMEmojiModel *)emojiModel showMode:(ZMCustomEmojiShowMode)showMode;
- (void)downloadEmojiIfNeeded;

- (void)hideAllContents;
- (void)updateContentHidden;

@end

NS_ASSUME_NONNULL_END
