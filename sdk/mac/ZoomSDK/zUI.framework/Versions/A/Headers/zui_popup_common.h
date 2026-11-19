#ifndef ZUI_POPUP_COMMON_H
#define ZUI_POPUP_COMMON_H

#include <functional>

#include "zui_api.h"
#include "model/model.h"

namespace zui
{
  /**
   * @brief Popup close policy
   * Controls when a popup automatically closes
   */
  enum class PopupClosePolicy
  {
    CloseOnSelect,       ///< Close immediately after selecting an item (default)
    CloseOnOutsideClick, ///< Only close when clicking outside (for multi-select)
    Manual               ///< Must call ctx.close() explicitly
  };

  /**
   * @brief Popup context for manual close control and optional keyboard navigation
   * Passed to popup builder function when using Manual close policy / keyboard nav
   */
  class ZUI_API PopupContext
  {
  public:
    struct KeyboardNavigation
    {
      bool enabled = false;
      int itemCount = 0;
      std::function<int()> getHighlight;
      std::function<void(int)> setHighlight;
      std::function<void(int)> onActivate;
    };

    explicit PopupContext(
        std::function<void()> closeFunc,
        std::function<void(const KeyboardNavigation&)> registerNav = nullptr)
      : _closeFunc(std::move(closeFunc))
      , _registerNav(std::move(registerNav))
    {
    }

    /// @brief Closes the popup
    void close()
    {
      if (_closeFunc)
      {
        _closeFunc();
      }
    }

    /**
     * @brief Enable Up/Down highlight + Enter/Space activate while the popup is open.
     * @param itemCount Number of navigable items
     * @param highlight Highlight index state (drive row visuals via calc)
     * @param onActivate Called when Enter/Space confirms the highlighted item
     * @param startIndex If >= 0, highlight is reset to this index when enabling
     *                   (typically the currently selected item)
     */
    void enableKeyboardNavigation(int itemCount,
                                  State<int>& highlight,
                                  std::function<void(int)> onActivate,
                                  int startIndex = -1)
    {
      if (itemCount <= 0 || !_registerNav)
        return;

      if (startIndex >= 0)
      {
        int clamped = startIndex;
        if (clamped >= itemCount)
          clamped = itemCount - 1;
        highlight = clamped;
      }

      KeyboardNavigation nav;
      nav.enabled = true;
      nav.itemCount = itemCount;
      nav.getHighlight = [&highlight]() { return highlight.Get(); };
      nav.setHighlight = [&highlight](int index) { highlight = index; };
      nav.onActivate = std::move(onActivate);
      _registerNav(nav);
    }

  private:
    std::function<void()> _closeFunc;
    std::function<void(const KeyboardNavigation&)> _registerNav;
  };

  using PopoverContext = PopupContext;
}

#endif
