#ifndef _ZOOM_NODE_MEETING_POLLING_CTRL_H_
#define _ZOOM_NODE_MEETING_POLLING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodePollingCtrlWrap :
	public ZoomWrapObject<ZoomNodePollingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodePollingCtrlWrap >;
private:
	ZoomNodePollingCtrlWrap();
	~ZoomNodePollingCtrlWrap();
public:
	/**
	 * @brief Determines whether the current meeting can do the polling.
	 * @return true if you can do polling. Otherwise, false.
	 */
	static void CanDoPolling(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines if the right answer item list can be allowed to get.
	 * @param pollingID Specify the right answer's polling ID.
	 */
	static void CanGetRightAnswerItemList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the list of poll's question.
	 * @param pollingID Specify the question's polling ID.
	 * @return If the function succeeds, the return value is a pointer to the IList<IPollingQuestionItem*>. Otherwise, the return value is nullptr.
	 */
	static void GetPollingQuestionItemList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the list of polling question or subquestion's right answer.
	 * @param pollingID Specify the right answer's polling ID.
	 * @return If the function succeeds, the return value is a pointer to the IList<IPollingAnswerItem*>, Otherwise, the return value is nullptr.
	 */
	static void GetPollingRightAnswerItemList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the list of polling answer result item.
	 * @param pollingID Specify the answer result's polling ID.
	 * @return If the function succeeds, the return value is a pointer to the IList<IPollingAnswerResultItem*>. Otherwise, the return value is nullptr.
	 */
	static void GetPollingAnswerResultItemList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the polling item object of specified polling ID.
	 * @param pollingID Specify the polling ID where you want to get the information.
	 * @return If the function succeeds, the return value is a pointer to the IPollingItem, Otherwise the function fails, and the return value is nullptr.
	 */
	static void GetPollingItemByID(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the list of poll item.
	 * @return If the function succeeds, the return value is a pointer to the IList<IPollingItem*>. Otherwise, the return value is nullptr.
	 */
	static void GetPollingItemList(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Start the polling.
	 * @param pollingID Specify the poll's polling ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise the function fails.
	 */
	static void StartPolling(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Stop the polling.
	 * @param pollingID Specify the poll's polling ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise the function fails.
	 */
	static void StopPolling(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Restart the polling.
	 * @param pollingID Specify the poll's polling ID.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise the function fails.
	 */
	static void RestartPolling(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines if the question is case sensitive.
	 * @param pollingID Specify the question's polling ID.
	 * @param questionID Specify the question's question ID.
	 * @note This function can only be used by fill blank questions.
	 */
	static void IsQuestionCaseSensitive(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get the polling question's image path.
	 * @param pollingID Specify the answer's polling ID.
	 * @param questionID Specify the answer's question ID.
	 * @return If the function succeeds, the return value is the question's image path. Otherwise the function fails, and the return value is nullptr.
	 */
	static void GetPollingQuestionImagePath(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Polling status changed callback. Use this function to inform the user that the polling has been started, share result or stopped.
	 * @param pollingID Specify the status changed poll's ID.
	 * @param status Specify current polling status.
	 */
	static void SetOnPollingStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Polling result updated callback. This is triggered when a participant submits polling.
	 * @param pollingID Specify the result updated poll's ID.
	 */
	static void SetOnPollingResultUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Polling list updated callback. This is triggered when a host adds, edits, duplicates or deletes a polling.
	 */
	static void SetOnPollingListUpdatedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Polling action result callback. This is triggered when a user perform an action for a poll.
	 * @param actionType Specify the action type.
	 * @param pollingID Specify the action poll's ID.
	 * @param bSuccess Specify whether the action succeeds.
	 * @param errorMsg Specify the error message when the action fails. It is only for  SDKPollingActionType_Error.
	 * @note If actionType is SDKPollingActionType_Error, use errorMsg. This errorMsg may be triggered by any action.
	 */
	static void SetOnPollingActionResultCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodePollingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodePollingCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanGetRightAnswerItemList", ZoomNodePollingCtrlWrap::CanGetRightAnswerItemList);
	
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanDoPolling", ZoomNodePollingCtrlWrap::CanDoPolling);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingQuestionItemList", ZoomNodePollingCtrlWrap::GetPollingQuestionItemList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingRightAnswerItemList", ZoomNodePollingCtrlWrap::GetPollingRightAnswerItemList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingAnswerResultItemList", ZoomNodePollingCtrlWrap::GetPollingAnswerResultItemList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingItemByID", ZoomNodePollingCtrlWrap::GetPollingItemByID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingItemList", ZoomNodePollingCtrlWrap::GetPollingItemList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartPolling", ZoomNodePollingCtrlWrap::StartPolling);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopPolling", ZoomNodePollingCtrlWrap::StopPolling);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RestartPolling", ZoomNodePollingCtrlWrap::RestartPolling);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsQuestionCaseSensitive", ZoomNodePollingCtrlWrap::IsQuestionCaseSensitive);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPollingQuestionImagePath", ZoomNodePollingCtrlWrap::GetPollingQuestionImagePath);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPollingStatusChangedCB", ZoomNodePollingCtrlWrap::SetOnPollingStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPollingResultUpdatedCB", ZoomNodePollingCtrlWrap::SetOnPollingResultUpdatedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPollingListUpdatedCB", ZoomNodePollingCtrlWrap::SetOnPollingListUpdatedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPollingActionResultCB", ZoomNodePollingCtrlWrap::SetOnPollingActionResultCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodePollingCtrlWrap >() {
	return &ZoomNodePollingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif