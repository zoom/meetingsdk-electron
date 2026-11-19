//
//  ZMEscrowWindowCtrl.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/4/25.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ZoomSetting/ZMEncryptBaseWindowCtrl.h>

@class ZMEscrowPromptData;
@class ZMEncryptBackupKeyGenerateData;

NS_ASSUME_NONNULL_BEGIN

@interface ZMEscrowWindowCtrl : ZMEncryptBaseWindowCtrl

@property (nonatomic, strong, nullable) ZMEscrowPromptData *promptData;

- (void)showSaveLoadingIndicator:(BOOL)show;

- (void)reloadCurrentData;
- (void)closeKeyViewCtrl;

- (void)onAddKeySuccess:(ZMEncryptBackupKeyGenerateData *)data;
- (void)onEnterKeySuccess;

@end

NS_ASSUME_NONNULL_END
