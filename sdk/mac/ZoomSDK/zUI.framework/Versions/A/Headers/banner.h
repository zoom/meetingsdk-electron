/**
 * @file banner.h
 * @brief Banner component for prominent messages
 * 
 * Provides banner functionality for displaying important information.
 */

#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class Banner
	 * @brief A prominent message component for important information.
	 * @ingroup controls_feedback
	 */
	class ZUI_API Banner : public View
	{
	public:
		enum class Sentiments
		{
			kInformation,
			kSuccess,
			kWarning,
			kError,
		};

		explicit Banner(const Bind<std::string>& message);

		virtual ~Banner() = default;

		Banner& sentiment(Sentiments sentiment);

		Banner& sentimentInformation();
		Banner& sentimentSuccess();
		Banner& sentimentWarning();
		Banner& sentimentError();

		Banner& label(const Bind<std::string>& label);

		Banner& closeButton(std::function<void()> callback);
	};

namespace p
{

  class ZUI_API bannerSentiment : public PipeModifier
  {
  public:
    explicit bannerSentiment(Banner::Sentiments sentiment);
    ~bannerSentiment();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerSentimentInformation : public PipeModifier
  {
  public:
    bannerSentimentInformation();
    ~bannerSentimentInformation();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerSentimentSuccess : public PipeModifier
  {
  public:
    bannerSentimentSuccess();
    ~bannerSentimentSuccess();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerSentimentWarning : public PipeModifier
  {
  public:
    bannerSentimentWarning();
    ~bannerSentimentWarning();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerSentimentError : public PipeModifier
  {
  public:
    bannerSentimentError();
    ~bannerSentimentError();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerCloseButton : public PipeModifier
  {
  public:
    explicit bannerCloseButton(std::function<void()> callback);
    ~bannerCloseButton();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API bannerLabel : public PipeModifier
  {
  public:
    explicit bannerLabel(const Bind<std::string>& label);
    ~bannerLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace banner {
        using zui::p::bannerSentiment;
        using zui::p::bannerSentimentInformation;
        using zui::p::bannerSentimentSuccess;
        using zui::p::bannerSentimentWarning;
        using zui::p::bannerSentimentError;
        using zui::p::bannerCloseButton;
        using zui::p::bannerLabel;
      }
    }
  }

} // namespace p

}
