//
//  ZPMainWindowProtocol.h
//  PTUIBridge
//
//  Created by fistice on 2/28/25.
//

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/ZMPTHeaderContainerProtocol.h>

@class PZMToastCoordinator;
@protocol ZPMainWindowProtocol <ZMPTRoutableObject>
@property (readonly) NSWindow *window;
@property (readonly) PZMToastCoordinator *toastCoordinator;
@property (readonly) NSView *bannerView;
@property (readonly) NSView *leftView;

@property (readonly, nonatomic) BOOL isWindowHadLoad;//ZOOM-228117

@property (readonly, nonatomic) BOOL isWindowLoaded;
@property (readonly, getter=isCompressed) BOOL compressed;

@property (readwrite, nonatomic) CGFloat widthToCompressMainWindow;
- (void)updateWidthToCompressMainWindow:(CGFloat)widthToCompress;

- (void)toggleCompress:(nullable id)sender;
- (void)toggleCompressWithoutAnimation;
- (void)decompressWithSize:(CGSize)size completionHandler:(nullable void (^)(void))completionHandler;
- (void)showWindow:(id)sender;
- (void)checkWindowFrameToMinWidth:(CGFloat)minWidth;
- (void)updateNavigationCompactMode:(BOOL)compact;
- (void)resizeWebviewWithTabIdentifier:(NSString *)tabIdentifier width:(CGFloat)width;
- (void)updateCobrandingLogo;

/// Re-clamp main-content min after tab switch / sidebar toggle / compact-mode change.
- (void)refreshMainContentMinSize;
@property (strong, readwrite, nullable) NSTouchBar *touchBar;

//@property (readonly) id<ZMPTHeaderContainerProtocol> headerContainer;
@end

// #import <PTUIBridge/ZMPTMainWindowMgrProtocol.h>

// toastCoordinator
// ZMPTSharedFor(ZPMainWindowProtocol)
