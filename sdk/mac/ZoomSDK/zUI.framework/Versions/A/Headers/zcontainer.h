#ifndef __ZUI_ZCONTAINER_BASE_H__
#define __ZUI_ZCONTAINER_BASE_H__

#include <functional>
#include <vector>
#include "model.h"

namespace zui 
{

/**
 * @brief Base class for reactive containers
 * 
 * ZContainerBase provides common functionality for reactive containers like ZVector and ZList.
 * It handles change notifications, size tracking, and common callback mechanisms.
 * 
 * @tparam T Element type
 * @tparam Container Underlying container type (std::vector, std::list, etc.)
 */
template<typename T, typename Container>
class ZContainerBase : public IStateObserver
{
public:
  enum class ChangeType {
    kAdd,       // Add element
    kRemove,    // Remove element  
    kModify,    // Modify element
    kClear,     // Clear container
    kReplace    // Replace entire container
  };

  struct ChangeInfo {
    ChangeType type;
    size_t index;
    T value;
    
    ChangeInfo(ChangeType t, size_t idx, const T& val = T{}) 
      : type(t), index(idx), value(val) {}
  };

  using ChangeCallback = std::function<void(const ChangeInfo&)>;
  using SizeCallback = std::function<void(const int&)>;

protected:
  ZContainerBase() : IStateObserver(IStateObserver::Type::kState) {
    AddObserver(false);
  }

  ZContainerBase(const Container& container) 
    : IStateObserver(IStateObserver::Type::kState), _data(container) {
    AddObserver(false);
  }

  ZContainerBase(const ZContainerBase<T, Container>& other) 
    : IStateObserver(IStateObserver::Type::kState), _data(other._data) {
    AddObserver(false);
  }

public:
  virtual ~ZContainerBase() = default;

  // Common interface
  virtual size_t Size() const {
    return _data.size();
  }

  virtual bool Empty() const {
    return _data.empty();
  }

  virtual void Clear() {
    _data.clear();
    NotifyChange(ChangeInfo(ChangeType::kClear, 0));
  }

  virtual void SetChangeCallback(const ChangeCallback& callback) {
    _changeCallback = callback;
  }

  virtual void SetSizeCallback(const SizeCallback& callback) {
    _sizeCallback = callback;
  }

  // Get reference to underlying container (read-only)
  const Container& GetData() const {
    return _data;
  }

  // Iterator support
  typename Container::iterator begin() { return _data.begin(); }
  typename Container::iterator end() { return _data.end(); }
  typename Container::const_iterator begin() const { return _data.begin(); }
  typename Container::const_iterator end() const { return _data.end(); }
  typename Container::const_iterator cbegin() const { return _data.cbegin(); }
  typename Container::const_iterator cend() const { return _data.cend(); }

protected:
  void NotifyChange(const ChangeInfo& info) {
    if (_changeCallback) {
      _changeCallback(info);
    }
    if (_sizeCallback) {
      _sizeCallback(static_cast<int>(_data.size()));
    }
    // Trigger state update notification
    Update(true);
  }

  // Assignment operators for derived classes
  ZContainerBase<T, Container>& AssignContainer(const Container& container) {
    _data = container;
    NotifyChange(ChangeInfo(ChangeType::kReplace, 0));
    return *this;
  }

  ZContainerBase<T, Container>& AssignOther(const ZContainerBase<T, Container>& other) {
    if (this != &other) {
      _data = other._data;
      NotifyChange(ChangeInfo(ChangeType::kReplace, 0));
    }
    return *this;
  }

protected:
  Container _data;
  ChangeCallback _changeCallback;
  SizeCallback _sizeCallback;
};


/**
 * @brief Base class for reactive containers with State<T> elements
 * 
 * Specialized base class that provides automatic monitoring of State<T> elements.
 * 
 * @tparam T Element value type (the T in State<T>)
 * @tparam Container Underlying container type containing State<T> elements
 */
template<typename T, typename Container>
class ZStateContainerBase : public IStateObserver
{
public:
  using ChangeInfo = typename ZContainerBase<T, std::vector<T>>::ChangeInfo;  // Use ZContainerBase's ChangeInfo with T
  using ChangeType = typename ZContainerBase<T, std::vector<T>>::ChangeType;  // Use ZContainerBase's ChangeType
  using ChangeCallback = std::function<void(const ChangeInfo&)>;
  using SizeCallback = std::function<void(const int&)>;
  using ElementChangeCallback = std::function<void(size_t, const T&)>;

protected:
  ZStateContainerBase() : IStateObserver(IStateObserver::Type::kState) {
    AddObserver(false);
  }

  ZStateContainerBase(const Container& container) 
    : IStateObserver(IStateObserver::Type::kState), _data(container) {
    AddObserver(false);
  }

public:
  virtual ~ZStateContainerBase() = default;

  // Common interface
  virtual size_t Size() const {
    return _data.size();
  }

  virtual bool Empty() const {
    return _data.empty();
  }

  virtual void Clear() {
    _data.clear();
    NotifyChange(ChangeInfo(ChangeType::kClear, 0));
  }

  virtual void SetChangeCallback(const ChangeCallback& callback) {
    _changeCallback = callback;
  }

  virtual void SetSizeCallback(const SizeCallback& callback) {
    _sizeCallback = callback;
  }

  virtual void SetElementChangeCallback(const ElementChangeCallback& callback) {
    _elementChangeCallback = callback;
  }

  // Iterator support
  typename Container::iterator begin() { return _data.begin(); }
  typename Container::iterator end() { return _data.end(); }
  typename Container::const_iterator begin() const { return _data.begin(); }
  typename Container::const_iterator end() const { return _data.end(); }

protected:
  void NotifyChange(const ChangeInfo& info) {
    if (_changeCallback) {
      _changeCallback(info);
    }
    if (_sizeCallback) {
      _sizeCallback(static_cast<int>(_data.size()));
    }
    Update(true);
  }

  void NotifyElementChange(size_t index, const T& value) {
    if (_elementChangeCallback) {
      _elementChangeCallback(index, value);
    }
    NotifyChange(ChangeInfo(ChangeType::kModify, index, value));
  }

protected:
  Container _data;
  ChangeCallback _changeCallback;
  SizeCallback _sizeCallback;
  ElementChangeCallback _elementChangeCallback;
};

}
#endif 
