//
//  ZMEncryptProtocol.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2022/7/19.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ZMEncryptBaseData;
@class ZMEncryptIdentityData;
@class ZMEncryptBackupKeyGenerateData;
@class ZMEncryptBackupKeyShareData;
@class ZMEncryptStoreData;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMEncryptBaseProtocol <NSObject>

@required
- (void)showLoadingIndicator:(BOOL)show;
- (CGFloat)contentTopOffset;
- (CGFloat)calculateTotalHeight;

@end

@protocol ZMEncryptWindowProtocol <NSObject>

//- (void)onConfirmButtonEnabled:(BOOL)enable contentView:(id<ZMEncryptBaseProtocol>)view;
- (void)showMoreInfoView:(ZMEncryptBaseData *)infoData;
- (void)focusOnButtonWhenTab;
- (void)onEncryptCheckButtonClick:(ZMCheckButton *)button;

@end


//@protocol ZMEncryptEventProtocol <NSObject>
//
//@optional

//- (void)onCheckButtonClick:(ZMCheckButton *)button;
//- (void)onActivityDataReady:(ZMEncryptIdentityData *)data;
//- (void)onActivityBadSeqnoResult:(ZMEncryptIdentityData *)data;
//- (void)onInputDataReady:(ZMEncryptIdentityData *)data;
//- (void)onGenerateBackupKey:(ZMEncryptBackupKeyGenerateData *)data;
//- (void)showEncryptSetting;
//- (void)showDataLossWindow:(ZMEncryptStoreData *)storeData;
//- (void)onGetDevicesToReview:(ZMEncryptBackupKeyShareData *)data requestId:(NSString *)reqId errorCode:(NSInteger)code;
//- (void)onRemoveErrorResult:(NSInteger)errorCode;
//- (void)closeActivityWindow;

//- (void)updateScrollHeight;
//- (void)focusOnButtonWhenTab;

//- (void)hideEncryptEntranceButton;

//@end

@protocol ZMEncryptDetailEventProtocol <NSObject>

- (void)onBadSeqnoResult:(ZMEncryptIdentityData *)data isInSetting:(BOOL)isInSetting;
- (void)onReviewErrorResult:(NSInteger)errorCode isInSetting:(BOOL)isInSetting;

- (void)closeEncryptWindow:(BOOL)isInSetting;

- (void)showDataLossWindow:(ZMEncryptStoreData *)storeData;
- (void)onActivityDataReady:(ZMEncryptIdentityData *)data;
- (void)onGetDevicesToReview:(ZMEncryptBackupKeyShareData *)data errorCode:(NSInteger)code isInSetting:(BOOL)isInSetting;
- (void)onAddKeyResult:(ZMEncryptBackupKeyGenerateData *)data errorCode:(NSInteger)code isInSetting:(BOOL)isInSetting;

@end


//@protocol ZMEncryptWindowBaseProtocol <ZMRoutableObject>
//
////- (void)onGenerateBackupKey:(ZMEncryptBackupKeyGenerateData *)data isEscrow:(BOOL)isEscrow;
//
//@end


@protocol ZMSettingAccountCtrlAPI <ZMRoutableObject>

- (void)showEncryptSetting;
- (void)hideEncryptEntranceButton;
- (void)refreshEncryptionEntrance;

@end

NS_ASSUME_NONNULL_END
