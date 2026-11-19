#ifndef _SETTING_PANEL_LANGUAGE_ADVANCED_H_
#define _SETTING_PANEL_LANGUAGE_ADVANCED_H_

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

class ZUIClient_API SettingPanelLanguageAdvanced : public zui::CustomView<SettingPanelLanguageAdvanced>
{
public:
  SettingPanelLanguageAdvanced() = default;
  ~SettingPanelLanguageAdvanced() = default;

  std::shared_ptr<zui::View> Clone() const override
  {
    return std::make_shared<SettingPanelLanguageAdvanced>(*this);
  }

  static void RefreshState();
  std::shared_ptr<zui::ViewNode> Build() override;
};

#endif // _SETTING_PANEL_LANGUAGE_ADVANCED_H_
