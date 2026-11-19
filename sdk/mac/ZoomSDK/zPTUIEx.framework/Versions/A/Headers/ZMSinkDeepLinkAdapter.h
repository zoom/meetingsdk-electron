//
//  ZMSinkDeepLinkAdapter.h
//  ChatUI
//
//  Created by Cooper.Chen on 2024/5/15.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZMDeepLinkInfo;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMChatDisplayMode) {
    ZMChatMode_None = 0,
    ZMChatMode_SingleNativeChat = 1,
    ZMChatMode_SingleNewChat = 2,
    ZMChatMode_Both = 3
};

@interface ZMSinkDeepLinkAdapter: NSObject

+ (nullable NSArray <ZMDeepLinkInfo *>*)getRecentDeeplinks;

+ (void)deleteDeeplink:(NSString *)deeplinkStr;

+ (void)webChatNavigate:(NSString *)sessionId;

+ (NSInteger)getDeeplinkServiceProviderID:(NSString *)url;

+ (BOOL)isNavigateURLAction:(NSString *)url tabIdentifier:(NSString *)tabIdentifier;

+ (BOOL)isDocsNavigateURLAction:(NSString *)url;

+ (BOOL)isWhiteboardNavigateURLAction:(NSString *)url;

+ (BOOL)isMailNavigateURLAction:(NSString *)url;

+ (BOOL)isHubNavigateURLAction:(NSString *)url;

+ (BOOL)isZoomSheetNavigateURLAction:(NSString *)url;

+ (BOOL)isZoomPresentNavigateURLAction:(NSString *)url;

+ (BOOL)isZoomPaperNavigateURLAction:(NSString *)url;

+ (NSString *)getTabNameByProviderID:(NSInteger)providerID;

+ (void)registerDeepLinkServiceProvider;

+ (void)unRegisterDeepLinkServiceProvider;

+ (void)clearAllHistory;

+ (BOOL)hasHistory;

+ (NSArray *)currentTabsArray;

+ (void)addDeepLink:(NSString *)deeplinkUrl
        canNavigate:(BOOL)canNavigate
               name:(NSString *)name;

+ (void)ptServiceAddDeepLink:(NSString *)deepLink
                        name:(NSString *)name
                 canNavigate:(BOOL)canNavigate;

+ (BOOL)canNavigateForward;

+ (BOOL)canNavigateBackward;

+ (BOOL)enableHistoryButton;

+ (void)navigateForward;

+ (void)navigateBackward;

+ (void)addIMHistoryWithSessionID:(NSString *)sessionID;

+ (void)addTabHistoryWithTab:(NSString *)tabName;

+ (void)appsServiceRegisterOrUnregister:(BOOL)isRegister;

+ (void)workspacesServiceRegisterOrUnregister:(BOOL)isRegister;

+ (void)openSearchWithHistory:(id)item;

+ (void)whiteBoardOpenLink:(NSString *)whiteboardurl;

+ (void)handlePhoneDeepLinkWithParams:(NSDictionary <NSString *, NSString *> *)params;

+ (BOOL)isSipPhoneAvailable;

+ (void)showFreeUserUpdateVC:(NSDictionary *)kvsExtra;

+ (void)showAICOnBoardingModal:(NSString *)hybridAppIndex
                    hashRoute:(NSString *)hashRoute;

+ (void)showLoginWindow;

+ (void)registerDeeplinkServiceBySpecID:(NSString *)tabID;

+ (void)unRegisterDeeplinkServiceBySpecID:(NSString *)tabID;

+ (void)showAICFreeTrialDialog;

+ (void)onShowClinicalNoteWithParams:(NSDictionary <NSString *, NSString *> *)params;

+ (NSString *)currentMailSelectUrl;

+ (NSString *)currentHubSelectUrl;

@end

NS_ASSUME_NONNULL_END
