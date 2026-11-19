/**
 * @file conditional.h
 * @brief Conditional logic components
 * @ingroup zui_logic_views
 * 
 * Provides conditional rendering functionality for dynamic UI logic.
 */

#pragma once

#include <memory>
#include <vector>
#include "view.h"
#include "zui_data_define.h"

// forward declaration
namespace zui
{
  namespace p
  {
    class IfTrue;
    class IfFalse;
    class When;
    class Otherwise;
  }
  
  /**
   * @class Conditional
   * @brief A view component that conditionally renders its child views based on a boolean condition.
   * @ingroup controls_logic
   * 
   * The Conditional component allows for dynamic UI rendering based on boolean conditions. It supports:
   * - Two separate view sets for true and false conditions
   * - Multiple child views in each condition
   * - Dynamic updates when the condition changes
   * 
   * @example
   * @code
   * // Basic conditional rendering
   * Conditional(isLoggedIn)
   *   .IfTrue(WelcomeMessage())
   *   .IfFalse(LoginButton());
   * 
   * // Multiple views in conditions
   * Conditional(hasError)
   *   .IfTrue(ErrorMessage(), RetryButton())
   *   .IfFalse(SuccessMessage());
   * @endcode
   */
  class ZUI_API Conditional : public View
  {
  public:
    /**
     * @brief Constructs a new Conditional object
     * @param condition The boolean condition that determines which views to render
     */
    Conditional(const Bind<bool>& condition);

    /// @brief Virtual destructor
    virtual ~Conditional() = default;

    /**
     * @brief Sets the child views to be rendered when the condition is true
     * @tparam Views Variadic template parameter for multiple view types
     * @param views The views to render when condition is true
     * @return Reference to this conditional for method chaining
     */
    template<typename... Views>
    Conditional& IfTrue(Views&&... views)
    {
      int dummy[] = { 0, (AddIfTrueView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy); // Prevent unused variable warning
      return *this;
    }

    /**
     * @brief Sets the child views to be rendered when the condition is false
     * @tparam Views Variadic template parameter for multiple view types
     * @param views The views to render when condition is false
     * @return Reference to this conditional for method chaining
     */
    template<typename... Views>
    Conditional& IfFalse(Views&&... views)
    {
      int dummy[] = { 0, (AddIfFalseView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy); // Prevent unused variable warning
      return *this;
    }

  protected:
    friend class p::IfTrue;
    friend class p::IfFalse;
    /**
     * @brief Adds a view node to the true condition set
     * @param viewNode The view node to add
     */
    void AddIfTrueView(std::shared_ptr<ViewNode> viewNode);

    /**
     * @brief Adds a view node to the false condition set
     * @param viewNode The view node to add
     */
    void AddIfFalseView(std::shared_ptr<ViewNode> viewNode);
  };

  /**
   * @class MultiConditional
   * @brief A view component for handling multiple conditional states.
   * @ingroup zui_logic_views
   */
  class ZUI_API MultiConditional : public View
  {
  public:
    MultiConditional(const Bind<int>& multiCondition);

    virtual ~MultiConditional() = default;

    /**
    * @brief Set Child views in different valid conditions
    * @param[in] val
    * @param[in] views
    */
    template<typename... Views>
    MultiConditional& When(int val, Views&&... views)
    {
      int dummy[] = { 0, (AddConditionValidView(val, views.GetViewNode()), 0 )... };
      static_cast<void>(dummy);

      return *this;
    }

    /**
    * @brief Set default Child views if all conditions are false
    * @param[in] views The views to render when all conditions are false
    */
    template<typename... Views>
    MultiConditional& Otherwise(Views&&... views)
    {
      int dummy[] = { 0, (AddConditionInvalidView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);

      return *this;
    }

  protected:
    friend class p::When;
    friend class p::Otherwise;
    
    void AddConditionValidView(int val, std::shared_ptr<ViewNode> viewNode);
    void AddConditionInvalidView(std::shared_ptr<ViewNode> viewNode);
  };

namespace p
{

  // Conditional-specific pipe modifiers
  class ZUI_API IfTrue : public PipeModifier
  {
  public:
    template<typename... Views>
    explicit IfTrue(Views&&... views) : _pImpl(nullptr)
    {
      int dummy[] = { 0, (addViewNode(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);
    }
    ~IfTrue();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    mutable Impl* _pImpl;
    void addViewNode(std::shared_ptr<ViewNode> viewNode);
  };

  class ZUI_API IfFalse : public PipeModifier
  {
  public:
    template<typename... Views>
    explicit IfFalse(Views&&... views) : _pImpl(nullptr)
    {
      int dummy[] = { 0, (addViewNode(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);
    }
    ~IfFalse();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    mutable Impl* _pImpl;
    void addViewNode(std::shared_ptr<ViewNode> viewNode);
  };

  // MultiConditional-specific pipe modifiers
  class ZUI_API When : public PipeModifier
  {
  public:
    template<typename... Views>
    explicit When(int val, Views&&... views) : _val(val), _pImpl(nullptr)
    {
      int dummy[] = { 0, (addViewNode(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);
    }
    ~When();
  protected:
    void apply(View& v) const override;
  private:
    int _val;
    class Impl;
    mutable Impl* _pImpl;
    void addViewNode(std::shared_ptr<ViewNode> viewNode);
  };

  class ZUI_API Otherwise : public PipeModifier
  {
  public:
    template<typename... Views>
    explicit Otherwise(Views&&... views) : _pImpl(nullptr)
    {
      int dummy[] = { 0, (addViewNode(views.GetViewNode()), 0)... };
      static_cast<void>(dummy);
    }
    ~Otherwise();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    mutable Impl* _pImpl;
    void addViewNode(std::shared_ptr<ViewNode> viewNode);
  };

  namespace discover {
    namespace by_view {
      namespace conditional {
        using zui::p::IfTrue;
        using zui::p::IfFalse;
        using zui::p::When;
        using zui::p::Otherwise;
      }
    }
  }

} // namespace p

}

