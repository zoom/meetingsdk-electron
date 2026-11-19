/**
 * @file scrollview.h
 * @brief Scroll view container component
 */

#pragma once

#include <functional>
#include "view.h"
#include "vertical_stack.h"
#include "horizontal_stack.h"

namespace zui
{

  /**
   * @brief Scroll state snapshot delivered by onScrollGeometryChange.
   *
   * All values are in logical pixels.
   *
   * Typical usage:
   *   bool atBottom = g.contentOffsetY + g.containerHeight >= g.contentHeight;
   *   bool atTop    = g.contentOffsetY <= 0.f;
   */
  struct ScrollGeometry
  {
    float contentOffsetX = 0.f; ///< Horizontal scroll position (distance from left edge)
    float contentOffsetY = 0.f; ///< Vertical scroll position (distance from top edge)
    float contentWidth   = 0.f; ///< Total content width
    float contentHeight  = 0.f; ///< Total content height
    float containerWidth  = 0.f; ///< Visible viewport width
    float containerHeight = 0.f; ///< Visible viewport height
  };

	/**
	 * @class ScrollView
	 * @ingroup controls_grouping
	 * @brief Scrollable container for content that exceeds the visible area.
	 */
	class ZUI_API ScrollView : public View
	{
	public:
		template <typename ViewT,
			typename = typename std::enable_if<
			std::is_convertible<typename std::decay<ViewT>::type, VerticalStack>::value ||
			std::is_convertible<typename std::decay<ViewT>::type, HorizontalStack>::value>::type>

		ScrollView(ViewT&& view)
			: View(View::Type::ScrollView, [this]() {
        return (this)->BuildScrollView();
      })
		{
			AddChildView(std::forward<ViewT>(view).GetViewNode());
      EnsureContentRoot();
		}

		virtual ~ScrollView() = default;

		ScrollView& horizontal(bool enabled);
		ScrollView& vertical(bool enabled);

		/// Called on the UI thread each time the scroll position or content size changes.
		ScrollView& onScrollGeometryChange(std::function<void(const ScrollGeometry&)> callback);

		std::shared_ptr<ViewNode> BuildScrollView();
    void EnsureContentRoot();

	private:
		void AddChildView(std::shared_ptr<ViewNode> viewNode);
	};

namespace p
{

  class ZUI_API scrollViewHorizontal : public PipeModifier
  {
  public:
    explicit scrollViewHorizontal(bool enabled);
    ~scrollViewHorizontal();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API scrollViewVertical : public PipeModifier
  {
  public:
    explicit scrollViewVertical(bool enabled);
    ~scrollViewVertical();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API scrollViewOnScrollGeometryChange : public PipeModifier
  {
  public:
    explicit scrollViewOnScrollGeometryChange(std::function<void(const ScrollGeometry&)> callback);
    ~scrollViewOnScrollGeometryChange();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace scrollview {
        using zui::p::scrollViewHorizontal;
        using zui::p::scrollViewVertical;
        using zui::p::scrollViewOnScrollGeometryChange;
      }
    }
  }

}

}
