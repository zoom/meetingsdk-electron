#include "zoom_node_meeting_close_caption_ctrl.h"

ZoomNodeCloseCaptionCtrlWrap::ZoomNodeCloseCaptionCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_closeCaptionWrapSink);
}

ZoomNodeCloseCaptionCtrlWrap::~ZoomNodeCloseCaptionCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().SetSink(NULL);
}

void ZoomNodeCloseCaptionCtrlWrap::GetAvailableMeetingSpokenLanguages(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<ZNLiveTranscriptionLanguage> zn_language_lst;
	zn_language_lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().GetAvailableMeetingSpokenLanguages();

	v8::Local<v8::Array> all_language_nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_language_lst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);

		node->Set(context, v8::String::NewFromUtf8(isolate, "languageName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_language_lst[i].languageName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "languageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_language_lst[i].languageID));

		all_language_nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(all_language_nodes);
}

void ZoomNodeCloseCaptionCtrlWrap::GetAvailableTranslationLanguages(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<ZNLiveTranscriptionLanguage> zn_language_lst;
	zn_language_lst = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().GetAvailableTranslationLanguages();

	v8::Local<v8::Array> all_language_nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_language_lst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);

		node->Set(context, v8::String::NewFromUtf8(isolate, "languageName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_language_lst[i].languageName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "languageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_language_lst[i].languageID));

		all_language_nodes->Set(context, i, node);
	}

	args.GetReturnValue().Set(all_language_nodes);
}

void ZoomNodeCloseCaptionCtrlWrap::GetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNLiveTranscriptionLanguage zn_language;
	zn_language = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().GetTranslationLanguage();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);

	node->Set(context, v8::String::NewFromUtf8(isolate, "languageName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_language.languageName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
	node->Set(context, v8::String::NewFromUtf8(isolate, "languageID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_language.languageID));

	args.GetReturnValue().Set(node);
}

void ZoomNodeCloseCaptionCtrlWrap::SetTranslationLanguage(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	do
	{
		com::electron::sdk::proto::SetTranslationLanguageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetTranslationLanguageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_languageid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _zn_languageID;
		_zn_languageID = proto_params.languageid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().SetTranslationLanguage(_zn_languageID);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::SetMeetingSpokenLanguage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	do
	{
		com::electron::sdk::proto::SetMeetingSpokenLanguageParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetMeetingSpokenLanguageParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_languageid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _zn_languageID;
		_zn_languageID = proto_params.languageid();

		bool _zn_isforall;
		_zn_isforall = proto_params.isforall();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().SetMeetingSpokenLanguage(_zn_languageID, _zn_isforall);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::EnableCaptions(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	do
	{
		com::electron::sdk::proto::EnableCaptionsParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableCaptionsParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_enable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		bool _zn_enable;
		_zn_enable = proto_params.enable();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().EnableCaptions(_zn_enable);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::StartLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().StartLiveTranscription();

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::StopLiveTranscription(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().StopLiveTranscription();

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::EnableReceiveSpokenLanguageContent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	do
	{
		com::electron::sdk::proto::EnableReceiveSpokenLanguageContentParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableReceiveSpokenLanguageContentParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_enable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		bool _zn_enable;
		_zn_enable = proto_params.enable();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().EnableReceiveSpokenLanguageContent(_zn_enable);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::IsReceiveSpokenLanguageContentEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;

	bool _zn_is_enabled;
	_zn_is_enabled = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().IsReceiveSpokenLanguageContentEnabled();

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, _zn_is_enabled);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::IsLiveTranscriptionFeatureEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	bool _zn_is_enabled;
	_zn_is_enabled = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().IsLiveTranscriptionFeatureEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, _zn_is_enabled);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::IsMultiLanguageTranscriptionEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();

	bool _zn_is_enabled;
	_zn_is_enabled = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().IsMultiLanguageTranscriptionEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, _zn_is_enabled);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::IsTextLiveTranslationEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool _zn_is_enabled;
	_zn_is_enabled = _g_native_wrap.GetMeetingServiceWrap().GetMeetingCloseCaptionCtrl().IsTextLiveTranslationEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, _zn_is_enabled);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::SetOnLiveTranscriptionMsgInfoReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onLiveTranscriptionMsgInfoReceived.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onLiveTranscriptionMsgInfoReceived.Reset(isolate, cbfunc);

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeCloseCaptionCtrlWrap::SetOnOriginalLanguageMsgReceivedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onOriginalLanguageMsgReceived.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onOriginalLanguageMsgReceived.Reset(isolate, cbfunc);

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}