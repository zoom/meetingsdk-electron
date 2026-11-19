

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKAutoFramingParameter
 * @brief Parameters for auto-framing feature in Zoom SDK.
 */
@interface ZoomSDKAutoFramingParameter : NSObject
/**
 * @brief The zoom in ratio of auto-framing, valid range of values: 1~10(when mode is ZoomSDKAutoFramingMode_Center_Coordinates), 0.1~10(when mode is ZoomSDKAutoFramingMode_Face_Recognition).
 */
@property (assign,nonatomic) float ratio;
/**
 * @brief The strategy when face recognition failed.
 */
@property (assign,nonatomic) ZoomSDKFaceRecognitionFailStrategy failStrategy;
@end


/**
 * @protocol ZoomSDKSettingVideoDelegate
 * @brief Delegate to receive video device related events.
 */
@protocol ZoomSDKSettingVideoDelegate <NSObject>
@optional
/**
 * @brief Notification of camera status changes in the meeting.
 * @param status The camera device status.
 */
- (void)onCameraStatusChanged:(ZoomSDKDeviceStatus)status;
/**
 * @brief Notification that the selected camera device is changed.
 * @param deviceID The ID of camera.
 */
- (void)onSelectedCameraChanged:(NSString*)deviceID;
@end

/**
 * @class ZoomSDKSettingTestVideoDeviceHelper
 * @brief Helper class for testing video devices.
 */
@interface ZoomSDKSettingTestVideoDeviceHelper: NSObject
{
    id<ZoomSDKSettingVideoDelegate>       _delegate;
}
/**
 * @brief Delegate to receive video device events.
 * @deprecated This property is deprecated. Use ZoomSDKVideoSetting.delegate instead.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingVideoDelegate> delegate DEPRECATED_MSG_ATTRIBUTE("This property is deprecated. Use ZoomSDKVideoSetting.delegate instead.");

/**
 * @brief Sets the frame of video preview and tells Zoom client the parent view where the video preview is drawn.
 * @param parentView The parent view where the video preview will be drawn.
 * @param containerRect The frame displaying video preview.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)SetVideoParentView:(NSView*)parentView VideoContainerRect:(NSRect)containerRect;

/**
 * @brief Preview user's video with default camera.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)StartPreview;
/**
 * @brief Stops previewing user's video.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)StopPreview;
@end


/**
 * @class ZoomSDKVideoPreferenceSetting
 * @brief Settings for video preference modes including frame rates and resolution adaptation.
 *
 * When custom modes are set, the developer provides the maximum and minimum frame rates. If the current bandwidth cannot maintain the minimum frame rate, the video system will drop to the next lower resolution. The default maximum and minimum frame rates for other modes are 0.
 */
@interface ZoomSDKVideoPreferenceSetting : NSObject
/**
 * @brief Preferred video mode.
 */
@property (nonatomic, assign, readwrite) ZoomSDKVideoPreferenceMode mode;
    
/**
 * @brief 0 for the default value, minimumFrameRate should be less than maximumFrameRate,
 * @note range: from 0 to 30. Out of range for frame rate will use default frame rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int minimumFrameRate;
    
/**
 * @brief 0 for the default value, maximumFrameRate should be less and equal than 30,
 * @note range: from 0 to 30. Out of range for frame rate will use default frame rate of Zoom.
 */
@property (nonatomic, assign, readwrite) unsigned int maximumFrameRate;
@end


/**
 * @class ZoomSDKVideoSetting
 * @brief Interface for video settings including camera selection, video effects, beauty mode, and auto-framing.
 */
@interface ZoomSDKVideoSetting: NSObject
{
    ZoomSDKSettingTestVideoDeviceHelper* settingVideoTestHelper;
    id<ZoomSDKSettingVideoDelegate>       _delegate;
}
/**
 * @brief Delegate to receive video device events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingVideoDelegate> delegate;

/**
 * @brief Gets the object to test video device.
 * @return If the function succeeds, it returns a ZoomSDKSettingTestVideoDeviceHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestVideoDeviceHelper*_Nullable)getSettingVideoTestHelper;

/**
 * @brief Gets the list of camera device.
 * @return If the function succeeds, it returns an array containing SDKDeviceInfo element. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getCameraList;

/**
 * @brief Select a camera.
 * @param deviceID The ID of camera.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)selectCamera:(NSString*)deviceID;

/**
 * @brief Determines if mirror effect is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isMirrorEffectEnabled;

/**
 * @brief Sets to enable or disable mirror effect.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableMirrorEffect:(BOOL)enable;

/**
 * @brief Determines if facial beauty effect is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isBeautyFaceEnabled;

/**
 * @brief Enable or disable facial beauty effect.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableBeautyFace:(BOOL)enable;

/**
 * @brief Gets beauty face value.
 * @return If the function succeeds, it returns an int value(0-100). Otherwise returns 0.
 */
- (int)getBeautyFaceValue;

/**
 * @brief Sets beauty face value.
 * @param value The value type is int, varies from 0 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setBeautyFaceValue:(int)value;
/**
 * @brief Turn off the participant's video when he joins meeting.
 * @param disable YES if the video is turned off, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)disableVideoJoinMeeting:(BOOL)disable;

/**
 * @brief Display or Hide username on the video window.
 * @param display YES to showing always username on the video window, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)displayUserNameOnVideo:(BOOL)display;

/**
 * @brief Enables or disable HD video.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableCatchHDVideo:(BOOL)enable;
/**
 * @brief Sets to capture video ratio: original or 16:9.
 * @param originalSize YES if original video, NO 16:9.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)onVideoCaptureOriginalSizeOr16To9:(BOOL)originalSize;
/**
 * @brief Enables to spotlight the current user's video in the main interface when he speaks in the meeting.
 * @param enable YES if spotlighting always the current user's video, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)onSpotlightMyVideoWhenISpeaker:(BOOL)enable;
/**
 * @brief Enables or disable to show the participants in Gallery View up to 49 per screen.
 * @param enable YES indicates to show the participants in Gallery View up to 49 per screen, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)onDisplayUpTo49InWallView:(BOOL)enable;
/**
 * @brief Enables or disable to hide the non-video participants.
 * @param hide YES if hiding, NO if displaying.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hideNoVideoUser:(BOOL)hide;
/**
 * @brief Determines if non-video participant is hided or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isHideNoVideoUser;
/**
 * @brief Query if original size of video is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isCaptureOriginalSize;
/**
 * @brief Determines if spotlighting the current user's video is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isSpotlightMyVideoOn;
/**
 * @brief Determines if the current user's video is muted when he joins meeting.
 * @return YES if muted. Otherwise, NO.
 */
- (BOOL)isMuteMyVideoWhenJoinMeetingOn;
/**
 * @brief Determines if displaying screen name of the user is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isdisplayUserNameOnVideoOn;
/**
 * @brief Determines if it is able to display up to 49 participants in video wall mode.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isCanDisplayUpTo49InWallView;
/**
 * @brief Determines whether to display up to 49 participants in video wall mode.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isDisplayUpTo49InWallViewOn;
/**
 * @brief Determines if HD video is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isCatchHDVideoOn;
/**
 * @brief Determines if adjustion for low light.
 * @return The ZoomSDKSettingVideoLightAdaptionModel.
 */
- (ZoomSDKSettingVideoLightAdaptionModel)getLightAdjustModel;
/**
 * @brief Sets the way to adjust the low light.
 * @param model The model to be set.
 * @param value The value type is int, varies from 0 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setLightAdaptionModel:(ZoomSDKSettingVideoLightAdaptionModel)model LightAdaptionManualValue:(int)value;
/**
 * @brief Gets the setted's value.
 * @return If the function succeeds, it returns an int value(0-100). Otherwise returns 0.
 */
- (int)getLightAdaptionManualValue;

/**
 * @brief Determines whether to hardware acceleration for video receive.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isHardwareAccelerationForVideoReceiveOn;

/**
 * @brief Enables or disable hardware acceleration for video receive.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableHardwareAccelerationForVideoReceive:(BOOL)enable;

/**
 * @brief Determines whether to de-noise.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isTemporalDeNoiseOn;

/**
 * @brief Enables or disable de-noise.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableTemporalDeNoise:(BOOL)enable;

/**
 * @brief Determines if optimizing received video quality is supported.
 * @return YES if it is supported, Otherwise, NO.
 */
- (BOOL)isOptimizeVideoQualitySupported;

/**
 * @brief Determines if optimizing received video quality is enabled.
 * @return YES if optimization is enabled. Otherwise, NO.
 */
- (BOOL)isOptimizeVideoQualityEnabled;

/**
 * @brief Enables or disable optimizing received video quality when facing network issues for a variety of reasons. Applies to the window in focus: speaker view, pinned / spotlighted videos, gallery view with a small number of videos
 * @param enable YES to enable this feature, NO to disable this feature.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableOptimizeVideoQuality:(BOOL)enable;

/**
 * @brief Enables or disable to stop incoming video.
 * @param enable YES indicates to enable to stop incoming video, NO to disable.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableStopIncomingVideo:(BOOL)enable;

/**
 * @brief Gets the flag to enable or disable to stop in coming video.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isStopIncomingVideoEnabled;

/**
 * @brief Enables or disable to hide the userself's view.
 * @param enable YES indicates to enable to hide the userself's view, NO to disable.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableHideSelfView:(BOOL)enable;

/**
 * @brief Gets the flag to enable or disable to hide userself's view.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isHideSelfViewEnabled;

/**
 * @brief Starts my video auto-framing.
 * @param mode The auto-framing mode.
 * @param parameter The setting of video auto-framing.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableVideoAutoFraming:(ZoomSDKAutoFramingMode)mode setting:(ZoomSDKAutoFramingParameter *)parameter;

/**
 * @brief Stops video auto-framing.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)disableVideoAutoFraming;

/**
 * @brief Determines whether auto-framing is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isVideoAutoFramingEnabled;

/**
 * @brief Gets the auto-framing mode.
 * @return The auto-framing mode.
 */
- (ZoomSDKAutoFramingMode)getVideoAutoFramingMode;

/**
 * @brief Gets the auto-framing parameter.
 * @param mode The auto-framing mode.
 * @return If the function succeeds, it returns the auto-framing parameter. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAutoFramingParameter *_Nullable)getVideoAutoFramingSettingWithMode:(ZoomSDKAutoFramingMode)mode;

/**
 * @brief Sets the mode of auto-framing when auto-framing is enabled.
 * @param mode The mode of auto-framing.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setVideoAutoFramingMode:(ZoomSDKAutoFramingMode)mode;

/**
 * @brief Sets the zoom in ratio of auto-framing when auto-framing is enabled.
 * @param ratio The zoom in ratio, effective range: 0.7 < ratio < 2.1.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setVideoAutoFramingRatio:(float)ratio;

/**
 * @brief Sets the fail strategy of face recognition when auto-framing is enabled(mode is @c ZoomSDKAutoFramingMode_Face_Recognition).
 * @param strategy The fail strategy of face recognition.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setFaceRecognitionFailStrategy:(ZoomSDKFaceRecognitionFailStrategy)strategy;

/**
 * @brief Sets the video quality preference that automatically adjust user's video to prioritize frame rate versus resolution based on the current bandwidth available.
 * @param preferenceSetting An instance of ZoomSDKVideoPreferenceSetting.
 * @return If the function succeeds, it returns ZMVideoSDKErrors_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setVideoQualityPreference:(ZoomSDKVideoPreferenceSetting*)preferenceSetting;
@end
NS_ASSUME_NONNULL_END
