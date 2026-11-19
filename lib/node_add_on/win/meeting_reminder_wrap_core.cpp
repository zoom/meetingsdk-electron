#include "meeting_reminder_wrap_core.h"
#include "sdk_wrap.h"
#include "meeting_service_components_wrap/meeting_reminder_ctrl_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingReminderWrap::ZMeetingReminderWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingReminderCtrlEvent.SetOwner(this);
	m_pSink = NULL;
}
ZMeetingReminderWrap::~ZMeetingReminderWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_meetingReminderCtrlEvent.SetOwner(NULL);
}
void ZMeetingReminderWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingReminderCtrlEvent);
}
void ZMeetingReminderWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().Uninit_Wrap();
}
void ZMeetingReminderWrap::SetSink(ZNativeSDKMeetingReminderWrapSink* pSink)
{
	m_pSink = pSink;
}
void ZMeetingReminderWrap::onReminderNotify(ZNMeetingReminderContent content)
{
	if (m_pSink)
	{
		m_pSink->onReminderNotify(content);
	}
}
void ZMeetingReminderWrap::onEnableReminderNotify(ZNMeetingReminderContent content)
{
	if (m_pSink)
	{
		m_pSink->onEnableReminderNotify(content);
	}
}
ZNSDKError ZMeetingReminderWrap::Ignore()
{
	return ZMeetingReminderHandler::GetInst().Ignore();
}
ZNSDKError ZMeetingReminderWrap::Accept()
{
	return ZMeetingReminderHandler::GetInst().Accept();
}
ZNSDKError ZMeetingReminderWrap::Decline()
{
	return ZMeetingReminderHandler::GetInst().Decline();
}

ZNSDKError ZMeetingReminderWrap::SetEnableOption(ZNFeatureEnableOption option)
{
	return ZMeetingEnableReminderHandler::GetInst().SetEnableOption(option);
}
ZNSDKError ZMeetingReminderWrap::StartEnable()
{
	return ZMeetingEnableReminderHandler::GetInst().Start();
}
ZNSDKError ZMeetingReminderWrap::DeclineEnable(bool bDeclineAll)
{
	return ZMeetingEnableReminderHandler::GetInst().Decline(bDeclineAll);
}
ZNSDKError ZMeetingReminderWrap::IgnoreEnable()
{
	return ZMeetingEnableReminderHandler::GetInst().Ignore();
}
ZNSDKError ZMeetingReminderWrap::SetHideFeatureDisclaimers()
{
	return ZMeetingReminderHandler::GetInst().SetHideFeatureDisclaimers();
}
ZNSDKError ZMeetingReminderWrap::SetMultiReminderDisclaimerUIConfig(int left, int top, ZoomSTRING parentWindowHandle, unsigned long backgroundColor)
{
	ZOOM_SDK_NAMESPACE::MultiReminderUIConfig config;
	config.left = left;
	config.top = top;
	config.background_color = backgroundColor;
	if (!parentWindowHandle.empty())
	{
		try
		{
			unsigned long long sdk_parent_window_handle = std::stoull(parentWindowHandle, nullptr, 16);
			config.hParent = reinterpret_cast<HWND>(static_cast<UINT_PTR>(sdk_parent_window_handle));
		}
		catch (...)
		{
			return ZNSDKERR_INVALID_PARAMETER;
		}
	}
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().SetMultiReminderDisclaimerUIConfig(config);
	return ZNSDKERR_SUCCESS;
}
ZNSDKError ZMeetingReminderWrap::UpdateMultiReminderDisclaimerUI()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingReminderController().UpdateMultiReminderDisclaimerUI();
	return ZNSDKERR_SUCCESS;
}