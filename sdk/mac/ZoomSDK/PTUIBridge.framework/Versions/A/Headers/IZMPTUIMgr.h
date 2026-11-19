//
//  IZMPTUIMgr.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/23.
//

#ifndef IZMPTUIMgr_h
#define IZMPTUIMgr_h

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPTRouterCenter.h>

@class PZMToastCoordinator;
@class NSWindow;

@protocol IZMPTUIMgr <NSObject>

- (NSWindow *)responsibleWindow;
- (PZMToastCoordinator *)toastCoordinator;
- (void)showFeedbackWindow;
- (void)showFontDownloadSucceedToast;
- (BOOL)isChatUILoaded;
@end
//ZMSharedFor(IZMPTUIMgr)

@protocol IZMPTWebViewMgr <ZMPTRoutableObject>

- (BOOL)showWebViewModalWithParams:(NSDictionary<NSString *, NSString *> *)params
                         inWindow:(NSWindow *)window
                independentWindow:(BOOL)independentWindow;

- (BOOL)showWebViewModalWithParams:(NSDictionary<NSString *, NSString *> *)params
                         inWindow:(NSWindow *)window
                independentWindow:(BOOL)independentWindow
                        moduleType:(NSInteger)moduleType;

@end
//ZMPTSharedFor(IZMPTWebViewMgr)
#endif /* IZMPTUIMgr_h */
