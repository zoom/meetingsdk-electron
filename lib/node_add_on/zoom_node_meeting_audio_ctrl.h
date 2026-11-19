#ifndef _ZOOM_NODE_MEETING_AUDIO_CTRL_H_
#define _ZOOM_NODE_MEETING_AUDIO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAudioCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingAudioCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAudioCtrlWrap >;
private:
	ZoomNodeMeetingAudioCtrlWrap();
	~ZoomNodeMeetingAudioCtrlWrap();
public:
	/**
	 * @brief Mute the assigned user.
	 * @param userid Specify the user ID to mute. ZERO(0) indicates to mute all the participants.
	 * @param allowUnmuteBySelf The user may unmute himself when everyone is muted.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unmute the assigned user.
	 * @param userid Specify the user ID to unmute.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Join VoIP meeting.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void JoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Leave VoIP meeting.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void LeaveVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Mute or umute the user after joining the meeting.
	 * @param bEnable true indicates to mute the user after joining the meeting.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void EnableMuteOnEntry(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the host or cohost can enable mute on entry.
	 * @return true indicates that the host or cohost can enable mute on entry. Otherwise, false.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void CanEnableMuteOnEntry(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if mute on entry is enabled.
	 * @return true indicates that mute on entry is enabled.
	 */
	static void IsMuteOnEntryEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief User's audio status changed callback.
	 */
	static void SetMeetingAudioStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback event that users whose audio is active changed.
	 */
	static void SetUserActiveAudioChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event for the mute on entry status change.
	 */
	static void SetOnMuteOnEntryStatusChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief User joins or leaves the meeting in silence or no.
	 * @param bEnable true indicates to play chime when the user joins or leaves the meeting.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void EnablePlayChimeWhenEnterOrExit(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable SDK to play meeting audio.
	 * @param bEnable true indicates that SDK will play meeting audio. false indicates that SDK will not play meeting audio.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note SDK will not support sharing computer sound when disabling playing meeting audio.
	 */
	static void EnablePlayMeetingAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if play meeting audio is enabled or not.
	 * @return true indicates enabled, otherwise it is not enabled.
	 */
	static void IsPlayMeetingAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingAudioCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAudioCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteAudio", ZoomNodeMeetingAudioCtrlWrap::MuteAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteAudio", ZoomNodeMeetingAudioCtrlWrap::UnMuteAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "JoinVoip", ZoomNodeMeetingAudioCtrlWrap::JoinVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LeaveVoip", ZoomNodeMeetingAudioCtrlWrap::LeaveVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMuteOnEntry", ZoomNodeMeetingAudioCtrlWrap::EnableMuteOnEntry);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanEnableMuteOnEntry", ZoomNodeMeetingAudioCtrlWrap::CanEnableMuteOnEntry);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMuteOnEntryEnabled", ZoomNodeMeetingAudioCtrlWrap::IsMuteOnEntryEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingAudioStatusCB", ZoomNodeMeetingAudioCtrlWrap::SetMeetingAudioStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetUserActiveAudioChangeCB", ZoomNodeMeetingAudioCtrlWrap::SetUserActiveAudioChangeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnablePlayChimeWhenEnterOrExit", ZoomNodeMeetingAudioCtrlWrap::EnablePlayChimeWhenEnterOrExit);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnablePlayMeetingAudio", ZoomNodeMeetingAudioCtrlWrap::EnablePlayMeetingAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsPlayMeetingAudioEnabled", ZoomNodeMeetingAudioCtrlWrap::IsPlayMeetingAudioEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnMuteOnEntryStatusChangeCB", ZoomNodeMeetingAudioCtrlWrap::SetOnMuteOnEntryStatusChangeCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAudioCtrlWrap >() {
	return &ZoomNodeMeetingAudioCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
