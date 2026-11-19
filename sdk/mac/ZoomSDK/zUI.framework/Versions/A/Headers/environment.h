#ifndef __ZUI_ENVIRONMENT_H__
#define __ZUI_ENVIRONMENT_H__

#include <map>
#include <memory>
#include <vector>
#include <functional>
#include <string>
#include "zui_data_define.h"
#include "cmmlib/CmmAppContextSharedDef.h"
#include "model/model.h"

namespace Layout { struct Rect; }

namespace zui {

  class ZUI_API Environment
  {
  public:
    static Environment& Instance();

    Environment();
    ~Environment();

    void Insert(const std::string& key, EnvironmentValue val);

    void SetEngine(void* engine) { _engine = engine; }
    void* GetEngine() { return _engine; }

    void SetDarkMode(bool darkMode);
    zui::Bind<bool> GetDarkMode() const;
    bool GetDarkModeValue() const;

    /// Enables or disables the development-only zUI Inspector at runtime.
    void SetZUIInspectorEnabled(bool enabled);

    void SetLanguage(NS_ZOOM_DATA::CMM_LANGUAGE_ID_VALUE languageId);
    NS_ZOOM_DATA::CMM_LANGUAGE_ID_VALUE GetLanguage() const;

    int GetInt(const std::string& key, int defaultVal = 0) const;
    float GetFloat(const std::string& key, float defaultVal = 0.0f) const;
    std::string GetString(const std::string& key) const;
    std::function<void(const std::string&)> GetFunc(const std::string& key) const;

    std::string GetPlatformDelegateTargetId();
    void ScrollToTop(const std::string& scrollViewId);
    void ScrollToBottom(const std::string& scrollViewId);
    void OpenUrlWithDefaultBrowser(const std::string& url);
    void OpenSystemNotifications();
    void ScrollToView(const std::string& scrollViewId, const std::string& viewId, const std::string& highlightColor);
    void FocusToView(const std::string& scrollViewId, const std::string& viewId);
    void FocusToView(const std::string& viewId);
    void NotifyAccessibilityMessage(const std::string& message);
    void GetControlTree(const std::string& id, ZUIControlNode& root);

    /**
     * @brief Get the screen-coordinate rect of a ZUI view/control by its event ID.
     *
     * Returns the global (screen) bounding rect of the control, which can be used
     * to position a native window adjacent to it (e.g. a popup or tooltip window).
     *
     * @param viewId  The event ID of the view (set via .eventID(...) modifier)
     * @param rect    Output screen-coordinate rect {left, top, right, bottom} in logical pixels
     * @return true if the view was found and rect was filled; false otherwise
     */
     bool GetViewScreenRect(const std::string& viewId, Layout::Rect& rect);

    /**
     * @brief Post a task to the UI thread for asynchronous execution
     * 
     * This method posts a callback function to the message queue, executing it in the next event loop.
     * Useful for scenarios where delayed execution is needed to avoid conflicts with current operations.
     * 
     * @param callback The callback function to execute
     * @return Whether the post was successful
     * 
     * @example
     * // Use in popup dialog callback: close dialog first, then update state asynchronously
     * gEnvironment.PostTask([this]() {
     *   _testResult = std::string("Dialog closed!");
     * });
     */
    bool PostTask(std::function<void()> callback);

    /// Posts a task after pending UI work, including the current layout pass.
    bool PostTaskIdle(std::function<void()> callback);

    static void ReleaseUIManager();
    static void ReleaseCustomViews();

  public:
    static const std::string openWindow;
    static const std::string closeWindow;
    static const std::string destroyApp;
    static const std::string openUrl;
    static const std::string clientCMMLanguage;
    static const std::string openSystemNotifications;
    static const std::string language;

  private:
    std::map<std::string, EnvironmentValue> _data;
    zui::State<bool> _darkMode = false;
    void* _engine = nullptr; // for linux
  };
  inline Environment& gEnvironment = Environment::Instance();
}

#endif
