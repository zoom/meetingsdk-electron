//
//  ZMMTNavigationTheme.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2026/7/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTNavigationTheme : NSObject
@property(strong) ZMPigment* bar;
@property(strong) ZMPigment* normalItem;
@property(strong) ZMPigment* hoverItem;
@property(strong) ZMPigment* selectedItem;

+ (instancetype)themeForName:(ZMThemeName)name;
- (void)setTheme:(ZMMTNavigationTheme*)theme;
@end

NS_ASSUME_NONNULL_END
