/**
 * @file ZoomSDKSettingVideoEffectController.h
 * @brief Interface declarations related to video effect settings in Zoom SDK.
 */

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <ZoomSDK/ZoomSDKErrors.h>

@class ZoomSDKVideoLipSyncAvatarPreviewHelper;
@class ZoomSDKSettingTestVideoDeviceHelper;

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKVirtualBGImageInfo
 * @brief Information of a virtual background image or video item.
 */
@interface ZoomSDKVirtualBGImageInfo: NSObject

/**
 * @brief Determines if it is the selected virtual background image.
 * @return YES if is the selected virtual background image. Otherwise, NO.
 */
- (BOOL)isSelected;
/**
 * @brief Gets file path of the virtual background image.
 * @return If the function succeeds, it returns the image file path. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getImageFilePath;
/**
 * @brief Gets image file name of the virtual background image.
 * @return If the function succeeds, it returns the image file name. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getImageName;
/**
 * @brief Determines if the selected virtual background is video.
 * @return YES if is the selected virtual background is video. Otherwise, NO.
 */
- (BOOL)isVideo;

/**
 * @brief Determines if the  virtual background item can be deleted.
 * @return YES if is the selected virtual background can be deleted. Otherwise, NO.
 */
- (BOOL)isAllowDelete;
@end


/**
 * @class ZoomSDKVideoFilterItemInfo
 * @brief Information of a video filter (face effect) item.
 */
@interface ZoomSDKVideoFilterItemInfo: NSObject

/**
 * @brief Determines if it is the selected virtual background image.
 * @return YES if is the selected virtual background image. Otherwise, NO.
 */
- (BOOL)isSelected;

/**
 * @brief Gets file path of the virtual background image.
 * @return If the function succeeds, it returns the image file path. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getImageFilePath;

/**
 * @brief Gets image file name of the virtual background image.
 * @return If the function succeeds, it returns the image file name. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getImageName;

/**
 * @brief Gets the virtual background image or video item's type.
 * @return The video effect type.
 */
- (ZoomSDKVideoEffectType)getType;

/**
 * @brief Gets the virtual background image or video item's index.
 * @return If the function succeeds, the return value is the index. Otherwise, returns -1.
 */
- (int)getIndex;
@end

/**
 * @class ZoomSDKVideoLipSyncAvatarPreviewHelper
 * @brief Helper class to control preview of lip-sync avatars.
 */
@interface ZoomSDKVideoLipSyncAvatarPreviewHelper : NSObject

/**
 * @brief Starts to preview lip-sync avatar.
 * @param lipsyncPreview The view of show lip-sync avatar preview.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startLipSyncAvatarPreview:(NSView *)lipsyncPreview;

/**
 * @brief Stops to preview lip-sync avatar.
 * @param lipsyncPreview The view of show lip-sync avatar preview.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopLipSyncAvatarPreview:(NSView *)lipsyncPreview;
@end

/**
 * @protocol ZoomSDKVirtualBackgroundSettingDelegate
 * @brief Protocol for receiving virtual background setting events.
 */
@protocol ZoomSDKVirtualBackgroundSettingDelegate <NSObject>
@optional
/**
 * @brief Notify the default virtual background image have been downloaded from web.
 * @param filePath The file's path.
 */
- (void)onVBImageDidDownloaded:(NSString*)filePath;

/**
 * @brief Notify the virtual background was updated with selected color.
 * @param selectedColor The selected color.
 */
- (void)onGreenVBDidUpdateWithReplaceColor:(NSColor*)selectedColor;

/**
 * @brief Notify the selected virtual background image has been changed, user can get the new selected image through image list.
 */
- (void)onSelectedVBImageChanged;

/**
 * @brief Notify the result of adding video virtual background.
 * @param success YES if successfully added, NO otherwise.
 * @param error If failed adding the video virtual background, the error will be notified.
 */
- (void)onVBVideoUploadedResult:(BOOL)success failedError:(ZoomSDKSettingVBVideoError)error;

/**
 * @brief Callback event of notification that the thumbnails of all video filter items have been downloaded.
 */
- (void)onVideoFilterItemThumnailsDownloaded;

/**
 * @brief Callback event of notification that the selected video filter item is downloading.
 * @param type The selected video filter item's type.
 * @param index The selected video filter item's index.
 */
- (void)onVideoFilterItemDataDownloading:(ZoomSDKVideoEffectType)type index:(int)index;

/**
 * @brief Callback event of notification that the selected video filter item whether has been downloaded successfully.
 * @param ready YES indicates the selected video filter item has been downloaded successfully, NO otherwise.
 * @param type The selected video filter item's type.
 * @param index The selected video filter item's index.
 */
- (void)onVideoFilterItemDataDownloaded:(BOOL)ready type:(ZoomSDKVideoEffectType)type index:(int)index;
@end


/**
 * @class ZoomSDKVirtualBackgroundSetting
 * @brief Interface for configuring virtual background and video filter settings.
 */
@interface ZoomSDKVirtualBackgroundSetting: NSObject
{
    id<ZoomSDKVirtualBackgroundSettingDelegate>       _delegate;
}
@property(nonatomic, assign, nullable)id<ZoomSDKVirtualBackgroundSettingDelegate> delegate;
/**
 * @brief Gets the object to video device test helper.
 * @return If the function succeeds, it returns a ZoomSDKSettingTestVideoDeviceHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestVideoDeviceHelper*_Nullable)getSettingVideoTestHelper;

/**
 * @brief Determines if support virtual background feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isSupportVirtualBG;

/**
 * @brief Determines if meeting supports the video virtual video background feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isSupportVirtualBackgroundVideo;

/**
 * @brief Determines if the machine can support the smart virtual background feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isDeviceSupportSmartVirtualBG;

/**
 * @brief Determines if the using green screen option is enabled.
 * @return YES if is enabled. Otherwise, NO.
 */
- (BOOL)isUsingGreenScreenOn;

/**
 * @brief Enables or disable the using green screen option.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setUsingGreenScreen:(BOOL)bUse;

/**
 * @brief Adds virtual background image.
 * @param filePath The image's file path user want to add.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addBGImage:(NSString*)filePath;

/**
 * @brief Adds virtual background video.
 * @param filePath The video's file path user want to add.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addBGVideo:(NSString*)filePath;

/**
 * @brief Removes virtual background item.
 * @param virtualBGImageInfo The ZoomSDKVirtualBGImageInfo object user want to remove.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeBGItem:(ZoomSDKVirtualBGImageInfo *)virtualBGImageInfo;

/**
 * @brief Gets the array of virtual background video item.
 * @return If the function succeeds, it returns the NSArray of video item list. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getBGItemList;

/**
 * @brief Use the specify image as selected virtual background images.
 * @param item The virtualbackground image or video item's path user want to select.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)useBGItem:(ZoomSDKVirtualBGImageInfo*)item;

/**
 * @brief Gets the selected replace color of virtual background images.
 * @return If the function succeeds, it returns the color. Otherwise, this function fails and returns nil.
 */
- (NSColor*_Nullable)getVBReplaceColor;

/**
 * @brief Starts selected replace color of virtual background images.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The selected replace color will be notified from callback event '- (void)onSelectedVBImageChanged'.
 */
- (ZoomSDKError)startSelectReplaceVBColor;

/**
 * @brief Determines if the machine can support the smart virtual background video feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isDeviceSupportSmartVirtualBackgroundVideo;

/**
 * @brief Determines if the machine can support the green virtual background video feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isDeviceSupportGreenVirtualBackgroundVideo;

/**
 * @brief Determines if the meeting supports the adding a new virtual background item feature.
 * @return YES if is allowed. Otherwise, NO.
 */
- (BOOL)isAllowAddNewVBItem;

/**
 * @brief Determines if the meeting supports the removing a new virtual background item feature.
 * @return YES if is allowed remove. Otherwise, NO.
 */
- (BOOL)isAllowRemoveVBItem;

/**
 * @brief Determines if face makeup feature is enabled.
 * @return YES if is enabled. Otherwise, NO.
 */
- (BOOL)isVideoFilterEnabled;

/**
 * @brief Determines if support face makeup feature.
 * @return YES if is support. Otherwise, NO.
 */
- (BOOL)isSupportVideoFilter;

/**
 * @brief Gets the array of face makeup images.
 * @return If the function succeeds, it returns the NSArray of image list. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getVideoFilterItemList;

/**
 * @brief Use the specify image as selected face makeup images.
 * @param imageInfo It is video filter object.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)useVideoFilterItem:(ZoomSDKVideoFilterItemInfo*)imageInfo;
@end

/**
 * @class ZoomSDKFaceMakeupImageInfo
 * @brief Represents information about a face makeup image in Zoom SDK.
 */
@interface ZoomSDKFaceMakeupImageInfo : NSObject

/**
 * @brief Gets the current image's type.
 */
@property(nonatomic, assign, readonly)ZoomSDKFaceMakeupType faceMakeupType;

/**
 * @brief Determines if the current face makeup item is being used.
 */
@property(nonatomic, assign, readonly)BOOL isSelected;

/**
 * @brief Gets the file path of the current image.
 */
@property(nonatomic, copy, readonly)NSString *imageFilePath;

/**
 * @brief Gets the current image's name.
 */
@property(nonatomic, copy, readonly)NSString *imageName;

/**
 * @brief Gets the current face makeup's index.
 */
@property(nonatomic, assign, readonly)int  index;
@end


/**
 * @protocol ZoomSDKFaceMakeupSettingContextDelegate
 * @brief Delegate protocol to receive callbacks about face makeup setting events.
 */
@protocol ZoomSDKFaceMakeupSettingContextDelegate <NSObject>

/**
 * @brief Callback event notifying that all face makeup items' thumbnails were downloaded.
 * @param type The type of current image.
 */
- (void)onFaceMakeupItemThumbnailsDownloaded:(ZoomSDKFaceMakeupType)type;

/**
 * @brief Callback event notifying that the selected face makeup item is downloading.
 * @param type The type of current image.
 * @param index The current face makeup's index.
 */
- (void)onFaceMakeupItemDataDownloading:(ZoomSDKFaceMakeupType)type index:(int)index;

/**
 * @brief Callback event notifying whether or not the selected face makeup item has downloaded successfully.
 * @param success YES indicates the selected face makeup item has downloaded successfully, NO otherwise.
 * @param type The type of current image.
 * @param index The current face makeup's index.
 */
- (void)onFaceMakeupItemDataDownloaded:(BOOL)success faceMakeupType:(ZoomSDKFaceMakeupType)type index:(int)index;

@end


/**
 * @class ZoomSDKFaceMakeupSettingContext
 * @brief Provides APIs to manage face makeup settings in Zoom SDK.
 */
@interface ZoomSDKFaceMakeupSettingContext : NSObject
{
    id<ZoomSDKFaceMakeupSettingContextDelegate>       _delegate;
}

/**
 * @brief The delegate to receive face makeup setting events.
 */
@property(nonatomic,assign, nullable)id<ZoomSDKFaceMakeupSettingContextDelegate> delegate;

/**
 * @brief Determines if the face makeup feature is enabled.
 * @return YES if face makeup feature is enabled. Otherwise, NO.
 */
- (BOOL)isFaceMakeupEnabled;

/**
 * @brief Determines if the meeting supports the face makeup feature.
 * @return YES if the meeting supports the face makeup feature. Otherwise, NO.
 */
- (BOOL)isSupportFaceMakeup;

/**
 * @brief Enable or Disable the selected face makeup effect is always used by future meetings.
 * @param enable YES indicates enabled, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableFaceMakeupEffectForAllMeeting:(BOOL)enable;

/**
 * @brief Determines if the selected face makeup effect is always used by future meetings.
 * @return YES if the selected face makeup effect still applies to future meetings. Otherwise, NO.
 */
- (BOOL)isFaceMakeupEffectForAllMeetingEnabled;

/**
 * @brief Gets the list of face makeup images.
 * @return If there are images in the list, the pointers's return value is a list to ZoomSDKFaceMakeupImageInfo. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKFaceMakeupImageInfo *> *_Nullable)getFaceMakeupImageList;

/**
 * @brief Specify an image to be face makeup image.
 * @param image Specify the image to use.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setFaceMakeupImage:(ZoomSDKFaceMakeupImageInfo *)image;

/**
 * @brief Enable or Disable the lip face makeup effect.
 * @param enable YES indicates enabled, NO otherwise.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setLipsFaceMakeup:(BOOL)enable;

/**
 * @brief Sets the colors of face makeup effect.
 * @param color Specify the face makeup effect's color in RGB format.
 * @param type The specified color uses on which face makeup type.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setColor:(NSColor *)color type:(ZoomSDKFaceMakeupType)type;

/**
 * @brief Sets the transparency of face makeup effect.
 * @param opactity Specify the face makeup effect's transparency. The value should be between 0 to 100.
 * @param type The specified color uses on which face makeup type.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setOpacity:(int)opacity type:(ZoomSDKFaceMakeupType)type;

/**
 * @brief Disables all the face makeup effect and reset color or opactity value to default value.
 * @return If the function is success returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)resetAllFaceMakeupEffect;
/**
 * @brief Gets the pointer to ZoomSDKSettingTestVideoDeviceHelper for previewing the video with face makeup image.
 * @return If the function succeeds, it returns the pointer to ZoomSDKSettingTestVideoDeviceHelper. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestVideoDeviceHelper*_Nullable)getTestVideoDeviceHelper;
@end


/**
 * @class ZoomSDK3DAvatarImageInfo
 * @brief Represents information of a 3D avatar image.
 */
@interface ZoomSDK3DAvatarImageInfo: NSObject

/**
 * @brief Determines whether the current image is being used.
 */
@property(nonatomic,assign,readonly)BOOL isSelected;

/**
 * @brief Determines whether it is the most recently used image.
 */
@property(nonatomic,assign,readonly)BOOL isLastUsed;

/**
 * @brief Gets the file path of the current image.
 */
@property(nonatomic,copy,readonly,nullable)NSString* imageFilePath;

/**
 * @brief Gets the name of the current image.
 */
@property(nonatomic,copy,readonly,nullable)NSString* imageName;

/**
 * @brief Gets the index of the current image.
 */
@property(nonatomic,assign,readonly)int index;
@end

/**
 * @class ZoomSDKCustom3DAvatarElementImageInfo
 * @brief Represents information of a custom 3D avatar element image.
 */
@interface ZoomSDKCustom3DAvatarElementImageInfo : NSObject

/**
 * @brief Gets the type of the current element image.
 */
@property(nonatomic, assign, readonly)ZoomSDKCustom3DAvatarElementImageType custom3DAvatarElementImageType;

/**
 * @brief Determines whether the current element image is being used.
 */
@property(nonatomic, assign, readonly)BOOL isSelected;

/**
 * @brief Gets the file path of the current element image.
 */
@property(nonatomic, copy, readonly, nullable)NSString* imageFilePath;

/**
 * @brief Gets the name of the current element image.
 */
@property(nonatomic, copy, readonly, nullable)NSString* imageName;

@end

/**
 * @class ZoomSDKCustom3DAvatarElementColorInfo
 * @brief Custom 3D avatar element color information interface.
 * @note These interfaces are only valid for the custom UI mode.
 */
@interface ZoomSDKCustom3DAvatarElementColorInfo : NSObject

/**
 * @brief Gets the type of the current element color.
 */
@property(nonatomic, assign, readonly)ZoomSDKCustom3DAvatarElementColorType custom3DAvatarElementColorType;

/**
 * @brief Gets the color of the current element color in RGB format.
 */
@property(nonatomic, retain, readonly)NSColor* color;

/**
 * @brief Determines whether the current element color is being used.
 */
@property(nonatomic, assign, readonly)BOOL isSelected;

/**
 * @brief Gets the name of the current element color.
 */
@property(nonatomic, copy, readonly, nullable)NSString* imageName;
@end


/**
 * @protocol ZoomSDKCustom3DAvatarElementSettingContextDelegate
 * @brief Custom 3D avatar element setting context callback event.
 */
@protocol ZoomSDKCustom3DAvatarElementSettingContextDelegate <NSObject>

/**
 * @brief Callback event when the custom 3D avatar element image model data download completes.
 * @param isSuccess YES if the custom 3D avatar element image model data has been downloaded successfully, NO otherwise.
 * @param imageInfo The image info for the downloaded custom 3D avatar element image.
 */
- (void)onCustom3DAvatarElementImageModelDataDownloaded:(BOOL)isSuccess elementImage:(ZoomSDKCustom3DAvatarElementImageInfo*)imageInfo;
@end

/**
 * @class ZoomSDKCustom3DAvatarElementSettingContext
 * @brief Context interface for configuring custom 3D avatar elements during avatar creation or editing.
 *
 * These interfaces are provided after calling
 * \link startCreateCustom3DAvatar: \endlink or \link startEditCustom3DAvatar: avatarImage: \endlink, and is used to configure
 * the visual elements of a custom 3D avatar, such as:
 * - Selecting a specific avatar element image (model)
 * - Downloading and checking readiness of element model data
 * - Applying a color to the selected avatar element
 *
 * The context represents an active avatar creation or editing session.
 * All operations performed through this context affect the
 * custom 3D avatar currently being created or edited.
 *
 * @note
 * - These interfaces are only valid during the custom 3D avatar creation or editing process.
 * - Set delegate first before using any other method.
 * - Do not delete the returned image of color lists. They are managed by the SDK.
 * - Model data must be downloaded and ready before applying an image.
 * - These interfaces are only valid for the custom UI mode.
 */
@interface ZoomSDKCustom3DAvatarElementSettingContext : NSObject

/**
 * @brief Gets or sets the delegate for receiving custom 3D avatar element setting events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKCustom3DAvatarElementSettingContextDelegate> delegate;

/**
 * @brief Gets the list of available custom 3D avatar element images.
 * @return If there are images in the list, the return value is an NSArray of custom 3D avatar element image info objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKCustom3DAvatarElementImageInfo*>*_Nullable)getCustom3DAvatarElementImageList;

/**
 * @brief Checks whether the model data for a specific custom 3D avatar element image has been fully downloaded and is ready for use.
 * Before an avatar element image can be applied, its model data must be fully downloaded and ready.
 * @param imageInfo The avatar element image info to check.
 * @return YES if the model data is ready. Otherwise, NO.
 */
- (BOOL)isCustom3DAvatarElementImageModelDataReady:(ZoomSDKCustom3DAvatarElementImageInfo*)imageInfo;

/**
 * @brief Downloads the model data required for a specific custom 3D avatar element image.
 * This should be called if \link isCustom3DAvatarElementImageModelDataReady \endlink returns NO for the specified image.
 * @param imageInfo The avatar element image whose model data should be downloaded.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This should be called before using the image if its model data is not yet ready.
 */
- (ZoomSDKError)downloadCustom3dAvatarElementImageModelData:(ZoomSDKCustom3DAvatarElementImageInfo*)imageInfo;

/**
 * @brief Applies a custom 3D avatar element image to the avatar being created or edited.
 * @param imageInfo The avatar element image to apply.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The model data for the image must be ready before calling this method.
 */
- (ZoomSDKError)setCustom3DAvatarElementImage:(ZoomSDKCustom3DAvatarElementImageInfo*)imageInfo;

/**
 * @brief Gets the list of the custom 3D avatar element colors.
 * @return If there are colors in the list, the return value is an NSArray of custom 3D avatar element color info objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKCustom3DAvatarElementColorInfo*>*_Nullable)getCustom3DAvatarElementColorList;

/**
 * @brief Applies a color to the avatar being created or edited.
 * @param colorInfo The color information to apply.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustom3DAvatarElementColor:(ZoomSDKCustom3DAvatarElementColorInfo*)colorInfo;
@end

/**
 * @protocol ZoomSDK3DAvatarSettingDelegate
 * @brief Delegate protocol for receiving 3D avatar setting events.
 */
@protocol ZoomSDK3DAvatarSettingDelegate <NSObject>

/**
 * @brief Callback event when all 3D avatar items' thumbnails have been downloaded.
 */
- (void)on3DAvatarItemThumbnailsDownloaded;

/**
 * @brief Callback event when the selected 3D avatar item is downloading.
 * @param index The index of the selected 3D avatar item.
 */
- (void)on3DAvatarItemDataDownloading:(int)index;

/**
 * @brief Callback event when the selected 3D avatar item download completes.
 * @param isSuccess YES if the selected 3D avatar item has been downloaded successfully, NO otherwise.
 * @param index The index of the selected 3D avatar item.
 */
- (void)on3DAvatarItemDataDownloaded:(BOOL)isSuccess index:(int)index;

/**
 * @brief Callback event when the custom 3D avatar image model data download completes.
 * @param isSuccess YES if the custom 3D avatar image model data has been downloaded successfully, NO otherwise.
 * @param image The custom 3D avatar image info that was downloaded.
 */
- (void)onCustom3DAvatarImageModelDataDownloaded:(BOOL)isSuccess avatarImage:(ZoomSDK3DAvatarImageInfo *)image;

/**
 * @brief Callback event when all custom 3D avatar element model data download completes.
 * @param isSuccess YES if all custom 3D avatar element model data has been downloaded successfully, NO otherwise.
 */
- (void)onCustom3DAvatarDefaultImageModelDataDownloaded:(BOOL)isSuccess;
@end

/**
 * @class ZoomSDK3DAvatarSetting
 * @brief Interface for configuring 3D avatar settings.
 */
@interface ZoomSDK3DAvatarSetting : NSObject
{
    ZoomSDKVideoLipSyncAvatarPreviewHelper* lipsyncAvatarPreviewHelper;
    id<ZoomSDK3DAvatarSettingDelegate>       _delegate;
}
/**
 * @brief Gets or sets the delegate for receiving 3D avatar setting events.
 */
@property(nonatomic,assign, nullable)id<ZoomSDK3DAvatarSettingDelegate> delegate;

/**
 * @brief Determines whether the 3D avatar feature is supported by the video device.
 * @return YES if the video device supports the 3D avatar feature. Otherwise, NO.
 */
- (BOOL)is3DAvatarSupportedByDevice;

/**
 * @brief Determines whether the 3D avatar feature is enabled.
 * @return YES if the 3D avatar feature is enabled. Otherwise, NO.
 */
- (BOOL)is3DAvatarEnabled;

/**
 * @brief Gets the list of the 3D avatar images.
 * @return If the function succeeds, it returns an NSArray of 3D avatar image info objects. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDK3DAvatarImageInfo*>*_Nullable)get3DAvatarImageList;

/**
 * @brief Specifies an image to be the 3D avatar image.
 * @param image The image to use.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)set3DAvatarImage:(ZoomSDK3DAvatarImageInfo*)image;

/**
 * @brief Gets the object to test the video device.
 * @return If the function succeeds, it returns a ZoomSDKSettingTestVideoDeviceHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestVideoDeviceHelper*_Nullable)getTestVideoDeviceHelper;

/**
 * @brief Gets the object to preview the lip-sync avatar.
 * @return If the function succeeds, it returns a ZoomSDKVideoLipSyncAvatarPreviewHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKVideoLipSyncAvatarPreviewHelper*_Nullable)getLipSyncAvatarPreviewHelper;

/**
 * @brief Enables or disables the 3D avatar effect when joining a meeting.
 * @param enable YES to enable the 3D avatar effect, NO to disable.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enable3DAvatarEffectForAllMeeting:(BOOL)enable;

/**
 * @brief Determines whether the 3D avatar is enabled when joining a meeting.
 * @return YES if the 3D avatar is enabled when joining a meeting. Otherwise, NO.
 */
- (BOOL)is3DAvatarEffectForAllMeetingEnabled;

/**
 * @brief Determines whether the custom 3D avatar feature is enabled.
 * @return YES if the custom 3D avatar feature is enabled. Otherwise, NO.
 */
- (BOOL)isCustom3DAvatarEnabled;

/**
 * @brief Gets the list of available custom 3D avatar images.
 * Each image represents a custom 3D avatar that can be selected, edited, duplicated, or deleted.
 * @return If there are images in the list, the return value is an NSArray of custom 3D avatar image info objects. Otherwise, this function fails and returns nil.
 * @note This interface is only valid for the custom UI mode.
 */
- (NSArray<ZoomSDK3DAvatarImageInfo*>*_Nullable)getCustom3DAvatarImageList;

/**
 * @brief Checks whether the model data for a specific custom 3D avatar image is ready.
 * The avatar image can only be used after its model data has been fully downloaded and prepared.
 * @param imageInfo The custom 3D avatar image info to check.
 * @return YES if the model data for the specified image has been downloaded and is ready. Otherwise, NO.
 * @note This interface is only valid for the custom UI mode.
 */
- (BOOL)isCustom3DAvatarImageModelDataReady:(ZoomSDK3DAvatarImageInfo*)imageInfo;

/**
 * @brief Downloads the model data required for a specific custom 3D avatar image.
 * Call this method if \link isCustom3DAvatarImageModelDataReady \endlink returns NO for the specified custom 3D avatar image.
 * @param imageInfo The custom 3D avatar image whose model data should be downloaded.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This should be called before calling \link setCustom3DAvatarImage: \endlink if its model data is not yet ready.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)downloadCustom3DAvatarImageModelData:(ZoomSDK3DAvatarImageInfo*)imageInfo;

/**
 * @brief Applies a custom 3D avatar image as the active avatar.
 * @param imageInfo The custom 3D avatar image to apply.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The model data for the avatar image must be fully downloaded and ready before calling this method.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)setCustom3DAvatarImage:(ZoomSDK3DAvatarImageInfo*)imageInfo;

/**
 * @brief Checks whether the model data for default custom 3D avatar elements image have been fully downloaded and are ready for use.
 * This method is typically used before starting the custom 3D avatar creation process to ensure default elements data is available.
 * @return YES if the model data for all custom 3D avatar elements image have been downloaded and are ready. Otherwise, NO.
 * @note This interface is only valid for the custom UI mode.
 */
- (BOOL)isCustom3DAvatarDefaultImageModelDataReady;

/**
 * @brief Downloads the model data required for a default custom 3D avatar image.
 * Call this method if  \link isCustom3DAvatarDefaultImageModelDataReady \endlink returns NO for the default custom 3D avatar image.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This should be called before calling \link startCreateCustom3DAvatar: \endlink if the default image model data is not yet ready.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)downloadCustom3DAvatarDefaultImageModelData;

/**
 * @brief Starts creating a new custom 3D avatar.
 * This method initializes a custom 3D avatar creation session
 * and returns a \link  ZoomSDKCustom3DAvatarElementSettingContext \endlink instance for configuring avatar elements (image, model data, color, etc.).
 * @param previewView The view used to render the avatar preview.
 * @return If the function succeeds, the return value is a \link  ZoomSDKCustom3DAvatarElementSettingContext \endlink object. Otherwise, this function fails and returns nil.
 * @note The model data for all elements image must be ready before calling this method. Otherwise returns nil.
 * If the function succeeds, before calling \link  finishCreateCustom3DAvatar: \endlink,
 * calling 3D-avatar-related API will result in an error. The maximum number of custom 3D avatars is 25. Exceeding this limit will result in an error.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKCustom3DAvatarElementSettingContext*_Nullable)startCreateCustom3DAvatar:(NSView*)previewView;

/**
 * @brief Finishes creating a custom 3D avatar.
 * This method ends the custom 3D avatar creation session that was started by \link startCreateCustom3DAvatar: \endlink.
 * @param save YES to apply the selected avatar elements and save the newly created custom 3D avatar, NO to discard all changes and cancel the creation.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)finishCreateCustom3DAvatar:(BOOL)save;

/**
 * @brief Starts editing an existing custom 3D avatar.
 * This method starts an editing session for the specified custom 3D avatar
 * and returns a \link ZoomSDKCustom3DAvatarElementSettingContext \endlink instance for modifying avatar elements such as images and colors.
 * @param previewView The view used to render the avatar preview.
 * @param imageInfo The image info of the custom 3D avatar to edit.
 * @return If the function succeeds, the return value is a \link ZoomSDKCustom3DAvatarElementSettingContext \endlink object. Otherwise, this function fails and returns nil.
 * @note The model data for the avatar image must be fully downloaded and ready before calling this method.
 * After this method succeeds and before calling \link finishEditCustom3DAvatar: \endlink, invoking other 3D avatar-related APIs will result in an error.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKCustom3DAvatarElementSettingContext*_Nullable)startEditCustom3DAvatar:(NSView*)previewView avatarImage:(ZoomSDK3DAvatarImageInfo*)imageInfo;

/**
 * @brief Finishes editing a custom 3D avatar.
 * This method ends the custom 3D avatar editing session that was started by \link startEditCustom3DAvatar: avatarImage: \endlink.
 * @param save YES to apply the selected avatar elements and save the edited custom 3D avatar, NO to discard all changes and cancel the editing.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)finishEditCustom3DAvatar:(BOOL)save;

/**
 * @brief Duplicates a custom 3D avatar.
 * @param imageInfo The custom 3D avatar image to duplicate.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The maximum number of custom 3D avatars is 25. Exceeding this limit will result in an error.
 * This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)duplicateCustom3DAvatarImage:(ZoomSDK3DAvatarImageInfo*)imageInfo;

/**
 * @brief Deletes a custom 3D avatar.
 * @param imageInfo The custom 3D avatar image to delete.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note This interface is only valid for the custom UI mode.
 */
- (ZoomSDKError)deleteCustom3DAvatarImage:(ZoomSDK3DAvatarImageInfo*)imageInfo;
@end

NS_ASSUME_NONNULL_END

