#ifndef ZUI_MEETING_LANGUAGE_IT_H
#define ZUI_MEETING_LANGUAGE_IT_H

#ifdef _WIN32
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUIClient/zUI_stdafx.h>
#else
#include "zUI_stdafx.h"
#endif
#include "zm_conf_universal_ui/zm_conf_uui_cc_interface.h"

class ZUIClient_API IZUIMeetingLanguageMgr
{
public:
  virtual ~IZUIMeetingLanguageMgr() = default;

  virtual void ShowTranslationLanguageSelectorDialog(
      NS_ZM_CONF_UNIVERSAL_UI::UuiTranslationPromptEntry entry) = 0;
  virtual void CloseLanguageSelectorDialogs() = 0;
};

#endif // ZUI_MEETING_LANGUAGE_IT_H
