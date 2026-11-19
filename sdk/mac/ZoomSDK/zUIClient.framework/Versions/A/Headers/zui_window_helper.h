#pragma once
#include "zUI/zui_base.h"
#include "zUI/window.h"

namespace zui
{
  static std::shared_ptr<ZUIWindow> CreateZUIWindow(const ZUIWindow::WindowData& windowData)
  {
    return ZUIWindow::Create(windowData);
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(zui::WindowStyle style)
  {
    ZUIWindow::WindowData data;
    data.style= style;
    return ZUIWindow::Create(data);
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(const View& view, const ZUIWindow::WindowData& windowData)
  {
    auto window = ZUIWindow::Create(windowData);
    if (window)
      window->AttachView(view);
    return window;
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(const View& view, zui::WindowStyle style)
  {
    ZUIWindow::WindowData data;
    data.style= style;
    return CreateZUIWindow(view, data);
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(const View& view, zui::WindowStyle style, void* parent)
  {
    ZUIWindow::WindowData data;
    data.style= style;
    data.parent = parent;
    return CreateZUIWindow(view, data);
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(std::shared_ptr<View> view, zui::WindowStyle style, void* parent)
  {
    ZUIWindow::WindowData data;
    data.style= style;
    data.parent = parent;

    auto window = ZUIWindow::Create(data);
    if (window)
      window->AttachView(view);
    return window;
  }

  static std::shared_ptr<ZUIWindow> CreateZUIWindow(std::shared_ptr<View> view, const ZUIWindow::WindowData& windowData)
  {
    auto window = ZUIWindow::Create(windowData);
    if (window)
      window->AttachView(view);
    return window;
  }

}
