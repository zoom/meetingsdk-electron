//
//  IZMSettingNotificationHelper.h
//  ZoomSetting
//
//  Created by Lester Gong on 2025/10/11.
//

#ifndef IZMSettingNotificationHelper_h
#define IZMSettingNotificationHelper_h

#import <ZoomSetting/ZMSettingNotificationDefs.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAutoNotifySettingItem;

@protocol IZMSettingNotificationHelper <NSObject>

@optional

- (BOOL)getNotificationStatusInCall;
- (NSUInteger)getKeywordCount;
- (NSUInteger)getExceptionContactCount;
- (NSInteger)getExceptionGroupCount;
- (BOOL)settingAutoNotifyTime:(NSInteger)startHour
                  startMinute:(NSInteger)startMin
                      endHour:(NSInteger)endHour
                    endMinute:(NSInteger)endMin
                    enableDnd:(BOOL)enable;
- (BOOL)settingReceiveNotifyMsgType:(NSInteger)type;
- (NSInteger)getGroupNotifySettingType:(NSString*)jid;
- (NSString*)getKeywordsSetting:(BOOL *)isMandatory;
- (void)clearKeywordsSetting;
- (void)setKeywordsSetting:(NSString*)keywords;
- (ZMAutoNotifySettingItem*)getAutoNotifySettingTime;

#pragma mark new added
- (void)initDNDSettings;
- (void)updateDNDSettingsWithEnable:(BOOL)enable;

- (void)pageWillAppear;
- (void)pageWillDisappear;
- (void)customRingToneManageDidClick:(NSWindow*)hostWindow;
- (void)chatContactsManageDidClick:(NSWindow*)hostWindow;
- (void)chatExceptionManageDidClick:(NSWindow*)hostWindow;
- (void)onAudioPlayChanged:(unsigned int)value
                    handle:(unsigned int)handle;
- (void)openActivityCenter;

- (BOOL)onCallQueueSettingUpdated:(NSWindow*)hostWindow;
- (void)onShareLineGroupContactClick:(NSWindow*)hostWindow;//kEventShareLineGroupContactClick
- (void)onCallQueuesContactClick:(NSWindow*)hostWindow;//kEventCallQueuesContactClick
- (void)onShareLineAppearanceContactClick:(NSWindow*)hostWindow;//kEventShareLineAppearanceContactClick
- (void)onChatKeywordsManageClick:(NSWindow*)hostWindow;//kEventChatKeywordsManageClick

// DND (Do Not Disturb) related methods
- (ZMShowDndTimeType)getShowDndTimeType;
- (BOOL)isInDNDRange;
- (BOOL)isInSnoozeRange;
- (long long)getNotDisturbSettingDuration;
- (long long)getNotDisturbSettingRemainingDuration;
- (BOOL)settingDoNotDisturbTime:(long long)duration;
- (void)turnOffSnoozeOrSchedule;
- (BOOL)isDndStatusInCurrentTime;
- (NSInteger)getReceiveNotifyMessagesType;
@end

NS_ASSUME_NONNULL_END


#ifndef ZMSharedSettingNotificationHelper
#define ZMSharedSettingNotificationHelper ZMSharedFor(IZMSettingNotificationHelper)
#endif /* ZMSharedSettingNotificationHelper */

#endif /* IZMSettingNotificationHelper_h */
