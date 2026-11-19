//
//  ZMBaseWKWebViewController.h
//  zChatUI
//
//  Created by Jed Zheng on 24/4/2023.
//  Copyright © 2023 Zoom. All rights reserved.
//

#ifdef ENABLE_ZAPP
#import <zUnifyWebViewApp/ZMUnifyWebURLSchemeHelper.h>
#import <ZoomAppUISDK/ZoomAppUISDK.h>
#import <ZoomUnit/ZPZAppAdapter.h>

@class ZMUnifyWebViewService;
#endif

typedef NS_ENUM(NSUInteger, ZMWebViewErrorType) {
    ZMWebViewErrorTypeLoadError,
    ZMWebViewErrorTypeOtherError
};

NS_ASSUME_NONNULL_BEGIN

@interface ZMBaseWKWebViewController : ZMBaseViewController
@property(nonatomic, assign, readonly) ZMAppType appType;
@property (nonatomic, assign) BOOL isRemoteUrl;
@property (nonatomic, assign) BOOL isRemoteLoaded;

// When YES, the underlying web view is NOT created in -viewDidLoad.
// It will be created lazily the first time -loadWebViewData is invoked.
// Default is NO, which preserves the original eager-creation behavior.
// NOTE: Subclasses that opt into lazy loading MUST call [super loadWebViewData]
// at the beginning of their -loadWebViewData override to trigger the lazy init.
@property (nonatomic, readonly) BOOL lazyLoadWebView;

#ifdef ENABLE_ZAPP
@property(nonatomic, readonly)id<ZMUnifyWebViewProtocol> zAppWebView;
#endif

- (instancetype)initWithAppType:(ZMAppType)appType;
- (void)loadWebViewData;
- (void)starLoadingIndicator;

- (void)stopLoadingIndicatorNeedShowError:(BOOL)showError;
- (void)stopLoadingIndicatorNeedShowError:(BOOL)showError errorType:(ZMWebViewErrorType)errorType;
- (void)makeWebViewFirstResponderIfPossible;

- (void)webResourceLoadStart;
- (void)webResourceLoadFinish;

#ifdef ENABLE_ZAPP
- (void)navigateToURL:(NSString *)url requestHeaders:(nullable NSDictionary<NSString *, NSString *> *)headers;
- (void)navigateToFileURL:(NSString *)fileURL folderPath:(NSString *)folderPath;

// Subclasses override these V2 delegate callbacks and may forward unhandled events to super.
- (void)onNavigateFinish:(id<ZMUnifyWebViewProtocol>)instance
                      url:(nullable NSString *)url
                errorCode:(enum UnifyWebViewError)errorCode
               httpStatus:(int)httpStatus;
- (BOOL)onRecvWebMessage:(id<ZMUnifyWebViewProtocol>)instance
                  message:(nullable NSString *)message;
#endif

#ifdef ENABLE_ZAPP
- (ZMZAppWebViewConfiguration *)webViewCustomConfiguration;
- (ZMUnifyWebViewService *)unifyWebViewService;
- (ZMZAppWebViewService *)zAppWebViewService;
- (ZMUnifyWebURLSchemeHelper *)unifyWebURLSchemeHelper;
- (NSString *)processDisplayName;
#endif

@end

NS_ASSUME_NONNULL_END
