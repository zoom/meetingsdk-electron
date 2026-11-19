#ifndef ZUI_MEETING_CLINICAL_NOTE_IT_H
#define ZUI_MEETING_CLINICAL_NOTE_IT_H

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

class IZUIMeetingClinicalNoteSink;

class ZUIClient_API IZUIMeetingClinicalNoteMgr
{
public:
    virtual ~IZUIMeetingClinicalNoteMgr() = default;

    virtual void SetSink(IZUIMeetingClinicalNoteSink* sink) = 0;
    virtual void SetWindowParent(void* parent) = 0;

    virtual void UpdateData() = 0;

    virtual void ShowWindow(void* parent = nullptr) = 0;
    virtual void HideWindow() = 0;
    virtual void UpdatePosition(int x, int y) = 0;
    virtual bool IsWindowVisible() = 0;
    virtual bool IsWindowMouseHovered() = 0;
    virtual void* GetWindowHandle() = 0;
    virtual Layout::Rect GetWindowGeometry() = 0;

    virtual void OnTurnOffNotifierButtonClicked() = 0;
};

class IZUIMeetingClinicalNoteSink
{
public:
    virtual ~IZUIMeetingClinicalNoteSink() = default;

    virtual void OnWindowShown() {}
    virtual void OnWindowSizeChanged(int width, int height) {}
    virtual void OnWindowHidden() {}
    virtual void OnWindowActiveChanged(bool active) {}
    virtual void OnMouseHoverChanged(bool hovered) {}
};

#endif // ZUI_MEETING_CLINICAL_NOTE_IT_H
