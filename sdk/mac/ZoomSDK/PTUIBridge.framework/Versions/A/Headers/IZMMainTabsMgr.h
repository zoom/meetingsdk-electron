//
//  IZMMainTabsMgr.h
//  PTUIBridge
//
//  Created by fistice on 2/28/25.
//

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/ZMTabDefineHeader.h>
#import <PTUIBridge/ZMBannerItem.h>
#import <PTUIBridge/ZMHTabViewDelegate.h>
#import <PTUIBridge/ZMViewMgr.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBannerItem;
@class ZMDynamicTabItemMgr;
@protocol ZMUnifyWebViewProtocol;

@protocol IZMMainTabsMgr <ZMPTRoutableObject, ZMViewProviding,ZMHTabViewDelegate>

@property (nonatomic, readonly) ZMMainTabsType currentType;

@property (readonly, getter=isViewLoaded) BOOL viewLoaded;
@property (readonly, getter=isViewAppeared) BOOL viewAppeared;
@property (retain, nonatomic, nullable) IBOutlet NSView *headerView;
@property (readonly, nonatomic) NSArray <ZMTabItem *> *arrangedTabItems;

//tabItems
- (void)updateTabs;
- (void)invalidateForVisibilityChange;
- (void)forceUpdateUIImage;
- (nullable ZMTabItem *)tabItemForAssociatedMgr:(__kindof ZMTabItemMgr *)itemMgr;
- (BOOL)isTabDisplayed:(ZMTabItem *)tabItem;
- (BOOL)availabilityOfItem:(ZMTabItem *)item;
- (BOOL)isSelectedItem:(ZMTabItem *)item;

//history
- (void)onSessionHistoryChanged;
//unread count
- (void)onWebChatUnreadCountChanged:(NSInteger)count showDot:(BOOL)showDot;

- (nullable id<ZMUnifyWebViewProtocol>)getWebViewOfTab:(NSString *)TabID;
- (NSString *)getWebviewIDOfTab:(NSString *)TabID;
- (BOOL)isVisibleOfTab:(NSString *)TabID;

//actions
- (void)onMenuSelectNextTab;
- (void)updateSidebarButtons;
- (void)selectTabAt:(NSUInteger)index;
- (BOOL)isSelectedMgr:(ZMTabItemMgr *)itemMgr;
- (void)updateStatusMessageActiveTimeBanner;
- (void)selectItemWithAssociatedMgr:(nullable __kindof ZMTabItemMgr *)itemMgr;

//tips
- (NSView *)tipHostViewForMgr:(__kindof ZMTabItemMgr *)itemMgr;
- (nullable NSString *)getTabIdentifierFromType:(ZMMainTabsType)type;

//header view
- (void)layoutHeader;

// Notification center
- (void)showNotificationDetailWindow;

//tabMgr
- (nullable __kindof ZMTabItemMgr *)mgrWithType:(ZMMainTabsType)type;

//Popout
- (void)bringToFrontTabItem:(ZMTabItem *)tabItem;
- (void)mergeBackTabItem:(ZMTabItem *)tabItem;
- (void)popoutMail:(BOOL)isPop;
- (void)popoutCalendar:(BOOL)isPop;
- (BOOL)isTabCanPop:(ZMTabItem * )tabItem;
- (BOOL)isTabPopped:(ZMTabItem *)tabItem;
- (void)popOutTabItem:(ZMTabItem *)tabItem;
- (void)tabPopOutWithIdentifier:(NSString *)tabIdentifier;

- (BOOL)popOutUrl:(NSString *)url ofType:(ZMMainTabsType)type;
- (BOOL)popOutView:(NSView *)view ofType:(ZMMainTabsType)type identifier:(NSString *)identifier;
- (void)openDetachedZappTab:(NSString *)tabId;
- (void)closeDetachedZappTab:(NSString *)tabId;
- (void)openClipsWebViewWithUrlString:(NSString *)urlStr;
- (void)popoutTabNoteWithURL:(NSString *)urlStr;
//move & drag
- (void)saveCurrentTabItemsOrder;
- (void)sortTabItems:(NSMutableArray <ZMTabItem *> *)items;

//report
- (void)showReportWindow;
- (void)onHelpCenter:(id)sender;
- (void)onWorkvivoHelp:(id)sender;
- (void)onZoomCommunity:(id)sender;
- (void)onReport:(id)sender;

//profile
- (void)showDownloadMobileDialog;
- (void)closeDownloadMobileDialog;
- (void)showPersonalNoteView;

- (void)refreshTabToken:(NSDictionary *)param;
- (void)getTabToken:(NSDictionary *)param;

//dynamic tabs
- (void)storeDynamicTabManagers:(NSArray<ZMDynamicTabItemMgr *> *)dynamicTabManagers;
- (void)applyDynamicTabsUpdate;

//Banner
- (void)responseVisibleStatus;
@end

NS_ASSUME_NONNULL_END
