#ifndef _ZOOM_NODE_MEETING_LIVE_STREAM_CTRL_H_
#define _ZOOM_NODE_MEETING_LIVE_STREAM_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingLiveStreamCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingLiveStreamCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingLiveStreamCtrlWrap >;
private:
	ZoomNodeMeetingLiveStreamCtrlWrap();
	~ZoomNodeMeetingLiveStreamCtrlWrap();
public:

	/**
	 * @brief Determines if it is able to start live streaming.
	 * @return If it is enabled to start the live streaming, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanStartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start live streaming.
	 * @param item_ A pointer to the IMeetingLiveStreamItem created via IMeetingLiveStreamController::GetSupportLiveStreamURL() API.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start live streaming.
	 * @param streamingURL The URL of live streaming.
	 * @param streamingKey The key of live streaming.
	 * @param broadcastURL The broadcast URL of live-stream.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Get the parameters from the third party of live stream service
	 */
	static void StartLiveStreamWithSteamingURL(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop live streaming.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of live stream information items in the current meeting.
	 * @return If the function succeeds, the return value is the live stream item list. Otherwise, this function fails and returns nullptr.
	 */
	static void GetSupportLiveStreamItems(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the current live stream object.
	 * @return If the function succeeds, the return value is the current live stream object. Otherwise, this function fails and returns nullptr.
	 */
	static void GetCurrentLiveStreamItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get live stream status of current meeting.
	 * @return If the function succeeds, the return value is the live stream status of current meeting. Otherwise, this function returns an error.
	 */
	static void GetCurrentLiveStreamStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop raw live streaming.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopRawLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of URL and associated information used by live streaming in the current meeting.
	 * @return If the function succeeds, the return value is the meeting information to be live streamed. Otherwise, this function returns an error, the return value is nullptr.
	 * @deprecated This interface is marked as deprecated, and is replaced by GetSupportLiveStreamItems().
	 */
	static void GetLiveStreamItemInfo(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Query Whether the meeting supports raw live streams.
	 * @return true if supported, false if not supported.
	 */
	static void IsRawLiveStreamSupported(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Whether if the current user is able to start raw live streaming.
	 * @return If the current user is able to start raw live streaming, the return value is SDKERR_SUCCESS. Otherwise, this function fails and returns nullptr.
	 */
	static void CanStartRawLiveStream(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Remove the raw live stream privilege.
	 * @param userID Specify the ID of the user whose privilege will be removed.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void RemoveRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get a list of current active raw live streams.
	 * @return If the function succeeds, the return value is a pointer to the IList object.
	 */
	static void GetRawLiveStreamingInfoList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of users'IDs who have raw live stream privileges.
	 * @return If the function succeeds, the return value is a pointer to the IList object.
	 */
	static void GetRawLiveStreamPrivilegeUserList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the live stream reminder is enabled.
	 * @return true if the live stream reminder is enabled. Otherwise, false.
	 * @note When the live stream reminder is enabled, the new join user is notified that the meeting is at capacity but that they can watch the meeting live stream with the callback IMeetingServiceEvent::onMeetingFullToWatchLiveStream when the meeting user has reached the meeting capability.
	 */
	static void IsLiveStreamReminderEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the current user can enable/disable the live stream reminder.
	 * @return true if the current user can enable/disable the live stream reminder. Otherwise, false.
	 */
	static void CanEnableLiveStreamReminder(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable the live stream reminder.
	 * @param enable true indicates enable the live stream reminder. false indicates disable the live stream reminder.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableLiveStreamReminder(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event when live stream status changes.
	 * @param status Live stream status.
	 */
	static void SetOnLiveStreamStatusChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the current user's raw live streaming privilege changes.
	 * @param bHasPrivilege Specify whether or not the user has privileg.
	 */
	static void SetOnRawLiveStreamPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when another user's raw live streaming privilege has changed.
	 * @param userid The ID of the user whose privilege has changed.
	 * @param bHasPrivilege Specify whether the user has privilege or not.
	 */
	static void SetOnUserRawLiveStreamPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when a user requests raw live streaming privilege.
	 * @param handler A pointer to the IRequestRawLiveStreamPrivilegeHandler.
	 */
	static void SetOnRawLiveStreamPrivilegeRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when users start/stop raw live streaming.
	 * @param liveStreamList A list of users with an active raw live stream.
	 */
	static void SetOnUserRawLiveStreamingStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the current user's request has time out.
	 */
	static void SetOnRawLiveStreamPrivilegeRequestTimeoutCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the live stream reminder enable status changes.
	 * @param enable true if the live stream reminder is enabled. Otherwise, false.
	 */
	static void SetOnLiveStreamReminderStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the live stream reminder enable status change fails.
	 */
	static void SetOnLiveStreamReminderStatusChangeFailedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the meeting or webinar user has nearly reached the meeting capacity, like 80% or 100% for the meeting or webinar capacity.
	 * The host can start live stream to let unjoined user watch live stream.
	 * @param percent Proportion of joined users to the total capacity.
	 */
	static void SetOnUserThresholdReachedForLiveStreamCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingLiveStreamCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingLiveStreamCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartLiveStream", ZoomNodeMeetingLiveStreamCtrlWrap::CanStartLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiveStream", ZoomNodeMeetingLiveStreamCtrlWrap::StartLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiveStreamWithSteamingURL", ZoomNodeMeetingLiveStreamCtrlWrap::StartLiveStreamWithSteamingURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopLiveStream", ZoomNodeMeetingLiveStreamCtrlWrap::StopLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSupportLiveStreamItems", ZoomNodeMeetingLiveStreamCtrlWrap::GetSupportLiveStreamItems);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentLiveStreamItem", ZoomNodeMeetingLiveStreamCtrlWrap::GetCurrentLiveStreamItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentLiveStreamStatus", ZoomNodeMeetingLiveStreamCtrlWrap::GetCurrentLiveStreamStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopRawLiveStream", ZoomNodeMeetingLiveStreamCtrlWrap::StopRawLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLiveStreamItemInfo", ZoomNodeMeetingLiveStreamCtrlWrap::GetLiveStreamItemInfo);

	NODE_SET_PROTOTYPE_METHOD(tpl, "IsRawLiveStreamSupported", ZoomNodeMeetingLiveStreamCtrlWrap::IsRawLiveStreamSupported);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartRawLiveStream", ZoomNodeMeetingLiveStreamCtrlWrap::CanStartRawLiveStream);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RemoveRawLiveStreamPrivilege", ZoomNodeMeetingLiveStreamCtrlWrap::RemoveRawLiveStreamPrivilege);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawLiveStreamingInfoList", ZoomNodeMeetingLiveStreamCtrlWrap::GetRawLiveStreamingInfoList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawLiveStreamPrivilegeUserList", ZoomNodeMeetingLiveStreamCtrlWrap::GetRawLiveStreamPrivilegeUserList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsLiveStreamReminderEnabled", ZoomNodeMeetingLiveStreamCtrlWrap::IsLiveStreamReminderEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanEnableLiveStreamReminder", ZoomNodeMeetingLiveStreamCtrlWrap::CanEnableLiveStreamReminder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLiveStreamReminder", ZoomNodeMeetingLiveStreamCtrlWrap::EnableLiveStreamReminder);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnLiveStreamStatusChangeCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnLiveStreamStatusChangeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnRawLiveStreamPrivilegeChangedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserRawLiveStreamPrivilegeChangedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnUserRawLiveStreamPrivilegeChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnRawLiveStreamPrivilegeRequestedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeRequestedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserRawLiveStreamingStatusChangedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnUserRawLiveStreamingStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnRawLiveStreamPrivilegeRequestTimeoutCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnRawLiveStreamPrivilegeRequestTimeoutCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnLiveStreamReminderStatusChangedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnLiveStreamReminderStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnLiveStreamReminderStatusChangeFailedCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnLiveStreamReminderStatusChangeFailedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserThresholdReachedForLiveStreamCB", ZoomNodeMeetingLiveStreamCtrlWrap::SetOnUserThresholdReachedForLiveStreamCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingLiveStreamCtrlWrap >() {
	return &ZoomNodeMeetingLiveStreamCtrlWrap::constructor;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZOOM_NODE_HIDE ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap :
	public ZoomWrapObject<ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap >
{
	friend class ZoomWrapObject<ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap >;
private:
	ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap();
	~ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap();
public:

	/**
	 * @brief Get the request ID.
	 * @return If the function succeeds, the return value is the request ID.
	 */
	static void GetRequestId(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user ID who requested privilege.
	 * @return If the function succeeds, the return value is the user ID. Otherwise, this returns 0.
	 */
	static void GetRequesterId(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user name who requested privileges.
	 * @return If the function succeeds, the return value is the user name.
	 */
	static void GetRequesterName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the broadcast URL.
	 * @return If the function succeeds, the return value is the broadcast URL.
	 */
	static void GetBroadcastUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Allows the user to start raw live stream and finally self-destroy.
	 */
	static void GrantRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Denies the user permission to start raw live stream and finally self-destroy.
	 */
	static void DenyRawLiveStreamPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequestId", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequestId);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequesterId", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequesterId);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequesterName", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetRequesterName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetBroadcastUrl", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GetBroadcastUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GrantRawLiveStreamPrivilege", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::GrantRawLiveStreamPrivilege);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DenyRawLiveStreamPrivilege", ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::DenyRawLiveStreamPrivilege);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap >() {
	return &ZoomNodeRequestRawLiveStreamPrivilegeHandlerWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
