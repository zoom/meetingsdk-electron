/**
 * @file divider.h
 * @brief Divider layout component
 * @ingroup zui_layout
 * 
 * Provides divider functionality for separating content sections.
 */

#pragma once
#include "zui_data_define.h"
#include "view.h"

namespace zui
{
	/**
	 * @class Divider
	 * @brief A view representing a divider.
	 * @ingroup controls_layout
	 *
	 * Separate pieces of content into clear groups, sections.
	 *
	 */
	class ZUI_API Divider : public View
	{
	public:
		/**
		 * @brief Construct a new Divider object
		 */
		Divider();

		/// @brief Virtual destructor of the Divider class.
		virtual ~Divider() = default;

	};
}
