/**
 * @file tag.h
 * @brief Tag component for labeling and categorizing content
 * 
 * Provides tag functionality for organizing and filtering items.
 */

#pragma once

#include <memory>
#include "zui_data_define.h"
#include "view.h"

namespace zui
{
	/**
	 * @class Tag
	 * @brief A view component that displays a label with optional close button.
	 * @ingroup controls
	 * 
	 * The Tag component is used to label, categorize, or organize items with keywords.
	 * It's commonly used for:
	 * - Category labels
	 * - Filter tags
	 * - Keywords
	 * - User-removable selections
	 * 
	 * @example
	 * @code
	 * // Basic tag
	 * Tag()
	 *   .text("Design")
	 *   .size(Tag::Size::kMedium)
	 *   .clearButton(true)
	 *   .onClick([]() { ... })
	 *   .onClickClose([]() { ... });
	 * @endcode
	 */
	class ZUI_API Tag : public View
	{
	public:
		/**
		 * @enum Size
		 * @brief Defines the size of the tag
		 */
		enum class Size
		{
			kSmall,   ///< Small tag (padding: 4px horizontal, 0px vertical)
			kMedium,  ///< Medium tag (padding: 6px horizontal, 2px vertical)
			kLarge,   ///< Large tag (padding: 6px horizontal, 4px vertical)
		};

	public:
		/// @brief Constructs a new Tag object
		Tag();

		/// @brief Virtual destructor
		virtual ~Tag() = default;

		/**
		 * @brief Sets the text displayed in the tag
		 * @param text The text to display
		 * @return Reference to this tag for method chaining
		 */
		Tag& text(const Bind<std::string>& text);

		/**
		 * @brief Sets the size of the tag
		 * @param size The size to apply
		 * @return Reference to this tag for method chaining
		 */
		Tag& tagSize(const Bind<Size>& size);

		/**
		 * @brief Sets whether the close button is visible
		 * @param show True to show the close button, false to hide it
		 * @return Reference to this tag for method chaining
		 */
		Tag& clearButton(const Bind<bool>& show);

		/**
		 * @brief Sets the callback for when the tag is clicked
		 * @param handler Function to call when clicked
		 * @return Reference to this tag for method chaining
		 */
		Tag& onClick(const std::function<void()>& handler);

		/**
		 * @brief Sets the callback for when the close button is clicked
		 * @param handler Function to call when close button is clicked
		 * @return Reference to this tag for method chaining
		 */
		Tag& onClickClose(const std::function<void()>& handler);
	};

namespace p
{
  class ZUI_API tagText : public PipeModifier
  {
  public:
    explicit tagText(const Bind<std::string>& text);
    ~tagText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tagSize : public PipeModifier
  {
  public:
    explicit tagSize(const Bind<Tag::Size>& size);
    ~tagSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tagClearButton : public PipeModifier
  {
  public:
    explicit tagClearButton(const Bind<bool>& show);
    ~tagClearButton();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tagOnClick : public PipeModifier
  {
  public:
    explicit tagOnClick(const std::function<void()>& handler);
    ~tagOnClick();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tagOnClickClose : public PipeModifier
  {
  public:
    explicit tagOnClickClose(const std::function<void()>& handler);
    ~tagOnClickClose();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace tag {
        using zui::p::tagText;
        using zui::p::tagSize;
        using zui::p::tagClearButton;
        using zui::p::tagOnClick;
        using zui::p::tagOnClickClose;
      }
    }
  }

} // namespace p

}

