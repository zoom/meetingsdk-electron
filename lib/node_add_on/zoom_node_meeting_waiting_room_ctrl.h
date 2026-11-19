#ifndef _ZOOM_NODE_MEETING_WAITING_ROOM_CTRL_H_
#define _ZOOM_NODE_MEETING_WAITING_ROOM_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingWaitingRoomCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingWaitingRoomCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingWaitingRoomCtrlWrap >;
private:
	ZoomNodeMeetingWaitingRoomCtrlWrap();
	~ZoomNodeMeetingWaitingRoomCtrlWrap();
public:
	/**
	 * @brief Determines whether the current meeting supports the waiting room or not.
	 * @return true if supported. Otherwise, false.
	 */
	static void IsSupportWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the attendee is enabled to enter the waiting room when joining the meeting.
	 * @return true if enabled to enter. Otherwise, false.
	 */
	static void IsWaitingRoomOnEntryFlagOn(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set to enable the attendee to enter the waiting room when joining the meeting.
	 * @param bEnable true if enabled to enter. Otherwise, false. false not.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableWaitingRoomOnEntry(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of attendees who are in the waiting room.
	 * @return If the function succeeds, the return value is the list of attendees. Otherwise, this function returns an error, the return is nullptr.
	 */
	static void GetWaitingRoomList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the attendee information in the waiting room via user ID.
	 * @param userid Specifies the user ID.
	 * @return If the function succeeds, the return value is a pointer to IUserInfo. Otherwise, this function returns an error, the return is nullptr.
	 */
	static void GetWaitingRoomUserInfoByID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Permit the specified user to join the meeting.
	 * @param userid Specifies the user ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AdmitToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Permit all of the users currently in the waiting room to join the meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AdmitAllToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable the specified user to enter the waiting room.
	 * @param userid Specifies the user ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void PutInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the attendee is enabled to turn on audio when joining the meeting.
	 * @return true if enabled to turn on. Otherwise, false.
	 */
	static void IsAudioEnabledInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the attendee is enabled to turn on video when joining the meeting.
	 * @return true if enabled to turn on. Otherwise, false.
	 */
	static void IsVideoEnabledInWaitingRoom(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the WaitingRoom CustomizeData information in the waiting room.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. See onCustomWaitingRoomDataUpdated to access the result data. Otherwise, this function returns an error.
	 */
	static void RequestCustomWaitingRoomData(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the host or cohost can rename users in the waiting room.
	 * @param bIsCan true indicates the host or cohost can rename users in the waiting room. Otherwise they can't.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanRenameUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Change a user's screen name in the waiting room.
	 * @param userid The ID of users put into the waiting room by a host or cohost.
	 * @param userName The new user name.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void RenameUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if a host or cohost can expel user(s) in the waiting room.
	 * @param bIsCan true indicates that a host or cohost can expel user(s) in the waiting room. Otherwise they may not
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanExpelUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Remove a specified user from the waiting room.
	 * @param userid The ID of the user removed from the waiting room by a host or cohost.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ExpelUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Retry to Download the WaitingRoom CustomizeData information in the waiting room.
	 * @return true if retry success. Otherwise, false.
	 */
	static void Retry(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore to Download the WaitingRoom CustomizeData information in the waiting room.
	 */
	static void Ignore(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification that user joins the waiting room.
	 * @param userID The ID of user who joins the waiting room.
	 */
	static void SetOnWaitingRoomUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification that user leaves the waiting room.
	 * @param userID The ID of user who leaves the waiting room.
	 */
	static void SetOnWaitingRoomUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief During the waiting room, this callback event will be triggered when host change audio status.
	 * @param bAudioCanTurnOn true if audio can be turned on. Otherwise, false.
	 */
	static void SetOnWaitingRoomPresetAudioStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief During the waiting room, this callback event will be triggered when host change video status.
	 * @param bVideoCanTurnOn true if video can be turned on. Otherwise, false.
	 */
	static void SetOnWaitingRoomPresetVideoStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief During the waiting room, this callback event will be triggered when RequestCustomWaitingRoomData called.
	 * @param bData The WaitingRoom Customize Data Info, handler for download waitingRoom Customize Data if download fail.
	 * @param bHandler The handler for download waitingRoom Customize Data if download fail.
	 */
	static void SetOnCustomWaitingRoomDataUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback indicating that the name of a user in the waiting room has changed.
	 * @param userID The ID of the user whose user name have has changed.
	 * @param userName The new user name.
	 */
	static void SetOnWaitingRoomUserNameChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief This callback event will be triggered when host or cohost enables or disables waiting room entrance.
	 * @param bIsEnabled true enables waiting room entrance, false indicates disables waiting room entrance.
	 */
	static void SetOnWaitingRoomEntranceEnabledCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
void InitClassAttribute<ZoomNodeMeetingWaitingRoomCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingWaitingRoomCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportWaitingRoom", ZoomNodeMeetingWaitingRoomCtrlWrap::IsSupportWaitingRoom);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsWaitingRoomOnEntryFlagOn", ZoomNodeMeetingWaitingRoomCtrlWrap::IsWaitingRoomOnEntryFlagOn);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableWaitingRoomOnEntry", ZoomNodeMeetingWaitingRoomCtrlWrap::EnableWaitingRoomOnEntry);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWaitingRoomList", ZoomNodeMeetingWaitingRoomCtrlWrap::GetWaitingRoomList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWaitingRoomUserInfoByID", ZoomNodeMeetingWaitingRoomCtrlWrap::GetWaitingRoomUserInfoByID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AdmitToMeeting", ZoomNodeMeetingWaitingRoomCtrlWrap::AdmitToMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AdmitAllToMeeting", ZoomNodeMeetingWaitingRoomCtrlWrap::AdmitAllToMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PutInWaitingRoom", ZoomNodeMeetingWaitingRoomCtrlWrap::PutInWaitingRoom);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAudioEnabledInWaitingRoom", ZoomNodeMeetingWaitingRoomCtrlWrap::IsAudioEnabledInWaitingRoom);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsVideoEnabledInWaitingRoom", ZoomNodeMeetingWaitingRoomCtrlWrap::IsVideoEnabledInWaitingRoom);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestCustomWaitingRoomData", ZoomNodeMeetingWaitingRoomCtrlWrap::RequestCustomWaitingRoomData);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRenameUser", ZoomNodeMeetingWaitingRoomCtrlWrap::CanRenameUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RenameUser", ZoomNodeMeetingWaitingRoomCtrlWrap::RenameUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanExpelUser", ZoomNodeMeetingWaitingRoomCtrlWrap::CanExpelUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ExpelUser", ZoomNodeMeetingWaitingRoomCtrlWrap::ExpelUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Retry", ZoomNodeMeetingWaitingRoomCtrlWrap::Retry);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Ignore", ZoomNodeMeetingWaitingRoomCtrlWrap::Ignore);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomUserJoinCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserJoinCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomUserLeftCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomPresetAudioStatusChangedCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomPresetAudioStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomPresetVideoStatusChangedCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomPresetVideoStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnCustomWaitingRoomDataUpdatedCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnCustomWaitingRoomDataUpdatedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomUserNameChangedCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomUserNameChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnWaitingRoomEntranceEnabledCB", ZoomNodeMeetingWaitingRoomCtrlWrap::SetOnWaitingRoomEntranceEnabledCB);
}
template<>
v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingWaitingRoomCtrlWrap >() {
	return &ZoomNodeMeetingWaitingRoomCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
