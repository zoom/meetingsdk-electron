//
//  ZMTabWidgets.h
//  NewUI
//
//  Created by Huxley Yang on 11/01/2018.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMMainTabsContentView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMTabTipsType) {
    ZMTabTipsTypeFirst,
    ZMTabTipsTypeEmptyMoreMenu,
    ZMTabTipsTypeMustOne
};

typedef NS_OPTIONS(NSUInteger, ZMTabUpdateBits) {
    ZMTabUpdateNone = 0,
    ZMTabUpdateSelectedTabItemChanged = 1 << 0,
    ZMTabUpdateOrderChanged = 1 << 1,
    ZMTabUpdateFrame = 1 << 2,
    ZMTabUpdateWithAnimation = 1 << 3,
    ZMTabUpdateMenu = 1 << 4,
    ZMTabUpdateLayoutDisplayItems = 1 << 5,
    ZMTabUpdateShowTip = 1 << 6,
};

typedef NS_OPTIONS(NSUInteger, ZMTabWidgetLayoutStyle) {
    ZMTabWidgetLayoutHorizontal = 0,
    ZMTabWidgetLayoutVertical = 1
};

typedef NS_ENUM(NSUInteger, ZMTabItemDisplayMode) {
    ZMTabItemDisplayModeIconAndText = 0,
    ZMTabItemDisplayModeIconOnly = 1
};

@class ZMHTabView, ZMTabItem;

@protocol ZMTabWidgetsDelegate <NSObject>

@optional
//data source delegate
- (BOOL)availabilityOfItem:(ZMTabItem *)item;
- (BOOL)isTabNeedPop:(ZMTabItem *)tabItem;
- (BOOL)isTabLoaded:(ZMTabItem *)tabItem;
- (BOOL)isTabPopped:(ZMTabItem *)tabItem;

//base event
- (void)tabWidgetsOnSearch;
- (void)tabWidgetsOnSetting;
- (void)onTabItemsDidChanged;
- (void)showUpgradeDialogForItem:(ZMTabItem *)item;

//tab mouse event
- (void)onTabItemRightMouseDown:(ZMTabItem *)tabItem event:(NSEvent *)event;
- (void)onMorePanelCellRightMouseDown:(ZMTabItem *)tabItem event:(NSEvent *)event cellView:(NSView *)cellView;
- (void)onTabItemSelected:(ZMTabItem *)tabItem;
- (void)onTabItemPerformDragOperation:(id <NSDraggingInfo>)sender;

//MorePanel popout delegate
/// Called when dragging moves in MorePanel - allows handling popout/merge logic
- (void)onMorePanelDraggingMovedToPoint:(NSPoint)screenPoint tabItem:(ZMTabItem *)tabItem cellImage:(NSImage *)cellImage session:(NSDraggingSession *)session;
/// Called to check if a tab item can be popped out
- (BOOL)canPopOutTabItem:(ZMTabItem *)tabItem;
/// Returns YES if the tab item is currently popped out
- (BOOL)isTabItemPoppedOut:(ZMTabItem *)tabItem;

//mouse event
- (void)onMoveLeft:(ZMTabItem *)currentTabItem preItem:(ZMTabItem *)preItem;
- (void)onMoveRight:(ZMTabItem *)currentTabItem nextItem:(ZMTabItem *)nextItem;

- (NSString *)getAccessibilityValue:(ZMTabItem *)item;
@end

@interface ZMTabWidgets : NSView

@property (weak) id <ZMTabWidgetsDelegate,ZMMainTabsContentViewDelegate> delegate;

@property (nonatomic, assign) BOOL needShowSearch;
@property (nonatomic, assign) BOOL needShowSetting;
@property (nonatomic, assign) BOOL needPopout;

@property (nonatomic, retain) NSMutableArray <ZMTabItem *> *itemsDisplay;
@property (nonatomic, retain) NSMutableArray <ZMTabItem *> *itemsCollapsed;
@property (nonatomic, strong) NSMutableArray<ZMTabItem *> *tabItems;

@property (nullable, retain) ZMTabItem *selectedTabItem;
@property (nonatomic, retain) ZMTabItem *focusedTabItem;
@property (nonatomic, retain) ZMTabItem *moreItem;
@property (nonatomic, retain) ZMBubbleObject* bubbleObj;
@property (nonatomic, assign) BOOL needShowMustOneTips;
@property (nonatomic, assign) BOOL dragFromWidget;
@property (nonatomic, assign) ZMTabWidgetLayoutStyle layoutStyle;
@property (nonatomic, assign) ZMTabItemDisplayMode tabItemDisplayMode;
@property (nonatomic, strong) ZMMainTabsContentView *contentView;
@property (nonatomic, assign) BOOL draggingEnabled;  // Default: YES (dragging enabled)
@property (nonatomic, assign) BOOL showResetControl;  // Default: YES (show reset control)
@property (nonatomic, strong) ZMTabItem *temporaryTabItem;

// Live preview of a More-panel item being dragged onto the bar: relayoutItems VIRTUALLY inserts it at previewInsertVisibleIndex (active tab protected, a non-active neighbor previewed into overflow) without mutating tabItems/currentNavList. Model changes only on commit; cancel clears these and relayouts to restore prior state, no snapshot needed.
@property (nonatomic, strong, nullable) ZMTabItem *previewIncomingItem;
@property (nonatomic, assign) NSInteger previewInsertVisibleIndex;  // slot among visible pins
// Pinned order relayoutItems produced for the active preview; commit copies it verbatim so the committed model reproduces exactly what the preview showed.
@property (nonatomic, copy, nullable) NSArray<ZMTabItem *> *lastPreviewedPinnedOrder;

// Pre-drag pin state of the More-panel item being dragged, and whether it committed onto the bar or back onto the More panel. Session-end restores isPin only when neither commit happened (Prism can flip isPin as the cursor passes a section).
@property (nonatomic, weak, nullable) ZMTabItem *incomingDragItem;
@property (nonatomic, assign) BOOL incomingDragWasPinned;
@property (nonatomic, assign) BOOL incomingDragCommitted;
@property (nonatomic, assign) BOOL incomingPanelDropCommitted;
// Mouse offset within the dragged item at drag start (item's own coords); lets popout hit-testing reconstruct the dragged item rect from the mouse point.
@property (nonatomic, assign) NSPoint popoutDragGrabOffset;

- (void)updateUI;
- (void)updateUI:(ZMTabUpdateBits)updateBits;
- (void)setNeedsUpdateUI:(ZMTabUpdateBits)updateBits;
- (void)updateSelection;
- (void)moveSelectionToNextPositionRight:(BOOL)rightDirection wrapAround:(BOOL)shouldWrap;//ZOOM-31518
- (void)showMustOneTabTips;
- (void)relayoutMustOneBubble;
- (void)focusFirstItem;
- (void)focusLastItem;
- (BOOL)isItemCollapsed:(ZMTabItem *)item;
- (void)setMoreItemHover:(BOOL)hover;
- (BOOL)isTabPopped:(ZMTabItem *)tabItem;
- (void)moveSelectionTabAtIndex:(NSUInteger)selectIndex;
- (void)selectTabItem:(ZMTabItem *)tabItem;
- (void)selectTabItem:(ZMTabItem *)tabItem force:(BOOL)force;
- (void)selectTabLeftToRight:(BOOL)direction wrapAround:(BOOL)shouldWrap;
- (void)onMoreButton:(ZMTabItemView *)sender;
- (BOOL)selectTabWithIdentifier:(NSString *)identifier;
- (nullable ZMTabItem *)getTabItemWithIdentifier:(NSString *)identifier;
- (NSArray<ZMTabItem *> *)getPinItems:(BOOL)isPin;
- (BOOL)isMorePannelOn;
- (BOOL)isMorePanelVisible;  // Only checks if MorePanel window exists and is visible
- (BOOL)isMorePanelDragging;  // YES while an in-panel drag (internal reorder) is in progress
- (BOOL)isScreenPointInsideMorePanel:(NSPoint)screenPoint;
- (BOOL)isTemporaryTabItem:(ZMTabItem *)tabItem;
- (void)clearTemporaryTab;
- (void)clearTemporaryTabWithUpdateUI:(BOOL)updateUI;
- (void)closeMorePanel;
- (void)populateMorePanelWithData;
@end

NS_ASSUME_NONNULL_END
