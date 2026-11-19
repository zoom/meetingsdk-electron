#ifndef _ZOOM_NODE_SETTING_SHARE_CTRL_H_
#define _ZOOM_NODE_SETTING_SHARE_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingShareCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingShareCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingShareCtrlWrap >;
private:
	ZoomNodeSettingShareCtrlWrap();
	~ZoomNodeSettingShareCtrlWrap();
public:
	/**
	 * @brief Enable or disable to auto-fit the ZOOM window when viewing the shared content.
	 * @param bEnable true if resizing automatically. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAutoFitToWindowWhenViewSharing(const v8::FunctionCallbackInfo<v8::Value>& args);       
	/**
	 * @brief Determines if it is able to auto-fit the ZOOM window when viewing the shared content.
	 * @return true if resizing automatically. Otherwise, false.
	 */
	static void IsAutoFitToWindowWhenViewSharingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);                            
	/**
	 * @brief Determines if the operating system supports the GPU acceleration when user shares.
	 * @return true if supported. Otherwise, false.
	 */
	static void IsCurrentOSSupportAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);            
	/**
	 * @brief Enable/Disable the GPU acceleration when user shares.
	 * @param bEnable true indicates to enable the acceleration. false not.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);                         
	/**
	 * @brief Determines if GPU acceleration is enabled when user shares.
	 * @param [out]bEnable true indicates the GPU acceleration is enabled. false indicates the GPU acceleration is not. It validates only when the return value is SDKERR_SUCCESS.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void IsAccelerateGPUWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);                     
	/**
	 * @brief Enable/disable remote control of all applications.
	 * @param bEnable true indicates to enable the remote control. false not.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableRemoteControlAllApplications(const v8::FunctionCallbackInfo<v8::Value>& args);                   
	/**
	 * @brief Determines if remote control of all applications is enabled.
	 * @return true if enabled. Otherwise, false.
	 */
	static void IsRemoteControlAllApplicationsEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);              
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingShareCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingShareCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	 
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFitToWindowWhenViewSharing", ZoomNodeSettingShareCtrlWrap::EnableAutoFitToWindowWhenViewSharing);       
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFitToWindowWhenViewSharingEnabled", ZoomNodeSettingShareCtrlWrap::IsAutoFitToWindowWhenViewSharingEnabled);	 
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsCurrentOSSupportAccelerateGPUWhenShare", ZoomNodeSettingShareCtrlWrap::IsCurrentOSSupportAccelerateGPUWhenShare);           
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAccelerateGPUWhenShare", ZoomNodeSettingShareCtrlWrap::EnableAccelerateGPUWhenShare);                            
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAccelerateGPUWhenShareEnabled", ZoomNodeSettingShareCtrlWrap::IsAccelerateGPUWhenShareEnabled);                         
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableRemoteControlAllApplications", ZoomNodeSettingShareCtrlWrap::EnableRemoteControlAllApplications);                       
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsRemoteControlAllApplicationsEnabled", ZoomNodeSettingShareCtrlWrap::IsRemoteControlAllApplicationsEnabled);                    
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingShareCtrlWrap >() {
	return &ZoomNodeSettingShareCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
