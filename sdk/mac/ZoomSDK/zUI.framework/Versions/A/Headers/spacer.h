/**
 * @file spacer.h
 * @brief Spacer layout component
 * @ingroup zui_layout
 * 
 * Provides spacing functionality for layout management.
 */

#pragma once

#include "view.h" 


namespace zui
{
	/**
	 * @class Spacer
	 * @brief A view representing a Spacer.
	 * @ingroup controls_layout
	 *
	 * Spacers are used to add space between views.
	 *
	 */
	class ZUI_API Spacer : public View
	{
	public:
		/// @brief Construct a new Spacer object
		Spacer();

		/// @brief Virtual destructor of the Spacer class.
		virtual ~Spacer() = default;
	};
}
