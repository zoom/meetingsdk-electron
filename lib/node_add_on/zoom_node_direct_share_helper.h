#ifndef _ZOOM_NODE_DIRECT_SHARE_HELPER_H_
#define _ZOOM_NODE_DIRECT_SHARE_HELPER_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeDirectShareHelperWrap :
	public ZoomWrapObject<ZoomNodeDirectShareHelperWrap >
{
	friend class ZoomWrapObject<ZoomNodeDirectShareHelperWrap >;
private:
	ZoomNodeDirectShareHelperWrap();
	~ZoomNodeDirectShareHelperWrap();
public:
	/**
	 * @brief Determines if it is able to start the direct sharing.
	 * @return If it is enabled to start the direct sharing, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanStartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if direct sharing is in progress.
	 * @return true if the direct sharing is in progress. Otherwise, false.
	 */
	static void IsDirectShareInProgress(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start direct sharing.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note This API can only be called by the logged in user.
	 */
	static void StartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop direct sharing.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note This API can only be called by the logged in user.
	 */
	static void StopDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback event will be triggered if the status of direct sharing changes.
	 * @param status Specifies the status of direct sharing.
	 * @param handler A pointer to the IDirectShareViaMeetingIDOrPairingCodeHandler. It is only valid when the value of status is DirectShare_Need_MeetingID_Or_PairingCode.
	 * @note The SDK user must set the value of the _paring_code or _meeting_number via the functions of IDirectShareViaMeetingIDOrPairingCodeHandler to  start direct sharing.
	 */
	static void SetDirectShareStatusUpdateCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Try to match with the specified meeting number.
	 * @param meetingNumber Specifies the meeting number.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void TryWithMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Try to match with the pairing code.
	 * @param pairingCode Specifies the pairing code.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void TryWithPairingCode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Delete the present direct sharing.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Cancel(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeDirectShareHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeDirectShareHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartDirectShare", ZoomNodeDirectShareHelperWrap::CanStartDirectShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDirectShareInProgress", ZoomNodeDirectShareHelperWrap::IsDirectShareInProgress);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartDirectShare", ZoomNodeDirectShareHelperWrap::StartDirectShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopDirectShare", ZoomNodeDirectShareHelperWrap::StopDirectShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDirectShareStatusUpdateCB", ZoomNodeDirectShareHelperWrap::SetDirectShareStatusUpdateCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TryWithMeetingNumber", ZoomNodeDirectShareHelperWrap::TryWithMeetingNumber);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TryWithPairingCode", ZoomNodeDirectShareHelperWrap::TryWithPairingCode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Cancel", ZoomNodeDirectShareHelperWrap::Cancel);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeDirectShareHelperWrap >() {
	return &ZoomNodeDirectShareHelperWrap::constructor;
}

#endif
