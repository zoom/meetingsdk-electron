//
//  ZMSettingNotificationDefs.h
//  SaasBeePTUIModule
//
//  Created by Evelyn on 8/6/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, DNDNowSettingType) {
    DNDNowNotSet,
    DNDNowSetOn,
    DNDNOwSetOff
};

typedef NS_ENUM (NSUInteger, ZMReceiveNotifyMsgType) {
    ZMReceiveAllMessage,
    ZMReceivePrivateOrMentionsMsg,
    ZMReceiveNothing
};

typedef NS_ENUM (NSUInteger, ZMGroupNotifyType) {
    ZMNotifyNotSet,
    ZMNotifyAll,
    ZMNotifyMention,
    ZMNotifyNothing
};

typedef NS_ENUM (NSUInteger, ZMShowDndTimeType) {
    ZMShowDndTimeType_None,
    ZMShowDndTimeType_Dnd,
    ZMShowDndTimeType_Snooze
};

typedef struct {
    BOOL isMandatory;
    BOOL isStartAtFirstUnread;
    BOOL keepAllUnreadChannelOnTop;
    BOOL showUnreadForChannels;
    BOOL showUnreadForCMCs;
} ZMChatSettingOptionResult;

// NOTE: the integer values of these entries MUST match the integer values
//       of the enum entries declared in NS_IM_NOTIFICATION::SidebarConfigurationItem
//       (see the SDK's NotificationDef.h).
#if defined(__cplusplus)
using SidebarConfigurationItem = NS_IM_NOTIFICATION::SidebarConfigurationItem;
typedef NS_ENUM(NSUInteger, ZMSidebarConfigurationType) {
    ZMSidebarConfigurationTypeAll                    = SidebarConfigurationItem::Sidebar_All,
    ZMSidebarConfigurationTypeMissedCalls            = SidebarConfigurationItem::Sidebar_MissedCalls,
    ZMSidebarConfigurationTypeContactRequests        = SidebarConfigurationItem::Sidebar_ContactRequests,
    ZMSidebarConfigurationTypeBookmarks              = SidebarConfigurationItem::Sidebar_Bookmarks,
    ZMSidebarConfigurationTypeFiles                  = SidebarConfigurationItem::Sidebar_Files,

    ZMSidebarConfigurationTypeKeepOneSectionOpen     = SidebarConfigurationItem::Sidebar_KeepOneSectionOpen,
    ZMSidebarConfigurationTypeSeparateChatAndChannel = SidebarConfigurationItem::Sidebar_SeparateChatAndChannel,
    ZMSidebarConfigurationTypeShowProfilePictures     = SidebarConfigurationItem::Sidebar_ShowProfilePictures,
    
    ZMSidebarConfigurationTypeReminderMessage        = SidebarConfigurationItem::Sidebar_Reminders,
    // Deprecated, GetStarted is removed
    ZMSidebarConfigurationTypeTutorials_DEPRECATED   = SidebarConfigurationItem::Sidebar_GetStarted,
    
    ZMSidebarConfigurationTypeDrafts                 = SidebarConfigurationItem::Sidebar_Drafts,
    ZMSidebarConfigurationTypeChannelsRecommendation = SidebarConfigurationItem::Sidebar_ChannelRecommendation,
    ZMSidebarConfigurationTypeNone                   = 10000
};

using ChatSettingType = NS_IM_NOTIFICATION::ChatSettingType;
typedef NS_ENUM (NSUInteger, ZMChatSettingType) {
    ZMChatSettingInvalid                    = ChatSettingType::CHAT_SETTING_INVALID,
    ZMChatSettingTargetLanguage             = ChatSettingType::CHAT_SETTING_TARGET_LANGUAGE,
    ZMChatSettingNotifyByKeyWord            = ChatSettingType::CHAT_SETTING_NOTIFY_BY_KEYWORD,
    ZMChatSettingHintLineOption             = ChatSettingType::CHAT_SETTING_HINTLINE_OPTION,
    ZMChatSettingUnreadChannelOnTop         = ChatSettingType::CHAT_SETTING_UNREAD_CHANNEL_ON_TOP,
    ZMChatSettingShowUnreadCountChannel     = ChatSettingType::CHAT_SETTING_SHOW_UNREAD_COUNT_CHANNEL,
    ZMChatSettingShowUnreadCountCMC         = ChatSettingType::CHAT_SETTING_SHOW_UNREAD_COUNT_CMC,
    ZMChatSettingNotifyPreference           = ChatSettingType::CHAT_SETTING_NOTIFY_PREFERENCE
};
#endif

