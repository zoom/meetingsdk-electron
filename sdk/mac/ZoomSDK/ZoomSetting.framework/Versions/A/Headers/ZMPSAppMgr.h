//
//  ZMPSAppMgr.h
//  ZoomClips
//
//  Created by Michael Lin on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>

#ifdef __cplusplus
#import <zPSApp/app/IPSApp.h>
#import <zPSApp/media/IPSMediaAgent.h>
#import <zPSApp/media/IPSAudio.h>
#import <zPSApp/media/IPSRender.h>
#import <zPSApp/media/IPSShare.h>
#import <zPSApp/media/IPSVideo.h>
#include "webService/SBWebServiceInterface.h"
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMSmartRecognitionPopupType) {
    ZMSmartRecognitionPopupTypeVideo = 0,
    ZMSmartRecognitionPopupTypeVoice = 1,
};

@class ZMPSCanvasMgr, ZMPSContextMgr, ZMPSMediaClient, ZMPSAvatarMgr;
@class ZMPSVirtualBackgroundMgr, ZMPSVideoMgr, ZMPSAudioMgr;
@class ZMPSWallpaperMgr, ZMPSShareMgr, ZMPSRenderMgr;
@class ZMPSWebAgentAPIMgr, ZMPSAnnotationMgr;
@interface ZMPSAppMgr : ZMPSObject

- (void)setupPSApp;
- (void)uninitPSApp;

@property (nonatomic, strong) ZMPSCanvasMgr *canvasMgr;
@property (nonatomic, strong) ZMPSRenderMgr *renderMgr;
@property (nonatomic, strong) ZMPSContextMgr *contextMgr;
@property (nonatomic, strong) ZMPSMediaClient *mediaClient;
@property (nonatomic, strong) ZMPSAvatarMgr *avatarMgr;
@property (nonatomic, strong) ZMPSVirtualBackgroundMgr *virtualBackgroundMgr;
@property (nonatomic, strong) ZMPSVideoMgr *videoMgr;
@property (nonatomic, strong) ZMPSAudioMgr *audioMgr;
@property (nonatomic, strong) ZMPSShareMgr *shareMgr;
@property (nonatomic, strong) ZMPSWebAgentAPIMgr *webAgentAPIMgr;
@property (nonatomic, strong) ZMPSWallpaperMgr *wallpaperMgr;
@property (nonatomic, strong) ZMPSAnnotationMgr *annotationMgr;

#ifdef __cplusplus
- (nullable ps::IPSMediaAgent *)mediaAgent;
- (nullable ps::IPSAudioAgent *)ipsAudioAgent;
- (nullable ps::IPSAudioDeviceMgr *)ipsAudioDeviceMgr;
- (nullable ps::IPSVideoAgent *)ipsVideoAgent;
- (nullable ps::IPSVideoConfig *)ipsVideoConfig;
- (nullable ps::IPSVideo3dAvatarConfig *)ipsVideo3dAvatarConfig;
- (nullable ps::IPSVideoBkgndConfig *)ipsVideoBkgndConfig;
- (nullable ps::IPSVideoFilterConfig *)ipsVideoFilterConfig;
- (nullable ps::IPSVideoStudioEffectConfig *)ipsVideoStudioEffectConfig;
- (nullable ps::IPSVideoPhotorealisticAvatarConfig *)ipsVideoPhotorealisticAvatarConfig;
- (nullable ps::IPSShareAgent *)ipsShareAgent;


- (nullable ps::IPSRenderMgr *)ipsRenderMgr;
- (nullable ps::IPSCanvasMgr *)ipsCanvasMgr;
- (nullable ps::IPSWebAgentAPI *)ipsWebAgentAPI;
- (nullable ps::IPSMediaClient *)ipsMediaClient;
- (nullable ps::IPSContext *)ipsContext;
- (nullable ps::IPSSmartRecognitionAgent *)ipsSmartRecognitionAgent;
- (nullable SB_webservice::ISBWebServiceAPI *)fetchWebServiceAPI;
#endif

- (void)setNeedSmartRecognitionPopup:(ZMSmartRecognitionPopupType)type popup:(BOOL)popup;
- (BOOL)requestReuseSntImage;
- (void)requestReuseSntRecording;
- (void)requestReuseSmartRecording;

@end

NS_ASSUME_NONNULL_END
