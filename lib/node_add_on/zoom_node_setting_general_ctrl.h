#ifndef _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#define _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingGeneralCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >;
private:
	ZoomNodeSettingGeneralCtrlWrap();
	~ZoomNodeSettingGeneralCtrlWrap();
public:
	/**
	 * @brief Enable or disable dual screen mode.
	 * @param bEnable true indicates to set to enable the dual screen mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableDualScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable the aero mode when sharing the screen.
	 * @param bTurnoff true indicates to turn off the aero mode when sharing the screen.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The function can only be called in windows 7 environment.
	 */
	static void TurnOffAeroModeInSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable to enter the full screen video mode automatically when join meeting.
	 * @param bEnable true if entering the full screen video mode. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAutoFullScreenVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable to use the split screen mode, which enables the attendees to view the lectures or the gallery.
	 * @param bEnable true indicates to enter the split screen mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the dual screen mode is supported.
	 * @return true if enabling the dual screen mode. Otherwise, false.
	 */
	static void IsDualScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the aero mode is turned off when sharing the screen.
	 * @return true if turning off the mode. Otherwise, false.
	 */
	static void IsAeroModeInSharingTurnOff(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines if it is able to enter the full screen video mode automatically when join meeting.
	 * @return true if entering the full screen video mode. Otherwise, false.
	 */
	static void IsAutoFullScreenVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the split screen mode is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsSplitScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * @brief Enable/Disable reminder window when user exits the meeting. Available only for normal attendees (non-host).
	 * @param bEnable true indicates to enable reminder window.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableDisplayReminderWindowWhenExit(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if reminder window is enabled when user exits the meeting.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsDisplayReminderWindowWhenExitEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable/Disable to show the elapsed time of the meeting.
	 * @param bEnable true indicates to show the elapsed time. false not.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableShowMyMeetingElapseTime(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if showing elapsed time of the meeting is enabled.
	 * @return true indicates to show.
	 */
	static void IsShowMyMeetingElapseTimeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingGeneralCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingGeneralCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDualScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableDualScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOffAeroModeInSharing", ZoomNodeSettingGeneralCtrlWrap::TurnOffAeroModeInSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFullScreenVideoWhenJoinMeeting", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSplitScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableSplitScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDualScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsDualScreenModeEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAeroModeInSharingTurnOff", ZoomNodeSettingGeneralCtrlWrap::IsAeroModeInSharingTurnOff);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFullScreenVideoWhenJoinMeetingEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSplitScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsSplitScreenModeEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDisplayReminderWindowWhenExit", ZoomNodeSettingGeneralCtrlWrap::EnableDisplayReminderWindowWhenExit);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDisplayReminderWindowWhenExitEnabled", ZoomNodeSettingGeneralCtrlWrap::IsDisplayReminderWindowWhenExitEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowMyMeetingElapseTime", ZoomNodeSettingGeneralCtrlWrap::EnableShowMyMeetingElapseTime);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShowMyMeetingElapseTimeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsShowMyMeetingElapseTimeEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingGeneralCtrlWrap >() {
	return &ZoomNodeSettingGeneralCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
