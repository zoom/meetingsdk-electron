#include "meeting_reminder_ctrl_wrap.h"
#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingReminderController* InitIMeetingReminderControllerFunc(IMeetingReminderEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingReminderController* pObj = pOwner->GetSDKObj()->GetMeetingReminderController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingReminderControllerFunc(IMeetingReminderController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

#if defined(WIN32)
//virtual void SetMultiReminderDisclaimerUIConfig(MultiReminderUIConfig config) = 0;
IMPL_FUNC_NORET_1(IMeetingReminderController, SetMultiReminderDisclaimerUIConfig, void, MultiReminderUIConfig, config)
//virtual void UpdateMultiReminderDisclaimerUI() = 0;
IMPL_FUNC_NORET_0(IMeetingReminderController, UpdateMultiReminderDisclaimerUI, void)
#endif

END_ZOOM_SDK_NAMESPACE