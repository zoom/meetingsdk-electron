//
//  ZMPSVideoMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#ifdef __cplusplus
#import <zPSApp/media/IPSVideo.h>
#endif
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMPSVideoRotationAction) {
    ZMPSVideoRotationActionZero = 0,
    ZMPSVideoRotationActionClock90 = 1,
    ZMPSVideoRotationActionClock180 = 2,
    ZMPSVideoRotationActionAntiClock90 = 3,
};

@class ZMPSVideoDevice;
@class ZMPSRecordLayoutModel;

@interface ZMPSVideoMgr : ZMPSObject

@property (nonatomic, weak) ZMPSVideoDevice *defaultDevice;
@property (nonatomic, weak) ZMPSRecordLayoutModel *recordLayout;

#ifdef __cplusplus
- (ps::IPSVideoDeviceMgr *)videoDeviceMgr;
#endif

- (NSArray<ZMPSVideoDevice *> *)devices;
- (BOOL)isDefaultDeviceNotExisted;
- (void)deviceAddedWithDeviceID:(nullable NSString *)deviceID;
- (void)videoDeviceRunStartedWithDeviceID:(nullable NSString *)deviceID;
- (void)deviceRemovedWithDeviceID:(nullable NSString *)deviceID;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)isConfigReady;
- (void)enableMirrorMyVideo:(BOOL)enable;
- (BOOL)isMirrorMyVideoEnabled;
- (void)enableFaceBeauty:(BOOL)enable;
- (BOOL)isFaceBeautyEnabled;
- (void)setFaceBeautyStrengthValue:(NSInteger)value;
- (NSInteger)getFaceBeautyStrengthValue;
- (void)enableLightAdaption:(BOOL)enable;
- (BOOL)isLightAdaptionEnabled;
- (void)enableAutoLightAdaption:(BOOL)enable;
- (BOOL)isAutoLightAdaptionEnabled;
- (void)setLightAdaptionManualValue:(NSInteger)value;
- (NSInteger)getLightAdaptionManualValue;
- (void)enablePortraitLighting:(BOOL)enable;
- (BOOL)isPortraitLightingEnabled;
- (BOOL)isPortraitLightingMandatory;
- (BOOL)canSupportPortraitLighting;
- (BOOL)is3DAvatarEffectOpened;
- (void)enableAutoFraming:(BOOL)enable;

/// Effective height/width for UI: from `GetVideoCaptureSizeRatio`, adjusted when `GetDeviceRotationType` is 90°/270° (swap). Returns 0 if unknown.
- (CGFloat)videoCaptureHeightToWidthRatio;

/// Returns the rotation of the current default device for this manager's scene (default device id is still scene-scoped).
- (ZMPSVideoRotationAction)defaultVideoDeviceRotation;

/// Rotates the default device via `IPSVideoConfig::SetDeviceRotationType` (device-level rotation config).
- (BOOL)rotateDefaultVideoDevice:(ZMPSVideoRotationAction)action;

/// Rotates current default device by +90° clockwise relative to current rotation.
- (BOOL)rotateDefaultVideoDeviceClockwise90;

/// Applies current rotation config to current default running device immediately.
- (BOOL)applyRotationToDefaultVideoDevice;

/// Forces the current default running device to the given rotation immediately via `IPSVideoDeviceController::RotateDevice`, WITHOUT modifying the persisted rotation config in `IPSVideoConfig`.
- (BOOL)forceRotateDefaultVideoDeviceToAction:(ZMPSVideoRotationAction)action;

/// Pure helper for rotation-cycle logic: 0->90->180->270->0.
+ (ZMPSVideoRotationAction)nextRotationActionClockwiseFrom:(ZMPSVideoRotationAction)current;

@end

NS_ASSUME_NONNULL_END
