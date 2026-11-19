//
//  IZMPTSidePanelMgr.h
//  PTUIBridge
//
//  Created by fistice on 2024/12/27.
//

typedef NS_OPTIONS(NSUInteger, ZMPTSidebarItemType) {
    ZMPTSidebarItemTypeNone = 0,
    ZMPTSidebarItemTypeCalendar = 1 << 0,
    ZMPTSidebarItemTypeAIC = 1 << 1,
    ZMPTSidebarItemTypeDisasterMode = 1 << 2,
    ZMPTSidebarItemTypeActivityCenter = 1<< 3,
};
NS_ASSUME_NONNULL_BEGIN
@protocol ZMPTSidebarDelegate;
@protocol ZMPTSidebarItemProtocol;
@protocol ZMPTSidebarItemDelegate;
//--IZMPTSidePanelMgr
@protocol IZMPTSidePanelMgr <ZMPTRoutableObject>

@property (weak) id<ZMPTSidebarDelegate> delegate;

@property (nonatomic,getter=isNewAICHomeTabSelected) BOOL newAICHomeTabSelected;
@property (nonatomic, assign) BOOL isPoppingIn;

//!< register item to use the type to change
- (BOOL)registerItem:(id<ZMPTSidebarItemProtocol>)item;
- (BOOL)unRegisterItem:(id<ZMPTSidebarItemProtocol>)item;
- (void)unRegisterItemForType:(ZMPTSidebarItemType)type;

//!< show or hide item, NOT require register
- (void)expandItem:(id<ZMPTSidebarItemProtocol>)item;
- (BOOL)popInItem:(id<ZMPTSidebarItemProtocol>)item;
- (BOOL)popOutItem:(id<ZMPTSidebarItemProtocol>)item;
- (void)collapseItem:(id<ZMPTSidebarItemProtocol>)item;
- (BOOL)invertDisplayedItem:(id<ZMPTSidebarItemProtocol>)item;

//!< show or hide item by type, require register
- (BOOL)expandItemByType:(ZMPTSidebarItemType)type;
- (BOOL)popInItemByType:(ZMPTSidebarItemType)type;
- (BOOL)popOutItemByType:(ZMPTSidebarItemType)type;
- (NSWindow *)popOutItemByType:(ZMPTSidebarItemType)type andFrame:(NSRect)frame;
- (BOOL)collapseItemByType:(ZMPTSidebarItemType)type;
- (BOOL)invertDisplayedItemByType:(ZMPTSidebarItemType)type;

- (BOOL)isDisplayedItemByType:(ZMPTSidebarItemType)type;
- (BOOL)isItemExpandInSidebarByType:(ZMPTSidebarItemType)type;
- (BOOL)isPopOutDisplayedItemByType:(ZMPTSidebarItemType)type;
- (id<ZMPTSidebarItemProtocol>)getRegisteredByType:(ZMPTSidebarItemType)type;

- (void)collapseItemInSidebar:(id<ZMPTSidebarItemProtocol>)item;
- (void)showItemInSidebar:(id<ZMPTSidebarItemProtocol>)item;

- (ZMPTSidebarItemType)getStoredLastType;
- (NSWindow *)getDisplayedItemWindowByType:(ZMPTSidebarItemType)type;

- (BOOL)isEmpty;
- (void)setPreferedWidth:(CGFloat)preferedWidth;
// TODO: should mirror DidChange across all transitions; for now only fires on
// collapsed -> expanded to unblock the urgent Home AIC mutual-exclusion need.
- (void)itemDisplayedStatusWillChange;
- (void)itemDisplayedStatusDidChange;

- (void)collapseAllItemsInSidebar;
@end

// ZMEventRegister(self, ZMPTSidebarEventProtocol)
@protocol ZMPTSidebarEventProtocol <NSObject>

// [ZMPTSharedFor(IZMPTSidePanelMgr) isEmpty]
- (void)onPTSidebarDisplayedStatusDidChange;
@optional
// TODO: should mirror DidChange; currently only posted before collapsed -> expanded
// (Home needs to close AIC before sidebar layout to avoid window-resize flicker).
- (void)onPTSidebarDisplayedStatusWillChange;
@end

//--ZMPTSidebarItemProtocol
@protocol ZMPTSidebarItemProtocol <NSObject>
@required
//@property (nonatomic, readonly) NSView *view;
@property (nonatomic, retain, readwrite) __kindof NSView *view;
@property (weak) id<ZMPTSidebarItemDelegate> delegate;
@property (readonly) BOOL isDisplayed;
@property (nonatomic) CGFloat maxWidth;
@property (nonatomic) CGFloat minWidth;
@property (nonatomic) CGFloat preferedWidth;
@property (nonatomic) ZMPTSidebarItemType type;
@property (nonatomic) BOOL isPoppingOut;
@property (nonatomic) BOOL isLastPopout;
@property (nonatomic, assign) NSInteger maxNumSharedView;
@property (nonatomic, copy) NSString *title;
@property (readonly, nullable) NSWindow *popOutWindow;
- (void)itemDisplayedStatusDidChange;
- (void)closePopoutWindow;
- (void)popOut;
- (void)popOutWithFrame:(NSRect)frame;
- (void)popIn;
@end
//--ZMPTSidebarDelegate
@protocol ZMPTSidebarDelegate <NSObject>
@required
- (void)expandSidebar;
- (void)collapseSidebar;
- (BOOL)canShowSideBar;
- (BOOL)isSidebarExpanded;
@end
//--ZMPTSidebarItemDelegate
@protocol ZMPTSidebarItemDelegate <NSObject>
@required
- (void)itemDisplayedStatusDidChange:(id<ZMPTSidebarItemProtocol>)sender displayed:(BOOL)displayed;
@optional
- (void)itemPreferedWidthDidChange:(id<ZMPTSidebarItemProtocol>)sender width:(CGFloat)width;
@end

NS_ASSUME_NONNULL_END
