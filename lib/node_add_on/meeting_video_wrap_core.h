#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingVideoWrap
{
public:
	ZMeetingVideoWrap();
	virtual ~ZMeetingVideoWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingVideoWrapSink* pSink);

	ZNSDKError MuteVideo(unsigned int userId);
	ZNSDKError UnMuteVideo(unsigned int userId);
	ZNSDKError CanPinToFirstView(unsigned int userId, ZNPinResult& result);
	ZNSDKError PinVideoToFirstView(unsigned int userId);
	ZNSDKError UnPinAllVideosFromFirstView();
	ZNList<unsigned int> GetPinnedUserListFromFirstView();
	ZNSDKError CanPinToSecondView(unsigned int userId, ZNPinResult& result);
	ZNSDKError PinVideoToSecondView(unsigned int userId);
	ZNList<unsigned int> GetPinnedUserListFromSecondView();
	ZNSDKError CanSpotlight(unsigned int userId, ZNSpotlightResult& result);
	ZNSDKError CanUnSpotlight(unsigned int userId, ZNSpotlightResult& result);
	ZNSDKError SpotlightVideo(unsigned int userId);
	ZNSDKError UnSpotlightVideo(unsigned int userId);
	ZNSDKError UnSpotlightAllVideos();
	ZNList<unsigned int> GetSpotlightedUserList();
	ZNSDKError HideOrShowNoVideoUserOnVideoWall(bool bHide);
	ZNSDKError UnPinVideoFromFirstView(unsigned int userId);
	ZNSDKError UnPinVideoFromSecondView(unsigned int userId);
	bool IsSupportFollowHostVideoOrder();
	ZNSDKError EnableFollowHostVideoOrder(bool bEnable);
	bool IsFollowHostVideoOrderOn();
	ZNList<unsigned int> GetVideoOrderList();
	ZNList<unsigned int> GetLocalVideoOrderList();
	ZNSDKError SetVideoQualityPreference(ZNSDKVideoPreferenceMode mode, uint32_t minimumFrameRate, uint32_t maximumFrameRate);

	//callback
	void onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status);
	void onActiveSpeakerVideoUserChanged(unsigned int userid);
	void onActiveVideoUserChanged(unsigned int userid);
	void onSpotlightedUserListChangeNotification(ZNList<unsigned int> lstSpotlightedUserID);

private:
	ZNativeSDKMeetingVideoWrapSink* m_pSink;

};
