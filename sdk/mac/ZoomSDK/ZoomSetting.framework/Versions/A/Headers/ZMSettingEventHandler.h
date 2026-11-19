//
//  ZMSettingEventHandler.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2025/1/2.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <zUIClient/zui_new_setting_event.h>

@class ZMSettingEventHandleMgr;

class ZMSettingEventHandler: public CZUINewSettingEventHandler
{
public:
    void OnSettingUIEvent(ZUIClientSettingEventParam& evnet);
    __weak ZMSettingEventHandleMgr *_hanldeMgr;
};
