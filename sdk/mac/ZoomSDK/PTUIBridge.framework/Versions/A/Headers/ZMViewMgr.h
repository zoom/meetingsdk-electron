//
//  ZMViewMgr.h
//  zChatUI
//
//  Created by Huxley Yang on 2018/1/22.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <PTUIBridge/ZMTabDefineHeader.h>
#import <PTUIBridge/IZMMainTabsData.h>
#import <PTUIBridge/IZMMainTabsLifeCycle.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMHomeTabProtocol
@optional
- (void)reloadTab;
- (BOOL)isSupportReload;
- (void)onTabSelected;
@end

@interface ZMViewMgr : ZMBaseViewController <ZMObjectDispose, ZMPTTabNavigationProtocol,ZMHomeTabProtocol,ZMBaseTabsDataProtocol,IZMMainTabsLifeCycle>
{
    BOOL _cleaned;
}

//@property (readonly) id<ZPMainWindowProtocol> mainWindowMgr;

@property (nonatomic) BOOL visible;//default is YES

#ifdef ENABLE_MAILCLIENT_SERVICE
@property (retain, nullable, nonatomic)NSView* customizedView;
#endif

- (void)cleanUp NS_REQUIRES_SUPER;

- (void)windowWillCompress:(NSWindow *)window;
- (void)windowDidCompress:(NSWindow *)window;
- (void)windowWillDecompress:(NSWindow *)window;
- (void)windowDidDecompress:(NSWindow *)window;

@end

@interface ZMMasterViewMgr : ZMViewMgr

@property (retain, nonatomic, nullable) IBOutlet NSView *headerView;

@end

@class ZMMainTabsMgr;
@class ZMTabItem;

@interface ZMTabItemMgr : ZMViewMgr
//TODO: remove ZMMainTabsMgr define @kay.fu
@property (readonly) ZMMainTabsMgr *mainTabsMgr;

@property (readonly) ZMTabItem *tabItem;

@property (nonatomic,assign) ZMMainTabsType type;

/// Webview-recycle contract: a webview-hosting tab overrides this to return its guid (base empty) so the nav-bar can recycle it when moved to More.
@property (nonatomic, readonly) NSString *webviewID;

- (void)onTabSelected;

@end

NS_ASSUME_NONNULL_END
