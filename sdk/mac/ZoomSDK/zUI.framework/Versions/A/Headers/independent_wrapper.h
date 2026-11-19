/*****************************************************************************
*
* Copyright (C) 2024, Zoom Video Communications, Inc
*
*****************************************************************************/

/**
 * @file independent_wrapper.h
 * @brief Independent wrapper component for interoperability
 * @ingroup zui_interop
 * 
 * Provides wrapper functionality for independent view integration.
 */

#ifndef ZUI_INDEPENDENT_WRAPPER
#define ZUI_INDEPENDENT_WRAPPER

#include <memory>
#include <functional>
#ifdef _WIN32
#include "zUI/helper.h"
#include "zUI/view.h"
#include "zUI/interoperability/independent_view.h"
#include "zUI/interoperability/independent_callbacks.h"
#elif defined __MACOS__
#import <zUI/helper.h>
#import <zUI/view.h>
#import <zUI/independent_view.h>
#import <zUI/independent_callbacks.h>
#else
#include "helper.h"
#include "view.h"
#include "independent_view.h"
#include "independent_callbacks.h"
#endif

namespace zui {

  /**
   * @class IndependentWrapper
   * @brief A wrapper class for independent view integration.
   * @ingroup integration
   */
  class ZUI_API IndependentWrapper
  {
  public:
    template<typename T>
    IndependentWrapper(T&& view, float width, float height)
    {
        InitUnderlyingView(view.GetViewNode());
        SetViewSize(width, height);
    }
      
    template<typename T>
    IndependentWrapper(T&& view)
    {
        InitUnderlyingView(view.GetViewNode());
    }
      
    IndependentWrapper()
    {
    }

    ~IndependentWrapper();

    std::shared_ptr<Independent> GetUnderlyingView(){ return _independentView; }
    std::shared_ptr<View> GetCustomView();
    void RegisterOnSizeCallback(OnSizeUpdateFunc pFunc);
    void RegisterOnSizeCallback(OnSizeUpdateFuncSimple pFunc);
    void RegisterOnSizeCallback(OnSizeUpdateFuncWithContext pFunc);

  private:
    void InitUnderlyingView(std::shared_ptr<ViewNode> view);
    void SetViewSize(float width, float height);
    std::shared_ptr<Independent> _independentView = nullptr;
    std::weak_ptr<ViewNode> _customViewNode;
  };
}

#endif //ZUI_INDEPENDENT_WRAPPER
