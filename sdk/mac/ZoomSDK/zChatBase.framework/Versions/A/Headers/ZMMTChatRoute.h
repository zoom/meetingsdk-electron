//
//  ZMMTChatRoute.h
//  zChatBase
//
//  Created by Devl on 01/06/2026.
//  Copyright © 2026 Zoom. All rights reserved.
//
//  Route facade for Meeting <-> PT chat calls over ZMXProcEventBus.
//  Method prefix marks the target process: PT_ sends to PT, MT_ sends to Meeting.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTChatRoute : NSObject

// Consumed by the PT-side receiver's @zm_request / @zm_action registration.
@property (class, nonatomic, readonly) NSString *feature;
@property (class, nonatomic, readonly) NSString *activeMeetChannel;

// channelId is the meeting's active PMC channel id; empty string clears it.
+ (void)PT_updateActiveMeetChannel:(NSString *)channelId;

@end

NS_ASSUME_NONNULL_END
