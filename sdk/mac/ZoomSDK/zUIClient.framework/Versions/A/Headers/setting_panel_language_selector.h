#ifndef _SETTING_PANEL_LANGUAGE_SELECTOR_H_
#define _SETTING_PANEL_LANGUAGE_SELECTOR_H_

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

class SettingPanelLanguageSelector : public zui::CustomView<SettingPanelLanguageSelector>
{
public:
  struct Config
  {
    std::string title;
    bool shouldNotShowSpeakingLanguageSection = false;
    bool shouldShowTranslationSection = true;
    bool shouldShowDoNotAskAgainCheckBox = false;
  };

  SettingPanelLanguageSelector(const Config& config,
                               const zui::Bind<std::list<std::string>>& speaking_options,
                               const zui::Bind<int>& speaking_language_index,
                               const zui::Bind<std::list<std::string>>& translation_options,
                               const zui::Bind<int>& translation_language_index,
                               zui::State<bool>& do_not_ask_again);
  SettingPanelLanguageSelector(const Config& config,
                               const zui::Bind<std::list<std::string>>& speaking_options,
                               const zui::Bind<int>& speaking_language_index);
  ~SettingPanelLanguageSelector() = default;

  std::shared_ptr<zui::View> Clone() const override
  {
    return std::make_shared<SettingPanelLanguageSelector>(*this);
  }

  std::shared_ptr<zui::ViewNode> Build() override;

private:
  Config _config;
  zui::Bind<std::list<std::string>> _speakingOptions;
  zui::Bind<int> _speakingLanguageIndex;
  zui::Bind<std::list<std::string>> _translationOptions;
  zui::Bind<int> _translationLanguageIndex;
  zui::State<bool>* _doNotAskAgain = nullptr;
};

#endif // _SETTING_PANEL_LANGUAGE_SELECTOR_H_
