#ifndef _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#define _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingAudioCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >;
private:
	ZoomNodeSettingAudioCtrlWrap();
	~ZoomNodeSettingAudioCtrlWrap();
public:
	/**
	 * @brief Select mic device.
	 * @param deviceId Specify the device to be selected.
	 * @param deviceName Specify the device name assigned by deviceId.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the mic device list.
	 * @return If the function succeeds, the return value is the camera device list. Otherwise returns nullptr.
	 */
	static void GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Select speaker device.
	 * @param deviceId Specify the device to be selected.
	 * @param deviceName Specify the device the device name assigned by deviceId.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the speaker device list.
	 * @return If the function succeeds, the return value is the camera device list. Otherwise returns nullptr.
	 */
	static void GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the audio automatically when join meeting.
	 * @return Enabled or disabled.
	 */
	static void IsAutoJoinAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to auto-adjust the mic volume.
	 * @return Enabled or disabled.
	 */
	static void IsAutoAdjustMicEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable the audio automatically when join meeting.
	 * @param bEnable true indicates to enable the audio automatically when join meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAutoJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable the auto-adjust mic volume.
	 * @param bEnable true indicates to enable to auto-adjust the mic volume.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAutoAdjustMic(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * @brief Notification of the SDK detects that the computer mic devices have been changed.
	 * @param pNewMicList The new list of all mic devices plugged into the computer.
	 */
	static void SetComputerMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the SDK detects that the computer speaker devices have been changed.
	 * @param pNewSpeakerList The new list of all speaker devices plugged into the computer.
	 */
	static void SetComputerSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the user that a microphone device is selected.
	 * @param deviceId Specify a device to be selected.
	 * @param deviceName Specify the device name assigned by deviceId.
	 */
	static void SetDefaultMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the user that a speaker device is selected.
	 * @param deviceId Specify a device to be selected.
	 * @param deviceName Specify the device the device name assigned by deviceId.
	 */
	static void SetDefaultSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable the stereo audio.
	 * @param bEnable true indicates to enable the stereo audio.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note This function is valid only if mic original input is enabled, otherwise invalid.
	 */
	static void EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the stereo audio.
	 * @return Enabled or disabled.
	 */
	static void IsStereoAudioEnable(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable the original input of mic.
	 * @param bEnable true indicates to enable the original input of mic.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableMicOriginalInput(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable the original input of mic.
	 * @return Enabled or disabled.
	 */
	static void IsMicOriginalInputEnable(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to press and hold the Space-bar to speak when muted.
	 * @param bEnable true indicates to press and hold the Space-bar to speak.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableHoldSpaceKeyToSpeak(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to press and hold the Space-bar to speak.
	 * @return Enabled or disabled.
	 */
	static void IsHoldSpaceKeyToSpeakEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to mute always the mic when join the meeting by VoiP.
	 * @param bEnable true indicates to enable to mute always the mic when join the meeting by VoiP.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAlwaysMuteMicWhenJoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to mute always the mic when join the meeting by VoiP.
	 * @return Enabled or disabled.
	 */
	static void IsAlwaysMuteMicWhenJoinVoipEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable or disable to prompt when the user joins the meeting using the third party audio.
	 * @param bEnable true indicates to enable to prompt.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSuppressAudioNotify(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the flag to enable/disable to prompt when the user joins the meeting using the third party audio.
	 * @return Enabled or disabled.
	 */
	static void IsSuppressAudioNotifyEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the echo cancellation level.
	 * @param level The new echo cancellation level to be set.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the echo cancellation level.
	 * @return The the echo cancellation level.
	 */
	static void GetEchoCancellationLevel(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the volume of the selected mic.
	 * @param value Specify the volume of the mic that varies between 0 and 255.
	 * @note The SDK will enable the default mic if there is no mic selected via SelectMic().
	 */
	static void SetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the volume of the selected mic.
	 * @param value [out] Specify the current volume of the mic.
	 */
	static void GetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the volume of the selected speaker.
	 * @param value Specify the volume of the speaker that varies between 0 and 255.
	 * @note The SDK will enable the default speaker if there is no speaker selected via SelectSpeaker.
	 */
	static void SetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the volume of the selected speaker.
	 * @param value [out] Specify the current volume of the speaker.
	 */
	static void GetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingAudioCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingAudioCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectMic", ZoomNodeSettingAudioCtrlWrap::SelectMic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicList", ZoomNodeSettingAudioCtrlWrap::GetMicList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectSpeaker", ZoomNodeSettingAudioCtrlWrap::SelectSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerList", ZoomNodeSettingAudioCtrlWrap::GetSpeakerList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoJoinAudioEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoJoinAudioEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoAdjustMicEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoAdjustMicEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoJoinAudio", ZoomNodeSettingAudioCtrlWrap::EnableAutoJoinAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoAdjustMic", ZoomNodeSettingAudioCtrlWrap::EnableAutoAdjustMic);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerMicDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetComputerMicDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerSpeakerDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetComputerSpeakerDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultMicDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetDefaultMicDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultSpeakerDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetDefaultSpeakerDeviceChangedCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableStereoAudio", ZoomNodeSettingAudioCtrlWrap::EnableStereoAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsStereoAudioEnable", ZoomNodeSettingAudioCtrlWrap::IsStereoAudioEnable);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMicOriginalInput", ZoomNodeSettingAudioCtrlWrap::EnableMicOriginalInput);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMicOriginalInputEnable", ZoomNodeSettingAudioCtrlWrap::IsMicOriginalInputEnable);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHoldSpaceKeyToSpeak", ZoomNodeSettingAudioCtrlWrap::EnableHoldSpaceKeyToSpeak);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHoldSpaceKeyToSpeakEnabled", ZoomNodeSettingAudioCtrlWrap::IsHoldSpaceKeyToSpeakEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysMuteMicWhenJoinVoip", ZoomNodeSettingAudioCtrlWrap::EnableAlwaysMuteMicWhenJoinVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysMuteMicWhenJoinVoipEnabled", ZoomNodeSettingAudioCtrlWrap::IsAlwaysMuteMicWhenJoinVoipEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSuppressAudioNotify", ZoomNodeSettingAudioCtrlWrap::EnableSuppressAudioNotify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSuppressAudioNotifyEnabled", ZoomNodeSettingAudioCtrlWrap::IsSuppressAudioNotifyEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetEchoCancellationLevel", ZoomNodeSettingAudioCtrlWrap::SetEchoCancellationLevel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEchoCancellationLevel", ZoomNodeSettingAudioCtrlWrap::GetEchoCancellationLevel);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMicVol", ZoomNodeSettingAudioCtrlWrap::SetMicVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicVol", ZoomNodeSettingAudioCtrlWrap::GetMicVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSpeakerVol", ZoomNodeSettingAudioCtrlWrap::SetSpeakerVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerVol", ZoomNodeSettingAudioCtrlWrap::GetSpeakerVol);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingAudioCtrlWrap >() {
	return &ZoomNodeSettingAudioCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
