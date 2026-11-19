#pragma once

#include "zui_data_define.h"
#include <functional>

namespace zui
{
  class View;
  
  /**
   * @class ModifierBundle
   * @brief Base class for bundling multiple pipe modifiers together
   * 
   * ModifierBundle allows you to group multiple pipe modifiers into a single
   * reusable bundle that can be applied via the | operator. This eliminates
   * the need for templates and works with the optimized pipe modifier system.
   */
  class ZUI_API ModifierBundle
  {
  public:
    virtual ~ModifierBundle() = default;
    
    /**
     * @brief Apply this bundle to a view using pipe modifiers
     * @param view The view to modify
     * @return Reference to the modified view
     */
    View& apply(View& view) const
    {
      return applyImpl(view);
    }
      
  protected:
    /**
     * @brief Implementation method that applies pipe modifiers to the view
     * @param view The view to modify
     * @return Reference to the modified view
     * 
     * Override this method to apply your desired pipe modifiers using the | operator.
     * Example:
     * @code
     * View& applyImpl(View& view) const override {
     *   return view | background("red") | padding(16.0f);
     * }
     * @endcode
     */
    virtual View& applyImpl(View& view) const = 0;
  };

  /**
   * @class LambdaModifierBundle
   * @brief A modifier bundle that uses a lambda function to apply modifications
   */
  class ZUI_API LambdaModifierBundle : public ModifierBundle
  {
  public:
    /**
     * @brief Constructor that takes a lambda function
     * @param func Lambda that takes a View& and returns View&
     */
    explicit LambdaModifierBundle(std::function<View&(View&)> func) : func_(std::move(func)) {}
      
  protected:
    View& applyImpl(View& view) const override
    {
      return func_(view);
    }
      
  private:
    std::function<View&(View&)> func_;
  };

  /**
   * @brief Creates a lambda-based modifier bundle
   * @param func Lambda function that applies modifiers to a view
   * @return LambdaModifierBundle instance
   * 
   * Example usage:
   * @code
   * auto exampleStyle = createBundle([](View& view) -> View& {
   *   return view | background("white") | padding(16.0f);
   * });
   * @endcode
   */
  inline LambdaModifierBundle createBundle(std::function<View&(View&)> func)
  {
    return LambdaModifierBundle(std::move(func));
  }
  
/*  Example class bundle creation:
 
  class ZUI_API TextViewStyleExample : public ModifierBundle
  {
  protected:
    View& applyImpl(View& view) const override
    {
      return view
      | p::textBodyLarge()
      | p::textColor(colorRed)
      | p::textWrap()
      | p::background(fillColorBlue)
      | p::padding(16.0f);
    }
  };
*/

/*  Example inline bundle creation using lambda:

  inline auto createButtonStyleExample()
  {
    return createBundle([](View& view) -> View& {
      return view
      | p::background(fillColorBlue)
      | p::padding(12.0f)
      | p::textColor(colorWhite);
    });
  }
*/

}
