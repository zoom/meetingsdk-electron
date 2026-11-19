#pragma once

#include "view.h"
#include "model/model.h"
#include <string>
#include <functional>

namespace zui {

class ZUI_API SplitButton 
  : public View {
public:
  enum class Type {
    Primary,
    Secondary
  };

  enum class Size {
    Large,
    Medium,
    Small
  };

  // Constructor
  explicit SplitButton(const Bind<std::string>& label);

  // Configuration methods (fluent interface)
  SplitButton& type(const Bind<Type>& buttonType);
  SplitButton& buttonSize(const Bind<Size>& buttonSize);
  
  // Event callbacks
  SplitButton& onMainClick(std::function<void()> callback);
  SplitButton& onDropdownClick(std::function<void()> callback);
};

// PipeModifier definitions
namespace p {
  // splitButtonType - Set button type (Primary/Secondary)
  class ZUI_API splitButtonType : public PipeModifier {
   public:
    explicit splitButtonType(const Bind<SplitButton::Type>& buttonType);
    explicit splitButtonType(SplitButton::Type buttonType);
    ~splitButtonType();
   protected:
    void apply(View& v) const override;
   private:
    class Impl;
    Impl* _pImpl;
  };

  // splitButtonSize - Set button size (Large/Medium/Small)
  class ZUI_API splitButtonSize : public PipeModifier {
   public:
    explicit splitButtonSize(const Bind<SplitButton::Size>& buttonSize);
    explicit splitButtonSize(SplitButton::Size buttonSize);
    ~splitButtonSize();
   protected:
    void apply(View& v) const override;
   private:
    class Impl;
    Impl* _pImpl;
  };

  // splitButtonOnMainClick - Main button click callback
  class ZUI_API splitButtonOnMainClick : public PipeModifier {
   public:
    explicit splitButtonOnMainClick(std::function<void()> callback);
    ~splitButtonOnMainClick();
   protected:
    void apply(View& v) const override;
   private:
    class Impl;
    Impl* _pImpl;
  };

  // splitButtonOnDropdownClick - Dropdown button click callback
  class ZUI_API splitButtonOnDropdownClick : public PipeModifier {
   public:
    explicit splitButtonOnDropdownClick(std::function<void()> callback);
    ~splitButtonOnDropdownClick();
   protected:
    void apply(View& v) const override;
   private:
    class Impl;
    Impl* _pImpl;
  };

  // Discover namespace for auto-completion
  namespace discover {
    namespace by_view {
      namespace split_button {
        using zui::p::splitButtonType;
        using zui::p::splitButtonSize;
        using zui::p::splitButtonOnMainClick;
        using zui::p::splitButtonOnDropdownClick;
      }
    }
  }
} // namespace p

} // namespace zui

