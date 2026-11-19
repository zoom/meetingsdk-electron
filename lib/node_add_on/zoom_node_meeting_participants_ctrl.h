#ifndef _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#define _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingParticipantsCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >;
private:
	ZoomNodeMeetingParticipantsCtrlWrap();
	~ZoomNodeMeetingParticipantsCtrlWrap();
public:
	/**
	 * @brief Get the list of all the panelists in the meeting.
	 * @return If the function succeeds, the return value is the list of the panelists in the meeting. Otherwise the function fails, and the return value is nullptr.
	 * @note Valid for both ZOOM style and user custom interface mode. Valid for both normal user and webinar attendee.
	 */
	static void GetParticipantsList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the information of specified user.
	 * @param userid Specify the user ID for which you want to get the information.
	 * @return If the function succeeds, the return value is a pointer to the IUserInfo. Otherwise the function fails, and the return value is nullptr.
	 * @note Valid for both ZOOM style and user custom interface mode. Valid for both normal user and webinar attendee.
	 */
	static void GetUserInfoByUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the information about the bot's authorized user.
	 * @param userid Specify the user ID for which to get the information.
	 * @return If the function succeeds, the return value is a pointer to the IUserInfo. Otherwise the function fails, and the return value is nullptr.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void GetBotAuthorizedUserInfoByUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the authorizer's bot list.
	 * @param userid Specify the user ID for which you want to get the information.
	 * @return If the function succeeds, the return value is the authorizer's bot list in the meeting. Otherwise the function fails, and the return value is nullptr.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void GetAuthorizedBotListByUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the current user can enable participant request cloud recording.
	 * @return true if the current user can enable participant request cloud recording. Otherwise, false.
	 */
	static void CanEnableParticipantRequestCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check whether the current meeting allows participants to send cloud recording privilege request, This can only be used in regular meeetings and webinar(no breakout rooms).
	 * @return If allows participants to send request, the return value is true.
	 */
	static void IsParticipantRequestCloudRecordingAllowed(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Toggle whether attendees can requests for the host to start a cloud recording. This can only be used in regular meeetings and webinar(no breakout rooms).
	 * @param bAllow true indicates that participants are allowed to send cloud recording privilege requests.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise the function fails.
	 */
	static void AllowParticipantsToRequestCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Requests the avatar download for a specified user.
	 * @param userid Specify the user ID whose avatar the SDK requests.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode. Valid for both normal user and webinar attendee.
	 */
	static void RequestAvatarForUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification of users who are in the meeting.
	 * @param lstUserID List of user IDs.
	 * @param strUserList List of users in JSON format. This function is currently invalid, hereby only for reservations.
	 * @note Valid for both normal user and webinar attendee.
	 */
	static void SetMeetingUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification of user who leaves the meeting.
	 * @param lstUserID List of the user ID who leaves the meeting.
	 * @param strUserList List of the users in JSON format. This function is currently invalid, hereby only for reservations.
	 * @note Valid for both normal user and webinar attendee.
	 */
	static void SetMeetingUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification of the new host.
	 * @param userId Specify the ID of the new host.
	 */
	static void SetMeetingHostChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that lets participants request that the host starts cloud recording.
	 * @param bAllow true allow. If false, disallow.
	 */
	static void SetOnAllowParticipantsRequestCloudRecordingCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the user's avatar path is updated in a meeting.
	 * @param userID Specify the user ID whose avatar path is updated.
	 */
	static void SetOnInMeetingUserAvatarPathUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that the bot relationship changed in the meeting.
	 * @param authorizeUserID Specify the authorizer user ID.
	 */
	static void SetOnBotAuthorizerRelationChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingParticipantsCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingParticipantsCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetParticipantsList", ZoomNodeMeetingParticipantsCtrlWrap::GetParticipantsList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetUserInfoByUserID", ZoomNodeMeetingParticipantsCtrlWrap::GetUserInfoByUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetBotAuthorizedUserInfoByUserID", ZoomNodeMeetingParticipantsCtrlWrap::GetBotAuthorizedUserInfoByUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthorizedBotListByUserID", ZoomNodeMeetingParticipantsCtrlWrap::GetAuthorizedBotListByUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanEnableParticipantRequestCloudRecording", ZoomNodeMeetingParticipantsCtrlWrap::CanEnableParticipantRequestCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsParticipantRequestCloudRecordingAllowed", ZoomNodeMeetingParticipantsCtrlWrap::IsParticipantRequestCloudRecordingAllowed);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AllowParticipantsToRequestCloudRecording", ZoomNodeMeetingParticipantsCtrlWrap::AllowParticipantsToRequestCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestAvatarForUser", ZoomNodeMeetingParticipantsCtrlWrap::RequestAvatarForUser);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserJoinCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserJoinCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserLeftCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingHostChangeCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingHostChangeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAllowParticipantsRequestCloudRecordingCB", ZoomNodeMeetingParticipantsCtrlWrap::SetOnAllowParticipantsRequestCloudRecordingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnInMeetingUserAvatarPathUpdatedCB", ZoomNodeMeetingParticipantsCtrlWrap::SetOnInMeetingUserAvatarPathUpdatedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnBotAuthorizerRelationChangedCB", ZoomNodeMeetingParticipantsCtrlWrap::SetOnBotAuthorizerRelationChangedCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingParticipantsCtrlWrap >() {
	return &ZoomNodeMeetingParticipantsCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
