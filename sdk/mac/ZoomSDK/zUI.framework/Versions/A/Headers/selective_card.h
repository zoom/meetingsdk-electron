/**
 * @file selective_card.h
 * @brief Option control component
 * 
 * Provides option selection functionality for selectable blocks.
 */

#ifndef _ZUI_SELECTIVECARD_H_
#define _ZUI_SELECTIVECARD_H_

#include "view.h"

namespace zui
{

	/**
	 * @class SelectiveCard
	 * @brief A selectable option component for choice selection.
	 * @ingroup controls_input
	 */
	class ZUI_API SelectiveCard : public View
	{
	public:
    explicit SelectiveCard(int value);
		virtual ~SelectiveCard() = default;

    SelectiveCard& normalimage(const Bind<std::string>& image);
    SelectiveCard& selectedimage(const Bind<std::string>& image);
    SelectiveCard& foreimage(const Bind<std::string>& image);

    SelectiveCard& imageSize(float width, float height);

    SelectiveCard& showSelectedFrame(bool enabled);
    SelectiveCard& selectedFrameWidth(float value);
    SelectiveCard& selectedFrameRadius(float value);

    SelectiveCard& groupValue(const Bind<int>& groupValue);

    SelectiveCard& fillImage(const Bind<std::string>& fillImage);
    SelectiveCard& fillColor(const Bind<std::string>& fillColor);
    SelectiveCard& onClick(std::function<bool()> callback);

    SelectiveCard& groupName(const std::string& groupName);
	};

namespace p
{

  // SelectiveCard-specific pipe modifiers
  class ZUI_API selectiveCardNormalImage : public PipeModifier
  {
  public:
    explicit selectiveCardNormalImage(const Bind<std::string>& image);
    ~selectiveCardNormalImage();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardSelectedImage : public PipeModifier
  {
  public:
    explicit selectiveCardSelectedImage(const Bind<std::string>& image);
    ~selectiveCardSelectedImage();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardForeImage : public PipeModifier
  {
  public:
    explicit selectiveCardForeImage(const Bind<std::string>& image);
    ~selectiveCardForeImage();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardImageSize : public PipeModifier
  {
  public:
    explicit selectiveCardImageSize(float width, float height);
    ~selectiveCardImageSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardShowSelectedFrame : public PipeModifier
  {
  public:
    explicit selectiveCardShowSelectedFrame(bool enabled);
    ~selectiveCardShowSelectedFrame();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardSelectedFrameWidth : public PipeModifier
  {
  public:
    explicit selectiveCardSelectedFrameWidth(float value);
    ~selectiveCardSelectedFrameWidth();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardSelectedFrameRadius : public PipeModifier
  {
  public:
    explicit selectiveCardSelectedFrameRadius(float value);
    ~selectiveCardSelectedFrameRadius();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };



  class ZUI_API selectiveCardFillImage : public PipeModifier
  {
  public:
    explicit selectiveCardFillImage(const Bind<std::string>& fillImage);
    ~selectiveCardFillImage();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardFillColor : public PipeModifier
  {
  public:
    explicit selectiveCardFillColor(const Bind<std::string>& fillColor);
    ~selectiveCardFillColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardGroupName : public PipeModifier
  {
  public:
    explicit selectiveCardGroupName(const std::string& groupName);
    ~selectiveCardGroupName();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardOnClick : public PipeModifier
  {
  public:
    explicit selectiveCardOnClick(std::function<bool()> callback);
    ~selectiveCardOnClick();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API selectiveCardGroupValue : public PipeModifier
  {
  public:
    explicit selectiveCardGroupValue(const Bind<int>& groupValue);
    ~selectiveCardGroupValue();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace selectiveCard {
        using zui::p::selectiveCardNormalImage;
        using zui::p::selectiveCardSelectedImage;
        using zui::p::selectiveCardForeImage;
        using zui::p::selectiveCardImageSize;
        using zui::p::selectiveCardShowSelectedFrame;
        using zui::p::selectiveCardSelectedFrameWidth;
        using zui::p::selectiveCardSelectedFrameRadius;
        using zui::p::selectiveCardFillImage;
        using zui::p::selectiveCardFillColor;
        using zui::p::selectiveCardGroupName;
        using zui::p::selectiveCardOnClick;
        using zui::p::selectiveCardGroupValue;
      }
    }
  }

} // namespace p

}

#endif // _ZUI_SELECTIVECARD_H_
