/**
 * @file model.h
 * @brief Data model and binding system
 * @ingroup zui_data_model
 * 
 * Provides data binding, observable objects, and model management
 * for reactive UI updates.
 */

#ifndef __ZUI_MODEL_V2_H__
#define __ZUI_MODEL_V2_H__

#include <functional>
#include <map>
#include <set>
#ifdef __MACOS__
#import <zUI/zui_data_define.h>
#import <zUI/expression.h>
#import <zUI/model_observer.h>
#else
#include "model_observer.h"
#include "zui_data_define.h"
#include "expression.h"
#endif

namespace zui {
  
template <typename T>
class TypedListModel;

#define MODEL_OPERATION_FUNC(model, op, op_detail)                             \
  model &operator op(const T &val) {                                           \
    T curVal = Get();                                                          \
    Set(curVal op_detail val);                                                 \
    return static_cast<model &>(*this);                                        \
  }

#define MODEL_OPERATION_INCREMENT(model)                                       \
  model &operator++() {                                                        \
    T val = Get();                                                             \
    Set(++val);                                                                \
    return *this;                                                              \
  }                                                                            \
  model operator++(int) {                                                      \
    model temp = *this;                                                        \
    ++(*this);                                                                 \
    return temp;                                                               \
  }

#define MODEL_OPERATION_DECREMENT(model)                                       \
  model &operator--() {                                                        \
    T val = Get();                                                             \
    Set(--val);                                                                \
    return *this;                                                              \
  }                                                                            \
  model operator--(int) {                                                      \
    model temp = *this;                                                        \
    --(*this);                                                                 \
    return temp;                                                               \
  }

#define MODEL_OPERATION_EQUAL(model)                                           \
  bool operator==(const model& other) const{                                   \
    return Get() == other.Get();                                               \
  }                                                                            

#define MODEL_OPERATION_EQUAL2()                                           \
  bool operator==(const T& other) const{                                   \
    return Get() == other;                                               \
  }   

#define MODEL_OPERATION(model)                                                 \
  MODEL_OPERATION_FUNC(model, +=, +)                                           \
  MODEL_OPERATION_FUNC(model, -=, -)                                           \
  MODEL_OPERATION_FUNC(model, |=, |)                                           \
  MODEL_OPERATION_FUNC(model, &=, &)                                           \
  MODEL_OPERATION_INCREMENT(model)                                             \
  MODEL_OPERATION_DECREMENT(model)                                             \
  MODEL_OPERATION_EQUAL(model) \
  MODEL_OPERATION_EQUAL2()
  
template <typename T>
class Bind;

template <typename T> class State : public IStateObserver {
public:
  using ValueType = T;

  State();
  State(const T &init);
  State(T &&init);
  State(const State<T> &state);
  State(const std::function<T()>& func);
  ~State();

  void Set(const T &val);
  void SetWithoutNotify(const T& val);
  T const Get() const;
  operator T() const;
  void Swap(State<T> &state);
  decltype(auto) operator()() const;

  State<T> &operator=(const State<T> &state);
  State<T> &operator=(const T &val);
  MODEL_OPERATION(State<T>)

  template <typename F>
  void Mutate(F&& func);

  template <typename F>
  void MutateWithoutNotify(F&& func);

  void SetUpdate(const std::function<void(const T &)> &func);
  void SetViewUpdate(const std::function<void(const T &)> &func);

  void Calc() override;
  int UseCount() override;
  void SetFromSwift(const zui::any& val) override;

protected:
  void SetImpl(const T& val, bool notify);
  void OnUpdate(bool needNotifySwift) override;
  void OnViewUpdate(bool needNotifySwift) override;

protected:
  friend class Bind<T>;

  std::shared_ptr<T> _val;
  std::function<void(const T &)> _update;
  std::function<void(const T &)> _viewUpdate;
  std::function<T()> _calc;
};

template <typename T> class Bind : public IStateObserver {
public:
  using ValueType = T;

  Bind();
  Bind(const T &init);
  Bind(const State<T> &state);
  Bind(const Bind<T> &bind);
  ~Bind();
    
  // Allows for Text("string") syntax for all components using Bind
  // Implicitly convert const char* to std::string
  // Specialized ctor that can accept string literal (const char*) only when T is std::string
  template <typename U = T>
  Bind(const char* value,
       typename std::enable_if<std::is_same<U, std::string>::value>::type* = nullptr)
      : IStateObserver(IStateObserver::Type::kBind), _default(value) {}

  T const Get() const;
  T& GetRef();
  void Set(const T &val);
  void SetWithoutNotify(const T& val);
  operator T() const;
  decltype(auto) operator()() const;

  Bind<T> &operator=(const State<T> &val); // rebind
  Bind<T> &operator=(const Bind<T> &val);
  Bind<T> &operator=(const T &val);
  template <typename U = T>
  typename std::enable_if<std::is_same<U, std::string>::value, Bind<T>&>::type
  operator=(const char* val);
  MODEL_OPERATION(Bind<T>)

  template <typename F>
  void Mutate(F&& func);

  template <typename F>
  void MutateWithoutNotify(F&& func);

  void SetUpdate(const std::function<void(const T &)> &func);
  void SetViewUpdate(const std::function<void(const T &)> &func);
  void SetFromSwift(const zui::any& val) override;

private:
  void SetImpl(const T& val, bool notify);
  void SetInternalViewUpdate(const std::function<void(const T&)>& func);

  template<typename U> friend class TypedListModel;

  void OnUpdate(bool needNotifySwift) override;
  void OnViewUpdate(bool needNotifySwift) override;
  void OnInternalViewUpdate() override;

private:
  friend class ViewNodeModelHelper;

  std::function<void(const T &)> _update;
  std::function<void(const T &)> _viewUpdate;
  std::function<void(const T &)> _internalViewUpdate;

  T _default;
  std::weak_ptr<T> _val;
};

template <typename T>
State(T) -> State<typename std::decay<T>::type>;

template <typename T>
State(const std::function<T()>&) -> State<T>;

template <typename T>
Bind(T) -> Bind<typename std::decay<T>::type>;

template <typename T>
Bind(const State<T>&) -> Bind<T>;

template <typename T>
Bind(const Bind<T>&) -> Bind<T>;

Bind(const char*) -> Bind<std::string>;

template <typename T>
State<T>::State() : 
  IStateObserver(IStateObserver::Type::kState),
  _val(std::make_shared<T>())
{
  AddObserver(true);
}

template <typename T>
State<T>::State(const T &init) : 
  IStateObserver(IStateObserver::Type::kState),
  _val(std::make_shared<T>(init))
{
  AddObserver(true);
}

template <typename T>
State<T>::State(T &&init) : 
  IStateObserver(IStateObserver::Type::kState),
  _val(std::make_shared<T>(init))
{
  AddObserver(true);
}

// Intentionally pointing to the same value: when copying with Loop, it can trigger a single item refresh externally
template <typename T> State<T>::State(const State<T>& state) :
  IStateObserver(IStateObserver::Type::kState),
  _val(state._val)
{
  Move(state.GetBindId());
}

template <typename T> State<T>::~State()
{
  RemoveObserver(this);
}

template <typename T> State<T>::State(const std::function<T()>& func) :
  IStateObserver(IStateObserver::Type::kState),
  _calc(func),
  _val(std::make_shared<T>(func()))
{
  AddObserver(true);
}

template <typename T> void State<T>::Set(const T &val) {
  SetImpl(val, true);
}

template <typename T> void State<T>::SetWithoutNotify(const T& val) {
  SetImpl(val, false);
}

template <typename T> void State<T>::SetImpl(const T& val, bool notify)
{
  if (!_val)
  {
    _val = std::make_shared<T>();
    if (!_val) return;
  }

  if (_bindId == INVALID_BINDING_ID)
  {
    *_val = val;
    AddObserver(notify);
  }
  else if (Get() != val)
  {
    *_val = val;
    Update(notify);
  }
}

template <typename T> T const State<T>::Get() const {
  if (g_reg_fun) {
    g_reg_fun(const_cast<State<T>*>(this));
  }
  if (_val)
    return *_val;

  return T();
}

template <typename T> State<T>::operator T() const 
{ 
  return Get(); 
}

template <typename T>
decltype(auto) State<T>::operator()() const {
  return Get();
}

template <typename T>
void State<T>::Swap(State<T> &other)
{
  T val = other.Get();
  other = Get();
  Set(val);
}

template <typename T> State<T> &State<T>::operator=(const State<T> &state) {
  Set(state.Get());
  return *this;
}

template <typename T> State<T> &State<T>::operator=(const T &val) {
  Set(val);
  return *this;
}

template <typename T>
void State<T>::SetUpdate(const std::function<void(const T &)> &func) {
  if (_update && func != nullptr) {
    // Chain call
    _update = [prev_f = _update, func](const T &val) {
      prev_f(val);
      func(val);
    };
  } else {
    _update = func;
  }
}

template <typename T>
void State<T>::SetViewUpdate(const std::function<void(const T &)> &func) {
  if (_viewUpdate && func != nullptr) {
    _viewUpdate = [prev_f = _viewUpdate, func](const T& val) {
      prev_f(val);
      func(val);
    };
  } else {
    _viewUpdate = func;
  }
}

template <typename T>
void State<T>::OnUpdate(bool needNotifySwift) {
  T newValue = T{};

  if (_val)
    newValue = *_val;

  if (_viewUpdate)
    _viewUpdate(newValue);
  
  if (_update)
    _update(newValue);

#ifdef __MACOS__
  if (needNotifySwift && !_stateName.empty()) {
    ZUIStateDidChange(_stateName, _dataType, (void *)&newValue);
  }
#else
  (void)needNotifySwift; // Suppress unused parameter warning
#endif
}

template <typename T>
void State<T>::OnViewUpdate(bool needNotifySwift) {
  T newValue = T{};

  if (_val)
    newValue = *_val;

  if (_viewUpdate)
    _viewUpdate(newValue);

#ifdef __MACOS__
  if (needNotifySwift && !_stateName.empty()) {
    ZUIStateDidChange(_stateName, _dataType, (void*)&newValue);
  }
#else
  (void)needNotifySwift;
#endif
}

template <typename T>
void State<T>::Calc() {
  if (_calc)
  {
    Set(_calc());
  }
}

template <typename T>
int State<T>::UseCount()
{
  return _val.use_count();
}

template <typename T>
void State<T>::SetFromSwift(const zui::any& val)
{
  Set(zui::any_cast<T>(val));
}

template <typename T>
template <typename F>
void State<T>::Mutate(F&& func) {
    if (!_val) {
        _val = std::make_shared<T>();
    }
    func(*_val);
    Update(true);
}

template <typename T>
template <typename F>
void State<T>::MutateWithoutNotify(F&& func) {
    if (!_val) {
        _val = std::make_shared<T>();
    }
    func(*_val);
    Update(false);
}

template <typename T>
Bind<T>::Bind()
  : IStateObserver(IStateObserver::Type::kBind), _default(T{}) {}

template <typename T>
Bind<T>::Bind(const T &init)
    : IStateObserver(IStateObserver::Type::kBind), _default(init) {}

template <typename T>
Bind<T>::Bind(const State<T> &state)
    : IStateObserver(IStateObserver::Type::kBind) {
  *this = state;
}

template <typename T>
Bind<T>::Bind(const Bind<T> &bind)
    : IStateObserver(IStateObserver::Type::kBind) {
  SetBindId(bind.GetBindId());
  _update = bind._update;
  _default = bind._default;
  _val = bind._val;
  if (_bindId != INVALID_BINDING_ID)
    AddObserver(true);
}

template <typename T> Bind<T>::~Bind()
{
  if (_bindId != INVALID_BINDING_ID)
    RemoveObserver(this);
}

template <typename T> T const Bind<T>::Get() const {
  if (_bindId == INVALID_BINDING_ID)
    return _default;
  if (g_reg_fun) {
    g_reg_fun(const_cast<Bind<T>*>(this));
  }
  if (auto val = _val.lock())
    return *val;
  return _default;
}

template <typename T> T& Bind<T>::GetRef()
{
  if (_bindId == INVALID_BINDING_ID)
    return _default;
  if (g_reg_fun) {
    g_reg_fun(const_cast<Bind<T>*>(this));
  }
  if (auto val = _val.lock())
    return *val;
  return _default;
}

template <typename T> void Bind<T>::Set(const T &value) {
  SetImpl(value, true);
}

template <typename T> void Bind<T>::SetWithoutNotify(const T& value) {
  SetImpl(value, false);
}

template <typename T> void Bind<T>::SetImpl(const T& value, bool notify)
{
  if (_bindId == INVALID_BINDING_ID)
  {
    _default = value;
  }
  else if (Get() != value)
  {
    if (auto val = _val.lock())
      *val = value;
    else
      _default = value;
    Update(notify);
  }
}

template <typename T>
void Bind<T>::SetInternalViewUpdate(const std::function<void(const T&)>& func)
{
  if (_internalViewUpdate) {
    _internalViewUpdate = [prev_f = _internalViewUpdate, func](const T& val) {
      prev_f(val);
      func(val);
    };
  }
  else {
    _internalViewUpdate = func;
  }
}

template <typename T> Bind<T>::operator T() const { return Get(); }

template <typename T> decltype(auto) Bind<T>::operator()() const
{
  return Get();
}

template <typename T> Bind<T> &Bind<T>::operator=(const State<T> &state) {
  _val = state._val;
  Move(state.GetBindId());
  return *this;
}

template <typename T> Bind<T> &Bind<T>::operator=(const Bind<T> &bind) {
  // bind new state
  if (_bindId == INVALID_BINDING_ID) {
    _default = bind._default;
    _val = bind._val;
    SetBindId(bind.GetBindId());
    if (_bindId != INVALID_BINDING_ID)
      AddObserver(true);
  } else {
    Set(bind.Get());
  }
  return *this;
}

template <typename T> Bind<T> &Bind<T>::operator=(const T &val) {
  this->Set(val);
  return *this;
}

template <typename T>
template <typename U>
typename std::enable_if<std::is_same<U, std::string>::value, Bind<T>&>::type
Bind<T>::operator=(const char* val) {
  this->Set(val);
  return *this;
}

template <typename T>
void Bind<T>::SetUpdate(const std::function<void(const T &)> &func) {
  if (_update && func != nullptr) {
    // Chain call
    _update = [prev_f = _update, func](const T &val) {
      prev_f(val);
      func(val);
    };
  } else {
    _update = func;
  }
}

template <typename T>
void Bind<T>::OnUpdate(bool needNotifySwift) {
  T value = _default;

  if (auto val = _val.lock())
    value = *val;
  if (_viewUpdate)
    _viewUpdate(value);
  if (_update)
    _update(value);
#ifdef __MACOS__
  if (needNotifySwift && !_stateName.empty())
    ZUIStateDidChange(_stateName, _dataType, (void *)&value);
#else
  (void)needNotifySwift;
#endif
}

template <typename T>
void Bind<T>::SetViewUpdate(const std::function<void(const T &)> &func) {
  if (_viewUpdate && func != nullptr) {
    _viewUpdate = [prev_f = _viewUpdate, func](const T& val) {
      prev_f(val);
      func(val);
    };
  } else {
    _viewUpdate = func;
  }
}

template <typename T>
void Bind<T>::SetFromSwift(const zui::any& val)
{
  Set(zui::any_cast<T>(val));
}

template <typename T>
template <typename F>
void Bind<T>::Mutate(F&& func) {
    if (_bindId == INVALID_BINDING_ID) {
        func(_default);
        Update(true);
    }
    else {
        if (auto val = _val.lock()) {
            func(*val);
            Update(true);
        }
    }
}

template <typename T>
template <typename F>
void Bind<T>::MutateWithoutNotify(F&& func) {
    if (_bindId == INVALID_BINDING_ID) {
        func(_default);
        Update(false);
    }
    else {
        if (auto val = _val.lock()) {
            func(*val);
            Update(false);
        }
    }
}

template <typename T>
void Bind<T>::OnViewUpdate(bool needNotifySwift) {
  T value = _default;

  if (auto val = _val.lock())
    value = *val;

  if (_viewUpdate)
    _viewUpdate(value);
#ifdef __MACOS__
  if (needNotifySwift && !_stateName.empty())
    ZUIStateDidChange(_stateName, _dataType, (void *)&value);
#else
  (void)needNotifySwift;
#endif
}

template <typename T>
void Bind<T>::OnInternalViewUpdate()
{
  T value = _default;

  if (auto val = _val.lock())
    value = *val;

  if (_internalViewUpdate)
    _internalViewUpdate(value);
}

template <typename Fun, typename... Args >
auto calc(Fun&& func, Args &&...args)
{
  using DecayedFun = typename std::decay<Fun>::type;
  using RetType = std::invoke_result_t<DecayedFun&>;

  Bind<RetType> calcBind;
  std::shared_ptr<State<RetType>> calcState = std::make_shared<State<RetType>>(func);

  if (calcState)
  {
    RegGuard g{ [&](IStateObserver* source) {
      if (!source)
        return;
      AddCalcObserver(calcState, source->GetBindId());
     }
    };
    (void)std::initializer_list<int>{ (args.Get(), 0)... };
    func();
    calcBind = *calcState;
  }
  return calcBind;
}

template <typename Expr>
auto expr(Expr&& expression)
{
  return zui::calc([f = std::forward<Expr>(expression)]() -> decltype(auto) {
    return f();
  });
}

} // namespace zui

#endif
