//
//  IZMZUISettingMgr.h
//  ZoomSetting
//
//  Created by Javenlee.Li on 11/10/25.
//

#ifndef IZMZUISettingMgr_h
#define IZMZUISettingMgr_h

#import "ZMSettingConstants.h"

@class ZMSettingItemController;

@protocol IZMZUISettingMgr <NSObject>

//ZUI tab
- (ZMSettingItemController *)itemSettingControllerFromZUIType:(int)zUITabType;
- (ZMSettingItemController *)itemSettingControllerFromTabID:(ZMSettingTabID)tabID;
- (void)itemViewWillAppear:(int)zUITabType;
- (void)itemViewWillDisappear:(int)zUITabType;

//Meeting tab
- (ZMSettingItemController *)itemSettingControllerFromMeetingType:(int)meetingType;
- (void)onSettingPageEnter:(int)meetingType;
- (void)onSettingPageLeave:(int)meetingType;

- (void)settingWillShow;
- (void)settingWillClose;

@end


#endif /* IZMZUISettingMgr_h */
