#include "zoom_node_meeting_video_ctrl.h"

ZoomNodeMeetingVideoCtrlWrap::ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingVideoWrapSink);
}

ZoomNodeMeetingVideoCtrlWrap::~ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(NULL);
}
void ZoomNodeMeetingVideoCtrlWrap::MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::MuteVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::MuteVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().MuteVideo(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UnMuteVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UnMuteVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnMuteVideo(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::CanPinToFirstView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	ZNPinResult result = ZN_PinResult_Unknown;
	do
	{
		com::electron::sdk::proto::PinVideoToFirstViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PinVideoToFirstViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().CanPinToFirstView(_zn_userid, result);
	} while (false);

	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "result", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)result));
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingVideoCtrlWrap::PinVideoToFirstView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::PinVideoToFirstViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PinVideoToFirstViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().PinVideoToFirstView(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnPinAllVideosFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnPinAllVideosFromFirstView();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::GetPinnedUserListFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<unsigned int> zn_list = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().GetPinnedUserListFromFirstView();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate, zn_list.size());
	for (unsigned int i = 0; i < zn_list.size(); i++)
	{
		nodes->Set(context, i, v8::Integer::NewFromUnsigned(isolate, zn_list[i]));
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingVideoCtrlWrap::CanPinToSecondView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	ZNPinResult result = ZN_PinResult_Unknown;
	do
	{
		com::electron::sdk::proto::PinVideoToFirstViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PinVideoToFirstViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().CanPinToSecondView(_zn_userid, result);
	} while (false);

	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "result", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)result));
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingVideoCtrlWrap::PinVideoToSecondView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::PinVideoToFirstViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::PinVideoToFirstViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().PinVideoToSecondView(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::GetPinnedUserListFromSecondView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<unsigned int> zn_list = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().GetPinnedUserListFromSecondView();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate, zn_list.size());
	for (unsigned int i = 0; i < zn_list.size(); i++)
	{
		nodes->Set(context, i, v8::Integer::NewFromUnsigned(isolate, zn_list[i]));
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingVideoCtrlWrap::CanSpotlight(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	ZNSpotlightResult result = ZN_SpotResult_Unknown;
	do
	{
		com::electron::sdk::proto::SpotlightVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SpotlightVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().CanSpotlight(_zn_userid, result);
	} while (false);

	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "result", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)result));
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingVideoCtrlWrap::CanUnSpotlight(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	ZNSpotlightResult result = ZN_SpotResult_Unknown;
	do
	{
		com::electron::sdk::proto::SpotlightVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SpotlightVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().CanUnSpotlight(_zn_userid, result);
	} while (false);

	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "result", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)result));
	args.GetReturnValue().Set(node);
}
void ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SpotlightVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SpotlightVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SpotlightVideo(_zn_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnSpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SpotlightVideoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SpotlightVideoParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnSpotlightVideo(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnSpotlightAllVideos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnSpotlightAllVideos();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::GetSpotlightedUserList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<unsigned int> zn_list = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().GetSpotlightedUserList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate, zn_list.size());
	for (unsigned int i = 0; i < zn_list.size(); i++)
	{
		nodes->Set(context, i, v8::Integer::NewFromUnsigned(isolate, zn_list[i]));
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::HideOrShowNoVideoUserOnVideoWallParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::HideOrShowNoVideoUserOnVideoWallParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_bhide())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bHide;
		convertBool(proto_params.bhide(), _bHide);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().HideOrShowNoVideoUserOnVideoWall(_bHide);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnPinVideoFromFirstView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UnPinVideoFromFirstViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UnPinVideoFromFirstViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnPinVideoFromFirstView(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnPinVideoFromSecondView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UnPinVideoFromSecondViewParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UnPinVideoFromSecondViewParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned int _zn_userid = proto_params.userid();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnPinVideoFromSecondView(_zn_userid);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::GetLocalVideoOrderList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<unsigned int> zn_list = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().GetLocalVideoOrderList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate, zn_list.size());
	for (unsigned int i = 0; i < zn_list.size(); i++)
	{
		nodes->Set(context, i, v8::Integer::NewFromUnsigned(isolate, zn_list[i]));
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingVideoCtrlWrap::IsSupportFollowHostVideoOrder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bSupport = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().IsSupportFollowHostVideoOrder();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bSupport);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::EnableFollowHostVideoOrder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnablePlayChimeWhenEnterOrExitParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnablePlayChimeWhenEnterOrExitParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().EnableFollowHostVideoOrder(_bEnable);
	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::IsFollowHostVideoOrderOn(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bOn = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().IsFollowHostVideoOrderOn();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bOn);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::GetVideoOrderList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();

	ZNList<unsigned int> zn_list = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().GetVideoOrderList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate, zn_list.size());
	for (unsigned int i = 0; i < zn_list.size(); i++)
	{
		nodes->Set(context, i, v8::Integer::NewFromUnsigned(isolate, zn_list[i]));
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingVideoCtrlWrap::SetVideoQualityPreference(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::SetVideoQualityPreferenceParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetVideoQualityPreferenceParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_mode())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKVideoPreferenceMode _zn_mode = (ZNSDKVideoPreferenceMode)proto_params.mode();

		uint32_t _minimumframerate = 0;
		if (proto_params.has_minimumframerate())
		{
			_minimumframerate = proto_params.minimumframerate();
		}

		uint32_t _maximumframerate = 0;
		if (proto_params.has_maximumframerate())
		{
			_maximumframerate = proto_params.maximumframerate();
		}

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetVideoQualityPreference(_zn_mode, _minimumframerate, _maximumframerate);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange.Reset(isolate, cbfunc);

		ZNSDKError err = ZNSDKERR_SUCCESS;
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetActiveSpeakerVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onActiveSpeakerVideoUserChanged.Reset(isolate, cbfunc);

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetActiveVideoUserChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onActiveVideoUserChanged.Reset(isolate, cbfunc);

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetSpotlightedUserListChangeNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onSpotlightedUserListChangeNotification.Clear();
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		ZoomNodeSinkHelper::GetInst().onSpotlightedUserListChangeNotification.Reset(isolate, cbfunc);

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
