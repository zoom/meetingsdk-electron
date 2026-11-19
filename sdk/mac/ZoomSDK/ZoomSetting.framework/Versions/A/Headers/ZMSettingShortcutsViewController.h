//
//  ZMSettingShortcutsViewController.h
//  ZoomSetting
//
//  Created by francis zhuo on 2019/2/21.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <ZoomSetting/ZMSettingItemViewController.h>

@class ZMSettingMgr;

@interface ZMSettingShortcutsViewController : ZMSettingItemViewController

- (void)didLogin;

- (void)didLogout;

- (void)cleanUp;
@end
