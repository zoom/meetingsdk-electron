#ifndef ZUI_MEETING_TRANSCRIPT_IT_H
#define ZUI_MEETING_TRANSCRIPT_IT_H

#ifdef _WIN32
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUIClient/zUI_stdafx.h>
#else
#include "zUI_stdafx.h"
#endif

class ZUIClient_API IZUIMeetingTranscriptMgr
{
public:
  virtual ~IZUIMeetingTranscriptMgr() = default;

  virtual void ShowRequestToStartTranscriptionDialog() = 0;
  virtual void HideRequestToStartTranscriptionDialog() = 0;
  
  virtual void ShowSaveTranscriptDialog() = 0;
  virtual void HideSaveTranscriptDialog() = 0;
};

#endif // ZUI_MEETING_TRANSCRIPT_IT_H
