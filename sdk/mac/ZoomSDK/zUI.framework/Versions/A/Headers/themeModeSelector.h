#pragma once

#include "zui_data_define.h"
#include <functional>
#include "view.h"

namespace zui
{
	class ZUI_API ThemeModeSelector
		: public View
	{
	public:

    enum class ThemeMode
    {
      kClassic,
      kBloom,
      kAgave,
      kRose
    };

    enum class ColorMode
    {
      kDarkMode,
      kLightMode
    };

		ThemeModeSelector();

		virtual ~ThemeModeSelector() = default;

		ThemeModeSelector& themeMode(const Bind<ThemeMode>& themeMode);

    ThemeModeSelector& colorMode(const Bind<ColorMode>& colorMode);
	};

namespace p
{

  class ZUI_API themeMode : public PipeModifier
  {
  public:
    explicit themeMode(const Bind<ThemeModeSelector::ThemeMode>& themeMode);
    ~themeMode();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API themeModeColorMode : public PipeModifier
  {
  public:
    explicit themeModeColorMode(const Bind<ThemeModeSelector::ColorMode>& colorMode);
    ~themeModeColorMode();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace theme_mode_selector {
        using zui::p::themeMode;
        using zui::p::themeModeColorMode;
      }
    }
  }

}

}
