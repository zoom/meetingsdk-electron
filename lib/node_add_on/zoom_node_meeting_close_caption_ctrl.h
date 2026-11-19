#ifndef _ZOOM_NODE_MEETING_CLOSE_CAPTION_CTRL_H_
#define _ZOOM_NODE_MEETING_CLOSE_CAPTION_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeCloseCaptionCtrlWrap :
	public ZoomWrapObject<ZoomNodeCloseCaptionCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeCloseCaptionCtrlWrap >;
private:
	ZoomNodeCloseCaptionCtrlWrap();
	~ZoomNodeCloseCaptionCtrlWrap();
public:
	static void GetAvailableMeetingSpokenLanguages(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAvailableTranslationLanguages(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableCaptions(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableReceiveSpokenLanguageContent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsReceiveSpokenLanguageContentEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsLiveTranscriptionFeatureEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsMultiLanguageTranscriptionEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsTextLiveTranslationEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Live transcription message received callback.
	 * @param messageInfo The live transcription message.
	 */
	static void SetOnLiveTranscriptionMsgInfoReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Original language message received callback.
	 * @param messageInfo The spoken language message.
	 */
	static void SetOnOriginalLanguageMsgReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeCloseCaptionCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeCloseCaptionCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAvailableMeetingSpokenLanguages", ZoomNodeCloseCaptionCtrlWrap::GetAvailableMeetingSpokenLanguages);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAvailableTranslationLanguages", ZoomNodeCloseCaptionCtrlWrap::GetAvailableTranslationLanguages);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetTranslationLanguage", ZoomNodeCloseCaptionCtrlWrap::GetTranslationLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTranslationLanguage", ZoomNodeCloseCaptionCtrlWrap::SetTranslationLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingSpokenLanguage", ZoomNodeCloseCaptionCtrlWrap::SetMeetingSpokenLanguage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableCaptions", ZoomNodeCloseCaptionCtrlWrap::EnableCaptions);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartLiveTranscription", ZoomNodeCloseCaptionCtrlWrap::StartLiveTranscription);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopLiveTranscription", ZoomNodeCloseCaptionCtrlWrap::StopLiveTranscription);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableReceiveSpokenLanguageContent", ZoomNodeCloseCaptionCtrlWrap::EnableReceiveSpokenLanguageContent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsReceiveSpokenLanguageContentEnabled", ZoomNodeCloseCaptionCtrlWrap::IsReceiveSpokenLanguageContentEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsLiveTranscriptionFeatureEnabled", ZoomNodeCloseCaptionCtrlWrap::IsLiveTranscriptionFeatureEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMultiLanguageTranscriptionEnabled", ZoomNodeCloseCaptionCtrlWrap::IsMultiLanguageTranscriptionEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsTextLiveTranslationEnabled", ZoomNodeCloseCaptionCtrlWrap::IsTextLiveTranslationEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnLiveTranscriptionMsgInfoReceivedCB", ZoomNodeCloseCaptionCtrlWrap::SetOnLiveTranscriptionMsgInfoReceivedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnOriginalLanguageMsgReceivedCB", ZoomNodeCloseCaptionCtrlWrap::SetOnOriginalLanguageMsgReceivedCB);


}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeCloseCaptionCtrlWrap >() {

	return &ZoomNodeCloseCaptionCtrlWrap::constructor;
}

#endif