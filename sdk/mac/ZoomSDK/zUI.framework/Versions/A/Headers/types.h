#ifndef TYPES_H
#define TYPES_H

#include <bitset>
#include <math.h>

#include "cmmlib/CmmDef.h"
#include "zui_data_define.h"

namespace zui
{
	enum class Result
	{
		kSuccess = 0,
		kFailure = 1
	};

	inline Result& operator|=(Result& lhs, Result rhs)
	{
		using Underlying = std::underlying_type_t<Result>;
		lhs = static_cast<Result>(
						static_cast<Underlying>(lhs) | static_cast<Underlying>(rhs)
				);
		return lhs;
	}

  enum class WindowStyle : uint32_t {
    // Basic styles
    kNone = 0x00000000,  // No style (bare window)

    // Title bar related
    kTitle = 0x00000001,  // Show title bar
    kCloseButton = 0x00000002,  // Show close button
    kMinimizeButton = 0x00000004,  // Show minimize button
    kMaximizeButton = 0x00000008,  // Show maximize button

    // Border and resizing
    kBorder = 0x00000010,  // Show border
    kResizable = 0x00000020,  // Resizable window
    kThickFrame = 0x00000040,  // Thick frame (draggable resize)

    // Window behavior
    kTopMost = 0x00000100,  // Always on top
    kToolWindow = 0x00000200,  // Tool window (not shown in taskbar)
    kModal = 0x00000400,  // Modal window

    // Special styles
    kTransparent = 0x00001000,  // Transparent background
    kLayered = 0x00002000,  // Layered window (supports transparency)
    kNoActivate = 0x00004000,  // Don't activate window
    kClickThrough = 0x00008000,  // Click-through window

    // Window levels
    kPopup = 0x00010000,
    kPopupWindow = 0x00020000,
    kPopover = 0x00040000,  // Popover window type

    // Composite styles
    kDefaultPopup = kPopup | kTitle | kBorder | kTopMost,
    kBorderlessPopup = kPopup | kTopMost,
    kTitlePopupWindow = kPopupWindow | kTitle | kBorder,
    
    // Modeless window style (for dropdown menus, tooltips, etc.)
    kModeless = kPopup | kBorder | kLayered | kToolWindow | kNoActivate
  };

  enum class ControlPosition {
    kNone,
    kLeftTop,
    kRightTop,
    kLeftBottom,
    kRightBottom,
    kCenter,
  };

  enum class WindowAnchor {
    kNone,
    kLeftTop,
    kRightTop,
    kLeftBottom,
    kRightBottom,
    kCenter,
  };

  enum class TelemetryModule {
    zoom_zcc,
    aic,
    calendar,
    chat,
    client,
    email,
    meetings,
    phone,
    zoom_docs,
    contacts,
    clips,
    zoom_apps,
    whiteboard,
  };

  inline WindowStyle operator|(WindowStyle lhs, WindowStyle rhs) {
    return static_cast<WindowStyle>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
  }

  inline WindowStyle operator&(WindowStyle lhs, WindowStyle rhs) {
    return static_cast<WindowStyle>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
  }

  inline WindowStyle operator^(WindowStyle lhs, WindowStyle rhs) {
    return static_cast<WindowStyle>(static_cast<uint32_t>(lhs) ^ static_cast<uint32_t>(rhs));
  }

  inline WindowStyle operator~(WindowStyle style) {
    return static_cast<WindowStyle>(~static_cast<uint32_t>(style));
  }

  inline WindowStyle& operator|=(WindowStyle& lhs, WindowStyle rhs) {
    return lhs = lhs | rhs;
  }

  inline WindowStyle& operator&=(WindowStyle& lhs, WindowStyle rhs) {
    return lhs = lhs & rhs;
  }

  inline WindowStyle& operator^=(WindowStyle& lhs, WindowStyle rhs) {
    return lhs = lhs ^ rhs;
  }

  inline bool HasStyle(WindowStyle styles, WindowStyle flag) {
    return (styles & flag) == flag;
  }

  enum class KeyboardConfig : CmmUInt32 {
    kDisableEscape = 0x00000001,
    kDisableAltF4 = 0x00000002,
    kDisableCommandW = 0x00000004
  };

  inline CmmUInt32 operator|(KeyboardConfig lhs, KeyboardConfig rhs) {
    return static_cast<CmmUInt32>(lhs) | static_cast<CmmUInt32>(rhs);
  }

  /**
   * @brief Cross-platform logical key for window-level key handlers (e.g. SetOnKeyDown).
   * Platform layers map native codes (VK_*, NSEvent.keyCode, Qt::Key_*) to this enum
   * before invoking cross-platform callbacks. Cross-platform code must not compare raw key codes.
   */
  enum class LogicalKey {
    Unknown = 0,
    Up,
    Down,
    Enter,
    Space,
    Escape,
    Tab,
  };
}

namespace Layout ///@todo change this to zui
{
	struct ZUI_API Position
	{
		float x;
		float y;

		Position(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Position()
		{
			this->x = 0;
			this->y = 0;
		}

		bool operator==(const Position& rhs) const;
		bool operator!=(const Position& rhs) const;
	};

	struct ZUI_API Size
	{
		float width;
		float height;

		Size(float _width, float _height)
		{
			width = _width;
			height = _height;
		};

		Size()
		{
			width = NAN;
			height = NAN;
		};

		bool operator==(const Size& rhs) const;
		bool operator!=(const Size& rhs) const;
	};

	enum class Alignment
	{
		Undefined,
		Center,
		Start,
		End
	};

	enum class JustifyContent
	{
		Start,
		End,
		SpaceBetween,
		Center,
		SpaceAround,
		SpaceEvenly
	};

	enum class Wrap
	{
		NoWrap,
		Wrap
	};

	struct Rect
	{
		Rect() = default;

		Rect(float value)
			: left(value)
			, top(value)
			, right(value)
			, bottom(value)
		{
		}

		Rect(float left, float top, float right, float bottom)
			: left(left)
			, top(top)
			, right(right)
			, bottom(bottom)
		{
		}

		float left = 0.f;
		float top = 0.f;
		float right = 0.f;
		float bottom = 0.f;
	};

	enum class Edge
	{
		Leading,
		Top,
		Trailing,
		Bottom
	};

	struct ZUI_API EdgeSet
	{
		std::bitset<4> edges;

		EdgeSet() = default;

		EdgeSet(std::initializer_list<Edge> edgesList)
		{
			for (auto edge : edgesList)
			{
				edges.set(static_cast<size_t>(edge));
			}
		}

		bool Contains(Edge edge) const
		{
			return edges.test(static_cast<size_t>(edge));
		}

		EdgeSet operator|(const EdgeSet& other) const
		{
			EdgeSet result;
			result.edges = this->edges | other.edges;
			return result;
		}

		static const EdgeSet All;
		static const EdgeSet Top;
		static const EdgeSet Bottom;
		static const EdgeSet Leading;
		static const EdgeSet Trailing;
		static const EdgeSet Horizontal;
		static const EdgeSet Vertical;
	};

  struct EdgeInsets
  {
    float leading = 0;
    float top = 0;
    float trailing = 0;
    float bottom = 0;

    EdgeInsets() = default;

    EdgeInsets(float _leading, float _top, float _trailing, float _bottom)
      : leading(_leading), top(_top), trailing(_trailing), bottom(_bottom)
    {
    }

    bool operator==(const EdgeInsets& rhs) const;
    bool operator!=(const EdgeInsets& rhs) const;
  };

}

#endif // TYPES_H
