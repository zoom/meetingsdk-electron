/**
 * @file ZoomSDKCameraControlHelper.h
 * @brief Interface for controlling remote camera during Zoom meetings.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKCameraControlHelper
 * @brief Provides APIs to control the remote camera, including pan, tilt, and zoom operations.
 */
@interface ZoomSDKCameraControlHelper : NSObject
/**
 * @brief Gets the controlled user ID.
 * @return If the function succeeds, it returns the user ID. Otherwise return 0.
 */
- (unsigned int)getUserId;

/**
 * @brief Determines whether the camera can be controlled or not.
 * @return YES if the camera can be controlled. Otherwise, NO.
 */
- (BOOL)canControlCamera;

/**
 * @brief Request to control remote camera.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestControlRemoteCamera;

/**
 * @brief Give up control of the remote camera.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)giveUpControlRemoteCamera;

/**
 * @brief Turn the camera to the left.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnLeft:(int)range;

/**
 * @brief Turn the camera to the right.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnRight:(int)range;

/**
 * @brief Turn the camera up.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnUp:(int)range;

/**
 * @brief Turn the camera down.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnDown:(int)range;

/**
 * @brief Zoom the camera in.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)zoomIn:(int)range;

/**
 * @brief Zoom the camera out.
 * @param range Rotation range, between 10 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)zoomOut:(int)range;
@end

NS_ASSUME_NONNULL_END
