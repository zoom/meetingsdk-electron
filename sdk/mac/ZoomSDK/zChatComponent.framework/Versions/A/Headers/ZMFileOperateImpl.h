//
//  ZMFileOperateImpl.h
//  zChatComponent
//
//  Created by Devl on 21/05/2026.
//  Copyright © 2026 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <ZoomUnit/ZMFileConstants.h>
#import <zChatComponent/ZMFileOperateProtocal.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMFileOperateImpl : NSObject <ZMFileImplProtocal>

/// Subclass overrides to declare its source. Default: ZMFileSourceType_IM.
@property (nonatomic, assign, readonly) ZMFileSourceType sourceType;

#pragma mark - Subclass Hooks

/// Alert hook for SB_ERROR_FILE_SERVICE_FILE_NOT_EXIST. Default: no-op.
- (void)showFileCannotBeDownloadedAlertForFileEntity:(ZMFileEntity *)fileEntity;

@end

NS_ASSUME_NONNULL_END
