//
//  ZMPNetworkConnectionSinkProtocol.h
//  PTUIBridge
//
//  Created by FangJin on 2015-05-25.
//  Copyright (c) 2015 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMPNetworkConnectionSinkProtocol <NSObject>

- (void)onReachabilityFlagsChanged:(BOOL)reachable ipAddress:(NSString*)ip;

@end

NS_ASSUME_NONNULL_END

