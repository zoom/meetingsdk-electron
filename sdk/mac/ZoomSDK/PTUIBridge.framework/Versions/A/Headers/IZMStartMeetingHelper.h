//
//  IZMStartMeetingHelper.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/25.
//

#ifndef IZMStartMeetingHelper_h
#define IZMStartMeetingHelper_h
#import <PTUIBridge/IZMPTMeetingHelper.h>
@protocol IZMStartMeetingHelper <NSObject>

+ (void)joinMeeting;
+ (void)startMeeting;
+ (void)startMeetingWithZMEntrance:(ZMStartMeetingEntrance)entrance videoOn:(BOOL)videoOn;

@end
#endif /* IZMStartMeetingHelper_h */
//[ZMRouterCenter.shared classForProtocol:@protocol(IZMStartMeetingHelper)]
