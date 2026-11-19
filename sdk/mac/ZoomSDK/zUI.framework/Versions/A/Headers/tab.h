/**
 * @file tab.h
 * @brief Tab and TabView components for tabbed interfaces
 * @ingroup zui_container_views
 * 
 * Provides tab navigation functionality with tabbed content organization.
 */

#pragma once

#include <type_traits>

#include "view.h"
#include "environment.h"
#include "badge.h"

namespace zui
{

	/**
	 * @class Tab
	 * @brief A single tab component for use within a TabView container.
	 * @ingroup controls_grouping
	 * 
	 * The Tab component represents an individual tab in a tab navigation interface.
	 * Each tab can contain:
	 * - Text label
	 * - Leading or trailing icons
	 * - Notification indicators
	 * - Badge displays
	 * - Child view content
	 * - Visibility control
	 * 
	 * @example
	 * @code
	 * // Basic tab with label
	 * Tab(
	 *   Text("Dashboard").body(),
	 *   // Dashboard content views...
	 * )
	 * .label("Dashboard")
	 * .icon("dashboard-icon.svg", Tab::IconPosition::kLeading);
	 * 
	 * // Tab with badge and notification
	 * Tab(
	 *   // Messages content...
	 * )
	 * .label("Messages")
	 * .showNotifier(true)
	 * .showBadge(true, Badge().text("5").style(Badge::Style::kBadgeRed));
	 * @endcode
	 */
	class ZUI_API Tab : public View
	{
	public:
		/**
		 * @enum IconPosition
		 * @brief Defines the position of the icon relative to the tab label
		 */
		enum class IconPosition
		{
			kLeading,   ///< Icon appears before (left of) the label
			kTrailing,  ///< Icon appears after (right of) the label
		};

		/**
		 * @brief Constructs a Tab with multiple child views
		 * @tparam Views Template parameter pack for View objects
		 * @param views Variable number of View objects to include in the tab content
		 */
		template<typename... Views>
		Tab(Views&&... views)
			: View(View::Type::Tab, [this]() {
        return (this)->BuildTab();
      })
		{
			int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
			static_cast<void>(dummy); // Prevent unused variable warning
		}
    
    std::shared_ptr<ViewNode> BuildTab();

		/**
		 * @brief Sets the text label for the tab
		 * @param label The text to display on the tab
		 * @return Reference to this tab for method chaining
		 */
		Tab& label(const Bind<std::string>& label);

		/**
		 * @brief Sets an icon for the tab with specified position
		 * @param icon The path to the icon image
		 * @param iconPosition The position of the icon relative to the label
		 * @return Reference to this tab for method chaining
		 */
		Tab& icon(const Bind<std::string>& icon, IconPosition iconPosition);

		/**
		 * @brief Sets whether to show a notification indicator on the tab
		 * @param shouldShowNotifier True to show notifier, false to hide
		 * @return Reference to this tab for method chaining
		 */
		Tab& showNotifier(const Bind<bool> shouldShowNotifier);

		/**
		 * @brief Sets whether to show a badge on the tab
		 * @param shouldShowBadge True to show badge, false to hide
		 * @param badge The Badge component to display
		 * @return Reference to this tab for method chaining
		 */
		Tab& showBadge(const Bind<bool> shouldShowBadge, Badge& badge);
    
    /**
     * @brief Sets the visibility of the tab
     * @param visible True to make the tab visible, false to hide it
     * @return Reference to this tab for method chaining
     */
    Tab& visible(const Bind<bool> visible);


	private:
		/// @brief Internal method to add child view nodes
		void AddChildView(std::shared_ptr<ViewNode> viewNode);
	};

	/**
	 * @class TabView
	 * @brief A container component that manages multiple Tab components.
	 * @ingroup controls_grouping
	 * 
	 * The TabView component provides a tabbed interface for organizing content
	 * into multiple sections. It supports:
	 * - Multiple visual styles (primary, secondary)
	 * - Different sizes (primary large, medium)
	 * - Tab selection management
	 * - Only accepts Tab components as children
	 * 
	 * @example
	 * @code
	 * // Basic tab view with multiple tabs
	 * TabView(
	 *   Tab(
	 *     Text("Home Content")
	 *   ).label("Home"),
	 *   
	 *   Tab(
	 *     Text("Profile Content")
	 *   ).label("Profile")
	 *   .icon("user-icon.svg", Tab::IconPosition::kLeading),
	 *   
	 *   Tab(
	 *     Text("Settings Content")
	 *   ).label("Settings")
	 * )
	 * .style(TabView::Style::kPrimary)
	 * .size(TabView::Size::kMedium)
	 * .selection(0); // Select first tab
	 * @endcode
	 */
	class ZUI_API TabView : public View
	{
	public:
		/**
		 * @enum Style
		 * @brief Defines the visual style of the tab view
		 */
		enum class Style
		{
			kPrimary,   ///< Primary tab style with prominent appearance
			kSecondary, ///< Secondary tab style with subtle appearance
		};

		/**
		 * @enum Size
		 * @brief Defines the size of the tab view
		 */
		enum class Size
		{
			kPrimaryLarge, ///< Large size for primary tabs
			kMedium,       ///< Medium size for standard layouts
		};

		/// @brief Template helper to check if all arguments are Tab objects
		template<typename...>
		struct are_all_tabs : std::true_type { };

		/**
		 * @brief Template specialization to validate Tab types
		 * @tparam T First type to check
		 * @tparam Rest Remaining types to check
		 */
		template<typename T, typename... Rest>
		struct are_all_tabs<T, Rest...>
			: std::integral_constant<
			bool,
			std::is_same<typename std::decay<T>::type, Tab>::value&&
			are_all_tabs<Rest...>::value
			>
		{
		};

		/**
		 * @brief Constructs a TabView with multiple Tab components
		 * @tparam Tabs Template parameter pack for Tab objects
		 * @param tabs Variable number of Tab objects to include in the view
		 * @note All parameters must be of type Tab
		 */
		template<typename... Tabs>
		TabView(Tabs&&... tabs)
			: View(View::Type::TabView, [this]() {
        return (this)->BuildTabView();
      })
		{
			static_assert(are_all_tabs<Tabs...>::value, "All parameters must be of type Tab"); /// @todo allow conditional & loop
			int dummy[] = { 0, (AddChildView(tabs.GetViewNode()), 0)... };
			static_cast<void>(dummy); // Prevent unused variable warning
		}
    
    std::shared_ptr<ViewNode> BuildTabView();

		/**
		 * @brief Sets the currently selected tab by index
		 * @param index The zero-based index of the tab to select
		 * @return Reference to this tab view for method chaining
		 */
		TabView& selection(Bind<int> index);

		/**
		 * @brief Sets the visual style of the tab view
		 * @param style The style to apply
		 * @return Reference to this tab view for method chaining
		 */
		TabView& style(Style style);

		/**
		 * @brief Sets the size of the tab view
		 * @param size The size to apply
		 * @return Reference to this tab view for method chaining
		 */
		TabView& size(Size size);

	private:
		/// @brief Internal method to add child view nodes
		void AddChildView(std::shared_ptr<ViewNode> viewNode);
	};

namespace p
{

  // Tab-specific pipe modifiers
  class ZUI_API tabIcon : public PipeModifier
  {
  public:
    explicit tabIcon(const Bind<std::string>& icon, Tab::IconPosition iconPosition);
    ~tabIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tabShowNotifier : public PipeModifier
  {
  public:
    explicit tabShowNotifier(const Bind<bool> shouldShowNotifier);
    ~tabShowNotifier();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tabShowBadge : public PipeModifier
  {
  public:
    explicit tabShowBadge(const Bind<bool> shouldShowBadge, const Badge& badge);
    ~tabShowBadge();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  // TabView-specific pipe modifiers
  class ZUI_API tabSelection : public PipeModifier
  {
  public:
    explicit tabSelection(Bind<int> index);
    ~tabSelection();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tabViewStyle : public PipeModifier
  {
  public:
    explicit tabViewStyle(TabView::Style style);
    ~tabViewStyle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tabViewSize : public PipeModifier
  {
  public:
    explicit tabViewSize(TabView::Size size);
    ~tabViewSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API tabLabel : public PipeModifier
  {
  public:
    explicit tabLabel(const Bind<std::string>& label);
    ~tabLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace tab {
        using zui::p::tabIcon;
        using zui::p::tabShowNotifier;
        using zui::p::tabShowBadge;
        using zui::p::tabSelection;
        using zui::p::tabViewStyle;
        using zui::p::tabViewSize;
        using zui::p::tabLabel;
      }
    }
  }

}

}

