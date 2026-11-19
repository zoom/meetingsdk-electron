//
//  IZMUpcomingMeetingHelper.h
//  PTUIBridge
//
//  Helper protocol to encapsulate ChatUI dependencies for ZMHomeUpcomingViewController
//  This allows PTUI to access meeting data even before ChatUI is fully loaded
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/IZMMeetingListHelper.h>
#import <PTUIBridge/IZMPTTransferMeetingMgr.h>
#import <PTUIBridge/ZMPTRouterCenter.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Helper protocol to encapsulate ChatUI dependencies for ZMHomeUpcomingViewController
 * Inherits from ZMPTRoutableObject to enable PT Router registration (only available after login)
 */
@protocol IZMUpcomingMeetingHelper <ZMPTRoutableObject>

#pragma mark - Data Accessors

// Meeting list data (forwarding to meeting list helper)
@property (nonatomic, strong, readonly, nullable) id<IZMMeetingDayProtocol> today;
@property (nonatomic, assign, readonly) BOOL needAddCalendarConfigItem;
@property (nonatomic, assign, readonly) BOOL needShowCalendarWarning;
- (NSString *)getCalendarWarningString;
- (NSString *)getCalendarUrl;

// Transfer meeting data
@property (nonatomic, copy, readonly) NSArray<id<IZMPTTransferMeetingItem>> *transferMeetings;

#pragma mark - Meeting Actions

- (void)addCalendar;
- (void)startMeeting:(id<IZMMeetingItemProtocol>)meetingItem;
- (void)joinMeeting:(id<IZMMeetingItemProtocol>)meetingItem;
- (void)showMeetingsTab:(nullable id<IZMMeetingItemProtocol>)meetingItem;
- (void)tryChatInChannel:(id<IZMMeetingItemProtocol>)meetingItem;
- (void)copyInvitation:(long long)meetingNumber;
- (void)copyPMIMeetingId;
- (void)copyPMIMeetingLink;
- (void)copyPMIMeetingInvitation;
- (void)editMeeting:(id<IZMMeetingItemProtocol>)meetingItem;
- (void)deleteMeeting:(id<IZMMeetingItemProtocol>)meetingItem;
- (void)joinMeetingByCompanionModeWithItem:(id<IZMMeetingItemProtocol>)meetingItem;

#pragma mark - Feature Flags

- (BOOL)isJoinMeetingByCompanionModeEnabled;
- (BOOL)isEnableNewAICHomeTab;
- (BOOL)isEnabledMeetingsTab;
- (BOOL)isShowCalendarOrNewMeetingTabUI;
- (BOOL)isSupportScheduleFixedTimeRecurrMeeting;

#pragma mark - Buddy Related

- (nullable id)getHostBuddyForItem:(id<IZMMeetingItemProtocol>)item webSearch:(BOOL)webSearch;
- (void)subscribeContactsPresence_v2:(NSArray<NSString *> *)jids forType:(NSInteger)type;
- (nullable id)getBuddyByJId:(NSString *)jid;

#pragma mark - Tracking

// Track chat interaction for meeting host
- (void)trackingChatForHost:(id<IZMMeetingItemProtocol>)meetingItem;

@end

NS_ASSUME_NONNULL_END

