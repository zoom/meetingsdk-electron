//
//  ZMCNetworkInterfaceManager.h
//  ChatUI
//
//  Created by Cyan.Yang on 2023/9/1.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMCNetworkInterfaceType) {
    ZMCNetworkInterfaceTypeNone = 0,
    ZMCNetworkInterfaceTypeWLAN = 1,
    ZMCNetworkInterfaceTypeEthernet = 2,
    ZMCNetworkInterfaceTypeUnknown = 99,
};

@interface ZMCNetworkInterfaceManager : NSObject

+ (instancetype)sharedInstance;

- (ZMCNetworkInterfaceType)primaryInterfaceType;

@end

NS_ASSUME_NONNULL_END
