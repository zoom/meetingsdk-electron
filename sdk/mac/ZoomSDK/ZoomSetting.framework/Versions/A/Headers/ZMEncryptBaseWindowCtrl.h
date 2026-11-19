//
//  ZMEncryptBaseWindowCtrl.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/6/5.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomSetting/ZMEncryptProtocol.h>

@class ZMEncryptTopView;
@class ZMEncryptInfoContentView;
@class ZMEncryptButtonsView;
@class ZMEncryptDataFactory;
@class ZMEncryptKeyViewCtrl;

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    ZMEncryptWindowType_SettingActivity,
    ZMEncryptWindowType_ProvisionFirst,
    ZMEncryptWindowType_NewDevices,
    ZMEncryptWindowType_ViewDevices,
    ZMEncryptWindowType_CanDecryptDevices,
    ZMEncryptWindowType_AccountRecovery,
    
    ZMEncryptWindowType_DefaultType,
    ZMEncryptWindowType_ProvisionSecond,
    ZMEncryptWindowType_EscrowLoading
}ZMEncryptWindowType;

@interface ZMEncryptBaseWindowCtrl : NSWindowController

@property (nonatomic, strong) ZMEncryptTopView *topView;
@property (nonatomic, strong) ZMEncryptInfoContentView *infoContentView;
@property (nonatomic, strong) ZMEncryptButtonsView *bottomView;
@property (nonatomic, strong) ZMEncryptKeyViewCtrl *inputKeyViewCtrl;

@property (nonatomic, strong) ZMEncryptDataFactory *dataFactory;

@property (nonatomic, assign) BOOL disabledKeyButtons;


// over write
- (void)cleanUp;
- (void)configWindow;
- (void)updateWindowWithType:(ZMEncryptWindowType)type;
- (void)onSaveButtonClicked;
- (BOOL)isEscrow;
//- (void)updateWithGenerateData:(ZMEncryptBackupKeyGenerateData *)data;

// apis
- (ZMEncryptWindowType)currentType;
- (void)reloadContentList:(nullable NSTreeNode *)node;
- (void)updateScrollHeight;
- (void)resetScrollHeight;
- (BOOL)isShowingKeyView;

- (void)showLoadingIndicator:(BOOL)show;
- (void)showAlertViewWithContent:(NSString *)content isRedConfirm:(BOOL)isRedConfirm actionConfirm:(void(^)())actionConfirm;
- (void)showErrorToast:(NSString *)content;
- (void)showInfoToast:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
