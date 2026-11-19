#pragma once

#include <memory>
#include "view.h"
#include "zui_data_define.h"

namespace zui
{

	/**
	 * @class Caption
	 * @ingroup controls_typography
	 * @brief A view component that displays captioned content with optional translation.
	 * 
	 * Caption components are used to provide text representation of audio content, 
	 * making it accessible to users who are deaf or hard of hearing. Features include:
	 * - Speaker avatar display
	 * - Primary caption text
	 * - Optional translation text
	 * - Customizable text sizes and colors
	 * 
	 * @example
	 * @code
	 * // Basic caption
	 * Caption()
	 *   .avatar("user_avatar.jpg")
	 *   .captionText("Hello, welcome to the meeting.")
	 *   .captionColor("#333333");
	 * 
	 * // Caption with translation
	 * Caption()
	 *   .avatar("user_avatar.jpg")
	 *   .captionText("Bonjour, bienvenue à la réunion.")
	 *   .translationText("Hello, welcome to the meeting.")
	 *   .translationColor("#666666");
	 * @endcode
	 */
	class ZUI_API Caption
		: public View
	{
	public:
		/**
		 * @brief Constructs a new Caption object
		 */
		explicit Caption();

		/// @brief Virtual destructor
		virtual ~Caption() = default;

		/**
		 * @brief Sets the speaker's avatar image
		 * @param avatar Path to the avatar image
		 * @ingroup Caption
		 * @return Reference to this caption for method chaining
		 */
		Caption& avatar(const Bind<std::string>& avatar);
		
		/**
		 * @brief Sets the size of the avatar
		 * @param size Size in pixels
		 * @return Reference to this caption for method chaining
		 */
		Caption& avatarSize(const Bind<float>& size);

		/**
		 * @brief Sets the caption text
		 * @param text The caption text to display
		 * @return Reference to this caption for method chaining
		 */
		Caption& captionText(const Bind<std::string>& text);
		
		/**
		 * @brief Sets the font size of the caption text
		 * @param size Font size in pixels
		 * @return Reference to this caption for method chaining
		 */
		Caption& captionSize(const Bind<float>& size);
		
		/**
		 * @brief Sets the color of the caption text
		 * @param color Color in hex format (e.g., "#333333")
		 * @return Reference to this caption for method chaining
		 */
		Caption& captionColor(const Bind<std::string>& color);

		/**
		 * @brief Sets the translation text
		 * @param translation The translated text to display below the caption
		 * @return Reference to this caption for method chaining
		 */
		Caption& translation(const Bind<std::string>& translation);

		/**
		 * @brief Sets the font size of the translation text
		 * @param translationSize Font size in pixels for the translation text
		 * @return Reference to this caption for method chaining
		 */
		Caption& translationSize(const Bind<float>& translationSize);

		/**
		 * @brief Sets the color of the translation text
		 * @param translationColor Color in hex format for the translation text
		 * @return Reference to this caption for method chaining
		 */
		Caption& translationColor(const Bind<std::string>& translationColor);

		/**
		 * @brief Sets the background color of the caption component
		 * @param backgroundColor Background color in hex format
		 * @return Reference to this caption for method chaining
		 */
		Caption& backgroundColor(const Bind<std::string>& backgroundColor);

		/**
		 * @brief Sets the font type/family for the caption text
		 * @param fontType The font family name or type identifier
		 * @return Reference to this caption for method chaining
		 */
		Caption& fontType(const Bind<std::string>& fontType);

	};

namespace p
{

  // Caption-specific pipe modifiers
  class ZUI_API captionAvatar : public PipeModifier
  {
  public:
    explicit captionAvatar(const Bind<std::string>& avatar);
    ~captionAvatar();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionAvatarSize : public PipeModifier
  {
  public:
    explicit captionAvatarSize(const Bind<float>& size);
    ~captionAvatarSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionText : public PipeModifier
  {
  public:
    explicit captionText(const Bind<std::string>& text);
    ~captionText();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionSize : public PipeModifier
  {
  public:
    explicit captionSize(const Bind<float>& size);
    ~captionSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionColor : public PipeModifier
  {
  public:
    explicit captionColor(const Bind<std::string>& color);
    ~captionColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionTranslation : public PipeModifier
  {
  public:
    explicit captionTranslation(const Bind<std::string>& translation);
    ~captionTranslation();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionTranslationSize : public PipeModifier
  {
  public:
    explicit captionTranslationSize(const Bind<float>& translationSize);
    ~captionTranslationSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionTranslationColor : public PipeModifier
  {
  public:
    explicit captionTranslationColor(const Bind<std::string>& translationColor);
    ~captionTranslationColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionBackgroundColor : public PipeModifier
  {
  public:
    explicit captionBackgroundColor(const Bind<std::string>& backgroundColor);
    ~captionBackgroundColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API captionFontType : public PipeModifier
  {
  public:
    explicit captionFontType(const Bind<std::string>& fontType);
    ~captionFontType();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace caption {
        using zui::p::captionAvatar;
        using zui::p::captionAvatarSize;
        using zui::p::captionText;
        using zui::p::captionSize;
        using zui::p::captionColor;
        using zui::p::captionTranslation;
        using zui::p::captionTranslationSize;
        using zui::p::captionTranslationColor;
        using zui::p::captionBackgroundColor;
        using zui::p::captionFontType;
      }
    }
  }

} // namespace p

}
