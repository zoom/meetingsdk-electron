#pragma once

/**
 * @todo what is the purpose of this file? Ross
 */
#include "zui_data_define.h"

#include "container.h"
#include "view.h"
#include <memory>

namespace zui
{
	/**
	 * @class Accordion
	 * @brief A container representing an accordion UI component.
	 *
	 * Allows users to view and interact with a large amount of information
	 * in a compact space by hiding or showing content in sections.
	 */
	class ZUI_API Accordion : public Container
	{
	public:
		/**
		 * @enum ChevronPosition
		 * @brief Defines the position of the chevron icon in the accordion.
		 */
		enum class ChevronPosition
		{
			kLeading,  ///< The chevron icon is on the leading side of the accordion.
			kTrailing, ///< The chevron icon is on the trailing side of the accordion.
		};

		/**
		 * @brief Construct a new Accordion object
		 *
		 * @tparam View
		 * @param views
		 */
		template<typename... Views>
		Accordion(Views&&... views)
			: Container(View::Type::Accordion,  [this]() {
        return (this)->BuildAccordion();
    }, views...)
		{
		}

		/// @brief Virtual destructor of the Accordion class.
		virtual ~Accordion() = default;

		/**
		 * @brief Build the view
		 *
		 * @return std::shared_ptr<ViewNode>
		 */
		std::shared_ptr<ViewNode> BuildAccordion();

		/**
		 * @brief Define the chevron icon position
		 *
		 * @param[in] status The position of the chevron icon.
		 */
		Accordion& chevron(const Bind<ChevronPosition>& status);

		/**
		 * @brief Define the label of the accordion.
		 *
		 * @param[in] label The label of the accordion.
		 */
		Accordion& label(const Bind<std::string>& label);

		/**
		 * @brief Define the icon of the accordion.
		 *
		 * @param icon The path of the icon.
		 */
		Accordion& icon(const Bind<std::string>& icon, const Bind<std::string>& disableIcon);
	};

namespace p
{
  // Accordion-specific pipe modifiers
  class ZUI_API accordionChevron : public PipeModifier
  {
  public:
    explicit accordionChevron(const Bind<Accordion::ChevronPosition>& status);
    ~accordionChevron();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API accordionIcon : public PipeModifier
  {
  public:
    explicit accordionIcon(const Bind<std::string>& iconPath, const Bind<std::string>& disableIcon);
    ~accordionIcon();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API accordionLabel : public PipeModifier
  {
  public:
    explicit accordionLabel(const Bind<std::string>& label);
    ~accordionLabel();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace accordion {
        using zui::p::accordionChevron;
        using zui::p::accordionIcon;
        using zui::p::accordionLabel;
      }
    }
  }

} // namespace p

}

