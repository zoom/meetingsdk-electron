#pragma once

#include <functional>
#include <memory>
#include "view.h"
#include "zui_data_define.h"

namespace zui
{
	/**
	 * @class AvatarGroup
	 * @brief A view component that displays a group of user profile images, initials, or fallback icons.
	 * @ingroup controls_media
	 * 
	 * The AvatarGroup component is used to represent a group of users or entities in the interface. It supports:
	 * - Profile images
	 * - User initials as fallback
	 * - Custom background colors
	 * - Multiple size options
	 * - Interactive events (click)
	 * 
	 * @example
	 * @code
	 * // Basic avatar with image
	 * AvatarGroup(Avatar().name("John Doe").image("user-profile.jpg"), Avatar().name("Jane Doe").image("user-profile.jpg"))
	 *   .avatarSize(Avatar::Size::kSize40);
	 *
	 * @endcode
	 */
	class ZUI_API AvatarGroup
		: public View
	{
	public:
    struct AvatarData 
    {
      std::string image;
      std::string name;

      bool operator==(const AvatarData& other) const {
        return image == other.image && name == other.name;
      }
    };

		/**
		 * @enum Size
		 * @brief Defines the available sizes for the AvatarGroup
		 */
		enum class Size
		{
			kSize20,  ///< 20x20 pixels (tag size)
			kSize24,  ///< 24x24 pixels (default size)
			kSize32,  ///< 32x32 pixels
			kSize40,  ///< 40x40 pixels
		};

	public:
    /**
     * @brief Constructs an AvatarGroup with multiple avatar views
     * @tparam Views Template parameter pack for View objects
     * @param views Variable number of avatar objects to include in the AvatarGroup content
     */
    template<typename... Views>
    AvatarGroup(Views&&... views)
      : View(View::Type::AvatarGroup, [this]() {
          return (this)->BuildAvatarGroup();
      })
    {
      int dummy[] = { 0, (AddAvatarView(views.GetViewNode()), 0)... };
      static_cast<void>(dummy); // Prevent unused variable warning
    }

		/// @brief Virtual destructor
		virtual ~AvatarGroup() = default;

		/// @brief Builds the view node for this AvatarGroup
		std::shared_ptr<ViewNode> BuildAvatarGroup();

		/**
		 * @brief Sets the avatar size
		 * @param size The size of the avatars in this avatarGroup
		 * @return Reference to this AvatarGroup for method chaining
		 */
    AvatarGroup& avatarSize(const Bind<Size>& size);
    
    /**
     * @brief Sets the max number of avatars shown
     * @param max The max number of avatars shown in this avatarGroup
     * @return Reference to this AvatarGroup for method chaining
     */
    AvatarGroup& maxShown(const Bind<int>& max);
    
    AvatarGroup& avatarData(const Bind<std::vector<AvatarData>>& data);

    AvatarGroup& count(const Bind<int>& number);
  private:
    /// @brief Internal method to add child avatar view nodes
    void AddAvatarView(std::shared_ptr<ViewNode> viewNode);
	};

namespace p
{

  class ZUI_API avatarGroupSize : public PipeModifier
  {
  public:
    explicit avatarGroupSize(const Bind<AvatarGroup::Size>& size);
    ~avatarGroupSize();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarGroupMaxShown : public PipeModifier
  {
  public:
    explicit avatarGroupMaxShown(const Bind<int>& max);
    ~avatarGroupMaxShown();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarGroupData : public PipeModifier
  {
  public:
    explicit avatarGroupData(const Bind<std::vector<AvatarGroup::AvatarData>>& data);
    ~avatarGroupData();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  class ZUI_API avatarGroupCount : public PipeModifier
  {
  public:
    explicit avatarGroupCount(const Bind<int>& number);
    ~avatarGroupCount();
  protected:
    void apply(View& v) const override;
  private:
    class Impl;
    Impl* _pImpl;
  };

  namespace discover {
    namespace by_view {
      namespace avatar_group {
        using zui::p::avatarGroupSize;
        using zui::p::avatarGroupMaxShown;
        using zui::p::avatarGroupData;
        using zui::p::avatarGroupCount;
      }
    }
  }

} // namespace p

}
