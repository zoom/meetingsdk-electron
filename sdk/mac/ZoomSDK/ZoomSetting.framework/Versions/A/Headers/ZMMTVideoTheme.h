//
//  ZMMTVideoTheme.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2024/2/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, ZMMTVideoSizeType) {
    ZMMTVideoSizeTypeSmall,
    ZMMTVideoSizeTypeNormal,
};
typedef NS_ENUM(NSInteger, ZMMTVideoCornerType){
    ZMMTVideoCornerType_Default,
    ZMMTVideoCornerType_NoCorner,
    ZMMTVideoCornerType_Outside,
};

@interface ZMMTVideoTheme : NSObject<ZMMTVideoTheme>
@property(nonatomic, assign) ZMMTVideoCornerType cornerType;
@property(nonatomic, assign) CGFloat cornerRadius;

@property(nonatomic, assign) CGFloat themeBorderWidth;
@property(nonatomic, strong) NSColor* themeBorder;
@property(nonatomic, assign) CGFloat activeBorderWidth;
@property(nonatomic, strong) NSColor* activeBorder;

@property(nonatomic, strong) NSColor* infoBackground;
/// Hover/press fill. Baked source-over of white 10% on `infoBackground` (#0D0D0D at 60%). Not used by name tag.
@property(nonatomic, strong) NSColor* infoHoverBackground;
@property(nonatomic, assign) CGFloat infoHeight;
@property(nonatomic, assign, readonly) CGFloat controlHeight;
@property(nonatomic, assign) CGFloat infoCornerRadius;
@property(nonatomic, assign) NSEdgeInsets infoEdgeMargin;
@property(nonatomic, assign) CGFloat infoSpacing;
@property(nonatomic, assign) NSEdgeInsets infoEdgePadding;

+ (instancetype)themeForName:(ZMThemeName)name size:(ZMMTVideoSizeType)size;

- (void)setTheme:(ZMMTVideoTheme*)theme;
@end

@interface ZMMTFloatPanelTheme : NSObject
@property(strong) ZMPigment* frame;
@property(assign) NSEdgeInsets videoEdgeGap;

+ (instancetype)themeForName:(ZMThemeName)name;
- (void)setTheme:(ZMMTFloatPanelTheme*)theme;
@end

@interface ZMMTMiniWindowTheme : NSObject
@property(strong) ZMPigment* frame;

+ (instancetype)themeForName:(ZMThemeName)name;
- (void)setTheme:(ZMMTMiniWindowTheme*)theme;
@end

@interface ZMMTTitlebarTheme : NSObject
@property(strong) ZMPigment* titlebar;
@property(strong) ZMPigment* videoTitlebar;
@property(strong) ZMPigment* headerInfo;

+ (instancetype)themeForName:(ZMThemeName)name;
- (void)setTheme:(ZMMTTitlebarTheme*)theme;
@end
NS_ASSUME_NONNULL_END
