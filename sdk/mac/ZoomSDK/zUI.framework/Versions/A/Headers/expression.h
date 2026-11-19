#ifndef __ZUI_EXPRESSION_H__
#define __ZUI_EXPRESSION_H__

#include <type_traits>
#include <utility>

namespace zui {

template <typename T> class State;
template <typename T> class Bind;

template <typename T> struct IsStateOrBind_impl : std::false_type {};
template <typename T> struct IsStateOrBind_impl<State<T>> : std::true_type {};
template <typename T> struct IsStateOrBind_impl<Bind<T>>  : std::true_type {};

template <typename Op, typename L, typename R> class BinaryOpExpr;

template <typename T> struct IsBinaryOpExpr_impl : std::false_type {};
template <typename Op, typename L, typename R>
struct IsBinaryOpExpr_impl<BinaryOpExpr<Op, L, R>> : std::true_type {};

template <typename T>
concept ModelLeaf = IsStateOrBind_impl<std::decay_t<T>>::value
                 || IsBinaryOpExpr_impl<std::decay_t<T>>::value;

template <typename L, typename R>
concept IsModelOp = ModelLeaf<L> || ModelLeaf<R>;

template <typename T>
struct ValueWrapper {
  using ValueType = std::decay_t<T>;
  T m_value;

  template <typename Type>
  ValueWrapper(Type&& t) : m_value(std::forward<Type>(t)) {}

  const T& operator()() const { return m_value; }
};

template <typename T>
using ExprTraits = std::conditional_t<ModelLeaf<T>, T, ValueWrapper<T>>;

template <typename Op, typename L, typename R>
class BinaryOpExpr {
 public:
  using ValueType =
      std::decay_t<std::common_type_t<typename L::ValueType,
                                      typename R::ValueType>>;

  template <typename Left, typename Right>
  BinaryOpExpr(Left&& l, Right&& r, Op o = Op{})
      : m_left(std::forward<Left>(l)),
        m_right(std::forward<Right>(r)),
        m_op(o) {}

  auto operator()() const { return calculate(); }
  operator ValueType() { return calculate(); }

 private:
  auto calculate() const { return m_op(m_left(), m_right()); }

  L  m_left;
  R  m_right;
  Op m_op;
};

template <typename Op, typename L, typename R>
auto make_binary_expr(L&& l, R&& r) {
  return BinaryOpExpr<Op,
                      ExprTraits<std::decay_t<L>>,
                      ExprTraits<std::decay_t<R>>>(
      std::forward<L>(l), std::forward<R>(r));
}

struct AddOp {
  template <typename L, typename R>
  auto operator()(L&& l, R&& r) const {
    return std::forward<L>(l) + std::forward<R>(r);
  }
};

struct SubOp {
  template <typename L, typename R>
  auto operator()(L&& l, R&& r) const {
    return std::forward<L>(l) - std::forward<R>(r);
  }
};

struct MulOp {
  template <typename L, typename R>
  auto operator()(L&& l, R&& r) const {
    return std::forward<L>(l) * std::forward<R>(r);
  }
};

struct DivOp {
  template <typename L, typename R>
  auto operator()(L&& l, R&& r) const {
    return std::forward<L>(l) / std::forward<R>(r);
  }
};

template <typename T1, typename T2>
  requires IsModelOp<T1, T2>
auto operator+(T1&& l, T2&& r) {
  return make_binary_expr<AddOp>(std::forward<T1>(l), std::forward<T2>(r));
}

template <typename T1, typename T2>
  requires IsModelOp<T1, T2>
auto operator-(T1&& l, T2&& r) {
  return make_binary_expr<SubOp>(std::forward<T1>(l), std::forward<T2>(r));
}

template <typename T1, typename T2>
  requires IsModelOp<T1, T2>
auto operator*(T1&& l, T2&& r) {
  return make_binary_expr<MulOp>(std::forward<T1>(l), std::forward<T2>(r));
}

template <typename T1, typename T2>
  requires IsModelOp<T1, T2>
auto operator/(T1&& l, T2&& r) {
  return make_binary_expr<DivOp>(std::forward<T1>(l), std::forward<T2>(r));
}

}  // namespace zui
#endif
