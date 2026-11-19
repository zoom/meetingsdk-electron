/**
 * @file interactive_container.h
 * @brief Base class for interactive containers with multi-state background support
 * 
 * InteractiveContainer provides built-in state management for hover, pressed,
 * focused, and disabled states. It serves as the base class for Pressable
 * and DropdownContainer.
 */

#pragma once

#include "view.h"

namespace zui {

  /**
   * @brief Control state enumeration for interactive controls
   * Following SwiftUI ControlState design pattern
   */
  enum class ControlState {
    Normal,     ///< Default state
    Hover,      ///< Mouse hover
    Pressed,    ///< Pressed state
    Focused,    ///< Focus state
    Disabled,   ///< Disabled state
    Selected    ///< Selected state
  };

  // Forward declaration
  class InteractiveContainerNode;

  /**
   * @class InteractiveContainer
   * @brief Base class for containers with multi-state background support
   * 
   * Provides automatic state management and background switching for:
   * - Normal state
   * - Hover state (mouse over)
   * - Pressed state (mouse down)
   * - Focused state (keyboard focus)
   * - Disabled state
   * 
   * This class is the base for Pressable (lightweight interaction) and
   * DropdownContainer (full dropdown functionality).
   */
  class ZUI_API InteractiveContainer : public View
  {
  public:
    template<typename... Views>
    InteractiveContainer(View::Type viewType, std::function<std::shared_ptr<ViewNode>()> builder, Views&&... views)
      : View(viewType, builder)
    {
      int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);
    }

    ~InteractiveContainer() = default;

    /**
     * @brief Sets background for a specific control state
     * @param state The control state (Normal, Hover, Pressed, Focused, Disabled)
     * @param imageOrColor Background image path (DuiLib format) or color token
     * @return Reference to this container for method chaining
     */
    InteractiveContainer& background(ControlState state, const std::string& imageOrColor);

    /**
     * @brief Sets backgrounds for multiple states at once
     * @param normal Background for normal state
     * @param hover Background for hover state (optional)
     * @param pressed Background for pressed state (optional)
     * @param focused Background for focused state (optional)
     * @param disabled Background for disabled state (optional)
     * @return Reference to this container for method chaining
     */
    InteractiveContainer& backgrounds(
      const std::string& normal,
      const std::string& hover = "",
      const std::string& pressed = "",
      const std::string& focused = "",
      const std::string& disabled = "");

    /**
     * @brief Sets border color for a specific control state
     * @param state The control state (Normal, Hover, Pressed, Focused, Disabled)
     * @param color Border color token
     * @return Reference to this container for method chaining
     */
    InteractiveContainer& borderColor(ControlState state, const std::string& color);

    /**
     * @brief Sets border colors for multiple states at once
     * @param normal Border color for normal state
     * @param hover Border color for hover state (optional)
     * @param pressed Border color for pressed state (optional)
     * @param focused Border color for focused state (optional)
     * @param disabled Border color for disabled state (optional)
     * @return Reference to this container for method chaining
     */
    InteractiveContainer& borderColors(
      const std::string& normal,
      const std::string& hover = "",
      const std::string& pressed = "",
      const std::string& focused = "",
      const std::string& disabled = "");

    /**
     * @brief Shorthand for setting only hover background
     * @param hoverBg Background for hover state
     * @return Reference to this container for method chaining
     * 
     * Normal state will use transparent/inherited background.
     * This is the most common use case for simple hover effects.
     */
    InteractiveContainer& hoverBackground(const std::string& hoverBg);

    /**
     * @brief Shorthand for setting hover and pressed backgrounds
     * @param hoverBg Background for hover state
     * @param pressedBg Background for pressed state
     * @return Reference to this container for method chaining
     */
    InteractiveContainer& hoverBackground(const std::string& hoverBg, const std::string& pressedBg);

  private:
    void AddChildView(std::shared_ptr<ViewNode> viewNode);
  };

} // namespace zui

