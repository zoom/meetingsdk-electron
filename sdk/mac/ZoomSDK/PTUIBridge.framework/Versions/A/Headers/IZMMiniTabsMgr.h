//
//  IZMMiniTabsMgr.h
//  PTUIBridge
//
//  Created by kay on 2/28/25.
//

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/ZMTabDefineHeader.h>
#import <Prism/ZMBaseKit.h>
#import <PTUIBridge/ZMTabWidgets.h>
#import <PTUIBridge/ZMHTabView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBannerItem;
@protocol ZMMiniTabsNavigationLayoutDelegate <NSObject>
- (void)miniTabsDidRequestNavigationWidth:(CGFloat)width;
@end

extern NSString *kZMUserDefaultSelectedTabType;
extern NSString *kZMUserDefaultSelectedTabIdentifier;
extern NSString *kZMUserDefaultTabDisplayModeIconOnly;

@protocol IZMMiniTabsMgr <ZMPTRoutableObject>

@property (nonatomic, readonly) ZMMainTabsType currentType;
@property (nonatomic, strong) NSMutableArray * _Nonnull currentNavList;
@property (nonatomic, weak, nullable) id<ZMMiniTabsNavigationLayoutDelegate> navigationLayoutDelegate;

//UI Compoent
- (ZMTabWidgets *)currentWidget;
- (ZMHTabView *)currentTabView;

//Tabs Resource
- (NSMutableArray<ZMTabItem *> *)getItemsFromRegistedTabsAndselectedItem:(ZMTabItem **)selectedItem;
- (NSString *)getLastSelectedTabIDAfterLogin;
- (ZMTabItem *)getTabItemWithTabIdentifier:(NSString *)identifier;
- (void)setupTabItems;
- (ZMTabItem *)findFirstPinTabItemWithSkipSelected:(BOOL)skipSelected;

//Tabs Orders
- (void)getCurrentNavListFromUserProfile;
- (void)sortTabItems:(NSMutableArray <ZMTabItem *> *)items;
- (NSArray <NSString *> *)defaultNavList;//server base order, profile default order, else local hardcode
- (nullable NSString * )getDefaultListStr;//server base order, nil when absent
- (NSString *_Nonnull)getFullNavListFromOrder:(NSString *_Nonnull)orderStr;
- (nullable NSString * )getOrderListStr;
- (void)resetTabItemsOrderToDefault;
- (void)resetNavIconList;
- (void)scheduleTabSync;
- (void)updateCurrentNavList;
//Pin / Unpin
- (nullable NSArray *)getPinList:(BOOL)isPin;
- (BOOL)isFirstLoadNewTabs;
- (void)setPinCount:(NSInteger)pinCount;
- (void)setPinList:(BOOL)isPin listStr:(NSString *)listStr;
- (NSString *)getFullPinList:(BOOL)isPin hasPin:(BOOL)hasPin hasUnpin:(BOOL)hasUnpin lastPinStr:(NSString *)lastPinStr;
- (nullable NSArray *)getFullPinList:(BOOL)isPin;

//tab property
- (BOOL)isVisibleOfTab:(NSString *)TabID;
- (BOOL)isTabDisplayModeIconOnly;
- (void)setTabDisplayModeIconOnly:(BOOL)iconOnly;
- (void)applyTransientTabDisplayModeIconOnly:(BOOL)iconOnly;
- (CGFloat)currentNavigationWidth;
- (CGFloat)currentNavigationMinWindowWidth;
- (CGFloat)clampedNavigationWidth:(CGFloat)width;
- (CGFloat)targetNavigationWidthForIconOnlyMode:(BOOL)iconOnly;
- (BOOL)iconOnlyModeForNavigationWidth:(CGFloat)width;
- (void)setNavigationCompactMode:(BOOL)compact;
- (void)handleNavigationWidthChanged:(CGFloat)width final:(BOOL)final;
- (void)saveCurrentNavigationWidth;

//Server-configured / admin-ordered tabs (ClientTabInfo, login field 156),
//ingested by PTUI's ZMNavTabConfigSink into ZMNavTabConfigStore.

/// Drives order and priority. Not gated on fromSetting.
- (BOOL)hasServerNavConfig;
/// Drives pin enforcement and force reset only.
- (BOOL)isAdminEnforced;
- (BOOL)handleAdminForceOverrideIfNeeded;
/// Dynamic tabs and feature toggles have been applied — the tab set is complete.
- (void)navTabsDidBecomeReady;
- (void)ensureAtLeastOneVisibleTab;
/// -1 when the server config does not list `tabId`.
- (NSInteger)serverPriorityForTabId:(NSString *)tabId;
/// Fills only when absent, so ZPNS cannot overwrite a server-pushed priority.
/// Session-only.
- (void)fillSessionPriorityIfAbsent:(NSInteger)priority forTabId:(NSString *)tabId;

//Selected Tab Identifier Storage (supports both static and dynamic tabs)
- (nullable NSString *)getSelectedTabIdentifierForJid:(nullable NSString *)jid;
- (void)saveSelectedTabIdentifier:(nonnull NSString *)identifier forJid:(nullable NSString *)jid;

// ZOOM-1222402: persist the temp tab identifier independently so it survives relaunch; nil/empty clears it.
- (void)persistTemporaryTabIdentifier:(nullable NSString *)identifier;
- (nullable NSString *)getPersistedTemporaryTabIdentifier;

- (nullable NSString *)getCurrentTabID;
- (nullable NSString *)getCurrentDeeplinkTabId;

@optional
- (void)tabVisibleChanged:(NSString *)tabId visible:(BOOL)visible;
- (void)tabDidPopOut:(NSString *)tabId;
- (void)tabDidMergeBack:(NSString *)tabId;
// Posted when a tab is moved into the More menu (right-click unpin / drag to more /
// merge-back while unpinned). Observers that own the tab's webview can recycle it
// (ZOOM-1287305). Not posted for temporary tabs or popped-out tabs.
- (void)tabsMovedToMoreAndNeedRecycle:(NSString *)tabId;
- (void)selectTabItem:(ZMTabItem *_Nonnull)item updateCache:(BOOL)updateCache;

@end

NS_ASSUME_NONNULL_END
