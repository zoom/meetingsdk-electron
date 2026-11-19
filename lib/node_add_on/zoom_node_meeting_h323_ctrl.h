#ifndef _ZOOM_NODE_MEETING_H323_CTRL_H_
#define _ZOOM_NODE_MEETING_H323_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingH323CtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >;
private:
	ZoomNodeMeetingH323CtrlWrap();
	~ZoomNodeMeetingH323CtrlWrap();
public:
	/**
	 * @brief Call out with the assigned H.323 device.
	 * @param deviceName Specifies the device name.
	 * @param deviceIP Specifies the device ip. To get extended information, see ZNH323DeviceType enum.
	 * @param deviceE164num Specifies the device E164 number.
	 * @param type Specifies the H.323 device type.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note If the function succeeds, the IMeetingH323HelperEvent::onCalloutStatusNotify() will be triggered once the callout status of H.323 device changes.
	 */
	static void CallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Cancel current outgoing call.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CancelCallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of H.323 call-in number supported by the current meeting.
	 * @return If the function succeeds, the return value is the pointer to the list of the call-in number. Otherwise, this function returns an error, the return value is nullptr.
	 */
	static void GetH323Address(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the H.323 password for the current meeting.
	 * @return If the function succeeds, the return value is the H.323 meeting connect password. Otherwise, this function returns an error, the return value is the length of zero(0).
	 */
	static void GetH323Password(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of the call-out devices supported by the current meeting.
	 * @return If the function succeeds, the return value is the pointer to the list of devices. Otherwise, this function returns an error, the return value is an empty list.
	 * @note The list will be cleared each time the function is called.
	 */
	static void GetCalloutH323DeviceList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when the calling status of H.323 device changes.
	 * @param status H.323 device calling out status value. For more details.
	 */
	static void SetH323CallOutStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingH323CtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingH323CtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CallOutH323", ZoomNodeMeetingH323CtrlWrap::CallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelCallOutH323", ZoomNodeMeetingH323CtrlWrap::CancelCallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Address", ZoomNodeMeetingH323CtrlWrap::GetH323Address);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Password", ZoomNodeMeetingH323CtrlWrap::GetH323Password);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCalloutH323DeviceList", ZoomNodeMeetingH323CtrlWrap::GetCalloutH323DeviceList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetH323CallOutStatusCB", ZoomNodeMeetingH323CtrlWrap::SetH323CallOutStatusCB);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingH323CtrlWrap >() {
	return &ZoomNodeMeetingH323CtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
