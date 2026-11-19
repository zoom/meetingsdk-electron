#ifndef _SETTING_PANEL_GENERAL_H_
#define _SETTING_PANEL_GENERAL_H_

#ifdef _WIN32
#include "zUI/view.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "zUI_stdafx.h"
#endif

#ifdef ENABLE_ZAPP
#include "zApp/ZappBase.h"
#endif // ENABLE_ZAPP

#include "cmmlib/CmmEmojiReactionDefine.h"
#include "zui_client_data_define.h"
#include "common_def.h"

class ZUIClient_API CGeneralSettingDataModel : public IInitializable
{
public:

  static CGeneralSettingDataModel& GetInstance();
  static void ReleaseInstance();
  
  CGeneralSettingDataModel();
  ~CGeneralSettingDataModel();

  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

  void OnPTLogout();
  void OnPTLogin();
  void UpdateThemeColor();
  void UpdateThemePanelVisibility();
  void SetAppInDarkMode(bool is_dark_mode);
  void UpdateAlwaysUseDarkThemeForMeetings();
  void UpdateTopNavigationUI();
  void UpdateAICompanionBarUI();
  void UpdateZoomPresenceWithOutlook();
  void UpdateZoomAssistant(bool need_update_phone = true);
  void OnUpdatesPolicyUpdated(const zpref::zPolicyList& policies);
  void OnUpdatesPolicyUpdated(zpref::zPolicyId policeId);
  void ResetIntegrationZoomWithOutlook();
  void RefreshEmojiSkinTone();
  struct AppVersionItem
  {
    std::string appName;
    std::string appIcon;
    std::string appVersion;

    bool operator==(const AppVersionItem& other) const
    {
      return appName == other.appName &&
             appIcon == other.appIcon &&
             appVersion == other.appVersion;
    }
  };

  // Native/client modules provide the versions shown by the Workplace versions page.
  void SetZoomWorkplaceVersions(const std::vector<AppVersionItem>& versions);
  std::string GetZoomWorkplaceVersionsText() const;
#ifdef ENABLE_ZAPP
  void UpdateAppsItemShowState(NS_ZOOM_APPS::ZappEnableState pt_state);
#endif // ENABLE_ZAPP
  bool IsAppInDarkMode() { return app_in_dark_mode_; }
private:
  void UpdateGeneralUpdates();
  void UpdateChannels();
  void UpdateCurrentChannel();
  void EnableShowUpdateChannel();
  void HandleSingleUpdatesPolicyUpdate(zpref::zPolicyId policeId);
  void UpdateSideBarAccName();
  void UpdateAICompanionTooltip();
  // overall page
public:
    
  zui::State<bool> _appearanceVisible = true;
  enum AppearanceType {
    kAppearanceLight = 1,
    kAppearanceDark,
    kAppearanceSystem
  };
  zui::State<int> _appearanceType = static_cast<int>(AppearanceType::kAppearanceLight);
    
  enum ThemeType {
    kThemeClassic = 0,
    kThemeBloom,
    kThemeAgace = 3,
    kThemeRose = 2
  };

  zui::State<bool> _themeVisible = true;
  zui::State<bool> _themeEnable = true;
  SwitchControl _alwaysUseDarkThemeForMeetings;

  zui::State<int> _themeType = static_cast<int>(ThemeType::kThemeClassic);
  zui::State<int> _skinToneType = static_cast<int>(CmmEmojiReactionSkinTone_Unknown);
    
  // reset button
  SwitchControl _updateZoomAuto;
  struct AutoUpdateSpeed
  {
    RadioGroupProperty _group;
    zui::State<std::vector<zui::any>> _data;
  };
  AutoUpdateSpeed _autoUpdateSpeed;
    
  SwitchControl _autoStartZoom;
  CheckBoxProperty _autoStartZoomSilently;
  RadioGroupProperty _exitPreference;
  SwitchControl _syncZoomPresenceWithOutlook;
  SwitchControl _pinZoomToMacMenuBar;
  zui::State<bool> _enableDiagnostic = false;
    
  SwitchControl _enableDiagnosticDataViewer;
  zui::State<bool> _diagnosticLinkEnable = true; // native set
  zui::State<bool> _diagnosticLinkVisible = true;

  zui::State<bool> _isShowResetNavigationBar = true;
  zui::State<bool> _isShowAICompanionBar = false;
  zui::State<bool> _isAICompanionBarEnable = false;
  zui::State<std::string> _aiCompanionTooltip;

  zui::State<bool> _showClearZoomAppsCache = false;
  SwitchControl  _callThisDeviceForScheduleMeeting;
  SwitchControl _useZoomAssistantForMeetings = { false,false,false };
  SwitchControl _useZoomAssistantForPhone = {false,false,false};
  zui::State<bool> _IsUseZoomAssistantVisible = false;
  CheckBoxProperty _hideZoomAssistantWhenNoCall;
  zui::State<std::string> _zoomappsLastClearCacheTime;
  zui::State<bool> _zoomappsLastClearCacheTimeVisible = false;
  zui::State<std::vector<zui::any>> _zoomWorkplaceVersions;
  zui::State<bool> _showZoomWorkPlaceVersions = false;
  zui::State<bool> _fallback_to_native_home = false;

#if (defined ZOOM_DEBUG || defined (BUILD_FOR_DOGFOOD)) && (defined WIN32 || defined __MACOS__)
  zui::State<bool> _runtime_test = false;
  zui::State<bool> _debug_switch = false;
  zui::State<bool> _automation = false;
#if defined(BUILD_FOR_NORMAL_CLIENT) && defined(WIN32)
  zui::State<bool> _open_unified_settings = false;
  zui::State<bool> _enable_async_camera_access = false;
#endif
  zui::State<bool> _open_new_home_page = false;
  zui::State<bool> _show_aic2_and_aic3 = false;
  zui::State<bool> _show_voice_translator_engine_selector = false;
  zui::State<bool> _show_zui_inspector = false;
  zui::State<bool> _meeting_plugin_enabled = false;
  zui::State<bool> _enable_self_pip_auto_hide = false;
#ifdef __MACOS__
  zui::State<bool> _standalone_meeting_app_enabled = false;
#endif
#ifdef WIN32
  zui::State<bool> _enable_one_render = false;
  zui::State<bool> _enable_img_detection = true;
#endif
#endif

  struct TeamChatSiderBarProps
  {
    zui::State<bool> visible = true;
    zui::State<bool> enable = true;
    zui::State<zui::ThemeModeSelector::ColorMode> colorMode;
    zui::State<zui::ThemeModeSelector::ThemeMode> themeMode;
  };

  TeamChatSiderBarProps _chatSiderBarProps;
  zui::State<std::string> _accNameForSiderBar;

private:
  bool app_in_dark_mode_ = false;
  static CGeneralSettingDataModel* _instance;
  CmmBool is_init_with_au2_value_ = CmmFalse;
};


class ZUIClient_API SettingPanelGeneral : public zui::CustomView<SettingPanelGeneral>
{
public:

  SettingPanelGeneral();
  ~SettingPanelGeneral();

  std::shared_ptr<zui::ViewNode> Build() override;
  
private:
  void UpdateAppearanceResource();
  void UpdateAutoUpdateSpeedVisible();
  void UpdateAutoCallTips();
  void UpdateAutoCallTipVisible();

  void OnClickLearnMoreAboutUpdate();

  zui::View GetAppearanceView();

  zui::View GetNavigationBarView();

  zui::View GetAICompanionView();

  zui::View GetZoomWorkPlaceView();
  zui::View GetZoomWorkPlaceVersionsView();

  zui::View GetPresenceStatusView();

  zui::View GetScheduleMeetingView();

  zui::View GetZoomAppsView();

  zui::View GetZoomAssistantView();

#if (defined ZOOM_DEBUG || defined (BUILD_FOR_DOGFOOD)) && (defined WIN32 || defined __MACOS__)
  zui::View GetDebugView();
#endif
#if defined(_WIN32) || defined(__MACOS__)
  zui::View GetFallbackToNativeHomeView();
#endif


private:
  zui::State<std::string> _appearance_light_bk;
  zui::State<std::string> _appearance_dark_bk;
  zui::State<std::string> _appearance_system_bk;
  zui::State<bool> _autoUpdateSpeedVisible = false;
  zui::Bind<int> _themeType = static_cast<int>(CGeneralSettingDataModel::ThemeType::kThemeClassic);
  zui::Bind<std::vector<zui::any>> _autoUpdateSpeedData;
  zui::Bind<bool> _updateZoomAutoValue = true;
  
  zui::Bind<bool> _autoCallValue = false;
  zui::Bind<bool> _autoCallEnable = true;
  zui::State<bool> _autoCallTipsVisible = false;
  zui::State<std::string> _autoCallTips;

  zui::State<std::string> _bk_team_chat_siderbar = std::string("");
};

#define GeneralPanelDataModel CGeneralSettingDataModel::GetInstance()

#endif
