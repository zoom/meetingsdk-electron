#ifndef _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#define _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >;
private:
	ZoomNodeSettingVideoCtrlWrap();
	~ZoomNodeSettingVideoCtrlWrap();
public:
	/**
	 * @brief Select camera device.
	 * @param deviceId Specify a device to be selected.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get camera device list.
	 * @return If the function succeeds, the return value the is camera device list. Otherwise returns nullptr.
	 */
	static void GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable video mirror effect.
	 * @param bEnable true indicates to enable the video mirror effect.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable the video facial beauty effect.
	 * @param bEnable true indicates to enable the video facial beauty effect.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Checks whether the video mirror effect is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the video facial beauty effect.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * @brief Callback event if the SDK detects that the computer camera devices have been changed.
	 * @param pNewCameraList The new list of all camera devices plugged into the computer.
	 */
	static void SetComputerCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notify the user that a camera device is selected.
	 * @param deviceId Specify a device to be selected.
	 * @param deviceName Specify the device name assigned by deviceId.
	 */
	static void SetDefaultCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable HD video.
	 * @param bEnable true indicates to enable the HD video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableHDVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the HD video.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsHDVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to show the username on the video.
	 * @param bEnable true indicates to show the username on the video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAlwaysShowNameOnVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to show the username on video.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsAlwaysShowNameOnVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to show the video preview dialog when join meeting
	 * @param bEnable true indicates to enable to show the video preview dialog when join meeting
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableVideoPreviewDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable to show the video preview dialog when join meeting.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsVideoPreviewDialogEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to turn off the video when join meeting
	 * @param bEnable true indicates to enable to turn off the video when join meeting
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAutoTurnOffVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable to turn off the video when join meeting.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsAutoTurnOffVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to spotlight the video.
	 * @param bEnable true indicates to enable to spotlight the video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSpotlightSelf(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to spotlight video.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsSpotlightSelfEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable the hardware acceleration.
	 * @param bEnable true indicates to enable the hardware acceleration.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableHardwareEncode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the hardware acceleration.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsHardwareEncodeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to show the participants in Gallery View up to 49 per screen.
	 * @param bEnable true indicates to show the participants in Gallery View up to 49 per screen.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Enable49VideoesInGallaryView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to show the participants in Gallery View up to 49 per screen.
	 * @return true if enabled. Otherwise, false.
	 */
	static void Is49VideoesInGallaryViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to hide the non-video participants.
	 * @param bEnable true indicates to hide the non-video Participants.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableHideNoVideoUsersOnWallView(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to hide non-video participants.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsHideNoVideoUsersOnWallViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingVideoCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectVideoCamera", ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCameraList", ZoomNodeSettingVideoCtrlWrap::GetCameraList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoMirrorEffect", ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableFaceBeautyEffect", ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMirrorEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsFaceBeautyEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerCamDeviceChangedCB", ZoomNodeSettingVideoCtrlWrap::SetComputerCamDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultCamDeviceChangedCB", ZoomNodeSettingVideoCtrlWrap::SetDefaultCamDeviceChangedCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHDVideo", ZoomNodeSettingVideoCtrlWrap::EnableHDVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHDVideoEnabled", ZoomNodeSettingVideoCtrlWrap::IsHDVideoEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysShowNameOnVideo", ZoomNodeSettingVideoCtrlWrap::EnableAlwaysShowNameOnVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysShowNameOnVideoEnabled", ZoomNodeSettingVideoCtrlWrap::IsAlwaysShowNameOnVideoEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoPreviewDialog", ZoomNodeSettingVideoCtrlWrap::EnableVideoPreviewDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsVideoPreviewDialogEnabled", ZoomNodeSettingVideoCtrlWrap::IsVideoPreviewDialogEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoTurnOffVideoWhenJoinMeeting", ZoomNodeSettingVideoCtrlWrap::EnableAutoTurnOffVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoTurnOffVideoWhenJoinMeetingEnabled", ZoomNodeSettingVideoCtrlWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSpotlightSelf", ZoomNodeSettingVideoCtrlWrap::EnableSpotlightSelf);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSpotlightSelfEnabled", ZoomNodeSettingVideoCtrlWrap::IsSpotlightSelfEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHardwareEncode", ZoomNodeSettingVideoCtrlWrap::EnableHardwareEncode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHardwareEncodeEnabled", ZoomNodeSettingVideoCtrlWrap::IsHardwareEncodeEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Enable49VideoesInGallaryView", ZoomNodeSettingVideoCtrlWrap::Enable49VideoesInGallaryView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Is49VideoesInGallaryViewEnabled", ZoomNodeSettingVideoCtrlWrap::Is49VideoesInGallaryViewEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHideNoVideoUsersOnWallView", ZoomNodeSettingVideoCtrlWrap::EnableHideNoVideoUsersOnWallView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHideNoVideoUsersOnWallViewEnabled", ZoomNodeSettingVideoCtrlWrap::IsHideNoVideoUsersOnWallViewEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingVideoCtrlWrap >() {
	return &ZoomNodeSettingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
