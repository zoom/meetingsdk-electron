#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class Avatar
	 * @brief A view component that displays a user's profile image, initials, or fallback icon.
	 * @ingroup controls_media
	 * 
	 * The Avatar component is used to represent users or entities in the interface. It supports:
	 * - Profile images
	 * - User initials as fallback
	 * - Custom background colors
	 * - Various presence status indicators
	 * - Multiple size options
	 * - Interactive events (click, hover)
	 * 
	 * @example
	 * @code
	 * // Basic avatar with image
	 * Avatar()
	 *   .image("user-profile.jpg")
	 *   .name("John Doe")
	 *   .avatarSize(Avatar::Size::kSize40);
	 * 
	 * // Avatar with status
	 * Avatar()
	 *   .name("Jane Smith")
	 *   .presenceStatus(Avatar::PresenceStatus::kOnline)
	 *   .avatarSize(Avatar::Size::kSize32);
	 * @endcode
	 */
	class ZUI_API Avatar
		: public View
	{
	public:
		/**
		 * @enum PresenceStatus
		 * @brief Defines the presence status of the avatar
		 */
		enum class PresenceStatus
		{
			kNone,           ///< No status indicator
			kAway,           ///< User is away
			kBlock,          ///< User is blocked
			kBusy,           ///< User is busy
			kDoNotDisturb,   ///< User is in do not disturb mode
			kInCalendarEvent,///< User is in a calendar event
			kInCall,         ///< User is in a call
			kInMeeting,      ///< User is in a meeting
			kMobile,         ///< User is on mobile
			kOffline,        ///< User is offline
			kOnline,         ///< User is online
			kOutOfOffice     ///< User is out of office
		};

		/**
		 * @enum Size
		 * @brief Defines the available sizes for the avatar
		 */
		enum class Size
		{
			kSize20,  ///< 20x20 pixels (tag size)
			kSize24,  ///< 24x24 pixels (default size)
			kSize32,  ///< 32x32 pixels
			kSize40,  ///< 40x40 pixels
			kSize48,  ///< 48x48 pixels
			kSize64,  ///< 64x64 pixels
			kSize80,  ///< 80x80 pixels
			kSize110  ///< 110x110 pixels
		};

	public:
		/// @brief Constructs a new Avatar object
		Avatar();
    Avatar(const Bind<std::string>& image);
		/// @brief Virtual destructor
		virtual ~Avatar() = default;

		/**
		 * @brief Sets the user name
		 * @param name The name of the user
		 * @return Reference to this avatar for method chaining
		 * @note The name is used to generate initials when no image is available
		 */
		Avatar& name(const Bind<std::string>& name);

		/**
		 * @brief Sets the background color
		 * @param color The background color in ARGB format
		 * @return Reference to this avatar for method chaining
		 * @note The background color is used when no image is available
		 */
		Avatar& backgroundColor(Bind<unsigned int> color);

		/**
		 * @brief Sets the presence status
		 * @param status The presence status to display
		 * @return Reference to this avatar for method chaining
		 */
		Avatar& presenceStatus(const Bind<PresenceStatus>& status);

		/**
		 * @brief Sets the avatar size
		 * @param size The size of the avatar
		 * @return Reference to this avatar for method chaining
		 */
		Avatar& avatarSize(const Bind<Size>& size);
	};

namespace p
{

  class ZUI_API avatarName : public PipeModifier
  {
  public:
    explicit avatarName(const Bind<std::string>& name);
    ~avatarName();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarBackgroundColor : public PipeModifier
  {
  public:
    explicit avatarBackgroundColor(Bind<unsigned int> color);
    ~avatarBackgroundColor();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarPresenceStatus : public PipeModifier
  {
  public:
    explicit avatarPresenceStatus(const Bind<Avatar::PresenceStatus>& status);
    ~avatarPresenceStatus();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarSize : public PipeModifier
  {
  public:
    explicit avatarSize(const Bind<Avatar::Size>& size);
    ~avatarSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace avatar {
        using zui::p::avatarName;
        using zui::p::avatarBackgroundColor;
        using zui::p::avatarPresenceStatus;
        using zui::p::avatarSize;
      }
    }
  }

} // namespace p

}
