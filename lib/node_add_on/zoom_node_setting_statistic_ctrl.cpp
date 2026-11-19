#include "zoom_node_setting_statistic_ctrl.h"


ZoomNodeSettingStatisticCtrlWrap::ZoomNodeSettingStatisticCtrlWrap()
{

}

ZoomNodeSettingStatisticCtrlWrap::~ZoomNodeSettingStatisticCtrlWrap()
{

}

void ZoomNodeSettingStatisticCtrlWrap::QueryOverallStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNOverallStatisticInfo zn_info;
	auto context = isolate->GetCurrentContext();
	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingStatisticCtrl().QueryOverallStatisticInfo(zn_info);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "networkType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.net_work_type));
	node->Set(context, v8::String::NewFromUtf8(isolate, "connectionType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_info.connection_type));
	node->Set(context, v8::String::NewFromUtf8(isolate, "proxyAddr", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_info.proxy_addr).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());

	args.GetReturnValue().Set(node);
}
