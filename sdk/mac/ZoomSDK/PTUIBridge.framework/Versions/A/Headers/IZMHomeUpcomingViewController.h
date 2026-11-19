//
//  IZMHomeTab.h
//  PTUIBridge
//
//  Created by Slevin Zhang on 2025/4/25.
//

#ifndef IZMHomeUpcomingViewController_h
#define IZMHomeUpcomingViewController_h

#import <AppKit/AppKit.h>

@protocol IZMHomeUpcomingViewController <ZMRoutableObject, ZMViewProviding>

- (void)meetingStateChange:(NSInteger)state;
- (void)updateViewFrame:(NSRect)frame;

@end

#endif
