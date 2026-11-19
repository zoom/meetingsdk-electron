/**
 * @file loading.h
 * @brief Loading spinner component
 * 
 * Provides loading spinner functionality for indicating processing states.
 */

#pragma once

#include <memory>
#include "view.h"
#include "container.h"

namespace zui
{
	/**
	 * @class Loading
	 * @brief A view component that displays a loading spinner indicator.
	 * @ingroup controls_feedback
	 * 
	 * The Loading component provides a visual indicator to convey that the system
	 * is processing or loading content. It supports:
	 * - Multiple sizes (small, medium, large)
	 * - Customizable appearance
	 * - Easy integration into any view hierarchy
	 * 
	 * @example
	 * @code
	 * // Large loading spinner for main content areas
	 * Loading()
	 *   .size(Loading::Size::kLarge);
	 * 
	 * // Small loading spinner for buttons or compact areas
	 * Loading()
	 *   .size(Loading::Size::kSmall);
	 * 
	 * // Medium loading spinner (default)
	 * Loading()
	 *   .size(Loading::Size::kMedium);
	 * 
	 * // Custom loading spinner with icon
	 * Loading()
	 *   .size(Loading::Size::kLarge)
	 *   .icon("custom-spinner.svg");
	 * @endcode
	 */
	class ZUI_API Loading : public View
	{
	public:
		/**
		 * @enum Size
		 * @brief Defines the size of the loading spinner
		 */
		enum class Size
		{
			kLarge,  ///< Large loading spinner for prominent areas
			kMedium, ///< Medium loading spinner (default size)
			kSmall,  ///< Small loading spinner for compact areas
		};

		/// @brief Constructs a new Loading object with default settings
		Loading();

		/// @brief Virtual destructor
		virtual ~Loading() = default;

	/**
	 * @brief Sets the size of the loading spinner
	 * @param size The size to apply to the spinner
	 * @return Reference to this loading component for method chaining
	 */
	Loading& size(const Bind<Size>& size);

	/**
	 * @brief Sets the icon image for the loading spinner
	 * @param icon The path to the icon image file (e.g., "custom-spinner.svg")
	 * @return Reference to this loading component for method chaining
	 * @note If not set, uses the default loading spinner animation
	 */
	Loading& icon(const Bind<std::string>& icon);

	};

namespace p
{

  // Loading-specific pipe modifiers
  class ZUI_API loadingSize : public PipeModifier
  {
  public:
    explicit loadingSize(const Bind<Loading::Size>& size);
    ~loadingSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API loadingIcon : public PipeModifier
  {
  public:
    explicit loadingIcon(const Bind<std::string>& icon);
    ~loadingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace loading {
        using zui::p::loadingSize;
        using zui::p::loadingIcon;
      }
    }
  }

} // namespace p

}
