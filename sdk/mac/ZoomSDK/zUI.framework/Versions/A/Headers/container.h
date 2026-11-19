/**
 * @file container.h
 * @brief Base container component
 * 
 * Provides base container functionality for layout components.
 */

#pragma once

#include <memory>
#include "helper.h"
#include "view.h"

namespace zui
{
	// forward declaration
	class ContainerNode;

	/**
	 * @brief Shadow style preset types
	 * 
	 * Defines predefined shadow configurations matching Prism design tokens.
	 * These presets provide consistent elevation levels across all platforms.
	 * 
	 * Platform mappings:
	 * - kSmall:  Linux(xsm_screen_min) y=2, blur=4  | Windows blur=4  | macOS radius=4
	 * - kMedium: Linux(xsm_screen_md)  y=6, blur=12 | Windows blur=12 | macOS radius=12
	 * - kLarge:  Linux(xsm_screen_max) y=12, blur=24 | Windows blur=24 | macOS radius=24
	 */
	enum class ShadowStyle : uint32_t {
		kNone,   ///< No shadow (default)
		kSmall,  ///< Small shadow: y=4, blur=8 (+ layer2: y=2, blur=4) | color=#000000 8%
		kMedium, ///< Medium shadow: y=12, blur=24 (+ layer2: y=6, blur=12) | color=#000000 8%
		kLarge   ///< Large shadow: y=24, blur=48 (+ layer2: y=12, blur=24) | color=#000000 8%
	};

	/**
	 * @class Container
	 * @brief Base class for container components.
		 */
	class ZUI_API Container : public View
	{
	public:
		template<typename... Views>
		Container(View::Type viewType, std::function<std::shared_ptr<ViewNode>()> builder, Views&&... views)
			: View(viewType, builder)
		{
			int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
			static_cast<void>(dummy); // Prevent unused variable warning
		}

		~Container() = default;

		Container& spacing(float spacing);
		Container& alignItems(Layout::Alignment alignment);

		/**
		 * @brief Sets the shadow style with data binding support
		 * 
		 * Applies predefined shadow effects that provide consistent elevation
		 * levels across all platforms. Shadow presets align with Prism design tokens.
		 * 
		 * Shadow Style Guide:
		 * - kSmall:  Subtle elevation for cards, buttons, and small containers
		 * - kMedium: Standard elevation for dropdowns, popovers, and floating panels
		 * - kLarge:  High elevation for modals, dialogs, and important overlays
		 * - kNone:   Removes any shadow effect (default state)
		 * 
		 * @param style Bindable shadow style value
		 * @return Reference to this container for method chaining
		 * 
		 * @code
		 * // Card with medium shadow
		 * VerticalStack()
		 *   .background("fill/fill-default")
		 *   .cornerRadius(8)
		 *   .shadow(ShadowStyle::kMedium)
		 *   .padding(16)
		 *   .child(Text("Elevated Card"));
		 * 
		 * // Dialog with large shadow
		 * Container()
		 *   .background(bgDefault)
		 *   .cornerRadius(12)
		 *   .shadow(ShadowStyle::kLarge);
		 * 
		 * // Data binding for dynamic shadow
		 * auto shadowLevel = MakeObservable(ShadowStyle::kSmall);
		 * VerticalStack()
		 *   .shadow(shadowLevel);
		 * @endcode
		 */
		Container& shadow(const Bind<ShadowStyle>& style);

	private:
		void AddChildView(std::shared_ptr<ViewNode> viewNode);
	};

namespace p
{

  class ZUI_API spacing : public PipeModifier
  {
  public:
    explicit spacing(float spacing);
    ~spacing();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API containerAlignItems : public PipeModifier
  {
  public:
    explicit containerAlignItems(Layout::Alignment alignment);
    ~containerAlignItems();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace container {
        using zui::p::spacing;
        using zui::p::containerAlignItems;
      }
    }
  }

} // namespace p

}

