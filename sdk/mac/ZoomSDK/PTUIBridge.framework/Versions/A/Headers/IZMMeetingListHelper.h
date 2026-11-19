//
//  IZMMeetingListHelper.h
//  PTUIBridge
//
//  Created by Titus.Jiang on 2025/7/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMMeetingItemProtocol;

@protocol IZMMeetingDayProtocol <NSObject>

@property (nonatomic, copy, nullable, readonly) NSArray<id<IZMMeetingItemProtocol>> *meetings;

// Properties required for upcoming meetings UI
@property (nonatomic, copy, nullable, readonly) NSArray<id<IZMMeetingItemProtocol>> *nextMeetings;
@property (nonatomic, assign, readonly) NSInteger countOfTodaysNextMeeting;

@end

@protocol IZMMeetingItemProtocol <NSObject>

// Basic meeting information
@property (nonatomic, strong, readonly) NSDate *dateStart;
@property (nonatomic, strong, readonly) NSDate *dateEnd;
@property (nonatomic, copy, readonly) NSString *topic;

- (NSInteger)minutesLeftFromDate:(NSDate *)date;

@property (nonatomic, copy, readonly) NSString *zmFormattedFullDateAndTimeString;

// Meeting number and identification
@property (nonatomic, readonly) long long numberOfMeeting;
@property (nonatomic, readonly) long long originalMeetingNumber;
@property (nonatomic, readonly) long long originalMeetingNumberOrNumberOfMeeting;
@property (nonatomic, copy, readonly) NSString *desNumber;
@property (nonatomic, copy, readonly) NSString *desNumberWithLabel;
@property (nonatomic, copy, readonly) NSString *vanityMeetingID;

// Duration and time
@property (nonatomic, copy, readonly) NSString *desDuration;

// Host information
@property (nonatomic, copy, readonly) NSString *hostEmail;
@property (nonatomic, copy, readonly) NSString *hostJid;
@property (nonatomic, copy, readonly) NSString *desHost;
@property (nonatomic, readonly) BOOL shouldShowHostName;
- (NSAttributedString *)getAttributedDesHostInHomePage;

// Location information
@property (nonatomic, copy, readonly) NSString *desLocation;

// Meeting status
@property (nonatomic, readonly) BOOL isPrivateEvent;
@property (nonatomic, readonly) BOOL isMeetingCanJoin;
@property (nonatomic, readonly) BOOL isInMeeting;
@property (nonatomic, readonly) BOOL isConnecting;
@property (nonatomic, readonly) BOOL isDisabledPMI;
@property (nonatomic, readonly) BOOL amIHost;
@property (nonatomic, readonly) BOOL amIAlterHost;

// Meeting types
@property (nonatomic, readonly) BOOL isWebinar;
@property (nonatomic, readonly) BOOL isFromCalendar;
@property (nonatomic, readonly) BOOL isNonZoomEvent;
@property (nonatomic, readonly) BOOL isPMIItem;
@property (nonatomic, readonly) BOOL isEventSummitConference;
@property (nonatomic, readonly) BOOL isDisplayStartJoinForLobby;
@property (nonatomic, readonly) BOOL isSimuliveWebinarMeeting;
@property (nonatomic, readonly) BOOL hideMeetingDetail;
@property (nonatomic, readonly) BOOL isSupportPersistentMeeting;
@property (nonatomic, readonly) BOOL IsInvitedMeeting;
@property (nonatomic, readonly) BOOL isDisabledInvite;
@property (nonatomic, readonly) BOOL isWebRecurring;
@property (nonatomic, readonly) BOOL isFixedTimeRecurringType;
@property (nonatomic, readonly) BOOL isEventDirectMeeting;
@property (nonatomic, readonly) BOOL isSupportCompanionMode;

// Special features
@property (nonatomic, copy, nullable, readonly) NSString *eventDirectMeetingViewUrl;

// Meeting master event ID
@property (nonatomic, copy, readonly) NSString *meetingMasterEventId;

// Additional method
- (void)getOnZoomJoinBtnStatus;

// Buddy update handling
- (BOOL)checkBuddyUpdateWithJids:(NSArray<NSString *> *)jids;

// Presence subscription handling
- (BOOL)handlePresenceExpired:(NSArray<NSString *> *)expiredJids;
- (BOOL)subscribeHostPresence;

@end

@protocol IZMMeetingListHelper <NSObject>

@property (nonatomic, strong, readonly) id<IZMMeetingDayProtocol> today;

// Calendar configuration
@property (nonatomic, assign, readonly) BOOL needAddCalendarConfigItem;
@property (nonatomic, assign, readonly) BOOL needShowCalendarWarning;
- (NSString *)getCalendarWarningString;
- (BOOL)checkBuddyUpdateWithJids:(NSArray<NSString *> *)jids;
@end

NS_ASSUME_NONNULL_END

