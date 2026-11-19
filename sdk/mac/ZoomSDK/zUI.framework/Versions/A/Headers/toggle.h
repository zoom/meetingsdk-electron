/**
 * @file toggle.h
 * @brief Toggle switch control component
 * 
 * Provides binary switch functionality for enabling/disabling features.
 */

#pragma once

#include "view.h"

namespace zui
{
	/**
	 * @class Toggle
	 * @brief A binary switch control for enabling/disabling features or settings.
	 * @ingroup controls_input
	 * 
	 * The Toggle component provides an intuitive on/off switch following Prism design
	 * guidelines. It's commonly used in settings panels, forms, and configuration
	 * interfaces where users need to enable or disable specific features.
	 * 
	 * **Key Features:**
	 * - Clear visual state indication (on/off)
	 * - Smooth animations and transitions
	 * - Keyboard and mouse interaction support
	 * - Reactive state binding
	 * - Accessibility compliance
	 * - Multiple sizes for different contexts
	 * 
	 * **Common Usage Patterns:**
	 * 
	 * @code{.cpp}
	 * // Settings panel toggle
	 * State<bool> darkModeEnabled = false;
	 * 
	 * HorizontalStack{
	 *     Text("Dark Mode")
	 *         .body(),
	 *     
	 *     Spacer(),
	 *     
	 *     Toggle(darkModeEnabled)
	 *         .onChange([this](bool enabled) {
	 *             applyTheme(enabled ? Theme::Dark : Theme::Light);
	 *         })
	 * }
	 * 
	 * // Compact toggle for lists
	 * Toggle(_isNotificationEnabled)
	 *     .size(Toggle::Size::kSmall)
	 *     .onChange([this](bool enabled) {
	 *         updateNotificationSettings(enabled);
	 *     });
	 * 
	 * // Disabled toggle
	 * Toggle(_isPremiumFeature)
	 *     .enabled(_userHasPremium)
	 *     .onChange([this](bool enabled) {
	 *         if (_userHasPremium) {
	 *             enablePremiumFeature(enabled);
	 *         }
	 *     });
	 * @endcode
	 * 
	 * @see @ref form_components "Form Components"
	 * @see @ref checkbox "Checkbox" for multi-option selections
	 * @see @ref radio_button "RadioButton" for exclusive choices
	 */
	class ZUI_API Toggle
		: public View
	{
	public:
		/**
		 * @enum Size
		 * @brief Defines the available sizes for the toggle switch
		 */
		enum class Size
		{
			kSmall,   ///< Small toggle switch for compact layouts
			kMedium   ///< Medium toggle switch (default size)
		};

		/// @brief Constructs a new Toggle object with default settings
		Toggle();

		/// @brief Virtual destructor
		virtual ~Toggle() = default;
		/**
		 * @brief Sets the on/off state of the toggle
		 * @param on True for on state, false for off state
		 * @return Reference to this toggle for method chaining
		 */
		Toggle& on(const Bind<bool>& on);

		/**
		 * @brief Sets the size of the toggle switch
		 * @param size The size to apply to the toggle
		 * @return Reference to this toggle for method chaining
		 */
		Toggle& toggleSize(const Bind<Size>& size);

	};

namespace p
{

  class ZUI_API toggleOn : public PipeModifier
  {
  public:
    explicit toggleOn(const Bind<bool>& on);
    ~toggleOn();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toggleSize : public PipeModifier
  {
  public:
    explicit toggleSize(const Bind<Toggle::Size>& size);
    ~toggleSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace toggle {
        using zui::p::toggleOn;
        using zui::p::toggleSize;
      }
    }
  }

}

}
