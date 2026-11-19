#ifndef ZUI_VOICE_TRANSLATION_IT_H
#define ZUI_VOICE_TRANSLATION_IT_H

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

class IZUVoiceTranslationSink;

class ZUIClient_API IZUVoiceTranslationMgr
{
public:
  virtual ~IZUVoiceTranslationMgr() = default;

  virtual void SetSink(IZUVoiceTranslationSink* sink) = 0;
  virtual void SetWindowParent(void* parent) = 0;

  virtual void UpdateData() = 0;

  virtual void ShowWindow(void* parent = nullptr) = 0;
  virtual void HideWindow() = 0;
  // Legacy 2-arg overload. KEPT AT ITS ORIGINAL VTABLE SLOT for ABI back-compat
  // with binaries built against the pre-ZOOM-1248707 header (see ZOOM-557853
  // for the kind of vtable-offset crash that happens when the slot at a given
  // index changes signature). x/y are interpreted as DIP.
  virtual void UpdatePosition(int x, int y) = 0;
  virtual bool IsWindowVisible() = 0;
  virtual bool IsWindowMouseHovered() = 0;
  virtual void* GetWindowHandle() = 0;
  virtual Layout::Rect GetWindowGeometry() = 0;

  // ----------------------------------------------------------------------
  // ABI extension. Added at the END of the vtable. Do NOT reorder or
  // insert anything before this point -- binaries built against an older
  // header rely on the preceding virtuals keeping their exact slot indices.
  // ----------------------------------------------------------------------

  // Extended UpdatePosition with explicit unit + anchor monitor DPI.
  // See IZUIMeetingEncryptionMgr::UpdatePosition for the full semantics of
  // usePhysicalPixels and anchorDpi.
  //
  // Non-pure by design: implementations that have not been ported keep their
  // legacy 2-arg DIP behavior via this default forwarder, so old and new
  // binaries can be linked together without forcing a synchronous upgrade
  // of every implementation in the tree.
  virtual void UpdatePosition(int x, int y, bool usePhysicalPixels, int anchorDpi)
  {
    (void)usePhysicalPixels;
    (void)anchorDpi;
    UpdatePosition(x, y);
  }
};

class IZUVoiceTranslationSink
{
public:
  virtual ~IZUVoiceTranslationSink() = default;

  virtual void OnWindowShown() {}
  virtual void OnWindowSizeChanged(int width, int height) {}
  virtual void OnWindowHidden() {}
  virtual void OnWindowActiveChanged(bool active) {}
  virtual void OnMouseHoverChanged(bool hovered) {}
};

#endif // ZUI_VOICE_TRANSLATION_IT_H
