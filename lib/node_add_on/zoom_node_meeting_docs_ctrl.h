#ifndef _ZOOM_NODE_MEETING_DOCS_CTRL_H_
#define _ZOOM_NODE_MEETING_DOCS_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingDocsCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingDocsCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingDocsCtrlWrap >;
private:
	ZoomNodeMeetingDocsCtrlWrap();
	~ZoomNodeMeetingDocsCtrlWrap();
public:
	/**
	 * @brief Determines whether the current meeting supports the docs or not.
	 * @return true if supported. Otherwise, false.
	 */
	static void IsSupportDocs(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can start sharing the doc or not.
	 * @param reason The reason why no one can start sharing the doc.
	 * @return true indicates you can start sharing the doc.
	 */
	static void CanStartShareDocs(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether the current user can set docs options or not.
	 * @return true if the current user can set docs options. Otherwise, false.
	 */
	static void CanSetDocsOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the setting option for who can share docs.
	 * @param option The setting for who can share docs.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetDocsShareOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the setting option for who can share docs.
	 * @param option Setting option for who can share docs.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetDocsShareOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the option for who can initiate a new doc.
	 * @param option Setting option for who can initiate a new doc.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetDocsCreateOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the option for who can initiate a new doc.
	 * @param option Setting option for who can initiate a new doc.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void GetDocsCreateOption(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Query if other user is sharing docs.
	 * @return true indicates other user is sharing docs.
	 */
	static void IsOtherSharingDocs(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Query if the current user is sharing docs successfully.
	 * @return true indicates sharing successfully.
	 */
	static void IsSharingDocsOut(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the docs web view and dashboard web view owner window.
	 * @param hOwner Specify the owner window. 
	 * @note Call this function before calling ShowDocsDashboard. Call this function when receiving the meeting status MEETING_STATUS_INMEETING. 
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for user custom interface mode.
	 */
	static void SetOwnerWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Show the docs dashboard web view window.
	 * @param x The horizontal coordinate value. 
	 * @param y The vertical coordinate value. 
	 * @note If x == -1 and y = -1, the window position will be in the center of the screen where the owner window is located.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void ShowDocsDashboard(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the dashboard web view window size.
	 * @param height Specify the height of the window. 
	 * @param width Specify the width of the window. 
	 * @note If height == -1 and width == -1, the window size will be default.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void SetDocDashboardSize(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the docs web view window position.
	 * @param x Specifies the X-axis coordinate of the top-left corner of the docs web view window in the parent window.
	 * @param y Specifies the Y-axis coordinate of the top-left corner of the docs web view window in the parent window.
	 * @note If x == -1 and y = -1, the window position will be in the center of the screen where the owner window is located.
	 * @note If you don't call this function, the window position will be in the center of the screen where the owner window is located.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void SetDocsViewPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the docs web view window size.
	 * @param height Specify the height of the docs web view window. 
	 * @param width Specify the width of the docs web view window. 
	 * @note If height == -1 and width == -1, the window size will be default.
	 * @note If you don't call this function, the window size will be default.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void SetDocsViewSize(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Show the docs web view window.
	 * @param sourceID The share source ID that is sharing.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void ShowDocsViewWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Close the docs web view window.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for custom user interface mode.
	 */
	static void CloseDocsViewWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the docs sharing source information list from the specified sharer.
	 * @param userID The ID of the user who is sharing docs.
	 * @return If the function succeeds, the return value is the viewable docs sharing information list.
	 */
	static void GetDocsSharingSourceInfoList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the ID of users who are sharing docs.
	 * @return If the function succeeds, the return value is a list of user ID of all users who are sharing docs. If the function fails, the return value is nullptr.
	 */
	static void GetViewableDocsSharingUserList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback for document status change
	 * @param pInfo Document sharing source information.
	 * @note Notifies when document sharing starts/stops. All meeting participants receive this event.
	 */
	static void SetOnDocsSharingSourceInfoChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback for document sharing permission changes
	 * @param createOption Specifies who can create new documents.
	 * @param option Specifies who can share documents.
	 * @note Triggered when document creation/sharing permissions are modified.
	 */
	static void SetOnDocsPermissionChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
void InitClassAttribute<ZoomNodeMeetingDocsCtrlWrap>(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingDocsCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportDocs", ZoomNodeMeetingDocsCtrlWrap::IsSupportDocs);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartShareDocs", ZoomNodeMeetingDocsCtrlWrap::CanStartShareDocs);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanSetDocsOption", ZoomNodeMeetingDocsCtrlWrap::CanSetDocsOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDocsShareOption", ZoomNodeMeetingDocsCtrlWrap::SetDocsShareOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDocsShareOption", ZoomNodeMeetingDocsCtrlWrap::GetDocsShareOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDocsCreateOption", ZoomNodeMeetingDocsCtrlWrap::SetDocsCreateOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDocsCreateOption", ZoomNodeMeetingDocsCtrlWrap::GetDocsCreateOption);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsOtherSharingDocs", ZoomNodeMeetingDocsCtrlWrap::IsOtherSharingDocs);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSharingDocsOut", ZoomNodeMeetingDocsCtrlWrap::IsSharingDocsOut);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOwnerWindow", ZoomNodeMeetingDocsCtrlWrap::SetOwnerWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowDocsDashboard", ZoomNodeMeetingDocsCtrlWrap::ShowDocsDashboard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDocDashboardSize", ZoomNodeMeetingDocsCtrlWrap::SetDocDashboardSize);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDocsViewPos", ZoomNodeMeetingDocsCtrlWrap::SetDocsViewPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDocsViewSize", ZoomNodeMeetingDocsCtrlWrap::SetDocsViewSize);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ShowDocsViewWindow", ZoomNodeMeetingDocsCtrlWrap::ShowDocsViewWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CloseDocsViewWindow", ZoomNodeMeetingDocsCtrlWrap::CloseDocsViewWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDocsSharingSourceInfoList", ZoomNodeMeetingDocsCtrlWrap::GetDocsSharingSourceInfoList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetViewableDocsSharingUserList", ZoomNodeMeetingDocsCtrlWrap::GetViewableDocsSharingUserList);

	// Event Callbacks
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnDocsSharingSourceInfoChangedCB", ZoomNodeMeetingDocsCtrlWrap::SetOnDocsSharingSourceInfoChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnDocsPermissionChangedCB", ZoomNodeMeetingDocsCtrlWrap::SetOnDocsPermissionChangedCB);
}
template<>
v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingDocsCtrlWrap >() {
	return &ZoomNodeMeetingDocsCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
