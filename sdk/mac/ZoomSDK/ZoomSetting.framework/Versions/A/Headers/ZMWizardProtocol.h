//
//  ZMWizardProtocol.h
//  ZoomSetting
//
//  Created by javenlee on 2026/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMWizardProtocol <NSObject>

@property (nonatomic, readonly) BOOL isVisible;
@property (nonatomic, readonly) BOOL isInTesting;
@property (nonatomic, readonly) BOOL isTestingMic;
@property (nonatomic, readonly) BOOL isTestingSpeaker;

- (void)startWizard:(BOOL)isFromTestMeeting;
- (void)startAudioWizard;
- (void)stopWizard;

- (void)changeSpeakerByDeviceID:(NSString *)deviceID deviceName:(NSString *)deviceName;
- (void)changeMicByDeviceID:(NSString *)deviceID deviceName:(NSString *)deviceName;
- (void)cameraChangedWithResult:(int)result;

@end

NS_ASSUME_NONNULL_END
