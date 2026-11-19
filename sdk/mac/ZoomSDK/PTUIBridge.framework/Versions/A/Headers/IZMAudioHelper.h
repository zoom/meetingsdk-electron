//
//  IZMAudioHelper.h
//  PTUIBridge
//
//  Created by fistice on 7/9/25.
//

#ifndef IZMAudioHelper_h
#define IZMAudioHelper_h

#ifdef __cplusplus
#import <zVideoApp/Confdef.h>
#endif

@protocol IZMAudioHelper <NSObject>

- (void)startSyncAudioExternalDevice;

- (void)cleanUp;
- (void)cleanUpAudioDeviceWithoutSetting;

- (void)onDeviceRestart;

// util
- (NSString*)getSelectedMicrophoneName;
- (NSString*)getSelectedMicrophoneDeviceID;
- (NSString*)getSelectedSpeakerName;
- (NSString*)getSelectedSpeakerDeviceID;
- (BOOL)hasMicDeviceAvailable;

- (BOOL)getMicInfoForZzHost:(NSString**)outName deviceId:(NSString**)outId;

- (NSString*)getCCIRingtonePath;
#ifdef __cplusplus
- (NSString *)getSystemDeviceName:(SSB_MC_DEVICE_TYPE)type;
- (void)addAudioFeature:(Feature)feature;
- (void)releaseAudioFeature:(Feature)feature;

- (void)cleanUpAudioDevice;
#endif

@end
#endif /* IZMAudioHelper_h */
// ZMSharedFor(IZMAudioHelper)
