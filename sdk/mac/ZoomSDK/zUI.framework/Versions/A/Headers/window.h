/*****************************************************************************
*
* Copyright (C) 2024, Zoom Video Communications, Inc
*
*****************************************************************************/
#ifndef _ZUI_WINDOW_H_
#define _ZUI_WINDOW_H_

#include "zUI/view.h"

namespace zui {
  /**
   * @brief Window centering mode for Center(). Platform behavior differs.
   */
  enum class WindowCenterMode {
    kScreen,        ///< macOS/Linux: window's current screen; Win popup: cursor monitor
    kSystemDefault, ///< macOS: [window center]; Linux: primary screen; Win: owner/current monitor (not primary)
    kParent,        ///< Parent/owner; fallback kScreen on macOS/Linux, cursor monitor on Win popup
    kCursorScreen,  ///< Cursor's screen; same as kScreen on Win popup
    kPrimaryScreen, ///< Primary display work area on all platforms
  };
  // Window level constants definition
  #define ZUIWINDOWLEVEL_NORMAL           0
  #define ZUIWINDOWLEVEL_FLOATING         3
  #define ZUIWINDOWLEVEL_MODALPANEL       8
  #define ZUIWINDOWLEVEL_UTILITY          19
  #define ZUIWINDOWLEVEL_DOCK             20
  #define ZUIWINDOWLEVEL_MAINMENU         24
  #define ZUIWINDOWLEVEL_STATUS           25
  #define ZUIWINDOWLEVEL_POPUPMENU        101
  #define ZUIWINDOWLEVEL_OVERLAY          102
  #define ZUIWINDOWLEVEL_HELP             200
  #define ZUIWINDOWLEVEL_DRAGGING         500
  #define ZUIWINDOWLEVEL_SCREENSAVER      1000
  #define ZUIWINDOWLEVEL_ASSISTIVETECHHIGH 1500

  /**
   * @brief Window event callback interface
   */
  class IZUIWindowEventSink
  {
  public:
#ifdef _WIN32
    virtual bool IsLayeredWndStyleInNeed() { return false; }
    virtual void GetWndStyleInNeed(bool& layered, bool& transparent) {}
#endif
    virtual void OnWndHandleDestroyed(size_t windowID) {}
    virtual void OnActiveChanged(size_t windowID, bool active) {}
    virtual void OnVisibleChanged(size_t windowID, bool visible) {}
    virtual void OnSizeChanged(size_t windowID, const Layout::Size& size) {}
    virtual void OnMouseHoverChanged(size_t windowID, bool hovered) {}
    virtual void OnScrollDetectedForAnchoredWindow(size_t windowID) {}
  };

#ifdef _WIN32
#define ZUIWINDOW_WIN32_OVERRIDE \
  virtual bool IsLayeredWndStyleInNeed() override {\
    return zui::utils::IsLayeredWndStyleInNeed(); }\
  virtual void GetWndStyleInNeed(bool& layered, bool& transparent) override {\
    zui::utils::GetWndStyleInNeed(layered, transparent); }
#else
#define ZUIWINDOW_WIN32_OVERRIDE
#endif

  /**
   * @brief ZUI window interface class
   * Defines pure virtual interfaces for all window operations
   */
  class ZUI_API ZUIWindow : public std::enable_shared_from_this<ZUIWindow>
  {
  public:
    /**
     * @brief Window configuration data structure
     */
    struct WindowData
    {
      zui::WindowStyle style = WindowStyle::kDefaultPopup;
      Layout::Size size = Layout::Size(NAN, NAN);
      bool runModal = false;
      void* parent = nullptr;
      bool draggable = true;
      // MAC only
      bool useCustomLevel = false;
      int level = 26;
      bool syncLevelWithParent = false;
      bool autoFocusFirstControl = true;
      // linux only
      bool isCenter = true;
      bool needCustomPosition = false;
      bool needInputFocus = false;
      // Windows only
      bool needRootOwner = false;
      // Control Anchor
      std::string anchoredControlId;
      zui::ControlPosition controlPosition = zui::ControlPosition::kNone;
      zui::WindowAnchor windowAnchor = zui::WindowAnchor::kNone;
      // Popover direction
      PopoverDirection popoverDirection = PopoverDirection::kUp;
      PopoverTriggerMode popoverTriggerMode = PopoverTriggerMode::kAuto;
      bool popoverArrow = true;
      std::string popoverAttachId;
      int anchorPaddingX = 0;
      int anchorPaddingY = 0;
    };

    virtual ~ZUIWindow() = default;
    
    // Static factory method
    static std::shared_ptr<ZUIWindow> Create(const WindowData& windowData);
    
    // Window operation interfaces
    virtual void Show() = 0;
    virtual void Hide() = 0;
    /**
     * @brief Center the window
     * @param mode Centering mode (kScreen = center on screen, kParent = center on parent window)
     */
    virtual void Center(WindowCenterMode mode = WindowCenterMode::kScreen) = 0;
    virtual void Destroy() = 0;
    virtual void AsyncDestroy() = 0;
    virtual void MakeKey() = 0;
    
    // View management interfaces
    // The view will be cloned internally, which causes the SetUpdate initialized in the constructor to be lost.
    // If SetUpdate is set up in the constructor, please use the second overload instead.
    virtual void AttachView(const View& view) = 0;
    // avoiding cloning and preserving the SetUpdate initialized in the constructor.
    virtual void AttachView(std::shared_ptr<View> view) = 0;
    virtual void DetachView() = 0;
    
    // Property setting interfaces
    virtual void SetSize(const Layout::Size& windowSize) = 0;
    virtual void SetTitle(const std::string& windowTitle) = 0;
    virtual void SetPosition(const Layout::Position& position) = 0;
    virtual void SetPhysicalPosition(const Layout::Position& position) = 0;
    virtual void SetUserData(const std::string& name, void* data) = 0;
    virtual void SetKeyboardConfig(CmmUInt32 config) = 0;
    virtual void SetDarkMode(bool darkMode) = 0;
    virtual void MakeFirstRespondToNil() = 0;
    virtual void SetTelemetry(std::string telemetryID,
                              TelemetryModule telemetryModule = TelemetryModule::meetings) = 0;

    // Event callback interfaces
    [[deprecated("Use SetZUIWindowEventSink instead")]]
    virtual void SetOnActive(std::function<void(bool)> callback) = 0;
    [[deprecated("Use SetZUIWindowEventSink instead")]]
    virtual void SetOnDidHide(std::function<void()> callback) = 0;
    virtual void SetZUIWindowEventSink(IZUIWindowEventSink* sink) = 0;
    
    // Information query interfaces
    virtual size_t GetID() = 0;
    virtual WindowData GetWindowData() = 0;
    virtual bool IsWindowVisible() = 0;
    virtual void* GetHandle() = 0;
    virtual Layout::Rect GetGeometry() = 0;
    virtual Layout::Rect GetPhysicalGeometry() = 0;
    virtual bool IsMouseInside() = 0;

    /**
     * @brief Sets whether to close when losing focus (modeless window only)
     * @param closeOnBlur true = close on blur, false = close on outside click only
     */
    virtual void SetCloseOnBlur(bool closeOnBlur) {}

    /**
     * @brief Keyboard handler for modeless windows.
     * @param callback Return true if the key was handled.
     * Receives LogicalKey; platform layers map native VK / NSEvent.keyCode / Qt keys.
     */
    virtual void SetOnKeyDown(std::function<bool(LogicalKey key)> callback) { (void)callback; }

  protected:
    ZUIWindow() = default;  // Only allow derived class construction
    // Disable copy and move
    ZUIWindow(const ZUIWindow&) = delete;
    ZUIWindow& operator=(const ZUIWindow&) = delete;
    ZUIWindow(ZUIWindow&&) = delete;
    ZUIWindow& operator=(ZUIWindow&&) = delete;
  };
}

#endif
