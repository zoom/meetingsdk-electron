#ifndef ZUI_ACCESSIBILITY_TYPES_H
#define ZUI_ACCESSIBILITY_TYPES_H

#include <cstdint>
#include <optional>

namespace zui
{
  enum class AccessibilityRole : int
  {
    kNone = -1,
    kText = 0,
    kButton = 1,
    kProgressIndicator = 2,
    kDropdown = 3,
    kLink = 30,
  };

  enum class AccessibilityIntent : uint32_t
  {
    kUnspecified = 0,
    kReadable,
    kExposeOnMacOnly,
  };

  enum class AccessibilityChildrenPolicy : uint32_t
  {
    kUnspecified = 0,
    kContain,
    kCombine,
    kIgnore,
  };

}

#endif
