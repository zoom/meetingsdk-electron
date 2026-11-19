//
//  ZMSettingMgr+Private.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2025/1/27.
//

#import <ZoomSetting/ZMSettingMgr.h>

#define LeftViewWidth                   228.0f
#define WindowWidth                     800.0f
#define WindowHeight                    660.0f
#define LeftScrollViewWidth             210.0f
#define LeftScrollViewHeight            542.0f
#define TitleHeight                     45.0f
#define ContentHeight                   615.0f
#define RightScrollViewWidth            572.0f

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingItemViewController;

@interface ZMSettingMgr (Private)

@property (nonatomic, assign, readonly) CGFloat languageExtraWidth;
@property (nonatomic, weak, readonly) ZMSettingItemViewController *selectedItem;

- (void)quitSearching:(BOOL)clearSearchField;
- (BOOL)reloadTabs:(BOOL)forced;
- (ZMSettingItemViewController*)findTheShowingItem;
- (NSInteger)suitableWindowLevel;
- (void)upgradeVersion;
- (void)scheduleCheckingOcclusionState;
- (void)cancelCheckingOcclusionState;
- (void)selectionDidChangeFrom:(__kindof ZMSettingItemViewController*)previousSelectedItem
                           to:(__kindof ZMSettingItemViewController*)newSelectedItem;
- (void)settingexDidLoad;
- (void)windowWillActivate;
- (void)windowWillAppear;
- (void)windowDidAppear;
- (void)windowDidActivate;

@end

NS_ASSUME_NONNULL_END
