/**
 * @file image.h
 * @brief Image component for displaying images and icons
 * 
 * Provides image and icon display functionality with styling options.
 */

#pragma once

#include <memory>
#include "view.h"
#include "zui_data_define.h"
#include "icon_name_hints.h"

namespace zui
{
	/**
	 * @class Image
	 * @brief A view component for displaying images and icons.
	 * @ingroup controls_media
	 * 
	 * The Image component provides functionality for displaying various types of
	 * visual content including images and icons. It supports:
	 * - Image file loading from paths
	 * - Icon display using icon names
	 * - Alpha/transparency control
	 * - Rotation transformations
	 * - Corner radius styling
	 * - Content mode configuration
	 * - Color tinting for icons
	 * 
	 * @example
	 * @code
	 * // Basic image display
	 * Image("path/to/image.jpg")
	 *   .cornerRadius(8.0f)
	 *   .alpha(0.9f);
	 *
	 * // Icon tinted by Prism token
	 * Image("settings-icon")
	 *   .tokenColor(textStrongerNeutral)
	 *   .rotate(45.0f);
	 *
	 * // Icon tinted by web-delivered hex
	 * Image("settings-icon")
	 *   .hexColor("#FF2A2B2D", "#FFF7F9FA");
	 * 
	 * // Fit content mode
	 * Image("large-photo.jpg")
	 *   .contentMode(Image::ContentMode::Fit);
	 * @endcode
	 */
	class ZUI_API Image : public View
	{
	public:

		/**
		 * @enum ContentMode
		 * @brief Defines how the image content should be displayed within its bounds
		 */
		enum class ContentMode
		{
			Fill, ///< Scale image to fill the entire bounds, may crop content
			Fit   ///< Scale image to fit within bounds while maintaining aspect ratio
		};

		/**
		 * @brief Constructs an Image with the specified image path
		 * @param image The path to the image file to display
		 */
		explicit Image(const Bind<std::string>& image);

		/// @brief Virtual destructor
		virtual ~Image() = default;

		/// @brief Builds the view node for this image
		std::shared_ptr<ViewNode> BuildImage();

		/**
		 * @brief Sets the alpha/transparency level of the image
		 * @param alpha The alpha value (0.0 = fully transparent, 1.0 = fully opaque)
		 * @return Reference to this image for method chaining
		 */
		Image& alpha(Bind<float> alpha);

		/**
		 * @brief Sets the rotation angle of the image
		 * @param rotate The rotation angle in degrees
		 * @return Reference to this image for method chaining
		 */
		Image& rotate(Bind<float> rotate);

		/**
		 * @brief Sets the corner radius for rounded corners
		 * @param cornerRadius The corner radius in pixels
		 * @return Reference to this image for method chaining
		 */
		Image& cornerRadius(const Bind<float>& cornerRadius);

		/**
		 * @brief Sets the content mode for how the image is displayed
		 * @param contentMode The content mode to apply
		 * @return Reference to this image for method chaining
		 * @note Currently unused in implementation
		 */
		Image& contentMode(ContentMode contentMode);

		/**
		 * @brief Applies link color tinting to the image
		 * @return Reference to this image for method chaining
		 * @note Typically used for icons to match link styling
		 */
		Image& linkColor();

		/**
		 * @brief Tints a single-color SVG with explicit light and/or dark hex colors
		 * @param lightColor Hex color for light mode ("#RRGGBB" or "#AARRGGBB"). Empty skips light tint.
		 * @param darkColor Hex color for dark mode ("#RRGGBB" or "#AARRGGBB"). Empty skips dark tint.
		 * @return Reference to this image for method chaining
		 */
		Image& hexColor(const Bind<std::string>& lightColor, const Bind<std::string>& darkColor);

		/**
		 * @brief Tints a single-color SVG with a Prism color token
		 * @param token Token such as textStrongerNeutral or "text/text-stronger-neutral".
		 *              Light and dark values come from the theme.
		 * @return Reference to this image for method chaining
		 */
		Image& tokenColor(const Bind<std::string>& token);

		/// @brief Default path for icon resources
		static const std::string DEFAULT_ICON_PATH;

		/// @brief Prefix used for icon resource names
		static const std::string ICON_PREFIX;

		/// @brief Prefix used for icon color resource names
		static const std::string COLOR_PREFIX;

		/// @brief Standard size for icons in pixels
		static const float STANDARD_ICON_SIZE;

		/// @todo Add method to set the aspect ratio of the image
		/// @todo Add method to clip the image
	};

namespace p
{

  // Image-specific pipe modifiers
  class ZUI_API imageAlpha : public PipeModifier
  {
  public:
    explicit imageAlpha(const Bind<float>& alpha);
    ~imageAlpha();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API imageRotate : public PipeModifier
  {
  public:
    explicit imageRotate(const Bind<float>& rotate);
    ~imageRotate();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API imageCornerRadius : public PipeModifier
  {
  public:
    explicit imageCornerRadius(const Bind<float>& cornerRadius);
    ~imageCornerRadius();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API imageHexColor : public PipeModifier
  {
  public:
    imageHexColor(const Bind<std::string>& lightColor, const Bind<std::string>& darkColor);
    ~imageHexColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API imageTokenColor : public PipeModifier
  {
  public:
    explicit imageTokenColor(const Bind<std::string>& token);
    ~imageTokenColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace image {
        using zui::p::imageAlpha;
        using zui::p::imageRotate;
        using zui::p::imageCornerRadius;
        using zui::p::imageHexColor;
        using zui::p::imageTokenColor;
      }
    }
  }

} // namespace p

}
