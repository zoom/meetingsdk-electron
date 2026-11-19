//
//  IZMPTShareWindowMgr.h
//  PTUIBridge
//

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/ZMTabDefineHeader.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItemMgr;
@class ZMPopOutWindow;
@protocol ZMUnifyWebViewProtocol;

/// Routes share-this-window actions from tab webview delegates (which live in
/// PTUIBridge/ChatComponent) to ZMPTShareWindowMgr (ChatUI), avoiding
/// a reverse module dependency.
@protocol IZMPTShareWindowMgr <ZMPTRoutableObject>

- (BOOL)isSharingTab:(NSString *)identifier;
- (void)startShareTab:(NSString *)identifier;
- (void)stopShareTab:(NSString *)identifier;

- (void)registerTabMgr:(ZMTabItemMgr *)tabMgr;
- (void)unregisterTab:(NSString *)identifier;

- (void)attachWindow:(ZMPopOutWindow *)popoutWindow;
- (void)detachWindow:(NSString *)identifier;
- (void)handleFullscreenStateChanged:(id<ZMUnifyWebViewProtocol>)instance
                                state:(NSInteger)state;

- (BOOL)handleUIActionEvent:(ZMWebViewUIAction)type tabMgr:(ZMTabItemMgr *)tabMgr;

@end

NS_ASSUME_NONNULL_END
