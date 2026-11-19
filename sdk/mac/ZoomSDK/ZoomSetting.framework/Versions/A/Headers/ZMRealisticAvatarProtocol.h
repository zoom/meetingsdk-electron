//
//  ZMRealisticAvatarProtocol.h
//  ZoomSetting
//
//  Created by vinson.wang on 2025/11/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMRealisticAvatarProtocol <NSObject>

@optional

#pragma mark - Sink Callback Methods

#ifdef __cplusplus
- (void)onBioInfoVerifyStatusChanged:(SSB_MC_DATA_BLOCK_CAMERA_VIDEO_BIO_INFO_VERIFY_STATUS_CHANGED)statusInfo;

- (void)onBioInfoVerifyInternalError:(SSB_MC_DATA_BLOCK_CAMERA_VIDEO_BIO_INFO_VERIFY_INTERNAL_ERROR)errorInfo;

- (void)onGeneratePhotorealisticAvatar:(CmmUInt32)result
                              avatarId:(const NS_ZOOM_DATA::PhotorealisticAvatarId)avatarId;

- (void)onPhotorealisticAvatarDownloaded:(CmmUInt32)result
                                avatarId:(const NS_ZOOM_DATA::PhotorealisticAvatarId)avatarId;

- (void)onPhotorealisticAvatarPreviewStyleDownloaded:(CmmUInt32)result;

- (void)onPhotorealisticAvatarPreviewGarmentDownloaded:(CmmUInt32)result
                                             elementId:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId)elementId;
#endif

- (void)onPhotorealisticAvatarImageModerationChecked;

- (void)onUploadPhotorealisticAvatarPhoto:(BOOL)success;

/**
 * Notified when the 3dgs_avatar video model download finishes (success or failure).
 * The common layer invokes this callback both in passive scenarios (auto-download
 * triggered when IsPhotorealisticAvatarDataReady detects a missing model) and
 * after an explicit DownloadVideoModel call.
 */
- (void)onVideoModelDownloaded:(BOOL)success;

- (void)onPhotorealisticAvatarElementDataBaseUpdated;

- (void)onPhotorealisticAvatarDataBaseUpdated;

- (void)closeAIAvatarCreatingWindowIfNeed;

@end

NS_ASSUME_NONNULL_END
