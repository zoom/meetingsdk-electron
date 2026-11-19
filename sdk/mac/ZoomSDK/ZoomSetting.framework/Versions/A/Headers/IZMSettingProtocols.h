//
//  IZMSettingProtocols.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2025/10/27.
//

#ifndef IZMSettingProtocols_h
#define IZMSettingProtocols_h

#import <ZoomSetting/ZMSettingConstants.h>

@class ZMSettingMgr;
@class ZMSettingItemViewController;
@class ZMSipCallOutInfo;
@class ZMSipCountry;
@class ZMSettingBaseTab;
@class ZMSettingTabInfo;
@class ZPZAppHeader;

NS_ASSUME_NONNULL_BEGIN

@protocol IZMSettingItemViewController <NSObject>

@end

@protocol IZMSettingBaseTab <NSObject>

@property (nonatomic, strong, readwrite, nullable) ZMSettingItemViewController* item;
@property (nonatomic, strong, readwrite, nullable) ZMSettingTabInfo *info;
@property (nonatomic, assign, readonly) BOOL isSelected;
// YES when this tab is selected and the settings window is visible.
@property (nonatomic, assign, readonly) BOOL isShowing;

- (void)sync;
- (void)cleanUp;

- (void)onSettingUIEvent:(void*_Nonnull)event;

- (void)setVisible:(NSNumber* _Nullable)visible
    orVisibleBlock:(BOOL (^ _Nullable)(ZMSettingTabID))visibleBlock
            reload:(BOOL)reload;
- (void)setTrail:(ZMSettingTabTrail)trail
          reload:(BOOL)reload;

- (void)windowWillActivate;
- (void)windowDidBecomeKey;
- (void)windowWillAppear;
- (void)windowDidAppear;
- (void)windowWillClose:(NSNotification *)notification;
#ifdef __cplusplus
class CSettingSearchDataInterface;
- (void)userWillSearch:(CSettingSearchDataInterface*)searchInterface;
#else
- (void)userWillSearch:(void *)searchInterface;
#endif

- (BOOL)registerWithTabID:(ZMSettingTabID)tabID
                    title:(NSString *)title
                 priority:(NSInteger)priority
               zUITabType:(NSInteger)zUITabType
               searchable:(BOOL)searchable
            implementedBy:(ZMSettingImplementedBy)implementedBy
               normalIcon:(nullable NSImage *)normalIcon
             selectedIcon:(nullable NSImage *)selectedIcon;
@property (nonatomic, assign, readonly) BOOL isRegistered;

- (void)unregister;

@end

@protocol IZMSettingGeneralTab <IZMSettingBaseTab>

- (void)registerTab;

@end

#ifndef ZMSharedSettingGeneralTab
#define ZMSharedSettingGeneralTab ZMSharedFor(IZMSettingGeneralTab)
#endif

@protocol IZMSettingRoomsTab <IZMSettingBaseTab>

- (void)registerTab;

@end

#ifndef ZMSharedSettingRoomsTab
#define ZMSharedSettingRoomsTab ZMSharedFor(IZMSettingRoomsTab)
#endif

@protocol IZMSettingVirtualTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)stopPreview;
- (void)onSearchSelect:(NSString*)searchableKey;
- (void)showVB;
- (void)showFilters;
- (void)showAvatar;
- (void)showVirtualEffects;
- (void)showWithOption:(NSString*)option;
- (void)closeVideoTab;

@end

#ifndef ZMSharedSettingVirtualTab
#define ZMSharedSettingVirtualTab ZMSharedFor(IZMSettingVirtualTab)
#endif


@protocol IZMSettingAudioTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)onUpdateAudioSettings;
- (void)startSelectedRecordingMic;

@end

#ifndef ZMSharedSettingAudioTab
#define ZMSharedSettingAudioTab ZMSharedFor(IZMSettingAudioTab)
#endif

@protocol IZMSettingNotificationTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)onIncomingCallRingtoneSettingsChanged;
- (void)onCallQueueSettingUpdated;
- (void)updateIncomingCallFocusControl;

@end


#ifndef ZMSharedSettingNotificationTab
#define ZMSharedSettingNotificationTab ZMSharedFor(IZMSettingNotificationTab)
#endif

@protocol IZMSettingMeetingTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)updateZoomAppsWithDatas:(NSArray<ZPZAppHeader *> *)datas;
- (void)showUnmuteAudioPrivacyView;
- (void)allowUnmuteAudioListChange;

@end

#ifndef ZMSharedSettingMeetingTab
#define ZMSharedSettingMeetingTab ZMSharedFor(IZMSettingMeetingTab)
#endif


@protocol IZMSettingRecordingTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)onCallbackUserCMRStorageInfo:(NSDictionary*)dict;

@end

#ifndef ZMSharedSettingRecordingTab
#define ZMSharedSettingRecordingTab ZMSharedFor(IZMSettingRecordingTab)
#endif

@protocol IZMSettingShareTab <IZMSettingBaseTab>

- (void)registerTab;

@end

#ifndef ZMSharedSettingShareTab
#define ZMSharedSettingShareTab ZMSharedFor(IZMSettingShareTab)
#endif

@protocol IZMSettingChatTab <IZMSettingBaseTab>//Implemented in ZoomSettingEx, about Chat features

- (void)registerTab;

@end

#ifndef ZMSharedSettingChatTab
#define ZMSharedSettingChatTab ZMSharedFor(IZMSettingChatTab)
#endif /* ZMSharedSettingChatTab */

@protocol IZMSettingAccessibilityTab <IZMSettingBaseTab>

- (void)registerTab;

@end

#ifndef ZMSharedSettingAccessibilityTab
#define ZMSharedSettingAccessibilityTab ZMSharedFor(IZMSettingAccessibilityTab)
#endif

@protocol IZMSettingShortcutTab <IZMSettingBaseTab>

- (void)registerTab;

@end

#ifndef ZMSharedSettingShortcutTab
#define ZMSharedSettingShortcutTab ZMSharedFor(IZMSettingShortcutTab)
#endif


@protocol IZMSettingStatisticTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)eventBandWidthLimitChanged;

@end


#ifndef ZMSharedSettingStatisticTab
#define ZMSharedSettingStatisticTab ZMSharedFor(IZMSettingStatisticTab)
#endif

@protocol IZMSettingAccountTab <IZMSettingBaseTab>

- (void)registerTab;
- (void)updateTrail:(BOOL)reload;
- (void)updateUserButton;

@end


#ifndef ZMSharedSettingAccountTab
#define ZMSharedSettingAccountTab ZMSharedFor(IZMSettingAccountTab)
#endif

@protocol IZMSettingPhoneTab <IZMSettingBaseTab>//Implemented in ZoomSettingEx, about Phone features

#pragma mark basic start

- (void)registerTab;
- (void)unregisterTab;

#pragma mark basic end and common phone start

- (void)giveupCallSchema;
- (void)onLocationAccessStatusChanged;

#pragma mark common phone end and cloud PBX start

- (void)updateCloudPBXInfo;
- (void)updateLocationInfo;
- (void)updateLocationHelperInfoData;
- (void)updateCallQueueAutoAnswerInfo;
- (void)updateLaunchAppInfo;
- (void)updateCallControllInfo;
- (void)updateZRACallsInfo;
- (void)updateFaxControlInfo;
- (void)updateCallMeOnInfo;
- (void)updateVideoGreetingInfo;
- (void)onCallQueueAutoAnswerPeriodListUpdated:(NSUInteger)index;
- (void)onDefaultTranscriptLanguageUpdated;
- (void)onPreferredTranslationLanguageUpdated;
- (void)onLiveTranscriptSettingsUpdated;
- (void)onVoicemailPriorityTopicsChanged;
- (void)emergencyAddressCallBack:(NSString *)defaultAddress;
- (void)onDeleteVideoGreeting;
- (void)onDeleteCallOutRequestDone:(BOOL)success deleteId:(NSString *)deleteId;
- (void)onUpdateCallOutRequestDone:(NSInteger)errCode updateId:(NSString *)updateId;
- (void)onCallOutInfoUpdate:(NSInteger)eventType callOutInfo:(ZMSipCallOutInfo *)callOutInfo;
- (void)onCallOutCheckChanged;
- (void)onVerificationRequestDone:(NSInteger)errCode;
- (void)onResultForCountries:(NSArray<ZMSipCountry *> *)countries;
- (void)showVoicemailTopicsManage;
- (void)onCallQueueSettingUpdated;
- (void)onSMSDelegationStatusChanged;
- (void)updateSMSAutoReplyInfo;
- (void)onNewZoomPhoneExperienceUpdated;
- (void)onPhoneWebViewStateChanged:(BOOL)show;
- (void)refreshAfterPhoneStackSwitch;

#pragma mark cloud PBX end and integration start

- (void)updateIntegrationWithErrorCode:(NSInteger)errorCode msg:(NSString *)errorMsg;

#pragma mark integration end

@end

#ifndef ZMSharedSettingPhoneTab
#define ZMSharedSettingPhoneTab ZMSharedFor(IZMSettingPhoneTab)
#endif /* ZMSharedSettingPhoneTab */

NS_ASSUME_NONNULL_END

#endif /* IZMSettingProtocols_h */
