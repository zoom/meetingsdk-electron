/*****************************************************************************
*
* Copyright (C) 2025, Zoom Video Communications, Inc
*
*****************************************************************************/
#pragma once

#include "view.h"
#include "interactive_container.h"
#include <memory>

namespace zui
{
  class ModifierBundle;

  namespace p
  {
    inline View& operator|(View& view, const PipeModifier& modifier) { return modifier(view); }
    inline View& operator|(View&& view, const PipeModifier& modifier) { return modifier(view); }

    class ZUI_API minSize : public PipeModifier
    {
    public:
      explicit minSize(float minWidth, float minHeight);
      ~minSize();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API minWidth : public PipeModifier
    {
    public:
      explicit minWidth(float width);
      ~minWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API minHeight : public PipeModifier
    {
    public:
      explicit minHeight(float height);
      ~minHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API maxSize : public PipeModifier
    {
    public:
      explicit maxSize(float maxWidth, float maxHeight);
      ~maxSize();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API maxWidth : public PipeModifier
    {
    public:
      explicit maxWidth(float width);
      ~maxWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API maxHeight : public PipeModifier
    {
    public:
      explicit maxHeight(float height);
      ~maxHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API size : public PipeModifier
    {
    public:
      explicit size(float width, float height);
      ~size();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API width : public PipeModifier
    {
    public:
      explicit width(float w);
      ~width();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API height : public PipeModifier
    {
    public:
      explicit height(float h);
      ~height();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API idealSize : public PipeModifier
    {
    public:
      explicit idealSize(float width, float height);
      ~idealSize();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API idealWidth : public PipeModifier
    {
    public:
      explicit idealWidth(float width);
      ~idealWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API idealHeight : public PipeModifier
    {
    public:
      explicit idealHeight(float height);
      ~idealHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentWidth : public PipeModifier
    {
    public:
      explicit percentWidth(float percent);
      ~percentWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentHeight : public PipeModifier
    {
    public:
      explicit percentHeight(float percent);
      ~percentHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentMinWidth : public PipeModifier
    {
    public:
      explicit percentMinWidth(float percent);
      ~percentMinWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentMinHeight : public PipeModifier
    {
    public:
      explicit percentMinHeight(float percent);
      ~percentMinHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentMaxWidth : public PipeModifier
    {
    public:
      explicit percentMaxWidth(float percent);
      ~percentMaxWidth();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API percentMaxHeight : public PipeModifier
    {
    public:
      explicit percentMaxHeight(float percent);
      ~percentMaxHeight();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API fixedSize : public PipeModifier
    {
    public:
      fixedSize();
      explicit fixedSize(bool width, bool height);
      ~fixedSize();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API layoutPriority : public PipeModifier
    {
    public:
      explicit layoutPriority(float priority);
      ~layoutPriority();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API offset : public PipeModifier
    {
    public:
      explicit offset(float x, float y);
      explicit offset(const Layout::Position& position);
      ~offset();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API padding : public PipeModifier
    {
    public:
      explicit padding(float length);
      explicit padding(const Layout::EdgeInsets& insets);
      explicit padding(float left, float top, float right, float bottom);
      explicit padding(const Layout::EdgeSet& edges, float length);
      ~padding();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API alignment : public PipeModifier
    {
    public:
      explicit alignment(Layout::Alignment align);
      ~alignment();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API justifyContent : public PipeModifier
    {
    public:
      explicit justifyContent(Layout::JustifyContent justify);
      ~justifyContent();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API gridHorizontalAlignment : public PipeModifier
    {
    public:
      explicit gridHorizontalAlignment(Layout::Alignment align);
      ~gridHorizontalAlignment();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API gridVerticalAlignment : public PipeModifier
    {
    public:
      explicit gridVerticalAlignment(Layout::Alignment align);
      ~gridVerticalAlignment();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API gridColumnSpan : public PipeModifier
    {
    public:
      explicit gridColumnSpan(unsigned int span);
      ~gridColumnSpan();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API background : public PipeModifier
    {
    public:
      explicit background(const Bind<std::string>& color);
      explicit background(const char* color);
      background(ControlState state, const std::string& imageOrColor);
      ~background();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API borderColor : public PipeModifier
    {
    public:
      explicit borderColor(const Bind<std::string>& color);
      explicit borderColor(const char* color);
      ~borderColor();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API borderGradientColors : public PipeModifier
    {
    public:
      explicit borderGradientColors(const std::vector<std::string>& colors);
      ~borderGradientColors();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API borderRadius : public PipeModifier
    {
    public:
      explicit borderRadius(const Bind<float>& radius);
      ~borderRadius();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API borderSize : public PipeModifier
    {
    public:
      explicit borderSize(const Bind<float>& size);
      explicit borderSize(const Bind<float>& xWidth, const Bind<float>& yWidth);
      ~borderSize();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API hidden : public PipeModifier
    {
    public:
      explicit hidden(const Bind<bool>& h);
      ~hidden();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API visible : public PipeModifier
    {
    public:
      explicit visible(const Bind<bool>& v);
      ~visible();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API enabled : public PipeModifier
    {
    public:
      explicit enabled(const Bind<bool>& e);
      ~enabled();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API forceEnabled : public PipeModifier
    {
    public:
      forceEnabled();
      ~forceEnabled();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API forceFocusable : public PipeModifier
    {
    public:
      forceFocusable();
      ~forceFocusable();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API focused : public PipeModifier
    {
    public:
      explicit focused(const Bind<bool>& f);
      ~focused();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API darkMode : public PipeModifier
    {
    public:
      explicit darkMode(const Bind<bool>& darkMode);
      ~darkMode();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onHover : public PipeModifier
    {
    public:
      explicit onHover(std::function<void(bool)> callback);
      ~onHover();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onClick : public PipeModifier
    {
    public:
      explicit onClick(std::function<void()> callback);
      ~onClick();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onChange : public PipeModifier
    {
    public:
      explicit onChange(std::function<void()> callback);
      ~onChange();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onAppear : public PipeModifier
    {
    public:
      explicit onAppear(const std::function<void()>& action);
      ~onAppear();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onDisappear : public PipeModifier
    {
    public:
      explicit onDisappear(const std::function<void()>& action);
      ~onDisappear();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API toolTip : public PipeModifier
    {
    public:
      explicit toolTip(const std::string& text, const std::string& key = "", uint32_t modifier = 0);
      ~toolTip();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityName : public PipeModifier
    {
    public:
      explicit accessibilityName(const Bind<std::string>& name);
      ~accessibilityName();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityDescription : public PipeModifier
    {
    public:
      explicit accessibilityDescription(const Bind<std::string>& desc);
      ~accessibilityDescription();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityHelp : public PipeModifier
    {
    public:
      explicit accessibilityHelp(const Bind<std::string>& help);
      ~accessibilityHelp();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityFocusable : public PipeModifier
    {
    public:
      explicit accessibilityFocusable(bool focusable);
      ~accessibilityFocusable();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityIgnoreSelfText : public PipeModifier
    {
    public:
      explicit accessibilityIgnoreSelfText(bool ignore = true);
      ~accessibilityIgnoreSelfText();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityChildrenPolicy : public PipeModifier
    {
    public:
      explicit accessibilityChildrenPolicy(AccessibilityChildrenPolicy policy);
      ~accessibilityChildrenPolicy();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityIntent : public PipeModifier
    {
    public:
      explicit accessibilityIntent(AccessibilityIntent intent);
      ~accessibilityIntent();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverWindowTitle : public PipeModifier
    {
    public:
      explicit popoverWindowTitle(const std::string& title);
      ~popoverWindowTitle();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverDirection : public PipeModifier
    {
    public:
      explicit popoverDirection(PopoverDirection direction);
      ~popoverDirection();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverCanFocus : public PipeModifier
    {
    public:
      explicit popoverCanFocus(bool canFocus);
      ~popoverCanFocus();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverTriggerMode : public PipeModifier
    {
    public:
      explicit popoverTriggerMode(const Bind<PopoverTriggerMode>& mode);
      ~popoverTriggerMode();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverArrow : public PipeModifier
    {
    public:
      explicit popoverArrow(bool showArrow);
      ~popoverArrow();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popover : public PipeModifier
    {
    public:
      explicit popover(const View& popoverView);
      explicit popover(const std::function<std::shared_ptr<View>(PopoverContext&)>& popoverBuilder);
      ~popover();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverAutoShow : public PipeModifier
    {
    public:
      explicit popoverAutoShow(bool autoShow);
      ~popoverAutoShow();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API popoverHasShow : public PipeModifier
    {
    public:
      explicit popoverHasShow(const Bind<bool>& hasShow);
      ~popoverHasShow();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onPopoverShow : public PipeModifier
    {
    public:
      explicit onPopoverShow(std::function<void()> callback);
      ~onPopoverShow();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onPopoverHide : public PipeModifier
    {
    public:
      explicit onPopoverHide(std::function<void()> callback);
      ~onPopoverHide();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onPopoverMouseEnter : public PipeModifier
    {
    public:
      explicit onPopoverMouseEnter(std::function<void()> callback);
      ~onPopoverMouseEnter();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API onPopoverMouseExit : public PipeModifier
    {
    public:
      explicit onPopoverMouseExit(std::function<void()> callback);
      ~onPopoverMouseExit();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityGroupName : public PipeModifier
    {
    public:
      explicit accessibilityGroupName(const Bind<std::string>& name);
      ~accessibilityGroupName();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API accessibilityCustomRole : public PipeModifier
    {
    public:
      explicit accessibilityCustomRole(AccessibilityRole roleValue);
      ~accessibilityCustomRole();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API viewId : public PipeModifier
    {
    public:
      explicit viewId(const std::string& viewId);
      ~viewId();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API idObserver : public PipeModifier
    {
    public:
      explicit idObserver(const Bind<std::string>& observer);
      ~idObserver();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API testId : public PipeModifier
    {
    public:
      explicit testId(const std::string& id);
      ~testId();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API attribute : public PipeModifier
    {
    public:
      explicit attribute(const std::string& attr);
      ~attribute();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API environment : public PipeModifier
    {
    public:
      explicit environment(const std::string& key, const EnvironmentValue& val);
      ~environment();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API loopListItem : public PipeModifier
    {
    public:
      loopListItem();
      ~loopListItem();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    class ZUI_API applyBundle : public PipeModifier
    {
    public:
      explicit applyBundle(const ModifierBundle& bundle);
      ~applyBundle();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    // =============================================================================
    // INTERACTIVE CONTAINER MODIFIERS
    // =============================================================================

    /**
     * @class hoverBackground
     * @brief Sets hover and optionally pressed background for InteractiveContainer/Pressable
     * 
     * @example
     * Pressable{ ... }
     *   | p::hoverBackground("state/state-subtle-neutral-hover")
     *   | p::hoverBackground("state/hover", "state/pressed")
     */
    class ZUI_API hoverBackground : public PipeModifier
    {
    public:
      explicit hoverBackground(const std::string& hoverBg);
      hoverBackground(const std::string& hoverBg, const std::string& pressedBg);
      ~hoverBackground();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    /**
     * @class stateBackground
     * @brief Sets background for a specific control state
     * 
     * @example
     * Pressable{ ... }
     *   | p::stateBackground(ControlState::Normal, "fill/default")
     *   | p::stateBackground(ControlState::Hover, "state/hover")
     */
    class ZUI_API stateBackground : public PipeModifier
    {
    public:
      stateBackground(ControlState state, const std::string& bg);
      ~stateBackground();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    /**
     * @class backgrounds
     * @brief Sets backgrounds for multiple control states at once
     *
     * @example
     * Pressable{ ... }
     *   | p::backgrounds("fill/default", "state/hover", "state/pressed")
     */
    class ZUI_API backgrounds : public PipeModifier
    {
    public:
      backgrounds(const std::string& normal,
                  const std::string& hover = "",
                  const std::string& pressed = "",
                  const std::string& focused = "",
                  const std::string& disabled = "");
      ~backgrounds();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    /**
     * @class stateBorderColor
     * @brief Sets border color for a specific control state
     *
     * @example
     * Pressable{ ... }
     *   | p::stateBorderColor(ControlState::Normal, "border/border-subtle-neutral")
     *   | p::stateBorderColor(ControlState::Hover, "border/border-neutral-hover")
     */
    class ZUI_API stateBorderColor : public PipeModifier
    {
    public:
      stateBorderColor(ControlState state, const std::string& color);
      ~stateBorderColor();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    /**
     * @class borderColors
     * @brief Sets border colors for multiple control states at once
     *
     * @example
     * Pressable{ ... }
     *   | p::borderColors("border/default", "border/hover", "border/pressed")
     */
    class ZUI_API borderColors : public PipeModifier
    {
    public:
      borderColors(const std::string& normal,
                   const std::string& hover = "",
                   const std::string& pressed = "",
                   const std::string& focused = "",
                   const std::string& disabled = "");
      ~borderColors();
    protected:
      void apply(View& v) const override;
    private:
      class Impl;
      Impl* _pImpl;
    };

    // =============================================================================
    // DISCOVERABILITY NAMESPACES
    // =============================================================================
    
    /**
     * @brief Discovery namespaces for improved modifier discoverability
     * 
     * These namespaces provide alternative ways to discover and access modifiers:
     * - by_category: Modifiers grouped by functional category
     * - by_view: All modifiers available for specific view types (to be extended)
     * - common: Pre-built modifier bundles for frequent patterns
     * 
     * All existing p::<modifier> usage continues to work unchanged.
     * These are purely additive discovery aids.
     */
    namespace discover {
      
      /**
       * @brief Modifiers organized by functional category
       */
      namespace by_category {
        
        /**
         * @brief Size and layout modifiers
         * Controls view dimensions, positioning, and layout behavior
         */
        namespace layout {
          using zui::p::minSize;
          using zui::p::minWidth;
          using zui::p::minHeight;
          using zui::p::maxSize;
          using zui::p::maxWidth;
          using zui::p::maxHeight;
          using zui::p::size;
          using zui::p::width;
          using zui::p::height;
          using zui::p::idealSize;
          using zui::p::idealWidth;
          using zui::p::idealHeight;
          using zui::p::percentWidth;
          using zui::p::percentHeight;
          using zui::p::percentMinWidth;
          using zui::p::percentMinHeight;
          using zui::p::percentMaxWidth;
          using zui::p::percentMaxHeight;
          using zui::p::fixedSize;
          using zui::p::layoutPriority;
          using zui::p::offset;
          using zui::p::padding;
          using zui::p::alignment;
          using zui::p::justifyContent;
        }
        
        /**
         * @brief Visual styling modifiers
         * Controls colors, borders, backgrounds, and visual appearance
         */
        namespace style {
          using zui::p::background;
          using zui::p::borderColor;
          using zui::p::borderGradientColors;
          using zui::p::borderRadius;
          using zui::p::borderSize;
        }
        
        /**
         * @brief User interaction and event modifiers
         * Handles clicks, hovers, focus, and other user interactions
         */
        namespace interaction {
          using zui::p::onClick;
          using zui::p::onHover;
          using zui::p::onChange;
          using zui::p::onAppear;
          using zui::p::onDisappear;
          using zui::p::hoverBackground;
          using zui::p::stateBackground;
          using zui::p::backgrounds;
          using zui::p::stateBorderColor;
          using zui::p::borderColors;
        }
        
        /**
         * @brief View state and visibility modifiers
         * Controls visibility, enabled state, and focus
         */
        namespace state {
          using zui::p::hidden;
          using zui::p::visible;
          using zui::p::enabled;
          using zui::p::forceEnabled;
          using zui::p::forceFocusable;
          using zui::p::focused;
          using zui::p::darkMode;
        }
        
        /**
         * @brief Accessibility modifiers
         * Provides accessibility labels, descriptions, and navigation aids
         */
        namespace accessibility {
          using zui::p::accessibilityName;
          using zui::p::accessibilityDescription;
          using zui::p::accessibilityHelp;
          using zui::p::accessibilityFocusable;
          using zui::p::accessibilityChildrenPolicy;
          using zui::p::accessibilityIntent;
          using zui::p::accessibilityGroupName;
          using zui::p::accessibilityCustomRole;
        }
        
        /**
         * @brief System and framework modifiers
         * Framework-specific functionality like telemetry, IDs, and environment
         */
        namespace system {
          using zui::p::viewId;
          using zui::p::idObserver;
          using zui::p::testId;
          using zui::p::attribute;
          using zui::p::environment;
          using zui::p::loopListItem;
          using zui::p::applyBundle;
        }
      }
      
      /**
       * @brief Modifiers organized by view type compatibility
       * Shows all modifiers available for specific view types
       * 
       * Note: Individual view-specific modifiers will be added to these
       * namespaces from their respective header files.
       */
      namespace by_view {
        
        /**
         * @brief Base modifiers available for all views
         * These modifiers work on any View-derived class
         */
        namespace base {
          // Size & Layout
          using zui::p::minSize;
          using zui::p::minWidth;
          using zui::p::minHeight;
          using zui::p::maxSize;
          using zui::p::maxWidth;
          using zui::p::maxHeight;
          using zui::p::size;
          using zui::p::width;
          using zui::p::height;
          using zui::p::idealSize;
          using zui::p::idealWidth;
          using zui::p::idealHeight;
          using zui::p::percentWidth;
          using zui::p::percentHeight;
          using zui::p::percentMinWidth;
          using zui::p::percentMinHeight;
          using zui::p::percentMaxWidth;
          using zui::p::percentMaxHeight;
          using zui::p::fixedSize;
          using zui::p::layoutPriority;
          using zui::p::offset;
          using zui::p::padding;
          using zui::p::alignment;
          using zui::p::justifyContent;
          using zui::p::gridHorizontalAlignment;
          using zui::p::gridVerticalAlignment;
          using zui::p::gridColumnSpan;
          
          // Style
          using zui::p::background;
          using zui::p::borderColor;
          using zui::p::borderGradientColors;
          using zui::p::borderRadius;
          using zui::p::borderSize;
          
          // State
          using zui::p::hidden;
          using zui::p::visible;
          using zui::p::enabled;
          using zui::p::forceEnabled;
          using zui::p::forceFocusable;
          using zui::p::focused;
          using zui::p::darkMode;
          
          // Events
          using zui::p::onClick;
          using zui::p::onHover;
          using zui::p::onChange;
          using zui::p::onAppear;
          using zui::p::onDisappear;
          
          // Accessibility
          using zui::p::accessibilityName;
          using zui::p::accessibilityDescription;
          using zui::p::accessibilityHelp;
          using zui::p::accessibilityFocusable;
          using zui::p::accessibilityChildrenPolicy;
          using zui::p::accessibilityIntent;
          using zui::p::accessibilityGroupName;
          using zui::p::accessibilityCustomRole;
          
          // System
          using zui::p::viewId;
          using zui::p::idObserver;
          using zui::p::testId;
          using zui::p::attribute;
          using zui::p::environment;
          using zui::p::loopListItem;
          using zui::p::applyBundle;
        }
      }
    }

  }//namespace p

} // namespace zui
