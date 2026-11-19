//
//  ZMSettingVirtualViewController.h
//  ZoomSetting
//
//  Created by Vinson Wang on 2024/5/21.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <ZoomSetting/ZMSettingItemViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingMgr;

@interface ZMSettingVirtualViewController : ZMSettingItemViewController

@property (nonatomic, assign, readonly, class, getter = isVisible) BOOL visible;

- (void)showVB;

- (void)showFilters;

- (void)showAvatar;

- (void)showVirtualEffects;

- (void)stopPreview;

- (void)onSearchSelect:(NSString*)searchableKey;

@end

NS_ASSUME_NONNULL_END
