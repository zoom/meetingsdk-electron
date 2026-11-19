//
//  ZMIMAvatarView.h
//  zChatUI
//
//  Created by ryan on 2018/4/23.
//  Copyright © 2018 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <ZoomUnit/ZMBaseAvatarView.h>
#import <ZoomUnit/ZMProfileConfig.h>
#import <Prism/ZMTrackingView.h>

typedef NS_ENUM(NSUInteger, ZMIMAvatarViewType) {
    ZMIMAvatarViewType_Default,
    ZMIMAvatarViewType_Custom,
    ZMIMAvatarViewType_AtAll,
    ZMIMAvatarViewType_MUC,
    ZMIMAvatarViewType_Public,
    ZMIMAvatarViewType_Public_E2e,
    ZMIMAvatarViewType_Private,
    ZMIMAvatarViewType_MeetingChats,
    ZMIMAvatarViewType_MeetingChats_Recurring,
    ZMIMAvatarViewType_ZCC,
    ZMIMAvatarViewType_Broadcast,
    ZMIMAvatarViewType_Muted,
    ZMIMAvatarViewType_NewChat,
    ZMIMAvatarViewType_JoinCMCPlaceholderRequest,
    ZMIMAvatarViewType_MentionMe,
    ZMIMAvatarViewType_MissedCall,
    ZMIMAvatarViewType_ContactRequest,
    ZMIMAvatarViewType_BookMarks,
    ZMIMAvatarViewType_AllFiles,
    ZMIMAvatarViewType_ReminderMessage,
    ZMIMAvatarViewType_ChannelsRecommendation,
    ZMIMAvatarViewType_ViewMore,
    ZMIMAvatarViewType_Drafts,
    ZMIMAvatarViewType_Archived,
    ZMIMAvatarViewType_InviteConsentRequest,
    ZMIMAvatarViewType_DraftsSent,
    ZMIMAvatarViewType_SharedSpace,
};

typedef NS_ENUM(NSUInteger, ZMAvatarHoverShowType) {
    ZMIMAvatarViewHoverShow_None,
    ZMIMAvatarViewHoverShow_ShowProfileCard,
    ZMIMAvatarViewHoverShow_ShowNameTip,
};

typedef NS_ENUM(NSUInteger, ZMAvatarKeypressrShowType) {
    ZMIMAvatarViewKeypress_None,
    ZMIMAvatarViewKeypress_ShowProfileCard,
};

@interface ZMIMAvatarView : ZMBaseAvatarView <ZMTrackingViewDelegate>

@property (nonatomic,assign) ZMIMAvatarViewType type;
@property (nonatomic,assign) BOOL isBigIcon;
@property (nonatomic,assign) BOOL isBlocked;

@property (nonatomic,copy,nullable) NSString* jid;
@property (nonatomic,copy,nullable) NSString *userName;

@property (nonatomic,retain,nullable) NSColor *avatarFillColor;

@property (nonatomic,assign) NSSize zmIntrinsicContentSize;
@property (nonatomic,assign) ZMUserProfileTrackType trackType;

@property (nonatomic,assign) BOOL zmAccessibilityVisible;
/// YES iff tabbing while VoiceOver is on should select this view
@property (nonatomic, assign) BOOL allowTabSelect;

@property(nonatomic,copy,nullable) NSString* zmAccessibilityLabel;
@property(nonatomic,copy,nullable) NSString* zmAccessibilityRoleDescription;

@property (nullable) SEL hoverAction;
@property (nonatomic,assign) ZMAvatarHoverShowType hoverShowType;
@property (nonatomic,assign) ZMAvatarKeypressrShowType keypressShowType;

@property (nonatomic,assign) BOOL allowTrackAreaEvent;
@property (nonatomic, assign) BOOL ignoresMouseEvents;
@property (nonatomic, assign) BOOL ignoresMouseDown;
@property (nonatomic, assign) BOOL isMaintabsAvatar;

@property (nonatomic,retain,nullable) NSImage *customChannelIcon;

- (void)onMouseEntered;

+ (nonnull NSString *)getPresenceSpeakByType:(ZMIMBuddyPresenceType)presenceType;

- (void)clearAvatar;

@end

