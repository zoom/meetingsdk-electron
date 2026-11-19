#ifndef _ZOOM_NODE_SDK_SMS_HELPER_H_
#define _ZOOM_NODE_SDK_SMS_HELPER_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSDKSMSHelperWrap :
	public ZoomWrapObject<ZoomNodeSDKSMSHelperWrap >
{
	friend class ZoomWrapObject<ZoomNodeSDKSMSHelperWrap >;
private:
	ZoomNodeSDKSMSHelperWrap();
	~ZoomNodeSDKSMSHelperWrap();
public:
	/**
	 * @brief Set the visibility of the dialog box of auth real name when needed. Default value: true.
	 * @param enable true indicates to display the dialog box. Otherwise, false.
	 * @return If the function succeeds, the return value is true.
	 */
	static void EnableZoomAuthRealNameMeetingUIShown(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set default cellphone information to let the user bypass the real name auth to start/join meeting directly.
	 * @param country_code Specifies the country code.
	 * @param phone_number Specifies the phone number.
	 * @return If the function succeeds, the return value is true.
	 */
	static void SetDefaultCellPhoneInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get retrieve SMS verification code handler interface.
	 * @return If the function succeeds, the return value is a pointer to IZoomRetrieveSMSVerificationCodeHandler. Otherwise, this function fails and returns nullptr.
	 */
	static void GetResendSMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Retrieve the sms verification code.
	 * @param country_code Specifies the country code.
	 * @param phone_number Specifies the phone number.
	 * @return If the function succeeds, the return value is true.
	 * @note The handler will become invalid after calling this function successfully.
	 */
	static void Retrieve(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the prompt of retrieving the verification code and leave meeting.
	 * @return If the function succeeds, the return value is true.
	 * @note The handler will become invalid and destroied after calling this function successfully.
	 */
	static void Retrieve_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get verify SMS verification code handler interface.
	 * @return If the function succeeds, the return value is a pointer to IZoomVerifySMSVerificationCodeHandler. Otherwise, this function fails and returns nullptr.
	 */
	static void GetReVerifySMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Verify the sms verification code.
	 * @param country_code Specifies the country code.
	 * @param phone_number Specifies the phone number.
	 * @param verification_code Specifies the verification code.
	 * @return If the function succeeds, the return value is true.
	 * @note The handler will become invalid after calling this function successfully.
	 */
	static void Verify(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the prompt of verifying the verification code and leave meeting.
	 * @return If the function succeeds, the return value is true.
	 * @note The handler will become invalid and destroied after calling this function successfully.
	 */
	static void Verify_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of the country information where the meeting supports real name auth.
	 * @return List of the country information where the meeting supports real name auth.
	 */
	static void GetSupportPhoneNumberCountryList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief If real name auth is needed, this callback will be triggered.
	 * @param support_country_list The list of the supporting country information.
	 * @param privacy_url The privacy url.
	 * @param handler A pointer to the IZoomRetrieveSMSVerificationCodeHandler.
	 * The SDK user can retrieve the verification code via the functions of IZoomRetrieveSMSVerificationCodeHandler.
	 */
	static void SetNeedRealNameAuthMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback event for retrieving SMS verification code.
	 * @param result Specifies the result of retrieve.
	 * @param handler A pointer to the IZoomVerifySMSVerificationCodeHandler. It is only valid when the value of result is SMSVerificationCodeErr_Success.
	 * The SDK user can do the verification via the functions of IZoomVerifySMSVerificationCodeHandler.
	 */
	static void SetRetrieveSMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback event for verification.
	 * @param result Specifies the result of verification.
	 */
	static void SetVerifySMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSDKSMSHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSDKSMSHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableZoomAuthRealNameMeetingUIShown", ZoomNodeSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetResendSMSVerificationCodeHandler", ZoomNodeSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Retrieve", ZoomNodeSDKSMSHelperWrap::Retrieve);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Retrieve_CancelAndLeaveMeeting", ZoomNodeSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetReVerifySMSVerificationCodeHandler", ZoomNodeSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Verify", ZoomNodeSDKSMSHelperWrap::Verify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Verify_CancelAndLeaveMeeting", ZoomNodeSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSupportPhoneNumberCountryList", ZoomNodeSDKSMSHelperWrap::GetSupportPhoneNumberCountryList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetNeedRealNameAuthMeetingNotificationCB", ZoomNodeSDKSMSHelperWrap::SetNeedRealNameAuthMeetingNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRetrieveSMSVerificationCodeResultNotificationCB", ZoomNodeSDKSMSHelperWrap::SetRetrieveSMSVerificationCodeResultNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetVerifySMSVerificationCodeResultNotificationCB", ZoomNodeSDKSMSHelperWrap::SetVerifySMSVerificationCodeResultNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultCellPhoneInfo", ZoomNodeSDKSMSHelperWrap::SetDefaultCellPhoneInfo);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSDKSMSHelperWrap >() {
	return &ZoomNodeSDKSMSHelperWrap::constructor;
}

#endif
