/**
 * @file dropdown.h
 * @brief Dropdown control components
 * 
 * Provides dropdown selection functionality with various styles and customization options.
 */

#pragma once

#include <functional>
#include <memory>
#include <list>
#include "view.h" 

#include "text.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class Dropdown
	 * @brief A view component that allows users to select from a list of options.
	 * @ingroup controls_input
	 * 
	 * The Dropdown component helps users navigate through options by allowing them
	 * to narrow down the list of items to a single specified criteria. It supports:
	 * - Multiple visual styles (basic, exposed editable, exposed read-only)
	 * - Various sizes (small, medium, large)
	 * - Text-based options
	 * - Custom option selection by text or index
	 * - Open/close event handling
	 * 
	 * @example
	 * @code
	 * // Basic dropdown with text options
	 * Dropdown("Select Language")
	 *   .option({"English", "Spanish", "French", "German"})
	 *   .style(Dropdown::Style::kBasic)
	 *   .size(Dropdown::Size::kMedium)
	 *   .select("English");
	 * 
	 * // Editable dropdown with custom options
	 * Dropdown()
	 *   .label("Choose Option")
	 *   .style(Dropdown::Style::kEditable)
	 *   .option(Text("Option 1"), Text("Option 2"))
	 *   .onOpened([]() { loadDynamicOptions(); });
	 * @endcode
	 */
	class ZUI_API Dropdown : public View
	{
	public:
		/**
		 * @enum Style
		 * @brief Defines the visual style and interaction mode of the dropdown
		 */
		enum class Style
		{
			kBasic,             ///< Standard dropdown with fixed options
			kExposedEditable,   ///< Dropdown with editable text input
			kExposedReadOnly,   ///< Dropdown with read-only exposed text
		};

		/**
		 * @enum Size
		 * @brief Defines the size of the dropdown
		 */
		enum class Size
		{
			kSmall,   ///< Small dropdown (24px height)
			kMedium,  ///< Medium dropdown (32px height, default)
			kLarge    ///< Large dropdown (40px height)
		};

		/**
		 * @brief Constructs a Dropdown object with an optional label
		 * @param label The label text for the dropdown (optional)
		 * @todo Consider making the label parameter truly optional by removing default value
		 */
		explicit Dropdown(const Bind<std::string>& label = Bind<std::string>(""));

		/// @brief Virtual destructor
		virtual ~Dropdown() = default;

		/**
		 * @brief Sets the label text for the dropdown
		 * @param label The label text to display
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& label(const Bind<std::string>& label);

		/**
		 * @brief Sets the unselected tip text shown when no option is selected
		 * @param tip The tip text to display when no selection is made
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& unselectedTip(const Bind<std::string>& tip);

		/**
		 * @brief Adds Text options to the dropdown (variadic template)
		 * @tparam Args Template parameter pack for Text objects
		 * @param args Variable number of Text objects to add as options
		 * @return Reference to this dropdown for method chaining
		 */
	template<typename... Args,
		typename = typename std::enable_if<std::conjunction<std::is_same<Args, Text>...>::value>::type>
		Dropdown& option(Args&&... args)
	{
		ProcessArgs(args...);
		return *this;
	}

		/**
		 * @brief Adds options from a list of Text objects
		 * @param text_list The list of Text objects to add as options
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& option(const std::list<Text>& text_list)
		{
			for (auto& text : text_list)
				DoOptionArgs(const_cast<Text&>(text));
			return *this;
		}

		/**
		 * @brief Adds options from a bound list of strings
		 * @param text_list The bound list of string options
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& option(const Bind<std::list<std::string>>& text_list);

		/**
		 * @brief Adds options from a vector of strings
		 * @param options The vector of string options
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& option(const std::vector<std::string>& options);

		/**
		 * @brief Sets user data associated with options
		 * @param data_list The list of user data strings
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& userData(const Bind<std::list<std::string>>& data_list);

    Dropdown& mixedStyleOption(const Bind<std::vector<std::vector<Text>>>& options);
		/**
		 * @brief Sets the visual style of the dropdown
		 * @param style The style to apply
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& style(const Dropdown::Style& style);

		/**
		 * @brief Sets the size of the dropdown
		 * @param size The size to apply
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& size(const Dropdown::Size& size);

		/**
		 * @brief Selects an option by its text content
		 * @param option The text of the option to select
		 * @return Reference to this dropdown for method chaining
		 * @todo Using text to identify options may be unreliable if text changes
		 */
		Dropdown& select(const Bind<std::string>& option);

		/**
		 * @brief Selects an option by its index
		 * @param index The zero-based index of the option to select
		 * @return Reference to this dropdown for method chaining
		 * @todo Using index may be unreliable if options are sorted or filtered
		 */
		Dropdown& select(const Bind<int>& index);

		/**
		 * @brief Enables full display mode for the dropdown
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& fullDisplay();

		/**
		 * @brief Disables full display mode for the dropdown
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& disableFullDisplay();

		/**
		 * @brief Sets the callback function for dropdown open events
		 * @param cb The function to call when the dropdown is opened
		 * @return Reference to this dropdown for method chaining
		 */
		Dropdown& onOpened(const std::function<void()>& cb);
    Dropdown& onEditTextChanged(const std::function<void(const std::string&)>& cb);

	protected:
		/// @brief Internal method to handle string option arguments
		void DoOptionArgs(const std::string& arg);

		/// @brief Internal method to handle Text option arguments
		void DoOptionArgs(Text& arg);

		/**
		 * @brief Internal template method to process multiple option arguments
		 * @tparam Arg First argument type
		 * @tparam Rest Remaining argument types
		 * @param arg First argument
		 * @param rest Remaining arguments
		 */
	template<typename Arg, typename... Rest,
		typename = typename std::enable_if<std::conjunction<std::is_same<Arg, Text>, std::is_same<Rest, Text>...>::value>::type>
		void ProcessArgs(Arg& arg, Rest&... rest)
	{
		DoOptionArgs(arg);
		ProcessArgs(rest...);
	}

		/// @brief Base case for ProcessArgs template recursion
		void ProcessArgs() { }
	};

namespace p
{

  // Dropdown-specific pipe modifiers
  class ZUI_API dropdownUnselectedTip : public PipeModifier
  {
  public:
    explicit dropdownUnselectedTip(const Bind<std::string>& tip);
    ~dropdownUnselectedTip();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownStyle : public PipeModifier
  {
  public:
    explicit dropdownStyle(const Dropdown::Style& style);
    ~dropdownStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownSize : public PipeModifier
  {
  public:
    explicit dropdownSize(const Dropdown::Size& size);
    ~dropdownSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownSelectText : public PipeModifier
  {
  public:
    explicit dropdownSelectText(const Bind<std::string>& option);
    ~dropdownSelectText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownSelectIndex : public PipeModifier
  {
  public:
    explicit dropdownSelectIndex(const Bind<int>& index);
    ~dropdownSelectIndex();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownFullDisplay : public PipeModifier
  {
  public:
    explicit dropdownFullDisplay();
    ~dropdownFullDisplay();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownDisableFullDisplay : public PipeModifier
  {
  public:
    explicit dropdownDisableFullDisplay();
    ~dropdownDisableFullDisplay();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownOnOpened : public PipeModifier
  {
  public:
    explicit dropdownOnOpened(const std::function<void()>& cb);
    ~dropdownOnOpened();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownOnEditTextChanged : public PipeModifier
  {
  public:
    explicit dropdownOnEditTextChanged(const std::function<void(const std::string&)>& cb);
    ~dropdownOnEditTextChanged();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API dropdownLabel : public PipeModifier
  {
  public:
    explicit dropdownLabel(const Bind<std::string>& label);
    ~dropdownLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  // Note: option() methods with various overloads are too complex for simple pipe modifiers
  // due to their template and variadic nature. Users should use dot notation for these.

  namespace discover {
    namespace by_view {
      namespace dropdown {
        using zui::p::dropdownUnselectedTip;
        using zui::p::dropdownStyle;
        using zui::p::dropdownSize;
        using zui::p::dropdownSelectText;
        using zui::p::dropdownSelectIndex;
        using zui::p::dropdownFullDisplay;
        using zui::p::dropdownDisableFullDisplay;
        using zui::p::dropdownOnOpened;
        using zui::p::dropdownOnEditTextChanged;
        using zui::p::dropdownLabel;
      }
    }
  }

} // namespace p

}
