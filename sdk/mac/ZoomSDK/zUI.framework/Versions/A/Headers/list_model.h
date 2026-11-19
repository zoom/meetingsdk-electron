/**
 * @file list_model.h
 * @brief List model interface and implementation for data binding
 * @ingroup zui_model
 */

#ifndef _ZUI_LIST_MODEL_H_
#define _ZUI_LIST_MODEL_H_

#include <vector>
#include <memory>
#include <functional>
#include "zUI/model/model.h"

namespace zui
{
  class IListModel
  {
  public:
    virtual ~IListModel() = default;
    virtual size_t GetCount() const = 0;
    virtual zui::any GetItem(size_t index) const = 0;
    virtual void RegisterObserver(std::function<void()> onUpdate) = 0;
  };

  template <typename T>
  class TypedListModel : public IListModel
  {
  public:
    TypedListModel(const Bind<std::vector<T>>& source) : _source(source)
    {
    }

    size_t GetCount() const override
    {
      return _source.Get().size();
    }

    zui::any GetItem(size_t index) const override
    {
      std::vector<T> list = _source.Get();
      if (index < list.size())
        return list[index];
      return {};
    }

    void RegisterObserver(std::function<void()> onUpdate) override
    {
      _source.SetInternalViewUpdate([onUpdate](const std::vector<T>& val) {
        onUpdate();
        });
    }

  private:
    Bind<std::vector<T>> _source;
  };
}

#endif // _ZUI_LIST_MODEL_H_

