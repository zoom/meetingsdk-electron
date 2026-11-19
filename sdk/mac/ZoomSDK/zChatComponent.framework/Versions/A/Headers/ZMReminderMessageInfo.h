//
//  ZMReminderMessageInfo.h
//  zChatComponent
//
//  Created by Kris Smith on 4/5/22.
//

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#import <zPTApp/SaasBeePTAppInterface.h>
#import <zChatApp/IZoomMessenger.h>
#endif


NS_ASSUME_NONNULL_BEGIN

@class ZMMessageAdapter;

@interface ZMReminderMessageInfo : NSObject

@property (nonatomic, readonly) ZMMessageAdapter *message;

@property (nonatomic, assign) unsigned long long serverTime;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, assign) NSInteger timeout;
@property (nonatomic, assign) long expiry;
@property (nonatomic, copy) NSString *note;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, assign) long long displayTime;

#if defined(__cplusplus)
@property (nonatomic, assign) NS_ZOOM_MESSAGER::ReminderMessageStatus status;
@property (nonatomic, assign) NS_ZOOM_MESSAGER::ReminderEvent event;
#endif

@property (nonatomic, readonly) BOOL isExpired;
@property (nonatomic, readonly) BOOL isUpcomming;

- (void)updateMessageIdAndSvrSideTimeIfNeed;

#if defined(__cplusplus)
+ (ZMReminderMessageInfo *)getReminderMessageInfo:(const NS_ZOOM_MESSAGER::ReminderInfo &)reminderMsgInfo
                                            event:(const NS_ZOOM_MESSAGER::ReminderEvent)event;

- (void)updateReminderInfo:(const NS_ZOOM_MESSAGER::ReminderInfo &)reminderMsgInfo;

- (void)updateReminder:(ZMReminderMessageInfo *)reminder;

#endif

@end

NS_ASSUME_NONNULL_END
