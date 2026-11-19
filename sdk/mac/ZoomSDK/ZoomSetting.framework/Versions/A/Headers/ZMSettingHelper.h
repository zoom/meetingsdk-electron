//
//  ZMSettingHelper.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2024/3/4.
//

#import <Foundation/Foundation.h>

@protocol ZMChatUISessionAdapterProtocol;

#ifdef __cplusplus
#import <zPTApp/PTService/IPTAccountService.h>
class CSettingSearchDataInterface;
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingHelper : NSObject

@property (nonatomic, assign, readonly, class) BOOL isLogin;
@property (nonatomic, assign, readonly, class) BOOL isInMeeting;
// YES : meeting process or single process;
// NO  : Multiple processes have been enabled and are in the PT process
@property (nonatomic, assign, readonly, class) BOOL isConfProcess;

#ifdef __cplusplus
@property (nonatomic, assign, readonly, class, getter = accountService) CPTServicePtr<IPTAccountService> accountService;
@property (assign, readonly, class, getter=searchInterface) CSettingSearchDataInterface*                 searchInterface;
#endif

+ (BOOL)existsSettingsItemValueForKey:(NSString*)stringKey;
+ (BOOL)getSettingsItemValueForKey:(NSString*)stringKey;

+ (void)setSettingsItemBoolValueForKey:(NSString*)key value:(BOOL)isYes;
+ (int)getSettingsItemIntValueForKey:(NSString*)key;

@end

@interface ZMSTPhoneHelper : ZMSettingHelper

+ (NSString *)maskSensitiveInfoWithString:(NSString*)inString;

@property (nonatomic, assign, readonly, class, getter = isCloudPBXEnabled) BOOL isCloudPBXEnabled;

@property (nonatomic, copy, readonly, class, getter = ZoomIQHomePageURL) NSString* ZoomIQHomePageURL;

@property (nonatomic, assign, readonly, class, getter = isWebEnableHideZoomPhoneAssistantOnIdle) BOOL isWebEnableHideZoomPhoneAssistantOnIdle;
@property (nonatomic, assign, readonly, class, getter = isWebLockedZoomAssistantForPhone) BOOL isWebLockedZoomAssistantForPhone;
@property (nonatomic, assign, readonly, class, getter = isWebEnableZoomAssistantForMeeting) BOOL isWebEnableZoomAssistantForMeeting;
@property (nonatomic, assign, readonly, class, getter = isWebLockedZoomAssistantForMeeting) BOOL isWebLockedZoomAssistantForMeeting;
@property (nonatomic, assign, readonly, class, getter = isSupportZoomAssistentForMeeting) BOOL isSupportZoomAssistentForMeeting;
@property (nonatomic, assign, readonly, class, getter = isWebEnableZoomAssistantForPhone) BOOL isWebEnableZoomAssistantForPhone;
@property (nonatomic, assign, readonly, class, getter = hasWebModifiedZoomAssistantPhoneManually) BOOL hasWebModifiedZoomAssistantPhoneManually;
@property (nonatomic, assign, readonly, class, getter = isBasicPowerUserEnable) BOOL isBasicPowerUserEnable;
@property (nonatomic, assign, readonly, class, getter = isPowerUserEnable) BOOL isPowerUserEnable;
@property (nonatomic, assign, readonly, class, getter = isAllowCallForMac) BOOL isAllowCallForMac;
@property (nonatomic, assign, readonly, class, getter = isWebEnableZoomAssistant) BOOL isWebEnableZoomAssistant;

@end

@interface ZMSTThemeHelper : ZMSettingHelper

@property (nonatomic, assign, readonly, class, getter = disableSwitchColorTheme) BOOL disableSwitchColorTheme;

@end

@interface ZMSTClipHelper : ZMSettingHelper

@property (nonatomic, assign, readonly, class, getter = isEnableZoomClipsCreateNew) BOOL isEnableZoomClipsCreateNew;
@property (nonatomic, assign, readonly, class, getter = isZoomClipsRecorderAvailable) BOOL isZoomClipsRecorderAvailable;

@end


@interface ZMSTMeetingHelper : ZMSettingHelper
+ (void)toggleAutoHideInterfaces;
+ (BOOL)isCheckedNotAllowAutoHideInterfaces:(BOOL * _Nullable)isManatory;
@property (nonatomic, assign, readonly, class, getter = isWebEnableAutoHideInterfaces) BOOL isWebEnableAutoHideInterfaces;

@end

#ifdef __cplusplus
class IPTAppWebServiceSink;
#endif

@interface ZMSTPTHelper : ZMSettingHelper

@property (nonatomic, assign, readonly, class) BOOL isMultiJoinSubProcess;

#ifdef __cplusplus
+ (void)registerWebServiceSink:(IPTAppWebServiceSink *)sink;
+ (void)unregisterWebServiceSink:(IPTAppWebServiceSink *)sink;
#endif

@property (nonatomic, copy, readonly, class, nullable, getter = userName) NSString* userName;
@property (nonatomic, copy, readonly, class, nullable, getter = userID) NSString* userID;
@property (nonatomic, copy, readonly, class, nullable, getter = myStatusInfo) NSString* myStatusInfo;
@property (nonatomic, copy, readonly, class, nullable, getter = emailAddress) NSString* emailAddress;
@property (nonatomic, copy, readonly, class, nullable, getter = pictureLocalPath) NSString* pictureLocalPath;
#ifdef __cplusplus
@property (nonatomic, assign, readonly, class, getter = ZUILanguageID) zoom_data::CMM_LANGUAGE_ID_VALUE ZUILanguageID;
#endif /* __cplusplus */
@property (nonatomic, assign, readonly, class, getter = canUpgrade) BOOL canUpgrade;
@property (nonatomic, assign, readonly, class, getter = canAccessZoomWebService) BOOL canAccessZoomWebService;
@property (nonatomic, assign, readonly, class, getter = isPaidUser) BOOL isPaidUser;
@property (nonatomic, assign, readonly, class, getter = isGovUser) BOOL isGovUser;
@property (nonatomic, assign, readonly, class, getter = isDODUser) BOOL isDODUser;
@property (nonatomic, assign, readonly, class, getter = allowMultiDeviceLogin) BOOL allowMultiDeviceLogin;
@property (nonatomic, assign, readonly, class, getter = loginType) int loginType;
@property (nonatomic, assign, readonly, class, getter = isNoMeetingLicenseUser) BOOL isNoMeetingLicenseUser;
@property (nonatomic, assign, readonly, class, getter = isEnableMaskInfo) BOOL isEnableMaskInfo;
@property (nonatomic, assign, readonly, class, getter = canAccessZoomWebservice) BOOL canAccessZoomWebservice;
@property (nonatomic, assign, readonly, class, getter = isDLPAppMeetEnabled) BOOL isDLPAppMeetEnabled;
@property (nonatomic, assign, readonly, class, getter = isDLPAppChatEnabled) BOOL isDLPAppChatEnabled;
@property (nonatomic, assign, readonly, class, getter = isDLPAppSMSEnabled) BOOL isDLPAppSMSEnabled;
@property (nonatomic, assign, readonly, class, getter = isDLPAppEnabled) BOOL isDLPAppEnabled;

@property (nonatomic, copy, readonly, class, nullable, getter = ZoomDomain) NSString* ZoomDomain;

+ (NSString *)formatDLPEnabledModuleString;
+ (BOOL)upgrade2PaidUser;
+ (BOOL)signMeOutOfAllDevices;
+ (NSString *)maskSensitiveInfo:(NSString*)inString;
+ (int/*SSBPTERROR*/)navWebWithDefaultBrowser:(int)type
                              inputUrl:(NSString *)inputUrl;

+ (BOOL)isFeatureToggleEnabled:(NSString *)toggleName service:(NSString *)service;
+ (NSNumber *)getFeatureToggleNumber:(NSString *)toggleName service:(NSString *)service;

@property (nonatomic, assign, readonly, class, getter = enableDiagnostic) BOOL enableDiagnostic;
@property (nonatomic, assign, readonly, class, getter = isSupportMemlogQuickPaste) BOOL isSupportMemlogQuickPaste;

+ (void)onDarkLight:(int)index;
+ (int)indexOfDarkLight;

@end

@interface ZMSTCalendarHelper : ZMSettingHelper
@property (nonatomic, assign, readonly, class, getter = isCalendarSidePanelEnabled) BOOL isCalendarSidePanelEnabled;
@end

@interface ZMSTChatHelper : ZMSettingHelper

@property (nonatomic, assign, readonly, class, getter = settingChatTabVisible) BOOL settingChatTabVisible;
@property (nonatomic, assign, readonly, class, getter = receiveNotifyMessagesType) NSInteger receiveNotifyMessagesType;
@property (nonatomic, copy, readonly, class, getter = chatSessions) NSArray<id<ZMChatUISessionAdapterProtocol>>* chatSessions;
@property (nonatomic, assign, readonly, class, getter = isEnableShowUserName) BOOL isEnableShowUserName;
@property (nonatomic, assign, readonly, class, getter = isPlaySoundForIMMessage) BOOL isPlaySoundForIMMessage;
@property (nonatomic, assign, readonly, class, getter = IMEnabled) BOOL IMEnabled;
@property (nonatomic, assign, readonly, class, getter = chatEnabled) BOOL chatEnabled;
@property (nonatomic, assign, readonly, class, getter = isNewChatDropdownEnabled) BOOL isNewChatDropdownEnabled;

+ (instancetype)shared;

+ (void)onSeparateChatsAndChannels:(int)index;
+ (void)onSeparateChatsAndChannels:(int)index notify:(BOOL)notify;
@property (nonatomic, assign, readonly, class, getter = indexOfSeparateChatsAndChannels) int indexOfSeparateChatsAndChannels;
@property (nonatomic, assign, readonly, class, getter = isEnableSeparateChatsAndChannels) bool isEnableSeparateChatsAndChannels;

+ (void)onOneSectionOpened:(int)index;
@property (nonatomic, assign, readonly, class, getter = indexOfOneSectionOpened) int indexOfOneSectionOpened;


+ (void)onResetDefault;

+ (void)onWhenViewingUnread:(int)index;
@property (nonatomic, assign, readonly, class, getter = indexOfWhenViewingUnread) int indexOfWhenViewingUnread;


- (void)onDropThread:(bool)isDrop;
@property (nonatomic, assign, readonly, class, getter = isDropThread) bool isDropThread;

+ (void)onManageBlockUser;
+ (void)dismissManageBlockUser;

+ (void)onChangeStatus:(int)minutes;
@property (nonatomic, assign, readonly, class, getter = minutesOfChangeStatus) int minutesOfChangeStatus;

+ (void)onBounce:(bool)isOn index:(int)index;
@property (nonatomic, assign, readonly, class, getter = isBounceOn) bool isBounceOn;
@property (nonatomic, assign, readonly, class, getter = indexOfBounce) int indexOfBounce;

+ (void)onLinkPreview:(BOOL)isOn;
@property (nonatomic, assign, readonly, class, getter = isLinkPreviewOn) bool isLinkPreviewOn;

+ (void)onTranslationTargetLanguage:(int)index;
@property (nonatomic, assign, readonly, class, getter = indexOfTranslationTargetLanguage) int indexOfTranslationTargetLanguage;
+ (NSArray <NSString *>*)supportedLanguages;

+ (void)onUnreadBadgeForPrivate:(bool)isShow;
@property (nonatomic, assign, readonly, class, getter = isUnreadBadgeForPrivateShow) bool isUnreadBadgeForPrivateShow;

+ (void)onCMCsUnreadCount:(bool)isShow;
@property (nonatomic, assign, readonly, class, getter = isCMCsUnreadCountShow) bool isCMCsUnreadCountShow;

+ (void)onCheckSpellingWhileTyping:(BOOL)checked;
+ (void)onCheckGrammarWithSpelling:(BOOL)checked;
+ (void)onCorrectSpellingAutomatically:(BOOL)checked;

+ (void)onChangeReadReceipts:(BOOL)isOn;
@property (nonatomic, assign, readonly, class, getter = isReadReceipts) BOOL isReadReceipts;

+ (void)onTabCountType:(int)index identifier:(nullable NSString *)identifier;
+ (int)getTabCountTypeWithIdentifier:(NSString *)identifier;

+ (void)onMuteNoti:(bool)isOn;

@end

@interface ZMSTChatHelper (ChatStorage)
+ (void)showChatStorageCleanupToastWithFreedBytes:(size_t)freedBytes;
@end

#define ZMSettingTrack [ZMRouterCenter.shared classForProtocol:@protocol(ZMCEventTrackerProtocol)]

NS_ASSUME_NONNULL_END
