#ifndef __ZUI_ZLIST_H__
#define __ZUI_ZLIST_H__

#include <list>
#include "model.h"
#include "zcontainer.h"

namespace zui 
{

/**
 * @brief Reactive list container that supports listening to add/remove/modify operations
 * 
 * ZList is a reactive container based on std::list. When elements in the list
 * are added, removed, or modified, it automatically triggers corresponding callback functions
 * to implement data binding and UI updates.
 * 
 * @tparam T List element type
 */
template<typename T>
class ZList : public ZContainerBase<T, std::list<T>>
{
  using Base = ZContainerBase<T, std::list<T>>;

public:
  using ChangeType = typename Base::ChangeType;
  using ChangeInfo = typename Base::ChangeInfo;
  using ChangeCallback = typename Base::ChangeCallback;
  using SizeCallback = typename Base::SizeCallback;

public:
  ZList() : Base() {}

  ZList(const std::initializer_list<T>& init_list) 
    : Base(std::list<T>(init_list)) {}

  ZList(const ZList<T>& other) : Base(other) {}

  ZList<T>& operator=(const ZList<T>& other) {
    Base::AssignOther(other);
    return *this;
  }

  ZList<T>& operator=(const std::list<T>& list) {
    Base::AssignContainer(list);
    return *this;
  }

  ZList<T>& operator=(std::initializer_list<T> init_list) {
    Base::AssignContainer(std::list<T>(init_list));
    return *this;
  }

  virtual ~ZList() = default;

  // ZList-specific methods
  void PushBack(const T& val);
  void PopBack();
  void PushFront(const T& value);
  void PopFront();
  void Insert(size_t index, const T& value);
  void Erase(size_t index);
  void Set(size_t index, const T& value);
  
  // Access methods
  T& operator[](size_t index);
  const T& operator[](size_t index) const;
  T& At(size_t index);
  const T& At(size_t index) const;
  T& Front();
  const T& Front() const;
  T& Back();
  const T& Back() const;

private:
  typename std::list<T>::iterator GetIteratorAt(size_t index);
  typename std::list<T>::const_iterator GetIteratorAt(size_t index) const;
};

// Implementation section

template<typename T>
void ZList<T>::PushBack(const T& val)
{
  this->_data.push_back(val);
  size_t index = this->_data.size() - 1;
  this->NotifyChange(ChangeInfo(ChangeType::kAdd, index, val));
}

template<typename T>
void ZList<T>::PopBack()
{
  if (!this->_data.empty()) 
  {
    T removedValue = this->_data.back();
    size_t index = this->_data.size() - 1;
    this->_data.pop_back();
    this->NotifyChange(ChangeInfo(ChangeType::kRemove, index, removedValue));
  }
}

template<typename T>
void ZList<T>::PushFront(const T& value)
{
  this->_data.push_front(value);
  this->NotifyChange(ChangeInfo(ChangeType::kAdd, 0, value));
}

template<typename T>
void ZList<T>::PopFront()
{
  if (!this->_data.empty()) 
  {
    T removedValue = this->_data.front();
    this->_data.pop_front();
    this->NotifyChange(ChangeInfo(ChangeType::kRemove, 0, removedValue));
  }
}

template<typename T>
void ZList<T>::Insert(size_t index, const T& value)
{
  if (index <= this->_data.size()) {
    auto it = GetIteratorAt(index);
    this->_data.insert(it, value);
    this->NotifyChange(ChangeInfo(ChangeType::kAdd, index, value));
  }
}

template<typename T>
void ZList<T>::Erase(size_t index)
{
  if (index < this->_data.size()) {
    auto it = GetIteratorAt(index);
    T removedValue = *it;
    this->_data.erase(it);
    this->NotifyChange(ChangeInfo(ChangeType::kRemove, index, removedValue));
  }
}

template<typename T>
void ZList<T>::Set(size_t index, const T& value)
{
  if (index < this->_data.size()) {
    auto it = GetIteratorAt(index);
    *it = value;
    this->NotifyChange(ChangeInfo(ChangeType::kModify, index, value));
  }
}

template<typename T>
T& ZList<T>::operator[](size_t index)
{
  auto it = GetIteratorAt(index);
  return *it;
}

template<typename T>
const T& ZList<T>::operator[](size_t index) const
{
  auto it = GetIteratorAt(index);
  return *it;
}

template<typename T>
T& ZList<T>::At(size_t index)
{
  if (index >= this->_data.size()) {
    static T default_val{};
    return default_val;
  }
  auto it = GetIteratorAt(index);
  return *it;
}

template<typename T>
const T& ZList<T>::At(size_t index) const
{
  if (index >= this->_data.size()) {
    static T default_val{};
    return default_val;
  }
  auto it = GetIteratorAt(index);
  return *it;
}

template<typename T>
T& ZList<T>::Front()
{
  return this->_data.front();
}

template<typename T>
const T& ZList<T>::Front() const
{
  return this->_data.front();
}

template<typename T>
T& ZList<T>::Back()
{
  return this->_data.back();
}

template<typename T>
const T& ZList<T>::Back() const
{
  return this->_data.back();
}

template<typename T>
typename std::list<T>::iterator ZList<T>::GetIteratorAt(size_t index)
{
  auto it = this->_data.begin();
  std::advance(it, index);
  return it;
}

template<typename T>
typename std::list<T>::const_iterator ZList<T>::GetIteratorAt(size_t index) const
{
  auto it = this->_data.begin();
  std::advance(it, index);
  return it;
}


// Specialized version: supports State<T> type elements with automatic element change monitoring
template<typename T>
class ZList<State<T>> : public ZStateContainerBase<T, std::list<State<T>>>
{
  using Base = ZStateContainerBase<T, std::list<State<T>>>;

public:
  using ChangeCallback = typename Base::ChangeCallback;
  using SizeCallback = typename Base::SizeCallback;
  using ElementChangeCallback = typename Base::ElementChangeCallback;
  using ChangeInfo = typename Base::ChangeInfo;
  using ChangeType = typename Base::ChangeType;

public:
  ZList() : Base() {}

  ZList(const std::initializer_list<State<T>>& init_list) 
    : Base(std::list<State<T>>(init_list)) {
    SetupElementObservers();
  }

  virtual ~ZList() = default;
  
  void PushBack(const State<T>& value) {
    this->_data.push_back(value);
    size_t index = this->_data.size() - 1;
    SetupElementObserver(index);
    this->NotifyChange(ChangeInfo(ChangeType::kAdd, index, value.Get()));
  }

  void PushBack(const T& value) {
    State<T> state(value);
    PushBack(state);
  }

  void PopBack() {
    if (!this->_data.empty()) {
      T removedValue = this->_data.back().Get();
      size_t index = this->_data.size() - 1;
      this->_data.pop_back();
      this->NotifyChange(ChangeInfo(ChangeType::kRemove, index, removedValue));
    }
  }

  void PushFront(const State<T>& value) {
    this->_data.push_front(value);
    SetupElementObservers(); // Re-setup all observers since indices changed
    this->NotifyChange(ChangeInfo(ChangeType::kAdd, 0, value.Get()));
  }

  void PushFront(const T& value) {
    State<T> state(value);
    PushFront(state);
  }

  void PopFront() {
    if (!this->_data.empty()) {
      T removedValue = this->_data.front().Get();
      this->_data.pop_front();
      SetupElementObservers(); // Re-setup all observers since indices changed
      this->NotifyChange(ChangeInfo(ChangeType::kRemove, 0, removedValue));
    }
  }

  State<T>& operator[](size_t index) {
    auto it = GetIteratorAt(index);
    return *it;
  }

  const State<T>& operator[](size_t index) const {
    auto it = GetIteratorAt(index);
    return *it;
  }

  State<T>& At(size_t index) {
    if (index >= this->_data.size()) {
      static State<T> default_val{};
      return default_val;
    }
    auto it = GetIteratorAt(index);
    return *it;
  }

  const State<T>& At(size_t index) const {
    if (index >= this->_data.size()) {
      static State<T> default_val{};
      return default_val;
    }
    auto it = GetIteratorAt(index);
    return *it;
  }

  State<T>& Front() { return this->_data.front(); }
  const State<T>& Front() const { return this->_data.front(); }
  State<T>& Back() { return this->_data.back(); }
  const State<T>& Back() const { return this->_data.back(); }

private:
  void SetupElementObservers() {
    size_t index = 0;
    for (auto it = this->_data.begin(); it != this->_data.end(); ++it, ++index) {
      SetupElementObserver(index, it);
    }
  }

  void SetupElementObserver(size_t index) {
    auto it = GetIteratorAt(index);
    SetupElementObserver(index, it);
  }

  void SetupElementObserver(size_t index, typename std::list<State<T>>::iterator it) {
    it->SetUpdate([this, index](const T& value) {
      this->NotifyElementChange(index, value);
    });
  }

  typename std::list<State<T>>::iterator GetIteratorAt(size_t index) {
    auto it = this->_data.begin();
    std::advance(it, index);
    return it;
  }

  typename std::list<State<T>>::const_iterator GetIteratorAt(size_t index) const {
    auto it = this->_data.begin();
    std::advance(it, index);
    return it;
  }
};

}
#endif 