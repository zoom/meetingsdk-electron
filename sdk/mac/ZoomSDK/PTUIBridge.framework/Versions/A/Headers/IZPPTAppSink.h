//
//  IZPPTAppSink.h
//  PTUI
//
//  Created by fistice on 2024-07-17.
//

#ifndef IZPPTAppSink_h
#define IZPPTAppSink_h
#include "zoom_client_conf.h"
#include <cmmlib/CmmDef.h>
#include <zPTApp/SaasBeePTAppInterface.h>
#include <zVideoApp/Confdef.h>
#include <zVideoApp/CmmConfAPI.h>
#include <zPTApp/SaasBeePTAppConstants.h>
#import <zPTApp/PTService/IPTAppWebService.h>

class IZPPTAppSink
{
public:
    virtual void DispatchPTAppEvent(PT_EVENT ptEvent, CmmUInt32 result, void* content) = 0;
    virtual void DispatchIMEvent(PT_IM_EVENT ptEvent, CmmUInt32 result, void* content) = 0;
    virtual void DispatchIPCEvent(PT_IPC_EVENT ptEvent, CmmUInt32 result, void* content) = 0;
    virtual void DispatchScheduleEvent(PT_MEETING_EVENT ptMeetingEvent, CmmUInt32 result, void* content) = 0;
    virtual int sinkStartRecConverter(const CString& path, CmmInt64 itemID) = 0;
    virtual int SinkOpenRecord(CmmInt64 itemID) = 0;
    virtual int SinkPlayRecord(CmmInt64 itemID) = 0;
    virtual int SinkPlayAudioRecord(CmmInt64 itemID) = 0;
    virtual int SinkDeleteRecord(CmmInt64 itemID) = 0;
    virtual void SinkResizeWebview(const CString& tabIdentifier, CmmInt64 width) = 0;
    virtual void sinkFavoriteEvent(PT_FAVORITE_EVENT ptEvent, CmmUInt32 result, void* content) = 0;
    virtual void sinkSearchDomainUser(const CString& requestID, CmmUInt32 result, CmmUInt32 contactCount, const NS_ZOOM_DATA::arrContacts& contacts) = 0;
    virtual void sinkFavAvatarReady(const CString& userid) = 0;
    virtual void destroyUI() = 0;
    
    virtual void OnScheduleBannerShow(const CString& msg) = 0;
    virtual void OnScheduleBannerButtonClick(const CString& msg) = 0;
#ifdef ENABLE_ZOOM_CCI
    virtual void NotifyPAKandCAKRefreshed(CmmUInt32 err_code) = 0;
    virtual void NotifyTurnOnOffCCIAudio(CmmBool isTurnOn) = 0;
    virtual CmmBool IsCCIUsingAudio() = 0;
    virtual void NotifyCCIUserDeleted() = 0;
    virtual void OnDownloadFileByUrlForCCI(const CString& requestID, const CString& localFilePath, CmmUInt32 result, const std::vector<CAString>& headers) = 0;
    virtual void SyncClientAudioSettingsToCCI() = 0;
    virtual void NotifyCCINetworkState(CmmBool isConnected) = 0;
    virtual void OpenMainWindowAndJumpToCCITab() = 0;
    virtual void NotifyOnDoTransferAcceptCallForCCI(const Cmm::CString& reqID, const CmmUInt32 retCode, const CAString& resp, const CAString& tracking_id) = 0;
    virtual void NotifyCCILeaveNativeVideo() = 0;
    virtual void NotifyCCIHybridSDKVideoMsgRecieved() = 0;
    virtual void StartEscalationFromZPToZCC(const Cmm::CString &url, const Cmm::CString &name) = 0;
    virtual void HandleZccVideoInboundForConsumer(const Cmm::CString &url) = 0;
    virtual void NotifyCCIAgentForceNotReady() = 0;
    virtual void NotifyCCIAgentStatusChanged(const Cmm::CString& type, const Cmm::CString& fromStatus, const Cmm::CString& toStatus, const Cmm::CString& nextStatus) = 0;
    virtual void NotifyCCIAgentRequestForHelp(const Cmm::CString& engagementId) = 0;
#endif
    virtual CmmBool IsCurrentUserEnableCCI() = 0;
    virtual void ShowNotAllowEmailAlert() = 0;    //Zoom-47270
    virtual void notifyLocalAddressChanged(const CString& old_ip, const CString& new_ip) = 0;
    virtual CmmBool GetIsInSipCall() = 0;
    virtual void OnZoomPhoneBlockStatusChanged(bool is_blocked) = 0;
    virtual void OnZoomPhoneZPNSLoginStatus(CmmZPNSLoginStatus status) = 0;
    virtual void OnNewZoomPhoneExperienceUpdated(const Cmm::Optional<CmmInt32>& experience) = 0;
    virtual void sinkChatProtEvent(PT_CHATPROTOCOL_EVENT ptEvent, const DataLunchRequest& request_info) = 0;    //ZOOM-61336
    virtual void SinkOnZoomLobbyEvent(PT_ONZOOMLOBBY_EVENT ptEvent, const RequestLobbyErrorParam& requestLobbyErrorInfo) = 0;//ZOOM-255235
    virtual void OnDeeplinkRoutePage(DeeplinkRoutePageParam params) = 0;
    virtual void NavigateDeeplinkUrl(IDeeplink* url) = 0;
    virtual void OnDeeplinkPopoutActionReceived(const std::string& params) = 0;
    virtual void OnDynamicUIHandleMessageReceived(const std::string& params) = 0;
    virtual void OnAlertPopoutActionReceived(const std::string& params) = 0;
    virtual void OnMenuPopoutActionReceived(const std::string& params) = 0;
    virtual void OnAddWebPageDeeplink(const Cmm::CAString& url, const Cmm::CAString& name, const std::map<Cmm::CAString, Cmm::CAString>& params_map = {}, CmmBool can_navigate = CmmTrue) = 0;
    virtual void OnOpenZoomSupport() = 0;
    virtual void OnWebPageLoadResultForDeeplink(const CString& req_id, const CString& name, const CString& url) = 0;
    virtual void NotifyVideoDeepLink(const VideoDeepLinkParam& param) = 0;  //ZOOM-156726
    virtual void NotifyRequestLobby(const RequestLobbyParam& param) = 0;
    virtual CmmBool IsOnZoomWindowOpened() = 0;
    virtual void NotifyRequestNewLobby(const RequestLobbyParam& param) = 0;
    virtual void NotifyOnZoomChannelWindow(void* wnd) = 0;
    virtual void NotifyRemoveOnZoomChannel(const NS_ZOOM_MESSAGER::OnZoomRemoveChannelInfo& info) = 0;
    virtual void NotifyOnZoomWebviewForceUpdate() = 0;
    virtual void JsSdkCallResultForZoomEvents(const CString& reqId, const CAString& extraData, const CString& funcName) = 0;
    virtual void NotifyOnZoomJoinStatusChange(const CAString& status, const CString& meetingId) = 0;
    virtual void NotifyParingStatusChange(const CAString& eventJson) = 0;
    virtual void NotifyOnCommonNotificationToLobby(const CAString& eventJson) = 0;
    virtual void Notify_Zpns_OnPushSetOfflineZESettingData(const CString& reqId, const CmmInt64& result) = 0;
    virtual void Notify_Zpns_OnPushGetOfflineZESettingData(const CString& reqId, const CmmInt64& config, const CmmInt64& result) = 0;
    virtual void OnGetZETokenWithFileIdDone(const CString& fileId, const CString& token, const CString& source) = 0;
    virtual void ShowWebviewForceUpdateToast(const CString& strAffectedName) = 0;
    virtual void NotifyActivateOnZoomWindow() = 0;
    virtual void RestartAppWhenNetworkResume() = 0;
    virtual CmmBool RequestMaintenanceRestart() = 0;
    virtual void OnCmrStorageInfoPush(const SB_webservice::CMRStorage& info) = 0;
    virtual void OnCmrStorageProfileResponse(const SB_webservice::CMRStorage& info) = 0;
    virtual void NotifySendNavIconListDone(const CString& requestID, CmmUInt32 result, const CString& errorMessage) = 0;
    virtual void OnPromptFirstUpdate(CmmBool bShow, ISBPTAppSink::FirstUpdatePromptType type, CmmBool& done) = 0;
    virtual void OnPromptDelayUpdateNotify(CmmBool& done) = 0;
    virtual void OnUploadFeedbackResult(const CString& reqid, CmmUInt32 result) = 0;//ZOOM-114602
    
    virtual void OnMarketBannerInfoGet(const RequestBannerInfoParam& params, const CString& requestID) = 0;
    virtual void OnGetMarketNoticeResponse(const CString& requestID, CmmUInt32 result, const std::vector<zWebService_Biz::ClientMarketingBannerV2>& response) = 0;
    virtual void OnMarketBannerInfoClose(CmmInt32 result, const CString& requsetID) = 0;
    virtual void OnMarketingDialogInfoGet(const RequestMarketingDialogInfoParam &params, const CString &requestID) = 0;
    virtual void OnRequestVOBillingNoticeBanner(const std::vector<ISBPTAppSink::RequestVOBillingNoticeBanner>& banner_list) = 0;
    virtual void OnBillingStatusPushReceived() = 0;
    virtual void OnAICNotificationChange(const CmmInt64 count, const CString& requestID) = 0;
    virtual void OnProfileAICSettingManageInfoChanged() = 0;
    virtual void OnZoomPhoneLicenseStatusChange(CmmBool is_license_enabled, CmmUInt64 old_bit_options, CmmUInt64 new_bit_options) = 0;
    virtual void OnWebOpenLocalRecordingFolder(const OpenLocalRecordingFolderParam& param) = 0;
    virtual void OnRequestLaucnhVn(CmmUInt32 returnCode, const std::map<CAString, CString>& webdataParams) = 0;
    virtual void OnShowCrashReport() = 0;
    virtual void OnStatCrashReport(const std::vector<CString>& arrDump) = 0;
    virtual void NotifyCloudRecordingComplete(std::map<CString, CString> eventMap) = 0;
    virtual CmmBool GetIsSipFeatureEnabled() = 0;
    virtual void ShowChatPath(const CString& path) = 0;
    virtual CmmBool SinkSipLocationCheckUpdate(const CString& latestVersion, const CString& downloadURL, const CString& releaseNote, const CString& requestID, CmmUInt32 result) = 0;
    virtual void OnGetSecurityParams(ISBPTAppSink::GetSecurityParamsStatus stauts, GetSecurityParamsError error) = 0;
    virtual void NotifyStartCaptureOnZoomWindow(void* wnd, const CString& reqid) = 0;
#ifdef ENABLE_ZAPP
    virtual void OnToggleZappFeature(CmmInt state) = 0;
    virtual void OnWebviewForceUpdate(const CString& webviewVersion) = 0;
    virtual void OnWebviewValidityFromWeb(const std::vector<NS_ZOOM_DATA::WebViewStatusInfo>& webviewInfo) = 0;
#endif //ENABLE_ZAPP
    virtual void OnWBJsOpenSaveFileFolder(const CString& save_path) = 0;
    virtual void NotifyNeedSwitchAccount(const ISBPTAppSink::SwitchAccountDatas& switchAccountDatas, CString newAccountEmail, CString currentUserName) = 0;
    
    virtual void SinkForOpenAICByDeepLink(int returnCode, const std::map<CAString, CString>& params) = 0;

    virtual CmmBool DoTransferMeetingFromPairedZR(const CString& resourceID, const CString& deviceID, const CString& meetingNumber) = 0;
    virtual CmmBool DoSwitchToComputerOnlyFromPairedZR(const CString& resourceID, const CString& deviceID, const CString& meetingNumber) = 0;
    virtual CmmBool JoinMeetingCompanionModeWithPairedZR(const CString& resourceID, const CString& deviceID, const CString& meetingNumber) = 0;
    virtual CmmBool JoinFromRoomOnly(CmmInt64 meeting_number, const CString& password, const CString& personal_link, CmmBool is_host) = 0;

    virtual CmmBool IsClientSupportTab(const CString& tab_name) = 0;
    
#ifdef ENABLE_ZOOM_CALENDAR
    virtual void GetCalendarSystemParam(CalendarSystemParam &calSysParam) = 0;
    virtual void CallPhoneNumberByCalendar(const CString& phonenumber) = 0;
#endif //ENABLE_ZOOM_CALENDAR
    virtual void SinkShowAicPlusSidePanel(CmmBool visible) = 0;
    virtual CmmBool IsAicPlusSidePanelDisplayed() = 0;
    virtual CmmBool IsPtRightPanelVisible() = 0;
    virtual CmmBool SinkSendEventToAicPlus(const std::map<CString,CString>& eventParams) = 0;
    virtual void OnInviteToCallBySMSPush(const CmmInt64& meetingNO, const CString& messageID, CmmUInt32 result) = 0;
    virtual void OnInviteToCallBySMSResponse(const CString& requestID, const CString& messageID, CmmUInt32 result) = 0;
    virtual void OnDocStatusPush(const NS_ZOOM_DATA::DocStatusPush& push) = 0;
    virtual void OnTabStatusPush(const NS_ZOOM_DATA::TabStatusPush& push) = 0;
    virtual void OnHubStatusPush(const NS_ZOOM_DATA::HubStatusPush& push) = 0;
    virtual void OnTasksStatusPush(const NS_ZOOM_DATA::TasksStatusPush& push) = 0;//ZOOM-910581
    virtual void OnShowTasksToast(const CString& url, const CString& title) = 0;
    
    //Whiteboard relevants start
    virtual void OnWBJsOpenNewWindowFromUrl(const CAString& url, bool* isSucceed = nullptr) = 0;
    virtual void OnWBJsCloseOpenWindowForce(IWBWebViewJSMessageSender* sender) = 0;
    virtual void OnWBJsOpenIMDashboard() = 0;
    virtual void OnWBJsReportProblem() = 0;
    //Whiteboard relevants end
    
    virtual void SendMeetingDocsShareCollaboratorsInviteInfo(const std::vector<CString>& user_id) = 0;
    virtual void PostJsonMessage2Web(const CAString& eventData) = 0;
    virtual void RegisterDeviceBy3rdSdk(const CString& device_name) = 0;
    virtual void NotifyZZhostWebHIDConfigListUpdate() = 0;

    virtual void SinkNeedSetupPbxChange(const CString& needSetup, const CString& setupLink) = 0;

    virtual void OnEscrowServiceEnabled() = 0;
    virtual void OnLoadingPTKBCrypto() = 0;
    virtual void OnKeyServerSigchainAlreadyEnabled(int init_reason) = 0;
    virtual void OnFreeUserLicenseUpdate(CmmInt64 seqid, const CAString& eventId) = 0;
    virtual void OnReleaseNotesChange() = 0;
    virtual void OnRequestForGetABTestResponse(const CString& requestID) = 0;
    ~IZPPTAppSink() {};
        
    //ASR
    virtual void NotifyToCheckUpdateASRLibrary() = 0;
    virtual void NotifyToCheckUpdateASRModels(const asr_model_download_infos& models) = 0;
    virtual void NotifyToPauseAllDownloadingASRModels() = 0;
    virtual void OnDownloadingFileByUrl(const CString& requestID, const CString& localFilePath, CmmUInt32 result) = 0;
    
    virtual void OnMailAccountCreate() = 0;
};

#endif /* IZPPTAppSink */
