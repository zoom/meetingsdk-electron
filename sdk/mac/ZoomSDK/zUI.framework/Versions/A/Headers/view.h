/**
 * @file view.h
 * @brief Base View class for all zUI components
 * 
 * The View class is the fundamental base class for all UI components
 * in the zUI framework. It provides common functionality for layout,
 * styling, and interaction.
 */

#ifndef ZUI_VIEW
#define ZUI_VIEW

#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include "types.h"

#ifdef __MACOS__
#import <zUI/model.h>
#else
#include "model/model.h"
#endif

#include "zui_data_define.h"
#include "zui_popup_common.h"
// forward declaration

namespace zui
{
	class ViewNode;
	class ModifierBundle;

  class Menu;
  class MenuDivider;
  class MenuItem;
  class MenuSection;

  template <typename T>
  using IsMenuArg = std::disjunction<
    std::is_same<std::remove_reference_t<T>, Menu>,
    std::is_same<std::remove_reference_t<T>, MenuDivider>,
    std::is_same<std::remove_reference_t<T>, MenuItem>,
    std::is_same<std::remove_reference_t<T>, MenuSection>>;

#define MAKE_VIEW(...) std::shared_ptr<View>(new __VA_ARGS__)


    enum class ToolTipModifier : uint32_t {
      kNone = 0,
      kShift = 1 << 0,     ///< Shift key modifier
      kControl = 1 << 1,   ///< Control key modifier (Ctrl on Windows/Linux)
      kOption = 1 << 2,    ///< Option key modifier (Alt on Windows/Linux)
      kAlternate = 1 << 3, ///< Alternate key modifier
      kCommand = 1 << 4,   ///< Command key modifier (Cmd on macOS, Win key on Windows)
    };

    enum class PopoverDirection : uint32_t {
      kDown,        ///< Popover appears above the anchor
      kDownLeft,    ///< Popover appears above and to the right of the anchor
      kDownRight,   ///< Popover appears above and to the left of the anchor
      kUp,          ///< Popover appears below the anchor
      kUpLeft,      ///< Popover appears below and to the right of the anchor
      kUpRight,     ///< Popover appears below and to the left of the anchor
      kLeft,        ///< Popover appears to the right of the anchor
      kLeftTop,     ///< Popover appears to the right and below the anchor
      kLeftBottom,  ///< Popover appears to the right and above the anchor
      kRight,       ///< Popover appears to the left of the anchor
      kRightTop,    ///< Popover appears to the left and below the anchor
      kRightBottom  ///< Popover appears to the left and above the anchor
    };

    enum class PopoverTriggerMode : uint32_t {
      kDisabled,
      kAuto,
      kHoverFirst,
    };
	/**
	 * @class View
	 * @ingroup view_fundamentals
	 * @brief Base class for all zUI view components
	 * 
	 * The View class is the fundamental base class for all UI components in the zUI framework.
	 * It provides a comprehensive set of modifier methods for layout, styling, and behavior 
	 * configuration that are inherited by all view components.
	 * 
	 * Key Responsibilities:
	 * - Component Foundation: Serves as the base for all zUI components
	 * - Layout Management: Provides size, padding, alignment, and other layout modifiers
	 * - Styling Support: Offers background, border, accessibility, and visual styling
	 * - Event Handling: Enables interaction through onClick, onHover, and other events
	 * - Custom Views: Acts as the base class for user-defined custom view components
	 * 
	 * Virtual Methods for Custom Views:
	 * When creating custom views, you must implement these virtual methods:
	 * - Build(): Returns the view hierarchy that represents your custom component
	 * - Clone(): Creates a copy of your view for the framework's reconciliation system
	 * 
	 * Common Modifier Methods:
	 * All views inherit layout and styling modifier methods:
	 * - Size Control: width(), height(), size(), minWidth(), maxHeight(), etc.
	 * - Layout: padding(), alignment(), justifyContent(), wrap()
	 * - Styling: background(), borderColor(), borderWidth(), cornerRadius()
	 * - Interaction: onClick(), onHover(), enabled(), focusable()
	 * - Accessibility: accessibilityLabel(), accessibilityHint(), accessibilityRole()
	 * 
	 * Usage Note:
	 * View is an abstract base class - you don't instantiate it directly. Instead, you either:
	 * 1. Use concrete view components (Text, BasicButton, VerticalStack, etc.)
	 * 2. Create custom views by inheriting from View and implementing the required virtual methods
	 */
	class ZUI_API View
	{
	public:
		/// @todo better place this in class View
		enum class Type
		{
			Undefined,
			BasicButton,
			IconButton,
			HorizontalStack,
			VerticalStack,
			ScrollView,
			Spacer,
			SelectiveCard,
			RadioButton,
			RadioButtonGroup,
			Checkbox,
			CheckboxGroup,
			Dropdown,
			MultiSelectDropdown,
			Text,
			Image,
			Link,
			Popover,
			PopoverButton,
			Accordion,
			Avatar,
			Toggle,
			Independent,
			Notifier,
			Badge,
			Slider,
			InputField,
			LoadingIndicator,
			Divider,
			Progress,
			BlockProgress,
			SplitButton,
			Conditional,
			MultiConditional,
			Loop,
			Custom,
			External,
			Toast,
			List,
			Cell,
			TabView,
			Tab,
			TabBar,
			Tag,
			Icon,
			DropdownButton,
			Banner,
			Caption,
      MenuItem,
      MenuDivider,
      MenuSection,
      Menu,
			ThemeModeSelector,
      AvatarGroup,
			FileUploader,
			Grid,
			GridRow,
			LayeredStack,
			InteractiveContainer,
		Pressable,
		VideoPlayer,
		AnimatedImage
	};

		/// @todo delete this constructor
		View(std::shared_ptr<ViewNode> viewNode);
        
    View(View::Type viewType, std::function<std::shared_ptr<ViewNode>()> builder);

		/// @brief Virtual destructor of the View class.
		virtual ~View();

		std::shared_ptr<ViewNode> GetViewNode();
    std::shared_ptr<ViewNode> GetConstViewNode() const;
    View::Type GetViewType() const { return _type; }
    
		virtual std::shared_ptr<View> Clone() const { return nullptr; }

		/// @addtogroup modifier_layout
    /// @{
    /// @name Size Modifiers
		/// @{
		
		/**
		 * @brief Sets the minimum size constraints for the view
		 * @param minWidth Minimum width in pixels
		 * @param minHeight Minimum height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& minSize(float minWidth, float minHeight);
		/**
		 * @brief Sets the minimum width constraint for the view
		 * @param minWidth Minimum width in pixels
		 * @return Reference to this view for method chaining
		 */
		View& minWidth(float minWidth);
		/**
		 * @brief Sets the minimum height constraint for the view
		 * @param minHeight Minimum height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& minHeight(float minHeight);

		/**
		 * @brief Sets the maximum size constraints for the view
		 * @param maxWidth Maximum width in pixels
		 * @param maxHeight Maximum height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& maxSize(float maxWidth, float maxHeight);
		/**
		 * @brief Sets the maximum width constraint for the view
		 * @param maxWidth Maximum width in pixels
		 * @return Reference to this view for method chaining
		 */
		View& maxWidth(float maxWidth);
		/**
		 * @brief Sets the maximum height constraint for the view
		 * @param maxHeight Maximum height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& maxHeight(float maxHeight);

		/**
		 * @brief Sets the exact size of the view
		 * @param width Width in pixels
		 * @param height Height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& size(float width, float height);
		/**
		 * @brief Sets the exact width of the view
		 * @param width Width in pixels
		 * @return Reference to this view for method chaining
		 */
		View& width(float width);
		/**
		 * @brief Sets the exact height of the view
		 * @param height Height in pixels
		 * @return Reference to this view for method chaining
		 */
		View& height(float height);

    // [0, 1.f]
		/**
		 * @brief Sets the width as a percentage of the parent's width
		 * @param percent Percentage value between 0.0 and 1.0
		 * @return Reference to this view for method chaining
		 */
		View& percentWidth(float percent);
		/**
		 * @brief Sets the height as a percentage of the parent's height
		 * @param percent Percentage value between 0.0 and 1.0
		 * @return Reference to this view for method chaining
		 */
		View& percentHeight(float percent);
    /**
     * @brief Sets the minimum width as a percentage of the parent's width
     * @param percent Percentage value between 0.0 and 1.0
     * @return Reference to this view for method chaining
     */
    View& percentMinWidth(float percent);
    /**
     * @brief Sets the minimum height as a percentage of the parent's height
     * @param percent Percentage value between 0.0 and 1.0
     * @return Reference to this view for method chaining
     */
    View& percentMinHeight(float percent);
    /**
     * @brief Sets the maximum width as a percentage of the parent's width
     * @param percent Percentage value between 0.0 and 1.0
     * @return Reference to this view for method chaining
     */
    View& percentMaxWidth(float percent);
    /**
     * @brief Sets the maximum height as a percentage of the parent's height
     * @param percent Percentage value between 0.0 and 1.0
     * @return Reference to this view for method chaining
     */
    View& percentMaxHeight(float percent);
    
    /**
     * @brief Sets the ideal size of a view
     * @param width ideal width
     * @param height ideal height
     * @return Reference to this view for method chaining
     */
    View& idealSize(float width, float height);
    
    /**
     * @brief Sets the ideal width of a view
     * @param width ideal width
     * @return Reference to this view for method chaining
     */
    View& idealWidth(float width);
    
    /**
     * @brief Sets the ideal height of a view
     * @param height ideal height
     * @return Reference to this view for method chaining
     */
    View& idealHeight(float height);
    
    /**
     * @brief Makes the view's size fixed (non-flexible)
     * @return Reference to this view for method chaining
     */
    View& fixedSize();
    /**
     * @brief Sets whether width and/or height are fixed
     * @param width Whether width is fixed
     * @param height Whether height is fixed
     * @return Reference to this view for method chaining
     */
    View& fixedSize(bool width, bool height);
    /**
     * @brief Sets the layout priority for flexible sizing
     * @param priority Layout priority value (higher values get more space)
     * @return Reference to this view for method chaining
     */
    View& layoutPriority(float priority);

		/// @}
    /// @}
		
		/// @addtogroup modifier_layout
		/// @{
		/// @name Padding Modifiers
		/// @{

		/**
		 * @brief Sets padding using edge insets
		 * @param insets Edge insets structure defining padding for all edges
		 * @return Reference to this view for method chaining
		 */
		View& padding(const Layout::EdgeInsets& insets);
		/**
		 * @brief Sets padding for each edge individually
		 * @param left Left padding in pixels
		 * @param top Top padding in pixels
		 * @param right Right padding in pixels
		 * @param bottom Bottom padding in pixels
		 * @return Reference to this view for method chaining
		 */
		View& padding(float left, float top, float right, float bottom);
		/**
		 * @brief Sets padding for specific edges
		 * @param edges Set of edges to apply padding to
		 * @param length Padding amount in pixels
		 * @return Reference to this view for method chaining
		 */
		View& padding(const Layout::EdgeSet& edges, float length);
		/**
		 * @brief Sets uniform padding for all edges
		 * @param length Padding amount in pixels for all edges
		 * @return Reference to this view for method chaining
		 */
		View& padding(float length);
		
		/// @}
		/// @}
		
		/// @addtogroup modifier_layout
		/// @{
		/// @name Flex Layout Modifiers
		/// @{
		
		/**
		 * @brief Sets the alignment of child views within this container
		 * @param alignment Alignment value (e.g., center, start, end)
		 * @return Reference to this view for method chaining
		 */
		View& alignment(Layout::Alignment alignment);
		/**
		 * @brief Sets how child views are distributed along the main axis
		 * @param justify Justification value (e.g., center, spaceBetween, spaceAround)
		 * @return Reference to this view for method chaining
		 */
		View& justifyContent(Layout::JustifyContent justify);

		/// @}
		/// @}
		
		/// @addtogroup modifier_layout
		/// @{
		/// @name LayeredStack Offset Modifiers
		/// @{
		
		/**
		 * @brief Sets the offset position (translation) for this view
		 * @param x Horizontal offset in pixels (positive = right, negative = left)
		 * @param y Vertical offset in pixels (positive = down, negative = up)
		 * @return Reference to this view for method chaining
		 * @note Offset applies translation after layout calculation without affecting sibling positions
		 */
		View& offset(float x, float y);
		
		/**
		 * @brief Sets the offset position (translation) for this view using a Position struct
		 * @param position Position containing x and y offset values
		 * @return Reference to this view for method chaining
		 * @note Offset applies translation after layout calculation without affecting sibling positions
		 */
		View& offset(const Layout::Position& position);

		/// @}
		/// @}
		
		/// @addtogroup modifier_visual
		/// @{
		/// @name Background Modifiers
		/// @{

		/**
		 * @brief Sets the background color with data binding support
		 * @param color Bindable color value (hex string or color name)
		 * @return Reference to this view for method chaining
		 */
		View& background(const Bind<std::string>& color);
		/**
		 * @brief Sets the background color
		 * @param color Color value (hex string or color name)
		 * @return Reference to this view for method chaining
		 */
		View& background(const char* color);
		
		/// @}
		/// @}
		
		/// @addtogroup modifier_visual
		/// @{
		/// @name Border Modifiers
		/// @{

		/**
		 * @brief Sets the border color with data binding support
		 * @param color Bindable color value (hex string or color name)
		 * @return Reference to this view for method chaining
		 */
		View& borderColor(const Bind<std::string>& color);
		/**
		 * @brief Sets the border color
		 * @param color Color value (hex string or color name)
		 * @return Reference to this view for method chaining
		 */
		View& borderColor(const char* color);
		/**
		 * @brief Sets the border gradient colors (4 colors for 4 corners)
		 * @param colors A vector of 4 color strings (hex or color name), mapped to top-left, top-right, bottom-right, bottom-left
		 * @return Reference to this view for method chaining
		 */
		View& borderGradientColors(const std::vector<std::string>& colors);
		/**
		 * @brief Sets the corner radius for rounded borders
		 * @param radius Bindable radius value in pixels
		 * @return Reference to this view for method chaining
		 */
		View& borderRadius(const Bind<float>& radius);
		/**
		 * @brief Sets the border width
		 * @param size Bindable border width in pixels
		 * @return Reference to this view for method chaining
		 */
		View& borderSize(const Bind<float>& size);
		/**
		 * @brief Sets different border widths for horizontal and vertical edges
		 * @param xWidth Bindable horizontal border width in pixels
		 * @param yWidth Bindable vertical border width in pixels
		 * @return Reference to this view for method chaining
		 */
		View& borderSize(const Bind<float>& xWidth, const Bind<float>& yWidth);

		/// @}
		/// @}
		
		/// @addtogroup modifier_visual
		/// @{
		/// @name Visibility Modifiers
		/// @{

		/**
		 * @brief Controls view visibility (hidden but takes up space)
		 * @param hidden Bindable boolean - true to hide, false to show
		 * @return Reference to this view for method chaining
		 */
		View& hidden(const Bind<bool>& hidden);
		/**
		 * @brief Controls view visibility (removed from layout when hidden)
		 * @param visible Bindable boolean - true to show, false to hide
		 * @return Reference to this view for method chaining
		 */
		View& visible(const Bind<bool>& visible);

		/// @}
		/// @}
		
		/// @addtogroup modifier_event_handling
		/// @{
		/// @name Interactivity Modifiers
		/// @{

		/**
		 * @brief Enables or disables user interaction with the view
		 * @param enabled Bindable boolean - true to enable, false to disable
		 * @return Reference to this view for method chaining
		 */
		View& enabled(const Bind<bool>& enabled);
		/**
		 * @brief Forces the view to be enabled regardless of parent state
		 * @return Reference to this view for method chaining
		 */
        View& forceEnabled();
		/**
		 * @brief Forces the view to be focusable for accessibility and focus traversal
		 * @return Reference to this view for method chaining
		 */
		View& forceFocusable();
		/**
		 * @brief Controls keyboard focus state of the view
		 * @param focused Bindable boolean - true to focus, false to unfocus
		 * @return Reference to this view for method chaining
		 */
		View& focused(const Bind<bool>& focused);
    
		/// @}
		/// @}
		
		/// @addtogroup modifier_event_handling
		/// @{
		/// @name Input Event Modifiers
		/// @{
		
    /**
     * @brief Sets a callback for mouse hover events
     * @param callback Function called with true on hover enter, false on hover exit
     * @return Reference to this view for method chaining
     */
    View& onHover(std::function<void(bool)> callback);
        
        /**
         * @brief Sets a callback for focus events
         * @param callback Function called with true when focused, false when not focused
         * @return Reference to this view for method chaining
         */
        View& onFocus(std::function<void(bool)> callback);
		/**
		 * @brief Sets a callback for click events
		 * @param callback Function called when the view is clicked
		 * @return Reference to this view for method chaining
		 */
		View& onClick(std::function<void()> callback);
		/**
		 * @brief Sets a callback for value change events
		 * @param callback Function called when the view's value changes
		 * @return Reference to this view for method chaining
		 */
		View& onChange(std::function<void()> callback);
		
		/// @}
		/// @}
		
		/// @addtogroup modifier_event_handling
		/// @{
		/// @name Lifecycle Event Modifiers
		/// @{
		
		/**
		 * @brief Sets a callback for when the view appears on screen
		 * @param action Function called when the view becomes visible
		 * @return Reference to this view for method chaining
		 */
		View& onAppear(const std::function<void()>& action);
		/**
		 * @brief Sets a callback for when the view disappears from screen
		 * @param action Function called when the view is removed or hidden
		 * @return Reference to this view for method chaining
		 */
		View& onDisappear(const std::function<void()>& action);

		/// @}
		/// @}
		
		/// @addtogroup modifier_accessibility
		/// @{
		/// @name Accessibility Modifiers
		/// @{

    // Accessibility
    /**
     * @brief Sets the accessibility name for screen readers
     * @param accName Bindable string for the accessible name
     * @return Reference to this view for method chaining
     */
    View& accessibilityName(const Bind<std::string>& accName);
    /**
     * @brief Sets the accessibility description for screen readers
     * @param accDescription Bindable string for the accessible description
     * @return Reference to this view for method chaining
     */
    View& accessibilityDescription(const Bind<std::string>& accDescription);
    /**
     * @brief Sets the accessibility help for screen readers(may not be read by default)
     * @param accHelp Bindable string for the accessible description
     * @return Reference to this view for method chaining
     */
    View& accessibilityHelp(const Bind<std::string>& accHelp);
    /**
     * @brief Explicitly controls whether this node should be focusable for accessibility.
     * @param focusable True to make node focusable, false to make node non-focusable.
     * @return Reference to this view for method chaining
     */
    View& accessibilityFocusable(bool focusable);
    /**
     * @brief Controls whether this node's own text should be ignored when assembling accessibility speech text.
     * @param ignore True to ignore self text, false to include it.
     * @return Reference to this view for method chaining
     */
    View& accessibilityIgnoreSelfText(bool ignore = true);
    /**
     * @brief Sets accessibility children policy for this node.
     * @param policy Accessibility children policy.
     * @return Reference to this view for method chaining
     */
    View& accessibilityChildrenPolicy(AccessibilityChildrenPolicy policy);
    /**
     * @brief Sets high-level accessibility intent.
     * @param intent Accessibility intent value
     * @return Reference to this view for method chaining
     */
    View& accessibilityIntent(AccessibilityIntent intent);
    /**
     * @brief Sets the accessibility group name for related elements
     * @param groupName Bindable string for the group name
     * @return Reference to this view for method chaining
     */
    View& accessibilityGroupName(const Bind<std::string>& groupName);
    /**
    * @brief Sets the accessibility custom role
    * @param roleValue AccessibilityRole value
    * @return Reference to this view for method chaining
    */
    View& accessibilityCustomRole(AccessibilityRole roleValue) ;

		/// @}
		/// @}
		
		/// @addtogroup modifier_telemetry
		/// @{
		/// @name Telemetry Modifiers
		/// @{

    /**
     * @brief Sets the telemetry ID for the view_node (used by Inspector and telemetry reporting)
     * @param id Telemetry ID string
     * @return Reference to this view for method chaining
     */
    View& telemetryId(const std::string& id);
    /**
     * @brief Sets the telemetry module for the view_node (used to select IZS_*_Interaction and log category)
     * @param module TelemetryModule enum (e.g. email, meetings, chat). When meetings, uses ZMonitorLogCategory_PAAP_Meeting; otherwise ZMonitorLogCategory_PAAP_PT
     * @return Reference to this view for method chaining
     */
    View& telemetryModule(TelemetryModule module);

		/// @}
		/// @}
		
		/// @name Auxiliary View Modifiers
		/// @{
    /**
     * @brief Attaches a menu to this view
     * @tparam Args Variadic template arguments for menu items
     * @param views Menu items to include in the menu
     * @return Reference to this view for method chaining
     */
    template<typename... Args,
      typename = typename std::enable_if<std::conjunction<IsMenuArg<Args>...>::value>::type>
    View& menu(Args&&... views)
    {
      // use shared_ptr avoid build error
      std::shared_ptr<Menu> view = std::make_shared<Menu>(std::forward<Args>(views)...);
      AddMenu(*view, false);
      return *this;
    }

    /**
     * @brief Attaches a context menu to this view
     * @tparam Args Variadic template arguments for menu items
     * @param views Menu items to include in the context menu
     * @return Reference to this view for method chaining
     */
    template<typename... Args,
      typename = typename std::enable_if<std::conjunction<IsMenuArg<Args>...>::value>::type>
      View& contextMenu(Args&&... views)
    {
      std::shared_ptr<Menu> view = std::make_shared<Menu>(std::forward<Args>(views)...);
      AddMenu(*view, false);
      return *this;
    }

    /**
     * @brief Attaches a popup to this view (SwiftUI-style)
     * @param popupBuilder Function that builds and returns the popup content view
     * @return Reference to this view for method chaining
     * 
     * When the view is clicked, the popupBuilder is called to create the popup content.
     * The popup closes automatically when clicking outside or selecting an item.
     * 
     * Example:
     * @code
     * IconButton("more_icon")
     *   .popup([]() {
     *     return VerticalStack {
     *       Text("Option 1").onClick([]{}),
     *       Text("Option 2").onClick([]{}),
     *     };
     *   });
     * @endcode
     */
    View& popup(const std::function<std::shared_ptr<View>()>& popupBuilder);

    /**
     * @brief Attaches a popup with context for manual close control
     * @param popupBuilder Function that receives PopupContext and returns the popup view
     * @return Reference to this view for method chaining
     * 
     * Use this overload when you need manual control over when the popup closes.
     * Call ctx.close() to close the popup programmatically.
     * 
     * Example:
     * @code
     * Button("Show Options")
     *   .popupClosePolicy(PopupClosePolicy::Manual)
     *   .popup([](PopupContext& ctx) {
     *     return VerticalStack {
     *       Text("Select items..."),
     *       Button("Confirm").onClick([ctx]() mutable { ctx.close(); })
     *     };
     *   });
     * @endcode
     */
    View& popup(const std::function<std::shared_ptr<View>(PopupContext&)>& popupBuilder);

    /**
     * @brief Sets the close policy for the popup
     * @param policy How the popup should close
     * @return Reference to this view for method chaining
     * 
     * Policies:
     * - CloseOnSelect (default): Closes when clicking any item
     * - CloseOnOutsideClick: Only closes when clicking outside (for multi-select)
     * - Manual: Must call ctx.close() explicitly
     */
    View& popupClosePolicy(PopupClosePolicy policy);

		/// @}
		
		/// @name Other Modifiers
		/// @{
		
		/**
		 * @brief Sets a unique identifier for the view
		 * @param viewId Unique identifier string
		 * @return Reference to this view for method chaining
		 */
		View& id(const std::string& viewId);
		/**
		 * @brief Sets an observer for the view's control id
		 * @param observer Bindable string for the value
		 * @return Reference to this view for method chaining
		 */
    View& idObserver(const Bind<std::string>& observer);
		/**
		 * @brief Sets a test identifier for UI automation
		 * @param id Test identifier string. On Linux this is applied as QQuickItem
		 *        dynamic property "spixId" for Spix/AI tests.
		 * @return Reference to this view for method chaining
		 */
		View& testId(const std::string& id);
		/**
		 * @brief Sets a custom attribute on the view
		 * @param attribute Attribute string
		 * @return Reference to this view for method chaining
		 */
		View& attribute(const std::string& attribute);
		/**
		 * @brief Sets an environment value for this view and its children
		 * @param key Environment key
		 * @param val Environment value
		 * @return Reference to this view for method chaining
		 */
		View& environment(const std::string& key, const EnvironmentValue& val);
		
		/**
		 * @brief Sets this view as LoopList container's item
		 * @return Reference to this view for method chaining
		 */
    View& loopListItem();

		/**
     * @brief Sets the dark mode state with data binding support
     * @param darkMode Bindable boolean - true for dark mode, false for light mode
     * @return Reference to this view for method chaining
     */
    View& darkMode(const Bind<bool>& darkMode);
    
    View& gridVerticalAlignment(Layout::Alignment alignment);
    View& gridHorizontalAlignment(Layout::Alignment alignment);
    View& gridColumnSpan(unsigned int span);
		
		/// @}
		/// @}
        
        /**
         * @brief Sets the text content of the tooltip, the keyboard input character for the shortcut and multiple keyboard modifier keys for the shortcut
         * @param text The text to display
         * @param key The key character (e.g., "S", "C", "Enter")
         * @param modifier (e.g., ToolTipModifier::kShift | ToolTipModifier::kControl)
         * @return Reference to this view for method chaining
         */
        View& toolTip(const std::string& text, const std::string& key = "", uint32_t modifier = 0);
       
        /**
         * @brief Set the display direction of the popover
         * @param popoverDirection the display direction of the popover
         * @return Reference to this view for method chaining
         */
        View& popoverDirection(PopoverDirection popoverDirection);
        
        /**
         * @brief Set whether the popover can be focused
         * @param popoverCanFocus whether the popover can be focused
         * @return Reference to this view for method chaining
         */
        View& popoverCanFocus(bool popoverCanFocus);

        /**
         * @brief Set popover trigger mode
         * @param mode popover trigger mode
         * @return Reference to this view for method chaining
         */
        View& popoverTriggerMode(const Bind<PopoverTriggerMode>& mode);

        /**
         * @brief Set whether to show popover arrow
         * @param popoverArrow whether the popover arrow is visible
         * @return Reference to this view for method chaining
         */
        View& popoverArrow(bool popoverArrow);
        
        /**
         * @brief Set up the popover view
         * @param popoverView popover view
         * @return Reference to this view for method chaining
         */
        View& popover(const View& popoverView);

        /**
         * @brief Attach a popover whose content is built lazily and receives a
         *        PopoverContext for manual close control
         * @param popoverBuilder Function that receives PopoverContext and returns
         *        the popover root view. Inside the builder you may, for example,
         *        wire up a close button via `ctx.close()`.
         * @return Reference to this view for method chaining
         *
         * @note  This overload is intended to be paired with `popoverAutoShow(true)`
         *        so the popover content can dismiss itself, but it is also usable
         *        with the regular hover/focus trigger flow.
         */
        View& popover(const std::function<std::shared_ptr<View>(PopoverContext&)>& popoverBuilder);

        /**
         * @brief Auto-show the popover when the anchor view appears.
         *
         * When set to `true`:
         *   - The popover is shown automatically in `OnAppear` (akin to
         *     `viewDidAppear`) and is hidden automatically in `OnDisappear`.
         *   - The legacy hover / focus / Space-to-toggle trigger logic is
         *     bypassed for this view.
         *   - The popover can be dismissed by:
         *       - Calling `PopoverContext::close()` from inside a builder-style
         *         popover (e.g. from a close button), or
         *       - The anchor view disappearing.
         *
         * When set to `false` (default): the original hover/focus/Space trigger
         * behaviour is used.
         *
         * @param autoShow whether to auto-show on appear
         * @return Reference to this view for method chaining
         */
        View& popoverAutoShow(bool autoShow);

        /**
         * @brief Whether the auto-show popover has already been shown.
         *
         * When paired with `popoverAutoShow(true)`, the popover is only shown
         * from `OnAppear` while this value is false.
         *
         * @param hasShow true if this auto-show popover has already been shown
         * @return Reference to this view for method chaining
         */
        View& popoverHasShow(const Bind<bool>& hasShow);

        /**
         * @brief Set the popover window title (used when the popover is shown)
         * @param title window title string
         * @return Reference to this view for method chaining
         */
        View& popoverWindowTitle(const std::string& title);

        /**
         * @brief Set callback when popover is shown
         * @param callback callback to invoke when popover is shown
         * @return Reference to this view for method chaining
         */
        View& onPopoverShow(std::function<void()> callback);

        /**
         * @brief Set callback when popover is hidden
         * @param callback callback to invoke when popover is hidden
         * @return Reference to this view for method chaining
         */
        View& onPopoverHide(std::function<void()> callback);

        /**
         * @brief Set callback when mouse enters popover
         * @param callback callback to invoke when mouse enters popover
         * @return Reference to this view for method chaining
         */
        View& onPopoverMouseEnter(std::function<void()> callback);

        /**
         * @brief Set callback when mouse exits popover
         * @param callback callback to invoke when mouse exits popover
         * @return Reference to this view for method chaining
         */
        View& onPopoverMouseExit(std::function<void()> callback);
		
		operator std::shared_ptr<ViewNode>() { return GetViewNode(); }
		
		virtual void SetHidden(bool hidden);

  private:
    void AddMenu(Menu& menu, bool isContext);
        
        
    protected:
		std::shared_ptr<ViewNode> _viewNode = nullptr;
        std::function<std::shared_ptr<ViewNode>()> _builder;
        View::Type _type;
	};

    class ZUI_API CustomHelper
    {
    protected:
        std::shared_ptr<ViewNode> InitView();
        void FinalizeView(std::shared_ptr<ViewNode> viewNode, std::shared_ptr<View> view, std::function<std::shared_ptr<ViewNode>()> build);
    };

    template<typename Derived>
    class CustomView : public View, public CustomHelper {
    public:
        CustomView() : View(View::Type::Custom, GetCustomViewBuilder())
        {
        }
        
       std::shared_ptr<View> Clone() const override {
            static_assert(std::is_copy_constructible<Derived>::value,
                      "Type must be copy-constructible");
                      
           return std::make_shared<Derived>(static_cast<const Derived&>(*this));
       }
        
       virtual std::shared_ptr<ViewNode> Build() { return nullptr; }
        
    private:
        ~CustomView() = default;
        friend Derived;
      
        std::function<std::shared_ptr<ViewNode>()> GetCustomViewBuilder()
        {
            return [&]() {
                _viewNode = InitView();
                // Clone to allow independent lifecycle
                std::shared_ptr<Derived> view = std::static_pointer_cast<Derived>((this)->Clone());
                FinalizeView(_viewNode, view, [this, view]() -> std::shared_ptr<ViewNode> {return (view ? view->Build() : nullptr);});
                return _viewNode;
            };
        }
    };

    namespace p
    {
      class ZUI_API PipeModifier {
      public:
        virtual ~PipeModifier() = default;

        // Operator overloads for both lvalue and rvalue references
        View& operator()(View& view) const { apply(view); return view; }
        View& operator()(View&& view) const { apply(view); return view; }

      protected:
        virtual void apply(View& view) const = 0;
      };
    }

} // namespace zui

#endif //ZUI_VIEW
