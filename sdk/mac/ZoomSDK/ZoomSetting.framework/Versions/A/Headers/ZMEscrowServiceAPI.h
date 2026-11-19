//
//  ZMEscrowServiceAPI.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/4/24.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMEscrowUIActionData;
@class ZMEscrowSettingInfoData;
@class ZMEscrowPromptData;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMEscrowServiceAPI <ZMRoutableObject>

- (void)onEscrowServiceEnabled;
- (void)consentPromptAction:(ZMEscrowPromptData *)promptData actionData:(nullable ZMEscrowUIActionData *)actionData;
- (void)generateEscrowBackupKey:(NSString *)requestId;

- (nullable ZMEscrowSettingInfoData *)getEscrowSettingInfo;
- (void)consentRecoveryAction:(NSArray<NSString *> *)revokeIds;

@end

NS_ASSUME_NONNULL_END
