//
//  ZMMessageAPIHelper.h
//  zChatComponent
//
//  Created by Kevin Li on 2022/8/4.
//

#import <Foundation/Foundation.h>
#import <dataModule/zDataConstants.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <zChatComponent/ZMIMDataInfo.h>
#import <zChatComponent/ZMMessageAPIHelper.h>

NS_ASSUME_NONNULL_BEGIN


@class ZMChannelMemberSearchFilter;


@interface ZMAtEventTelemetryData : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, assign) NSInteger index;

@end


@interface ZMMessageAPIHelper : NSObject

+ (ZoomIMPresence)getMyPresence;
+ (ZoomIMPresenceStatus)getMyPresenceStatus;

+ (void)joinMeetingWithMessageID:(NSString * _Nullable)messageID sessionID:(NSString * _Nullable)sessionID;
+ (BOOL)isSharePointEnabledInChannel:(nullable NSString*)groupID;
+ (ZMFileStorageType)currentFileStorageType;
+ (BOOL)isSharePointUser;
+ (BOOL)isSharePointOrBoxUser;
+ (NSInteger)getSessionFileSotrageType:(nonnull NSString*)sessionID;
+ (E2EChatOption)getMyE2EOption:(nullable NSString *)sessionID;
+ (BOOL)isE2ESelectiveModeEnabled:(nullable NSString *)sessionID;
+ (BOOL)isWhiteboardURL:(nonnull NSString*)url sessionID:(nullable NSString*)sessionID;
+ (BOOL)searchMessageFileDisable;

// ZOOM-628330 describes what are considered as internal links.
// Currently, internal links should include:
//  - Join meeting link
//  - Deeplinks such as "Link to chat message"
//  - Whiteboard links
+ (BOOL)isZoomInternalURL:(nonnull NSString *)URLString sessionID:(nullable NSString *)sessionID;

+ (BOOL)isValidJoinMeetingLink:(nonnull NSString *)URLString;
+ (BOOL)isURLLinkCanJumpToTab:(nonnull NSString *)URLString sessionID:(nullable NSString *)sessionID;

// For "Open in Browser" entries that go through NSWorkspace and bypass the URL action service —
// returns the URL with `?from=<from>` appended when it's an internal navigate URL (Docs / Whiteboard /
// Workvivo / Notes / ...), otherwise returns it unchanged.
+ (nullable NSURL *)urlByAppendingFromIfInternal:(nullable NSURL *)url sessionID:(nullable NSString *)sessionID;

+ (BOOL)isMessageAtChannelAllowPreview:(nonnull NSString*)sessionId withMessageID:(nonnull NSString*)messageID groupID:(nonnull NSString*)groupID;

+ (BOOL)isSessionExistByID:(nonnull NSString*)sessionID ;

+ (BOOL)trackAppActionInteraction:(NSString *)action messageID:(NSString *)messageID sessionID:(NSString *)sessionID;

+ (BOOL)isLargeChannelForMemberListOptimization:(NSString*)sessionId;
+ (NSString*)searchChannelMember:(ZMChannelMemberSearchFilter*)searchFilter;
+ (BOOL)isNotInChannelAtMentionEnabled;
+ (BOOL)isShortKeyNotInChannelSearchEnabled;
+ (BOOL)isChannelCanAddExternalByDefaultEnabled;

/// Exhaustively searches members, returning both those IN and NOT-IN a channel and exclude apps.
+ (NSString*)exhaustiveSearchMember:(ZMExhaustiveMemberSearchFilter*)filter;
/// Searches users by email. Limit of 20 emails per call.
+ (NSString*)batchSearchContactsByEmails:(NSArray<NSString*>*)emails;

+ (nullable NSArray<NSString*>*)sortChannelMemberSearchResult:(nonnull NSString*)sessionId threadId:(nullable NSString*)threadId keyword:(nullable NSString*)keyword jidArray:(nonnull NSArray<NSString*>*)jidArray hasMore:(nullable BOOL*)hasmore;

+ (nullable NSString*)searchChannelByKeyword:(nonnull NSString*)keyword;

+ (nullable NSString*)searchChannelByKeyword:(nonnull NSString*)keyword channelFilter:(ZMChannelSearchFilter*)channelFilter;

+ (nullable NSString*)searchArchivedChannelByKeyword:(nonnull NSString*)keyword;

+ (nullable NSString*)getMarketplaceURLForMioSupport; //ZOOM-386910

+ (NSString*)getURLByType:(int)type;

+ (BOOL)isEnableImprovedMentionSortLogic:(NSString *)sessionId;
+ (void)sendAtEventTelemetryWithList:(nullable NSArray*)list type:(ZMMessageSrcType)srcType;
+ (nullable NSArray*)getAtMentionSortedListForSessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID key:(nullable NSString*)key hasMore:(nullable BOOL*)hasmore;
+ (nullable NSArray*)getAtMentionSortedListForSessionID:(nullable NSString*)sessionID threadID:(nullable NSString*)threadID key:(nullable NSString*)key includeApps:(BOOL)includeApps hasMore:(nullable BOOL*)hasMore;
+ (nullable NSArray*)getAtMentionSortedListForDM:(NSString* _Nonnull)buddyId key:(nullable NSString*)key includeApps:(BOOL)includeApps;

+ (BOOL)isEnableOutOfOffice;

+ (BOOL)isInOfflineMode;

+ (BOOL)isEnablePersonalContactEdition;

+ (BOOL)getManageAppInChannelMoreDetailLink:(NSString *_Nullable*_Nullable)moreDetailLink;
+ (BOOL)getManageAppInChannelMoreDetailLink:(NSString *_Nullable*_Nullable)moreDetailLink sessionID:(nullable NSString*)sessionID;

+ (NSInteger)getChannelInstantMeetingLimitMembers;
+ (BOOL)isAccountDisableChannelInstantMeeting;
+ (BOOL)isAccountChannelInstantMeetingOnlyOwnerAdmin;

+ (BOOL)getChannelOwnerSpecialSetting:(NSString *_Nonnull)channelID;

+ (BOOL)isSipPhoneEnabled;
+ (BOOL)isSipVoicemailEnabled;
+ (BOOL)queryVoiceMailItemByCallID:(NSString *)callId;

+ (BOOL)isEnableShowMeetingChatTag;

+ (BOOL)isEnablePhoneCallMsgSupportReply;

+ (BOOL)isNewChatCanSwitchNative;

//ZOOM-670825
+ (BOOL)isMentionGroupEnhancementEnabled;

+ (BOOL)isDisableGIFAnimations;
+ (BOOL)hasZoomIM;
//zoom-40622
+ (BOOL)goToOffline;
+ (BOOL)resumeFromOffline;
+ (void)notifyNetworkState:(BOOL)isOK isSystemSleep:(BOOL)isSystemSleep;
+ (BOOL)setPresence:(NSInteger)inPresence manual:(BOOL)manual;

+ (BOOL)isEnableCanvasNaming;
@end

NS_ASSUME_NONNULL_END
