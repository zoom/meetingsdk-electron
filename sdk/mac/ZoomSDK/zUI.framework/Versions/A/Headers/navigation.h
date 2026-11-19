/**
 * @file navigation.h
 * @brief Navigation component
 * @ingroup zui_navigation_views
 * 
 * Provides navigation functionality for menu and routing systems.
 */

#ifndef _ZUI_NAVIGATION_H_
#define _ZUI_NAVIGATION_H_

#include "vertical_stack.h"
#include "horizontal_stack.h"

namespace zui
{

	/**
	 * @class Navigation
	 * @brief A navigation component for menu and routing systems.
	 * @ingroup zui_navigation_views
	 * @note Currently unused in the framework
	 */
	class ZUI_API Navigation : public View  //unused
	{
	public:


		template <typename... Views>
		Navigation(Views &&...views)
    :View(View::Type::Undefined, [this]() {
      return (this)->BuildNavigation();
  });
		virtual ~Navigation() = default;

    std::shared_ptr<ViewNode> BuildNavigation(){};
	};
}

#endif // NAVIGATION_H
