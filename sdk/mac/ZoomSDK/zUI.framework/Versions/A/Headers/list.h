/**
 * @file list.h
 * @brief Virtualized list container component
 * @ingroup zui_container_views
 *
 * Provides efficient list container functionality for displaying both static
 * and dynamic collections using virtualization and cell recycling.
 */

#pragma once

#include "zui_data_define.h"
#include "view.h"
#include "model/model.h"
#include <vector>
#include <functional>

namespace zui
{
/**
 * @class List
 * @brief A virtualized container for efficiently displaying collections of items.
 * @ingroup zui_container_views
 *
 * The List component supports two modes:
 * 1. Static lists - Direct view children
 * 2. Dynamic lists - Data-driven with cell factories
 *
 * For large datasets, it provides high-performance scrolling by only
 * rendering visible items plus a small buffer, automatically recycling
 * cells as the user scrolls.
 */
class ZUI_API List : public View
{
public:
  /**
   * @brief Static list constructor - accepts any number of views
   * @param views The view components to display as list items
   *
   * Creates a static list with the provided views as cells.
   *
   * Example:
   * @code
   * List(
   *     Text("First Item"),
   *     Text("Second Item"),
   *     Text("Third Item")
   * )
   * @endcode
   */
  template<typename... Views,
           typename = typename std::enable_if<std::conjunction<std::is_base_of<View, std::decay_t<Views>>...>::value>::type>
  List(Views&&... views)
    : View(View::Type::List, [this]() { return BuildList(); })
  {
    int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
    static_cast<void>(dummy); // Prevent unused variable warning
  }

  /**
   * @brief Dynamic list constructor - data-driven list
   * @param data The reactive data source for the list items
   *
   * Creates a dynamic list bound to a data source. Must be followed
   * by .cell() to specify how to render each item.
   *
   * Example:
   * @code
   * List(myDataSource)
   *     .cell([](auto& item, size_t index) {
   *         return Text(item.name);
   *     })
   * @endcode
   */
  List(const Bind<std::vector<zui::any>>& data);

  virtual ~List() = default;

  /**
   * @brief Sets the cell factory function for dynamic lists
   * @param cellFactory Function that creates a view for each data item
   * @return Reference to this List for method chaining
   *
   * The cell factory is called to create views for visible items.
   * The framework automatically recycles cells for performance.
   *
   * @param cellData The data item to render (as zui::any)
   * @param index The index of the item in the data source
   * @return A view representing the cell
   */
  List& cell(const std::function<std::shared_ptr<View>(zui::any& cellData, size_t index)>& cellFactory);

  /**
   * @brief Sets a fixed cell height for performance optimization
   * @param height The height of each cell in points
   * @return Reference to this List for method chaining
   *
   * When all cells have the same height, setting this value enables
   * significant performance optimizations by bypassing layout measurement.
   */
  List& cellHeight(float height);

  /**
   * @brief Compatibility placeholder for list-level cell padding
   * @param cellPadding The padding insets for each cell
   * @return Reference to this List for method chaining
   *
   * This API is kept for source compatibility with older callers, but it is
   * not currently wired into list layout/rendering on any platform.
   */
  List& cellPadding(const Layout::EdgeInsets& cellPadding);

  std::shared_ptr<ViewNode> BuildList();

private:
  void AddChildView(std::shared_ptr<ViewNode> viewNode);

  // Data for dynamic lists
  Bind<std::vector<zui::any>> _data;
  std::function<std::shared_ptr<View>(zui::any& cellData, size_t index)> _cellFactory;
};

namespace p
{

  // List-specific pipe modifiers
  class ZUI_API listCell : public PipeModifier
  {
  public:
    explicit listCell(const std::function<std::shared_ptr<View>(zui::any& cellData, size_t index)>& cellFunc);
    ~listCell();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API listCellHeight : public PipeModifier
  {
  public:
    explicit listCellHeight(float cellHeight);
    ~listCellHeight();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API listCellPadding : public PipeModifier
  {
  public:
    explicit listCellPadding(const Layout::EdgeInsets& cellPadding);
    ~listCellPadding();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace list {
        using zui::p::listCell;
        using zui::p::listCellHeight;
        using zui::p::listCellPadding;
      }
    }
  }

} // namespace p

}
