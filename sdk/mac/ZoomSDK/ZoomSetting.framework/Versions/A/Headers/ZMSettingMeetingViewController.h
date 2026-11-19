//
//  ZMSettingMeetingViewController.h
//  ZoomSetting
//
//  Created by Cooper.Chen on 2024/11/13.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMSettingItemViewController.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingMgr, ZPZAppHeader;

@interface ZMSettingMeetingViewController : ZMSettingItemViewController

- (void)showUnmuteAudioPrivacyView;
- (void)allowUnmuteAudioListChange;

#pragma mark - ZMZappInstanceEventsProtocol
- (void)updateZoomAppsWithDatas:(NSArray<ZPZAppHeader *> *)datas;
#ifdef __cplusplus
- (void)updateZoomAppsWithAutoOpenType:(NS_ZOOM_APPS::AutoOpenSettingType)showType forAppId:(NSString *)appId;
#endif

@end

NS_ASSUME_NONNULL_END
