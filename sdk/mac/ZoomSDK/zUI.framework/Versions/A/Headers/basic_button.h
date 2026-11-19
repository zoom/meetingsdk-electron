/**
 * @file basic_button.h
 * @brief Basic button component
 * 
 * Provides a simple button component for user interaction.
 */

#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "text.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class BasicButton
	 * @ingroup controls_buttons
	 * @brief A fundamental button component for user interactions.
	 * 
	 * BasicButton is the primary interactive component in zUI, implementing
	 * Zoom's Prism design system button specifications. It provides consistent
	 * styling, behavior, and accessibility features across all platforms.
	 * 
	 * **Key Features:**
	 * - Prism design system compliance
	 * - Multiple visual styles for different use cases
	 * - Built-in loading states with activity indicators
	 * - Icon support (leading and trailing)
	 * - Tooltip and popover integration
	 * - Full accessibility support
	 * - Reactive text content
	 * 
	 * **Usage Guidelines:**
	 * 
	 * @code{.cpp}
	 * // Primary actions (most important)
	 * BasicButton("Save Changes")
	 *     .style(BasicButton::Style::kPrimary)
	 *     .onClick([this]() { saveData(); });
	 * 
	 * // Secondary actions
	 * BasicButton("Cancel")
	 *     .style(BasicButton::Style::kSecondary)
	 *     .onClick([this]() { closeDialog(); });
	 * 
	 * // Destructive actions
	 * BasicButton("Delete")
	 *     .style(BasicButton::Style::kDangerPrimary)
	 *     .onClick([this]() { confirmDelete(); });
	 * 
	 * // With icons and loading states
	 * BasicButton("Upload File")
	 *     .style(BasicButton::Style::kPrimary)
	 *     .leadingIcon("upload-icon")
	 *     .activityIndicator(_isUploading)
	 *     .onClick([this]() { startUpload(); });
	 * 
	 * // Reactive button text
	 * State<int> count = 0;
	 * BasicButton(count.bind([](int c) {
	 *     return "Items: " + std::to_string(c);
	 * }))
	 *     .style(BasicButton::Style::kSecondary);
	 * @endcode
	 * 
	 * @see zui::IconButton for icon-only buttons
	 */
	class ZUI_API BasicButton
		: public View
	{
	public:
		/**
		 * @enum Style
		 * @brief Defines the visual style and semantic meaning of the button
		 * 
		 * Button styles follow Prism design system hierarchy:
		 * - **Primary**: Most important action in a context (e.g., "Save", "Submit")
		 * - **Secondary**: Supporting actions (e.g., "Cancel", "Back")
		 * - **Tertiary**: Least emphasis, often text-only appearance
		 * - **Danger**: Destructive actions (e.g., "Delete", "Remove")
		 */
		enum class Style
		{
			kPrimary,       ///< Primary emphasis - use for main call-to-action
			kSecondary,     ///< Secondary emphasis - use for supporting actions
			kTetiary,       ///< Tertiary emphasis - minimal styling, often text-only
			kOverlay,       ///< Special style for buttons over image/video overlays
			kSelected,      ///< Indicates selected/active state
			kDangerPrimary, ///< Primary destructive action (e.g., "Delete Account")
			kDangerSecondary, ///< Secondary destructive action
			kDangerTetiary  ///< Tertiary destructive action
		};

		/**
		 * @enum Size
		 * @brief Defines the size of the button
		 */
		enum class Size
		{
			kSmall,         ///< Small-sized button
			kMedium,        ///< Medium-sized button (default)
			kLarge,         ///< Large-sized button
			kXLarge         ///< Extra large-sized button
		};

	public:
		/**
		 * @brief Constructs a BasicButton with the given text
		 * @param text The text displayed on the button
		 */
		explicit BasicButton(const Bind<std::string>& text);

		/// @brief Virtual destructor
		virtual ~BasicButton() = default;

		/**
		 * @brief Sets the visual style of the button
		 * @param style The style to apply
		 * @return Reference to this button for method chaining
		 */
		BasicButton& style(const Bind<Style>& style);

		/**
		 * @brief Sets the size of the button
		 * @param size The size to apply
		 * @return Reference to this button for method chaining
		 */
		BasicButton& size(const Bind<Size>& size);

		/**
		 * @brief Sets the leading (left in LTR) icon
		 * @param icon The path to the icon image
		 * @return Reference to this button for method chaining
		 */
		BasicButton& leadingIcon(const Bind<std::string>& icon);

		/**
		 * @brief Sets the trailing (right in LTR) icon
		 * @param icon The path to the icon image
		 * @return Reference to this button for method chaining
		 */
		BasicButton& trailingIcon(const Bind<std::string>& icon);

		/**
		 * @brief Shows or hides an activity indicator (spinner) on the button
		 * @param show Whether to show the activity indicator
		 * @return Reference to this button for method chaining
		 */
		BasicButton& activityIndicator(const Bind<bool>& show);

		/**
		 * @brief Controls whether the icon is recolored to match the button text color
		 *
		 * By default (false) the icon is tinted to the text color. Pass true to keep
		 * the icon's original colors untouched (multi-color / branded icons).
		 * @param keep true to preserve the icon's original color, false to recolor
		 * @return Reference to this button for method chaining
		 */
		BasicButton& keepIconColor(const Bind<bool>& keep);

		/**
		 * @brief Sets the click event handler
		 * @param callback The function to be called when the button is clicked
		 * @return Reference to this button for method chaining
		 */
		BasicButton& onClick(std::function<void()> callback);

		/**
		 * @brief Sets the click event handler
		 * @param callback The function to be called when the button is clicked
		 * @param keyboardTransfer The function to be called when the click event is transfered from keyboard event
		 * @return Reference to this button for method chaining
		 */
		BasicButton& onClick(std::function<void()> callback, std::function<void()> keyboardTransfer);
	};

namespace p
{

  // BasicButton-specific pipe modifiers
  class ZUI_API basicButtonStyle : public PipeModifier
  {
  public:
    explicit basicButtonStyle(const Bind<BasicButton::Style>& style);
    ~basicButtonStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonSize : public PipeModifier
  {
  public:
    explicit basicButtonSize(const Bind<BasicButton::Size>& size);
    ~basicButtonSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonOnClick : public PipeModifier
  {
  public:
    explicit basicButtonOnClick(std::function<void()> callback, std::function<void()> keyboardTransfer);
    ~basicButtonOnClick();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonActivityIndicator : public PipeModifier
  {
  public:
    explicit basicButtonActivityIndicator(const Bind<bool>& show);
    ~basicButtonActivityIndicator();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonKeepIconColor : public PipeModifier
  {
  public:
    explicit basicButtonKeepIconColor(const Bind<bool>& keep);
    ~basicButtonKeepIconColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonLeadingIcon : public PipeModifier
  {
  public:
    explicit basicButtonLeadingIcon(const Bind<std::string>& icon);
    ~basicButtonLeadingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API basicButtonTrailingIcon : public PipeModifier
  {
  public:
    explicit basicButtonTrailingIcon(const Bind<std::string>& icon);
    ~basicButtonTrailingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };


  namespace discover {
    namespace by_view {
      namespace basic_button {
        using zui::p::basicButtonStyle;
        using zui::p::basicButtonSize;
        using zui::p::basicButtonOnClick;
        using zui::p::basicButtonActivityIndicator;
        using zui::p::basicButtonKeepIconColor;
        using zui::p::basicButtonLeadingIcon;
        using zui::p::basicButtonTrailingIcon;
      }
    }
  }

} // namespace p

}
