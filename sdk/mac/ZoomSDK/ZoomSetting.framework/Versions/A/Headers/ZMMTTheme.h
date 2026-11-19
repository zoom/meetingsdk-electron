//
//  ZMMTTheme.h
//  VideoUI
//
//  Created by Francis Zhuo on 2024/1/6.
//  Copyright © 2024 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMMTSidePanelTheme.h>
#import <ZoomSetting/ZMMTToolbarTheme.h>
#import <ZoomSetting/ZMMTVideoTheme.h>
#import <ZoomSetting/ZMMTNavigationTheme.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMMTPopoutTheme;
@interface ZMMTTheme : NSObject
@property(nonatomic, strong) ZMPigment* windowFrame;
@property(nonatomic, strong) ZMPigment* videoFrame;
@property(nonatomic, strong) ZMPigment* bottomFrame;
@property(nonatomic, assign) NSEdgeInsets videoFramePadding;

@property(nonatomic, strong) ZMMTTitlebarTheme* titlebarTheme;

@property(nonatomic, strong) ZMMTNavigationTheme* navigation;

@property(nonatomic, strong) ZMMTPopoutTheme *popout;

@property(nonatomic, strong) ZMMTVideoTheme* videoTheme;
@property(nonatomic, strong) ZMMTVideoTheme* smallVideoTheme;
@property(nonatomic, strong) ZMMTSidePanelTheme *sidePanelTheme;
@property(nonatomic, strong) ZMMTToolbarTheme* toolbarTheme;
@property(nonatomic, strong) ZMMTPresenterToolbarTheme* presenterToolbarTheme;

@property(nonatomic, strong) ZMMTFloatPanelTheme* floatPanelTheme;
@property(nonatomic, strong) ZMMTMiniWindowTheme* miniWindowTheme;
@property(assign, readonly) ZMThemeName name;

+ (ZMMTTheme*)display;

+ (void)setThemeWithName:(ZMThemeName)name;
+ (void)lockThemeWithName:(ZMThemeName)name;
+ (void)unlockTheme;
+ (instancetype)themeForName:(ZMThemeName)name;

/// The Classic video-container surface color (light #F1F4F6 / dark #050505). Shared by the
/// video frame/titlebar and the selected-tab background so the selected tab stays visually
/// merged with the content behind it.
+ (NSColor*)videoContainerColor;

+ (NSColor*)classicColor;
+ (NSColor*)bloomColor;
+ (NSColor*)agaveColor;
+ (NSColor*)roseColor;
@end

NS_ASSUME_NONNULL_END
