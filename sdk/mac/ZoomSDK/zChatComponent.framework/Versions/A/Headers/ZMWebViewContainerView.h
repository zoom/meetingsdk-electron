//
//  ZMWebViewContainerView.h
//  zChatUI
//
//  Reusable NSView component that contains a UnifyWebView.
//  Can be added as a subview to any view hierarchy.
//

#import <Cocoa/Cocoa.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewProtocol.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewDefine.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMUnifyWebViewConfiguration;
@class ZMWebViewContainerView;

#pragma mark - Configuration Block

/// Block type for customizing webview configuration
/// @param defaultConfig The default configuration with preset values
/// @return Modified configuration (can return the same object after modification)
typedef ZMUnifyWebViewConfiguration * _Nonnull (^ZMWebViewConfigurationBlock)(ZMUnifyWebViewConfiguration *defaultConfig);

#pragma mark - Delegate Protocol

@protocol ZMWebViewContainerViewDelegate <NSObject>

@optional

/// Called when webview navigation starts
- (BOOL)webViewContainer:(ZMWebViewContainerView *)container
       onNavigateStartUrl:(NSString *)url
          decisionHandler:(nullable void (^)(enum UnifyWebViewOperateState decision))decisionHandler;

/// Called when webview navigation finishes
- (void)webViewContainer:(ZMWebViewContainerView *)container
      onNavigateFinishUrl:(NSString *)url
                errorCode:(enum UnifyWebViewError)errorCode
               httpStatus:(int)httpStatus;

/// Called when webview crashes
- (BOOL)webViewContainer:(ZMWebViewContainerView *)container
        onBrowserCrashed:(enum UnifyWebviewCrashType)crashType
                     url:(NSString *)url;

/// Called before download starts
- (ZMUnifyWebViewDownloadDecision *)webViewContainer:(ZMWebViewContainerView *)container
                                    onBeforeDownload:(ZMUnifyWebViewDownloadParam *)downloadParam;

/// Called when webview requests a new window
- (nullable ZMUnifyWebViewNewWindowOpenResult *)webViewContainer:(ZMWebViewContainerView *)container
                                         onWindowOpenRequested:(ZMUnifyWebViewWindowOpenParam *)windowOpenParam;

/// Called to query meeting state
- (enum UnifyWebviewMeetingState)webViewContainerQueryMeetingState:(ZMWebViewContainerView *)container;

/// Called when hybrid app opens
- (void)webViewContainer:(ZMWebViewContainerView *)container
          onOpenHybridApp:(ZMOpenHybridAppResult *)openResult;

/// Called when webview sends a message from JavaScript to native
- (BOOL)webViewContainer:(ZMWebViewContainerView *)container
        onRecvWebMessage:(nullable NSString *)message;

- (void)webViewContainer:(ZMWebViewContainerView *)container
 onFullscreenStateChanged:(id<ZMUnifyWebViewProtocol>)instance
                    state:(enum UnifyWebViewFullscreenState)state;

- (BOOL)webViewContainer:(ZMWebViewContainerView *)container
         onUIActionEvent:(nullable NSString *)message;

@end

#pragma mark - ZMWebViewContainerView

@interface ZMWebViewContainerView : NSView

#pragma mark - Properties

/// The embedded webview instance (nil until loadWebView is called)
@property (nonatomic, strong, readonly, nullable) id<ZMUnifyWebViewProtocol> webview;

/// Delegate for webview events
@property (nonatomic, weak, nullable) id<ZMWebViewContainerViewDelegate> delegate;

/// The URL to load
@property (nonatomic, copy, nullable) NSString *webUrl;

/// Display name for the webview process
@property (nonatomic, copy, nullable) NSString *processDisplayName;

/// Module type for the webview
@property (nonatomic, assign) enum UnifyWebViewAppType moduleType;

/// Optional block to customize webview configuration.
/// If not set, default configuration will be used.
/// Set this BEFORE calling loadWebView.
@property (nonatomic, copy, nullable) ZMWebViewConfigurationBlock configurationCustomizer;

/// Whether the webview instance has been created
@property (nonatomic, assign, readonly) BOOL isWebViewLoaded;

/// Whether the current page finished loading successfully
@property (nonatomic, assign, readonly) BOOL pageLoaded;

#pragma mark - UserAgent Customization

/// String to append to the default UserAgent (via ZMUnifyWebViewConfiguration.userAgentSuffix).
/// Set this BEFORE calling loadWebView.
/// Example: Setting "MyApp/1.0" results in "Mozilla/5.0 ... MyApp/1.0"
@property (nonatomic, copy, nullable) NSString *userAgentSuffix;

#pragma mark - Hybrid App Configuration

/// Hybrid app index. If set (> 0), will use openHybridApp instead of navigateToUrl.
/// Set this BEFORE calling loadWebView.
/// Example: zoom_apps::ZoomLabAppIndex_NewChat
@property (nonatomic, assign) int hybridAppIdx;

/// Whether the hybrid app is opening in meeting context.
/// Only used when hybridAppIdx > 0.
@property (nonatomic, assign) BOOL isInMeeting;

/// Whether to fallback to CDN if hybrid app fails.
/// Only used when hybridAppIdx > 0. Default is YES.
@property (nonatomic, assign) BOOL needFallbackToCDN;

/// Extra key-value info to pass to the hybrid app (e.g., @{@"hash_route": @"?type=sms"}).
/// Only used when hybridAppIdx > 0. Set this BEFORE calling loadWebView.
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *extraInfo;

#pragma mark - Initialization

/// Initialize with frame
- (instancetype)initWithFrame:(NSRect)frameRect;

/// Initialize with frame and URL
- (instancetype)initWithFrame:(NSRect)frameRect webUrl:(nullable NSString *)webUrl;

#pragma mark - WebView Lifecycle

/// Load the webview with the configured URL or hybrid app
/// @return YES if webview loaded successfully, NO otherwise
- (BOOL)loadWebView;

/// Navigate to a new URL
/// @param url The URL to navigate to
- (void)navigateToUrl:(NSString *)url;

/// Set the deeplink URL used by the next hybrid app open.
/// @param url The deeplink URL to open
- (void)setHybridAppDeeplinkUrl:(NSString *)url;

/// Open hybrid app (requires hybridAppIdx to be set)
/// @return YES if hybrid app opened successfully, NO otherwise
- (BOOL)openHybridApp;

/// Reload the current page
- (void)reloadWebView;

/// Release webview resources
- (void)releaseWebView;

#pragma mark - Configuration

/// Create default webview configuration.
/// Called internally, can be used to inspect defaults.
- (ZMUnifyWebViewConfiguration *)createDefaultConfiguration;

#pragma mark - Cookie Management

/// Add a cookie to the webview.
/// Can be called before or after webview is loaded.
/// @param name Cookie name
/// @param value Cookie value
/// @param domain Cookie domain (e.g., ".zoom.us")
/// @param path Cookie path (default "/")
/// @param httpOnly Whether cookie is HTTP only
- (void)addCookieWithName:(NSString *)name
                    value:(NSString *)value
                   domain:(nullable NSString *)domain
                     path:(nullable NSString *)path
                 httpOnly:(BOOL)httpOnly;

/// Add a cookie using NSHTTPCookie object.
/// Can be called before or after webview is loaded.
/// @param cookie The NSHTTPCookie to add
- (void)addCookie:(NSHTTPCookie *)cookie;

@end

NS_ASSUME_NONNULL_END
