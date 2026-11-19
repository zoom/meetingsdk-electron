/**
 * @file input_field.h
 * @brief Input field component for text input and data entry
 * 
 * Provides versatile text input functionality with validation support.
 */

#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "link.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class InputField
	 * @brief A versatile text input component for user data entry.
	 * @ingroup controls_input
	 * 
	 * InputField is the primary text input component in zUI, supporting various
	 * input types and validation patterns following Prism design guidelines.
	 * It provides a consistent user experience across different platforms while
	 * offering extensive customization options.
	 * 
	 * **Supported Input Types:**
	 * - **Text**: General text input with optional validation
	 * - **Password**: Secure input with character masking
	 * - **Search**: Search-optimized input with magnifying glass icon
	 * - **Number**: Numeric input with validation and formatting
	 * - **Email**: Email input with built-in validation hints
	 * - **Multi-line**: Text area for longer content
	 * 
	 * **Key Features:**
	 * - Reactive value binding with @ref zui::State "State<std::string>"
	 * - Built-in validation and error display
	 * - Character count limits and display
	 * - Placeholder text and labels
	 * - Required field indicators
	 * - Focus and blur event handling
	 * - Accessibility support with proper labeling
	 * 
	 * **Form Integration Examples:**
	 * 
	 * @code{.cpp}
	 * class UserRegistrationForm : public View {
	 * private:
	 *     State<std::string> _email = "";
	 *     State<std::string> _password = "";
	 *     State<std::string> _confirmPassword = "";
	 *     State<std::string> _emailError = "";
	 * 
	 * public:
	 *     std::shared_ptr<ViewNode> Build() override {
	 *         return VerticalStack{
	 *             // Email input with validation
	 *             InputField(_email)
	 *                 .title("Email Address")
	 *                 .placeholder("user@example.com")
	 *                 .required(true)
	 *                 .errorText(_emailError)
	 *                 .onEditChanged([this](const std::string& email) {
	 *                     validateEmail(email);
	 *                 }),
	 *             
	 *             // Password input
	 *             InputField(_password)
	 *                 .title("Password")
	 *                 .placeholder("Enter secure password")
	 *                 .stylePassword()
	 *                 .required(true)
	 *                 .limitCharacterCount(128)
	 *                 .helpText("Minimum 8 characters"),
	 *             
	 *             // Confirm password
	 *             InputField(_confirmPassword)
	 *                 .title("Confirm Password")
	 *                 .stylePassword()
	 *                 .required(true)
	 *                 .onEditChanged([this](const std::string& confirm) {
	 *                     validatePasswordMatch(confirm);
	 *                 }),
	 *             
	 *             // Search field example
	 *             InputField(_searchQuery)
	 *                 .placeholder("Search users...")
	 *                 .styleSearch()
	 *                 .onEditChanged([this](const std::string& query) {
	 *                     performSearch(query);
	 *                 })
	 *         }
	 *         .spacing(16);
	 *     }
	 * };
	 * @endcode
	 * 
	 * @see @ref form_patterns "Form Design Patterns"
	 * @see @ref validation_guide "Input Validation Guide"
	 * @see @ref zui::BasicButton "BasicButton" for form submissions
	 */
	class ZUI_API InputField : public View
	{
	public:
		/// @brief Callback function type for edit change events
		using OnEditChangedFunc = std::function<void(const std::string&)>;

		/**
		 * @enum Style
		 * @brief Defines the input style and behavior of the input field
		 */
		enum class Style
		{
			kDefault = 1,   ///< Standard text input field
			kPassword = 2,  ///< Password input with masked characters
			kSearch = 3,    ///< Search input with search styling
			kSelect = 4,    ///< Select input (dropdown style)
			kNumber = 5,    ///< Numeric input with validation
			kCombo = 6,     ///< Combo input with dropdown functionality
			kTextArea = 7,  ///< Multi-line text area input
		};

		/// @brief Constructs a new InputField object with default style
		InputField();

		/// @brief Virtual destructor
		virtual ~InputField() = default;

		/**
		 * @brief Sets the input field style
		 * @param inputStyle The style to apply to the input field
		 * @return Reference to this input field for method chaining
		 */
		InputField& style(const Bind<InputField::Style>& inputStyle);

		/**
		 * @brief Sets the input field to default style
		 * @return Reference to this input field for method chaining
		 */
		InputField& styleDefault();

		/**
		 * @brief Sets the input field to password style (masked input)
		 * @return Reference to this input field for method chaining
		 */
		InputField& stylePassword();

		/**
		 * @brief Sets the input field to search style
		 * @return Reference to this input field for method chaining
		 */
		InputField& styleSearch();

		/**
		 * @brief Sets the input field to select style (dropdown)
		 * @return Reference to this input field for method chaining
		 */
		InputField& styleSelect();

		/**
		 * @brief Sets the input field to number style (numeric input)
		 * @return Reference to this input field for method chaining
		 */
		InputField& styleNumber();

		/**
		 * @brief Sets the input field to combo style (dropdown with text input)
		 * @return Reference to this input field for method chaining
		 */
		InputField& styleCombo();

		/**
		 * @brief Sets the label displayed above the input field
		 * @param label The label text to display
		 * @return Reference to this input field for method chaining
		 */
		InputField& label(const Bind<std::string>& label);

		/**
		 * @brief Sets the question mark tooltip text
		 * @param questionMarkText The tooltip text displayed when hovering over the question mark icon
		 * @return Reference to this input field for method chaining
		 */
		InputField& questionMarkText(const Bind<std::string>& questionMarkText);

		/**
		 * @brief Adds a link component to the input field
		 * @param linkText The link component to add
		 * @return Reference to this input field for method chaining
		 */
		InputField& link(Link&& linkText);

		/**
		 * @brief Sets whether the input field is required
		 * @param isRequired True if the field is required, false otherwise
		 * @return Reference to this input field for method chaining
		 */
		InputField& required(const Bind<bool>& isRequired);

		/**
		 * @brief Sets optional text displayed next to the label
		 * @param optional The optional indicator text (e.g., "(optional)")
		 * @return Reference to this input field for method chaining
		 */
		InputField& optional(const Bind<std::string>& optional);

		/**
		 * @brief Sets the placeholder text displayed when the input is empty
		 * @param placeHolder The placeholder text
		 * @return Reference to this input field for method chaining
		 */
		InputField& placeholder(const Bind<std::string>& placeHolder);

		/**
		 * @brief Sets the current text content of the input field
		 * @param text The text content
		 * @return Reference to this input field for method chaining
		 */
		InputField& text(const Bind<std::string>& text);

		/**
		 * @brief Sets the typography style of the input text
		 * @param typography The typography style to apply
		 * @return Reference to this input field for method chaining
		 */
		InputField& typography(const Bind<Text::Typography>& typography);

		/**
		 * @brief Sets the text color of the input field
		 * @param color The color value (e.g., "#FF0000", "red")
		 * @return Reference to this input field for method chaining
		 */
		InputField& textColor(const Bind<std::string>& color);

		/**
		 * @brief Sets the combo head text (for combo style inputs)
		 * @param comboHead The text displayed at the beginning of combo inputs
		 * @return Reference to this input field for method chaining
		 */
		InputField& comboHead(const Bind<std::string>& comboHead);

		/**
		 * @brief Sets whether to show error styling
		 * @param showError True to show error state, false otherwise
		 * @return Reference to this input field for method chaining
		 */
		InputField& error(const Bind<bool>& showError);

		/**
		 * @brief Sets whether to show a clear button when text is present
		 * @param allowClear True to show clear button, false otherwise
		 * @return Reference to this input field for method chaining
		 */
		InputField& allowClear(const Bind<bool>& allowClear);

		/**
		 * @brief Sets whether to show an up arrow (for number inputs or similar)
		 * @param showUpArrow True to show up arrow, false otherwise
		 * @return Reference to this input field for method chaining
		 * @todo Clarify the specific use case for the up arrow
		 */
		InputField& upArrow(const Bind<bool>& showUpArrow);

		/**
		 * @brief Sets whether the input field is read-only
		 * @param readOnly True for read-only mode, false for editable
		 * @return Reference to this input field for method chaining
		 */
		InputField& readOnly(const Bind<bool>& readOnly);

		/**
		 * @brief Sets the maximum character count and displays the limit
		 * @param maxCharacterCount The maximum allowed character length
		 * @return Reference to this input field for method chaining
		 */
		InputField& limitCharacterCount(const Bind<int>& maxCharacterCount);

		/**
		 * @brief Sets the numeric input range for styleNumber InputFields.
		 * @param minValue The minimum allowed integer value (inclusive)
		 * @param maxValue The maximum allowed integer value (inclusive)
		 * @return Reference to this input field for method chaining
		 *
		 * @note Only applies when style is `kNumber`. The range is forwarded
		 *       to the underlying native NumberInputField so that:
		 *       - the increment chevron is disabled when the value reaches
		 *         `maxValue`,
		 *       - the decrement chevron is disabled when the value reaches
		 *         `minValue`,
		 *       - keyboard input is automatically clamped to [min, max].
		 *       For non-`kNumber` styles the modifier is a silent no-op —
		 *       the binding is captured into the render-tree node, but the
		 *       native delegate ignores it (text-style controls have no
		 *       numeric semantics to clamp against).
		 *
		 * @note Platform support:
		 *       - **macOS**: implemented. The range is captured on first
		 *         render (passed to `PZMNumberInputField`'s `range:` init)
		 *         and cannot be reconfigured after the control has been
		 *         instantiated.
		 *       - **Windows**: not yet implemented — the modifier compiles
		 *         and runs without error (the values are propagated to the
		 *         render tree), but the native `CDsInput` does not yet
		 *         honor the range. See the `TODO(windows)` block in
		 *         `prism-ui/zUI/src/windows/dui_control_delegate.cpp`
		 *         (`DuiInputFieldAgent::ApplyNodeData`) for the wiring
		 *         instructions when adding native support.
		 *       - **Linux**: not yet implemented (qquick bridge unchanged).
		 */
		InputField& numericRange(const Bind<int>& minValue,
		                         const Bind<int>& maxValue);

		/**
		 * @brief Sets the unit suffix for a number input field.
		 * @param unitSuffix The unit text associated with the numeric value.
		 * @return Reference to this input field for method chaining.
		 *
		 * @note The value is forwarded to platform renderers. It is intended for
		 *       `kNumber` style input fields.
		 */
		InputField& unitSuffix(const Bind<std::string>& unitSuffix);

		/**
		 * @brief Sets the error message text displayed below the input
		 * @param errorText The error message to display
		 * @return Reference to this input field for method chaining
		 * @note If error text is set, consider automatically showing error state
		 */
		InputField& errorText(const Bind<std::string>& errorText);

		/**
		 * @brief Sets the help text displayed below the input
		 * @param helpText The help message to display
		 * @return Reference to this input field for method chaining
		 */
		InputField& helpText(const Bind<std::string>& helpText);

		/**
		 * @brief Sets whether to show the character count display
		 * @param show True to show character count, false to hide
		 * @return Reference to this input field for method chaining
		 * @note Character count is typically shown when a limit is set
		 */
		InputField& showCount(const Bind<bool>& show);

    /**
     * @brief Sets whether to automatically adjust height based on text content
     * @param autoHeight True to enable auto height adjustment, false for fixed height
     * @return Reference to this input field for method chaining
     * @note This is particularly useful for multi-line text input (TextArea style)
     */
    InputField& autoHeight(const Bind<bool>& autoHeight);

    /**
     * @brief Sets the trail hover image displayed when hovering over the input field
     * @param image The image resource string or path for the trail hover icon
     * @return Reference to this input field for method chaining
     * @note The trail hover image is shown on hover and hidden during editing or when not hovering
     */
    InputField& trailHoverImage(const Bind<std::string>& image);

		/**
		 * @brief Sets the callback function for text change events
		 * @param func The function to call when the input text changes
		 * @return Reference to this input field for method chaining
		 */
		InputField& onEditChanged(const OnEditChangedFunc& func);

		/**
		 * @brief Disables the Enter key functionality in the input field
		 * @return Reference to this input field for method chaining
		 * @note When disabled, pressing Enter will not trigger any action (e.g., form submission)
		 */
		InputField& disableEnter();
	};

namespace p
{

  // InputField-specific pipe modifiers
  class ZUI_API inputFieldStyle : public PipeModifier
  {
  public:
    explicit inputFieldStyle(const Bind<InputField::Style>& inputStyle);
    ~inputFieldStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldQuestionMarkText : public PipeModifier
  {
  public:
    explicit inputFieldQuestionMarkText(const Bind<std::string>& questionMarkText);
    ~inputFieldQuestionMarkText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldRequired : public PipeModifier
  {
  public:
    explicit inputFieldRequired(const Bind<bool>& isRequired);
    ~inputFieldRequired();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldOptional : public PipeModifier
  {
  public:
    explicit inputFieldOptional(const Bind<std::string>& optional);
    ~inputFieldOptional();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldPlaceholder : public PipeModifier
  {
  public:
    explicit inputFieldPlaceholder(const Bind<std::string>& placeHolder);
    ~inputFieldPlaceholder();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldText : public PipeModifier
  {
  public:
    explicit inputFieldText(const Bind<std::string>& text);
    ~inputFieldText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldComboHead : public PipeModifier
  {
  public:
    explicit inputFieldComboHead(const Bind<std::string>& comboHead);
    ~inputFieldComboHead();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldError : public PipeModifier
  {
  public:
    explicit inputFieldError(const Bind<bool>& showError);
    ~inputFieldError();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldAllowClear : public PipeModifier
  {
  public:
    explicit inputFieldAllowClear(const Bind<bool>& allowClear);
    ~inputFieldAllowClear();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldUpArrow : public PipeModifier
  {
  public:
    explicit inputFieldUpArrow(const Bind<bool>& showUpArrow);
    ~inputFieldUpArrow();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldReadOnly : public PipeModifier
  {
  public:
    explicit inputFieldReadOnly(const Bind<bool>& readOnly);
    ~inputFieldReadOnly();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldLimitCharacterCount : public PipeModifier
  {
  public:
    explicit inputFieldLimitCharacterCount(const Bind<int>& maxCharacterCount);
    ~inputFieldLimitCharacterCount();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldErrorText : public PipeModifier
  {
  public:
    explicit inputFieldErrorText(const Bind<std::string>& errorText);
    ~inputFieldErrorText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldHelpText : public PipeModifier
  {
  public:
    explicit inputFieldHelpText(const Bind<std::string>& helpText);
    ~inputFieldHelpText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldShowCount : public PipeModifier
  {
  public:
    explicit inputFieldShowCount(const Bind<bool>& show);
    ~inputFieldShowCount();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldOnEditChanged : public PipeModifier
  {
  public:
    explicit inputFieldOnEditChanged(const InputField::OnEditChangedFunc& func);
    ~inputFieldOnEditChanged();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldLabel : public PipeModifier
  {
  public:
    explicit inputFieldLabel(const Bind<std::string>& label);
    ~inputFieldLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldTypography : public PipeModifier
  {
  public:
    explicit inputFieldTypography(const Bind<Text::Typography>& typography);
    ~inputFieldTypography();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldTextColor : public PipeModifier
  {
  public:
    explicit inputFieldTextColor(const Bind<std::string>& color);
    ~inputFieldTextColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldAutoHeight : public PipeModifier
  {
  public:
    explicit inputFieldAutoHeight(const Bind<bool>& autoHeight);
    ~inputFieldAutoHeight();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldTrailHoverImage : public PipeModifier
  {
  public:
    explicit inputFieldTrailHoverImage(const Bind<std::string>& image);
    ~inputFieldTrailHoverImage();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API inputFieldDisableEnter : public PipeModifier
  {
  public:
    inputFieldDisableEnter();
    ~inputFieldDisableEnter();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace input_field {
        using zui::p::inputFieldStyle;
        using zui::p::inputFieldQuestionMarkText;
        using zui::p::inputFieldRequired;
        using zui::p::inputFieldOptional;
        using zui::p::inputFieldPlaceholder;
        using zui::p::inputFieldText;
        using zui::p::inputFieldComboHead;
        using zui::p::inputFieldError;
        using zui::p::inputFieldAllowClear;
        using zui::p::inputFieldUpArrow;
        using zui::p::inputFieldReadOnly;
        using zui::p::inputFieldLimitCharacterCount;
        using zui::p::inputFieldErrorText;
        using zui::p::inputFieldHelpText;
        using zui::p::inputFieldShowCount;
        using zui::p::inputFieldOnEditChanged;
        using zui::p::inputFieldLabel;
        using zui::p::inputFieldTypography;
        using zui::p::inputFieldTextColor;
        using zui::p::inputFieldAutoHeight;
        using zui::p::inputFieldTrailHoverImage;
        using zui::p::inputFieldDisableEnter;
      }
    }
  }

} // namespace p

}
