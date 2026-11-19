#ifndef _ZOOM_NODE_MEETING_RECORDING_CTRL_H_
#define _ZOOM_NODE_MEETING_RECORDING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingRecordingCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingRecordingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingRecordingCtrlWrap >;
private:
	ZoomNodeMeetingRecordingCtrlWrap();
	~ZoomNodeMeetingRecordingCtrlWrap();
public:
	
	/**
	 * @brief Start recording.
	 * @param startTimestamp The timestamps when start recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop recording.
	 * @param stopTimestamp The timestamps when stop recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the specified user is enabled to start recording.
	 * @param cloud_recording true indicates to determine whether to enable the cloud recording. false local recording.
	 * @param userid Specifies the user ID.
	 * @return If the value of cloud_recording is set to true and the cloud recording is enabled, the return value is SDKERR_SUCCESS.
	 * If the value of cloud_recording is set to false and the local recording is enabled, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanStartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the current user own the authority to change the recording permission of the others.
	 * @return If the user own the authority, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanAllowDisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start cloud recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop cloud recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the specified user is enabled to start local recording.
	 * @param userid Specifies the user ID.
	 * @return If the specified user is enabled to start local recording, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void IsSupportLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Give the specified user authority for local recording.
	 * @param userid Specifies the user ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Abrogate the authority of the specified user for local recoding.
	 * @param userid Specifies the user ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Send a request to ask the host to start cloud recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS and the SDK sends the request. Otherwise, this function returns an error and the request is not sent.
	 */
	static void RequestStartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the smart recording feature is enabled in the meeting.
	 * @return true indicates that the feature enabled, false indicates that the feature isn't enabled.
	 */
	static void IsSmartRecordingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Whether the current user can enable the smart recording feature.
	 * @return true indicates the current user can enable the smart recording feature.
	 */
	static void CanEnableSmartRecordingFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable the smart recording feature.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the user ID who requested that the host start cloud recording.
	 * @return If the function succeeds, the return value is the user ID. Otherwise, this returns 0.
	 */
	static void GetRequesterId(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user name who requested that the host start cloud recording.
	 * @return If the function succeeds, the return value is the user name.
	 */
	static void GetRequesterName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Accept the request to start cloud recording and then destroys the IRequestCloudRecordingHandler instance.
	 */
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Deny the request to start cloud recording and then destroys the IRequestCloudRecordingHandler instance.
	 * @param bDenyAll true indicates to deny all requests. Participants can't send requests again until the host change the setting.
	 */
	static void Deny(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the user ID who requests to enable and start smart cloud recording.
	 * @return If the function succeeds, the return value is the user ID.
	 */
	static void GetRequestEnableAndStartSmartRecordingUserId(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the legal tip that you should agree to handle the user request.
	 * @return If the function succeeds, the return value is the legal notice about enabling and starting smart cloud recording.
	 */
	static void GetRequestEnableAndStartSmartRecordingTipString(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start normal cloud recording without enabling smart recording.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartCloudRecordingWithoutEnableSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Agree to the legal notice to enable and start smart cloud recording.
	 * @param bAllMeetings true indicates to enable smart recording for all future meetings including the current meeting. false indicates to only enable smart recording for the current meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AgreeToEnableAndStartSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the request to start cloud recording.
	 * @param bDenyAll true indicates to deny all attendees' requests for the host to start cloud recording. Participants can't send these types of requests again until the host change the setting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeclineEnableAndStartSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the legal tip to enable smart recording.
	 * @return The legal notice.
	 */
	static void GetSmartRecordingEnableActionTipString(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Confirm enabling and starting the smart recording.
	 * @param bAllMeetings true indicates to enable smart recording for all future meetings including the current meeting. false indicates to only enable smart recording for the current meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ActionConfirmEnableSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Cancel enabling and starting the smart recording
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ActionCancelEnableSmartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of ending the conversion to MP4 format.
	 * @param bsuccess true indicates to convert successfully. false not.
	 * @param iResult This value is used to save the error code only when the convert fails.
	 * @param szPath If the conversion is successful, this value is used to save the path of the recording file.
	 * @note In order to trigger this callback correctly, you need call IMeetingConfiguration.EnableLocalRecordingConvertProgressBarDialog(false) before you start a meeting.
	 */
	static void SetonRecording2MP4DoneCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of the process of the conversion to MP4 format.
	 * @param iPercentage Percentage of conversion process. Range from ZERO(0) to ONE HUNDREAD(100).
	 * @note In order to trigger this callback correctly, you need call IMeetingConfiguration.EnableLocalRecordingConvertProgressBarDialog(false) before you start a meeting.
	 */
	static void SetonRecording2MP4ProcessingCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that the status of my local recording changes.
	 * @param status Value of recording status.
	 */
	static void SetonRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that the status of cloud recording changes.
	 * @param status Value of recording status.
	 */
	static void SetonCloudRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that the recording authority changes.
	 * @param bCanRec true indicates to enable to record.
	 */
	static void SetonRecordPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event that the cloud recording storage is full.
	 * @param gracePeriodDate a point in time, in milliseconds, in UTC. You can use the cloud recording storage until the gracePeriodDate.
	 */
	static void SetonCloudRecordingStorageFullCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event for when the host responds to a cloud recording permission request
	 * @param status Value of request host to start cloud recording response status.
	 */
	static void SetonRequestCloudRecordingResponseCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event received only by the host when a user requests to start cloud recording.
	 * @param handler A pointer to the IRequestStartCloudRecordingHandler.
	 */
	static void SetonStartCloudRecordingRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event received only by the host when a user requests to enable and start smart cloud recording.
	 * @param handler A pointer to the IRequestEnableAndStartSmartRecordingHandler.
	 */
	static void SetonEnableAndStartSmartRecordingRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event received when you call EnableSmartRecording. You can use the handler to confirm or cancel enabling the smart recording.
	 * @param handler A pointer to the ISmartRecordingEnableActionHandler.
	 */
	static void SetonSmartRecordingEnableActionCallback(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingRecordingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingRecordingCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartRecording", ZoomNodeMeetingRecordingCtrlWrap::StartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopRecording", ZoomNodeMeetingRecordingCtrlWrap::StopRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartRecording", ZoomNodeMeetingRecordingCtrlWrap::CanStartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanAllowDisAllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::CanAllowDisAllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartCloudRecording", ZoomNodeMeetingRecordingCtrlWrap::StartCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopCloudRecording", ZoomNodeMeetingRecordingCtrlWrap::StopCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::IsSupportLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::AllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisAllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::DisAllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestStartCloudRecording", ZoomNodeMeetingRecordingCtrlWrap::RequestStartCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSmartRecordingEnabled", ZoomNodeMeetingRecordingCtrlWrap::IsSmartRecordingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanEnableSmartRecordingFeature", ZoomNodeMeetingRecordingCtrlWrap::CanEnableSmartRecordingFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::EnableSmartRecording);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequesterId", ZoomNodeMeetingRecordingCtrlWrap::GetRequesterId);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequesterName", ZoomNodeMeetingRecordingCtrlWrap::GetRequesterName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeMeetingRecordingCtrlWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Deny", ZoomNodeMeetingRecordingCtrlWrap::Deny);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequestEnableAndStartSmartRecordingUserId", ZoomNodeMeetingRecordingCtrlWrap::GetRequestEnableAndStartSmartRecordingUserId);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequestEnableAndStartSmartRecordingTipString", ZoomNodeMeetingRecordingCtrlWrap::GetRequestEnableAndStartSmartRecordingTipString);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartCloudRecordingWithoutEnableSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::StartCloudRecordingWithoutEnableSmartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AgreeToEnableAndStartSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::AgreeToEnableAndStartSmartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeclineEnableAndStartSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::DeclineEnableAndStartSmartRecording);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSmartRecordingEnableActionTipString", ZoomNodeMeetingRecordingCtrlWrap::GetSmartRecordingEnableActionTipString);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ActionConfirmEnableSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::ActionConfirmEnableSmartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ActionCancelEnableSmartRecording", ZoomNodeMeetingRecordingCtrlWrap::ActionCancelEnableSmartRecording);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecording2MP4DoneCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4DoneCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecording2MP4ProcessingCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4ProcessingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecordingStatusCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecordingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCloudRecordingStatusCB", ZoomNodeMeetingRecordingCtrlWrap::SetonCloudRecordingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecordPrivilegeChangedCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecordPrivilegeChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCloudRecordingStorageFullCB", ZoomNodeMeetingRecordingCtrlWrap::SetonCloudRecordingStorageFullCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRequestCloudRecordingResponseCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRequestCloudRecordingResponseCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonStartCloudRecordingRequestedCB", ZoomNodeMeetingRecordingCtrlWrap::SetonStartCloudRecordingRequestedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonEnableAndStartSmartRecordingRequestedCB", ZoomNodeMeetingRecordingCtrlWrap::SetonEnableAndStartSmartRecordingRequestedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonSmartRecordingEnableActionCallback", ZoomNodeMeetingRecordingCtrlWrap::SetonSmartRecordingEnableActionCallback);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingRecordingCtrlWrap >() {
	return &ZoomNodeMeetingRecordingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
