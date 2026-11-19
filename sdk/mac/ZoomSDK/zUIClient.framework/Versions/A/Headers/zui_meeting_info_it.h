#ifndef _ZUI_MEETING_INFO_IT_H_
#define _ZUI_MEETING_INFO_IT_H_

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

class IZUIMeetingInfoSink
{
public:
  virtual ~IZUIMeetingInfoSink() = default;

  virtual bool CopyTextToClipboard(const CString& text) { return true; }
  virtual void OnClickViewAllMeetingInfo() {}
  virtual void OnClickHostSettings() {}
  virtual void OnMeetingInfoVisibleChanged(bool visible) {}
  virtual void OnWindowSizeChanged(int width, int height) {}
  virtual bool ShouldHideOnDeactivate() { return true; }
  virtual bool IsHostToolPanelVisible() { return false; }
  virtual void OnMeetingInfoMouseHoverChanged(bool hovered) {}
};


class ZUIClient_API IZUIMeetingInfoMgr
{
public:
	virtual ~IZUIMeetingInfoMgr() = default;
  virtual void ShowMeetingInfo(void* parent = nullptr) = 0;
  virtual void HideMeetingInfo() = 0;
  virtual void CloseMeetingInfo() = 0;
  virtual void UpdatePosition(int x, int y) = 0;
  virtual void SetSink(IZUIMeetingInfoSink* sink) = 0;
  virtual void SetViewMeetingInfoBtnVisible(bool visible) = 0;
  virtual bool IsMeetingInfoVisible() = 0;
  virtual void* GetHandle() = 0;
  virtual Layout::Rect GetGeometry() = 0;

protected:
};

#endif
