/**
 * @file radio_button.h
 * @brief Radio button control components
 * 
 * Provides radio button functionality for mutually exclusive selection.
 */

#ifndef _ZUI_RADIO_BUTTON_H_
#define _ZUI_RADIO_BUTTON_H_

#include "view.h" 

#include "text.h"
#include <iostream>

namespace zui
{

/**
 * @class RadioButton
 * @brief A single radio button component for mutually exclusive selection.
 * @ingroup controls_input
 *
 * The RadioButton component represents a single option in a group of mutually
 * exclusive choices. When used within a RadioButtonGroup, only one radio button
 * can be selected at a time. It supports:
 * - Custom title text
 * - Associated data values
 * - Group value binding for selection state
 * - Integration with RadioButtonGroup for proper behavior
 *
 * @example
 * @code
 * // Individual radio button (typically used within RadioButtonGroup)
 * RadioButton()
 *   .title("Option 1")
 *   .value("option1")
 *   .groupValue(selectedValue);
 * @endcode
 *
 * @note RadioButton is typically used within a RadioButtonGroup rather than standalone
 * @see RadioButtonGroup
 */
class ZUI_API RadioButton : public View
{
public:
  /// @brief Constructs a new RadioButton object with an integer tag value
  explicit RadioButton(int value);

  /// @brief Constructs a new RadioButton object with an enum or integral tag value
  template <typename T, typename = typename std::enable_if<std::is_enum<T>::value || std::is_integral<T>::value>::type>
  explicit RadioButton(T value) : RadioButton(static_cast<int>(value)) {}
  
  /// @brief Virtual destructor
  virtual ~RadioButton() = default;
  
  /**
   * @brief Sets the label text displayed next to the radio button
   * @param label The text label for this radio button option
   * @return Reference to this radio button for method chaining
   */
  RadioButton& label(const std::string& label);
  
  /**
   * @brief Sets the group value binding for selection state
   * @param groupValue The bound value representing the currently selected option in the group
   * @return Reference to this radio button for method chaining
   * @note This is required when the radio button is used within a Loop component
   */
  RadioButton& groupValue(const Bind<int>& groupValue);
};

/**
 * @class RadioButtonGroup
 * @brief A container component that manages multiple RadioButton components.
 * @ingroup controls_input
 *
 * The RadioButtonGroup component ensures that only one radio button within the group
 * can be selected at a time, providing proper mutually exclusive behavior. It supports:
 * - Multiple radio button children
 * - Group value management for current selection
 * - Automatic text alignment across radio buttons
 * - Proper spacing and layout for radio button content
 *
 * @example
 * @code
 * // Radio button group with multiple options
 * RadioButtonGroup(
 *   RadioButton()
 *     .title("Small")
 *     .value("small"),
 *
 *   RadioButton()
 *     .title("Medium")
 *     .value("medium"),
 *
 *   RadioButton()
 *     .title("Large")
 *     .value("large")
 * )
 * .groupValue(selectedSize)
 * .textAutoAlignment(true);
 * @endcode
 */
class ZUI_API RadioButtonGroup : public View
{
public:
  /// @brief Top padding for radio button detail content
  static constexpr float RadioDetailTopPadding = -6.f;
  
#ifdef __MACOS__
  /// @brief Leading padding for content alignment (macOS)
  static constexpr float ContentLeadingPadding = 22.f;
#else
  /// @brief Leading padding for content alignment (other platforms)
  static constexpr float ContentLeadingPadding = 26.f;
#endif
  
  /**
   * @brief Constructs a RadioButtonGroup with multiple views
   * @tparam Views Template parameter pack for View objects
   * @param views Variable number of View objects (typically RadioButton instances)
   */
  template<typename... Views>
  RadioButtonGroup(Views&&... views)
  : View(View::Type::RadioButtonGroup, [this]() {
    return (this)->BuildRadioButtonGroup();
  })
  {
    int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
    static_cast<void>(dummy); // Prevent unused variable warning
  }
  
  /// @brief Virtual destructor
  ~RadioButtonGroup() = default;
  
  /**
   * @brief Sets the group value binding for managing selection state
   * @param groupValue The bound value representing the currently selected option
   * @return Reference to this radio button group for method chaining
   */
  RadioButtonGroup& groupValue(const Bind<int>& groupValue);
  
  /**
   * @brief Sets whether to automatically align text across radio buttons
   * @param enabled True to enable automatic text alignment, false to disable
   * @return Reference to this radio button group for method chaining
   * @note This helps maintain consistent visual alignment of radio button labels
   */
  RadioButtonGroup& textAutoAlignment(bool enabled);
  
  /**
   * @brief Sets whether to append radio position(1 of 3, 1/3, etc.) in accessibility screen reader
   * @param enabled True to enable position announcement, False to disable
   * @return Reference to this radio button group for method chaining
   */
  RadioButtonGroup& positionAnnouncement(bool enabled);
  
  /**
   * @bried Sets whether to generate sibling group tree for RadioButton's accessibility in zUI framework
   * @param enabled True to enable sibling group(default), False to disable
   * @return Reference to this radio button group for method chaining
   */
  RadioButtonGroup& siblingGroup(bool enabled);
  
  std::shared_ptr<ViewNode> BuildRadioButtonGroup();
  
private:
  /// @brief Internal method to add child view nodes
  void AddChildView(std::shared_ptr<ViewNode> viewNode);
};

namespace p
{

  // RadioButtonGroup-specific pipe modifiers
  class ZUI_API radioButtonGroupTextAutoAlignment : public PipeModifier
  {
  public:
    explicit radioButtonGroupTextAutoAlignment(bool enabled);
    ~radioButtonGroupTextAutoAlignment();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API radioButtonGroupPositionAnnouncement : public PipeModifier
  {
  public:
    explicit radioButtonGroupPositionAnnouncement(bool enabled);
    ~radioButtonGroupPositionAnnouncement();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API radioButtonGroupSiblingGroup : public PipeModifier
  {
  public:
    explicit radioButtonGroupSiblingGroup(bool enabled);
    ~radioButtonGroupSiblingGroup();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API radioButtonGroupValue : public PipeModifier
  {
  public:
    explicit radioButtonGroupValue(const Bind<int>& groupValue);
    ~radioButtonGroupValue();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API radioButtonGroupGroupValue : public PipeModifier
  {
  public:
    explicit radioButtonGroupGroupValue(const Bind<int>& groupValue);
    ~radioButtonGroupGroupValue();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API radioButtonLabel : public PipeModifier
  {
  public:
    explicit radioButtonLabel(const Bind<std::string>& label);
    ~radioButtonLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace radio_button {
        using zui::p::radioButtonLabel;
      }
      namespace radio_button_group {
        using zui::p::radioButtonGroupTextAutoAlignment;
        using zui::p::radioButtonGroupPositionAnnouncement;
        using zui::p::radioButtonGroupSiblingGroup;
        using zui::p::radioButtonGroupValue;
        using zui::p::radioButtonGroupGroupValue;
      }
    }
  }

}
}
#endif
