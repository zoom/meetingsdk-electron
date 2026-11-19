//
//  ZMSettingRecordingViewController.h
//  ZoomSetting
//
//  Created by Lester Gong on 2024/12/26.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMSettingItemViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingMgr;

@interface ZMSettingRecordingViewController : ZMSettingItemViewController

@property (nonatomic, assign, readonly, class, getter = isVisible) BOOL visible;

@end

NS_ASSUME_NONNULL_END
