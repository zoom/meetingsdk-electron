//
//  ZMEncryptDetailWindowCtrl.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/5/8.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMEncryptBaseWindowCtrl.h"

@class ZMEncryptIdentityData;
@class ZMEncryptBackupKeyGenerateData;

NS_ASSUME_NONNULL_BEGIN

@interface ZMEncryptDetailWindowCtrl : ZMEncryptBaseWindowCtrl

@property (nonatomic, strong, nullable) ZMEncryptIdentityData *identityData;

@property (nonatomic, assign) BOOL isInSetting;

- (void)reloadActivityType;
- (void)reloadCanDecryptDevicesType;

@end

NS_ASSUME_NONNULL_END
