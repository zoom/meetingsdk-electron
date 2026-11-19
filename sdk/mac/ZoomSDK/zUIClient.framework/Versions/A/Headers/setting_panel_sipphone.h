#ifndef _SETTING_PANEL_SIPPHONE_H_
#define _SETTING_PANEL_SIPPHONE_H_

#include "signals/signals.h"
#include "zSipCallCommon/pbx_call_handling_settings_api.h"
#include "zSipCallCommon/pbx_efax_api.h"
#include "zPTApp/sip/sipcall_audio_file_player_api.h"
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
#include "zUIClient/zui_client_data_define.h"
#include "setting_panel_phone_dialog.h"

class ZUIClient_API CSIPPhoneSettingDataModel : public IInitializable
{
public:
  // MAC only
  struct CallPreferenceInfo {
    std::string app_name;
    std::string boudle_id;
    std::string icon;
    bool is_default;
    bool operator==(const CallPreferenceInfo& other) const {
      return app_name == other.app_name
        && boudle_id == other.boudle_id
        && icon == other.icon
        && is_default == other.is_default
        ;
    }
  };
  zui::State<std::vector<zui::any>> _callingPreferences;

  static CSIPPhoneSettingDataModel& GetInstance();
  CSIPPhoneSettingDataModel();
  ~CSIPPhoneSettingDataModel();

  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

public:
  zui::State<bool> _isSipVisble = false;;
  zui::State<bool> _sipErrorMsgVisible;
  zui::State<std::string> _sipErrorMsg;
 
  zui::State<std::string> _sipDomain;
  zui::State<std::string> _sipRegisterServer;
  zui::State<std::string> _sipTransportProtocol;
  zui::State<std::string> _sipProxyServer;
  zui::State<std::string> _sipRegistrationExpiry;
  zui::State<std::string> _sipLastRegistration;
  zui::State<std::string> _sipUserName;
  zui::State<std::string> _sipAuthorizationName;
  zui::State<std::string> _sipUserIdentity;
  zui::State<std::string> _sipVoicemail;
  SwitchControl           _locationPermission;
  BtnProperty _showWebRTCWebview;
};

class ZUIClient_API NewSettingPanelSIPPhone : public zui::CustomView<NewSettingPanelSIPPhone>
{
public:
  NewSettingPanelSIPPhone();
  ~NewSettingPanelSIPPhone() = default;

  std::shared_ptr<zui::ViewNode> Build() override;
};


#define SIPPhoneDataModel CSIPPhoneSettingDataModel::GetInstance()

#endif
