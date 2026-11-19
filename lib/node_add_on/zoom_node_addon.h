#ifndef _ZOOM_NODE_ADDON_H_
#define _ZOOM_NODE_ADDON_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

class ZOOM_NODE_HIDE ZoomNodeAuthWrap :
	public ZoomWrapObject<ZoomNodeAuthWrap >
{
	//
	friend class ZoomWrapObject<ZoomNodeAuthWrap >;
private:
	ZoomNodeAuthWrap();
	~ZoomNodeAuthWrap();
public:
	/**
	 * @brief Authenticates SDK.
	 * @param authContext The parameter to be used for authentication SDK.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SDKAuth(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Account logout.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Logout(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get authentication status.
	 * @return The return value is authentication status.
	 */
	static void GetAuthResult(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get login status.
	 * @return The return value is login status.
	 */
	static void GetLoginStatus(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of logout.
	 */
	static void SetLogoutCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of authentication result.
	 * @param ret Authentication result value.
	 */
	static void SetOnAuthReturnCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of Zoom identity has expired, please re-login or generate a new zoom access token via REST Api.
	 */
	static void SetOnZoomIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get direct share service helper interface. 
	 * @return If you logged in your account successfully, the return value is the object pointer IDirectShareServiceHelper. Otherwise is nullptr.
	 */
	static void GetDirectShareHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of Zoom authentication identity will be expired in 10 minutes, please re-auth.
	 */
	static void SetOnZoomAuthIdentityExpiredCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of login result with fail reason.
	 * @param ret Login status.
	 * @param pAccountInfo Valid when the ret is LOGINRET_SUCCESS. Otherwise nullptr.
	 * @param reason Login fail reason. Valid when the ret is LOGIN_FAILED. Otherwise LoginFail_None.
	 */
	static void SetLoginReturnWithReasonCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get SSO login web url.
	 * @param prefix_of_vanity_url prefix of vanity url. 
	 * @return SSO login web url
	 */
	static void GenerateSSOLoginWebURL(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Account login.
	 * @param uri_protocol For the parameter to be used for sso account login
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note You need to call this APIs after IAuthServiceEvent::onAuthenticationReturn(AUTHRET_SUCCESS).
	 */
	static void SSOLoginWithWebUriProtocol(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeAuthWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeAuthWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SDKAuth", ZoomNodeAuthWrap::SDKAuth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Logout", ZoomNodeAuthWrap::Logout);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthResult", ZoomNodeAuthWrap::GetAuthResult);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetLoginStatus", ZoomNodeAuthWrap::GetLoginStatus);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLogoutCB", ZoomNodeAuthWrap::SetLogoutCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDirectShareHelperObj", ZoomNodeAuthWrap::GetDirectShareHelperObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAuthReturnCB", ZoomNodeAuthWrap::SetOnAuthReturnCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnZoomIdentityExpiredCB", ZoomNodeAuthWrap::SetOnZoomIdentityExpiredCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnZoomAuthIdentityExpiredCB", ZoomNodeAuthWrap::SetOnZoomAuthIdentityExpiredCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLoginReturnWithReasonCB", ZoomNodeAuthWrap::SetLoginReturnWithReasonCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GenerateSSOLoginWebURL", ZoomNodeAuthWrap::GenerateSSOLoginWebURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SSOLoginWithWebUriProtocol", ZoomNodeAuthWrap::SSOLoginWithWebUriProtocol);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeAuthWrap >() {
	return &ZoomNodeAuthWrap::constructor;
}

class ZOOM_NODE_HIDE ZoomNodeWrap : public ZoomWrapObject<ZoomNodeWrap >
{
	friend class ZoomWrapObject<ZoomNodeWrap >;
private:
	ZoomNodeWrap() {}
	~ZoomNodeWrap() {}

public:
	/**
	 * @brief Initialize ZOOM SDK.
	 * @param path On win os is the sdk.dll path. On mac os is empty.
	 * @param domain Web domain.
	 * @param langid The ID of the SDK language. see ZNSDK_LANGUAGE_ID enum.
	 * @param langName Resource name.
	 * @param langInfo The value should be the full path of the resource file when the langType value is CustomizedLanguage_FilePath, including the file name. When the langType value is CustomizedLanguage_Content, the value saves the content of the resource.
	 * @param strSupportUrl Support URL.
	 * @param enable_log Enable log feature.
	 * @param locale Locale
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void InitSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Clean up ZOOM SDK.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CleanUPSDK(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Auth Service Module.
	 */
	static void GetAuthObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Service Module.
	 */
	static void GetMeetingObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Setting Service Module.
	 */
	static void GetSetObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Customized Resource Service Module.
	 */
	static void GetCustomizedResourceObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK SMS Helper Service Module.
	 */
	static void GetSDKSMSHelperObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the version of ZOOM SDK.
	 * @return The version of ZOOM SDK.
	 */
	static void GetZoomSDKVersion(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static void GetRawdataAPIWrap(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "InitSDK", ZoomNodeWrap::InitSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CleanUPSDK", ZoomNodeWrap::CleanUPSDK);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAuthObj", ZoomNodeWrap::GetAuthObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingObj", ZoomNodeWrap::GetMeetingObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSetObj", ZoomNodeWrap::GetSetObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCustomizedResourceObj", ZoomNodeWrap::GetCustomizedResourceObj);
	
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetZoomSDKVersion", ZoomNodeWrap::GetZoomSDKVersion);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSDKSMSHelperObj", ZoomNodeWrap::GetSDKSMSHelperObj);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawdataAPIWrap", ZoomNodeWrap::GetRawdataAPIWrap);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeWrap >() {
	return &ZoomNodeWrap::constructor;
}

class AddonData {
public:
	explicit AddonData(v8::Isolate* isolate)
	{
		node::AddEnvironmentCleanupHook(isolate, DeleteInstance, this);
	}

	v8::Local<v8::Object> zoomNodeWrapInstance;

	static void DeleteInstance(void* data) {
		delete static_cast<AddonData*>(data);
	}
};

class ZOOM_NODE_HIDE ZoomNodeMeetingWrap :
	public ZoomWrapObject<ZoomNodeMeetingWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingWrap >;
private:
	ZoomNodeMeetingWrap();
	~ZoomNodeMeetingWrap();
public:
	/**
	 * @brief Start meeting.
	 * @param meetingNumber Meeting number.
	 * @param hDirectShareAppWnd The window handle of the direct sharing application.
	 * @param participantId The ID of attendees. The SDK will set this value when the associated settings are turned on.
	 * @param isVideoOff Turn off video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isAudioOff Turn off audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isDirectShareDesktop Share the desktop directly or not. true indicates to Share.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Start(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start meeting.
	 * @param userId [Required] User ID.  
	 * @param userToken [Required] User token. 
	 * @param userZAK [Required] ZOOM access token. 
	 * @param username [Required] Username. 
	 * @param zoomuserType [Required] Zoom user type. See ZNZoomUserType enum.
	 * @param meetingNumber [Optinal] Meeting number.
	 * @param sdkVanityID [Optinal] Meeting vanity ID
	 * @param hDirectShareAppWnd [Optinal] The window handle of the direct sharing application.
	 * @param participantId [Optinal] The ID of attendees. The SDK will set this value when the associated settings are turned on.
	 * @param isDirectShareDesktop [Optinal] Share the desktop directly or not. true indicates to share.
	 * @param isVideoOff [Optinal] Turn off the video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isAudioOff [Optinal] Turn off the audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Start_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Join the meeting.
	 * @param meetingNumber Meeting number.
	 * @param sdkVanityID Meeting vanity ID.
	 * @param username Username when logged in the meeting.
	 * @param psw Meeting password.
	 * @param hDirectShareAppWnd The window handle of the direct sharing application.
	 * @param participantId The ID of attendees. The SDK will set this value when the associated settings are turned on.
	 * @param webinarToken Webinar token.
	 * @param isVideoOff Turn off the video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isAudioOff Turn off the audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isDirectShareDesktop Share the desktop directly or not. true indicates to share.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Join(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Join the meeting.
	 * @param meetingNumber [Required] Meeting number. Meeting number or VanityID is required.
	 * @param sdkVanityID [Optinal] Meeting vanity ID. Meeting number or VanityID is required.
	 * @param username [Optinal] Username 
	 * @param psw [Optinal] Meeting password.
	 * @param hDirectShareAppWnd [Optinal] The window handle of the direct sharing application.
	 * @param token4EnforceLogin [Optinal] Use the token if the meeting requests to login.
	 * @param participantId [Optinal] The ID of attendees. The SDK will set this value when the associated settings are turned on.
	 * @param webinarToken [Optinal] Webinar token.
	 * @param isDirectShareDesktop [Optinal] Share the desktop directly or not. true indicates to share.
	 * @param isVideoOff [Optinal] Turn off the video or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @param isAudioOff [Optinal] Turn off the audio or not. true indicates to turn off. In addition, this flag is affected by meeting attributes.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Join_WithoutLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Leave meeting.
	 * @param leaveCmd Leave meeting command.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Leave(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Lock the current meeting.
	 * @return If the function succeeds, the return value is the SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Lock(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Unlock the current meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Unlock(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the current user can change the meeting topic.
	 * @return If it can change the meeting topic, the return value is true.
	 */
	static void CanSetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Change the meeting topic.
	 * @param sTopic The new meeting topic. 
	 * @return If the function succeeds, the return value is the SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Meeting status changed callback.
	 * @param status The value of meeting.
	 * @param iResult Detailed reasons for special meeting status.
	 * If the status is MEETING_STATUS_FAILED, the value of iResult is one of those listed in MeetingFailCode enum. 
	 * If the status is MEETING_STATUS_ENDED, the value of iResult is one of those listed in MeetingEndReason.
	 */
	static void SetMeetingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get meeting information.
	 * @return If the function succeeds, the return value is the meeting information. Otherwise returns nullptr.
	 */
	static void GetMeetingInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting UI Controller Module.
	 */
	static void GetMeetingUICtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Annotation Controller Module.
	 */
	static void GetMeetingAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Audio Controller Module.
	 */
	static void GetMeetingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Video Controller Module.
	 */
	static void GetMeetingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Recording Controller Module.
	 */
	static void GetMeetingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Participants Controller Module.
	 */
	static void GetMeetingParticipantsCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Share Controller Module.
	 */
	static void GetMeetingShareCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting H323 Controller Module.
	 */
	static void GetMeetingH323Ctrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Configuration Controller Module.
	 */
	static void GetMeetingConfigCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the quality of Internet connection when sharing.
	 * @param bSending true indicates to get the connection quality of sending the sharing statistics. false indicates to get the connection quality of receiving the sharing statistics.
	 * @return If the function succeeds, the return is one of those enumerated in ConnectionQuality enum.
	 * @note If you are not in the meeting, the Conn_Quality_Unknown will be returned.
	 */
	static void GetSharingConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the Internet connection quality of video.
	 * @param bSending true indicates to get the connection quality of sending the video. false indicates to get the connection quality of receiving the video.
	 * @return If the function succeeds, the return is one of those enumerated in ConnectionQuality enum.
	 * @note If you are not in the meeting, the Conn_Quality_Unknown will be returned.
	 */
	static void GetVideoConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the Internet connection quality of audio.
	 * @param bSending true indicates to get the connection quality of sending the audio. false indicates to get the connection quality of receiving the audio.
	 * @return If the function succeeds, the return value is one of those enumerated in ConnectionQuality enum.
	 * @note If you are not in the meeting, the Conn_Quality_Unknown will be returned.
	 */
	static void GetAudioConnQuality(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get meeting audio statistics information.
	 * @param info_ [out] Audio statistics information.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetMeetingAudioStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get meeting video statistics information.
	 * @param info_ [out] Video statistics information.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetMeetingVideoStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get meeting share statistics information.
	 * @param info_ [out] Share statistics information.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetMeetingShareStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Join meeting with web uri
	 * @param protocol_action Specifies the web uri
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void HandleZoomWebUriProtocolAction(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetMeetingAAN(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetMeetingRawArchivingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetMeetingLiveStreamCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	/**
	 * @brief Get Zoom SDK Meeting Reminder Controller Module.
	 */
	static void GetMeetingReminderCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	/**
	 * @brief Get Zoom SDK Meeting Chat Controller Module.
	 */
	static void GetMeetingChatCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Waiting Room Controller Module.
	 */
	static void GetMeetingWaitingRoomCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting AI Companion Controller Module.
	 */
	static void GetMeetingAICompanionCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Indicator Controller Module.
	 */
	static void GetMeetingIndicatorCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Webinar Controller Module.
	 */
	static void GetMeetingWebinarCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting QA Controller Module.
	 */
	static void GetMeetingQACtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Reaction Controller Module.
	 */
	static void GetMeetingReactionCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Close Caption Controller Module.
	 */
	static void GetMeetingCloseCaptionCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Polling Controller Module.
	 */
	static void GetMeetingPollingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Whiteboard Controller Module.
	 */
	static void GetMeetingWhiteboardCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get Zoom SDK Meeting Docs Controller Module.
	 */
	static void GetMeetingDocsCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetRequestRawLiveStreamPrivilegeHandler(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Meeting statistics warning notification callback.
	 * @param type The warning type of the meeting statistics.
	 */
	static void SetMeetingStatisticsWarningNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Meeting parameter notification callback.
	 * @param meeting_param Meeting parameter.
	 * @note The callback will be triggered right before the meeting starts. The meeting_param will be destroyed once the function calls end.
	 */
	static void SetMeetingParameterNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event for the meeting topic changed. 
	 * @param sTopic The new meeting topic.
	 */
	static void SetOnMeetingTopicChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Calback event that the meeting users have reached the meeting capacity.
	 *  The new join user can not join meeting, but they can watch the meeting live stream.
	 * @param sLiveStreamUrl The live stream URL to watch the meeting live stream.
	 */
	static void SetOnMeetingFullToWatchLiveStreamCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Called when the user's share network quality changes.
	 * @param type The data type whose network quality changed.
	 * @param level The new network quality level for the specified data type.
	 * @param userId The user whose network quality changed.
	 * @param uplink This data is uplink or downlink.
	 */
	static void SetOnUserNetworkStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event when the app signal panel is updated.
	 * @param handler The handler object to control the app signal panel.
	 * @note Only available for the custom UI.
	 */
	static void SetOnAppSignalPanelUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check if the app signal panel can be shown.
	 * @return true if the app signal panel can be shown, false otherwise.
	 */
	static void CanShowPanel(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Show the app signal panel window.
	 * @param x The horizontal coordinate value.
	 * @param y The vertical coordinate value.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowPanel(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Hide the app signal panel window.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void HidePanel(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start", ZoomNodeMeetingWrap::Start);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Join", ZoomNodeMeetingWrap::Join);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Leave", ZoomNodeMeetingWrap::Leave);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Lock", ZoomNodeMeetingWrap::Lock);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Unlock", ZoomNodeMeetingWrap::Unlock);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Start_WithoutLogin", ZoomNodeMeetingWrap::Start_WithoutLogin);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Join_WithoutLogin", ZoomNodeMeetingWrap::Join_WithoutLogin);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSetMeetingTopic", ZoomNodeMeetingWrap::CanSetMeetingTopic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingTopic", ZoomNodeMeetingWrap::SetMeetingTopic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingStatusCB", ZoomNodeMeetingWrap::SetMeetingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingStatisticsWarningNotificationCB", ZoomNodeMeetingWrap::SetMeetingStatisticsWarningNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingParameterNotificationCB", ZoomNodeMeetingWrap::SetMeetingParameterNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnMeetingTopicChangedCB", ZoomNodeMeetingWrap::SetOnMeetingTopicChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnMeetingFullToWatchLiveStreamCB", ZoomNodeMeetingWrap::SetOnMeetingFullToWatchLiveStreamCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserNetworkStatusChangedCB", ZoomNodeMeetingWrap::SetOnUserNetworkStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAppSignalPanelUpdatedCB", ZoomNodeMeetingWrap::SetOnAppSignalPanelUpdatedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanShowPanel", ZoomNodeMeetingWrap::CanShowPanel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowPanel", ZoomNodeMeetingWrap::ShowPanel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HidePanel", ZoomNodeMeetingWrap::HidePanel);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingInfo", ZoomNodeMeetingWrap::GetMeetingInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingUICtrl", ZoomNodeMeetingWrap::GetMeetingUICtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAnnotation", ZoomNodeMeetingWrap::GetMeetingAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAudioCtrl", ZoomNodeMeetingWrap::GetMeetingAudioCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingVideoCtrl", ZoomNodeMeetingWrap::GetMeetingVideoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingRecordingCtrl", ZoomNodeMeetingWrap::GetMeetingRecordingCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingParticipantsCtrl", ZoomNodeMeetingWrap::GetMeetingParticipantsCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingShareCtrl", ZoomNodeMeetingWrap::GetMeetingShareCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingH323Ctrl", ZoomNodeMeetingWrap::GetMeetingH323Ctrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingConfigCtrl", ZoomNodeMeetingWrap::GetMeetingConfigCtrl);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSharingConnQuality", ZoomNodeMeetingWrap::GetSharingConnQuality);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoConnQuality", ZoomNodeMeetingWrap::GetVideoConnQuality);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioConnQuality", ZoomNodeMeetingWrap::GetAudioConnQuality);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAudioStatisticInfo", ZoomNodeMeetingWrap::GetMeetingAudioStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingVideoStatisticInfo", ZoomNodeMeetingWrap::GetMeetingVideoStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingShareStatisticInfo", ZoomNodeMeetingWrap::GetMeetingShareStatisticInfo);

	NODE_SET_PROTOTYPE_METHOD(tpl, "HandleZoomWebUriProtocolAction", ZoomNodeMeetingWrap::HandleZoomWebUriProtocolAction);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAAN", ZoomNodeMeetingWrap::GetMeetingAAN);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingRawArchivingCtrl", ZoomNodeMeetingWrap::GetMeetingRawArchivingCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingLiveStreamCtrl", ZoomNodeMeetingWrap::GetMeetingLiveStreamCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequestRawLiveStreamPrivilegeHandler", ZoomNodeMeetingWrap::GetRequestRawLiveStreamPrivilegeHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingReminderCtrl", ZoomNodeMeetingWrap::GetMeetingReminderCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingChatCtrl", ZoomNodeMeetingWrap::GetMeetingChatCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingWaitingRoomCtrl", ZoomNodeMeetingWrap::GetMeetingWaitingRoomCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingAICompanionCtrl", ZoomNodeMeetingWrap::GetMeetingAICompanionCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingIndicatorCtrl", ZoomNodeMeetingWrap::GetMeetingIndicatorCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingWebinarCtrl", ZoomNodeMeetingWrap::GetMeetingWebinarCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingQACtrl", ZoomNodeMeetingWrap::GetMeetingQACtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingReactionCtrl", ZoomNodeMeetingWrap::GetMeetingReactionCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingCloseCaptionCtrl", ZoomNodeMeetingWrap::GetMeetingCloseCaptionCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingPollingCtrl", ZoomNodeMeetingWrap::GetMeetingPollingCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingWhiteboardCtrl", ZoomNodeMeetingWrap::GetMeetingWhiteboardCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingDocsCtrl", ZoomNodeMeetingWrap::GetMeetingDocsCtrl);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingWrap >() {
	return &ZoomNodeMeetingWrap::constructor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeMeetingInfoWrap :
	public ZoomWrapObject<ZoomNodeMeetingInfoWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingInfoWrap >;
private:
	ZoomNodeMeetingInfoWrap() {}
	~ZoomNodeMeetingInfoWrap() {}
public:
	/**
	 * @brief Get the meeting topic.
	 * @return If the function succeeds, the return value is the current meeting topic. Otherwise returns an empty string of length ZERO(0)
	 */
	static void GetMeetingTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the meeting type.
	 * @return If the function succeeds, the return value is the current meeting type.
	 */
	static void GetMeetingType(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the current meeting number.
	 * @return If the function succeeds, the return value is the current meeting number. Otherwise returns ZERO(0).
	 */
	static void GetMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the current meeting ID.
	 * @return If the function succeeds, the return value is the current meeting ID. Otherwise returns an empty string of length ZERO(0).
	 */
	static void GetMeetingID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the email invitation template for the current meeting.
	 * @return If the function succeeds, the return value is the email invitation template. Otherwise returns nullptr.
	 */
	static void GetInviteEmailTemplate(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the meeting title in the email invitation template.
	 * @return If the function succeeds, the return value is the meeting title. Otherwise returns nullptr.
	 */
	static void GetInviteEmailTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the URL of invitation to join the meeting.
	 * @return If the function succeeds, the return value is the URL of invitation. Otherwise returns nullptr.
	 */
	static void GetJoinMeetingUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the host tag of the current meeting.
	 * @return If the function succeeds, the return value is the host tag. Otherwise returns nullptr.
	 */
	static void GetMeetingHostTag(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingInfoWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingInfoWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingTopic", ZoomNodeMeetingInfoWrap::GetMeetingTopic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingType", ZoomNodeMeetingInfoWrap::GetMeetingType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingNumber", ZoomNodeMeetingInfoWrap::GetMeetingNumber);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingID", ZoomNodeMeetingInfoWrap::GetMeetingID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetInviteEmailTemplate", ZoomNodeMeetingInfoWrap::GetInviteEmailTemplate);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetInviteEmailTitle", ZoomNodeMeetingInfoWrap::GetInviteEmailTitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetJoinMeetingUrl", ZoomNodeMeetingInfoWrap::GetJoinMeetingUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingHostTag", ZoomNodeMeetingInfoWrap::GetMeetingHostTag);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingInfoWrap >() {
	return &ZoomNodeMeetingInfoWrap::constructor;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeMeetingUICtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingUICtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingUICtrlWrap >;
private:
	ZoomNodeMeetingUICtrlWrap();
	~ZoomNodeMeetingUICtrlWrap();
public:
	/**
	 * @brief Show the chat dialog during the meeting.
	 * @param hParent Parent window handle.
	 * @param left Left position of chat dialog.
	 * @param top Top position of chat dialog.
	 * @param right Right position of chat dialog.
	 * @param bottom Bottom position of chat dialog.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Hide the chat dialog during the meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void HideChatDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enter full screen display mode.
	 * @param firstView true indicates to enable the full screen mode for the first view.
	 * @param secondView true indicates to enable the full screen mode for the second view if it is in the dual view mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnterFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Exit the full screen display mode.
	 * @param firstView true indicates to exit the full screen mode for the first view.
	 * @param secondView true indicates to exit the full screen mode for the second view if it is in the dual view mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ExitFullScreen(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Switch to video wall mode. 
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwitchToVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Switch to the mode of showing the current speaker.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwitchToActiveSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Move the floating video window.
	 * @param left Sets the left margin edge for the floating video window. Please use the coordinate of the screen.
	 * @param top Sets the top margin edge for the floating video window. Please use the coordinate of the screen.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void MoveFloatVideoWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable to display the floating sharing toolbar.
	 * @param bShow true indicates to display the floating toolbar.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note This function works only in the share mode. 
	 */
	static void ShowSharingToolbar(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Switch to current speaker mode on the floating window. 
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwitchFloatVideoToActiveSpkMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Adjust the display mode of floating window. 
	 * @param type Specify the type of the floating video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ChangeFloatToActiveSpkVideoSize(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Switch to gallery view mode on the floating window. 
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwitchFloatVideoToGalleryMod(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Display/hide the window which is used to display the list of the participants. 
	 * @param bShow true indicates to display the list of the participants.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowParticipantsListWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Display/hide the toolbar at the bottom of the meeting window. 
	 * @param bShow true indicates to display the toolbar.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowBottomFloatToolbarWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Display the dialog to choose the audio to join the meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Hide the dialog to choose the audio to join the meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void HideJoinAudioDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the information in video wall mode.
	 * @param currentPage 0 can be used to initialize.
	 * @param totalPages 0 can be used to initialize.
	 * @return If the function succeeds, the return value is a object which includes "err", "currentPage" and "totalPages".
	 */
	static void GetWallViewPageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Show the video users on previous page or next page in video wall mode.
	 * @param bPageUp true indicates to show the video users on previous page, false next page.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The function does not work if the window shows the first or last page. The return value is SDKERR_SUCCESS in this case.
	 */
	static void ShowPreOrNextPageVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the green frame when sharing the desktop.
	 * @param bShow true indicates to display the frame. false hide.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ShowSharingFrameWindows(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the information whether the current view supports split screen mode or not. If supports, check it if it is already in the split screen mode.
	 * @param bZNSupportSplitScreen false can be used to initialize.
	 * @param bZNInSplitScreenMode false can be used to initialize.
	 * @return If the function succeeds, the return value is a object which includes "err", "bZNSupportSplitScreen" and "bZNInSplitScreenMode".
	 */
	static void GetCurrentSplitScreenModeInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Switch to the split screen mode or cancel.
	 * @param bSplit true indicates to switch to the split screen mode. false cancel.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note true does not work if it is in the split screen mode. false does not work if it is not the split screen mode.
	 */
	static void SwitchSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event to click the INVITE button.
	 * @param bHandled true indicates to show the user's own custom dialog interface. Default value: false.
	 * @note If the value of bHandled is not set to true, the default interface will pop up. 
	 */
	static void SetInviteButtonClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Active the principal window of meeting and place it on top.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. If the function fails, the return value is not SDKERR_SUCCESS. To get extended error information, refer to SDKError enum.
	 */
	static void BackToMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the window handle of the meeting user interface.
	 * @param hFirstView If the function succeeds, the parameter will save the window handle of the meeting user interface displayed by the first view.
	 * @param hSecondView If the function succeeds, the parameter will save the window handle of the meeting user interface displayed by the second view.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Change the display mode of the minimized meeting window for the first view.
	 * @param mode Specifies the minimized mode.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwitchMinimizeUIMode4FirstScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines the minimize state of the first view.
	 * @param mode If the function succeeds, the parameter will save the display mode.
	 * @return true if the minimize state. Otherwise, false.
	 */
	static void IsMinimizeModeOfFirstScreenMeetingUIWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief when someone else shares, and meeting window is not full screen. you can call the api to switch video & share display postion. 
	 * @param bToDisplayShare true indicates to display share, otherwise video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the meeting is displaying the sharing screen now.
	 * @param bIsShare true indicates is showing sharing screen, false indicates is showing video.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void IsDisplayingShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the user can swap to show sharing screen or video now.
	 * @param bCan true indicates can. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanSwapToShowShareViewOrVideo(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the cloud recording manage url in the recording setting page. 
	 * @param crmURL Specify the cloud recording manage url in the recording setting page.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetCustomizedCloudRecordingMgrUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the invitation domain. 
	 * @param invitation_domain Specify the invitation domain.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetCustomizedInvitationDomain(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Allowing the developer to customize the URL of create/edit the polling. 
	 * @param URL customized URL.
	 * @param bCreate When bCreate is true, it changes the URL of creating a polling. Otherwise, it changes the URL of editing a polling..
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetCustomizedPollingUrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * @brief Callback event for clicking START SHARE button.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the SHARE button. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickShareBTNEvent().
	 */
	static void SetonStartShareBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of clicking the END MEETING button.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the END MEETING button. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickEndMeetingBTNEvent().
	 */
	static void SetonEndMeetingBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of clicking PRTICIPANT LIST button.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the PARTICIPANT LIST button. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickParticipantListBTNEvent().
	 */
	static void SetonParticipantListBtnClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of clicking CUSTOME LIVE STREAM menu.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the CUSTOME LIVE STREAM menu. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickCustomLiveStreamMenuEvent().
	 */
	static void SetonCustomLiveStreamMenuClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification occurs only when the SDK fails to display the default ZOOM INVITE dialog.
	 */
	static void SetonZoomInviteDialogFailedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of clicking CC menu.
	 * @note The user won't receive this callback event unless he redirects the process of clicking the CUSTOME LIVE STREAM menu. For more details, see IMeetingUIElemConfiguration::RedirectClickCCBTNEvent() .
	 */
	static void SetonCCBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event for clicking Audio button in the meeting.
	 * @param info The suggested action information for user to handle after getting the callback event.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the Audio button in the meeting. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickAudioBTNEvent() .
	 */
	static void SetonAudioBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event for clicking Audio Menu button in the meeting.
	 * @note The user won't receive this callback event unless he sets to redirect the process of clicking the Audio Menu button in the meeting. 
	 * For more details, see IMeetingUIElemConfiguration::RedirectClickAudioMenuBTNEvent() .
	 */
	static void SetonAudioMenuBTNClickedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingUICtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingUICtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowChatDlg", ZoomNodeMeetingUICtrlWrap::ShowChatDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideChatDlg", ZoomNodeMeetingUICtrlWrap::HideChatDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnterFullScreen", ZoomNodeMeetingUICtrlWrap::EnterFullScreen);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ExitFullScreen", ZoomNodeMeetingUICtrlWrap::ExitFullScreen);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchToVideoWall", ZoomNodeMeetingUICtrlWrap::SwitchToVideoWall);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchToActiveSpeaker", ZoomNodeMeetingUICtrlWrap::SwitchToActiveSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MoveFloatVideoWnd", ZoomNodeMeetingUICtrlWrap::MoveFloatVideoWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSharingToolbar", ZoomNodeMeetingUICtrlWrap::ShowSharingToolbar);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchFloatVideoToActiveSpkMod", ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToActiveSpkMod);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ChangeFloatToActiveSpkVideoSize", ZoomNodeMeetingUICtrlWrap::ChangeFloatToActiveSpkVideoSize);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchFloatVideoToGalleryMod", ZoomNodeMeetingUICtrlWrap::SwitchFloatVideoToGalleryMod);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowParticipantsListWnd", ZoomNodeMeetingUICtrlWrap::ShowParticipantsListWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowBottomFloatToolbarWnd", ZoomNodeMeetingUICtrlWrap::ShowBottomFloatToolbarWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowJoinAudioDlg", ZoomNodeMeetingUICtrlWrap::ShowJoinAudioDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideJoinAudioDlg", ZoomNodeMeetingUICtrlWrap::HideJoinAudioDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWallViewPageInfo", ZoomNodeMeetingUICtrlWrap::GetWallViewPageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowPreOrNextPageVideo", ZoomNodeMeetingUICtrlWrap::ShowPreOrNextPageVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSharingFrameWindows", ZoomNodeMeetingUICtrlWrap::ShowSharingFrameWindows);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentSplitScreenModeInfo", ZoomNodeMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchSplitScreenMode", ZoomNodeMeetingUICtrlWrap::SwitchSplitScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetInviteButtonClickedCB", ZoomNodeMeetingUICtrlWrap::SetInviteButtonClickedCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "BackToMeeting", ZoomNodeMeetingUICtrlWrap::BackToMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::GetMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwitchMinimizeUIMode4FirstScreenMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::SwitchMinimizeUIMode4FirstScreenMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMinimizeModeOfFirstScreenMeetingUIWnd", ZoomNodeMeetingUICtrlWrap::IsMinimizeModeOfFirstScreenMeetingUIWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SwapToShowShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::SwapToShowShareViewOrVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDisplayingShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::IsDisplayingShareViewOrVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSwapToShowShareViewOrVideo", ZoomNodeMeetingUICtrlWrap::CanSwapToShowShareViewOrVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetCustomizedCloudRecordingMgrUrl", ZoomNodeMeetingUICtrlWrap::SetCustomizedCloudRecordingMgrUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetCustomizedInvitationDomain", ZoomNodeMeetingUICtrlWrap::SetCustomizedInvitationDomain);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetCustomizedPollingUrl", ZoomNodeMeetingUICtrlWrap::SetCustomizedPollingUrl);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonStartShareBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonStartShareBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonEndMeetingBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonEndMeetingBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonParticipantListBtnClickedCB", ZoomNodeMeetingUICtrlWrap::SetonParticipantListBtnClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCustomLiveStreamMenuClickedCB", ZoomNodeMeetingUICtrlWrap::SetonCustomLiveStreamMenuClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonZoomInviteDialogFailedCB", ZoomNodeMeetingUICtrlWrap::SetonZoomInviteDialogFailedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCCBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonCCBTNClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonAudioBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonAudioBTNClickedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonAudioMenuBTNClickedCB", ZoomNodeMeetingUICtrlWrap::SetonAudioMenuBTNClickedCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingUICtrlWrap >() {
	return &ZoomNodeMeetingUICtrlWrap::constructor;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeSettingWrap :
	public ZoomWrapObject<ZoomNodeSettingWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingWrap >;
private:
	ZoomNodeSettingWrap();
	~ZoomNodeSettingWrap();
public:
	/**
	 * @brief Display Meeting Setting dialog.
	 * @param hParent Parent window handle.
	 * @param left The X-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	 * @param top The Y-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	 * @param hSettingWnd Window handle of the dialog setting.
	 * @param bShow Enable to display or not.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void ShowSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Hide meeting setting dialog.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void HideSettingDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Video Setting Controller Module.
	 */
	static void GetSettingVideoCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Audio Setting Controller Module.
	 */
	static void GetSettingAudioCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK General Setting Controller Module.
	 */
	static void GetSettingGeneralCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Recording Setting Controller Module.
	 */
	static void GetSettingRecordingCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Wallpaper Controller Module.
	 */
	static void GetSettingWallpaperCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Meeting Virtual BG Controller Module.
	 */
	static void GetSettingVirtualBGCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Setting UI Strategy Controller Module.
	 */
	static void GetSettingUIStrategyCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Setting Statistic Controller Module.
	 */
	static void GetSettingStatisticCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Setting Accessibility Controller Module.
	 */
	static void GetSettingAccessibilityCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get Zoom SDK Setting Share Controller Module.
	 */
	static void GetSettingShareCtrl(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeSettingWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowSettingDlg", ZoomNodeSettingWrap::ShowSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideSettingDlg", ZoomNodeSettingWrap::HideSettingDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingVideoCtrl", ZoomNodeSettingWrap::GetSettingVideoCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingAudioCtrl", ZoomNodeSettingWrap::GetSettingAudioCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingGeneralCtrl", ZoomNodeSettingWrap::GetSettingGeneralCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingRecordingCtrl", ZoomNodeSettingWrap::GetSettingRecordingCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingWallpaperCtrl", ZoomNodeSettingWrap::GetSettingWallpaperCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingVirtualBGCtrl", ZoomNodeSettingWrap::GetSettingVirtualBGCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingUIStrategyCtrl", ZoomNodeSettingWrap::GetSettingUIStrategyCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingStatisticCtrl", ZoomNodeSettingWrap::GetSettingStatisticCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingAccessibilityCtrl", ZoomNodeSettingWrap::GetSettingAccessibilityCtrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSettingShareCtrl", ZoomNodeSettingWrap::GetSettingShareCtrl);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingWrap >() {
	return &ZoomNodeSettingWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
