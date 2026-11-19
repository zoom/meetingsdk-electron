#ifndef _ZOOM_NODE_SETTING_WALLPAPER_CTRL_H_
#define _ZOOM_NODE_SETTING_WALLPAPER_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSettingWallpaperCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingWallpaperCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingWallpaperCtrlWrap >;
private:
	ZoomNodeSettingWallpaperCtrlWrap();
	~ZoomNodeSettingWallpaperCtrlWrap();
public:
	/**
	 * @brief Callback event of notification that the meeting wall-paper item is changed.
	 * @param item The config changed.
	 */
	static void SetOnMeetingWallpaperChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification that download status of the meeting wall-paper is changed.
	 * @param status The download status of the meeting wall-peper.
	 * @param wallpaperId The download meeting wall-paper image ID.
	 */
	static void SetOnMeetingWallpaperImageDownloadStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification that the personal wall-paper item is changed.
	 * @param item The config changed.
	 */
	static void SetOnPersonalWallpaperChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event of notification that download status of the personal wall-paper is changed.
	 * @param status The download status of the personal wall-peper.
	 * @param wallpaperId The download personal wall-paper image ID.
	 */
	static void SetOnPersonalWallpaperImageDownloadStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Determines if the meeting wall-paper feature enabled by OP.
	 * @return true indicates the feature enabled. Otherwise, false.
	 */
	static void IsMeetingWallpaperEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if meeting wall-paper thumbnail ready.
	 * @return true indicates ready. Otherwise, false.
	 */
	static void IsMeetingWallpaperThumbsReady(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the meeting wall-paper item.
	 * @return The current using meeting wall-paper config.
	 * @note If select None, the wall-paper ID is empty.
	 */
	static void GetCurrentMeetingWallpaperItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the meeting wall-paper list.
	 * @return The meeting wall-paper list.
	 */
	static void GetMeetingWallpaperList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the meeting wall-paper item.
	 * @param item The meeting wall-paper item need to set.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void SetMeetingWallpaper(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the meeting wall-paper item by wall-paper ID.
	 * @return The meeting wall-paper with the wall-paper ID.
	 */
	static void GetMeetingWallpaperItemByID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Determines if the personal wall-paper feature enabled by OP.
	 * @return true indicates the feature enabled. Otherwise, false.
	 */
	static void IsPersonalWallpaperEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the current user's persional wall-paper item.
	 * @return The current user's personal wall-paper config.
	 * @note Only login user has this config. If select None, the wall-paper ID is empty.
	 */
	static void GetCurrentPersonalWallpaperItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the current user's personal wall-paper list.
	 * @return The current user's personal wall-paper list.
	 * @note Only login user has this config list.
	 */
	static void GetPersonalWallpaperList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the current user's personal wall-paper.
	 * @param item Personal wall-paper item need to set.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note Only valid for login user.
	 */
	static void SetPersonalWallpaper(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the personal wall-paper item by wall-paper ID.
	 * @return The personal wall-paper item with the wall-paper ID.
	 * @note Only valid for login user.
	 */
	static void GetPersonalWallpaperItemByID(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingWallpaperCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingWallpaperCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnMeetingWallpaperChangedCB", ZoomNodeSettingWallpaperCtrlWrap::SetOnMeetingWallpaperChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnMeetingWallpaperImageDownloadStatusCB", ZoomNodeSettingWallpaperCtrlWrap::SetOnMeetingWallpaperImageDownloadStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPersonalWallpaperChangedCB", ZoomNodeSettingWallpaperCtrlWrap::SetOnPersonalWallpaperChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetOnPersonalWallpaperImageDownloadStatusCB", ZoomNodeSettingWallpaperCtrlWrap::SetOnPersonalWallpaperImageDownloadStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMeetingWallpaperEnabled", ZoomNodeSettingWallpaperCtrlWrap::IsMeetingWallpaperEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMeetingWallpaperThumbsReady", ZoomNodeSettingWallpaperCtrlWrap::IsMeetingWallpaperThumbsReady);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentMeetingWallpaperItem", ZoomNodeSettingWallpaperCtrlWrap::GetCurrentMeetingWallpaperItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingWallpaperList", ZoomNodeSettingWallpaperCtrlWrap::GetMeetingWallpaperList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingWallpaper", ZoomNodeSettingWallpaperCtrlWrap::SetMeetingWallpaper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMeetingWallpaperItemByID", ZoomNodeSettingWallpaperCtrlWrap::GetMeetingWallpaperItemByID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsPersonalWallpaperEnabled", ZoomNodeSettingWallpaperCtrlWrap::IsPersonalWallpaperEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCurrentPersonalWallpaperItem", ZoomNodeSettingWallpaperCtrlWrap::GetCurrentPersonalWallpaperItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPersonalWallpaperList", ZoomNodeSettingWallpaperCtrlWrap::GetPersonalWallpaperList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetPersonalWallpaper", ZoomNodeSettingWallpaperCtrlWrap::SetPersonalWallpaper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetPersonalWallpaperItemByID", ZoomNodeSettingWallpaperCtrlWrap::GetPersonalWallpaperItemByID);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingWallpaperCtrlWrap >() {
	return &ZoomNodeSettingWallpaperCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
