//
//  ZMPTHelper.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/12.
//

#ifndef IZMPTHelper_h
#define IZMPTHelper_h

#import <zPTApp/PTService/IPTAppWebService.h>
#import <zPTApp/PTService/IPTUrlActionService.h>
#import <zPTApp/PTService/IPTMarketService.h>
#import <zPTApp/PTService/IPTWhiteboardsService.h>
#import <zPTApp/PTService/IPTDocsService.h>
#import <zPTApp/PTService/IPTZDMServiceMgr.h>
#import <zPTApp/PTService/IPTTasksService.h>
#import <zPTApp/PTService/IPTZoomConfService.h>
#import <zPTApp/PTService/IPTZoomEventsService.h>
#import <zPTApp/PTService/IPTCalendarService.h>
#import <zPTApp/PTService/IPTEventTrackerService.h>
#import <zPTApp/PTService/IPTIMService.h>
#import <zPTApp/PTService/IPTPhoneService.h>
#import <zPTApp/PTService/IPTAccountService.h>

#import <zVideoApp/CmmShareAPI.h>
#import <zVideoApp/CmmConfAPI.h>
#import <PTUIBridge/ZMPTRouterCenter.h>
class ZMPTSink;
class IZPPTAppSink;
class IDeeplinkDispatcher;
namespace ps {
class IPSAudioDeviceMgr;
class IPSApp;
class IPSConfConfig;
class IPSContext;
class IPSMiscConfig;
}
@protocol IZMPTHelper <NSObject>
- (void)setPTSinkInstance:(ZMPTSink *)instance;
- (void)setZPPTAppSink:(IZPPTAppSink*)appSink;
- (void)setIMMsgSink:(ns_zoom_messager::IZoomMessengerUI*)msgSink;
#ifdef BUILD_FOR_CLIENT_SDK
- (BOOL)isInGR;
#endif
- (BOOL)zmFeatureToggleEnable:(NSString *)toggleName service:(NSString *)service;
- (ICmmConfMgrAPI*)getConfApi;
- (ps::IPSApp *)getPSApp;
- (ps::IPSContext *)getPSContext;
- (ps::IPSConfConfig *)getPSConfConfig;
- (ps::IPSMiscConfig *)getPSMiscConfig;
- (ps::IPSMediaAgent *)getPSMediaAgent;
- (ps::IPSAudioAgent *)getPSAudioAgent;
- (ISBWebServiceAPI*)getWebServiceApi;

//PT and Meeting chat only
- (ISBPTAppAPI*)getPTAppApi;
- (CPTServicePtr<IPTWhiteboardsService>)whiteboardsService;
- (ISSBPTUserProfile*)getUserProfile;
- (NS_ZOOM_MESSAGER::IZoomMessenger*)getMessenger;
- (ISBPTMeetingHelper*)getMeetingHelper;
- (ISBPTSettingHelper*)getSettingHelper;
- (IFBAuthHelper*)getFBAuthHelper;
- (ICmmConfInst *)getDefaultConfInst;
- (ISSBPTUserSetting*)getUserSetting;
//MARK: Common Layer APIS
- (CPTServicePtr<IPTAppWebService>)PTAppWebService;

- (CPTServicePtr<IPTUrlActionService>)PTUrlActionService;

- (CPTServicePtr<IPTAccountService>)PTAccountService;

- (CPTServicePtr<IPTMarketService>)PTMarketService;

- (CPTServicePtr<IPTAuthenticationService>)PTAuthenticationService;

- (CPTServicePtr<IPTZDMServiceMgr>)PTZDMService;

- (CPTServicePtr<IPTDocsService>)PTDocsService;

- (CPTServicePtr<IPTTasksService>)PTTasksService;

- (CPTServicePtr<IPTZoomConfService>)PTAppConfService;

- (CPTServicePtr<IPTZoomEventsService>)PTZoomEventsService;

- (CPTServicePtr<IPTCalendarService>)PTCalendarService;

- (CPTServicePtr<IPTEventTrackerService>)PTEventTrackerService;

- (CPTServicePtr<IPTIMService>)PTIMService;

- (CPTServicePtr<IPTPhoneService>)PTPhoneService;

- (CPTServicePtr<IDeeplinkDispatcher>)DeeplinkDispatcher;
@end

#define ZMPTHelper ZMSharedFor(IZMPTHelper)

#endif /* IZMPTHelper_h */
