//
//  ZMRealisticAvatarHelper.h
//  ZoomSetting
//
//  Created by vinson.wang on 2025/11/14.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * ZMRealisticAvatarHelper
 * Encapsulates the PhotorealisticAvatar related interfaces provided by the common layer
 */
@interface ZMRealisticAvatarHelper : NSObject

+ (instancetype)shared;

#pragma mark - Avatar Data Manager

/**
 * Get PhotorealisticAvatar data manager
 * @return PhotorealisticAvatar data manager
 */
#ifdef __cplusplus
- (ICmmVideoPhotorealisticAvatarDataMgr*)getPhotorealisticAvatarDataMgr;
#endif

#pragma mark - Model & Moderation Status

/**
 * Check if the video model has been downloaded
 * @return Whether the video model is downloaded
 */
- (BOOL)isVideoModelDownloaded;

/**
 * Check if the video model is currently downloading
 * @return Whether the video model is downloading
 */
- (BOOL)isVideoModelDownloading;

/**
 * Trigger the video model download (idempotent on the common side)
 * @return Whether the download request was accepted
 */
- (BOOL)downloadVideoModel;

/**
 * Check if image moderation check result is failed
 * @return Whether the image moderation check failed
 */
- (BOOL)isImageModerationCheckFailed;

#pragma mark - Feature Availability

/**
 * Check if web setting is enabled
 * @return Whether PhotorealisticAvatar setting is enabled
 */
- (BOOL)isPhotorealisticAvatarEnabled;

/**
 * Check if device supports PhotorealisticAvatar
 * @return Whether PhotorealisticAvatar is supported
 */
- (BOOL)canDeviceSupportPhotorealisticAvatar;

/**
 * Check if PhotorealisticAvatar effect is currently opened
 * @return Whether the effect is in use
 */
- (BOOL)isPhotorealisticAvatarEffectOpened;

#pragma mark - Image Upload

#ifdef __cplusplus
/**
 * Upload image with style for avatar generation
 * Calls common-layer UploadImage(img_path, style) to trigger server-side preview pre-generation.
 * Should be called early (at verify-identity step) so garment previews are ready by outfit selection.
 * @param imgPath Path to the image file
 * @param style Avatar style (0=Realistic, 1=Stylized)
 * @return Whether the upload started successfully
 */
- (BOOL)uploadImageWithPath:(NSString*)imgPath style:(NSInteger)style;
#endif

#pragma mark - Avatar Management

#ifdef __cplusplus
/**
 * Generate a new Avatar using file_id from a prior UploadImage call
 * @param fileId File ID returned by the UploadImage callback
 * @param outAvatarId Output parameter for the generated Avatar ID
 * @return Whether the generation started successfully
 */
- (BOOL)generateAvatarWithFileId:(NSString*)fileId
                        avatarId:(NS_ZOOM_DATA::PhotorealisticAvatarId&)outAvatarId;

/**
 * Remove an Avatar
 * @param avatarId Avatar identifier to remove
 * @return Whether the removal was successful
 */
- (BOOL)removeAvatarWithId:(const NS_ZOOM_DATA::PhotorealisticAvatarId&)avatarId;

/**
 * Get Avatar by index
 * @param index Avatar index in array
 * @return Avatar info pointer, NULL if not found
 */
- (const NS_ZOOM_DATA::PhotorealisticAvatar* _Nullable)getAvatarByIndex:(NSInteger)index;

/**
 * Get Avatar by ID
 * @param avatarId Avatar identifier
 * @return Avatar info pointer, NULL if not found
 */
- (const NS_ZOOM_DATA::PhotorealisticAvatar* _Nullable)getAvatarById:(const NS_ZOOM_DATA::PhotorealisticAvatarId&)avatarId;

/**
 * Check if Avatar data is ready (water mark and model files downloaded)
 * @param avatarId Avatar identifier
 * @return Whether the data is ready
 */
- (BOOL)isAvatarDataReady:(const NS_ZOOM_DATA::PhotorealisticAvatarId&)avatarId;

/**
 * Download Avatar data
 * @param avatarId Avatar identifier
 * @return Whether the download started successfully
 */
- (BOOL)downloadAvatar:(const NS_ZOOM_DATA::PhotorealisticAvatarId&)avatarId;

/**
 * Check if Avatar is currently downloading
 * @param avatarId Avatar identifier
 * @return Whether the Avatar is downloading
 */
- (BOOL)isDownloadingAvatar:(const NS_ZOOM_DATA::PhotorealisticAvatarId&)avatarId;
#endif

/**
 * Get Avatar count
 * @return Total number of Avatars
 */
- (NSInteger)getAvatarsCount;

/**
 * Check if realistic avatar count has reached the maximum limit
 * @return Whether the limit is reached
 */
- (BOOL)isRealisticAvatarReachedLimit;

#pragma mark - Avatar Creation Mode

/**
 * Enable/disable Avatar creation mode
 * @param enable Whether to enable creation mode
 */
- (void)enablePhotoAvatarCreateMode:(BOOL)enable;

#pragma mark - Avatar Setting

#ifdef __cplusplus
/**
 * Get current 3D avatar setting
 * @return Current Cmm3DAvatarSetting
 */
- (Cmm3DAvatarSetting)get3DAvatarSetting;

/**
 * Set preview PhotorealisticAvatar setting
 * @param setting Avatar setting
 */
- (void)setPreviewPhotorealisticAvatarSetting:(const Cmm3DAvatarSetting&)setting;
#endif

#pragma mark - Virtual Camera Detection

/**
 * Check if it is a virtual camera
 * @param deviceID Device ID
 * @return Whether it is a third-party virtual camera
 */
- (BOOL)isThirdPartyVirtualCamera:(NSString*)deviceID;

/**
 * Check if using third-party virtual camera
 * @return Whether using a third-party virtual camera
 */
- (BOOL)isUsingThirdPartyVirtualCamera;

#pragma mark - Liveness Detection / Photo Verification

#ifdef __cplusplus
/**
 * Enable liveness detection
 * @param verifyInfo Verification info block
 * @return Whether liveness detection was enabled successfully
 */
- (BOOL)enableBioInfoVerify:(const SSB_MC_DATA_BLOCK_VIDEO_BIO_INFO_VERIFY&)verifyInfo;

/**
 * Update liveness detection mode
 * @param verifyInfo Updated verification info
 * @return Whether the mode was updated successfully
 */
- (BOOL)updateBioInfoVerifyMode:(const SSB_MC_DATA_BLOCK_VIDEO_BIO_INFO_VERIFY&)verifyInfo;

/**
 * Generate photo compliance info
 * @param inputPic Input picture
 * @param frameRect Face frame rectangle (in/out)
 * @param outputStatus Output verification status
 * @param outputFaceStatus Output face status
 * @return Whether photo compliance info was generated successfully
 */
- (BOOL)generatePhotoComplianceInfo:(void*)inputPic 
                          frameRect:(SSB_MC_DATA_BLOCK_FLOAT_DISPLAY_RECT&)frameRect 
                       outputStatus:(SSB_MC_VIDEO_DEVICE_BIO_INFO_VERIFY_STATUS&)outputStatus 
                   outputFaceStatus:(SSB_MC_DATA_BLOCK_CAMERA_VIDEO_BIO_INFO_FACE_STATUS&)outputFaceStatus;

/**
 * Take a snapshot
 * @param hwnd Window handle
 * @param hPicture Output picture handle
 * @return Whether snapshot was taken successfully
 */
- (BOOL)snapShot:(void*)hwnd picture:(void*&)hPicture;
#endif

/**
 * Disable liveness detection
 * @return Whether liveness detection was disabled successfully
 */
- (BOOL)disableBioInfoVerify;

#pragma mark - Garment Elements

#ifdef __cplusplus
/**
 * Get elements count of a specific category
 * @param category Element category
 * @return Number of elements in the category
 */
- (NSInteger)getElementsCountOfCategory:(NS_ZOOM_DATA::PhotorealisticAvatarElementCategory)category;

/**
 * Get element by category and index
 * @param category Element category
 * @param index Element index in the category
 * @return Element info pointer, NULL if not found
 */
- (const NS_ZOOM_DATA::PhotorealisticAvatarElement* _Nullable)getElementByCategoryAndIndex:(NS_ZOOM_DATA::PhotorealisticAvatarElementCategory)category index:(NSInteger)index;

/**
 * Get element by ID
 * @param elementId Element identifier
 * @return Element info pointer, NULL if not found
 */
- (const NS_ZOOM_DATA::PhotorealisticAvatarElement* _Nullable)getElementById:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId&)elementId;
#endif

#pragma mark - Garment Preview

#ifdef __cplusplus
/**
 * Check if garment preview image is downloaded for a given element
 * @param elementId Element identifier
 * @return Whether the preview image is downloaded
 */
- (BOOL)isGarmentPreviewDownloaded:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId&)elementId;

/**
 * Download garment preview image for a given element
 * @param elementId Element identifier
 */
- (void)downloadGarmentPreview:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId&)elementId;

/**
 * Check if garment preview is currently downloading for a given element
 * @param elementId Element identifier
 * @return Whether the preview is downloading
 */
- (BOOL)isGarmentPreviewDownloading:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId&)elementId;

/**
 * Get garment preview config for a given element
 * @param elementId Element identifier
 * @return PhotorealisticAvatarPreviewConfig with path_ for image loading
 */
- (NS_ZOOM_DATA::PhotorealisticAvatarPreviewConfig)getGarmentPreviewConfig:(const NS_ZOOM_DATA::PhotorealisticAvatarElementId&)elementId;

/**
 * Get default preview config (for "Use Photo" / no garment selection)
 * @return PhotorealisticAvatarPreviewConfig with path_ for image loading
 */
- (NS_ZOOM_DATA::PhotorealisticAvatarPreviewConfig)getDefaultPreviewConfig;
#endif

@end

NS_ASSUME_NONNULL_END

