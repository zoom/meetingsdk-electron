#ifndef _SETTING_PANEL_LANGUAGE_H_
#define _SETTING_PANEL_LANGUAGE_H_

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
#include "zm_conf_universal_ui/zm_conf_uui_meeting_control_interface.h"

class ZUIClient_API SettingPanelLanguage : public zui::CustomView<SettingPanelLanguage>
{
public:
  SettingPanelLanguage() = default;
  ~SettingPanelLanguage() = default;

  std::shared_ptr<zui::View> Clone() const override
  {
    return std::make_shared<SettingPanelLanguage>(*this);
  }

  std::shared_ptr<zui::ViewNode> Build() override;
};

class ZUIClient_API CLanguageSettingDataModel : public IInitializable
{
public:
  static CLanguageSettingDataModel& GetInstance();
  static void ReleaseInstance();

  CLanguageSettingDataModel();
  ~CLanguageSettingDataModel();

  virtual void initializeState() override;
  virtual void initializeStateHandler() override;

  void UpdateTranslationRelatedState();
  void UpdateMeetingSpeakingLanguageTitle();
  void UpdateMeetingSpeakingLanguageHelp();
  void UpdateMeetingSpeakingLanguageVisibility();
  void UpdateLanguagePanelState();
  void RefreshAllLanguagePanelState();
  void SyncMeetingSpeakingLanguageData();
  void SyncTranslatedLanguageData();
  NS_ZM_CONF_UNIVERSAL_UI::LanguageLabelType GetLanguageLabelType() const;
  
  void SetTranslateCaptionsOnWithoutNotify(bool enabled);
  void SetShowOriginalAndTranslatedCaptionWithoutNotify(bool enabled);

public:
  zui::State<int> _meetingSpeakingLanguageIndex = 0;
  zui::State<std::list<std::string>> _meetingSpeakingLanguageOptions = {};
  zui::State<int> _translatedLanguageIndex = 0;
  zui::State<std::list<std::string>> _translatedLanguageOptions = {};
  zui::State<bool> _translatedLanguageComboVisible = false;
  zui::State<bool> _translatedLanguageComboEnabled = true;
  zui::State<std::string> _meetingSpeakingLanguageTitle = std::string();
  zui::State<std::string> _meetingSpeakingLanguageHelp = std::string();
  zui::State<bool> _meetingSpeakingLanguageHelpVisible = false;
  zui::State<bool> _meetingSpeakingLanguageSectionVisible = false;
  zui::State<bool> _meetingSpeakingLanguageEnabled = true;
  zui::State<bool> _advancedEntranceVisible = false;
  zui::State<bool> _translateCaptionsOn = false;
  zui::State<bool> _translateCaptionsEnabled = true;
  zui::State<bool> _translateCaptionsVisible = false;
  zui::State<bool> _showOriginalAndTranslatedCaptionOn = false;
  zui::State<bool> _showOriginalAndTranslatedCaptionVisible = false;
  zui::State<bool> _showOriginalAndTranslatedCaptionEnabled = true;

private:
  NS_ZM_CONF_UNIVERSAL_UI::IUuiHostToolCaptionsPanelLogic* GetHostToolCaptionsPanelLogic() const;
  NS_ZM_CONF_UNIVERSAL_UI::IUuiHostToolParticipantPanelLogic* GetHostToolParticipantPanelLogic() const;
  static CLanguageSettingDataModel* _instance;
};

#define LanguagePanelDataModel CLanguageSettingDataModel::GetInstance()

#endif // _SETTING_PANEL_LANGUAGE_H_
