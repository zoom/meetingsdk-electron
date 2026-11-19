/**
 * @file slider.h
 * @brief Slider control component
 * 
 * Provides range selection functionality with continuous value input.
 */

#pragma once

#include "view.h"

namespace zui
{
	/**
	 * @class Slider
	 * @brief A view component that allows users to select values from a continuous range.
	 * @ingroup controls_input
	 * 
	 * The Slider component provides an interactive control for selecting numeric values
	 * within a specified range. It supports:
	 * - Customizable value range (minimum and maximum)
	 * - Step increments for discrete value selection
	 * - Optional step indicators
	 * - Tooltip display showing current value
	 * - Value change event handling
	 * - Click event handling
	 * 
	 * @example
	 * @code
	 * // Basic volume slider
	 * Slider()
	 *   .range(0.0f, 100.0f)
	 *   .value(75.0f)
	 *   .step(1.0f)
	 *   .showToolTip(true)
	 *   .onValueChanged([](float newValue) {
	 *     setVolume(newValue);
	 *   });
	 * 
	 * // Discrete slider with step indicators
	 * Slider()
	 *   .range(1.0f, 10.0f)
	 *   .step(1.0f)
	 *   .showStep(true)
	 *   .value(5.0f);
	 * @endcode
	 */
	class ZUI_API Slider : public View
	{
	public:
		/// @brief Constructs a new Slider object with default settings
		Slider(const Bind<float>& value);

		/// @brief Virtual destructor
		virtual ~Slider() = default;

		/**
		 * @brief Sets the valid range for the slider values
		 * @param from The minimum value of the slider
		 * @param to The maximum value of the slider
		 * @return Reference to this slider for method chaining
		 */
		Slider& range(const Bind<float>& from, const Bind<float>& to);

		/**
		 * @brief Sets the step increment for discrete value selection
		 * @param step The step value for incrementing/decrementing
		 * @return Reference to this slider for method chaining
		 */
		Slider& step(const Bind<float>& step);

		/**
		 * @brief Sets whether to show step indicators on the slider track
		 * @param show True to show step indicators, false to hide them
		 * @return Reference to this slider for method chaining
		 */
		Slider& showStep(const Bind<bool>& show);

		/**
		 * @brief Sets whether to show a tooltip displaying the current value
		 * @param showToolTip True to show tooltip, false to hide it
		 * @return Reference to this slider for method chaining
		 */
		Slider& showToolTip(const Bind<bool>& showToolTip);

		/**
		 * @brief Sets the callback function for value change events
		 * @param func The function to call when the slider value changes
		 * @return Reference to this slider for method chaining
		 */
		Slider& onValueChanged(const std::function<void(float)>& func);
	};

namespace p
{

  class ZUI_API sliderRange : public PipeModifier
  {
  public:
    explicit sliderRange(const Bind<float>& from, const Bind<float>& to);
    ~sliderRange();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API sliderStep : public PipeModifier
  {
  public:
    explicit sliderStep(const Bind<float>& step);
    ~sliderStep();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API sliderShowStep : public PipeModifier
  {
  public:
    explicit sliderShowStep(const Bind<bool>& show);
    ~sliderShowStep();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API sliderShowToolTip : public PipeModifier
  {
  public:
    explicit sliderShowToolTip(const Bind<bool>& showToolTip);
    ~sliderShowToolTip();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API sliderOnValueChanged : public PipeModifier
  {
  public:
    explicit sliderOnValueChanged(const std::function<void(float)>& func);
    ~sliderOnValueChanged();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace slider {
        using zui::p::sliderRange;
        using zui::p::sliderStep;
        using zui::p::sliderShowStep;
        using zui::p::sliderShowToolTip;
        using zui::p::sliderOnValueChanged;
      }
    }
  }

}

}
