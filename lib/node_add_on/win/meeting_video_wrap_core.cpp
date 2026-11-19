#include "meeting_video_wrap_core.h"
#include "sdk_wrap.h"
#include "meeting_service_components_wrap/meeting_video_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingVideoWrap::ZMeetingVideoWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingVideoWrap::~ZMeetingVideoWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingVideoWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent);
}
void ZMeetingVideoWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Uninit_Wrap();
}
void ZMeetingVideoWrap::SetSink(ZNativeSDKMeetingVideoWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingVideoWrap::MuteVideo(unsigned int userId)
{
	bool zn_is_myself = false;
	ZOOM_SDK_NAMESPACE::IUserInfo* userinfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetUserByUserID(userId);
	if (userinfo)
	{
		zn_is_myself = userinfo->IsMySelf();
	}
		
	if (userId != 0 && !zn_is_myself)
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().StopAttendeeVideo(userId));
	}
	else
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().MuteVideo());
	}
}
ZNSDKError ZMeetingVideoWrap::UnMuteVideo(unsigned int userId)
{
	bool zn_is_myself = false;
	ZOOM_SDK_NAMESPACE::IUserInfo* userinfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetUserByUserID(userId);
	if (userinfo)
	{
		zn_is_myself = userinfo->IsMySelf();
	}
	if (userId != 0 && !zn_is_myself)
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().AskAttendeeToStartVideo(userId));
	}
	else
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnmuteVideo());
	}
	
}
ZNSDKError ZMeetingVideoWrap::CanPinToFirstView(unsigned int userId, ZNPinResult& result)
{
	result = ZN_PinResult_Unknown;
	ZOOM_SDK_NAMESPACE::PinResult nativeResult = ZOOM_SDK_NAMESPACE::PinResult_Unknown;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().CanPinToFirstView(userId, nativeResult));
	result = (ZNPinResult)nativeResult;
	return err;
}
ZNSDKError ZMeetingVideoWrap::PinVideoToFirstView(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().PinVideoToFirstView(userId));
}
ZNSDKError ZMeetingVideoWrap::UnPinAllVideosFromFirstView()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnPinAllVideosFromFirstView());
}
ZNList<unsigned int> ZMeetingVideoWrap::GetPinnedUserListFromFirstView()
{
	ZNList<unsigned int> zn_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int>* pList = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().GetPinnedUserListFromFirstView();
	if (pList)
	{
		for (int i = 0; i < pList->GetCount(); i++)
		{
			zn_list.push_back(pList->GetItem(i));
		}
	}
	return zn_list;
}
ZNSDKError ZMeetingVideoWrap::CanPinToSecondView(unsigned int userId, ZNPinResult& result)
{
	result = ZN_PinResult_Unknown;
	ZOOM_SDK_NAMESPACE::PinResult nativeResult = ZOOM_SDK_NAMESPACE::PinResult_Unknown;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().CanPinToSecondView(userId, nativeResult));
	result = (ZNPinResult)nativeResult;
	return err;
}
ZNSDKError ZMeetingVideoWrap::PinVideoToSecondView(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().PinVideoToSecondView(userId));
}
ZNList<unsigned int> ZMeetingVideoWrap::GetPinnedUserListFromSecondView()
{
	ZNList<unsigned int> zn_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int>* pList = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().GetPinnedUserListFromSecondView();
	if (pList)
	{
		for (int i = 0; i < pList->GetCount(); i++)
		{
			zn_list.push_back(pList->GetItem(i));
		}
	}
	return zn_list;
}
ZNSDKError ZMeetingVideoWrap::CanSpotlight(unsigned int userId, ZNSpotlightResult& result)
{
	result = ZN_SpotResult_Unknown;
	ZOOM_SDK_NAMESPACE::SpotlightResult nativeResult = ZOOM_SDK_NAMESPACE::SpotResult_Unknown;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().CanSpotlight(userId, nativeResult));
	result = (ZNSpotlightResult)nativeResult;
	return err;
}
ZNSDKError ZMeetingVideoWrap::CanUnSpotlight(unsigned int userId, ZNSpotlightResult& result)
{
	result = ZN_SpotResult_Unknown;
	ZOOM_SDK_NAMESPACE::SpotlightResult nativeResult = ZOOM_SDK_NAMESPACE::SpotResult_Unknown;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().CanUnSpotlight(userId, nativeResult));
	result = (ZNSpotlightResult)nativeResult;
	return err;
}
ZNSDKError ZMeetingVideoWrap::SpotlightVideo(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SpotlightVideo(userId));
}
ZNSDKError ZMeetingVideoWrap::UnSpotlightVideo(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnSpotlightVideo(userId));
}
ZNSDKError ZMeetingVideoWrap::UnSpotlightAllVideos()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnSpotlightAllVideos());
}
ZNList<unsigned int> ZMeetingVideoWrap::GetSpotlightedUserList()
{
	ZNList<unsigned int> zn_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int>* pList = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().GetSpotlightedUserList();
	if (pList)
	{
		for (int i = 0; i < pList->GetCount(); i++)
		{
			zn_list.push_back(pList->GetItem(i));
		}
	}
	return zn_list;
}
ZNSDKError ZMeetingVideoWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().HideOrShowNoVideoUserOnVideoWall(bHide));
}
ZNSDKError ZMeetingVideoWrap::UnPinVideoFromFirstView(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnPinVideoFromFirstView(userId));
}
ZNSDKError ZMeetingVideoWrap::UnPinVideoFromSecondView(unsigned int userId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnPinVideoFromSecondView(userId));
}
bool ZMeetingVideoWrap::IsSupportFollowHostVideoOrder()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().IsSupportFollowHostVideoOrder();
}
ZNSDKError ZMeetingVideoWrap::EnableFollowHostVideoOrder(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().EnableFollowHostVideoOrder(bEnable));
}
bool ZMeetingVideoWrap::IsFollowHostVideoOrderOn()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().IsFollowHostVideoOrderOn();
}
ZNList<unsigned int> ZMeetingVideoWrap::GetVideoOrderList()
{
	ZNList<unsigned int> zn_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int>* pList = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().GetVideoOrderList();
	if (pList)
	{
		for (int i = 0; i < pList->GetCount(); i++)
		{
			zn_list.push_back(pList->GetItem(i));
		}
	}
	return zn_list;
}
ZNList<unsigned int> ZMeetingVideoWrap::GetLocalVideoOrderList()
{
	ZNList<unsigned int> zn_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int>* pList = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().GetLocalVideoOrderList();
	if (pList)
	{
		for (int i = 0; i < pList->GetCount(); i++)
		{
			zn_list.push_back(pList->GetItem(i));
		}
	}
	return zn_list;
}
ZNSDKError ZMeetingVideoWrap::SetVideoQualityPreference(ZNSDKVideoPreferenceMode zn_mode, uint32_t minimumFrameRate, uint32_t maximumFrameRate)
{
	ZOOM_SDK_NAMESPACE::SDKVideoPreferenceSetting preferenceSetting;
	preferenceSetting.mode = Map2SDKDefine(zn_mode);
	preferenceSetting.minimumFrameRate = minimumFrameRate;
	preferenceSetting.maximumFrameRate = maximumFrameRate;
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetVideoQualityPreference(preferenceSetting));
}


void ZMeetingVideoWrap::onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status)
{
	if (m_pSink)
	{
		m_pSink->onUserVideoStatusChange(userId, status);
	}
}
void ZMeetingVideoWrap::onActiveSpeakerVideoUserChanged(unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onActiveSpeakerVideoUserChanged(userId);
	}
}
void ZMeetingVideoWrap::onActiveVideoUserChanged(unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onActiveVideoUserChanged(userId);
	}
}
void ZMeetingVideoWrap::onSpotlightedUserListChangeNotification(ZNList<unsigned int> lstSpotlightedUserID)
{
	if (m_pSink)
	{
		m_pSink->onSpotlightedUserListChangeNotification(lstSpotlightedUserID);
	}
}