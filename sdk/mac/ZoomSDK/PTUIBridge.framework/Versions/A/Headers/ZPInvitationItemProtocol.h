//
//  ZPInvitationItemProtocol.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 2/7/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
class InvitationItem;

#endif

NS_ASSUME_NONNULL_BEGIN

@protocol ZMInvitationExtInfoProtocol <NSObject>

@property (nonatomic, copy) NSString *confId;
@property (nonatomic, copy) NSString *meetingTopic;
@property (nonatomic, assign) BOOL isWebinarCall;
@property (nonatomic, assign) NSInteger totalParticipantNum; // total participant number joined the meeting
@property (nonatomic, assign) NSInteger totalAttendeeNum; // total attendee number joined the meeting

@end

@protocol ZPInvitationItemProtocol <NSObject>

#ifdef __cplusplus
- (void)setInvitationItem:(InvitationItem*)invitationItem;
- (InvitationItem*)getInvitationItem;
#endif

- (NSString*)senderJID;
- (NSString*)receiverJID;
- (NSString*)meetingID;
- (NSString*)password;
- (NSNumber*)meetingOption;
//- (NSString*)zcAddress;
- (NSNumber*)meetingNumber;
- (NSString*)senderUserName;
- (NSString*)groupId;
- (NSString*)groupName;
- (NSUInteger)groupCount;
//ZOOM-134180
- (BOOL)isTimeOutDecline;
// ZOOM-149804 zExtInfoForCallAction {CString _pbx_bind_res/_local_res;}
- (NSString*)pbxBindRes;
- (NSString*)localRes;
/// ZOOM-461644, how long the inviting window and ring last
- (NSInteger)remainTime;
- (BOOL)isDirectShareScreen;
- (BOOL)isWebinarCall;
- (nullable id<ZMInvitationExtInfoProtocol>)extInfoModel;
- (nullable NSString *)boRoomID;
@end

NS_ASSUME_NONNULL_END
