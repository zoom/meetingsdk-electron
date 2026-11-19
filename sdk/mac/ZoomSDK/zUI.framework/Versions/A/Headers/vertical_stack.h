/**
 * @file vertical_stack.h
 * @brief Vertical stack container component
 * 
 * Arranges child views vertically in a stack layout.
 */

#ifndef _ZUI_VERTICAL_STACK_H_
#define _ZUI_VERTICAL_STACK_H_

#include "container.h"

namespace zui
{
	/**
	 * @class VerticalStack
	 * @ingroup controls_layout
	 * @brief A container that lays out its children vertically.
		 */
	class ZUI_API VerticalStack : public Container
	{
	public:
		template <typename... Views>
		VerticalStack(Views &&...views)
			: Container(View::Type::VerticalStack, [this]() {
        return (this)->BuildStack();
    }, std::forward<Views>(views)...)
		{
		}

		virtual ~VerticalStack() = default;

		std::shared_ptr<ViewNode> BuildStack();
	};
}

#endif // VERTICAL_STACK_H

