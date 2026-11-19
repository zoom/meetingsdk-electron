//
//  ZMAICAppViewController.h
//  ZoomAIC
//
//  Created by Howie Xu on 1/14/24.
//

#import <ZoomKit/ZoomKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

// Posted on the main thread when the underlying UnifyWebView is recycled by the
// framework. The wrapper (`unifyWebview`) is preserved — the framework will
// auto-recreate the underlying webview on next display. Observers should treat
// any direct message-send to the AIC webview as a no-op until restore.
extern NSNotificationName const ZMAICAppViewControllerWebViewRecycledNotification;

@interface ZMAICAppViewController : ZMBaseViewController

@property (nonatomic, copy) NSString *webViewInstanceID;
// YES once the UnifyWebView wrapper has been created via the AIC load flow.
// Stays YES across recycle/restore cycles because the wrapper instance is
// preserved — see onUnifyWebViewRecycled:.
@property (nonatomic, assign) BOOL webViewLoaded;
// YES while the underlying UnifyWebView is in the recycled state. Auto-clears
// on onWebViewRestoreStart:. Messages sent to the wrapper while this is YES
// are not delivered.
@property (nonatomic, assign, readonly) BOOL webViewRecycled;

- (void)loadApp;
- (void)loadAppWithInMeeting:(BOOL)inMeeting;
- (void)refresh;
- (NSString*)webViewGUID;
- (void)makeFirstResponderIfPossible;
- (BOOL)checkIsWebViewReady;
- (void)cleanUp;

@end

NS_ASSUME_NONNULL_END
