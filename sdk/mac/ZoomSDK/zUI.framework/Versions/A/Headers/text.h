/**
 * @file text.h
 * @brief Text component for displaying styled text content
 * 
 * Provides text display functionality with Prism typography support.
 */

#pragma once

#include "view.h"

namespace zui
{
  /**
   * @class Text
   * @ingroup controls_typography
   * @brief A view component for displaying styled text content.
   *
   * The Text component is the primary way to display text in zUI applications.
   * It follows Zoom's Prism design system typography guidelines and provides
   * convenient methods for common text styling patterns.
   *
   * **Key Features:**
   * - Prism typography styles (display, body, subtitle, caption, etc.)
   * - Reactive text content using @ref zui::Bind "Bind<std::string>"
   * - Flexible text wrapping and truncation
   * - Click event support for interactive text
   * - Seamless color integration with Prism color tokens
   *
   * **Common Usage Patterns:**
   *
   * @code{.cpp}
   * // Page titles and headers
   * Text("Settings")
   *     .display1()
   *     .color(textPrimary);
   *
   * // Body content with automatic wrapping
   * Text("This is the main content of your view that may span multiple lines")
   *     .body()
   *     .wrap()
   *     .color(textPrimary);
   *
   * // Secondary information
   * Text("Last updated 2 minutes ago")
   *     .caption()
   *     .color(textSecondary);
   *
   * // Interactive text (clickable)
   * Text("Learn more")
   *     .body()
   *     .color(colorPrimary)
   *     .onClick([](){
   *         // handle click
   *     });
   *
   * // Reactive content
   * State<std::string> username = "John";
   * Text(username.bind([](const std::string& name) {
   *     return "Hello, " + name + "!";
   * }))
   *     .body();
   * @endcode
   *
   * @see zui::Bind for data binding
   */
  class ZUI_API Text : public View
  {
  public:
    /**
     * @enum Typography
     * @brief Defines the typography styles available for text
     * @todo Move the enum out of the class for better reusability
     */
    enum class Typography
    {
      kDisplay,           ///< Display text style
      kHeadline1,         ///< Headline 1 text style
      kHeadline2,         ///< Headline 2 text style
      kTitle1Emphasis,    ///< Title 1 emphasis text style
      kTitle1,            ///< Title 1 text style
      kTitle2Emphasis,    ///< Title 2 emphasis text style
      kTitle2,            ///< Title 2 text style
      kTitle3Emphasis,    ///< Title 3 emphasis text style
      kTitle3,            ///< Title 3 text style
      kBody1Emphasis,     ///< Body 1 emphasis text style
      kBody1,             ///< Body 1 text style
      kBody2Emphasis,     ///< Body 2 emphasis text style
      kBody2,             ///< Body 2 text style
      kCaptionEmphasis,   ///< Caption emphasis text style
      kCaption,           ///< Caption text style
      kLabel,             ///< Label text style

      kDisplay1,          ///< @deprecated Use kHeadline2 instead
      kDisplay2,          ///< @deprecated Use kTitle1Emphasis instead
      kDisplay3,          ///< @deprecated Use kTitle2Emphasis instead
      kBodyLargeBold,     ///< @deprecated Use kTitle3Emphasis instead
      kBodyLarge,         ///< @deprecated Use kTitle3 instead
      kBodyBold,          ///< @deprecated Use kBody1Emphasis instead
      kBody,              ///< @deprecated Use kBody1 instead
      kSubtitleBold,      ///< @deprecated Use kBody2Emphasis instead
      kSubtitle           ///< @deprecated Use kBody2 instead
    };

    /**
     * @enum WrapMode
     * @brief Defines how text wrapping should behave
     */
    enum class WrapMode
    {
      kNoWrap,        ///< Text does not wrap and may overflow
      kWordWrap,      ///< Text wraps at word boundaries
      kWrapAnyWhere   ///< Text can wrap anywhere, including within words
    };

    /**
     * @enum LinearGradientMode
     * @brief Defines how to create linear gradient color
     */
    enum class LinearGradientMode
    {
      kHorizontal,      ///< Horizontal linear gradient
      kVertical,        ///< Vertical linear gradient
      kForwardDiagonal, ///< Diagonal(LeftTop -> RightBottom) linear gradient
      kBackwardDiagonal ///< Diagonal(RightTop -> LeftBottom) linear gradient
    };

    /**
     * @struct GradientStop
     * @brief Defines the color and its relative position in a gradient
     * @param color The name or value of the color
     * @param position The relative position of the color in a gradient(related to gradient mode, 0.0f - 1.0f)
     */
    struct GradientStop
    {
      std::string color;
      float position = 0.0f;

      GradientStop() {}
      GradientStop(const std::string& colorName, float colorPosition)
        : color(colorName), position(colorPosition) {}
      bool operator==(const GradientStop& other) const {
        return color == other.color && position == other.position;
      }
    };

    /**
     * @brief Constructs a Text object with the given text content
     * @param text The text content to display
     * @todo Remove noNeedAddParent parameter if it's no longer needed
     */
    explicit Text(const Bind<std::string>& text);

    /// @brief Virtual destructor
    virtual ~Text() = default;
    
    std::shared_ptr<ViewNode> BuildText();
    /**
     * @brief Sets the typography style of the text
     * @param typography The typography style to apply
     * @return Reference to this text for method chaining
     */
    Text& typography(const Bind<Text::Typography>& typography);

    /**
     * @brief Sets the text color using a string color value
     * @param color The color value (e.g., "#FF0000", "red")
     * @return Reference to this text for method chaining
     */
    Text& color(const Bind<std::string>& color);

    /**
     * @brief Sets the text color using a C-string color value
     * @param color The color value as a C-string
     * @return Reference to this text for method chaining
     */
    Text& color(const char* color);

    /**
     * @brief Sets the text linear gradient color using string color value
     * @param gradient 
     * @param param mode Linear gradient color mode
     * @return Reference to this text for method chaining
     */
    Text& linearGradientColor(const Bind<std::vector<GradientStop>>& gradient, LinearGradientMode mode);

    /**
     * @brief Sets the text linear gradient color using C-string color value from starting to ending
     * @param startColor The color value in linear starting position
     * @param endColor The color value in linear ending position
     * @param mode Linear gradient color mode
     * @return Reference to this text for method chaining
     */
    Text& linearGradientColor(const char* startColor, const char* endColor, LinearGradientMode mode);

    /**
     * @brief Sets the text wrapping mode
     * @param mode The wrap mode to apply
     * @return Reference to this text for method chaining
     */
    Text& wrapMode(const Bind<WrapMode>& mode);

    /**
     * @brief Sets the callback function for click events
     * @param callback The function to call when the text is clicked
     * @return Reference to this text for method chaining
     */
    Text& onClick(std::function<void()> callback);

    /**
     * @brief Sets the text align center when word wrapping
     * @return Reference to this text for method chaining
     */
    Text& multilineCenterAlign();

    // Typography convenience methods (Desktop Prism 2.0)
    /**
     * @brief Sets the text to display typography style
     * @return Reference to this text for method chaining
     */
    Text& display();
    
    /**
     * @brief Sets the text to headline1 typography style
     * @return Reference to this text for method chaining
     */
    Text& headline1();
    
    /**
     * @brief Sets the text to headline2 typography style
     * @return Reference to this text for method chaining
     */
    Text& headline2();
    
    /**
     * @brief Sets the text to title1Emphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& title1Emphasis();
    
    /**
     * @brief Sets the text to title1 typography style
     * @return Reference to this text for method chaining
     */
    Text& title1();
    
    /**
     * @brief Sets the text to title2Emphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& title2Emphasis();
    
    /**
     * @brief Sets the text to title2 typography style
     * @return Reference to this text for method chaining
     */
    Text& title2();
    
    /**
     * @brief Sets the text to title3Emphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& title3Emphasis();
    
    /**
     * @brief Sets the text to title3 typography style
     * @return Reference to this text for method chaining
     */
    Text& title3();
    
    /**
     * @brief Sets the text to body1Emphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& body1Emphasis();
    
    /**
     * @brief Sets the text to body1 typography style
     * @return Reference to this text for method chaining
     */
    Text& body1();
    
    /**
     * @brief Sets the text to body2Emphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& body2Emphasis();
    
    /**
     * @brief Sets the text to body2 typography style
     * @return Reference to this text for method chaining
     */
    Text& body2();
    
    /**
     * @brief Sets the text to captionEmphasis typography style
     * @return Reference to this text for method chaining
     */
    Text& captionEmphasis();
    
    /**
     * @brief Sets the text to caption typography style
     * @return Reference to this text for method chaining
     */
    Text& caption();
    
    /**
     * @brief Sets the text to label typography style
     * @return Reference to this text for method chaining
     */
    Text& label();

    // Typography convenience methods (Legacy Prism, backward compatibility)
    /**
     * @brief Sets the text to display1 typography style
     * @deprecated Use headline2() instead.
     * @return Reference to this text for method chaining
     */
    Text& display1();
    /**
     * @brief Sets the text to display2 typography style
     * @deprecated Use title1Emphasis() instead.
     * @return Reference to this text for method chaining
     */
    Text& display2();
    /**
     * @brief Sets the text to display3 typography style
     * @deprecated Use title2Emphasis() instead.
     * @return Reference to this text for method chaining
     */
    Text& display3();
    /**
     * @brief Sets the text to bodyLargeBold typography style
     * @deprecated Use title3Emphasis() instead.
     * @return Reference to this text for method chaining
     */
    Text& bodyLargeBold();
    /**
     * @brief Sets the text to bodyLarge typography style
     * @deprecated Use title3() instead.
     * @return Reference to this text for method chaining
     */
    Text& bodyLarge();
    /**
     * @brief Sets the text to bodyBold typography style
     * @deprecated Use body1Emphasis() instead.
     * @return Reference to this text for method chaining
     */
    Text& bodyBold();
    /**
     * @brief Sets the text to body typography style
     * @deprecated Use body1() instead.
     * @return Reference to this text for method chaining
     */
    Text& body();
    /**
     * @brief Sets the text to subtitleBold typography style
     * @deprecated Use body2Emphasis() instead.
     * @return Reference to this text for method chaining
     */
    Text& subtitleBold();
    /**
     * @brief Sets the text to subtitle typography style
     * @deprecated Use body2() instead.
     * @return Reference to this text for method chaining
     */
    Text& subtitle();
    
    // Wrap mode convenience methods
    
    /**
     * @brief Enables text wrapping at word boundaries
     * @return Reference to this text for method chaining
     */
    Text& wrap();
    
    /**
     * @brief Disables text wrapping
     * @return Reference to this text for method chaining
     */
    Text& noWrap();

    /**
     * @brief Sets whether HTML rendering is enabled
     * 
     * When enabled, the text content will be parsed and rendered as HTML.
     * 
     * Supported HTML tags (cross-platform: Windows/Linux/macOS):
     * - Bold: <b>text</b> or <strong>text</strong>
     * - Italic: <i>text</i> or <em>text</em>
     * - Underline: <u>text</u>
     * - Line Break: <br>
     * - Font Color: <font color="#RRGGBB">text</font>
     * - Link: <a href="url">text</a>
     * - Paragraph: <p style="margin-top: 10px; margin-left: 20px;">text</p>
     * - Div: <div style="margin-top: 10px; margin-left: 20px;">text</div>
     * 
     * Note: For <p> and <div>, only 'margin-top' and 'margin-left' styles are consistently supported across all platforms.
     * 
     * @code{.cpp}
     * Text("<b>Bold</b> and <i>italic</i> text")
     *     .body()
     *     .html(true);
     * @endcode
     * 
     * @param enabled True to enable HTML parsing, false for plain text
     * @return Reference to this text for method chaining
     */
    Text& html(const Bind<bool>& enabled);

    bool operator==(const Text& other) const;

protected:
    Text(const Bind<std::string>& text, View::Type viewType, std::function<std::shared_ptr<ViewNode>()> builder);
};

namespace p
{

  // Text-specific pipe modifiers
  class ZUI_API textTypography : public PipeModifier
  {
  public:
    explicit textTypography(const Bind<Text::Typography>& typography);
    ~textTypography();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textColor : public PipeModifier
  {
  public:
    explicit textColor(const Bind<std::string>& color);
    explicit textColor(const char* color);
    ~textColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textWrapMode : public PipeModifier
  {
  public:
    explicit textWrapMode(const Bind<Text::WrapMode>& mode);
    ~textWrapMode();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textLinearGradientColor : public PipeModifier
  {
  public:
    explicit textLinearGradientColor(const Bind<std::vector<Text::GradientStop>>& gradient, Text::LinearGradientMode mode);
    explicit textLinearGradientColor(const char* startColor, const char* endColor, Text::LinearGradientMode mode);
    ~textLinearGradientColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textMultilineCenterAlign : public PipeModifier
  {
  public:
    textMultilineCenterAlign();
    ~textMultilineCenterAlign();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  // Typography convenience modifiers
  class ZUI_API textDisplay : public PipeModifier
  {
  public:
    textDisplay();
    ~textDisplay();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textHeadline1 : public PipeModifier
  {
  public:
    textHeadline1();
    ~textHeadline1();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textHeadline2 : public PipeModifier
  {
  public:
    textHeadline2();
    ~textHeadline2();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle1Emphasis : public PipeModifier
  {
  public:
    textTitle1Emphasis();
    ~textTitle1Emphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle1 : public PipeModifier
  {
  public:
    textTitle1();
    ~textTitle1();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle2Emphasis : public PipeModifier
  {
  public:
    textTitle2Emphasis();
    ~textTitle2Emphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle2 : public PipeModifier
  {
  public:
    textTitle2();
    ~textTitle2();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle3Emphasis : public PipeModifier
  {
  public:
    textTitle3Emphasis();
    ~textTitle3Emphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textTitle3 : public PipeModifier
  {
  public:
    textTitle3();
    ~textTitle3();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBody1Emphasis : public PipeModifier
  {
  public:
    textBody1Emphasis();
    ~textBody1Emphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBody1 : public PipeModifier
  {
  public:
    textBody1();
    ~textBody1();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBody2Emphasis : public PipeModifier
  {
  public:
    textBody2Emphasis();
    ~textBody2Emphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBody2 : public PipeModifier
  {
  public:
    textBody2();
    ~textBody2();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textCaptionEmphasis : public PipeModifier
  {
  public:
    textCaptionEmphasis();
    ~textCaptionEmphasis();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textDisplay1 : public PipeModifier
  {
  public:
    textDisplay1();
    ~textDisplay1();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textDisplay2 : public PipeModifier
  {
  public:
    textDisplay2();
    ~textDisplay2();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textDisplay3 : public PipeModifier
  {
  public:
    textDisplay3();
    ~textDisplay3();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBodyLargeBold : public PipeModifier
  {
  public:
    textBodyLargeBold();
    ~textBodyLargeBold();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBodyLarge : public PipeModifier
  {
  public:
    textBodyLarge();
    ~textBodyLarge();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBodyBold : public PipeModifier
  {
  public:
    textBodyBold();
    ~textBodyBold();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textBody : public PipeModifier
  {
  public:
    textBody();
    ~textBody();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textSubtitleBold : public PipeModifier
  {
  public:
    textSubtitleBold();
    ~textSubtitleBold();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textSubtitle : public PipeModifier
  {
  public:
    textSubtitle();
    ~textSubtitle();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textCaption : public PipeModifier
  {
  public:
    textCaption();
    ~textCaption();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textNoWrap : public PipeModifier
  {
  public:
    textNoWrap();
    ~textNoWrap();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textWrap : public PipeModifier
  {
  public:
    textWrap();
    ~textWrap();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textLabel : public PipeModifier
  {
  public:
    textLabel();
    ~textLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API textHtml : public PipeModifier
  {
  public:
    explicit textHtml(const Bind<bool>& enabled);
    ~textHtml();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace text {
        using zui::p::textTypography;
        using zui::p::textColor;
        using zui::p::textLinearGradientColor;
        using zui::p::textWrapMode;
        using zui::p::textMultilineCenterAlign;
        using zui::p::textDisplay;
        using zui::p::textHeadline1;
        using zui::p::textHeadline2;
        using zui::p::textTitle1Emphasis;
        using zui::p::textTitle1;
        using zui::p::textTitle2Emphasis;
        using zui::p::textTitle2;
        using zui::p::textTitle3Emphasis;
        using zui::p::textTitle3;
        using zui::p::textBody1Emphasis;
        using zui::p::textBody1;
        using zui::p::textBody2Emphasis;
        using zui::p::textBody2;
        using zui::p::textCaptionEmphasis;
        using zui::p::textDisplay1;
        using zui::p::textDisplay2;
        using zui::p::textDisplay3;
        using zui::p::textBodyLargeBold;
        using zui::p::textBodyLarge;
        using zui::p::textBodyBold;
        using zui::p::textBody;
        using zui::p::textSubtitleBold;
        using zui::p::textSubtitle;
        using zui::p::textCaption;
        using zui::p::textNoWrap;
        using zui::p::textWrap;
        using zui::p::textLabel;
        using zui::p::textHtml;
      }
    }
  }

} // namespace p

} // namespace zui
