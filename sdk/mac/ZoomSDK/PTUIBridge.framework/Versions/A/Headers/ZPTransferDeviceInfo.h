//
//  ZPTransferDeviceInfo.h
//  PTUIBridge
//
//  Created by fistice on 7/15/21.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZPTransferDeviceInfo : NSObject <NSCopying>

@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *resource;
@property (nonatomic, assign) NSInteger resourceType;
@property (nonatomic, assign) BOOL isCurrentSession;
@property (readonly) NSString *imageName;
@property (readonly) NSString *imageVODescription;
@property (readonly) NSString *deviceDescription;

- (BOOL)isEqualToDevice:(ZPTransferDeviceInfo *)obj;

@end

NS_ASSUME_NONNULL_END
