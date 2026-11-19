//
//  ZMPTConfHelper.h
//  PTUIBridge
//
//  Created by Francis Zhuo on 2026/6/9.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
namespace zoom_data {
class ISBMeetingItem;
}
#endif

NS_ASSUME_NONNULL_BEGIN

@interface ZMPTConfHelper : NSObject
@property(class, readonly) ZMPTConfHelper* shared;
#ifdef __cplusplus
- (nullable zoom_data::ISBMeetingItem*)activeMeetingItem;
#endif
- (NSString*)activeMeetingID;
- (int)getCallStatus;
- (BOOL)isInMeeting;
- (void)fetchCanShowKeypadForUser:(int)userId completion:(void(^)(BOOL canShow))completion;
- (BOOL)isInWebinarMeeting;
@end

NS_ASSUME_NONNULL_END
