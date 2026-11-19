//
//  ZMPSAudioMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSAudioDevice;

typedef NS_ENUM(NSUInteger, ZMBGNoiseSuppress) {
    ZMBGNoiseSuppressAuto,
    ZMBGNoiseSuppressLow,
    ZMBGNoiseSuppressMedium,
    ZMBGNoiseSuppressHigh,
};

typedef NS_ENUM(NSUInteger, ZMNoiseSuppressMode) {
    ZMNoiseSuppressModeBackGroundNoise,
    ZMNoiseSuppressModeOriginalSound,
    ZMNoiseSuppressModePlaceholder,
    ZMNoiseSuppressModePersonalVoice,
};

@interface ZMPSAudioMgr : ZMPSObject

@property (nonatomic, weak) ZMPSAudioDevice *microphoneDevice;
- (NSArray<ZMPSAudioDevice *> *)microphoneDevices;
- (BOOL)isDefaultMicDeviceNotExisted;
- (void)micDeviceAddedWithDeviceID:(nullable NSString *)deviceID;
- (void)micDeviceRemovedWithDeviceID:(nullable NSString *)deviceID isActive:(BOOL)isActive;
- (void)startRecord;
- (void)stopRecord;
- (void)startPlayFileSerially;
- (void)stopPlayFileSerially;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)isConfigReady;
@property (nonatomic, assign) ZMNoiseSuppressMode noiseSuppressMode;
@property (nonatomic, assign) BOOL enableAGCMode;
@property (nonatomic, assign) BOOL enableHighFideMusicMode;
@property (nonatomic, assign) BOOL enableEchoCancellation;
@property (nonatomic, assign) BOOL enableStereo;
@property (nonatomic, assign, readonly) BOOL isAudioDeviceInstalled;
@property (nonatomic, assign) ZMBGNoiseSuppress bgNoiseSuppress;

- (BOOL)isFTUPersonalizedVoiceIsolation;
- (BOOL)isVoicePrintDataExistForManual:(BOOL)isManual;
- (BOOL)deletePersonlizeAudioSignatureManual:(BOOL)manual withoutRequest:(BOOL)withoutRequest;
+ (void)notifyDeletePersonalizedAudioSignatureToPhoneAndCCI:(BOOL)manual;

- (BOOL)startRecordMicDummy;
- (BOOL)recordVoicePrint;
- (BOOL)stopRecordMic;
- (BOOL)stopRecordVoicePrint;
- (BOOL)playVoicePrint;

#pragma mark - Working Device Query
- (nullable NSString *)workingMicName;
- (nullable NSString *)workingMicID;
- (nullable NSString *)workingSpkName;
- (nullable NSString *)workingSpkID;
- (BOOL)getMicInfoForZzHostID:(NSString *_Nullable *_Nullable)outID name:(NSString *_Nullable *_Nullable)outName;
- (BOOL)hasMicDeviceAvailable;
- (nullable NSString *)sysDefMicName;
- (nullable NSString *)sysDefSpkName;

- (BOOL)isStereoMicRecordingEnabled;
- (void)setStereoMicRecording:(BOOL)enable;
- (BOOL)isStereoMicRecordingMandatory;
- (void)startMicForIdle;
- (void)stopMicForIdle;
- (void)startSpkForIdle;
- (void)stopSpkForIdle;
- (void)notifyShareAudioDriverInstalled;

#pragma mark - System Audio Capture
- (BOOL)isSupportLoopbackSystemAudio;
#ifdef __cplusplus
- (SSB_MC_PERMISSION_STATUS)getSystemAudioPermissionStatus;
- (SSB_MC_PERMISSION_STATUS)getMicrophonePermissionStatus;
#endif
- (void)requestSystemAudioPermission;
- (void)requestMicrophonePermission;

- (BOOL)configureSystemAudioCapture:(BOOL)enabled;
//- (BOOL)enableSystemAudioCapture:(BOOL)enabled;
- (void)startComputerAudioShare;
- (void)stopComputerAudioShare;

- (void)startVoiceDurationTracking;
- (UInt32)stopVoiceDurationTracking;
- (UInt32)queryVoiceDuration;

@end

NS_ASSUME_NONNULL_END
