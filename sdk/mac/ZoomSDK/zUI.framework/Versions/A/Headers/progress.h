/**
 * @file progress.h
 * @brief Progress indicator component
 * 
 * Displays progress information to users during long-running operations.
 */

#pragma once

#include "view.h"

namespace zui
{
	/**
	 * @class Progress
	 * @brief A view representing a continuous progress indicator.
	 * @ingroup controls_feedback
	 *
	 * Visual indicator to inform the user of the system status through a continuous bar.
	 * 
	 * @example
	 * @code
	 * // Basic progress bar
	 * Progress()
	 *   .value(0.6f) // 60% progress
	 *   .scale(Progress::Scale::kSmall);
	 * 
	 * // Styled progress bar
	 * Progress()
	 *   .value(0.4f)
	 *   .scale(Progress::Scale::kDefault)
	 *   .defaultColors("#3498db")
	 *   .rangeColors(0.8f, 1.0f, "#27ae60");
	 * @endcode
	 */
	class ZUI_API Progress : public View
	{
	public:
		enum class Scale
		{
			kSmall,  // height = 4.0
			kDefault,  // Default height = 6.0
		};

		/**
		 * @brief Constructs a new Progress object with default settings
		 */
    Progress(const Bind<float>& progressValue);

		/// @brief Virtual destructor of the Progress class.
		virtual ~Progress() = default;

		/**
		 * @brief Sets the scale of the progress bar
		 * @param scale The scale to apply to the progress bar
		 * @return Reference to this Progress for method chaining
		 */
		Progress& scale(const Bind<Progress::Scale>& scale);
		
		/**
		 * @brief Sets the color for the progress bar
		 * @param color The color in hex format (e.g., "#3498db")
		 * @return Reference to this Progress for method chaining
		 */
		Progress& color(const Bind<std::string>& color);
		
		/**
		 * @brief Sets the normal color for the progress bar
		 * @param color The color in hex format (e.g., "#3498db")
		 * @return Reference to this Progress for method chaining
		 * @deprecated Use color() instead
		 */
		[[deprecated("Use color() instead")]]
		Progress& defaultColors(const std::string& color);

		/**
		 * @brief Sets custom color for a specific range of progress
		 * @param start The start value of the range (0.0 to 1.0)
		 * @param end The end value of the range (0.0 to 1.0)
		 * @param color The color for progress within this range
		 * @return Reference to this Progress for method chaining
		 * @deprecated This method is deprecated
		 */
		[[deprecated("Use color() instead")]]
		Progress& rangeColors(float start, float end, const std::string& color);
	};

namespace p
{

  // Progress-specific pipe modifiers

  class ZUI_API progressScale : public PipeModifier
  {
  public:
    explicit progressScale(const Bind<Progress::Scale>& scale);
    ~progressScale();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API progressColor : public PipeModifier
  {
  public:
    explicit progressColor(const Bind<std::string>& color);
    ~progressColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };


#ifdef __LINUX_CLIENT__
	// [[deprecated("Use progressColor() instead")]]
	class ZUI_API progressRangeColors : public PipeModifier
#else
  class [[deprecated("Use progressColor() instead")]] ZUI_API progressRangeColors : public PipeModifier
#endif
  {
  public:
    explicit progressRangeColors(float start, float end, const std::string& color);
    ~progressRangeColors();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };
  
#ifdef __LINUX_CLIENT__
	// [[deprecated("Use progressColor() instead")]]
	class ZUI_API progressDefaultColors : public PipeModifier
#else
  class [[deprecated("Use progressColor() instead")]] ZUI_API progressDefaultColors : public PipeModifier
#endif
  {
  public:
    explicit progressDefaultColors(const std::string& color);
    ~progressDefaultColors();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace progress {
        using zui::p::progressScale;
        using zui::p::progressColor;
      }
    }
  }

}
}
