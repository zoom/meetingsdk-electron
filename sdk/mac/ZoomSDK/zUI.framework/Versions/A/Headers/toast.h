/**
 * @file toast.h
 * @brief Toast notification component
 * 
 * Provides toast notification functionality for user feedback.
 */

#ifndef _ZUI_TOAST_H_
#define _ZUI_TOAST_H_

#include "view.h" 

namespace zui
{
	class Link;
	class BasicButton;
	
	/**
	 * @class Toast
	 * @brief A notification component for displaying temporary messages.
	 * @ingroup controls_feedback
	 */
	class ZUI_API Toast : public View
	{
	public:
		enum class Sentiments
		{
			kInformative,
			kSuccess,
			kWarning,
			kDanger
		};

		Toast();
		virtual ~Toast() = default;

		Toast& sentiments(const Bind<Sentiments>& sentiments);
		Toast& sentimentsInformative();
		Toast& sentimentsSuccess();
		Toast& sentimentsWarning();
		Toast& sentimentsDanger();

		Toast& close(const Bind<bool>& visible);
		Toast& label(const Bind<std::string>& label);
		Toast& body(const Bind<std::string>& body);
		Toast& link(Link& link);
		Toast& action(const Bind<std::string>& left, const Bind<std::string>& right);
	};

namespace p
{

  class ZUI_API toastSentiments : public PipeModifier
  {
  public:
    explicit toastSentiments(const Bind<Toast::Sentiments>& sentiments);
    ~toastSentiments();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastSentimentsInformative : public PipeModifier
  {
  public:
    toastSentimentsInformative();
    ~toastSentimentsInformative();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastSentimentsSuccess : public PipeModifier
  {
  public:
    toastSentimentsSuccess();
    ~toastSentimentsSuccess();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastSentimentsWarning : public PipeModifier
  {
  public:
    toastSentimentsWarning();
    ~toastSentimentsWarning();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastSentimentsDanger : public PipeModifier
  {
  public:
    toastSentimentsDanger();
    ~toastSentimentsDanger();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastClose : public PipeModifier
  {
  public:
    explicit toastClose(const Bind<bool>& visible);
    ~toastClose();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastBody : public PipeModifier
  {
  public:
    explicit toastBody(const Bind<std::string>& body);
    ~toastBody();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastLink : public PipeModifier
  {
  public:
    explicit toastLink(const Link& link);
    ~toastLink();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastAction : public PipeModifier
  {
  public:
    explicit toastAction(const Bind<std::string>& left, const Bind<std::string>& right);
    ~toastAction();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API toastLabel : public PipeModifier
  {
  public:
    explicit toastLabel(const Bind<std::string>& label);
    ~toastLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace toast {
        using zui::p::toastSentiments;
        using zui::p::toastSentimentsInformative;
        using zui::p::toastSentimentsSuccess;
        using zui::p::toastSentimentsWarning;
        using zui::p::toastSentimentsDanger;
        using zui::p::toastClose;
        using zui::p::toastBody;
        using zui::p::toastLink;
        using zui::p::toastAction;
        using zui::p::toastLabel;
      }
    }
  }

}

}

#endif //_ZUI_TOAST_H_
