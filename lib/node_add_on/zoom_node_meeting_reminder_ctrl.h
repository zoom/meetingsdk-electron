#ifndef _ZOOM_NODE_MEETING_REMINDER_CTRL_H_
#define _ZOOM_NODE_MEETING_REMINDER_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingReminderCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingReminderCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingReminderCtrlWrap >;
private:
	ZoomNodeMeetingReminderCtrlWrap();
	~ZoomNodeMeetingReminderCtrlWrap();
public:
	/**
	 * @brief Ignore the reminder.
	 */
	static void Ignore(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Accept the reminder.
	 */
	static void Accept(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the reminder.
	 */
	static void Decline(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the reminder dialog show.
	 * @param content The detail content in the reminder dialog.
	 * @param handle A pointer to the IMeetingReminderHandler.
	 */
	static void SetOnReminderNotifyCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Sets the option indicating which meetings feature will be enabled for.
	 * @param option Specify the option.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetEnableOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Starts the feature.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the reminder.
	 * @param bDeclineAll true indicates decline all reminders,and participants cannot send requests again until the host changes the setting. false means that the host declines only this specific request, not all requests.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeclineEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the reminder.
	 */
	static void IgnoreEnable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the enable reminder dialog show.
	 * @param content The detail content in the reminder dialog.
	 * @param handle A pointer to the IMeetingEnableReminderHandler.
	 */
	static void SetOnEnableReminderNotifyCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Sets not show the disclaimer in subsequent meetings.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetHideFeatureDisclaimers(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Sets the customized config of multi-reminder disclaimer.
	 * @param left Specifies the X-axis coordinate of the top-left corner of the multi-reminder window in the parent window.
	 * @param top Specifies the Y-axis coordinate of the top-left corner of the multi-reminder window in the parent window.
	 * @param parentWindowHandle Specifies the hexadecimal handle of the parent window.
	 * @param backgroundColor Specifies the background color of the multi-reminder window.
	 * @note Valid for user custom interface mode only.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetMultiReminderDisclaimerUIConfig(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Update the position and size of multi-reminder disclaimer window when its parent window moves or changes size.
	 * @note This interface should be invoked when the OnSize and OnMove messages of the parent window recieved. Valid for user custom interface mode only.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void UpdateMultiReminderDisclaimerUI(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
void InitClassAttribute<ZoomNodeMeetingReminderCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingReminderCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Ignore", ZoomNodeMeetingReminderCtrlWrap::Ignore);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Accept", ZoomNodeMeetingReminderCtrlWrap::Accept);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Decline", ZoomNodeMeetingReminderCtrlWrap::Decline);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReminderNotifyCB", ZoomNodeMeetingReminderCtrlWrap::SetOnReminderNotifyCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetEnableOption", ZoomNodeMeetingReminderCtrlWrap::SetEnableOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartEnable", ZoomNodeMeetingReminderCtrlWrap::StartEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeclineEnable", ZoomNodeMeetingReminderCtrlWrap::DeclineEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IgnoreEnable", ZoomNodeMeetingReminderCtrlWrap::IgnoreEnable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnEnableReminderNotifyCB", ZoomNodeMeetingReminderCtrlWrap::SetOnEnableReminderNotifyCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetHideFeatureDisclaimers", ZoomNodeMeetingReminderCtrlWrap::SetHideFeatureDisclaimers);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMultiReminderDisclaimerUIConfig", ZoomNodeMeetingReminderCtrlWrap::SetMultiReminderDisclaimerUIConfig);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpdateMultiReminderDisclaimerUI", ZoomNodeMeetingReminderCtrlWrap::UpdateMultiReminderDisclaimerUI);
}
template<>
v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingReminderCtrlWrap >() {
	return &ZoomNodeMeetingReminderCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
