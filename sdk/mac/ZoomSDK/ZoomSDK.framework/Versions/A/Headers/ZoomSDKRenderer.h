/**
 * @file ZoomSDKRenderer.h
 * @brief Interface for rendering and receiving raw video data in Zoom SDK.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
@class ZoomSDKYUVRawDataI420;
@class ZoomSDKFaceROIInfo;

/**
 * @class ZoomSDKShareCursorData
 * @brief Represents the cursor position data during screen sharing.
 */
@interface ZoomSDKShareCursorData : NSObject

/**
 * @brief The source ID of the share cursor.
 */
@property (nonatomic, assign, readonly) unsigned int sourceID;

/**
 * @brief The x value of the coordinate.
 */
@property (nonatomic, assign, readonly) int x;

/**
 * @brief The y value of the coordinate.
 */
@property (nonatomic, assign, readonly) int y;
@end

/**
 * @brief Face region of interest reported alongside a decoded frame.
 *
 * Coordinates are normalized to [0.0, 1.0], with the origin at the top-left
 * corner of the decoded (pre-rotation) frame. Callers that need display
 * coordinates must apply the frame rotation reported by
 * @c -getRotation on the host @ref ZoomSDKYUVRawDataI420.
 */
@interface ZoomSDKFaceROI : NSObject
/** Normalized left edge, [0.0, 1.0]. */
@property (readonly, nonatomic) float left;
/** Normalized top edge, [0.0, 1.0]. */
@property (readonly, nonatomic) float top;
/** Normalized right edge, [0.0, 1.0], > left. */
@property (readonly, nonatomic) float right;
/** Normalized bottom edge, [0.0, 1.0], > top. */
@property (readonly, nonatomic) float bottom;
@end

/**
 * @class ZoomSDKFaceROIInfo
 * @brief Per-frame face ROI metadata accessor.
 *
 * Face ROI data is generated on the sender's device and embedded in the
 * video stream. The receiver SDK only surfaces what the sender provides;
 * no face detection is performed locally. Individual participants may
 * deliver frames with zero detected faces — for example, when their device
 * does not support face detection or detection is not currently active.
 *
 * Lifetime is bound to the host @ref ZoomSDKYUVRawDataI420. Do not retain
 * this object past the raw data delegate callback unless the host frame has
 * also been retained via @c -addRef.
 *
 * @note Face ROI is only supported on video streams.
 */
@interface ZoomSDKFaceROIInfo : NSObject

/**
 * @brief Number of valid face ROIs available for the current frame.
 *
 * When multiple faces are present, the ROIs are ordered by the area of the
 * detected region in descending order — index 0 corresponds to the largest
 * (typically closest or most prominent) face.
 *
 * @return The face count in the range [0, 50]. A value of zero means no
 *         face was detected, the sender has not enabled detection, or
 *         face metadata was not delivered for this frame.
 */
- (NSUInteger)getFaceCount;

/**
 * @brief Get a face ROI by zero-based index.
 *
 * Faces are sorted by detected region area in descending order; index 0
 * is always the largest face in the frame.
 *
 * @param index The zero-based index, must be < @c -getFaceCount.
 * @return The face ROI on success, or @c nil if @p index is out of range.
 */
- (nullable ZoomSDKFaceROI *)getFaceROIByIndex:(NSUInteger)index;

@end

/**
 * @class ZoomSDKYUVRawDataI420
 * @brief Represents raw YUV I420 format data received from subscribed video stream.
 */
@interface ZoomSDKYUVRawDataI420 : NSObject
/**
 * @brief Gets if this object can add ref.
 * @return If can add ref, it returns YES. Otherwise, NO.
 */
- (BOOL)canAddRef;
/**
 * @brief Adds reference for this object, if you doesn't add ref, this object is released when the callback response ends.
 * @return If the function succeeds, it returns YES. Otherwise, NO.
 */
- (BOOL)addRef;
/**
 * @brief Release the object, if you has add ref, remeber to call this api to release when you wantn't to use this object.
 * @return If the function succeeds, it returns reference count of this object. Otherwise, returns -1.
 */
- (int)releaseData;
/**
 * @brief Gets the Y data.
 * @return If the function succeeds, it returns the Y data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getYBuffer;
/**
 * @brief Gets the U data.
 * @return If the function succeeds, it returns the U data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getUBuffer;
/**
 * @brief Gets the V data.
 * @return If the function succeeds, it returns the V data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getVBuffer;
/**
 * @brief Gets the buffer data.
 * @return If the function succeeds, it returns the buffer data. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getBuffer;
/**
 * @brief Gets video alpha mask data buffer.
 * @return Buffer address if alpha data exists. Otherwise, this function fails and returns nil.
 */
- (char*_Nullable)getAlphaBuffer;
/**
 * @brief Gets the buffer length of this data.
 * @return If the function succeeds, it returns the buffer length of this data. Otherwise, returns 0.
 */
- (unsigned int)getBufferLen;
/**
 * @brief Gets the alpha buffer length.
  * @return The length of alpha data.
 */
- (unsigned int)getAlphaBufferLen;
/**
 * @brief Gets if this data is limited I420 format.
 * @return If is limited I420 format, it returns YES. Otherwise, NO.
 */
- (BOOL)isLimitedI420;
/**
 * @brief Gets the stream width of this data.
 * @return If the function succeeds, it returns the stream width of this data. Otherwise, returns 0.
 */
- (unsigned int)getStreamWidth;
/**
 * @brief Gets the stream height of this data.
 * @return If the function succeeds, it returns the stream height of this data. Otherwise, returns 0.
 */
- (unsigned int)getStreamHeight;
/**
 * @brief Gets the rotation of this data.
 * @return If the function succeeds, it returns the rotation of this data. Otherwise, returns 0.
 */
- (unsigned int)getRotation;
/**
 * @brief Gets the source ID of this data.
 * @return If the function succeeds, it returns the source ID of this data. Otherwise, returns 0.
 */
- (unsigned int)getSourceID;
/**
 * @brief Gets the raw data's timestamp.
 * @return If the function succeeds, it returns the millisecond timestamp. Otherwise, returns 0.
 */
- (long long)getTimeStamp;

/**
 * @brief Gets the face ROI metadata associated with this frame.
 *
 * Always returns a valid object; inspect @c -getFaceCount to determine
 * whether any face was reported. The returned object's lifetime is bound to
 * this @ref ZoomSDKYUVRawDataI420 instance.
 *
 * @note Face ROI is only supported on video streams (@c ZoomSDKRawDataType_Video).
 *
 * @return A non-null face ROI accessor.
 */
- (ZoomSDKFaceROIInfo *)getFaceROIInfo;
@end


/**
 * @protocol ZoomSDKRendererDelegate
 * @brief Callback interface for receiving video render events.
 */
@protocol ZoomSDKRendererDelegate <NSObject>
/**
 * @brief Notify if subscribed user's video data becomes available.
 */
- (void)onSubscribedUserDataOn;
/**
 * @brief Notify if subscribed user's video data becomes unavailable.
 */
- (void)onSubscribedUserDataOff;

/**
 * @brief Notify if raw data is received for rendering.
 * @param data The rawData status.
 */
- (void)onRawDataReceived:(ZoomSDKYUVRawDataI420*_Nullable)data;
@optional
/**
 * @brief Callback when the cursor data of share is received.
 * @param info Share cursor data object.
 */
- (void)onShareCursorDataReceived:(ZoomSDKShareCursorData *)info;
@required
/**
 * @brief Notify if the renderer is being destroyed.
 */
- (void)onRendererBeDestroyed;
@end


/**
 * @class ZoomSDKRenderer
 * @brief Subscribe to raw video or share data and handle rendering.
 */
@interface ZoomSDKRenderer : NSObject
{
    unsigned int                  _subscribeID;
    ZoomSDKRawDataType            _rawDataType;
    ZoomSDKResolution             _resolution;
    id<ZoomSDKRendererDelegate>   _delegate;
}
/**
 * @brief The delegate to receive rendering events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKRendererDelegate> delegate;

/**
 * @brief Subscribe to receive raw data.
 * @param subscribeID The subscribe ID of the raw data user want to receive. If subscribe video, the subscribeID is user ID. If subscribe the sharing, the subscribeID is share source ID.
 * @param rawDataType The type of raw data user want to receive.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)subscribe:(unsigned int)subscribeID rawDataType:(ZoomSDKRawDataType)rawDataType;

/**
 * @brief Unsubscribe to receive raw data.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)unSubscribe;

/**
 * @brief Gets the type of raw data.
 * @return The type of raw data.
 */
- (ZoomSDKRawDataType)getRawDataType;

/**
 * @brief Gets the subscribe ID of raw data user is subscribing to.
 * @return If the function succeeds, it returns the subscribe ID. Otherwise, returns -1.
 */
- (unsigned int)getSubscribeID;

/**
 * @brief Gets the resolution of raw data.
 * @return The resolution.
 */
- (ZoomSDKResolution)getResolution;

/**
 * @brief Sets the resolution of raw data.
 * @param resolution The resolution of raw data user want to receive.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setResolution:(ZoomSDKResolution)resolution;
@end

NS_ASSUME_NONNULL_END
