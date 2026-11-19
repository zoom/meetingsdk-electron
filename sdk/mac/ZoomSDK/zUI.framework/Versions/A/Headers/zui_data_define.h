#ifndef ZUI_DATA_DEFINE_H
#define ZUI_DATA_DEFINE_H

#include <string>
#include <vector>
#include <variant>
#include <functional>

#include "zui_accessibility_types.h"
#include "zui_api.h"
#include "zui_colors.h"

namespace zui
{
	// Backwards-compatibility shim:
	// Prefer including focused headers directly:
	// - zui_api.h
	// - zui_popup_common.h
	// - zui_colors.h
	// - zui_accessibility_types.h

	using EnvironmentValue = std::variant<int, float, std::string, std::function<void(const std::string&)>>;
	using Variant [[deprecated("Use EnvironmentValue instead")]] = EnvironmentValue;

	struct ZUIControlNode {
		std::string text;
		std::string exText;
		std::string id;
		bool isVisible;
		std::vector<ZUIControlNode> child;
	};

	class BannerCallbackIt
	{
	public:
		virtual void OnBannerClose() = 0;
	};
}

#endif
