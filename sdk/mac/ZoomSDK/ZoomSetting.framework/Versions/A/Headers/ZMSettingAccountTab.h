//
//  ZMSettingAccountTab.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2026/3/31.
//

#import <ZoomSetting/ZMSettingBaseTab.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingAccountTab : ZMSettingBaseTab

+ (BOOL)isVideoSmartRecognitionEnable;
+ (BOOL)isRegistedVideoSmartRecognition;
+ (BOOL)isAudioSmartRecognitionEnable;
+ (BOOL)isRegistedAudioSmartRecognition;
+ (BOOL)isSmartRecognitionEnable;
+ (BOOL)isAgreedAudioRecognitionDisclaimer;
+ (BOOL)canVoicePrint;

+ (BOOL)isZRSNTEnrollmentForVoiceEnabled;
+ (BOOL)isZRSNTForVoiceEnabled;
+ (BOOL)isWorkplaceSNTEnrollmentForVoiceEnabled;

+ (BOOL)isWorkplaceSNTForVoiceEnabled;
+ (BOOL)isZRSNTEnrollmentForVideoEnabled;
+ (BOOL)isZRSNTForVideoEnabled;

+ (BOOL)showVoiceBanner;
+ (BOOL)showVideoBaner;
+ (void)refreshNewDeviceList;
+ (BOOL)isVideoSmartRecognitionImageIdeal;
+ (BOOL)isAvaliableVersionForNewBadge;

@end

NS_ASSUME_NONNULL_END
