#ifndef _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#define _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >;
private:
	ZoomNodeMeetingVideoCtrlWrap();
	~ZoomNodeMeetingVideoCtrlWrap();
public:
	/**
	 * @brief Turn off the user's own video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Turn on the user's own video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if it is able to pin the video of the specified user to the first view.
	 * @param userid Specifies the user ID to be determined.
	 * @param [out] result Indicates if it is able to pin. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is an object with err and result.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void CanPinToFirstView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Pin the video of the assigned user to the first view.
	 * @param userid Specifies the user ID to be pinned.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void PinVideoToFirstView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unpin all the videos from the first view.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void UnPinAllVideosFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Gets the list of all the pinned user in the first view.
	 * @return If the function succeeds, it returns the list of the pinned user in the first view. Otherwise, this function fails and returns an empty array.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void GetPinnedUserListFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if it is able to pin the video of the specified user to the second view.
	 * @param userid Specifies the user ID to be determined.
	 * @param [out] result Indicates if it is able to pin. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is an object with err and result.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void CanPinToSecondView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Pin the video of the assigned user to the second view.
	 * @param userid Specifies the user ID to be pinned.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void PinVideoToSecondView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Gets the list of all the pinned user in the second view.
	 * @return If the function succeeds, it returns the list of the pinned user in the second view. Otherwise, this function fails and returns an empty array.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void GetPinnedUserListFromSecondView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if it is able to spotlight the video of the specified user in the meeting.
	 * @param userid Specifies the user ID to be determined.
	 * @param [out] result Indicates if it is able to spotlight. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is an object with err and result.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void CanSpotlight(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if it is able to unspotlight the video of the specified user in the meeting.
	 * @param userid Specifies the user ID to be determined.
	 * @param [out] result Indicates if it is able to unspotlight. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is an object with err and result.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void CanUnSpotlight(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Spotlight the video of the assigned user to the first view.
	 * @param userid Specifies the user ID to be spotlighted.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unspotlight the video of the assigned user.
	 * @param userid Specifies the user ID to be unspotlighted.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void UnSpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unspotlight all videos.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void UnSpotlightAllVideos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of all spotlighted users in the meeting.
	 * @return If the function succeeds, the return value is an array of user IDs.
	 * @note Valid for both Zoom style and customize user interface mode.
	 */
	static void GetSpotlightedUserList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Display or not the user who does not turn on the video in the video all mode.
	 * @param bHide true if hide. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unpin the video of the assigned user from the first view.
	 * @param userid Specifies the user ID to be unpinned.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void UnPinVideoFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unpin the video of the assigned user from the second view.
	 * @param userid Specifies the user ID to be unpinned.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for Zoom style user interface mode.
	 */
	static void UnPinVideoFromSecondView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Gets the local video order list.
	 * @return If the function succeeds, it returns the local video order list. Otherwise, this function fails and returns an empty array.
	 * @note This list reflects the local video order as last received via the onLocalVideoOrderUpdated callback.
	 * The local video order is updated whenever onLocalVideoOrderUpdated is triggered.
	 */
	static void GetLocalVideoOrderList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the following host video order feature is supported.
	 * @return true indicates to support the following host video order feature.
	 */
	static void IsSupportFollowHostVideoOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enables or disable follow host video order mode.
	 * @param bEnable true indicates to set to enable the follow host video order mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableFollowHostVideoOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the follow host video mode is enabled.
	 * @return true indicates to enable the mode.
	 */
	static void IsFollowHostVideoOrderOn(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Gets the host video order list.
	 * @return If the function succeeds, it returns the host video order list. Otherwise, this function fails and returns an empty array.
	 * @note This method only returns the order list based on the host's video order (hostVideoOrder).
	 * If the host has not updated the video order, this list will be empty.
	 */
	static void GetVideoOrderList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the video quality preference that automatically adjust user's video to prioritize frame rate versus resolution based on the current bandwidth available.
	 * @param preferenceSetting Specifies the video quality preference.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetVideoQualityPreference(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the user video status changes.
	 * @param userId The user ID whose video status changes
	 * @param status New video status.
	 * @note Valid for both normal user and webinar attendee.
	 */
	static void SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the active speaker video user changes.
	 * @param userid The ID of user who becomes the new active speaker.
	 */
	static void SetActiveSpeakerVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the active video user changes.
	 * @param userid The ID of user who becomes the new active speaker.
	 */
	static void SetActiveVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event for when the video spotlight user list changes. Spotlight user means that the view will show only the specified user and won't change the view even other users speak.
	 * @param lstSpotlightedUserID spot light user list.
	 */
	static void SetSpotlightedUserListChangeNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingVideoCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteVideo", ZoomNodeMeetingVideoCtrlWrap::MuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteVideo", ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanPinToFirstView", ZoomNodeMeetingVideoCtrlWrap::CanPinToFirstView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PinVideoToFirstView", ZoomNodeMeetingVideoCtrlWrap::PinVideoToFirstView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnPinAllVideosFromFirstView", ZoomNodeMeetingVideoCtrlWrap::UnPinAllVideosFromFirstView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPinnedUserListFromFirstView", ZoomNodeMeetingVideoCtrlWrap::GetPinnedUserListFromFirstView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanPinToSecondView", ZoomNodeMeetingVideoCtrlWrap::CanPinToSecondView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PinVideoToSecondView", ZoomNodeMeetingVideoCtrlWrap::PinVideoToSecondView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPinnedUserListFromSecondView", ZoomNodeMeetingVideoCtrlWrap::GetPinnedUserListFromSecondView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSpotlight", ZoomNodeMeetingVideoCtrlWrap::CanSpotlight);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanUnSpotlight", ZoomNodeMeetingVideoCtrlWrap::CanUnSpotlight);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SpotlightVideo", ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSpotlightVideo", ZoomNodeMeetingVideoCtrlWrap::UnSpotlightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSpotlightAllVideos", ZoomNodeMeetingVideoCtrlWrap::UnSpotlightAllVideos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpotlightedUserList", ZoomNodeMeetingVideoCtrlWrap::GetSpotlightedUserList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideOrShowNoVideoUserOnVideoWall", ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnPinVideoFromFirstView", ZoomNodeMeetingVideoCtrlWrap::UnPinVideoFromFirstView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnPinVideoFromSecondView", ZoomNodeMeetingVideoCtrlWrap::UnPinVideoFromSecondView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLocalVideoOrderList", ZoomNodeMeetingVideoCtrlWrap::GetLocalVideoOrderList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportFollowHostVideoOrder", ZoomNodeMeetingVideoCtrlWrap::IsSupportFollowHostVideoOrder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableFollowHostVideoOrder", ZoomNodeMeetingVideoCtrlWrap::EnableFollowHostVideoOrder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsFollowHostVideoOrderOn", ZoomNodeMeetingVideoCtrlWrap::IsFollowHostVideoOrderOn);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoOrderList", ZoomNodeMeetingVideoCtrlWrap::GetVideoOrderList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetVideoQualityPreference", ZoomNodeMeetingVideoCtrlWrap::SetVideoQualityPreference);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingVideoStatusCB", ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetActiveSpeakerVideoUserChangedCB", ZoomNodeMeetingVideoCtrlWrap::SetActiveSpeakerVideoUserChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetActiveVideoUserChangedCB", ZoomNodeMeetingVideoCtrlWrap::SetActiveVideoUserChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSpotlightedUserListChangeNotificationCB", ZoomNodeMeetingVideoCtrlWrap::SetSpotlightedUserListChangeNotificationCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingVideoCtrlWrap >() {
	return &ZoomNodeMeetingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
