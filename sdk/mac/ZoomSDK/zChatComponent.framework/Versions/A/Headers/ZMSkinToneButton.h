//
//  ZMSkinToneButton.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/20.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMSkinToneButtonDelegate <NSObject>

- (void)skinToneButtonDidSetSkinTone:(NSUInteger)skinTone;

@end

@interface ZMSkinToneButton : NSView
@property (nonatomic, weak) id<ZMSkinToneButtonDelegate> delegate;

+ (NSInteger)expWidth;
+ (BOOL)isSupportSkinTone;
- (void)cleanUp;

/// The inner glyph button — the focusable "thumb up" node used to splice
/// the skin tone control into a host's keyboard key-view loop. Returns nil
/// when skin tone isn't supported (the button was never created).
- (nullable NSView *)keyboardFocusView;

/// V2-only restyle hook. The V1 init hard-codes a 12pt label font + grey
/// color + a frame derived from the 12pt string width; the V2 panel needs
/// a 14pt font with a different color and the label widened to fit. Calling
/// this method updates the inner label's font/color and resizes the field
/// to `labelWidth`, then re-positions the skin tone glyph button to follow.
/// Pass `nil` for `font`/`textColor` to keep the existing value, and a
/// non-positive `labelWidth` to leave the frame unchanged.
- (void)applyV2LabelStyleWithFont:(nullable NSFont *)font
                        textColor:(nullable NSColor *)textColor
                       labelWidth:(CGFloat)labelWidth;
@end


NS_ASSUME_NONNULL_END
