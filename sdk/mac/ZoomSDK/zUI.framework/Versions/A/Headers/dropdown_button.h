#pragma once

#include "interactive_container.h"
#include "zui_popup_common.h"

namespace zui
{
  // Dropdown-specific aliases for clarity
  using DropdownClosePolicy = PopupClosePolicy;
  using DropdownContext = PopupContext;

  class DropdownButtonNode;
	
  /**
   * @class DropdownButton
   * @brief Interactive button with dropdown popup support
   * 
   * Inherits multi-state background support from InteractiveContainer.
   * Adds dropdown-specific functionality like popup view and close policy.
   * 
   * @example
   * ```cpp
   * DropdownButton()
   *   .content(HorizontalStack { ... })
   *   .backgrounds(normalBg, hoverBg, pressedBg)
   *   .closePolicy(DropdownClosePolicy::CloseOnSelect)
   *   .popupView([this]() { return BuildMenu(); });
   * ```
   */
	class ZUI_API DropdownButton : public InteractiveContainer
	{
	public:
    template<typename... Views>
		DropdownButton(Views&&... views)
      : InteractiveContainer(
          View::Type::DropdownButton,
          [this]() { return BuildDropdownButton(); },
          std::forward<Views>(views)...)
    {
    }

    std::shared_ptr<ViewNode> BuildDropdownButton();

		virtual ~DropdownButton() = default;

    /**
     * @brief Sets the displayed content of the dropdown button
     * @param view The content view to display
     */
    DropdownButton& content(std::shared_ptr<View> view);

    /**
     * @brief Sets popup view callback (simple version for most scenarios)
     * @param func Callback function that returns the popup view
     * 
     * Close behavior is controlled by closePolicy:
     * - CloseOnSelect (default): Closes after selecting an option
     * - CloseOnOutsideClick: Only closes on outside click (multi-select)
     * 
     * @code
     * .popupView([this]() {
     *   return std::make_shared<DropDownMenu>(selectedIndex, onSelect);
     * })
     * @endcode
     */
    DropdownButton& popupView(const std::function<std::shared_ptr<View>()>& func);

    /**
     * @brief Sets popup view callback with context (for Manual policy only)
     * @param func Callback with ctx for manual dropdown control
     * 
     * Use when closePolicy is Manual, call ctx.close() to close manually.
     * 
     * @code
     * .closePolicy(DropdownClosePolicy::Manual)
     * .popupView([](DropdownContext& ctx) {
     *   return VerticalStack{
     *     Button("Confirm").onClick([ctx]() mutable { ctx.close(); })
     *   };
     * })
     * @endcode
     */
    DropdownButton& popupView(const std::function<std::shared_ptr<View>(DropdownContext& ctx)>& func);

    /**
     * @brief Sets the close policy
     * @param policy Close policy
     * - CloseOnSelect: Close after selection (default, for single-select)
     * - CloseOnOutsideClick: Only close on outside click (for multi-select)
     * - Manual: Requires manual ctx.close() call
     */
    DropdownButton& closePolicy(DropdownClosePolicy policy);
	};
} 

