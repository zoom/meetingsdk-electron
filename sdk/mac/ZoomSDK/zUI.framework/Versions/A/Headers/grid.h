/**
 * @file grid.h
 * @brief Grid layout component
 *
 * Arranges child views in a grid layout
 */

#pragma once

#include "container.h"
#include "helper.h"
#include "grid_row.h"
#include "divider.h"
#include "zui_data_define.h"

namespace zui
{
  namespace detail {
    template<typename T>
    struct is_grid_child : std::integral_constant<bool,
        std::is_convertible<typename std::decay<T>::type, GridRow>::value ||
        std::is_convertible<typename std::decay<T>::type, Divider>::value>
    {};
  }

  /**
  * @class Grid
  * @ingroup controls_layout
  * @brief A container that lays out its children in a grid pattern. Accepts GridRow and Divider objects.
  */
  class ZUI_API Grid : public Container
  {
  public:
    //Grid accepts GridRow and Divider objects in its parameter pack
    template <typename... Views,
        typename = typename std::enable_if<
            all_true<
                detail::is_grid_child<Views>::value...
            >::value
        >::type>
    Grid(Views&&... views)
        : Container(View::Type::Grid, [this]() {
            return (this)->BuildGrid();
          }, std::forward<Views>(views)...)
    {
    }
    
  public:
    virtual ~Grid() = default;

    Grid& horizontalSpacing(float spacing);
    Grid& verticalSpacing(float spacing);

  private:
    std::shared_ptr<ViewNode> BuildGrid();

	};

  namespace p
  {
    class ZUI_API gridHorizontalSpacing : public PipeModifier
    {
    public:
      explicit gridHorizontalSpacing(float spacing);
      ~gridHorizontalSpacing();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API gridVerticalSpacing : public PipeModifier
    {
    public:
      explicit gridVerticalSpacing(float spacing);
      ~gridVerticalSpacing();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };
  
    namespace discover {
      namespace by_view {
        namespace grid {
          using zui::p::gridHorizontalSpacing;
          using zui::p::gridVerticalSpacing;
        }
      }
    }
  }
}
