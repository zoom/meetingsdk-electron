//
//  ZMEmojiCollectionViewHeader.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/18.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMEmojiCollectionViewHeader : ZMBaseView

@property (nonatomic, assign) BOOL forceDarkMode;

@property (nonatomic, copy) void (^rightActionBlock)(void);
@property (nonatomic, copy) void (^leftActionBlock)(void);

- (void)updateTitle:(NSString *)title;
- (void)updateLeftActionImage:(NSImage *)image toolTip:(NSString *)toolTip;
- (void)updateRightActionImage:(NSImage *)image toolTip:(NSString *)toolTip;

/// V2-only override: re-applies the title label's font and color so the
/// emoji panel V2 can render section headers in 12pt semibold with its
/// Figma-spec color (light/dark variants). Pass `nil` for either argument
/// to keep the existing value. The label is created lazily on first
/// `updateTitle:`, so callers must invoke this *after* the title is set.
- (void)applyTitleFont:(nullable NSFont *)font textColor:(nullable NSColor *)textColor;

@end

NS_ASSUME_NONNULL_END
