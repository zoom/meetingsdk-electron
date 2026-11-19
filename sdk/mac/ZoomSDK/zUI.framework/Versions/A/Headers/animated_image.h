#pragma once

#include <memory>
#include "view.h"
#include "image.h"
#include "zui_data_define.h"

namespace zui
{
  class ZUI_API AnimatedImage : public View
  {
  public:
    explicit AnimatedImage(const Bind<std::string>& path);
    virtual ~AnimatedImage() = default;

    // true = loop indefinitely (default); false = play once.
    AnimatedImage& loop(const Bind<bool>& loop);

    // true = start playing on appear (default); false = stay paused.
    AnimatedImage& play(const Bind<bool>& play);

    AnimatedImage& contentMode(Image::ContentMode contentMode);
  };

} // namespace zui
