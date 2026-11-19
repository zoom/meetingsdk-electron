/**
 * @file horizontal_stack.h
 * @brief Horizontal stack layout component
 * 
 * Arranges child views horizontally in a stack layout.
 */

#pragma once

#include "container.h"
#include "zui_data_define.h"

// forward declaration
namespace zui
{
	/**
	* @class HorizontalStack
	* @ingroup controls_layout
	* @brief A container that lays out its children in a horizontal line.
	*/
	class ZUI_API HorizontalStack : public Container
	{
	public:
		template <typename... Views>
		HorizontalStack(Views &&...views)
			: Container(View::Type::HorizontalStack, [this]() {
        return (this)->BuildStack();
    }, std::forward<Views>(views)...)
		{
		}
	public:
		/// @brief Virtual destructor of the HorizontalStack class.
		virtual ~HorizontalStack() = default;

		std::shared_ptr<ViewNode> BuildStack();

	};
}
