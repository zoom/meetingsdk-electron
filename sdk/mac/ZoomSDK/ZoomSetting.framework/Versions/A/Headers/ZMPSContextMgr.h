//
//  ZMPSContextMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2023/1/11.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSContextMgr : ZMPSObject

@property (nonatomic, assign) BOOL notRemindRecordWithoutMic;

@property (nonatomic, assign, getter = isEnableRecordImmersive) BOOL enableRecordImmersive;

@property (nonatomic, assign) BOOL hasAIAvatarTipShown;
@property (nonatomic, assign) BOOL hasVideoEffectTipShown;
@property (nonatomic, assign) BOOL advancedSettingTipShown;
@property (nonatomic, assign, getter = isEnableShareComputerSound) BOOL enableShareComputerSound;
@property (nonatomic, assign, getter = isHighlightMouseClick) BOOL highlightMouseClick;
@property (nonatomic, assign, getter = isRemindPauseShareTipShown) BOOL remindPauseShareTipShown;
@property (nonatomic, assign, getter = isMicMuted) BOOL micMuted;
@property (nonatomic, assign, getter = isClipsUnlimitedUser) BOOL clipsUnlimitedUser;

- (nullable NSString *)userName;
- (nullable NSString *)accountID;
- (nullable NSString *)userID;
- (void)unregisterSink;
- (void)registerSink;
- (BOOL)is3DAvatarEnabled;
- (BOOL)isCustom3DAvatarEnabled;
- (BOOL)isAnimal3DAvatarEnabled;
- (BOOL)isVideoVirtualBkgndEnabled;

- (BOOL)isPersonalizedAudioIsolationEnabled;
- (BOOL)isFirstTimeUsePersonalVoiceIsolation;
- (void)setNotFirstTimeUsePersonalVoiceIsolation;
- (void)setFirstTimeUsePersonalVoiceIsolation:(BOOL)isFirst;

- (BOOL)isShowSmartRecognitionForVoiceEnabled;
- (BOOL)isUserAcceptedSmartRecognitionVoicePopup;

- (NSInteger)allowedUnmutePrivacyHostInfoCount;
- (BOOL)getAllowedUnmutePrivacyHostInfoAtIndex:(NSInteger)index
                                        hostID:(NSString *_Nullable *_Nullable)outHostID
                                      hostName:(NSString *_Nullable *_Nullable)outHostName;
- (BOOL)removeAllowedUnmutePrivacyHostInfo:(NSString *)hostID;
- (nullable NSString *)activeMeetingHostID;

@end

NS_ASSUME_NONNULL_END
