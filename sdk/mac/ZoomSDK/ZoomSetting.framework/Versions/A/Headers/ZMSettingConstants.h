//
//  ZMSettingConstants.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2024/3/25.
//

#import <Foundation/Foundation.h>

#ifndef ZMSettingConstants_h
#define ZMSettingConstants_h

//InterFont
#define kZMInterFontToastMarkerFileName @"interfont_toast_marker.plist"

//Setting Deeplink IDs
#define kZMSettingDeeplinkIDAssistant @"assistant"
#define kZMSettingDeeplinkIDVersionNumbers @"versionNumbers"
#define kZMSettingDeeplinkIDAutoDnd @"autodnd"
#define kZMSettingDeeplinkIDTranslation @"translation"
#define kZMSettingDeeplinkIDApps @"apps"
#define kZMSettingDeeplinkIDRingtone @"ringtone"
#define kZMSettingDeeplinkIDPhoneTranslation @"phoneTranslation"
#define kZMSettingDeeplinkIDPhoneVisualUpdate @"phoneVisualUpdate"
#define kZMSettingDeeplinkIDPhoneAudioSettings @"phoneAudioSettings"
#define kZMSettingDeeplinkIDNotiRingtone @"notiringtone"
#define kZMSettingDeeplinkIDBadgeSettings @"badgesettings"
#define kZMSettingDeeplinkIDNotification @"desktopnotification"
#define kZMSettingDeeplinkIDAudioMicrophoneModes @"audiomicrophonemodes"

typedef NS_ENUM(NSInteger, ZMSettingTabID) {
    ZMSettingTabIDInvalid = 0,
    ZMSettingTabIDGeneral = 1,
    ZMSettingTabIDRooms,
    ZMSettingTabIDVirtual,
    ZMSettingTabIDAudio,
    ZMSettingTabIDNotification NS_SWIFT_NAME(notification),
    ZMSettingTabIDMeeting,
    ZMSettingTabIDRecording,
    ZMSettingTabIDShare,
    ZMSettingTabIDPhone,
    ZMSettingTabIDChat,
    ZMSettingTabIDAccessibility,
    ZMSettingTabIDShortcut,
    ZMSettingTabIDStatistic,
    ZMSettingTabIDAccount
};

typedef NS_ENUM(NSInteger, ZMSettingImplementedBy) {
    ZMSettingImplementedByZUI = 0,
    ZMSettingImplementedByNative,
    ZMSettingImplementedByWebview,
};

typedef NS_ENUM(NSInteger, ZMSettingTabTrail) {
    ZMSettingTabTrailNone = 0,
    ZMSettingTabTrailNew  = 1,
};

//setting anchor key
#define kZMSettingAnchorKey @"kZMSettingAnchorKey"
typedef NSString* ZMAnchorKey;

//Notification names
#define kZPSettingShowDarkSessionList @"SettingShowDarkSessionList"
#define kZPSettingSidebarConfigurationChanged @"kZPSettingSidebarConfigurationChanged"
#define kZPSettingGroupNotification @"kZPSettingGroupNotification"
#define KZPSettingSelectChannelNotification @"SettingSelectChannelNotification"
#define kZPSettingDndStatus @"SettingDndStatusNotification"
#define kZPSettingBounceApplicationIconKey @"BounceApplicationSetting"
#define kZPSettingSortByUnreadChanged @"kZPSettingSortByUnreadChanged"
#define kZPSettingOnlyShowUnreadForPrivateAndMentions @"kZPSettingOnlyShowUnreadForPrivateAndMentions"
#define kZPSettingOnlyShowUnreadForCMCs @"kZPSettingOnlyShowUnreadForCMCs"
#define kZPSettingWhenViewingUnreadFirst @"kZPSettingWhenViewingUnreadFirst"
#define kZPSettingNotifyWhenFollowThread @"kZPSettingNotifyWhenFollowThread"
#define kZPGlobalUnreadBadgeChange @"kZPGlobalUnreadBadgeChange"
#define kZPResetAllChannelNotification @"kZPResetAllChannelNotification"
#define kZPSettingResetSidebarLeftTab @"kZPSettingResetSidebarLeftTab"
#define kZPSettingMuteNotificationsKey @"MuteNotifications"

#define kZMNotiContactsSettingChanged @"kZMNotiContactsSettingChanged"
#define kZMNotiKeywordsSettingChanged @"kZMNotiKeywordsSettingChanged"

#define ZMCSettingEventValueChecked @"check"
#define ZMCSettingEventValueUnchecked @"uncheck"

#endif
