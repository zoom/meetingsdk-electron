/**
 * @file badge.h
 * @brief Badge component for informational tags
 * 
 * Provides badge functionality for status indicators and labels.
 */

#pragma once

#include <memory>
#include "zui_data_define.h"
#include "view.h"

namespace zui
{
	/**
	 * @class Badge
	 * @brief A view component that displays a small informational tag or label.
	 * @ingroup controls_feedback
	 * 
	 * The Badge component is used to highlight information or status related to an item.
	 * It's commonly used for:
	 * - Status indicators
	 * - Counters
	 * - Categorization
	 * - Emphasis of important information (e.g., "New", "Beta")
	 * 
	 * @example
	 * @code
	 * // Basic badge with text
	 * Badge()
	 *   .text("New")
	 *   .styleNew();
	 * 
	 * // Custom badge
	 * Badge()
	 *   .text("42")
	 *   .style(Badge::Style::kBadgeBlue);
	 * @endcode
	 */
	class ZUI_API Badge : public View
	{
	public:
		/**
		 * @enum Style
		 * @brief Defines the visual style of the badge
		 */
		enum class Style
		{
			kBadgeGray,    ///< Gray badge style
			kBadgeRed,     ///< Red badge style
			kBadgeOrange,  ///< Orange badge style
			kBadgeYellow,  ///< Yellow badge style
			kBadgeGreen,   ///< Green badge style
			kBadgeTeal,    ///< Teal badge style
			kBadgeBlue,    ///< Blue badge style
			kBadgePurple,  ///< Purple badge style
			kBadgeInverse, ///< Inverse badge style (typically dark background with light text)
			kBadgeNew,     ///< Special "New" badge style
			kBadgeBeta,    ///< Special "Beta" badge style
		};

	public:
		/// @brief Constructs a new Badge object
		Badge();

		/// @brief Virtual destructor
		virtual ~Badge() = default;

		/**
		 * @brief Sets the label displayed in the badge
		 * @param label The label to display
		 * @return Reference to this badge for method chaining
		 */
		Badge& label(const Bind<std::string>& label);

		/**
		 * @brief Sets the style of the badge
		 * @param style The style to apply
		 * @return Reference to this badge for method chaining
		 */
		Badge& style(const Bind<Style>& style);
	};

namespace p
{

  class ZUI_API badgeStyle : public PipeModifier
  {
  public:
    explicit badgeStyle(const Bind<Badge::Style>& style);
    ~badgeStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API badgeLabel : public PipeModifier
  {
  public:
    explicit badgeLabel(const Bind<std::string>& label);
    ~badgeLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace badge {
        using zui::p::badgeStyle;
        using zui::p::badgeLabel;
      }
    }
  }

} // namespace p

}
