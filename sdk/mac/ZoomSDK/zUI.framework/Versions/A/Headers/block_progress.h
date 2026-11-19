/**
 * @file block_progress.h
 * @brief Block progress indicator component
 * 
 * Provides block-style progress visualization for user feedback.
 */

#pragma once

#include <memory>
#include "view.h"

namespace zui
{
	/**
	 * @class BlockProgress
	 * @brief A view component that displays progress as a series of blocks.
	 * @ingroup controls_feedback
	 * 
	 * The BlockProgress component visualizes progress through a sequence of 
	 * blocks that fill based on the current value. It supports:
	 * - Customizable number of blocks
	 * - Adjustable block dimensions and appearance
	 * - Color customization for different progress ranges
	 * - Smooth value binding for reactive updates
	 * 
	 * @example
	 * @code
	 * // Basic block progress bar
	 * BlockProgress()
	 *   .blockCount(5)
	 *   .blockWidth(20)
	 *   .blockHeight(10)
	 *   .value(0.6f); // 60% progress
	 * 
	 * // Styled block progress
	 * BlockProgress()
	 *   .blockCount(10)
	 *   .blockRadius(4)
	 *   .defaultColors("#3498db", "#e0e0e0")
	 *   .rangeColors(0.8f, 1.0f, "#27ae60", "#e0e0e0");
	 * @endcode
	 */
	class ZUI_API BlockProgress : public View
	{
	public:
		/**
		 * @brief Constructs a new BlockProgress object with default settings
		 */
		BlockProgress(const Bind<float>& value);

		/**
		 * @brief Virtual destructor
		 */
		virtual ~BlockProgress() = default;

		/**
		 * @brief Sets the number of blocks in the progress indicator
		 * @param count The number of blocks to display
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& blockCount(int count);

		/**
		 * @brief Sets the width of each block
		 * @param width The width of each block in pixels
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& blockWidth(float width);

		/**
		 * @brief Sets the height of each block
		 * @param height The height of each block in pixels
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& blockHeight(float height);

		/**
		 * @brief Sets the stroke width around each block
		 * @param stroke The stroke width in pixels
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& blockStroke(float stroke);

		/**
		 * @brief Sets the corner radius of each block
		 * @param radius The corner radius in pixels
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& blockRadius(float radius);

		/**
		 * @brief Sets the default colors for blocks and strokes
		 * @param blockColor The color of the blocks
		 * @param strokeColor The color of the block strokes
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& defaultColors(const std::string& blockColor, const std::string& strokeColor);

		/**
		 * @brief Sets custom colors for a specific range of progress
		 * @param start The start value of the range (0.0 to 1.0)
		 * @param end The end value of the range (0.0 to 1.0)
		 * @param blockColor The color of blocks within this range
		 * @param strokeColor The color of block strokes within this range
		 * @return Reference to this BlockProgress for method chaining
		 */
		BlockProgress& rangeColors(float start, float end, const std::string& blockColor, const std::string& strokeColor);
	};

namespace p
{

  // BlockProgress-specific pipe modifiers
  class ZUI_API blockCount : public PipeModifier
  {
  public:
    explicit blockCount(int count);
    ~blockCount();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockWidth : public PipeModifier
  {
  public:
    explicit blockWidth(float width);
    ~blockWidth();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockHeight : public PipeModifier
  {
  public:
    explicit blockHeight(float height);
    ~blockHeight();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockStroke : public PipeModifier
  {
  public:
    explicit blockStroke(float stroke);
    ~blockStroke();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockRadius : public PipeModifier
  {
  public:
    explicit blockRadius(float radius);
    ~blockRadius();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockRangeColors : public PipeModifier
  {
  public:
    explicit blockRangeColors(float start, float end, const std::string& blockColor, const std::string& strokeColor);
    ~blockRangeColors();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API blockDefaultColors : public PipeModifier
  {
  public:
    explicit blockDefaultColors(const std::string& blockColor, const std::string& strokeColor);
    ~blockDefaultColors();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace block_progress {
        using zui::p::blockCount;
        using zui::p::blockWidth;
        using zui::p::blockHeight;
        using zui::p::blockStroke;
        using zui::p::blockRadius;
        using zui::p::blockRangeColors;
        using zui::p::blockDefaultColors;
      }
    }
  }

} // namespace p

}
