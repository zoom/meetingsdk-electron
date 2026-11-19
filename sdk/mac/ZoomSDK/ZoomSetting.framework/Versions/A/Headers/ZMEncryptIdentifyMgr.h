//
//  ZMEncryptIdentifyMgr.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2022/7/29.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMEncryptIdentityData.h>
#import "ZMEscrowServiceMgr.h"

@class ZMEncryptDetailWindowCtrl;

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    ZMEncryptConfigResult_InitFailed = 1,
    ZMEncryptConfigResult_Initing,
    ZMEncryptConfigResult_Inited,
}ZMEncryptConfigResult;

@interface ZMEncryptIdentifyMgr : NSObject <ZMEscrowServiceAPI>

+ (ZMEncryptIdentifyMgr *)shared;
+ (void)releaseInstance;

@property (nonatomic, weak) ZMEncryptDetailWindowCtrl *settingEncryptWindowCtrl;

- (BOOL)isVoicemailEncryptionEnable;
- (BOOL)isEncryptionEnable;
- (NSString *)getEncryptUpgradeLink;
- (ZMEncryptConfigResult)configKBService:(ZmKbInitUserArgs::Reason)reason;
- (ZMEncryptConfigResult)configKBService:(ZmKbInitUserArgs::Reason)reason initFlag:(ZmKbInitFlag)flag;
- (void)onEncryptOptionClose:(ZmKbInitUserArgs::Reason)reason;
- (void)onVoicemailEncryptionChanged;
- (void)onKeyServerSigchainAlreadyEnabled:(NSInteger)reason;
- (void)onKBServiceFinishInit:(BOOL)success isFirstDevice:(BOOL)isFirstDevice;

- (void)onLoadingPTKBCrypto;

- (NSString *)provisionFirstDevice;
- (void)requestActivityData;
//- (void)requestInputKeysData;
- (void)requestViewDevicesData;
//- (void)requestDevicesToReview:(NSString *)backupKey;

- (NSString *)ensureDeviceIsProvisioned;
- (NSString *)provisionFirstDevice;
- (NSString *)getIdentityAndDevices;
- (NSString *)generateBackupKey:(BOOL)isInSetting;
- (NSString *)reviewIdentityAndDevices:(NSUInteger)seqno deviceIds:(nullable NSArray<NSString *> *)revokeIds accessLossAck:(BOOL)accessLossAck isInSetting:(BOOL)isInSetting;
- (NSString *)revokeDevices:(NSUInteger)seqno deviceIds:(nullable NSArray<NSString *> *)revokeIds accessLossAck:(BOOL)accessLossAck isInSetting:(BOOL)isInSetting;
- (NSString *)getDevicesToReviewForBackupKey:(NSString *)backupKey isInSetting:(BOOL)isInSetting;
- (NSString *)approveFromBackupKey:(NSString *)backupKey seqno:(NSUInteger)seqno deviceIds:(nullable NSArray<NSString *> *)revokeIds accessLossAck:(BOOL)accessLossAck isInSetting:(BOOL)isInSetting;


- (void)onEnsureDeviceIsProvisioned:(NSString *)requestId state:(ZmEnsureDeviceProvisionedState)state result:(nullable ZMEncryptIdentityData *)data;
- (void)onGetIdentityAndDevices:(NSString *)requestId result:(nullable ZMEncryptIdentityData *)data;
- (void)onProvisionFirstDevice:(NSString *)requestId result:(BOOL)isSuccess;
- (void)onReviewIdentityAndDevices:(NSString *)requestId result:(BOOL)isSuccess errorDesc:(ZmKbErrorDesc)errorDesc;
- (void)onRevokeDevice:(NSString *)requestId result:(BOOL)isSuccess errorDesc:(ZmKbErrorDesc)errorDesc;
- (void)onIdentityOrDeviceChanged;
- (void)onGenerateBackupKeyEx:(NSString *)requestId result:(nullable ZMEncryptBackupKeyGenerateData *)data errorDesc:(ZmKbErrorDesc)errorDesc;
- (void)onGetDevicesToReviewForBackupKey:(NSString *)requestId result:(nullable ZMEncryptBackupKeyShareData *)data errorDesc:(ZmKbErrorDesc)errorDesc;
- (void)onApproveFromBackupKey:(NSString *)requestId success:(BOOL)success errorDesc:(ZmKbErrorDesc)errorDesc;
- (void)notifyNeedBackupKey;
- (void)notifyDeviceApproved:(BOOL)isKey;
- (void)notifyDismissIdentityOrDeviceChanged:(NSInteger)seqno;
- (void)notifyShowDeviceAndActivity;


+ (void)showToastInfo:(NSString *)info toastType:(ZMToastType)type isInSetting:(BOOL)isInSetting;

- (void)showAllDevices;
- (void)showCanDecryptDevices:(NSString *)reqId;
- (void)onCanDecryptDevicesResult:(NSArray *)devices requestId:(NSString *)reqId;
- (ZMEncryptDevice *)getEncryptDevice;

- (NSString *)getEncryptEnabledModuleStr;
- (NSString *)properStringWith:(NSString *)wildcardStr;
- (NSString *)getErrorStringByCode:(ZmKbError)errorCode;
- (NSString *)getErrorStringByCode:(ZmKbError)errorCode isAddKey:(BOOL)isAddKey;

- (void)showEscrowPromptWindow;
- (void)showAlertViewWithContent:(NSString *)content actionConfirm:(nullable void(^)())actionConfirm;
- (void)showAccountRecoveryWindow:(nullable ZMEncryptIdentityData *)data;
- (void)checkToCloseRecoveryWindow;

@end

NS_ASSUME_NONNULL_END
