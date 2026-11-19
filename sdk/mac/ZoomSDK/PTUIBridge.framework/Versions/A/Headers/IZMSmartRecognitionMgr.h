//
//  IZMSmartRecognitionMgr.h
//  PTUIBridge
//
//  Created by Javenlee.Li on 2025/8/20.
//

#ifndef IZMSmartRecognitionMgr_h
#define IZMSmartRecognitionMgr_h

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPTRouterCenter.h>
@protocol IZMSmartRecognitionMgr <ZMPTRoutableObject>

@optional

- (BOOL)isCoachMarkAvailable;
- (void)markCoachMarkShowing;
- (void)markCoachMarkShown;
- (void)registerCoachMark;
- (void)unregisterCoachMark;
- (NSString *)coachMarkTip;

@end

@protocol ZMPTSmartRecognitionProtocol
@optional
- (void)smartRecognitionCoachMarkTimer;

@end


#endif /* IZMSmartRecognitionMgr_h */
