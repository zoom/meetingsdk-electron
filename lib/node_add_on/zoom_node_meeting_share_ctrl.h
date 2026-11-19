#ifndef _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#define _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingShareCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >;
private:
	ZoomNodeMeetingShareCtrlWrap();
	~ZoomNodeMeetingShareCtrlWrap();
public:
	/**
	 * @brief Share the specified application.
	 * @param hwndSharedApp Specify the window handle of the application to be shared. If the hwndSharedApp can't be shared, the return value is the SDKERR_INVALID_PARAMETER error code. If the hwndSharedApp is nullptr, the primary monitor will be shared.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void StartAppShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Share the specified monitor.
	 * @param monitorID Specify the monitor ID to be shared. You may get the value via EnumDisplayMonitors System API.
	 * If the monitorID is nullptr, the primary monitor will be shared. For more details, see szDevice in MONITORINFOEX structure.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void StartMonitorShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop the current sharing.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void StopShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the changed sharing status.
	 * @param shareInfo Sharing information.
	 * @note The userId changes according to the status value. When the status value is the Sharing_Self_Send_Begin or Sharing_Self_Send_End, the userId is the user own ID. Otherwise, the value of userId is the sharer ID.
	 * @note When status is Sharing_Self_Send_Begin or Sharing_Other_Share_Begin, shareInfo.contentType can be
	 *       SHARE_TYPE_UNKNOWN temporarily. Do not treat UNKNOWN at this stage as the finalized share content type.
	 *       Wait for onShareContentNotification to get the finalized content type.
	 */
	static void SetOnSharingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of failure to start sharing.
	 */
	static void SetOnFailedToStartShareCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the changed optimizing video status.
	 * @param shareInfo Sharing information.
	 */
	static void SetOnOptimizingShareForVideoClipStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback when the video sharing quality has changed.
	 * @param quality The new quality in effect.
	 * @note Triggered only when the effective quality actually changes.
	 */
	static void SetOnVideoSharingQualityChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines whether the legal notice for white board is available.
	 * @return true indicates the legal notice for white board is available. Otherwise, false.
	 */
	static void IsWhiteboardLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the white board legal notices prompt.
	 */
	static void GetWhiteboardLegalNoticesPrompt(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the white board legal notices explained.
	 */
	static void GetWhiteboardLegalNoticesExplained(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the audio share mode before or during sharing.
	 * @param mode The mode for audio share.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void SetAudioShareMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the audio share mode.
	 * @param mode The mode for audio share, see AudioShareMode enum.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid for both ZOOM style and user custom interface mode.
	 */
	static void GetAudioShareMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingShareCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingShareCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAppShare", ZoomNodeMeetingShareCtrlWrap::StartAppShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartMonitorShare", ZoomNodeMeetingShareCtrlWrap::StartMonitorShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopShare", ZoomNodeMeetingShareCtrlWrap::StopShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSharingStatusCB", ZoomNodeMeetingShareCtrlWrap::SetOnSharingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnFailedToStartShareCB", ZoomNodeMeetingShareCtrlWrap::SetOnFailedToStartShareCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnOptimizingShareForVideoClipStatusChangedCB", ZoomNodeMeetingShareCtrlWrap::SetOnOptimizingShareForVideoClipStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnVideoSharingQualityChangedCB", ZoomNodeMeetingShareCtrlWrap::SetOnVideoSharingQualityChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsWhiteboardLegalNoticeAvailable", ZoomNodeMeetingShareCtrlWrap::IsWhiteboardLegalNoticeAvailable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWhiteboardLegalNoticesPrompt", ZoomNodeMeetingShareCtrlWrap::GetWhiteboardLegalNoticesPrompt);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWhiteboardLegalNoticesExplained", ZoomNodeMeetingShareCtrlWrap::GetWhiteboardLegalNoticesExplained);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetAudioShareMode", ZoomNodeMeetingShareCtrlWrap::SetAudioShareMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioShareMode", ZoomNodeMeetingShareCtrlWrap::GetAudioShareMode);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingShareCtrlWrap >() {
	return &ZoomNodeMeetingShareCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
