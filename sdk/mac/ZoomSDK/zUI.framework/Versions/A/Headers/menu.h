#ifndef _ZUI_MENU_H_
#define _ZUI_MENU_H_

#include <memory>
#include <vector>
#include "view.h"

namespace zui
{
  class ZUI_API MenuItem : public View
  {
  public:
    MenuItem();
    virtual ~MenuItem() = default;
        
    MenuItem& leadingIcon(const Bind<std::string>& icon);
    MenuItem& trailingIcon(const Bind<std::string>& icon);
    MenuItem& label(const Bind<std::string>& label);
    MenuItem& check(const Bind<bool>& check);
    MenuItem& onClick(std::function<void()> callback);
  };

  class ZUI_API MenuSection : public View
  {
  public:
    template<typename... Args,
      typename = typename std::enable_if<std::conjunction<IsMenuArg<Args>...>::value>::type>
      MenuSection(Args&&... views) : View(View::Type::MenuSection, [this]() {
        return (this)->BuildMenuSection();
    })
    {
      int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy); // Prevent unused variable warning
    }
    virtual ~MenuSection() = default;

    std::shared_ptr<ViewNode> BuildMenuSection();
    MenuSection& label(const Bind<std::string>& label);

  private:
    void AddChildView(std::shared_ptr<ViewNode> child);
  };

  class ZUI_API MenuDivider : public View
  {
  public:
    MenuDivider();
    virtual ~MenuDivider() = default;

    std::shared_ptr<ViewNode> BuildMenuDivider();
  };

	class ZUI_API Menu : public View
	{
	public:
    template<typename... Args,
      typename = typename std::enable_if<std::conjunction<IsMenuArg<Args>...>::value>::type>
    Menu(Args&&... views) : View(View::Type::Menu, [this]() {
      return (this)->BuildMenu();
  })
    {
      int dummy[] = { 0, (AddChildView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy); // Prevent unused variable warning
    }
		virtual ~Menu() = default;

    std::shared_ptr<ViewNode> BuildMenu();

    Menu& leadingIcon(const Bind<std::string>& icon);
    Menu& trailingIcon(const Bind<std::string>& icon);
    Menu& label(const Bind<std::string>& label);

  private:
    void AddChildView(std::shared_ptr<ViewNode> child);
	};

namespace p
{

  // MenuItem-specific pipe modifiers
  class ZUI_API menuCheck : public PipeModifier
  {
  public:
    explicit menuCheck(const Bind<bool>& check);
    ~menuCheck();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuItemLeadingIcon : public PipeModifier
  {
  public:
    explicit menuItemLeadingIcon(const Bind<std::string>& icon);
    ~menuItemLeadingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuLeadingIcon : public PipeModifier
  {
  public:
    explicit menuLeadingIcon(const Bind<std::string>& icon);
    ~menuLeadingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuItemTrailingIcon : public PipeModifier
  {
  public:
    explicit menuItemTrailingIcon(const Bind<std::string>& icon);
    ~menuItemTrailingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuTrailingIcon : public PipeModifier
  {
  public:
    explicit menuTrailingIcon(const Bind<std::string>& icon);
    ~menuTrailingIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuSectionLabel : public PipeModifier
  {
  public:
    explicit menuSectionLabel(const Bind<std::string>& label);
    ~menuSectionLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuItemLabel : public PipeModifier
  {
  public:
    explicit menuItemLabel(const Bind<std::string>& label);
    ~menuItemLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API menuLabel : public PipeModifier
  {
  public:
    explicit menuLabel(const Bind<std::string>& label);
    ~menuLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace menu {
        using zui::p::menuCheck;
        using zui::p::menuLeadingIcon;
        using zui::p::menuTrailingIcon;
        using zui::p::menuLabel;
      }
      namespace menu_item {
        using zui::p::menuItemLeadingIcon;
        using zui::p::menuItemTrailingIcon;
        using zui::p::menuItemLabel;
      }
      namespace menu_section {
        using zui::p::menuSectionLabel;
      }
    }
  }

} // namespace p

}

#endif
