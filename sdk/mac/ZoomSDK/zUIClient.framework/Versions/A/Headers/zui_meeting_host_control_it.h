#ifndef _ZUI_MEETING_HOST_CONTROL_H_
#define _ZUI_MEETING_HOST_CONTROL_H_

#ifdef _WIN32
#include "zUI/view.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "zUI_stdafx.h"
#endif

enum HostControlSettingType {
	kHostControlMainSettingPage,
	kAdvanced,
	kSubPageShare,
	kSubPageCaptions,
	kSubPageApps,
	kSubPageAiCompanion,
	kSubPageMyNotes,
	kSubPageRecording
};

class IZUIMeetingHostControlSink {
public:
	virtual ~IZUIMeetingHostControlSink() = default;

	virtual void OnSettingTypeChange(HostControlSettingType type) {};

	virtual void OnClose() {};
	
	virtual void OnPopInOut() {};
};


class ZUIClient_API IZUIMeetingHostControlMgr
{
public:
	virtual ~IZUIMeetingHostControlMgr() = default;

	virtual void InitDataState() = 0;

	virtual void SetHostControlSettingType(HostControlSettingType setting_type) = 0;

	virtual void SetPopInOutBtnVisible(bool visble) = 0;

	virtual void SetPanelDockState(bool is_docked) = 0;

	virtual std::shared_ptr<zui::View> GetHostControlView() = 0;

	virtual void SetSink(IZUIMeetingHostControlSink* sink) = 0;

	virtual HostControlSettingType GetCurrentPageType() = 0;
};

#endif