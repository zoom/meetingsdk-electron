#ifndef _SETTING_PANEL_SHARE_SCREEN_H_
#define _SETTING_PANEL_SHARE_SCREEN_H_

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
#include "zUI/zui_base.h"
#include "zui_client_data_define.h"

class ICmmShareConfig;

class ZUIClient_API CSettingShareDataModel : public IInitializable
{
public:

  static CSettingShareDataModel& GetInstance();
  static void ReleaseInstance();
  
  CSettingShareDataModel();
  ~CSettingShareDataModel();

  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

  // interface start
  ICmmShareConfig* GetShareConfigIt();

  void SetSideBySideControlsVisible(bool val);
  void UpdateSideBySideControls();
  void UpdateShareFilterOption();
  void UpdateOptimizeVideoclip();
  void SetUseSystemPickerVisible(bool val);  // mac only
  RadioBtnProperty1 _eableRemoteControlInAllApps;  // win only
  
  // Video quality helpers: convert between enum value and list index
  int GetVideoQualityEnumValue(const int listIndex);
  int GetVideoQualityIndex(const int enumValue);
  std::vector<std::string> GetVideoQualityOptionTitles() const;

  // interface end

public:
  enum {
    windowSizeCurrentSize = 0,
    windowSizeFullScreen = 1,
  };
  RadioGroupProperty _winSizeOfViewingShare;
  RadioBtnProperty _scaleToFitContent;
  RadioBtnProperty1 _sideBySide;

  enum {
    shareWindow = 0,
    shareApp = 1
  };
  RadioGroupProperty _shareContentOption;

  RadioBtnProperty _showGreenBorder;
  RadioBtnProperty1 _showZoomWindowWhenSharing;
  CheckBoxProperty _shareToolbarAndNoti;

  enum {
    previewContent = 0,
    shareDesktop = 1
  };
  RadioGroupProperty _shareButtonBehavior;
  RadioGroupProperty _shareButtonBehaviorInZR;

  enum {
    captureAuto = 0,
    captureWithWindowFilter,
    captureWithWindowFilterAdvanced,
    captureWithoutWindowFilter,
#ifdef WIN32
    captureSecureShareWithWindowFilter,
#endif
    captureLegacyOperationgSystems
  };

  DropDownProperty _captureMode;

  RadioBtnProperty _shareSelectedAppWindowOnly;//mac only
  RadioBtnProperty1 _useSystemPicker;  //mac only

  RadioBtnProperty _useTCP;

  enum {
    k1080p_30fps = 0,
    k720p_30fps,
    k1080p_60fps,
    k720p_60fps,
    k4k_30fps,
    k4k_60fps
  };
  zui::State<bool> _isShowPanelAutoOptimizeVideoSharing = true;
  RadioBtnProperty _autoOptimizeVideoSharing;
  DropDownProperty _preferredParam;  // Stores list index, not enum value
  zui::State<bool> _isShownPreferredParamWarning = false;
  struct VideoQualityOption {
    std::string title;
    int enum_value;
  };
  std::vector<VideoQualityOption> _videoQualityOptions;
  
  enum {
    limitShareFPS_15,
    limitShareFPS_10,
    limitShareFPS_8,
    limitShareFPS_6,
    limitShareFPS_4,
    limitShareFPS_2,
    limitShareFPS_1
  };
  SwitchControl    _shareFPSLimit;
  DropDownProperty _limitShareFPSValue;

  RadioBtnProperty _accelerationShareScreen;
  SwitchControl   _accelerationVideoScreen;
  RadioBtnProperty _accelerationAnnoScreen;

  DropDownProperty _screenCaptureModeOnWayland;
  
  zui::State<bool> _showAdvanced = false;

  // Focus control: idObserver + FocusToView (same pattern as Recording page)
  zui::State<std::string> _basicViewIdObserver;      // BasicPage ScrollView ID
  zui::State<std::string> _advancedViewIdObserver;   // AdvancedPage ScrollView ID
  zui::State<std::string> _advancedBtnObserver;      // Advanced button ID
  zui::State<std::string> _backBtnObserver;          // Back button ID

  // only linux need
  zui::State<bool> _isAutoGrabRemoteControlEnabled = false;
  zui::State<int> _remoteControllerIdleIndex = 0;
  
  zui::State<bool> _showAdvancedButton = true;
#if (defined BUILD_FOR_VDI) && (defined WIN32)
  zui::State<std::list<std::string>> _vdiShareFps;
#endif
  // only client sdk need
  zui::State<bool> _showLearnMore = true;

  SwitchControl    _optSliderControl;

private:
  static CSettingShareDataModel* _instance;
};

class ZUIClient_API SettingPanelShareScreen : public zui::CustomView<SettingPanelShareScreen>
{
public:

  SettingPanelShareScreen(bool is_meeting_mode = false);
  ~SettingPanelShareScreen() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelShareScreen>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;

private:
  bool is_meeting_mode_ = false;
};

#define SharePanelDataModel CSettingShareDataModel::GetInstance()

#endif
