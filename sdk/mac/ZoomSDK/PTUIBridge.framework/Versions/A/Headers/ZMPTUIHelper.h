//
//  ZMPTUIHelper.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/25.
//

#ifndef ZMPTUIHelper_h
#define ZMPTUIHelper_h

@protocol IZMPTUIHelper <NSObject>

- (void)initCurrentLocale;
- (void)setLanguageID:(NSString*)lanID;
- (NSString*)getZoomDisplayingVersionNumber;
- (NSString*)getZoomDisplayingVersionNumberWithTime;
- (NSString*)getOpenSourceURLByLangId;
- (void)showAboutView;
- (void)prepareForZUIDestroy;
- (void)showCrashPanel;

- (BOOL)canJoinByIDNow;
- (void)setStartMeetingScenarioLocation;
- (BOOL)isMultiJoinSubProcess;
- (BOOL)isLaunchedByWebJoin;
- (BOOL)isInMeeting;
- (BOOL)isRestartMachineAndRejoinInProgress;
- (BOOL)canAccessZoomWebservice;
- (BOOL)isFeedbackOff;
- (BOOL)isGovUser;
- (BOOL)isDODUser;
- (void)onZoomCommunity;
- (BOOL)isNoMeetingLicenseUser;
- (BOOL)canAccessZoomWebService;
- (NSInteger)getAICFTStatus;
- (BOOL)getAICFTIsProUser;
- (BOOL)isZpnsAICSidePanelCanOpen;
- (BOOL)isAIC3SidePanelEnabled;

- (NSString *)getLocalizedTermServiceURL;
- (NSString *)getLocalizedPolicyURL;

- (BOOL)uploadAvatar:(NSImage*)image;
- (void)notifyCanPromptFirstUpdate;

- (void)restartTheApplication;
- (BOOL)logout:(int)option;

- (BOOL)isGovDomain:(NSString *)domain;

- (BOOL)canZoomDisplayFontSize;
- (BOOL)isQualtricsFeedbackEnabled;
- (BOOL)isPTJoinByWeb;
- (BOOL)isCoBrandEnable;
- (NSImage * _Nullable)getLightCobrandingLogo;
- (NSImage * _Nullable)getDarkCobrandingLogo;
- (NSImage * _Nullable)getLightCobrandingDialogLogo;
- (NSImage * _Nullable)getDarkCobrandingDialogLogo;

- (NSString *)ZoomDomain;

- (BOOL)isQualtricsFeedbackEnabled;

- (BOOL)disableReportProblemGPO;

- (BOOL)setUserWorkLocation:(NSInteger)workLocation requestId:(NSString **)requestID;

- (int)getCallStatus;

- (void)registerDeeplinkServiceBySpecID:(NSString *)tabID;
- (void)unRegisterDeeplinkServiceBySpecID:(NSString *)tabID;

/// Localized product name for Zoom Docs vs Canvas naming. Reads the cached
/// value of the `enable_canvas_naming` web feature toggle from NSUserDefaults
/// (populated by ZMMainTabsDynamicTabsSink when the toggle list is received).
- (NSString *)localizedZoomDocsProductName;


- (void)openPhoneSettingInDefaultBrowser:(NSString *)url;
@end

#define ZMPTUIHelper ZMSharedFor(IZMPTUIHelper)

#endif /* ZMPTUIHelper_h */
