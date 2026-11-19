/**
 * @file icon_button.h
 * @brief Icon button component for icon-based interactions
 * 
 * Provides button functionality with icon-based visual representation.
 */

#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "basic_button.h"
#include "menu.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class IconButton
	 * @brief A view component that provides icon-based button functionality.
	 * @ingroup controls_buttons
	 * 
	 * The IconButton component allows users to take actions through a button
	 * that uses an icon to elaborate on the button's function. It supports:
	 * - Multiple visual styles (primary, secondary, tertiary, overlay)
	 * - Various sizes (small, medium, large, extra large)
	 * - Activity indicators for loading states
	 * - Tooltip and popover integration
	 * - Click event handling
	 * 
	 * @example
	 * @code
	 * // Primary icon button
	 * IconButton()
	 *   .icon("save-icon.svg")
	 *   .style(IconButton::Style::kPrimary)
	 *   .size(IconButton::Size::kMedium)
	 *   .tooltip(ToolTip("Save document"))
	 *   .onClick([]() { saveDocument(); });
	 * 
	 * // Secondary icon button with activity indicator
	 * IconButton()
	 *   .icon("refresh-icon.svg")
	 *   .style(IconButton::Style::kSecondary)
	 *   .activityIndicator(isLoading)
	 *   .onClick([]() { refreshData(); });
	 * @endcode
	 */
	class ZUI_API IconButton
		: public View
	{
	public:
		/**
		 * @enum Style
		 * @brief Defines the visual style of the icon button
		 */
		enum class Style
		{
			kPrimary,   ///< Primary emphasis button
			kSecondary, ///< Secondary emphasis button
			kTetiary,   ///< Tertiary emphasis button
			kOverlay,   ///< Button for overlay contexts
		};

		/**
		 * @enum Size
		 * @brief Defines the size of the icon button
		 */
		enum class Size
		{
			kSmall,  ///< Small icon button
			kMedium, ///< Medium icon button (default)
			kLarge,  ///< Large icon button
			kXLarge  ///< Extra large icon button
		};

	public:
		/// @brief Constructs a new IconButton object
		explicit IconButton();

		/// @brief Virtual destructor
		virtual ~IconButton() = default;

		/**
		 * @brief Sets the visual style of the icon button
		 * @param style The style to apply
		 * @return Reference to this icon button for method chaining
		 * @todo Consider merging with BasicButton class since they share similar functionality
		 */
		IconButton& style(const Bind<Style>& style);

		/**
		 * @brief Sets the size of the icon button
		 * @param size The size to apply
		 * @return Reference to this icon button for method chaining
		 */
		IconButton& size(const Bind<Size>& size);

		/**
		 * @brief Sets the icon to display on the button
		 * @param icon The path to the icon image file
		 * @return Reference to this icon button for method chaining
		 */
		IconButton& icon(const Bind<std::string>& icon);

		/**
		 * @brief Shows or hides an activity indicator (spinner) on the button
		 * @param show True to show the activity indicator, false to hide
		 * @return Reference to this icon button for method chaining
		 */
		IconButton& activityIndicator(const Bind<bool>& show);

		/**
		 * @brief Sets the callback function for click events
		 * @param callback The function to call when the icon button is clicked
		 * @return Reference to this icon button for method chaining
		 */
		IconButton& onClick(std::function<void()> callback);

		/**
		 * @brief Sets the click event handler
		 * @param callback The function to be called when the button is clicked
		 * @param keyboardTransfer The function to be called when the click event is transfered from keyboard event
		 * @return Reference to this icon button for method chaining
		 */
		IconButton& onClick(std::function<void()> callback, std::function<void()> keyboardTransfer);
	};

namespace p
{

  // IconButton-specific pipe modifiers
  class ZUI_API iconButtonStyle : public PipeModifier
  {
  public:
    explicit iconButtonStyle(const Bind<IconButton::Style>& style);
    ~iconButtonStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API iconButtonSize : public PipeModifier
  {
  public:
    explicit iconButtonSize(const Bind<IconButton::Size>& size);
    ~iconButtonSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API iconButtonOnClick : public PipeModifier
  {
  public:
    explicit iconButtonOnClick(std::function<void()> callback, std::function<void()> keyboardTransfer);
    ~iconButtonOnClick();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API iconButtonIcon : public PipeModifier
  {
  public:
    explicit iconButtonIcon(const Bind<std::string>& iconPath);
    ~iconButtonIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API iconButtonActivityIndicator : public PipeModifier
  {
  public:
    explicit iconButtonActivityIndicator(const Bind<bool>& show);
    ~iconButtonActivityIndicator();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace icon_button {
        using zui::p::iconButtonStyle;
        using zui::p::iconButtonSize;
        using zui::p::iconButtonOnClick;
        using zui::p::iconButtonIcon;
        using zui::p::iconButtonActivityIndicator;
      }
    }
  }

} // namespace p

}

