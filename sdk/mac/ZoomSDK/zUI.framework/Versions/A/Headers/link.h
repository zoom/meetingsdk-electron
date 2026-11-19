/**
 * @file link.h
 * @brief Link component for clickable navigation elements
 * 
 * Provides clickable text links with navigation functionality.
 */

#pragma once

#include <memory>
#include "zui_data_define.h"

#include "text.h"

namespace zui
{
	/**
	 * @class Link
	 * @brief A view component that allows users to navigate to another location or resource.
	 * @ingroup controls_typography
	 * 
	 * The Link component extends Text functionality to provide clickable navigation
	 * elements. It supports:
	 * - Multiple destination types (custom, URL, window)
	 * - Multiple link types (inline, standalone with arrow)
	 * - Click event handling with destination information
	 * - All text styling capabilities from the Text base class
	 * 
	 * @example
	 * @code
	 * // Simple URL link
	 * Link("Visit our website", "https://example.com")
	 *   .standaloneLink()
	 *   .onClick([](Link::DestType type, const std::string& dest) {
	 *     openURL(dest);
	 *   });
	 * 
	 * // Custom action link
	 * Link("Open Settings")
	 *   .destination(Link::DestType::kCustom, "settings")
	 *   .inlineLink()
	 *   .onClick([](Link::DestType type, const std::string& dest) {
	 *     showSettingsDialog();
	 *   });
	 * @endcode
	 * 
	 * @todo Add size specification support
	 */
	class ZUI_API Link : public Text
	{
	public:

		/**
		 * @enum DestType
		 * @brief Defines the destination type of a link
		 * @todo Move this enum out of Link class for better reusability
		 */
		enum class DestType
		{
			kCustom, ///< Custom destination handled by application logic
			kUrl,    ///< URL destination for web navigation
			kWindow, ///< Window destination for internal navigation
		};

		/**
		 * @enum LinkType
		 * @brief Defines the visual type of the link
		 */
		enum class LinkType
		{
			kInline,     ///< Inline link without visual indicators
			kStandalone, ///< Standalone link with arrow icon
		};

		/**
		 * @brief Constructs a new Link object with text content
		 * @param text The text to display for the link (can include fragments in {})
		 */
		Link(const Bind<std::string>& text);

		/**
		 * @brief Constructs a new Link object with text and URL destination
		 * @param text The text to display for the link
		 * @param url The URL destination for the link
		 */
		Link(const std::string& text, const std::string& url);

		/**
		 * @brief Constructs a new Link object with bound text and URL
		 * @param text The bound text to display for the link
		 * @param url The bound URL destination for the link
		 */
		Link(const Bind<std::string>& text, const Bind<std::string>& url);

		/// @brief Virtual destructor
		virtual ~Link() = default;

		/// @brief Builds the view node for this link
		std::shared_ptr<ViewNode> BuildLink();

		/**
		 * @brief Sets the destination of the link
		 * @param type The type of destination
		 * @param dest The destination string (URL, window name, or custom identifier)
		 * @return Reference to this link for method chaining
		 */
		Link& destination(DestType type, const std::string& dest);

		/**
		 * @brief Sets the callback function for link click events
		 * @param callback The function to call when the link is clicked
		 * @return Reference to this link for method chaining
		 */
		Link& onClick(std::function<void(Link::DestType, const std::string&)> callback);

		/**
		 * @brief Sets the link type
		 * @param type The visual type of the link (inline or standalone)
		 * @return Reference to this link for method chaining
		 */
		Link& linkType(LinkType type);

		/**
		 * @brief Sets the link type to inline (no arrow icon)
		 * @return Reference to this link for method chaining
		 */
		Link& inlineLink();

		/**
		 * @brief Sets the link type to standalone (arrow icon after link)
		 * @return Reference to this link for method chaining
		 */
		Link& standaloneLink();
	};

namespace p
{

  // Link-specific pipe modifiers
  class ZUI_API linkDestination : public PipeModifier
  {
  public:
    explicit linkDestination(Link::DestType type, const std::string& dest);
    ~linkDestination();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };


  class ZUI_API linkInline : public PipeModifier
  {
  public:
    linkInline();
    ~linkInline();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API linkStandalone : public PipeModifier
  {
  public:
    linkStandalone();
    ~linkStandalone();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace link {
        using zui::p::linkDestination;
        using zui::p::linkInline;
        using zui::p::linkStandalone;
      }
    }
  }

} // namespace p

}
