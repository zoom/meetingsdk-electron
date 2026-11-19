/**
 * @file loop.h
 * @brief Loop logic component
 * @ingroup zui_logic_views
 * 
 * Provides loop rendering functionality for dynamic content generation.
 */

#ifndef _ZUI_LOOP_H_
#define _ZUI_LOOP_H_

#include <functional>
#include <memory>
#include <type_traits>
#include <vector>
#include "container.h"
#include "zUI/model/list_model.h"

namespace zui
{
  namespace detail
  {
    template <typename T>
    struct function_traits : public function_traits<decltype(&T::operator())> {};

    template <typename ClassType, typename ReturnType, typename Arg>
    struct function_traits<ReturnType(ClassType::*)(Arg) const>
    {
      using arg_type = Arg;
      using return_type = ReturnType;
    };

    template <typename ClassType, typename ReturnType, typename Arg>
    struct function_traits<ReturnType(ClassType::*)(Arg)>
    {
      using arg_type = Arg;
      using return_type = ReturnType;
    };
  }

	/**
	 * @class Loop
	 * @brief A view component for rendering collections of data.
	 * @ingroup controls_logic
	 */
	class ZUI_API Loop : public View
	{
	public:
    template <typename Range>
    Loop(const Range& range) : Loop(CreateTypedModel(range)) {}

		virtual ~Loop() = default;

		/**
		* @brief Set up a view for loop creation.
		* @param[in] view
		*/

    template <typename F>
    Loop& body(F&& func)
    {
      using Traits = detail::function_traits<typename std::decay<F>::type>;
      using ArgType = typename Traits::arg_type;
      using RetType = typename Traits::return_type;
      using T = typename std::remove_reference<ArgType>::type;
      using ReturnsPtr = typename std::is_convertible<RetType, std::shared_ptr<View>>::type;

      return bodyImpl<T>(std::forward<F>(func), ReturnsPtr{});
    }

  protected:
    Loop& bodyCore(const std::function<std::shared_ptr<View>(zui::any&)>& func);
    explicit Loop(std::shared_ptr<IListModel> model);

    // Helper to avoid any_cast when T is zui::any
    template <typename T>
    static T& cast_helper(zui::any& val, std::false_type) {
      return zui::any_cast<T&>(val);
    }

    template <typename T>
    static zui::any& cast_helper(zui::any& val, std::true_type) {
      return val;
    }

    template <typename T, typename F>
    Loop& bodyImpl(F&& func, std::true_type)
    {
      auto adapter = [func = std::forward<F>(func)](zui::any& val) mutable -> std::shared_ptr<View> {
        using IsAny = typename std::is_same<T, zui::any>::type;
        return func(cast_helper<T>(val, IsAny{}));
      };
      return bodyCore(adapter);
    }

    template <typename T, typename F>
    Loop& bodyImpl(F&& func, std::false_type)
    {
      auto adapter = [func = std::forward<F>(func)](zui::any& val) mutable -> std::shared_ptr<View> {
        using IsAny = typename std::is_same<T, zui::any>::type;
        auto res = func(cast_helper<T>(val, IsAny{}));
        using ActualType = decltype(res);
        static_assert(std::is_base_of<View, ActualType>::value, "Return type must be derived from View");
        return std::make_shared<ActualType>(std::move(res));
      };
      return bodyCore(adapter);
    }

    template <typename T>
    static std::shared_ptr<IListModel> CreateTypedModel(const std::vector<T>& range) {
      return std::make_shared<TypedListModel<T>>(Bind<std::vector<T>>(range));
    }

    template <typename T>
    static std::shared_ptr<IListModel> CreateTypedModel(const State<std::vector<T>>& range) {
      return std::make_shared<TypedListModel<T>>(Bind<std::vector<T>>(range));
    }

    template <typename T>
    static std::shared_ptr<IListModel> CreateTypedModel(const Bind<std::vector<T>>& range) {
      return std::make_shared<TypedListModel<T>>(range);
    }
	};

	/**
	 * @class ListLoop
	 * @brief A specialized loop view with accessibility features similar to list(Windows only currently)
	 * @ingroup controls_logic
	 */
	class ZUI_API ListLoop : public Loop
	{
	public:
		ListLoop(const Bind<std::vector<zui::any>>& range);
	};

namespace p
{

  // Loop-specific pipe modifiers
  class ZUI_API loopBody : public PipeModifier
  {
  public:
    explicit loopBody(const std::function<std::shared_ptr<View>(zui::any& val)>& func);
    explicit loopBody(const std::function<View(zui::any& val)>& func);
    ~loopBody();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace loop {
        using zui::p::loopBody;
      }
    }
  }

} // namespace p

}

#endif
