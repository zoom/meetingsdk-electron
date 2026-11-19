//
//  ZPMeetingItemProtocol.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 12/28/11.
//  Copyright (c) 2011 Zipow. All rights reserved.
//

typedef enum{
	PTMeetingScheduleType_Preschedule = 0,
	PTMeetingScheduleType_Instant  = 1,
	PTMeetingScheduleType_Scheudle = 2,
	PTMeetingScheduleType_Repeat = 3
}PTMeetingScheduleType;

#import <Foundation/Foundation.h>
#ifdef __cplusplus
namespace NS_ZOOM_DATA {
    class ISBMeetingItem;
}
#endif

@protocol ZPMeetingItemProtocol <NSObject, NSCopying>

- (void)setMeetingTopic:(NSString*)topic;
- (void)setMeetingID:(NSString*)id;
- (void)setMeetingNumber:(unsigned long long)number;
- (void)setMeetingHostID:(NSString*)id;
- (void)setMeetingHostName:(NSString*)name;
- (void)setMeetingPassword:(NSString*)password;
- (void)setDurationInMinutes:(unsigned int)duration;
- (void)setStartTime:(NSDate*)startTime;
- (void)setMeetingOption:(unsigned long long)option;
- (void)setToken:(NSString*)token;

//the userID the jabberID.
//in most cases the email is empty due to we don't know buddies' email address.
//picture URL is user's avatar,if it's not good enough we may use bigger picture.
- (void)addAttendeeInfo:(NSString*)name email:(NSString*)email userID:(NSString*)userID url:(NSString*)picUrl;
- (void)setPhoneID:(int)phoneID;
- (void)setCallInNumber:(NSString*)number;
- (NSString*)getMeetingTopic;
- (NSString*)getMeetingID;
- (long long)getMeetingNumber;
- (NSString*)getMeetingHostID;
- (NSString*)getMeetingHostName;
- (NSString*)getMeetingPassword;
- (NSString*)getJoinMeetingUrl;
- (unsigned int)getDurationInMinutes;
- (NSDate*)getStartTime;
- (unsigned long long)getMeetingOption;
- (NSString*)getToken;
- (NSString*)getPingServer;
- (unsigned int)getCount;
- (int)getPhoneID;
- (NSString*)getCallInNumber;
- (int)getMeetingStatus;
- (void)setScheduleType:(int)type;
- (int)getScheduleType;
- (void)setHasPassword:(BOOL)hasPassword;
- (BOOL)hasPassword;
- (void)setGoogleCalendarUrl:(NSString*)url;
- (NSString*)getGoogleCalendarUrl;
- (NSString*)getTimeZone;
- (void)setInviteEmailContent:(NSString*)url;
- (NSString*)getInviteEmailContent;

- (void)setInviteEmailContentWithTime:(NSString*)url;
- (NSString*)getInviteEmailContentWithTime;

- (void)setZCAddress:(NSString*)url;
- (NSString*)getZCAddress;

- (void)setGmailInviteUrl:(NSString*)url;
- (NSString*)getGmailInviteUrl;

- (void)setYahooInviteUrl:(NSString*)url;
- (NSString*)getYahooInviteUrl;
- (BOOL)isTodayMeeting;
- (void)setSharingOnlyMeeting:(BOOL)flag;
- (BOOL)isSharingOnlyMeeting;
- (BOOL)isPersonalMeetingID;
- (BOOL)isWebinarMeeting;
- (NSString*)getInviteEmailSubject;
- (void)setInviteEmailSubject:(NSString*)subject;

- (void)turnOffVideoForHost:(BOOL)isOff;
- (BOOL)isHostVideoOff;
- (void)turnOffVideoForAttendee:(BOOL)isOff;
- (BOOL)isAttendeeVideoOff;
- (void)turnOffVoip:(BOOL)isOff;
- (BOOL)isVoipOff;
- (void)turnOffTelephony:(BOOL)isOff;
- (BOOL)isTelephonyOff;
- (void)turnOffSelfTelephony:(BOOL)isOff;
- (BOOL)isSelfTelephonyOff;

- (NSString*)getOtherTeleConfInfo;
- (void)setOtherTeleConfInfo:(NSString*)inInfo;

- (void)setUsePMIAsMeetingID:(BOOL)bUsePMI;
- (BOOL)isUsePMIAsMeetingID;
- (long long)getOriginalMeetingNumber;
- (long long)getRealMeetingNumber;

- (BOOL)isAlldayEvent;
//ZOOM-73673
@property (nonatomic, readonly) BOOL isWebRecurring;
- (BOOL)isSupportInvite;
- (BOOL)isEventDirectMeeting;
- (NSString*)viewEventDirectMeetingUrl;
- (BOOL)isEventSummitConference;
- (BOOL)isEnablePrivateEvent;
- (BOOL)isPrivateEventGoogleCalendar;
- (BOOL)getCanViewDetail;
- (BOOL)isMeetingInviteesListEnabled;
- (BOOL)isFixedTimeRecurringType;
- (long long)getOccurrenceTime;
- (NSString *)getChannelID;
- (NSString *)getSubCMCID;
- (BOOL)isEnableOne2OneMeeting;
- (BOOL)isPersistentMeeting;
- (BOOL)isChannelMeeting;
- (BOOL)isEnablePersistentMeetingChat;
- (BOOL)isCMCForChannelMeeting;
- (BOOL)IsInvitedMeeting;
- (BOOL)canMessageParticipants;
- (BOOL)isDisplayStartJoinForLobby;
- (BOOL)isSimuliveWebinarMeeting;
- (NSString *)meetingMasterEventId;
#ifdef __cplusplus
- (ISBMeetingItem*)getMeetingItem;
- (void)setMeetingItem:(ISBMeetingItem*)meetingItem;
- (void)setClonedMeetingItem:(ISBMeetingItem*)meetingItem;
#endif

@end
