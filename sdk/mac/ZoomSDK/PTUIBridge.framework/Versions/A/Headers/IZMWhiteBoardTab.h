//
//  IZMWhiteBoardTab.h
//  PTUIBridge
//
//  Created by Cursor on 2026/3/9.
//

#ifndef IZMWhiteBoardTab_h
#define IZMWhiteBoardTab_h

#import <Cocoa/Cocoa.h>
#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/IZMMainTabsData.h>

#ifdef __cplusplus
class IWBWebViewJSMessageSender;
#endif

@protocol IZMWhiteBoardTab <ZMPTRoutableObject, ZMBaseTabsDataProtocol>

@property (copy, readonly) NSString *domain;
@property (copy, readonly) NSString *clusterName;
@property (copy, readonly) NSString *zak;

- (void)onZRDetectPairStatusChanged;
- (void)queryCanvas:(BOOL *)isInCanvas
              docId:(NSString *_Nullable *_Nullable)docId
            docName:(NSString *_Nullable *_Nullable)docName;

- (void)navigate2Dashboard;
- (void)navigate2Canvas:(NSString *)canvasUrlString;

- (void)aPoppedWindowWillClose:(NSWindowController *)aPoppedWindow;
- (void)refreshAllDashboards;

- (BOOL)activateTabAndOpenShareLink:(NSString *)shareLinkURL;
- (BOOL)activateTabAndOpenDoc:(NSString *)docId;
- (BOOL)activateTabAndNavigate2Dashboard;
- (BOOL)activateTabAndOpenURL:(NSString *)stringURL;

- (BOOL)openDocInPoppedWindow:(NSString *)urlString;
#ifdef __cplusplus
- (void)closeMatchedWindow:(IWBWebViewJSMessageSender *)jsMessagePointer;
#else
- (void)closeMatchedWindow:(void *)jsMessagePointer;
#endif

@end

#endif
