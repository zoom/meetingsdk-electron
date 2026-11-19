#ifndef _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#define _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSettingRecordingCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >;
private:
	ZoomNodeSettingRecordingCtrlWrap();
	~ZoomNodeSettingRecordingCtrlWrap();
public:
	/**
	 * @brief Set the path to save the recording file.
	 * @param szPath Specify the path to save the recording file.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the path to save the recording file.
	 * @return The path to save the recording file.
	 */
	static void GetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * @brief Notification of the current cloud recording storage information.
	 * @param storage_total_size Specify the total storage space.
	 * @param storage_used_size Specify the used storage space.
	 * @param allow_exceed_storage Specify whether the used space can overflow the total space.
	 */
	static void SetonCloudRecordingStorageInfoCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the user has the privilege to get the storage information for cloud recording.
	 * @return true if the user has the privilege. Otherwise, false.
	 */
	static void CanGetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the storage information of cloud recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note If the return value is SDKERR_SUCCESS, IRecordingSettingContextEvent.onCloudRecordingStorageInfo() will be triggered after the infermation has be retrieved.
	 */
	static void GetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the recording management URL. It returns the real url only after you retrieve the callback IRecordingSettingContextEvent.onCloudRecordingStorageInfo().
	 * @return true if enabled. Otherwise, false.
	 */
	static void GetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to get recording management URL.
	 * @param [out]bEnable true if the recording management URL can be retrieved. Otherwise, false. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanGetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set whether to enable the function of selecting the path to save the recording file after meeting.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSelectRecordFileLocationAfterMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the function of selecting storage path for recording file is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsSelectRecordFileLocationAfterMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable/Disable multi-audio stream recording.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableMultiAudioStreamRecord(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if multi-audio stream recording is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsMultiAudioStreamRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable/Disable watermark of timestamp.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAddTimestampWatermark(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the watermark of timestamps is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsAddTimestampWatermarkEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable/Disable the optimization for the third party video editor.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableOptimizeFor3rdPartyVideoEditor(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the third party video editor is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsOptimizeFor3rdPartyVideoEditorEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable/Disable showing the video thumbnail when sharing.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableShowVideoThumbnailWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if video thumbnail is enabled when sharing.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsShowVideoThumbnailWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable/Disable placing the video layout next to the shared content in recording file.
	 * @param bEnable true if enabled. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnablePlaceVideoNextToShareInRecord(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if placing video next to the shared content in recording file is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsPlaceVideoNextToShareInRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingRecordingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingRecordingCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::SetRecordingPath);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::GetRecordingPath);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCloudRecordingStorageInfoCB", ZoomNodeSettingRecordingCtrlWrap::SetonCloudRecordingStorageInfoCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanGetCloudRecordingStorageInfo", ZoomNodeSettingRecordingCtrlWrap::CanGetCloudRecordingStorageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCloudRecordingStorageInfo", ZoomNodeSettingRecordingCtrlWrap::GetCloudRecordingStorageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingManagementURL", ZoomNodeSettingRecordingCtrlWrap::GetRecordingManagementURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanGetRecordingManagementURL", ZoomNodeSettingRecordingCtrlWrap::CanGetRecordingManagementURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSelectRecordFileLocationAfterMeeting", ZoomNodeSettingRecordingCtrlWrap::EnableSelectRecordFileLocationAfterMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSelectRecordFileLocationAfterMeetingEnabled", ZoomNodeSettingRecordingCtrlWrap::IsSelectRecordFileLocationAfterMeetingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMultiAudioStreamRecord", ZoomNodeSettingRecordingCtrlWrap::EnableMultiAudioStreamRecord);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMultiAudioStreamRecordEnabled", ZoomNodeSettingRecordingCtrlWrap::IsMultiAudioStreamRecordEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAddTimestampWatermark", ZoomNodeSettingRecordingCtrlWrap::EnableAddTimestampWatermark);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAddTimestampWatermarkEnabled", ZoomNodeSettingRecordingCtrlWrap::IsAddTimestampWatermarkEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableOptimizeFor3rdPartyVideoEditor", ZoomNodeSettingRecordingCtrlWrap::EnableOptimizeFor3rdPartyVideoEditor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsOptimizeFor3rdPartyVideoEditorEnabled", ZoomNodeSettingRecordingCtrlWrap::IsOptimizeFor3rdPartyVideoEditorEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowVideoThumbnailWhenShare", ZoomNodeSettingRecordingCtrlWrap::EnableShowVideoThumbnailWhenShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShowVideoThumbnailWhenShareEnabled", ZoomNodeSettingRecordingCtrlWrap::IsShowVideoThumbnailWhenShareEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnablePlaceVideoNextToShareInRecord", ZoomNodeSettingRecordingCtrlWrap::EnablePlaceVideoNextToShareInRecord);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsPlaceVideoNextToShareInRecordEnabled", ZoomNodeSettingRecordingCtrlWrap::IsPlaceVideoNextToShareInRecordEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingRecordingCtrlWrap >() {
	return &ZoomNodeSettingRecordingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
