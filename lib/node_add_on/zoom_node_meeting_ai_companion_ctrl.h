#ifndef _ZOOM_NODE_MEETING_AI_COMPANION_CTRL_H_
#define _ZOOM_NODE_MEETING_AI_COMPANION_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAICompanionCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingAICompanionCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAICompanionCtrlWrap >;
private:
	ZoomNodeMeetingAICompanionCtrlWrap();
	~ZoomNodeMeetingAICompanionCtrlWrap();
public:
	/**
	 * @brief Determines whether the current meeting supports turning off the AI Companion features.
	 * @return true if supported. Otherwise, false.
	 */
	static void IsTurnoffAllAICompanionsSupported(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current meeting supports turning on the AI Companion features.
	 * @return true if supported. Otherwise, false.
	 */
	static void IsTurnOnAllAICompanionsSupported(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can turn off the AI Companion features.
	 * @return true indicates the user can turn off the AI Companion features.
	 */
	static void CanTurnOffAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can turn on the AI Companion features.
	 * @return true indicates the user can turn on the AI Companion features.
	 */
	static void CanTurnOnAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Turn off the AI Companion features.
	 * @note All AI features including smart summary, smart recording and query can be turned off at once.
	 * @param deleteAssets Specify whether delete the meeting assets when turn off the AI Companion features.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void TurnOffAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Turn on the AI Companion features.
	 * @note smart summary and query can be turned on at once.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void TurnOnAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can request host to turn off all started AI Companion features.
	 * @note if the current user join the meeting before the host, they can check CanTurnOffAllAICompanions to turn off the AI Companion features by himself/herself.
	 * All AI features include smart summary, smart recording and query can be requested to turn off at once.
	 * @return true indicates the user can request host to turn off all started AI Companion features.
	 */
	static void CanRequestTurnoffAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can request host to turn on all AI Companion features if they are enabled for the current meeting.
	 * @note smart summary and query can be requested to turn on at once.
	 * @return true indicates the user can request host to turn on the AI Companion features.
	 */
	static void CanRequestTurnOnAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief request host to turn off all started AI Companion features.
	 * @note All AI features include smart summary, smart recording and query can be requested to turn off at once.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void RequestTurnoffAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief request host to turn on all AI Companion features if they are enabled for the current meeting.
	 * @note Only smart summary and query can be requested to turn on at once.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void RequestTurnOnAllAICompanions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of features that the participant turns off.
	 */
	static void GetFeatureList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the list of features that the assets are deleted when the feature is turned off by participant.
	 */
	static void GetAssetsDeletedFeatureList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Turn on the auto AI Companion feature which was stopped by the participant before the host or cohost joined meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void TurnOnAgain(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Agree the auto AI Companion feature turn off status. Keep the AI Companion feature off.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AgreeTurnOff(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user ID who requests host to turn the AI Companion features on or off.
	 * @return the request user ID.
	 */
	static void GetRequestUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Turn the AI Companion features on or off.
	 * @return true indicates turn on the AI Companion features, false indicates turn off the AI Companion features.
	 */
	static void IsTurnOn(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Agree the request to turn the AI companion features on or off.
	 * @param deleteAssets Specify whether delete the meeting assets when turning off the AI Companion features.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Agree(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the request to turn the AI companion features on or off.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void Decline(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the auto start AI Companion feature is turned off by a participant before the host join. Only the host or cohost can receive this callback.
	 * @param handler A pointer to the IAutoAICompanionFeatureTurnOnAgainHandler.
	 */
	static void SetOnAICompanionFeatureTurnOffByParticipantCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of host receives the request to turn the AI Companion features on or off.
	 * @param handler A pointer to the IAICompanionFeatureSwitchHandler.
	 */
	static void SetOnAICompanionFeatureSwitchRequestedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the host handles the request to turn the AI Companion features on or off.
	 * @param timeout Specify the host not handle the request until timeout.
	 * @param bAgree Specify the host agrees to the request to turn the AI companion features on or off.
	 * @param bTurnOn Specify the host respond the request of turn on or off.
	 */
	static void SetOnAICompanionFeatureSwitchRequestResponseCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the started AI Companion feature can't be turned off.
	 * @param features Specify the AI Companion features that can't be turned off.
	 */
	static void SetOnAICompanionFeatureCanNotBeTurnedOffCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Sink the event when the host's client does not support handling the stop Notes request.
	 * @note This callback is triggered when a participant requests to stop Notes, but the meeting host's client version does not support processing this request.
	 */
	static void SetOnHostUnsupportedStopNotesRequestCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Enable smart summary.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if this handler is requesting enable smart summary.
	 * @return true indicates this handler is for requesting enable smart summary. Otherwise, false.
	 */
	static void IsForRequestEnableSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start smart summary.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if this handler is for requesting to start the smart summary.
	 * @return true indicates this handler is requesting to start the smart summary. Otherwise, false.
	 */
	static void IsForRequestStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop smart summary.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user ID of the requester.
	 * @return The user ID of the requester.
	 */
	static void GetSenderEnableSmartSummaryUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Continue approve action.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ContinueApproveEnableSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user ID of the requester.
	 * @return The user ID of the requester.
	 */
	static void GetSenderStartSmartSummaryUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Approve request.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ApproveStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline request.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeclineStartSmartSummary(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the title of tip.
	 * @return The title of tip.
	 */
	static void GetEnableSmartSummaryActionTipTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the string of tip.
	 * @return The string of tip.
	 */
	static void GetEnableSmartSummaryActionTipString(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Confirm enabling smart summary.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ConfirmEnableSmartSummaryAction(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Cancel enabling smart summary.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CancelEnableSmartSummaryAction(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meting does not support smart summary.
	 */
	static void SetOnSmartSummaryStateNotSupportedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meeting support smart summary but smart summary feature is disabled.
	 * @param handler The handler to enable smart summary.
	 */
	static void SetOnSmartSummaryStateSupportedButDisabledCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meeting smart summary is not started.
	 * @param handler The handler to start smart summary.
	 */
	static void SetOnSmartSummaryStateEnabledButNotStartedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meeting smart summary is started.
	 * @param handler The handler to stop smart summary. If the user can not stop smart summary, the handler will be null.
	 */
	static void SetOnSmartSummaryStateStartedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of failed to start the smart summary.
	 * @param bTimeout true indicates timeout. Otherwise, no timeout. May be declined by host or cohost.
	 */
	static void SetOnFailedToStartSmartSummaryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving request to enable smart summary.
	 * @param handler The handler to handle enable smart summary request.
	 */
	static void SetOnSmartSummaryEnableRequestReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving request to start smart summary.
	 * @param handler The handler to handle request.
	 */
	static void SetOnSmartSummaryStartRequestReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving smart summary enable action.
	 * @param handler The handler to enable smart summary.
	 */
	static void SetOnSmartSummaryEnableActionCallbackCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines whether the current user can change query setting.
	 * @param bCan true indicates that it can change the setting. Otherwise, it cannot change the setting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CanChangeQuerySetting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Change query setting.
	 * @param setting The query setting. For more details, see \link MeetingAICompanionQuerySettingOptions \endlink.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ChangeQuerySettings(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the selected query setting.
	 * @return If the function succeeds, it returns the selected query setting. Otherwise, this function returns an error.
	 */
	static void GetSelectedQuerySetting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the legal notice for the AI Companion query is available.
	 * @param bAvailable true indicates the legal notice for the AI Companion query is available. Otherwise the legal notice is not available.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void IsAICompanionQueryLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the AI Companion query legal notices prompt.
	 * @return If the function succeeds, it returns the AI Companion query legal notices prompt. Otherwise, this function fails and returns nullptr.
	 */
	static void GetAICompanionQueryLegalNoticesPrompt(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the AI Companion query legal notices explained.
	 * @return If the function succeeds, it returns the AI Companion query legal notices explained. Otherwise, this function fails and returns nullptr.
	 */
	static void GetAICompanionQueryLegalNoticesExplained(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the legal notice for the AI Companion query privacy is available.
	 * @param bAvailable true indicates the legal notice for the AI Companion query privacy is available. Otherwise the legal notice is not available.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void IsAICompanionQueryPrivacyLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the AI Companion query privacy legal notices prompt.
	 * @return If the function succeeds, it returns the AI Companion query privacy legal notices prompt. Otherwise, this function fails and returns nullptr.
	 */
	static void GetAICompanionQueryPrivacyLegalNoticesPrompt(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable meeting query.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if this handler for request enable query.
	 * @return true indicates this handler is for request enable query. Otherwise it returns false indicates this handler is for enable query directly.
	 */
	static void IsForRequestEnableQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Start meeting query.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartMeetingQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if this handler for request start query.
	 * @return true indicates this handler is for request start query. Otherwise it returns false indicates this handler is for start query directly.
	 */
	static void IsForRequestStartMeetingQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get default query questions.
	 * @return If the function succeeds, it returns the array of questions. Otherwise, this function fails and returns nullptr.
	 */
	static void GetDefaultQueryQuestions(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Send query question.
	 * @param question The query question.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SendQueryQuestion(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Stop meeting query.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StopMeetingQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the current user can send query.
	 * @return true indicates can. Otherwise, false.
	 */
	static void CanSendQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Request send query privilege.
	 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
	 */
	static void RequestSendQueryPrivilege(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the user id of requester.
	 * @return The user ID of the requester.
	 */
	static void GetSenderEnableQueryUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Continue approve action.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ContinueApproveEnableQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the requester's user ID.
	 * @return The user ID of the requester.
	 */
	static void GetSenderStartQueryUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Approve the request.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ApproveStartQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the request.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeclineStartQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Send feedback of query answer.
	 * @param eFeedbackType The feedback type. For more details, see \link MeetingAICompanionQueryFeedbackType \endlink.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void AICompanionQueryFeedback(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the title of the tip.
	 * @return The title of tip.
	 */
	static void GetEnableQueryActionTipTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the tip string.
	 * @return The string of tip.
	 */
	static void GetEnableQueryActionTipString(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Confirm enable query. The object will be deleted after this interface call.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ConfirmEnableQueryAction(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Cancel enable query. The object will be deleted after this interface call.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CancelEnableQueryAction(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the requester's user ID.
	 * @return The user ID of the requester.
	 */
	static void GetSenderQueryUserID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Approve the request.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ApproveSendQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Decline the request.
	 * @param bDeclineAll true indicates decline all requests.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeclineSendQuery(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meeting does not support query.
	 */
	static void SetOnQueryStateNotSupportedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the meeting supports query but query feature is disabled.
	 * @param pHandler The handler to enable the query.
	 */
	static void SetOnQueryStateSupportedButDisabledCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the query is not started.
	 * @param pHandler The handler to start the query.
	 */
	static void SetOnQueryStateEnabledButNotStartedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the query is started.
	 * @param pHandler The handler to send query.
	 */
	static void SetOnQueryStateStartedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the query setting is changed.
	 * @param eSetting The selected query setting.
	 */
	static void SetOnQuerySettingChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the query failed to start.
	 * @param bTimeout true indicates timeout. Otherwise, it indicates that the user declines the request.
	 */
	static void SetOnFailedToStartQueryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving request to enable query.
	 * @param pHandler The handler to handle the request.
	 */
	static void SetOnReceiveRequestToEnableQueryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving request to start query.
	 * @param pHandler The handler to handle the request.
	 */
	static void SetOnReceiveRequestToStartQueryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving query answer.
	 * @param pHandler The object of IMeetingAICompanionQueryItem.
	 */
	static void SetOnReceiveQueryAnswerCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving query enable action callback.
	 * @param pHandler The handler to enable the query.
	 */
	static void SetOnQueryEnableActionCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of getting or losing send query question privilege.
	 * @param canSendQuery true indicates can send. Otherwise, not.
	 */
	static void SetOnSendQueryPrivilegeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of the request to send query failed.
	 * @param bTimeout true indicates that the request timed out. Otherwise, it indicates that the user declines the request.
	 */
	static void SetOnFailedToRequestSendQueryCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Notification of receiving request to send query.
	 * @param handler The handler to handle the request.
	 */
	static void SetOnReceiveRequestToSendQueryCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
void InitClassAttribute<ZoomNodeMeetingAICompanionCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAICompanionCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	// IMeetingAICompanionController
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsTurnoffAllAICompanionsSupported", ZoomNodeMeetingAICompanionCtrlWrap::IsTurnoffAllAICompanionsSupported);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsTurnOnAllAICompanionsSupported", ZoomNodeMeetingAICompanionCtrlWrap::IsTurnOnAllAICompanionsSupported);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanTurnOffAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::CanTurnOffAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanTurnOnAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::CanTurnOnAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOffAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::TurnOffAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOnAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::TurnOnAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestTurnoffAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::CanRequestTurnoffAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanRequestTurnOnAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::CanRequestTurnOnAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestTurnoffAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::RequestTurnoffAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestTurnOnAllAICompanions", ZoomNodeMeetingAICompanionCtrlWrap::RequestTurnOnAllAICompanions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetFeatureList", ZoomNodeMeetingAICompanionCtrlWrap::GetFeatureList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAssetsDeletedFeatureList", ZoomNodeMeetingAICompanionCtrlWrap::GetAssetsDeletedFeatureList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOnAgain", ZoomNodeMeetingAICompanionCtrlWrap::TurnOnAgain);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOnAgain", ZoomNodeMeetingAICompanionCtrlWrap::TurnOnAgain);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AgreeTurnOff", ZoomNodeMeetingAICompanionCtrlWrap::AgreeTurnOff);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequestUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetRequestUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsTurnOn", ZoomNodeMeetingAICompanionCtrlWrap::IsTurnOn);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Agree", ZoomNodeMeetingAICompanionCtrlWrap::Agree);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Decline", ZoomNodeMeetingAICompanionCtrlWrap::Decline);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAICompanionFeatureTurnOffByParticipantCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnAICompanionFeatureTurnOffByParticipantCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAICompanionFeatureSwitchRequestedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnAICompanionFeatureSwitchRequestedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAICompanionFeatureSwitchRequestResponseCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnAICompanionFeatureSwitchRequestResponseCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAICompanionFeatureCanNotBeTurnedOffCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnAICompanionFeatureCanNotBeTurnedOffCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnHostUnsupportedStopNotesRequestCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnHostUnsupportedStopNotesRequestCB);
	// IMeetingAICompanionSmartSummaryHelper
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::EnableSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsForRequestEnableSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::IsForRequestEnableSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::StartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsForRequestStartSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::IsForRequestStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::StopSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSenderEnableSmartSummaryUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetSenderEnableSmartSummaryUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ContinueApproveEnableSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::ContinueApproveEnableSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSenderStartSmartSummaryUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetSenderStartSmartSummaryUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ApproveStartSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::ApproveStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeclineStartSmartSummary", ZoomNodeMeetingAICompanionCtrlWrap::DeclineStartSmartSummary);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEnableSmartSummaryActionTipTitle", ZoomNodeMeetingAICompanionCtrlWrap::GetEnableSmartSummaryActionTipTitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEnableSmartSummaryActionTipString", ZoomNodeMeetingAICompanionCtrlWrap::GetEnableSmartSummaryActionTipString);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfirmEnableSmartSummaryAction", ZoomNodeMeetingAICompanionCtrlWrap::ConfirmEnableSmartSummaryAction);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelEnableSmartSummaryAction", ZoomNodeMeetingAICompanionCtrlWrap::CancelEnableSmartSummaryAction);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStateNotSupportedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryStateNotSupportedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStateSupportedButDisabledCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryStateSupportedButDisabledCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStateEnabledButNotStartedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryStateEnabledButNotStartedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStateStartedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryStateStartedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnFailedToStartSmartSummaryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnFailedToStartSmartSummaryCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryEnableRequestReceivedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryEnableRequestReceivedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryStartRequestReceivedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryStartRequestReceivedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSmartSummaryEnableActionCallbackCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSmartSummaryEnableActionCallbackCB);
	// IMeetingAICompanionQueryHelper
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanChangeQuerySetting", ZoomNodeMeetingAICompanionCtrlWrap::CanChangeQuerySetting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ChangeQuerySettings", ZoomNodeMeetingAICompanionCtrlWrap::ChangeQuerySettings);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSelectedQuerySetting", ZoomNodeMeetingAICompanionCtrlWrap::GetSelectedQuerySetting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAICompanionQueryLegalNoticeAvailable", ZoomNodeMeetingAICompanionCtrlWrap::IsAICompanionQueryLegalNoticeAvailable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAICompanionQueryLegalNoticesPrompt", ZoomNodeMeetingAICompanionCtrlWrap::GetAICompanionQueryLegalNoticesPrompt);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAICompanionQueryLegalNoticesExplained", ZoomNodeMeetingAICompanionCtrlWrap::GetAICompanionQueryLegalNoticesExplained);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAICompanionQueryPrivacyLegalNoticeAvailable", ZoomNodeMeetingAICompanionCtrlWrap::IsAICompanionQueryPrivacyLegalNoticeAvailable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAICompanionQueryPrivacyLegalNoticesPrompt", ZoomNodeMeetingAICompanionCtrlWrap::GetAICompanionQueryPrivacyLegalNoticesPrompt);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableQuery", ZoomNodeMeetingAICompanionCtrlWrap::EnableQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsForRequestEnableQuery", ZoomNodeMeetingAICompanionCtrlWrap::IsForRequestEnableQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartMeetingQuery", ZoomNodeMeetingAICompanionCtrlWrap::StartMeetingQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsForRequestStartMeetingQuery", ZoomNodeMeetingAICompanionCtrlWrap::IsForRequestStartMeetingQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDefaultQueryQuestions", ZoomNodeMeetingAICompanionCtrlWrap::GetDefaultQueryQuestions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SendQueryQuestion", ZoomNodeMeetingAICompanionCtrlWrap::SendQueryQuestion);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopMeetingQuery", ZoomNodeMeetingAICompanionCtrlWrap::StopMeetingQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSendQuery", ZoomNodeMeetingAICompanionCtrlWrap::CanSendQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestSendQueryPrivilege", ZoomNodeMeetingAICompanionCtrlWrap::RequestSendQueryPrivilege);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSenderEnableQueryUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetSenderEnableQueryUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ContinueApproveEnableQuery", ZoomNodeMeetingAICompanionCtrlWrap::ContinueApproveEnableQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSenderStartQueryUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetSenderStartQueryUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ApproveStartQuery", ZoomNodeMeetingAICompanionCtrlWrap::ApproveStartQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeclineStartQuery", ZoomNodeMeetingAICompanionCtrlWrap::DeclineStartQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AICompanionQueryFeedback", ZoomNodeMeetingAICompanionCtrlWrap::AICompanionQueryFeedback);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEnableQueryActionTipTitle", ZoomNodeMeetingAICompanionCtrlWrap::GetEnableQueryActionTipTitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetEnableQueryActionTipString", ZoomNodeMeetingAICompanionCtrlWrap::GetEnableQueryActionTipString);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfirmEnableQueryAction", ZoomNodeMeetingAICompanionCtrlWrap::ConfirmEnableQueryAction);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelEnableQueryAction", ZoomNodeMeetingAICompanionCtrlWrap::CancelEnableQueryAction);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSenderQueryUserID", ZoomNodeMeetingAICompanionCtrlWrap::GetSenderQueryUserID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ApproveSendQuery", ZoomNodeMeetingAICompanionCtrlWrap::ApproveSendQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeclineSendQuery", ZoomNodeMeetingAICompanionCtrlWrap::DeclineSendQuery);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQueryStateNotSupportedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQueryStateNotSupportedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQueryStateSupportedButDisabledCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQueryStateSupportedButDisabledCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQueryStateEnabledButNotStartedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQueryStateEnabledButNotStartedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQueryStateStartedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQueryStateStartedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQuerySettingChangedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQuerySettingChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnFailedToStartQueryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnFailedToStartQueryCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveRequestToEnableQueryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnReceiveRequestToEnableQueryCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveRequestToStartQueryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnReceiveRequestToStartQueryCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveQueryAnswerCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnReceiveQueryAnswerCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQueryEnableActionCallback", ZoomNodeMeetingAICompanionCtrlWrap::SetOnQueryEnableActionCallback);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSendQueryPrivilegeChangedCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnSendQueryPrivilegeChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnFailedToRequestSendQueryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnFailedToRequestSendQueryCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveRequestToSendQueryCB", ZoomNodeMeetingAICompanionCtrlWrap::SetOnReceiveRequestToSendQueryCB);
}
template<>
v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAICompanionCtrlWrap >() {
	return &ZoomNodeMeetingAICompanionCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
