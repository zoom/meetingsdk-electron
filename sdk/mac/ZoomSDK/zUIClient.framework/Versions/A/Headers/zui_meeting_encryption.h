#ifndef ZUI_MEETING_ENCRYPTION_H
#define ZUI_MEETING_ENCRYPTION_H

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

class IZUIMeetingEncryptionSink
{
public:
  virtual ~IZUIMeetingEncryptionSink() = default;

  virtual void OnClickReportProblem() = 0;
  virtual void OnClickSecuritySetting() = 0;

  virtual void OnEncryptionShow() {}
  virtual void OnEncryptionSizeChanged(int width, int height) {}
  virtual void OnEncryptionHide() {}

  virtual void OnEncryptionActiveChanged(bool active) {}
  virtual void OnEncryptionMouseHoverChanged(bool hovered) {}
};

class ZUIClient_API IZUIMeetingEncryptionMgr
{
public:
  enum class Page
  {
    kMainInfo,
    kSecurityCode,
    kException,
  };

public:
  virtual ~IZUIMeetingEncryptionMgr() = default;

  virtual void ShowEncryptionInfo(void* parent = nullptr) = 0;
  virtual void HideEncryptionInfo() = 0;
  virtual void CloseEncryptionInfo() = 0;
  // Legacy 2-arg overload. KEPT AT ITS ORIGINAL VTABLE SLOT for ABI back-compat
  // with binaries built against the pre-ZOOM-1248707 header (see ZOOM-557853
  // for the kind of vtable-offset crash that happens when the slot at a given
  // index changes signature). x/y are interpreted as DIP.
  virtual void UpdatePosition(int x, int y) = 0;
  virtual bool IsEncryptionInfoVisible() = 0;

  virtual bool IsWindowMouseHovered() { return false; };

  virtual void SetSink(IZUIMeetingEncryptionSink* sink) = 0;
  virtual void* GetWindowHandle() = 0;
  virtual Layout::Rect GetWindowGeometry() = 0;

  virtual void UpdateData() = 0;
  virtual void SwitchToMainPage() = 0;

  virtual void SetPage(IZUIMeetingEncryptionMgr::Page page) = 0;
  virtual void SetDefaultPage(IZUIMeetingEncryptionMgr::Page page) = 0;
  virtual IZUIMeetingEncryptionMgr::Page GetCurrentPage() = 0;
  virtual bool IsCurrentPage(IZUIMeetingEncryptionMgr::Page page) = 0;

  // ----------------------------------------------------------------------
  // ABI extension. Added at the END of the vtable. Do NOT reorder or
  // insert anything before this point -- binaries built against an older
  // header rely on the preceding virtuals keeping their exact slot indices.
  // ----------------------------------------------------------------------

  // Extended UpdatePosition with explicit unit + anchor monitor DPI.
  //
  // usePhysicalPixels = true: x/y are virtual-screen physical pixels
  // (DPI-invariant). The Windows implementation should use
  // SetPhysicalPosition / GetPhysicalGeometry, bypassing DIP conversion so
  // the position stays correct across mixed-DPI multi-monitor setups.
  // Non-Windows callers should leave usePhysicalPixels = false; in that
  // case x/y are interpreted as DIP (legacy behavior).
  //
  // anchorDpi: when usePhysicalPixels = true, the *anchor monitor's*
  // effective DPI (96 = 100%, 120 = 125%, 144 = 150%, ...). The
  // implementation uses it to scale visual paddings that must match ZUI's
  // DPI-scaled popup shadow on the anchor monitor. 0 means "unknown" ->
  // implementation falls back to unscaled padding (legacy behavior).
  // Windows callers should compute this via CHighDpi::GetDpiFromRect(...)
  // so the ZUI side never has to load Shcore.dll itself.
  //
  // Non-pure by design: implementations that have not yet been ported keep
  // their legacy 2-arg behavior via this default forwarder. ABI back-compat:
  // an old caller that doesn't know about this overload simply does not
  // invoke this slot, and an old implementation that doesn't override it
  // still has an entry at this slot (the inline default below).
  virtual void UpdatePosition(int x, int y, bool usePhysicalPixels, int anchorDpi)
  {
    (void)usePhysicalPixels;
    (void)anchorDpi;
    UpdatePosition(x, y);
  }

  // ABI extension: hover-opened popups auto-close on mouse leave, while
  // click-opened popups let their activation owner control closure.
  virtual void SetAutoCloseOnMouseLeave(bool enabled)
  {
    (void)enabled;
  }
};

#endif // ZUI_MEETING_ENCRYPTION_H
