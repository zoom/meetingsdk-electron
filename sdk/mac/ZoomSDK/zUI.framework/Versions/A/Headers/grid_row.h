/**
 * @file gridrow.h
 * @brief Grid Row layout component
 *
 * Arranges child views into a grid row component
 */

#pragma once

#include "container.h"
#include "zui_data_define.h"

// forward declaration
namespace zui
{
  /**
  * @class GridRow
  * @ingroup controls_layout
  * @brief A container that lays out its children into a grid row component.
  */
  class ZUI_API GridRow : public Container
  {
  public:
    template <typename... Views>
    GridRow(Views &&...views)
      : Container(View::Type::GridRow, [this]() {
        return (this)->BuildGridRow();
    }, std::forward<Views>(views)...)
    {
    }
  public:
    /// @brief Virtual destructor of the GridRow class.
    virtual ~GridRow() = default;

  private:
    std::shared_ptr<ViewNode> BuildGridRow();
  };
}
