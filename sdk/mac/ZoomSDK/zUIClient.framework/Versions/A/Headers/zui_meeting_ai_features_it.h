#ifndef ZUI_MEETING_AI_FEATURES_IT_H
#define ZUI_MEETING_AI_FEATURES_IT_H

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

class IZUIMeetingAiFeaturesSink;

class ZUIClient_API IZUIMeetingAiFeaturesMgr
{
public:
  enum class FeatureType
  {
    kOverview,
    kTranscriptions,
    kMyNotes,
  };

public:
  virtual ~IZUIMeetingAiFeaturesMgr() = default;

  virtual void SetSink(IZUIMeetingAiFeaturesSink* sink) = 0;
  virtual void SetWindowParent(void* parent) = 0;

  virtual void UpdateData(FeatureType type) = 0;

  virtual void ShowWindow(FeatureType type, void* parent = nullptr) = 0;
  virtual void HideWindow(FeatureType type) = 0;
  virtual void HideAllWindows() = 0;
  virtual void HideAllDialogs() = 0;
  // Pre-ZOOM-1248707 overload. KEPT AT ITS ORIGINAL VTABLE SLOT (with the
  // usePhysicalPixels parameter introduced by an earlier MR) for ABI back-
  // compat -- see ZOOM-557853 for the kind of vtable-offset crash that happens
  // when the slot at a given index changes signature.
  virtual void UpdatePosition(FeatureType type, int x, int y,
                              bool usePhysicalPixels = false) = 0;
  virtual bool IsWindowVisible(FeatureType type) = 0;
  virtual bool IsWindowMouseHovered(FeatureType type) = 0;
  virtual void* GetWindowHandle(FeatureType type) = 0;
  virtual Layout::Rect GetWindowGeometry(FeatureType type) = 0;
  virtual void ShowStopTranscriptionDialog() = 0;

  // ----------------------------------------------------------------------
  // ABI extension. Added at the END of the vtable. Do NOT reorder or
  // insert anything before this point -- binaries built against an older
  // header rely on the preceding virtuals keeping their exact slot indices.
  // ----------------------------------------------------------------------

  // Extended UpdatePosition that additionally takes the anchor monitor DPI.
  // See IZUIMeetingEncryptionMgr::UpdatePosition for the semantics. Non-pure
  // by design: implementations that have not been ported keep their previous
  // behavior via this default forwarder.
  virtual void UpdatePosition(FeatureType type, int x, int y,
                              bool usePhysicalPixels, int anchorDpi)
  {
    (void)anchorDpi;
    UpdatePosition(type, x, y, usePhysicalPixels);
  }
};

class IZUIMeetingAiFeaturesSink
{
public:
  virtual ~IZUIMeetingAiFeaturesSink() = default;

  // Overview view callbacks
  virtual void OnAiCompanionSettingClicked(CmmBool result) {}
  virtual void OnStartAiCompanion(CmmBool result) {}
  virtual void OnOpenAiCompanion(CmmBool result) {}
  virtual void OnStopAiCompanion(CmmBool result) {}

  // Transcriptions view callbacks
  virtual void OnStopTranscriptionClicked(CmmBool result) {}

  // My Notes view callbacks
  virtual void OnMyNotesSettingClicked() {}
  virtual void OnStartTakingMyNotes() {}
  virtual void OnOpenMyNotes() {}

  // Window callbacks
  virtual void OnWindowShown(IZUIMeetingAiFeaturesMgr::FeatureType type) {}
  virtual void OnWindowSizeChanged(IZUIMeetingAiFeaturesMgr::FeatureType type, int width, int height) {}
  virtual void OnWindowHidden(IZUIMeetingAiFeaturesMgr::FeatureType type) {}
  virtual void OnWindowActiveChanged(IZUIMeetingAiFeaturesMgr::FeatureType type, bool active) {}
  virtual void OnMouseHoverChanged(IZUIMeetingAiFeaturesMgr::FeatureType type, bool hovered) {}

  // Popover callbacks (Windows only)
  virtual void OnBeforeWindowHidden(IZUIMeetingAiFeaturesMgr::FeatureType type, void* parent) {}
};

#endif // ZUI_MEETING_AI_FEATURES_IT_H
