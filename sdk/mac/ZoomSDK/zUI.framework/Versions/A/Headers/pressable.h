/**
 * @file pressable.h
 * @brief Lightweight interactive wrapper with built-in hover/pressed effects
 * 
 * Pressable is similar to Flutter's InkWell or wrapping content in a SwiftUI Button.
 * It provides the simplest way to add hover and pressed effects to any content.
 */

#pragma once

#include "interactive_container.h"

namespace zui {

  /**
   * @class Pressable
   * @brief Lightweight interactive container for hover/pressed effects
   * 
   * Wraps any content and automatically manages hover, pressed, and focus states.
   * This is the recommended way to add simple interaction effects to containers.
   * 
   * For dropdown functionality, use DropdownButton instead.
   */
  class ZUI_API Pressable : public InteractiveContainer
  {
  public:
    /**
     * @brief Constructs a Pressable with child views
     * @tparam Views Variadic template for child views
     * @param views Child views to wrap
     */
    template<typename... Views>
    Pressable(Views&&... views)
      : InteractiveContainer(
          View::Type::Pressable,
          [this]() { return BuildPressable(); },
          std::forward<Views>(views)...)
    {
    }

    ~Pressable() = default;

    std::shared_ptr<View> Clone() const override;

    /// @brief Builds the Pressable view node
    std::shared_ptr<ViewNode> BuildPressable();
  };

} // namespace zui

