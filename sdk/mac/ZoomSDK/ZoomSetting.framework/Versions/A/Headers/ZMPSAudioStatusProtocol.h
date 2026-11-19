//
//  ZMPSAudioStatusProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/15.
//

#ifndef ZMPSAudioStatusProtocol_h
#define ZMPSAudioStatusProtocol_h

#import <ZoomSetting/ZMPSObject.h>

typedef NS_ENUM(NSUInteger, ZMPSMCDeviceSpecialInfoType) {
    ZMPSMCDeviceSpecialInfoTypeNoInput,
    ZMPSMCDeviceSpecialInfoTypeMusicDetected,
    ZMPSMCDeviceSpecialInfoTypeMuteReminder,
};

@class ZMPSDevice;
@class ZMMicrophoneUsageInfo;
@protocol ZMPSAudioStatusProtocol <NSObject>

@optional
- (void)psAudioDeviceSpecialInfoChange:(ZMPSMCDeviceSpecialInfoType)type;
- (void)psPoorQualityAlert;
- (void)psMicAudioLevelChanged:(NSUInteger)level;
- (void)psSpeakerAudioLevelChanged:(NSUInteger)level;
- (void)psMicRecordVoiceDetection:(BOOL)hasVoice;
- (void)psPlayRecordSeriallyStopped:(ZMPSScene)scene;
- (void)psPlayFileSeriallyStopped:(ZMPSScene)scene filePath:(NSString *)filePath;
- (void)psPlayFileSeriallyStopped:(ZMPSScene)scene soundType:(NSInteger)soundType;
- (void)psPlayRingToneSeriallyStopped:(ZMPSScene)scene filePath:(NSString *)filePath;
- (void)psPlayMp3SeriallyStopped:(ZMPSScene)scene filePath:(NSString *)filePath;
- (void)psMicDeviceChanged;
- (void)psSpeakerDeviceChanged;
- (void)psMicDeviceRemovedForCurrentDevice:(BOOL)isCurrentDevice;
- (void)psMicDeviceAdded:(ZMPSDevice *)device;
- (void)psMicMutedChanged;
- (void)psStereoMicRecordingChanged;
- (void)psOriginalSoundChanged;
- (void)psMicrophoneModesChanged;
- (void)psUseMicDeviceAppsChange:(ZMMicrophoneUsageInfo*)usageInfo;

// Migrated from IZMDeviceProtocol: audio device access changes.
- (void)psMicAccessChanged:(BOOL)hasAccess;
- (void)psSpkAccessChanged:(BOOL)hasAccess;

// Migrated from IZMDeviceProtocol: manual speaker embedding status update.
- (void)psManualSpkEmbStatusChanged:(BOOL)success;

- (void)psSpkEmbInfoChanged:(BOOL)manual exist:(BOOL)exist;

// Migrated from IZMDeviceProtocol: smart recognition / workplace SNT setting changes.
- (void)psSmartRecognitionSettingChanged;
- (void)psWorkplaceSNTSettingChanged;

// Migrated from IZMDeviceProtocol (CMD_AUDIO_PROFILE_SETTING_CHANGED):
// personalized audio isolation enable state changed.
- (void)psPersonalizedAudioIsolationEnableChanged;
@end

#endif /* ZMPSAudioStatusProtocol_h */
