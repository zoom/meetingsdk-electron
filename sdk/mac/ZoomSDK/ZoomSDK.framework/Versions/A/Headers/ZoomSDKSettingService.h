/**
 * @file ZoomSDKSettingService.h
 * @brief Interface declarations for Zoom SDK setting services.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
#import <ZoomSDK/ZoomSDKSettingVideoEffectController.h>
#import <ZoomSDK/ZoomSDKSettingGeneralController.h>
#import <ZoomSDK/ZoomSDKSettingVideoController.h>
#import <ZoomSDK/ZoomSDKSettingAudioController.h>
#import <ZoomSDK/ZoomSDKSettingRecordController.h>
#import <ZoomSDK/ZoomSDKSettingShareScreenController.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKAudioStatisticInfo
 * @brief The meeting audio statistic information.
 */
@interface ZoomSDKAudioStatisticInfo : NSObject
/**
 * @brief The send audio frequency in kilohertz (KHz) in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendFrequency;
/**
 * @brief The send audio rtt in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendRTT;
/**
 * @brief The send audio jitter in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/**
 * @brief The average of send audio packet loss in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/**
 * @brief The maximum send audio packet loss in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;
/**
 * @brief The send band width of audio in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendBandwidth;
/**
 * @brief The receive audio frequency in kilohertz (KHz) in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvFrequency;
/**
 * @brief  The receive audio rtt in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvRTT;
/**
 * @brief TThe receive audio jitter in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/**
 * @brief The average of receive audio packet loss in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/**
 * @brief The maximum receive audio packet loss in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
/**
 * @brief The receive band width of audio in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger    recvBandwidth;
@end

/**
 * @class ZoomSDKASVStatisticInfo
 * @brief The meeting video or share statistic information.
 */
@interface ZoomSDKASVStatisticInfo : NSObject
/**
 * @brief The send band width of video or share in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendBandwidth;
/**
 * @brief The send frame rate of video or share in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendFps;
/**
 * @brief The send video or share rtt data in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendRTT;
/**
 * @brief The send video or share jitter data in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  sendJitter;
/**
 * @brief The average video or share packet loss of send data in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossAvg;
/**
 * @brief The maximum video or share packet loss of send data in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    sendPacketLossMax;
/**
 * @brief The send resolution when transferring video or sharing data.
 */
@property(nonatomic, assign, readonly) NSInteger    sendResolution;
/**
 * @brief The receive band width of video or share in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvBandwidth;
/**
 * @brief The receive frame rate of video or share in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvFps;
/**
 * @brief The receive video or share rtt data in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvRTT;
/**
 * @brief The receive video or share jitter data in this meeting.
 */
@property(nonatomic, assign, readonly) NSInteger  recvJitter;
/**
 * @brief The average video or share packet loss of receive data in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossAvg;
/**
 * @brief The maximum video or share packet loss of receive data in this meeting.
 */
@property(nonatomic, assign, readonly) CGFloat    recvPacketLossMax;
/**
 * @brief The receive resolution when transferring video or sharing data.
 */
@property(nonatomic, assign, readonly) NSInteger    recvResolution;
@end

/**
 * @class SDKDeviceInfo
 * @brief Class representing information about a device (microphone, speaker, camera).
 */
@interface SDKDeviceInfo : NSObject
/**
 * @brief Gets the ID of device, such as microphone, speaker, camera.
 */
- (NSString*)getDeviceID;
/**
 * @brief Gets the device name.
 */
- (NSString*)getDeviceName;
/**
 * @brief Query if the device is selected.
 */
- (BOOL)isSelectedDevice;
@end

/**
 * @class ZoomSDKStatisticsSetting
 * @brief Interface for obtaining meeting statistics.
 */
@interface ZoomSDKStatisticsSetting: NSObject
/**
 * @brief Gets the connection type of current meeting.
 * @return An enumeration of connection type.
 */
- (SettingConnectionType)getSettingConnectionType;

/**
 * @brief Gets network type of current meeting.
 * @return An enumeration of network type.
 */
- (SettingNetworkType)getSettingNetworkType;
/**
 * @brief Gets the proxy address of current meeting.
 * @return Proxy address if the meeting uses a proxy. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getProxyAddress;

/**
 * @brief Gets meeting audio statistics information.
 * @return If the function succeeds, it returns an object of ZoomSDKAudioStatisticInfo. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAudioStatisticInfo*_Nullable)getAudioStatisticInfo;

/**
 * @brief Gets meeting video statistics information.
 * @return If the function succeeds, it returns an object of ZoomSDKASVStatisticInfo. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKASVStatisticInfo*_Nullable)getVideoStatisticInfo;

/**
 * @brief Gets meeting share statistics information.
 * @return If the function succeeds, it returns an object of ZoomSDKASVStatisticInfo. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKASVStatisticInfo*_Nullable)getShareStatisticInfo;
@end


/**
 * @class ZoomSDKSettingService
 * @brief Provides access to various Zoom SDK settings modules.
 */
@interface ZoomSDKSettingService : NSObject
{
    ZoomSDKAudioSetting* _audioSetting;
    ZoomSDKVideoSetting* _videoSetting;
    ZoomSDKRecordSetting* _recordSetting;
    ZoomSDKGeneralSetting* _generalSetting;
    ZoomSDKStatisticsSetting* _statisticsSetting;
    ZoomSDKVirtualBackgroundSetting* _virtualBGSetting;
    ZoomSDKShareScreenSetting* _shareScreenSetting;
    ZoomSDK3DAvatarSetting* _avatarSetting;
    ZoomSDKFaceMakeupSettingContext* _faceMakeupSettingContext;
}
/**
 * @brief Gets the object of audio settings.
 * @return If the function succeeds, it returns an object of ZoomSDKAudioSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAudioSetting*_Nullable)getAudioSetting;

/**
 * @brief Gets the object of video settings.
 * @return If the function succeeds, it returns an object of ZoomSDKVideoSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKVideoSetting*_Nullable)getVideoSetting;

/**
 * @brief Gets the object of meeting recording settings.
 * @return If the function succeeds, it returns an object of ZoomSDKRecordSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKRecordSetting*_Nullable)getRecordSetting;

/**
 * @brief Gets the object of general settings of SDK.
 * @return If the function succeeds, it returns an object of ZoomSDKGeneralSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKGeneralSetting*_Nullable)getGeneralSetting;

/**
 * @brief Gets the object of statistic settings.
 * @return If the function succeeds, it returns an object of ZoomSDKStatisticsSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKStatisticsSetting*_Nullable)getStatisticsSetting;

/**
 * @brief Gets the object of virtual background settings.
 * @return If the function succeeds, it returns an object of ZoomSDKVirtualBackgroundSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKVirtualBackgroundSetting*_Nullable)getVirtualBGSetting;

/**
 * @brief Gets the object of share screen settings.
 * @return If the function succeeds, it returns an object of ZoomSDKShareScreenSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKShareScreenSetting*_Nullable)getShareScreenSetting;

/**
 * @brief Gets the object of 3D avatar.
 * @return If the function succeeds, it returns an object of ZoomSDK3DAvatarSetting. Otherwise, this function fails and returns nil.
 */
- (ZoomSDK3DAvatarSetting*_Nullable)get3DAvatarSettings;

/**
 * @brief Gets the object of face makeup.
 * @return If the function succeeds, it returns an object of ZoomSDKFaceMakeupSettingContext. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKFaceMakeupSettingContext*_Nullable)getFaceMakeupSettings;
/**
 * @brief Custom the url link show or hide on setting page.
 * @param settingPageUrl It is a enumeration of setting page url.
 * @param hide YES to hide, NO to show.
 */
- (void)configToShowUrlLinksInSetting:(ZoomSDKSettingPageURL)settingPageUrl isHide:(BOOL)hide;
@end

NS_ASSUME_NONNULL_END
