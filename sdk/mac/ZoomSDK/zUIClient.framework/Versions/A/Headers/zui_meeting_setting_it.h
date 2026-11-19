#ifndef _ZUI_MEETING_SETTING_H_
#define _ZUI_MEETING_SETTING_H_

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

enum MeetingSettingType {
	kMainSettingPage = 0,
	kVideoEffects,
	kAudio,
	kDisplayControl,
	kRecording,
	kShareScreen,
	kStatistics,
	kAccessibility,
	kRooms,
	kSubPageDisplay,
	kSubPageControls,
	kSubPageMyVideo,
	kSubPageParticipantVideo,
	kSubPageReactions,
	kSubPageChat,
	kLanguage,
	kSubPageLanguageAdvanced
};

class IZUIMeetingSettingSink {
public:
	virtual ~IZUIMeetingSettingSink() = default;

	virtual void OnSettingTypeChange(MeetingSettingType type) {};

	virtual void OnSettingPageLeave(MeetingSettingType from_type) {};

	virtual void OnSettingPageEnter(MeetingSettingType to_type) {};

	virtual void OnClose() {};
};

class ZUIClient_API IZUIMeetingSettingMgr
{
public:

	virtual ~IZUIMeetingSettingMgr() = default;

	virtual void InitDataState() = 0;

	virtual void SetMeetingSettingType(MeetingSettingType setting_type) = 0;
	
	virtual std::shared_ptr<zui::View> GetMeetingSettingView() = 0;

	virtual void SetPanelDockState(bool is_docked) = 0;

	virtual void SetSink(IZUIMeetingSettingSink* sink) = 0;

	virtual void SetNativeVideoView(void* view) = 0;

	virtual MeetingSettingType GetCurrentPageType() = 0;

	virtual void RefreshAudioOnlyMeetingState() {}
};

#endif
