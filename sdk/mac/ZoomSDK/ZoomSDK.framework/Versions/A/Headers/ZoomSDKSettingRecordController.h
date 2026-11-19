


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @protocol ZoomSDKSettingRecordDelegate
 * @brief Delegate to notify cloud recording storage info.
 */
@protocol ZoomSDKSettingRecordDelegate <NSObject>
@optional
/**
 * @brief Notify of cloud recording storage info.
 * @param totalSize The total size of cloud recording storage.
 * @param usedSize The used size of cloud recording storage.
 * @param allowExceedStorage YES if exceeding storage is allowed, NO otherwise.
 */
- (void)onNotifyCloudRecordingStorageInfo:(long long)totalSize usedSize:(long long)usedSize isAllowExceedStorage:(BOOL)allowExceedStorage;
@end


/**
 * @class ZoomSDKRecordSetting
 * @brief Interface for recording settings.
 */
@interface ZoomSDKRecordSetting: NSObject
{
    id<ZoomSDKSettingRecordDelegate>       _delegate;
}
/**
 * @brief Delegate object for receiving recording setting events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingRecordDelegate> delegate;
/**
 * @brief Sets the path for saving the meeting recording file.
 * @param path The path for saving the meeting recording file.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The parameter 'path' must already be present, or the path cannot be set successfully.
 */
- (ZoomSDKError)setRecordingPath:(NSString*)path;

/**
 * @brief Gets the current meeting's recorded path.
 * @return If the function succeeds, it returns the recording path. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getRecordingPath;

/**
 * @brief Determines if choose recording path when meeting ended is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableChooseRecordingPathWhenMeetingEnd;

/**
 * @brief Enables or disable choose recording path when meeting ended.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)chooseRecordingPathWhenMeetingEnd:(BOOL)enable;

/**
 * @brief Determines if record audio for every attendee individually is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableRecordAudioForEveryAttendeeIndividually;

/**
 * @brief Enables or disable record audio for every attendee individually.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)recordAudioForEveryAttendeeIndividually:(BOOL)enable;

/**
 * @brief Determines if optimize for third party video editor is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableOptimizeFor3PartyVideoEditor;

/**
 * @brief Enables or disable optimize for third party video editor.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)OptimizeFor3PartyVideoEditor:(BOOL)enable;

/**
 * @brief Determines if add timestamp for recording is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableAddTimestampForRecording;

/**
 * @brief Enables or disable add timestamp for recordin.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addTimestampForRecording:(BOOL)enable;

/**
 * @brief Determines if recording during screen sharing is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableRecordDuringScreenSharing;

/**
 * @brief Enables or disable record during screen sharing .
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)recordDuringScreenSharing:(BOOL)enable;

/**
 * @brief Determines if display video next to share contents in recording file is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableDisplayVideoNextToShareContentsInRecordingFile;

/**
 * @brief Enables or disable display video next to share contents in recording file.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)displayVideoNextToShareContentsInRecordingFile:(BOOL)enable;

/**
 * @brief Determines if the user have privilege to get cloud recording storage info.
 * @return YES if can get info. Otherwise, NO.
 */
- (BOOL)canGetCloudRecordingStorageInfo;

/**
 * @brief Call to get cloud recording storage info if the user has the privilege to get cloud recording storage info.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note The cloud recording storage info will be notified to user through delegate ZoomSDKSettingRecordDelegate when you have call this api successfully.
 */
- (ZoomSDKError)getCloudRecordingStorageInfo;

/**
 * @brief Determines if the user have privilege to get cloud recording management URL.
 * @return YES if can get url. Otherwise, NO.
 */
- (BOOL)canGetRecordingManagementURL;

/**
 * @brief Call to get cloud recording management URL if the user has the privilege to get cloud recording management URL.
 * @return If the function succeeds, it returns the cloud recording management URL. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getRecordingManagementURL;

/**
 * @brief Sets the cloud recording manage url in the recording setting page.
 * @param recordingMgrUrl Specify the cloud recording manage url in the recording setting page.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustomizedCloudRecordingMgrUrl:(NSString *)recordingMgrUrl;
@end
NS_ASSUME_NONNULL_END
