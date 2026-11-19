/**
 * @file notifier.h
 * @brief Notifier component for count indicators
 * 
 * Provides notifier functionality for displaying count badges and indicators.
 */

#pragma once

#include <memory>
#include "zui_data_define.h"
#include "view.h"

namespace zui
{
    /**
     * @class Notifier
     * @brief A notification indicator component for counts and alerts.
     * @ingroup controls_feedback
     */
    class ZUI_API Notifier : public View
    {
    public:
      enum class Type
      {
        kDot,
        kCounterRed,
        kCounterRedInverse,
        kCounterBlue,
      };

      enum class Size
      {
        kDefault,
        kSmall,
        kLarge,
        kXLarge
      };

    public:
        /// @brief Construct a new Avatar View
        Notifier();

        /// @brief Virtual destructor of the Badge class.
        virtual ~Notifier() = default;

        Notifier &type(const Bind<Notifier::Type> &type);

        Notifier &size(const Bind<Notifier::Size>& size);

        /**
         * @brief Define the count displayed in the notifier.
         *
         * @param[in] count The label displayed in the badge.
         * @todo Change count to label to follow the naming convention.
         */
        Notifier &count(const Bind<unsigned int>& count);
    };

namespace p
{

  // Notifier-specific pipe modifiers
  class ZUI_API notifierType : public PipeModifier
  {
  public:
    explicit notifierType(const Bind<Notifier::Type>& type);
    ~notifierType();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API notifierSize : public PipeModifier
  {
  public:
    explicit notifierSize(const Bind<Notifier::Size>& size);
    ~notifierSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API notifierCount : public PipeModifier
  {
  public:
    explicit notifierCount(const Bind<unsigned int>& count);
    ~notifierCount();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace notifier {
        using zui::p::notifierType;
        using zui::p::notifierSize;
        using zui::p::notifierCount;
      }
    }
  }

} // namespace p

}
