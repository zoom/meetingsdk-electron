//
//  ZMPTSinkProtocol.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/25.
//

#ifndef ZMPTSinkProtocol_h
#define ZMPTSinkProtocol_h

#include <zPTApp/SaasBeePTAppInterface.h>
#import <Foundation/Foundation.h>

@protocol ZMPTSinkProtocol <NSObject>
@optional
- (void)initModule;
- (void)postJsonMessage2Web:(NSString *)jsonString;
- (void)sinkMeetingEvent:(PT_MEETING_EVENT)ptEvent result:(CmmUInt32)result content:(void *)content;
- (void)sinkIPCEvent:(PT_IPC_EVENT)ptEvent result:(CmmUInt32)result content:(void *)content;
- (void)sinkAppEvent:(PT_EVENT)ptEvent result:(CmmUInt32)result content:(void *)content;
- (void)sinkIMEvent:(PT_IM_EVENT)ptEvent result:(CmmUInt32)result content:(void *)content;

- (void)onZpnsCommonSidepanelReceived;
- (void)onAICompanionSettingUpdate;
- (void)onBillingStatusPushReceived;
- (void)onZpnsECMSNoticeReceived:(const std::vector<CmmECMSNoticeItem>&)ecms_notice_items;
- (void)onZpnsCommandClearListReceived:(const std::map<CString, std::vector<CString>>&)clear_list;

- (void)onZpnsAdsWidgetReceived:(const CmmAdsWidgetItem&)ads_widget_item;
- (void)onZpnsCommonToastReceived:(const std::vector<CmmZpnsToast>&) toast_vec;
- (void)onZpnsCommonCoachmarkReceived:(const std::vector<CmmZpnsCoachmark>&) vec_coachmarks;
- (void)onZpnsCommonCoachmarkUpdated:(const CmmZpnsCoachmark&) coachmark;
- (void)onZpnsAICSidePanelUpdated;
- (void)notifyUnKnownURLScheme;
- (void)onNeedForceUpgrade:(const UpdateAppParam&)param;
- (void)onNeedSoftUpgrade:(const UpdateAppParam&)param;
- (void)onRevokeXmppToken:(const CString&)reqID
                   result:(CmmUInt32)result;
- (BOOL)sinkRingtoneCheckUpdate:(const CString &)latestVersion
                    downloadURL:(const CString &)downloadURL
                    releaseNote:(const CString &)releaseNote
                      requestID:(const CString &)requestID
                         result:(CmmUInt32)result;
- (void)onRecaptchaRequest:(const SB_webservice::RecaptchaInfo&)info;

// ASR Download Events
- (void)notifyToCheckUpdateASRLibrary;
- (void)notifyToCheckUpdateASRModels:(const asr_model_download_infos&)models;
- (void)notifyToCheckUpdateASRCommonModel:(const CommonModelDownloadInfo&)model;
- (void)notifyToPauseAllDownloadingASRModels;
- (void)onDownloadingFileByUrl:(const CString&)requestID localFilePath:(const CString&)localFilePath result:(CmmUInt32)result;

- (void)onGetNoAuthNumberOfMeetingsV2Response:(const RequestMarketingDialogInfoParam&)response requestID:(const CString&)requestID;

- (void)onCustomMessageFromConf:(CmmUInt32)type andMsgData:(const CmmUInt8* )pMsgData andSize:(CmmUInt32)size;

- (void)handlePolishNotCompletedError:(const PolishNotCompeletedCtx&)ctx;
@end
#endif /* ZMPTSinkProtocol_h */
