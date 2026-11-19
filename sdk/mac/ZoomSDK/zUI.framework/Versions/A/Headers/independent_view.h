/*****************************************************************************
*
* Copyright (C) 2024, Zoom Video Communications, Inc
*
*****************************************************************************/

/**
 * @file independent_view.h
 * @brief Independent view component for interoperability
 * @ingroup zui_interop
 * 
 * Provides independent view functionality for cross-platform integration.
 */

#pragma once

#ifndef ZUI_INTEROPERABILITY_INDEPENDENT_VIEW_H
#define ZUI_INTEROPERABILITY_INDEPENDENT_VIEW_H

#include <memory>
#ifdef _WIN32
#include "zUI/helper.h"
#include "zUI/view.h"
#else
#include "helper.h"
#include "view.h"
#endif

namespace zui {

  /**
   * @class Independent
   * @brief A view component for independent interoperability contexts.
   * @ingroup integration
   */
  class ZUI_API Independent : public View
  {
  public:
    template<typename T>
    Independent(T&& view)
      : View(View::Type::Independent, [this]() {
        return (this)->BuildIndependent();
    })
    {
      AddChildView(view.GetViewNode());
    }

    Independent()
      : View(View::Type::Independent, [this]() {
        return (this)->BuildIndependent();
    })
    {
    }

    virtual ~Independent();

    std::shared_ptr<View> Clone() const override
    {
      return std::make_shared<Independent>(*this);
    }

    virtual std::shared_ptr<ViewNode> BuildIndependent();

  private:
    friend class IndependentWrapper;
    void RemoveAllDescendants();
    void AddChildView(std::shared_ptr<ViewNode> viewNode);
  };
}

#endif /* ZUI_INTEROPERABILITY_INDEPENDENT_VIEW_H */
