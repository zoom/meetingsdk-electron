//
//  ZMEmbeddedTabItemMgr.h
//  PTUIBridge
//
//  Created by fistice on 2024-03-26.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <PTUIBridge/ZMViewMgr.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewProtocol.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewDefine.h>
#import <zUnifyWebViewApp/ZMUnifyWebDataStoreHelper.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewService.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMEmbeddedTabItemMgr : ZMTabItemMgr <ZMUnifyWebViewInstanceDelegate, ZMUnifyTabsDataProtocol>

@property (nonatomic, strong) id<ZMUnifyWebViewInstance> webview;
@property (nonatomic, strong) NSView *webViewContainer;
@property (nonatomic, strong) NSView *errorView;
@property (nonatomic, assign) BOOL webViewLoaded;
@property (nonatomic, assign) BOOL docPageLoaded;

@property (nonatomic, readonly) NSString *webviewID;
@property (nonatomic, assign) ZMAppType appType;
@property (nonatomic, readonly, nullable) NSString *getHomePageURL;
@property (nonatomic, readonly, nullable) NSString *customUserAgent;
@property (nonatomic, readonly) NSString *processDisplayName;
@property (nonatomic, readonly) enum UnifyWebViewAppType moduleType;
@property (nonatomic, readonly) BOOL checkJSMessageEnabled;
@property (nonatomic, readonly) BOOL fullScreenEnabled;
@property (nonatomic, readonly) ZMUnifyWebViewConfiguration *getWebViewConfiguration;
@property (nonatomic, strong) NSProgressIndicator *loadingView;

- (BOOL)startLoadingHomeUrl;
- (BOOL)startLoadingUrl:(NSString *)url;
- (BOOL)startLoadingUrl:(NSString *)url isNavigateAction:(BOOL)isNavigateAction;
- (BOOL)doLoadURLAction:(NSString *)url isNavigateAction:(BOOL)isNavigateAction;
- (void)webviewReload:(NSString *)url;
- (BOOL)fastLoading:(NSString *)url;
- (void)onRefresh:(id)sender;

- (void)viewDidLoad;
- (BOOL)loadWebView;
- (void)webViewDidLoad;
- (NSDictionary *)getParams:(WKScriptMessage *)message;
- (void)webviewWillRelease;
- (void)webViewDidFinishNavigation;
- (nullable NSDictionary *)headerDict;
- (BOOL)forceKillWebContentProcessOnDestroyEnabled;
- (BOOL)shouldIgnoreMessage:(WKScriptMessage *)message;
- (void)didReceiveCustomScriptMessage:(WKScriptMessage *)message;
- (void)reloadHomePage;
- (void)releaseWebView;
- (WKWebsiteDataStore *)websiteDataStoreWithConfiguration:(ZMUnifyWebViewConfiguration *)configuration;
- (ZMUnifyWebViewService *)shareUnifyWebViewService;
- (ZMUnifyWebDataStoreHelper *)dataStoreHelper;

@end

#pragma mark V2

@interface ZMEmbeddedTabItemMgrV2 : ZMTabItemMgr <ZMUnifyWebViewDelegate, ZMUnifyTabsDataProtocol>

@property (nonatomic, strong, nullable) id<ZMUnifyWebViewProtocol> webview;
@property (nonatomic, strong) NSView *webViewContainer;
@property (nonatomic, assign) BOOL webViewLoaded;
@property (nonatomic, assign) BOOL docPageLoaded;

@property (nonatomic, readonly) NSString *webviewID;
@property (nonatomic, assign) ZMAppType appType;
@property (nonatomic, readonly, nullable) NSString *getHomePageURL;
@property (nonatomic, readonly, nullable) NSString *userAgentSuffix;
@property (nonatomic, copy, readonly) NSString *instName;
@property (nonatomic, readonly) enum UnifyWebViewAppType moduleType;
@property (nonatomic, readonly) BOOL checkJSMessageEnabled;
@property (nonatomic, readonly) BOOL fullScreenEnabled;
@property (nonatomic, readonly) ZMUnifyWebViewConfiguration *getWebViewConfiguration;

- (BOOL)startLoadingHomeUrl;
- (BOOL)startLoadingUrl:(NSString *)url;
- (BOOL)startLoadingUrl:(NSString *)url isNavigateAction:(BOOL)isNavigateAction;
- (BOOL)doLoadURLAction:(NSString *)url isNavigateAction:(BOOL)isNavigateAction;
- (void)webviewReload:(NSString *)url;

- (void)viewDidLoad;
- (BOOL)loadWebView;
- (void)webViewDidLoad;
- (NSDictionary *)getParams:(WKScriptMessage *)message;
- (void)webviewWillRelease;
- (void)webViewDidFinishNavigation;
- (nullable NSDictionary *)headerDict;
- (BOOL)forceKillWebContentProcessOnDestroyEnabled;
- (BOOL)shouldIgnoreMessage:(WKScriptMessage *)message;
- (void)didReceiveCustomScriptMessage:(WKScriptMessage *)message;
- (void)reloadHomePage;
- (void)releaseWebView;
- (WKWebsiteDataStore *)websiteDataStoreWithConfiguration:(ZMUnifyWebViewConfiguration *)configuration;
- (ZMUnifyWebViewService *)shareUnifyWebViewService;
- (ZMUnifyWebDataStoreHelper *)dataStoreHelper;

@end

NS_ASSUME_NONNULL_END
