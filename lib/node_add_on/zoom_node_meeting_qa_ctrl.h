#ifndef _ZOOM_NODE_MEETING_QA_CTRL_H_
#define _ZOOM_NODE_MEETING_QA_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingQACtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingQACtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingQACtrlWrap >;
private:
	ZoomNodeMeetingQACtrlWrap();
	~ZoomNodeMeetingQACtrlWrap();
public:
	/**
	 * @brief Get a certain question.
	 * @param questionID Specifies the question id.
	 * @return A pointer to IQAItemInfo.
	 */
	static void GetQuestion(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get a certain answer.
	 * @param answerID Specifies the answer id.
	 * @return A pointer to IAnswerItem.
	 */
	static void GetAnswer(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the list of all the questions.
	 * @return The list of all the questions.
	 */
	static void GetAllQuestionList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host answers the question publicly.
	 * @param questionID Specifies the question id.
	 * @param answerContent Specifies the content of the answer.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The answer will be cut off if it is over long.
	 */
	static void AnswerQuestionPublicWithQuestionID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host answers the question to the question sender privately.
	 * @param questionID Specifies the question id.
	 * @param answerContent Specifies the content of the answer.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The answer will be cut off if it is over long.
	 */
	static void AnswerQuestionPrivateWithQuestionID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the question can be answered live.
	 * @param questionID Specifies the question id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void StartLiving(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the question can not be answered live.
	 * @param questionID Specifies the question id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EndLiving(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host dismisses the question.
	 * @param questionID Specifies the question id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DismissQuestionWithQuestionID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host deletes the question.
	 * @param questionID Specifies the question id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeleteQuestion(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host deletes the answerID.
	 * @param answerID Specifies the answer id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DeleteAnswer(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The host reopens the question.
	 * @param questionID Specifies the question id.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void ReopenQuestionWithQuestionID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Vote up or revoke voting up the question.
	 * @param questionID Specifies the question id.
	 * @param bVokeup true indicates to vote up, false indicates to revoke voting up.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void VoteupQuestionWithQuestionID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of adding question.
	 * @param questionID The question id.
	 * @param bSuccess Add question successfully or not.
	 */
	static void SetOnAddQuestionCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of receiving question.
	 * @param questionID The question id.
	 */
	static void SetOnReceiveQuestionCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of deleting question(s).
	 * @param lstQuestionID The list of question ids.
	 */
	static void SetOnDeleteQuestionsCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of marking question as dismissed.
	 * @param question_id The question id.
	 */
	static void SetOnQuestionMarkedAsDismissedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of reopening question.
	 * @param question_id The question id.
	 */
	static void SetOnReopenQuestionCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of user answering live.
	 * @param questionID The question id.
	 */
	static void SetOnUserLivingReplyCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of end of user answering live.
	 * @param questionID The question id.
	 */
	static void SetOnUserEndLivingCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of receiving answer.
	 * @param answerID The answer id.
	 */
	static void SetOnReceiveAnswerCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of adding answer.
	 * @param answerID The answer id.
	 * @param bSuccess Add answer successfully or not.
	 */
	static void SetOnAddAnswerCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of deleting answer(s).
	 * @param lstAnswerID The list of answer ids.
	 */
	static void SetOnDeleteAnswersCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of voting up question.
	 * @param question_id The question id.
	 * @param order_changed The order of the question in question list is changed or not.
	 */
	static void SetOnVoteupQuestionCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Callback event of revoking voting up question.
	 * @param question_id The question id.
	 * @param order_changed The order of the question in question list is changed or not.
	 */
	static void SetOnRevokeVoteupQuestionCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingQACtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingQACtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAddQuestionCB", ZoomNodeMeetingQACtrlWrap::SetOnAddQuestionCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveQuestionCB", ZoomNodeMeetingQACtrlWrap::SetOnReceiveQuestionCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnDeleteQuestionsCB", ZoomNodeMeetingQACtrlWrap::SetOnDeleteQuestionsCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnQuestionMarkedAsDismissedCB", ZoomNodeMeetingQACtrlWrap::SetOnQuestionMarkedAsDismissedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReopenQuestionCB", ZoomNodeMeetingQACtrlWrap::SetOnReopenQuestionCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserLivingReplyCB", ZoomNodeMeetingQACtrlWrap::SetOnUserLivingReplyCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnUserEndLivingCB", ZoomNodeMeetingQACtrlWrap::SetOnUserEndLivingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnAddAnswerCB", ZoomNodeMeetingQACtrlWrap::SetOnAddAnswerCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnReceiveAnswerCB", ZoomNodeMeetingQACtrlWrap::SetOnReceiveAnswerCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnDeleteAnswersCB", ZoomNodeMeetingQACtrlWrap::SetOnDeleteAnswersCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnVoteupQuestionCB", ZoomNodeMeetingQACtrlWrap::SetOnVoteupQuestionCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnRevokeVoteupQuestionCB", ZoomNodeMeetingQACtrlWrap::SetOnRevokeVoteupQuestionCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetQuestion", ZoomNodeMeetingQACtrlWrap::GetQuestion);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAnswer", ZoomNodeMeetingQACtrlWrap::GetAnswer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAllQuestionList", ZoomNodeMeetingQACtrlWrap::GetAllQuestionList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AnswerQuestionPublicWithQuestionID", ZoomNodeMeetingQACtrlWrap::AnswerQuestionPublicWithQuestionID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AnswerQuestionPrivateWithQuestionID", ZoomNodeMeetingQACtrlWrap::AnswerQuestionPrivateWithQuestionID);	
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiving", ZoomNodeMeetingQACtrlWrap::StartLiving);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EndLiving", ZoomNodeMeetingQACtrlWrap::EndLiving);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DismissQuestionWithQuestionID", ZoomNodeMeetingQACtrlWrap::DismissQuestionWithQuestionID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeleteQuestion", ZoomNodeMeetingQACtrlWrap::DeleteQuestion);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DeleteAnswer", ZoomNodeMeetingQACtrlWrap::DeleteAnswer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ReopenQuestionWithQuestionID", ZoomNodeMeetingQACtrlWrap::ReopenQuestionWithQuestionID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "VoteupQuestionWithQuestionID", ZoomNodeMeetingQACtrlWrap::VoteupQuestionWithQuestionID);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingQACtrlWrap >() {
	return &ZoomNodeMeetingQACtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
