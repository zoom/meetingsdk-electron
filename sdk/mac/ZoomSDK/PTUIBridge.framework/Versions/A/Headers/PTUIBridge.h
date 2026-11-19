//
//  PTUIBridge.h
//  PTUIBridge
//
//  Created by Molay.Yu on 2024/6/26.
//

#import <Foundation/Foundation.h>
//! Project version number for PTUIBridge.
FOUNDATION_EXPORT double PTUIBridgeVersionNumber;

//! Project version string for PTUIBridge.
FOUNDATION_EXPORT const unsigned char PTUIBridgeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PTUIBridge/PublicHeader.h>

#import <PTUIBridge/ZMPTTheme.h>
#import <PTUIBridge/ZMTabItem.h>
#import <PTUIBridge/ZMTabWidgets.h>
#import <PTUIBridge/ZMPTUIHelper.h>

#ifdef __OBJC__

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/ZMPTUIEventCenterProtocol.h>
#import <PTUIBridge/ZPMainWindowEventProtocol.h>
#import <PTUIBridge/ZPMainWindowProtocol.h>
#import <PTUIBridge/ZMSidebarLeftTabProtcol.h>
#import <PTUIBridge/IZMPTSidePanelMgr.h>
#import <PTUIBridge/IZMPTUIMgr.h>
#import <PTUIBridge/IZPMainMenuMgr.h>
#import <PTUIBridge/IZMPTBannerMgr.h>
#import <PTUIBridge/ZMRingtoneHelper.h>
#import <PTUIBridge/IZMPTMeetingUpdate.h>
#import <PTUIBridge/IZMSupportMgr.h>
#import <PTUIBridge/IZMMeetingListHelper.h>
#import <PTUIBridge/IZMPTAsistantMgr.h>
#import <PTUIBridge/IZMSmartRecognitionMgr.h>
#import <PTUIBridge/IZMUpcomingMeetingHelper.h>
//UI Components
#import <PTUIBridge/ZMWaitingProgressButton.h>
#import <PTUIBridge/ZMMeetingListWarningView.h>
#import <PTUIBridge/IZPAlertMgr.h>

//transfer meeting
#import <PTUIBridge/IZMPTTransferMeetingMgr.h>
#import <PTUIBridge/ZPTransferDeviceInfo.h>
#import <PTUIBridge/IZMPTTransferMeetingItem.h>
#import <PTUIBridge/ZMSelectionTableRowView.h>
#import <PTUIBridge/ZMTransferMeetingCellView.h>
//update
#import <PTUIBridge/IZMCheckUpdateMgr.h>
#import <PTUIBridge/ZMUpdateConstants.h>
#import <PTUIBridge/IZMPTFeedbackMgr.h>

//Upgeade
#import <PTUIBridge/IZMUpgradeMgr.h>

//nav tabs
#import <PTUIBridge/ZMTabDefineHeader.h>
#import <PTUIBridge/IZMMainTabsData.h>
#import <PTUIBridge/IZMMainTabsLifeCycle.h>
#import <PTUIBridge/IZMMainTabsMgr.h>
#import <PTUIBridge/IZMPTShareWindowMgr.h>
#import <PTUIBridge/IZMMiniTabsMgr.h>
#import <PTUIBridge/ZMPTTabNavigationProtocol.h>
#import <PTUIBridge/ZMTabsRegisterCenter.h>
#import <PTUIBridge/ZMHTabViewDelegate.h>
#import <PTUIBridge/ZMViewMgr.h>
#import <PTUIBridge/ZMPopOutWindowMgr.h>
#import <PTUIBridge/ZMHTabView.h>
#import <PTUIBridge/ZMTabPermission.h>
//meeting
#import <PTUIBridge/ZPInvitationItemProtocol.h>
#import <PTUIBridge/IZMPTMeetingHelper.h>
#import <PTUIBridge/IZPCMDWindowManager.h>
#import <PTUIBridge/IZMPTMeetingMgr.h>
#import <PTUIBridge/ZMPTConfHelper.h>

//audio
#import <PTUIBridge/IZPPTMediaHelper.h>
#import <PTUIBridge/IZMAudioHelper.h>
#import <PTUIBridge/ZMAppleHeadsetSyncBridge.h>

// Clips
#import <PTUIBridge/IZMPTClipsHelperAdapter.h>
#import <PTUIBridge/IZMClipsTab.h>
#import <ZoomUnit/ZMClipsProtocol.h>
#import <PTUIBridge/ZMClipsWebViewProtocol.h>

//Session&helper
#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wignored-attributes"
#import <PTUIBridge/ZMPTHelper.h>
#import <PTUIBridge/IZMCCIHelper.h>
#import <PTUIBridge/IZMHybridSDKHelper.h>
#pragma clang diagnostic pop
#endif

//Mail
#import <PTUIBridge/IZMMailHelper.h>

//PhoneCall
#import <PTUIBridge/IZMReceiveCallProtocol.h>

//Assistant
#import <PTUIBridge/ZMCCICallStatusProtocol.h>

#endif
