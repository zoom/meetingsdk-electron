//
//  IZMCheckUpdateMgr.h
//  PTUIBridge
//
//  Created by davies zhao on 2024/10/30.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ZMUpdateMethodType) {
    ZMUpdateMethodTypeAuto = 0,
    ZMUpdateMethodTypeBackground,
    ZMUpdateMethodTypeManual,
    ZMUpdateMethodTypeForce
};

typedef NS_ENUM(NSInteger, ZMUpdatePromptSource) {
    ZMUpdatePromptSourceDefault = 0,
    ZMUpdatePromptSourceAfterMeeting = 1,
    ZMUpdatePromptSourceResumeDownload = 2
};

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMReleaseNotesEventSource) {
    ZMReleaseNotesEventSourceNone,
    ZMReleaseNotesEventSourceProfileMenu,
    ZMReleaseNotesEventSourceCheckForUpdates,
    ZMReleaseNotesEventSourceInstallSuccessful,
    ZMReleaseNotesEventSourceUpdateCompleted
};

typedef NS_ENUM(NSUInteger, ZMReleaseNotesEventType) {
    ZMReleaseNotesEventTypeNone,
    ZMReleaseNotesEventTypeScreenDisplayed,
    ZMReleaseNotesEventTypeClicked
};

typedef NS_ENUM(NSInteger, ZMUserUpdateCheckMode) {
    ZMUserUpdateCheckModeManualLatest = 0,
    ZMUserUpdateCheckModeRepeatLastCheck,
    ZMUserUpdateCheckModeUseCached,
};

typedef NS_ENUM(NSInteger, ZMUserUpdateCheckResult) {
    ZMUserUpdateCheckResultChecking = 0,
    ZMUserUpdateCheckResultReadyPackage,
    ZMUserUpdateCheckResultUpdateAvailable,
    ZMUserUpdateCheckResultBlocked,
    ZMUserUpdateCheckResultFailed,
};

@protocol ZMForceUpdateParamProtocol <NSObject>

@property (nonatomic, assign) BOOL isJoin;
@property (nonatomic, assign) BOOL isForceUpdateByWeb;
@property (nonatomic, assign) BOOL isLimitManualUpdateVersion;
@property (nonatomic, assign) BOOL isUnknowURLScheme;
@property (nonatomic, assign) NSUInteger meetingNo;
@property (nonatomic, copy) NSString *minClientVersion;
@property (nonatomic, copy) NSString *webClientLink;
@property (nonatomic, copy) NSString *meetPassword;
@property (nonatomic, copy) NSString *joinType;
@property (nonatomic, copy) NSString *jmak;
@property (nonatomic, copy) NSString *errorDesc;
@property (nonatomic, copy) NSString *errorTitle;
@property (nonatomic, copy) NSString *errorDescLink;

@end

@protocol IZMCheckUpdateMgr <NSObject>

- (void)forceReCheckUpdate;
- (void)checkUpdate;
- (void)checkUpdateWithType:(ZMUpdateMethodType)type reCheck:(BOOL)reCheck;
- (void)checkUpdateWithType:(ZMUpdateMethodType)type;
- (void)notifyCanPromptFirstUpdate;

- (BOOL)downloadDidFinish;
- (BOOL)isSelfCheck;
- (BOOL)isEnableAutoUpdate;
- (BOOL)isNewVersionAvailable;

- (BOOL)canShowUpdateBanner;
- (BOOL)isUpdateBannerSuppressed;
- (void)notifyUpdateBannerDismissed;
- (void)clearUpdateBannerDismiss;
- (void)registerUpdateBannerIfNeeded;
- (void)unregisterUpdateBanner;
- (void)refreshUpdateBanner;
- (BOOL)canShowGlobalUpdateButton;
- (BOOL)isVersionOutdated;
- (BOOL)isGlobalUpdateButtonDisabled;
- (BOOL)isPromptUpdateToast;
- (BOOL)isShowUpdateBanner;
- (BOOL)isZoomAutoUpdateDisabled;
- (BOOL)requestUserUpdateCheckWithMode:(ZMUserUpdateCheckMode)mode;

- (NSString *)getVersionString;
- (NSString *)getLatestVersionString;
- (NSString *)getPackageDownloadRootUrl;
- (NSString *)getPackageCheckSumSha256;
- (NSString *)getLatestDisplayVersion;
- (NSString *)GetLatestVersionReleaseNote;

- (void)setPromptUpdateAction;
- (void)setPromptUpdateDelay:(NSInteger)hours;
- (BOOL)isAllowedUpdateWithVersion:(NSString *)version;
- (BOOL)isShowUpdateSetting;
- (BOOL)isEnableAutoUpdate:(nullable BOOL *)isMandatory;
- (void)setEnableAutoUpdate:(BOOL)enable;
- (void)setAU2UpdatingChannel:(NSString *)channel;
- (BOOL)isEnableManualCheckUpdate;
- (BOOL)isUpdateSpecificVersion;
- (BOOL)isInstallAtIdleTime;
- (BOOL)isSafeTimeToIdleInstall;
- (BOOL)requestMaintenanceRestartForMemoryPressure;
- (NSString *)getUpdate3rdStorageUrl;
- (BOOL)isLimitManualUpdateVersion;
- (NSString *)getAU2UpdatingChannel;
- (BOOL)isPromptUpdateAfterMeetingEnd;

// Force update methods
- (void)didNotifyForceUpdate:(id<ZMForceUpdateParamProtocol>)paramObj;
- (void)didNotifySoftForceUpdate:(id<ZMForceUpdateParamProtocol>)paramObj;

// Update prompt methods
- (void)onPromptFirstUpdate:(BOOL)bShow isUpdateType:(BOOL)isUpdateType;
- (BOOL)onPromptDelayUpdateNotify;

// Update view methods
- (BOOL)isNewVersionUpdateViewExist;
- (void)showNewVersionWindow;
- (void)showNewVersionWithInfo:(NSString *)info;
- (void)showNewVersionWithInfo:(NSString *)info source:(ZMUpdatePromptSource)source;

// Update state properties
- (BOOL)updateForced;
- (BOOL)remindShowUpdateWhenMeetExit;

// Dogfood update channel methods
- (BOOL)isNeedAddDogFoodUpdateChannel;
- (NSString *)getAU2UpdatingChannel;
- (NSArray<NSString *> *)getAU2ChannelList;
- (NSString *)getAU2UpdatingChannel:(nullable BOOL *)isMandatory;
- (NSMutableArray<NSDictionary *> *)getAU2ChannelMapList;
- (NSMutableArray *)getHistoryChannel;
- (void)setAU2UpdatingChannel:(NSString *)channel forDogfood:(BOOL)isDogfood subVersion:(NSString *)subVersion;
- (void)setAU2UpdatingChannel:(NSString *)channel forDogfood:(BOOL)isDogfood;

// Release notes management
- (void)showReleaseNotesWindow:(ZMReleaseNotesEventSource)eventSource;
- (void)openReleaseNotes:(ZMReleaseNotesEventSource)eventSource;

// Force update handling
- (void)confirmToForceUpdate:(id<ZMForceUpdateParamProtocol>)param;

// Force update alert view access
- (NSView *)forceUpdateAlertView;

// Auto update completed coach mark
- (void)registerCoachMarkAndShowToast;
- (BOOL)canShowAutoUpdateCompletedCoachMark;
- (void)showAutoUpdateCompletedToast;

@end

@protocol ZMUpdateEventProtocol <ZMRoutableObject>
@optional
- (void)newVersionReady;

@end

NS_ASSUME_NONNULL_END
// ZMSharedFor(IZMCheckUpdateMgr)
