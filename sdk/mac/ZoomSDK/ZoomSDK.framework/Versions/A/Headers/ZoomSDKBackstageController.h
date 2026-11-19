/**
 * @file ZoomSDKBackstageController.h
 * @brief Interfaces for managing webinar backstage (green room) features in Zoom SDK.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKBackstageController
 * @brief Controller for managing webinar backstage (green room) functions.
 */
@interface ZoomSDKBackstageController : NSObject

/**
 * @brief Determines if the backstage feature is enabled for the current webinar.
 * @return YES if the backstage feature is enabled. Otherwise, NO.
 */
- (BOOL)isBackstageEnabled;

/**
 * @brief Determines if the local user can enter the backstage.
 * @return YES if the local user can enter the backstage. Otherwise, NO.
 * @note Returns NO when the local user is a panelist and the host does not allow panelists to switch between the main session and the backstage on their own.
 */
- (BOOL)canJoinBackstage;

/**
 * @brief Makes the local user enter the backstage.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user will receive the onMeetingStatusChange callback event with ZoomSDKMeetingStatus_Join_Backstage.
 */
- (ZoomSDKError)joinBackstage;

/**
 * @brief Determines if the local user can leave the backstage.
 * @return YES if the local user can leave the backstage. Otherwise, NO.
 */
- (BOOL)canLeaveBackstage;

/**
 * @brief Makes the local user leave the backstage and return to the main session.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the function succeeds, the user will receive the onMeetingStatusChange callback event with ZoomSDKMeetingStatus_Leave_Backstage.
 * The switch takes effect immediately; the SDK does not apply the countdown used by the Zoom client.
 */
- (ZoomSDKError)leaveBackstage;

/**
 * @brief Determines if the specified user can be moved into the backstage.
 * @param userID Specify the user ID to check.
 * @return YES if the user can be moved into the backstage. Otherwise, NO.
 * @warning Only meeting host or co-host can run the function.
 */
- (BOOL)canMoveUserToBackstage:(unsigned int)userID;

/**
 * @brief Moves the specified users into the backstage.
 * @param userIDs Specify the array of user IDs to move. Each element should be an NSNumber containing unsigned int.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @warning Only meeting host or co-host can run the function.
 * @note The return value only indicates that the request was sent. Track the per-user outcome through user join/left events.
 */
- (ZoomSDKError)moveUsersToBackstage:(NSArray<NSNumber *> *)userIDs;

/**
 * @brief Determines if the specified user can be moved back to the main session.
 * @param userID Specify the user ID to check.
 * @return YES if the user can be moved back to the main session. Otherwise, NO.
 * @warning Only meeting host or co-host can run the function.
 * @note Valid whether or not the local user is currently in the backstage.
 */
- (BOOL)canMoveUserToMainSession:(unsigned int)userID;

/**
 * @brief Moves the specified users from the backstage back to the main session.
 * @param userIDs Specify the array of user IDs to move. Each element should be an NSNumber containing unsigned int.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @warning Only meeting host or co-host can run the function.
 */
- (ZoomSDKError)moveUsersToMainSession:(NSArray<NSNumber *> *)userIDs;

/**
 * @brief Determines if the local user can set the local playback volume of the main session audio.
 * @return YES if the local user is in the backstage. Otherwise, NO.
 * @note When this method returns NO, setMainSessionAudioVolume: returns ZoomSDKError_WrongUsage.
 */
- (BOOL)canSetMainSessionAudioVolume;

/**
 * @brief Sets the local playback volume of the main session audio while in the backstage.
 * @param value The volume that ranges from 0 to 255.
 * @return If the function succeeds, the return value is ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Available only when the local user is in the backstage. The change is local and does not affect other users.
 */
- (ZoomSDKError)setMainSessionAudioVolume:(float)value;

/**
 * @brief Gets the local playback volume of the main session audio while in the backstage.
 * @return The current volume that ranges from 0 to 255. Returns 0 if the function fails.
 * @note Available only when the local user is in the backstage.
 */
- (float)getMainSessionAudioVolume;

@end

NS_ASSUME_NONNULL_END
