

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @protocol ZoomSDKSettingTestAudioDelegate
 * @brief Delegate to receive audio testing related events.
 */
@protocol ZoomSDKSettingTestAudioDelegate <NSObject>
@optional
/**
 * @brief Notification of microphone level changes when testing.
 * @param level The level of microphone.
 */
- (void)onMicLevelChanged:(unsigned int)level;
/**
 * @brief Notification of speaker level changes when testing.
 * @param level The speaker level.
 */
- (void)onSpeakerLevelChanged:(unsigned int)level;
/**
 * @brief Notify the microphone test status has changed.
 * @param status Test status of microphone.
 */
- (void)onMicTestStatusChanged:(ZoomSDKTestMicStatus)status;
/**
 * @brief Notification of speaker status changes when testing.
 * @param isTesting YES if the speaker test is in progress, NO otherwise.
 */
- (void)onSpeakerTestStatusChanged:(BOOL)isTesting;
@end

/**
 * @protocol ZoomSDKSettingAudioDeviceDelegate
 * @brief Delegate to receive audio device related events.
 */
@protocol ZoomSDKSettingAudioDeviceDelegate <NSObject>
@optional
/**
 * @brief Notify the microphone device status has changed in the meeting.
 * @param status The microphone device status.
 */
- (void)onMicDeviceStatusChanged:(ZoomSDKDeviceStatus)status;
/**
 * @brief Notify the speaker device status has changed in the meeting.
 * @param status The speaker device status.
 */
- (void)onSpeakerDeviceStatusChanged:(ZoomSDKDeviceStatus)status;
/**
 * @brief Notification that the selected microphone device is changed.
 */
- (void)onSelectedMicDeviceChanged;
/**
 * @brief Notification that the selected speaker device is changed.
 */
- (void)onSelectedSpeakerDeviceChanged;
@end


/**
 * @class ZoomSDKSettingTestSpeakerDeviceHelper
 * @brief Helper class to test speaker devices.
 */
@interface ZoomSDKSettingTestSpeakerDeviceHelper: NSObject
{
    id<ZoomSDKSettingTestAudioDelegate>     _delegate;
    BOOL                                    _isSpeakerInTesting;
    NSString*                               _speakerID;
}
/**
 * @brief Indicates whether speaker testing is in progress.
 */
@property (nonatomic, readwrite, assign)BOOL                    isSpeakerInTesting;

/**
 * @brief Delegate to receive audio testing events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingTestAudioDelegate> delegate;

/**
 * @brief Starts playing when testing speaker.
 * @param deviceID The speaker's device ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)SpeakerStartPlaying:(NSString*)deviceID;
/**
 * @brief Stops playing when testing speaker.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)SpeakerStopPlaying;
@end

/**
 * @class ZoomSDKSettingTestMicrophoneDeviceHelper
 * @brief Helper class for testing microphone devices.
 */
@interface ZoomSDKSettingTestMicrophoneDeviceHelper: NSObject
{
    id<ZoomSDKSettingTestAudioDelegate>         _delegate;
    ZoomSDKTestMicStatus         _testMicStatus;
    NSString*                    _microphoneID;
}
/**
 * @brief Delegate to receive audio testing events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingTestAudioDelegate> delegate;
/**
 * @brief Starts recording when testing microphone.
 * @param deviceID The microphone's device ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startRecordingMic:(NSString*)deviceID;
/**
 * @brief Stops recording when testing microphone.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopRecrodingMic;
/**
 * @brief Plays recorded sounds when testing microphone.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)playRecordedMic;
/**
 * @brief Stops playing recorded sounds when testing microphone.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopPlayRecordedMic;
/**
 * @brief Gets the status when testing microphone.
 * @return If the function succeeds, it returns test mic status \link ZoomSDKTestMicStatus \endlink.
 */
- (ZoomSDKTestMicStatus)getTestMicStatus;
@end


/**
 * @class ZoomSDKAudioSetting
 * @brief Provides APIs to manage audio devices, audio volumes, and audio-related meeting features.
 */
@interface ZoomSDKAudioSetting: NSObject
{
    ZoomSDKSettingTestSpeakerDeviceHelper* _speakerTestHelper;
    ZoomSDKSettingTestMicrophoneDeviceHelper* _micTestHelper;
    id<ZoomSDKSettingAudioDeviceDelegate>       _delegate;
}
/**
 * @brief Delegate to receive audio device status changes.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKSettingAudioDeviceDelegate> delegate;
/**
 * @brief Gets the object of ZoomSDKSettingTestSpeakerDeviceHelper.
 * @return If the function succeeds, it returns a ZoomSDKSettingTestSpeakerDeviceHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestSpeakerDeviceHelper*_Nullable)getSettingSpeakerTestHelper;
/**
 * @brief Gets the object of ZoomSDKSettingTestMicrophoneDeviceHelper.
 * @return If the function succeeds, it returns a ZoomSDKSettingTestMicrophoneDeviceHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSettingTestMicrophoneDeviceHelper*_Nullable)getSettingMicrophoneTestHelper;
/**
 * @brief Gets the list of audio device.
 * @param mic YES if microphone device, NO if speaker device.
 * @return If the function succeeds, it returns an array containing \link SDKDeviceInfo \endlink elements. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAudioDeviceList:(BOOL)mic;

/**
 * @brief Gets the volume of audio device.
 * @param mic YES if the volume of microphone device, NO if speaker device.
 * @return If the function succeeds, it returns an int value(0-100). Otherwise, this function fails and returns 0.
 */
- (float)getAudioDeviceVolume:(BOOL)mic;

/**
 * @brief Sets the volume of audio device.
 * @param mic YES if the volume of microphone device, NO if speaker device.
 * @param volume The volume of device, varies from 0 to 100.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setAudioDeviceVolume:(BOOL)mic Volume:(float)volume;

/**
 * @brief Select an audio device.
 * @param mic YES if microphone device, NO if speaker device.
 * @param deviceID The device's ID.
 * @param deviceName The device's name.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)selectAudioDevice:(BOOL)mic DeviceID:(NSString *)deviceID DeviceName:(NSString*)deviceName;

/**
 * @brief Sets to enable stereo in the meeting.
 * @param enable YES to enable stereo, NO to disable.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableStero:(BOOL)enable;

/**
 * @brief Enables to join meeting with the audio of computer.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableAutoJoinVoip:(BOOL)enable;

/**
 * @brief Mute user's microphone when he joins the meeting with the audio of computer.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableMuteMicJoinVoip:(BOOL)enable;
/**
 * @brief Enables the feature that attendee can speak by pressing the Spacebar when he is muted.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enablePushToTalk:(BOOL)enable;

/**
 * @brief Sets whether to disable the prompt dialog of joining meeting with third party audio.
 * @param disable YES if disabled, NO enabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)disablePromptJoinAudioDialogWhenUse3rdPartyAudio:(BOOL)disable;

/**
 * @brief Determines if the meeting supports to pop up the dialog when user joins meeting with third party audio.
 * @return YES if supported. Otherwise, NO.
 */
- (BOOL)isSupportPromptJoinAudioDialogWhenUse3rdPartyAudio;

/**
 * @brief Determines if the dialog pops up when user joins meeting with third party audio.
 * @return YES if the dialog will not pop up. Otherwise, NO.
 */
- (BOOL)isPromptJoinAudioDialogWhenUse3rdPartyAudioDisable;

/**
 * @brief Enables auto-adjust microphone.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableAutoAdjustMic:(BOOL)enable;

/**
 * @brief Determines if auto-adjust microphone is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isAutoAdjustMicOn;
/**
 * @brief Determines if user joins meeting with audio on.
 * @return YES to enable the audio. Otherwise, NO.
 */
- (BOOL)isJoinAudioWhenJoinMeetingOn;
/**
 * @brief Determines if user joins meeting with microphone muted.
 * @return YES if muted. Otherwise, NO.
 */
- (BOOL)isMuteMicWhenJoinMeetingOn;

/**
 * @brief Determines if stereophonic sound is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEnableStereoOn;
/**
 * @brief Sets whether to enable the feature that attendee can speak by pressing the Spacebar when he is muted.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isTemporarilyUnmuteOn;


/**
 * @brief Enables show original sound option in meeting UI.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableShowOriginalSoundOptionInMeetingUI:(BOOL)enable;

/**
 * @brief Determines if show original sound option in meeting UI is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isShowOriginalSoundOptionInMeetingUIOn;

/**
 * @brief Determines if the meeting supports show original sound option in meeting UI.
 * @return YES if supported. Otherwise, NO.
 */
- (BOOL)isSupportShowOriginalSoundOptionInMeetingUI;

/**
 * @brief Sets echo cancellation level.
 * @param level The level to be set.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setEchoCancellationLevel:(ZoomSDKAudioEchoCancellationLevel)level;
/**
 * @brief Gets echo cancellation level.
 * @return The level of echo cancellation.
 */
- (ZoomSDKAudioEchoCancellationLevel)getEchoCancellationLevel;
/**
 * @brief Enables echo cancellation.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableEchoCancellation:(BOOL)enable;

/**
 * @brief Determines if echo cancellation is enabled or not.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isEchoCancellationOn;

/**
 * @brief Determines if the meeting supports echo cancellation.
 * @return YES if supported. Otherwise, NO.
 */
- (BOOL)isSupportEchoCancellation;

/**
 * @brief Gets the level of suppressed background noise.
 * @return The level of suppressed background noise.
 */
- (ZoomSDKSuppressBackgroundNoiseLevel)getSuppressBackgroundNoiseLevel;

/**
 * @brief Sets the level of to suppress background noise.
 * @param level The level to be set.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setSuppressBackgroundNoise:(ZoomSDKSuppressBackgroundNoiseLevel)level;

/**
 * @brief Determines if used separate audio device to play ringtone simultaneously.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isAlwaysUseSeparateRingSpkOn;

/**
 * @brief Enables use separate audio device to play ringtone simultaneously.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableAlwaysUseSeparateRingSpk:(BOOL)enable;

/**
 * @brief Gets use separate audio device to play ringtone simultaneously devices.
 * @return If the function succeeds, it returns an array containing SDKDeviceInfo elements. Otherwise, this function fails and returns nil.
 */
- (NSArray *_Nullable)getRingSpkDeviceList;

/**
 * @brief Gets the volume of audio device.
 * @return If the function succeeds, it returns an float value(0.0-255.0). Otherwise returns 0.0.
 */
- (float)getRingSpkVolume;

/**
 * @brief Sets the volume of audio device.
 * @param value The value of device, varies from 0.0 to 255.0.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setRingSpkVolume:(float)value;

/**
 * @brief Select an audio device.
 * @param deviceId The ID of device.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setRingSpkDevice:(NSString*)deviceId;

/**
 * @brief Sets enable sync buttons on headset.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setSyncHeadsetButtonStatus:(BOOL)enable;

/**
 * @brief Determines if sync buttons on headset option on or off.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isSyncHeadsetButtonStatus;

/**
 * @brief Sets the "Enable Original Sound" option is high fidelity music model.
 * @param enable YES if enabled, NO if disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setHighFideMusicMode:(BOOL)enable;

/**
 * @brief Determines if use high fidelity music model.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isHighFideMusicMode;

/**
 * @brief Select the same audio device as system.
 * @param mic YES if microphone device, NO if speaker device.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)selectSameAudioDeviceAsSystem:(BOOL)mic;
@end
NS_ASSUME_NONNULL_END
