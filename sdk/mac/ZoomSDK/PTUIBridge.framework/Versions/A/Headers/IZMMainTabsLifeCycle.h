//
//  IZMMainTabsLifeCycle.h
//  ChatUI
//
//  Created by Kay Fu on 10/25/24.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <PTUIBridge/ZMTabItem.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItem;
@class ZMDynamicTabItemMgr;
@class ZMUnifyWebViewDownloadParam;
@class ZMUnifyWebViewDownloadDecision;

#pragma mark - ═══════════════════════════════════════════════════════════════
#pragma mark - Instance Lifecycle Protocol (for Tab implementations)
#pragma mark - ═══════════════════════════════════════════════════════════════

/// Protocol for tab instances to implement lifecycle callbacks.
/// These are called directly on the tab instance.
@protocol IZMMainTabsLifeCycle <NSObject>

@optional

#pragma mark - Registration Lifecycle

/// Called before tab registration. Return NO to prevent registration.
/// Default returns YES (allow registration).
- (BOOL)onTabWillRegister;

/// Called after tab registration completed.
- (void)onTabDidRegister;

/// Legacy method for tab registration (kept for compatibility)
- (void)onTabRegister;

/// Called before tab unregistration. Return NO to prevent unregistration.
/// Default returns YES (allow unregistration).
- (BOOL)onTabWillUnregister;

/// Called after tab unregistration completed.
- (void)onTabDidUnregister;

/// Legacy method for tab unregistration (kept for compatibility)
- (void)onTabUnregister;

#pragma mark - Selection Lifecycle

/// Called before tab selection. Return NO to prevent selection.
/// Default returns YES (allow selection).
- (BOOL)onTabWillSelect;

/// Called after tab selection completed.
- (void)onTabDidSelect;

/// Legacy method for tab selection (kept for compatibility)
- (void)onTabSelected;

/// Called before tab deselection. Return NO to prevent deselection.
/// Default returns YES (allow deselection).
- (BOOL)onTabWillDeselect;

/// Called after tab deselection completed.
- (void)onTabDidDeselect;

#pragma mark - Initialization Lifecycle

/// Called when tab item is initialized
- (void)onTabItemInited:(ZMTabItem *)tabItem;

#pragma mark - Appearance Lifecycle

/// Called before tab view appears.
- (void)onTabWillAppear;

/// Called after tab view appeared.
- (void)onTabDidAppear;

/// Called before tab view disappears.
- (void)onTabWillDisappear;

/// Called after tab view disappeared.
- (void)onTabDidDisappear;

#pragma mark - Reload Lifecycle

/// Called before tab reload. Return NO to prevent reload.
/// Default returns YES (allow reload).
- (BOOL)onTabWillReload;

/// Called after tab reload completed.
- (void)onTabDidReload;

/// Legacy method for tab reload (kept for compatibility)
- (void)reloadTab;

#pragma mark - Reset Lifecycle

/// Called before tab reset. Return NO to prevent reset.
/// Default returns YES (allow reset).
- (BOOL)onTabWillReset;

/// Called after tab reset completed.
- (void)onTabDidReset;

/// Legacy method for tab reset (kept for compatibility)
- (void)onTabReset;

#pragma mark - Destroy Lifecycle

/// Called before tab destruction. Return NO to prevent destruction.
/// Default returns YES (allow destruction).
- (BOOL)onTabWillDestroy;

/// Called after tab destruction completed.
- (void)onTabDidDestroy;

@end

#pragma mark - ═══════════════════════════════════════════════════════════════
#pragma mark - Dynamic Tab Observer Protocol (for external observers via ZMEventPoster)
#pragma mark - ═══════════════════════════════════════════════════════════════

/// Protocol for observing dynamic tab lifecycle events from outside.
/// All methods receive the tab object directly, allowing access to all properties and methods.
///
/// Usage:
/// 1. Register: [ZMRouterCenter.shared registerTartget:self forProtocol:@protocol(IZMDynamicTabLifeCycleObserver)]
/// 2. Implement optional methods to observe lifecycle events
/// 3. Unregister: [ZMRouterCenter.shared unregisterTartget:self forProtocol:@protocol(IZMDynamicTabLifeCycleObserver)]
///
/// Example - Set custom UserAgent suffix:
/// @code
/// - (void)onDynamicTabWillCreateWebView:(ZMDynamicTabItemMgr *)tab {
///     if ([tab.tabId isEqualToString:@"my_tab"]) {
///         tab.webViewContainer.userAgentSuffix = @"MyApp/1.0";
///     }
/// }
/// @endcode
///
/// Example - Add cookie after webview loaded:
/// @code
/// - (void)onDynamicTabDidLoadWebView:(ZMDynamicTabItemMgr *)tab {
///     NSHTTPCookie *cookie = [NSHTTPCookie cookieWithProperties:@{
///         NSHTTPCookieName: @"token",
///         NSHTTPCookieValue: @"xxx",
///         NSHTTPCookieDomain: @".zoom.us",
///         NSHTTPCookiePath: @"/"
///     }];
///     [tab.webViewContainer addCookie:cookie];
/// }
/// @endcode
@protocol IZMDynamicTabLifeCycleObserver <NSObject>

@optional

#pragma mark - Initialization Events

/// Called after dynamic tab is initialized
- (void)onDynamicTabDidInitialize:(ZMDynamicTabItemMgr *)tab;

#pragma mark - Registration Events

/// Called before dynamic tab registration
- (void)onDynamicTabWillRegister:(ZMDynamicTabItemMgr *)tab;

/// Called after dynamic tab registration
- (void)onDynamicTabDidRegister:(ZMDynamicTabItemMgr *)tab;

#pragma mark - WebView Creation Events

/// Called before webview is created.
/// Use this to set configurationCustomizer block or userAgentSuffix.
- (void)onDynamicTabWillCreateWebView:(ZMDynamicTabItemMgr *)tab;

/// Called after webview is created (before loading URL)
- (void)onDynamicTabDidCreateWebView:(ZMDynamicTabItemMgr *)tab;

#pragma mark - WebView Load Events

/// Called before webview starts loading URL.
/// Use this to add cookies before navigation.
- (void)onDynamicTabWillLoadWebView:(ZMDynamicTabItemMgr *)tab;

/// Called after webview finishes loading URL.
/// Use this to add cookies or perform post-load operations.
- (void)onDynamicTabDidLoadWebView:(ZMDynamicTabItemMgr *)tab;

/// Called when webview load fails
- (void)onDynamicTabWebViewLoadFailed:(ZMDynamicTabItemMgr *)tab error:(nullable NSError *)error;

/// Called before a dynamic tab webview starts a file download.
/// Observers can modify `decision` in place to customize download behavior.
- (void)onDynamicTab:(ZMDynamicTabItemMgr *)tab
willPrepareDownloadDecision:(ZMUnifyWebViewDownloadDecision *)decision
       downloadParam:(ZMUnifyWebViewDownloadParam *)downloadParam;

#pragma mark - WebView Release Events

/// Called before webview is released
- (void)onDynamicTabWillReleaseWebView:(ZMDynamicTabItemMgr *)tab;

/// Called after webview is released
- (void)onDynamicTabDidReleaseWebView:(ZMDynamicTabItemMgr *)tab;

#pragma mark - Navigation Events

/// Called when webview navigation starts
- (void)onDynamicTab:(ZMDynamicTabItemMgr *)tab navigationStartUrl:(NSString *)url;

/// Called when webview navigation finishes
- (void)onDynamicTab:(ZMDynamicTabItemMgr *)tab navigationFinishUrl:(NSString *)url errorCode:(int)errorCode;

#pragma mark - Selection Events

/// Called before tab is selected
- (void)onDynamicTabWillSelect:(ZMDynamicTabItemMgr *)tab;

/// Called after tab is selected
- (void)onDynamicTabDidSelect:(ZMDynamicTabItemMgr *)tab;

/// Called before tab is deselected
- (void)onDynamicTabWillDeselect:(ZMDynamicTabItemMgr *)tab;

/// Called after tab is deselected
- (void)onDynamicTabDidDeselect:(ZMDynamicTabItemMgr *)tab;

#pragma mark - Destroy Events

/// Called before tab is destroyed
- (void)onDynamicTabWillDestroy:(ZMDynamicTabItemMgr *)tab;

/// Called after tab is destroyed
- (void)onDynamicTabDidDestroy:(ZMDynamicTabItemMgr *)tab;

@end

NS_ASSUME_NONNULL_END
