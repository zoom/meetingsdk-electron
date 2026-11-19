#ifndef _ZOOM_NODE_MEETING_ANNOTATION_H_
#define _ZOOM_NODE_MEETING_ANNOTATION_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAnnotationWrap :
	public ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >;
private:
	ZoomNodeMeetingAnnotationWrap() {};
	~ZoomNodeMeetingAnnotationWrap() {};
public:
	/**
	 * @brief The SDK will trigger this callback if the presenter enable/disable PARTICIPANTS ANNOTATION.
	 */
	static void SetOnSupportAnnotationStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines whether current meeting supports annotation feature.
	 * @param args Function callback arguments.
	 * @return true not support, false support.
	 */
	static void IsAnnotationDisable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Display annotation toolbar.
	 * @param viewtype Specify which view to display the toolbar.
	 * @param left Specify X-axis coordinate of the upper-left corner for the toolbar.
	 * @param top Specify Y-axis coordinate of the upper-left corner for the toolbar.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Close the current annotation toolbar.
	 * @param viewtype Specify which view to close the toolbar.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Choose annotation tool.
	 * @param viewtype Specify which view to display the toolbar.
	 * @param type Specify the annotation tool to be used.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode. The tool type ANNOTOOL_PICKER and ANNOTOOL_SPOTLIGHT are not support for viewer.
	 */
	static void SetTool(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Clear present annotations.
	 * @param viewtype Specify on which view to clear the annotations.
	 * @param type Specify the ways to clear annotations.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void Clear(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the colors of annotation tools.
	 * @param viewtype The specified color is used on which view.
	 * @param color Specify the color of the annotation tools in RGB format.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void SetColor(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the line width of annotation tools.
	 * @param viewtype The specified line width is used on which view.
	 * @param lineWidth Specify the line width to annotate.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void SetLineWidth(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Undo the last annotation.
	 * @param viewtype Specify on which view to undo the last annotation.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void Undo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Redo the last-undo annotation.
	 * @param viewtype Specify on which view to redo the last-undo annotation.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Valid only for ZOOM style user interface mode.
	 */
	static void Redo(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines whether the legal notice for annotation is available.
	 * @return true indicates the legal notice for annotation transcript is available. Otherwise, false.
	 */
	static void IsAnnotationLegalNoticeAvailable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the annotation legal notices prompt.
	 * @return The annotation legal notices prompt.
	 */
	static void GetAnnotationLegalNoticesPrompt(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the annotation legal notices explained.
	 * @return The annotation legal notices explained.
	 */
	static void GetAnnotationLegalNoticesExplained(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingAnnotationWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAnnotationWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnSupportAnnotationStatusCB", ZoomNodeMeetingAnnotationWrap::SetOnSupportAnnotationStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAnnotationDisable", ZoomNodeMeetingAnnotationWrap::IsAnnotationDisable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAnnotation", ZoomNodeMeetingAnnotationWrap::StartAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAnnotation", ZoomNodeMeetingAnnotationWrap::StopAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTool", ZoomNodeMeetingAnnotationWrap::SetTool);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Clear", ZoomNodeMeetingAnnotationWrap::Clear);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetColor", ZoomNodeMeetingAnnotationWrap::SetColor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLineWidth", ZoomNodeMeetingAnnotationWrap::SetLineWidth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Undo", ZoomNodeMeetingAnnotationWrap::Undo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Redo", ZoomNodeMeetingAnnotationWrap::Redo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAnnotationLegalNoticeAvailable", ZoomNodeMeetingAnnotationWrap::IsAnnotationLegalNoticeAvailable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAnnotationLegalNoticesPrompt", ZoomNodeMeetingAnnotationWrap::GetAnnotationLegalNoticesPrompt);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAnnotationLegalNoticesExplained", ZoomNodeMeetingAnnotationWrap::GetAnnotationLegalNoticesExplained);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAnnotationWrap >() {
	return &ZoomNodeMeetingAnnotationWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
