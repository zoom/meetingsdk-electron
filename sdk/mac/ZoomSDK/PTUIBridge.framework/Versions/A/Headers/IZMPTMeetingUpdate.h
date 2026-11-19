//
//  IZMPTMeetingUpdate.h
//  PTUIBridge
//
//  Created by Slevin Zhang on 2025/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMPTMeetingUpdate

@optional
// Meeting list update notifications
- (void)onMeetingListUpdated;
- (void)onMeetingStateChanged:(NSInteger)state;
- (void)onCalendarConfigUpdated;
- (void)onTransferMeetingsListUpdated;
- (void)onUpdateWarningViewDisplay;
- (void)onBuddyUpdatedWithJids:(NSArray<NSString *> *)jids;

@end

NS_ASSUME_NONNULL_END
