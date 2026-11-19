#ifndef __ZUI_ZVECTOR_H__
#define __ZUI_ZVECTOR_H__

#include <vector>
#include "model.h"
#include "zcontainer.h"

namespace zui 
{

/**
 * @brief Reactive vector container that supports listening to add/remove/modify operations
 * 
 * ZVector is a reactive container based on std::vector. When elements in the vector
 * are added, removed, or modified, it automatically triggers corresponding callback functions
 * to implement data binding and UI updates.
 * 
 * @tparam T Vector element type
 */
template<typename T>
class ZVector : public ZContainerBase<T, std::vector<T>>
{
  using Base = ZContainerBase<T, std::vector<T>>;

public:
  using ChangeType = typename Base::ChangeType;
  using ChangeInfo = typename Base::ChangeInfo;
  using ChangeCallback = typename Base::ChangeCallback;
  using SizeCallback = typename Base::SizeCallback;

public:
  ZVector() : Base() {}

  ZVector(const std::initializer_list<T>& init_list) 
    : Base(std::vector<T>(init_list)) {}

  ZVector(const ZVector<T>& other) : Base(other) {}

  ZVector<T>& operator=(const ZVector<T>& other) {
    Base::AssignOther(other);
    return *this;
  }

  ZVector<T>& operator=(const std::vector<T>& vec) {
    Base::AssignContainer(vec);
    return *this;
  }

  ZVector<T>& operator=(std::initializer_list<T> init_list) {
    Base::AssignContainer(std::vector<T>(init_list));
    return *this;
  }

  virtual ~ZVector() = default;

  // ZVector-specific methods
  void PushBack(const T& val);
  void PopBack();
  void Insert(size_t index, const T& value);
  void Erase(size_t index);
  void Set(size_t index, const T& value);
  
  // Access methods
  T& operator[](size_t index);
  const T& operator[](size_t index) const;
  T& At(size_t index);
  const T& At(size_t index) const;
};

// Implementation section

template<typename T>
void ZVector<T>::PushBack(const T& val)
{
  this->_data.emplace_back(val);
  size_t index = this->_data.size() - 1;
  this->NotifyChange(ChangeInfo(ChangeType::kAdd, index, val));
}

template<typename T>
void ZVector<T>::PopBack()
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
void ZVector<T>::Insert(size_t index, const T& value)
{
  if (index <= this->_data.size()) {
    this->_data.insert(this->_data.begin() + index, value);
    this->NotifyChange(ChangeInfo(ChangeType::kAdd, index, value));
  }
}

template<typename T>
void ZVector<T>::Erase(size_t index)
{
  if (index < this->_data.size()) {
    T removedValue = this->_data[index];
    this->_data.erase(this->_data.begin() + index);
    this->NotifyChange(ChangeInfo(ChangeType::kRemove, index, removedValue));
  }
}

template<typename T>
void ZVector<T>::Set(size_t index, const T& value)
{
  if (index < this->_data.size()) {
    this->_data[index] = value;
    this->NotifyChange(ChangeInfo(ChangeType::kModify, index, value));
  }
}

template<typename T>
T& ZVector<T>::operator[](size_t index)
{
  return this->_data[index];
}

template<typename T>
const T& ZVector<T>::operator[](size_t index) const
{
  return this->_data[index];
}

template<typename T>
T& ZVector<T>::At(size_t index)
{
  return this->_data.at(index);
}

template<typename T>
const T& ZVector<T>::At(size_t index) const
{
  return this->_data.at(index);
}


// Specialized version: supports State<T> type elements with automatic element change monitoring
template<typename T>
class ZVector<State<T>> : public ZStateContainerBase<T, std::vector<State<T>>>
{
  using Base = ZStateContainerBase<T, std::vector<State<T>>>;

public:
  using ChangeCallback = typename Base::ChangeCallback;
  using SizeCallback = typename Base::SizeCallback;
  using ElementChangeCallback = typename Base::ElementChangeCallback;
  using ChangeInfo = typename Base::ChangeInfo;
  using ChangeType = typename Base::ChangeType;

public:
  ZVector() : Base() {}

  ZVector(const std::initializer_list<State<T>>& init_list) 
    : Base(std::vector<State<T>>(init_list)) {
    SetupElementObservers();
  }

  virtual ~ZVector() = default;
  
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

  State<T>& operator[](size_t index) { return this->_data[index]; }
  const State<T>& operator[](size_t index) const { return this->_data[index]; }

private:
  void SetupElementObservers() {
    for (size_t i = 0; i < this->_data.size(); ++i) {
      SetupElementObserver(i);
    }
  }

  void SetupElementObserver(size_t index) {
    if (index < this->_data.size()) {
      this->_data[index].SetUpdate([this, index](const T& value) {
        this->NotifyElementChange(index, value);
      });
    }
  }
};

}
#endif