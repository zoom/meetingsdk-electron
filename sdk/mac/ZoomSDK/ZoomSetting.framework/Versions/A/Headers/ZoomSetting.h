//
//  ZoomSetting.h
//  ZoomSetting
//
//  Created by Javenlee Li on 2023/7/31.
//

#import <Foundation/Foundation.h>

//! Project version number for ZoomSetting.
FOUNDATION_EXPORT double ZoomSettingVersionNumber;

//! Project version string for ZoomSetting.
FOUNDATION_EXPORT const unsigned char ZoomSettingVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ZoomSetting/PublicHeader.h>

//protocol
#import <ZoomSetting/ZMAudioSettingProtocol.h>
#import <ZoomSetting/ZMVideoSettingProtocol.h>
#import <ZoomSetting/ZMSettingAudioShareMgr.h>
#import <ZoomSetting/ZMNetUtilsHelper.h>
#import <ZoomSetting/ZMClipsConfig.h>
#import <ZoomSetting/ZMPSWallpaperItem.h>
#import <ZoomSetting/ZMPSWallpaperMgr.h>
#import <ZoomSetting/ZMPSMgr.h>
#import <ZoomSetting/ZMPSAppMgr.h>
#import <ZoomSetting/ZMPSVirtualBackgroundStatusProtocol.h>
#import <ZoomSetting/ZMPSVirtualBackgroundMgr.h>
#import <ZoomSetting/ZMPSVirtualBackgroundItem.h>
#import <ZoomSetting/ZMPSContextMgr.h>
#import <ZoomSetting/ZMPSMediaClient.h>
#import <ZoomSetting/ZMPSAvatarStatusProtocol.h>
#import <ZoomSetting/ZMPSAvatarMgr.h>
#import <ZoomSetting/ZMPSAudioStatusProtocol.h>
#import <ZoomSetting/ZMPSAudioMgr.h>
#import <ZoomSetting/ZMPSVideoStatusProtocol.h>
#import <ZoomSetting/ZMPSVideoMgr.h>
#import <ZoomSetting/ZMPSRecordLayoutModel.h>
#import <ZoomSetting/ZMPSWallpaperStatusProtocol.h>
#import <ZoomSetting/ZMPSWallpaperMgr.h>
#import <ZoomSetting/ZMPSWallpaperItem.h>
#import <ZoomSetting/ZMPSShareMgr.h>
#import <ZoomSetting/ZMPSRenderMgr.h>
#import <ZoomSetting/ZMPSRenderStatusProtocol.h>
#import <ZoomSetting/ZMPSObject.h>
#import <ZoomSetting/ZMPSCanvas.h>
#import <ZoomSetting/ZMPSRender.h>
#import <ZoomSetting/ZMPSSceneContext.h>
#import <ZoomSetting/ZMPSUploadResult.h>
#import <ZoomSetting/ZMPSWebAgentAPIMgr.h>
#import <ZoomSetting/ZMPSAnnotationMgr.h>
#import <ZoomSetting/ZMPSDevice.h>
#import <ZoomSetting/ZMPSAudioDevice.h>
#import <ZoomSetting/ZMPSVideoDevice.h>
#import <ZoomSetting/ZMPSUIUtil.h>
#import <ZoomSetting/ZMPSAvatarItem.h>
#import <ZoomSetting/ZMPSActionToken.h>
#import <ZoomUnit/ZMOndemandProtocol.h>
#import <ZoomSetting/ZMDownloadMgr.h>
#import <ZoomSetting/ZMDownloadPanelMgr.h>
#import <ZoomSetting/ZMSettingSideBarRowView.h>
#import <ZoomSetting/NSView+ZMSettingRouter.h>
#import <ZoomSetting/NSMutableArray+ZPResponderButtons.h>
#import <ZoomSetting/ZMVideoEventProtocol.h>
#import <ZoomSetting/ZMSettingHelper.h>
#import <ZoomSetting/ZMFontManager.h>
#import <ZoomSetting/ZMSettingItemViewController.h>
#import <ZoomSetting/ZMSettingBaseTab.h>
#import <ZoomSetting/ZMSettingAccountViewController.h>
#import <ZoomSetting/ZMSettingAccountTab.h>
#import <ZoomSetting/ZMSettingVirtualViewController.h>
#import <ZoomSetting/ZMTableScrollView.h>
#import <ZoomSetting/ZMNetworkDiagnosticAdapter.h>
#import <ZoomSetting/ZMNetworkDiagnosticViewController.h>
#import <ZoomSetting/ZMSettingConstants.h>
#import <ZoomSetting/IZMSettingMgr.h>
#import <ZoomSetting/ZMSettingMgr.h>
#import <ZoomSetting/IZMSettingProtocols.h>
#import <ZoomSetting/IZMZUISettingMgr.h>
#import <ZoomSetting/ZMMTTheme.h>

#pragma mark - Wizard
#import <ZoomSetting/ZMWizardProtocol.h>
#import <ZoomSetting/ZMWizardEnvironmentDelegate.h>
#import <ZoomSetting/ZMWizardController.h>

#pragma mark - Protocol
#import <ZoomSetting/ZMSTUserStatusProtocol.h>
#ifdef __cplusplus
#import <ZoomSetting/ZMSTPolicyUpdateProtocol.h>
#endif
