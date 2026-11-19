//
//  ZMWizardEnvironmentDelegate.h
//  ZoomSetting
//
//  Created by javenlee on 2026/5/7.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMWizardMediaBackendType)
{
    ZMWizardMediaBackendTypeCmm = 0,
    ZMWizardMediaBackendTypePS,
};

@protocol ZMWizardEnvironmentDelegate <NSObject>

#pragma mark - Video State
- (BOOL)isCameraConnected;
- (BOOL)isMyVideoTurnOn;
- (void)unmuteMyVideo;

#pragma mark - Window Positioning
- (NSPoint)wizardWindowPositionForWindow:(NSWindow *)window;

#pragma mark - Settings Interaction
- (void)closeRelatedSettings;

#pragma mark - Audio Feature Management
- (void)addAudioTestFeatures;
- (void)releaseAudioTestFeatures;

#pragma mark - Toolbar Update
- (void)updateOriginalSoundButton;
- (void)updateToolbarAudioButton;
- (void)updateToolbarVideoButton;

#pragma mark - Conference State
- (BOOL)isConfReady;
- (BOOL)isE2EEncMeeting;
- (BOOL)isSupportTelephony;
- (BOOL)isWebinar;

#pragma mark - Alert
- (void)showDeviceAuthorizedAlertForMediaType:(AVMediaType)mediaType;

#pragma mark - FitMgr Update
- (void)updateFitAudio;
- (void)updateFitVideo;

#pragma mark - Audio UI Navigation
- (void)showAudioInfoWindowWithAvailablePhone;

#pragma mark - Event Reporting
- (void)onDeviceSettingChanged;

#pragma mark - System Device Name
#ifdef __cplusplus
- (NSString *)getSystemDeviceName:(unsigned int)type;
#endif

#pragma mark - Video State Change (from ForceUpdate strategy)
- (void)onMyVideoStateDidChanged;

@optional
- (ZMWizardMediaBackendType)preferredWizardMediaBackendType;

@end

NS_ASSUME_NONNULL_END
