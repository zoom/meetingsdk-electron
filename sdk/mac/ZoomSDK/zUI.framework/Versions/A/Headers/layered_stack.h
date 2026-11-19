/**
 * @file layered_stack.h
 * @brief Layered stack container component
 * 
 * Arranges child views in z-axis (overlay) layout, stacking views on top of each other.
 * Similar to SwiftUI's ZStack, later children appear above earlier ones.
 */

#ifndef _ZUI_LAYERED_STACK_H_
#define _ZUI_LAYERED_STACK_H_

#include "container.h"

namespace zui
{
	/**
	 * @class LayeredStack
	 * @ingroup controls_layout
	 * @brief A container that overlays its children on top of each other.
	 * 
	 * LayeredStack arranges child views along the z-axis, with each child
	 * placed on top of the previous one. By default, children are
	 * centered within the LayeredStack.
	 * 
	 * @section usage Usage Example
	 * @code
	 * LayeredStack(
	 *   Image("background.png"),
	 *   Text("Hello World").color("#FFFFFF")
	 * ).alignment(Layout::Alignment::kCenter)
	 * @endcode
	 */
	class ZUI_API LayeredStack : public Container
	{
	public:
		/**
		 * @brief Constructs a LayeredStack with the given child views.
		 * @tparam Views Variadic template for child views.
		 * @param views Child views to be stacked.
		 */
		template <typename... Views>
		LayeredStack(Views &&...views)
			: Container(View::Type::LayeredStack, [this]() {
        return (this)->BuildStack();
    }, std::forward<Views>(views)...)
		{
		}

		virtual ~LayeredStack() = default;

		/**
		 * @brief Builds the LayeredStack node.
		 * @return Shared pointer to the ViewNode.
		 */
		std::shared_ptr<ViewNode> BuildStack();
	};
}

#endif // _ZUI_LAYERED_STACK_H_

