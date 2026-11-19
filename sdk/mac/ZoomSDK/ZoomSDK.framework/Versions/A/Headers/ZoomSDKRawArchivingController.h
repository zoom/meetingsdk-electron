/**
 * @file ZoomSDKRawArchivingController.h
 * @brief Interface for controlling raw archiving (recording raw data) in Zoom SDK.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKRawArchivingController
 * @brief Controller for managing raw archiving privilege in Zoom SDK.
 */
@interface ZoomSDKRawArchivingController : NSObject

/**
 * @brief Starts raw archiving, call this method can get rawdata receive privilege.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startRawArchiving;

/**
 * @brief Stops raw archiving, call this method reclaim rawdata receive privilege.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopRawArchiving;
@end

NS_ASSUME_NONNULL_END
