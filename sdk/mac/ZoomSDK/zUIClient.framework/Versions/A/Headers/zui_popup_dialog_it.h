#ifndef ZUI_POPUP_DIALOG_IT_H_
#define ZUI_POPUP_DIALOG_IT_H_

#include <memory>
#include <string>
#include <functional>

namespace zui { class View; }

/**
 * @brief Popup dialog configuration options
 */
/**
 * @brief Dialog position mode
 */
enum class PopupDialogPosition
{
  kCenter,        // Center on screen (default)
  kCenterParent,  // Center on parent window
  kCustom         // Custom position (use x, y)
};

/**
 * @brief Button style for popup dialog buttons
 */
enum class PopupDialogBtnStyle
{
  kDefault,       // Default button style (blue primary)
  kDanger         // Danger/destructive action (red button)
};

/**
 * @brief Theme mode for popup dialogs
 */
enum class PopupDialogThemeMode
{
  kFollowSystem,  // Follow app/system theme dynamically
  kForceLight,    // Force light theme
  kForceDark      // Force dark theme
};

/**
 * @brief Popup dialog configuration options
 */
struct PopupDialogConfig
{
  // Title
  std::string title;
  bool showTitle = true;
  
  // Buttons
  std::string primaryBtnText;
  std::string secondaryBtnText;
  bool showPrimaryBtn = true;
  bool showSecondaryBtn = true;
  bool enablePrimaryBtn = true;
  bool enableSecondaryBtn = true;
  PopupDialogBtnStyle primaryBtnStyle = PopupDialogBtnStyle::kDefault;
  PopupDialogBtnStyle secondaryBtnStyle = PopupDialogBtnStyle::kDefault;
  
  // Styling
  int width = 400;
  int borderRadius = 8;
  int padding = 24;
  int buttonSpacing = 8;
  int borderSize = 0;           // Border width in pixels (0 = no border, uses borderSubtleNeutral color)
  
  // Window behavior
  bool closeOnBlur = false;
  // Legacy chrome toggle: swaps style between kBorderlessPopup (false) and
  // kTitlePopupWindow (true). Does NOT make the dialog input-blocking.
  bool modal = false;
  // Strict modality forwarded to WindowData::runModal. Orthogonal to
  // `modal`: pair runModal=true + modal=false for borderless input-blocking.
  // Platform dispatch in client-zui/.agents/kb/window-test-guide.md sec 4.6.
  bool runModal = false;
  // When true, a visibility transition to hidden is normalized as a close
  // event and triggers OnDialogClosed callback, even for non-runModal dialogs.
  // Use this for Esc/title-close fallback actions that must run consistently.
  bool closeOnHideAsClose = false;
  // For runModal=true Show paths without an explicit parent, lets the
  // Windows delegate resolve the active root window so EnableWindow targets it.
  bool needRootOwner = false;
  bool showCloseButton = false;
  
  // Content height limit (0 = no limit)
  int maxContentHeight = 0;
  
  // Position
  PopupDialogPosition positionMode = PopupDialogPosition::kCenter;
  int posX = 0;  // Used when positionMode == kCustom
  int posY = 0;  // Used when positionMode == kCustom
  
  // Theme
  PopupDialogThemeMode themeMode = PopupDialogThemeMode::kFollowSystem;
  bool disableEscape = false;
};

/**
 * @brief Raw popup dialog configuration (window-only, no built-in layout)
 * 
 * Use with IZUIRawPopupDialog for fully custom dialog layouts.
 */
struct RawPopupDialogConfig
{
  // Window size
  int width = 400;
  int height = 0;  // 0 = auto-fit to content
  
  // Window style
  int borderRadius = 8;
  int borderSize = 0;           // Border width in pixels (0 = no border, uses borderSubtleNeutral color)
  PopupDialogThemeMode themeMode = PopupDialogThemeMode::kFollowSystem;
  bool disableEscape = false;
  bool draggable = true;
  bool transparentBackground = false; // Let the custom root view own rounded corners/background.
  bool useCustomLevel = false; // macOS only
  int level = 26;              // macOS only
  
  // Window behavior
  bool closeOnBlur = false;
  bool modal = false;
  bool showCloseButton = false;
  
  // Position
  PopupDialogPosition positionMode = PopupDialogPosition::kCenter;
  int posX = 0;  // Used when positionMode == kCustom
  int posY = 0;  // Used when positionMode == kCustom
};

/**
 * @brief Raw popup dialog interface (window-only, fully custom View)
 * 
 * Provides only window management - View is completely controlled by business code.
 * Use this when standard Title/Content/Buttons layout is not sufficient.
 * 
 * Usage:
 * @code
 * auto rawDialog = popupMgr->MakeRawDialog();
 * 
 * RawPopupDialogConfig config;
 * config.width = 500;
 * config.darkMode = true;
 * rawDialog->SetConfig(config);
 * 
 * // Business fully controls the View
 * auto customView = std::make_shared<MyCustomView>();
 * rawDialog->SetView(customView);
 * rawDialog->Show();
 * @endcode
 */
class IZUIRawPopupDialog
{
public:
  virtual ~IZUIRawPopupDialog() = default;
  
  // Lifecycle
  virtual void Show(void* parent = nullptr) = 0;
  virtual void Hide() = 0;
  virtual void Close() = 0;
  virtual bool IsVisible() = 0;
  
  // Configuration
  virtual void SetConfig(const RawPopupDialogConfig& config) = 0;
  virtual RawPopupDialogConfig GetConfig() = 0;
  virtual void SetTitle(const std::string& title) = 0;
  
  // View - business fully controls
  virtual void SetView(std::shared_ptr<zui::View> view) = 0;
  
  // Position and Size
  virtual void SetPosition(int x, int y) = 0;
  virtual void SetSize(int width, int height) = 0;
  virtual void CenterOnScreen() = 0;
  virtual void CenterOnParent() = 0;
  virtual bool GetSize(int& width, int& height) = 0;
  virtual bool GetPosition(int& x, int& y) = 0;
  
  // Callbacks
  virtual void SetOnDialogShown(const std::function<void()>& callback) = 0;
  virtual void SetOnDialogClosed(const std::function<void()>& callback) = 0;
};

/**
 * @brief Single popup dialog instance interface
 * 
 * Represents one popup dialog window. Each instance is independent,
 * allowing multiple dialogs to be shown simultaneously.
 * 
 * Usage:
 * @code
 * auto dialog = popupMgr->MakeDialog();
 * dialog->SetConfig(config);
 * dialog->SetContentView(contentView);
 * dialog->SetOnPrimaryBtnClick([dialog]() { dialog->Close(); });
 * dialog->Show();
 * @endcode
 */
class IZUIPopupDialog
{
public:
  virtual ~IZUIPopupDialog() = default;
  
  // Lifecycle
  virtual void Show(void* parent = nullptr) = 0;
  virtual void Hide() = 0;
  virtual void Close() = 0;
  virtual bool IsVisible() = 0;
  
  // Configuration
  virtual void SetConfig(const PopupDialogConfig& config) = 0;
  virtual PopupDialogConfig GetConfig() = 0;
  virtual void SetContentView(std::shared_ptr<zui::View> contentView) = 0;
  
  // Dynamic updates
  virtual void SetTitle(const std::string& title) = 0;
  virtual void SetPrimaryBtnText(const std::string& text) = 0;
  virtual void SetSecondaryBtnText(const std::string& text) = 0;
  virtual void SetPrimaryBtnEnabled(bool enabled) = 0;
  virtual void SetSecondaryBtnEnabled(bool enabled) = 0;
  
  // Position and Size
  virtual void SetPosition(int x, int y) = 0;
  virtual void CenterOnScreen() = 0;
  virtual void CenterOnParent() = 0;
  
  /**
   * @brief Get dialog window size (available after Show)
   * @param width Output: window width in pixels
   * @param height Output: window height in pixels
   * @return true if size is available (window is shown), false otherwise
   */
  virtual bool GetSize(int& width, int& height) = 0;
  
  /**
   * @brief Get dialog window position (available after Show)
   * @param x Output: window X position in screen coordinates
   * @param y Output: window Y position in screen coordinates
   * @return true if position is available (window is shown), false otherwise
   */
  virtual bool GetPosition(int& x, int& y) = 0;
  
  // Callbacks
  virtual void SetOnPrimaryBtnClick(const std::function<void()>& callback) = 0;
  virtual void SetOnSecondaryBtnClick(const std::function<void()>& callback) = 0;
  virtual void SetOnDialogShown(const std::function<void()>& callback) = 0;
  virtual void SetOnDialogClosed(const std::function<void()>& callback) = 0;
};

/**
 * @brief Popup dialog factory interface
 * 
 * Creates independent popup dialog instances. Each dialog can be
 * configured and shown separately, supporting multiple dialogs at once.
 * 
 * Usage:
 * @code
 * IZUIPopupDialogMgr* mgr = GetPopupDialogMgr();
 * 
 * // Create first dialog
 * auto dialog1 = mgr->MakeDialog();
 * dialog1->SetConfig(config1);
 * dialog1->Show();
 * 
 * // Create second dialog (can be shown at the same time)
 * auto dialog2 = mgr->MakeDialog();
 * dialog2->SetConfig(config2);
 * dialog2->Show();
 * @endcode
 */
class IZUIPopupDialogMgr
{
public:
  virtual ~IZUIPopupDialogMgr() = default;
  
  /**
   * @brief Create a new popup dialog with standard layout (Title/Content/Buttons)
   * @return Shared pointer to the new dialog
   */
  virtual std::shared_ptr<IZUIPopupDialog> MakeDialog() = 0;
  
  /**
   * @brief Create a raw popup dialog (window-only, fully custom View)
   * 
   * Use when standard Title/Content/Buttons layout is not sufficient.
   * Business code fully controls the View content.
   * 
   * @return Shared pointer to the new raw dialog
   */
  virtual std::shared_ptr<IZUIRawPopupDialog> MakeRawDialog() = 0;
};

#endif // ZUI_POPUP_DIALOG_IT_H_
