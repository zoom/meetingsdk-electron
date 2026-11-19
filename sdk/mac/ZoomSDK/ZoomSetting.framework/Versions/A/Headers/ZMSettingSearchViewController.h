//
//  ZMSettingSearchViewController.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2025/7/7.
//  Copyright © 2025 Zoom. All rights reserved.
//
#import <zUIClient/setting_panel_search.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingSearchViewController : ZMBaseViewController
- (void)onSettingUIEvent:(void*)event;
- (instancetype)initWithOnSearchResult:(void(^)(const SearchResultItem&))onSearchResult;
@property (nonatomic, assign) BOOL hidden;
- (NSString *)getFocusResultItemId;
@end

NS_ASSUME_NONNULL_END
