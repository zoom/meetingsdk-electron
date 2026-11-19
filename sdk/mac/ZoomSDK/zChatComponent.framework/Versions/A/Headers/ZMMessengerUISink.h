//
//  ZMMessengerUISink.h
//  zChatComponent
//
//  Created by Devl on 9/19/25.
//

#ifndef ZMMessengerUISink_h
#define ZMMessengerUISink_h

#include <cmmlib/CmmDef.h>
#include <zPTApp/SaasBeePTAppInterface.h>
#import <ZoomUnit/ZMFileConstants.h>
#import <zChatApp/search/SearchMgr.h>
#include <zPTApp/PTService/IPTAppWebService.h>
#import <zPTApp/PTService/IPTInternetDetectService.h>
#import <zChatApp/mmessager/MarkMessage/IZoomMarkMessage.h>
#import <zChatApp/mmessager/MessagerStruct.h>
#import <zChatApp/FileTransfer/IFileStreamDownload.h>

class ZMMessengerUISink : public NS_ZOOM_MESSAGER::IZoomMessengerUI, public ns_im_crawler::CrawlerUICallback, public NS_ZOOM_MESSAGER::CommonAppUICallback, public NS_ZOOM_MESSAGER::ThreadDataUI, public NS_ZOOM_MESSAGER::IZoomMarkMessageUI, public NS_ZOOM_MESSAGER::IFileStreamDownloadUI
{
public:
    virtual void registerUISink() = 0;
    virtual void unregisterUISink() = 0;

    /// Subclass overrides to declare its source. Default: ZMFileSourceType_IM.
    virtual ZMFileSourceType GetSourceType() const { return ZMFileSourceType_IM; }
    
    //MARK: - Override but do nothing in base
    virtual void DataReady() {}
    virtual void On_BeginConnect() {}
    virtual void On_ConnectReturn(XmppConnectionError err) {}
    virtual void Indicate_BuddyListUpdated() {}
    virtual void Indicate_BuddyInfoUpdated(const CString& phoneNumber) {}
    virtual void Indicate_BuddyInfoUpdatedWithJID(const CString& jid) {}
    virtual void Indicate_BuddyBigPictureDownloaded(const CString& jid, CmmUInt32 result) {}
    virtual void Indicate_OnlineBuddies(const std::vector<CString>& jidList) {}
    virtual void Indicate_BuddyGroupsRemoved(const std::vector<CString>& groupIDs) {}
    virtual void Indicate_BuddyPresenceChanged(const CString& jid) {}
    virtual void Indicate_BuddyGroupAdded(const CString& groupID) {}
    virtual void Indicate_BuddyGroupInfoUpdated(const CString& groupID) {}
    virtual void Indicate_BuddyGroupMembersAdded(const CString& groupID, const std::vector<CString>& jidList) {}
    virtual void Indicate_BuddyGroupMembersRemoved(const CString& groupID, const std::vector<CString>& jidList) {}
    virtual void Indicate_BuddyGroupMembersChanged(const std::vector<NS_ZOOM_MESSAGER::BuddyGroupMemberChangeList>& vecChangedBuddyGroups, CmmBool bLastPage) {}
    virtual void Indicate_BuddyAdded(const CString& jid, const std::set<CString> gorupIDs) {}
    virtual void On_AddLocalPendingBuddy(const CString& jid, CmmUInt32 result, const CString& groupJid) {}
    virtual void On_RemoveBuddy(const CString& jid, CmmUInt32 result) {}
    virtual void On_SearchBuddy(const CString& email, CmmUInt32 result) {}
    virtual void On_SearchBuddyByKey(const CString& key, CmmUInt32 result) {}
    virtual void On_SearchBuddyPicDownloaded(const CString& jid) {}
    virtual void Notify_SubscribeRequest(const CString& jid, const CString& msg) {}
    virtual void Notify_SubscriptionAccepted(const CString& jid) {}
    virtual void Notify_SubscriptionDenied(const CString& jid) {}
    virtual void Notify_UnsubscribeRequest(CString const& strBareJid, CString const& message) {}
    virtual void Notify_SubscribeRequestUpdated(const CString& jid) {}
    virtual void Notify_MUCGroupInfoUpdated(const CString& groupid) {}
    virtual void Notify_ChatSessionListUpdate() {}
    virtual void Notify_JIDUpdated() {}
    virtual void Indicate_InputStateChanged(const CString& sessionID, NS_SSB_XMPP::SSBIMInputState state) {}
    virtual void Indicate_IMCMD_Received(const CString& senderJID, const CString& senderName, const CString& message, const Cmm::Time& tm, MessageType t) {}
    virtual void On_ReceivedCall(const CString& groupID, const CString& senderID, InvitationItem* ii) {}
    virtual void NotifyBuddyJIDUpgrade(const CString& phoneNo,const CString& oldJID, const CString& newJID) {}
    
    //MARK: - Override with common logic
    // Common app callback methods
    virtual void Notify_SendGetHttpMessageDone(const CString& reqID, CmmUInt32 result);
    virtual void Notify_SendPostHttpMessageDone(const CString& reqID, CmmUInt32 result);
    virtual void Notify_EditCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::EditParam& param);
    virtual void Notify_FieldsEditCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::FieldsEditParam& param);
    virtual void Notify_ButtonCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::ButtonParam& param);
    virtual void Notify_CheckBoxsCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::CheckBoxsParam& param);
    virtual void Notify_RadioButtonCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::RadioButtonParam& param);
    virtual void Notify_SelectCommandResponse(CmmBool isSuccess, const NS_ZOOM_MESSAGER::SelectParam& param);
    
    virtual void Notify_RobotCommandUpdate(const std::vector<CString>& robotJids);
    virtual void Notify_EditRobotMessage(const NS_ZOOM_MESSAGER::RobotEditInfo& info);
    virtual void Notify_RevokeRobotMessage(const NS_ZOOM_MESSAGER::RobotRevokeInfo& info);
    virtual void Notify_StopStreamingDone(CmmBool isSuccess, const CString& reqID, const NS_ZOOM_MESSAGER::StopStreamPram& param);
    virtual void Notify_OpenWebviewByWebhook(const NS_ZOOM_MESSAGER::WebhookTemplateDialog &info);
    
    // Bot callback methods
    virtual void On_AddedBotToGroup(const NS_ZOOM_MESSAGER::zGroupCallBackInfo& info);
    virtual void On_RemovedBotFromGroup(const NS_ZOOM_MESSAGER::zGroupCallBackInfo& info);
    
    virtual void IndicateChatAppsGetBotsList(const NS_ZOOM_MESSAGER::ChatAppsGetBotsRsp& get_bots_rsp);
    virtual void IndicateChatAppsAddBotsToChannel(const NS_ZOOM_MESSAGER::ChatAppsEditBotsRsp& info);
    virtual void IndicateChatAppsRemoveBotsFromChannel(const NS_ZOOM_MESSAGER::ChatAppsEditBotsRsp& info);
    
    // Session update methods
    virtual void Notify_ChatSessionUpdate(const CString& sessionID);//will update pin
    
    // Message confirmation methods
    virtual void Confirm_MessageSent(const CString& sessionID, const CString& messageID, CmmUInt32 result);
    virtual void Confirm_FileDownloaded(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, CmmUInt32 result);
    virtual void Confirm_PreviewPicFileDownloaded(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, CmmUInt32 result);
    virtual void Confirm_PreviewAttachmentDownloaded(const CString& sessionID, const CString& messageID, CmmUInt32 result);
    virtual void Indicate_MessageRecieved(const CString& sessionID, const CString& senderJID, const CString& messageID);
    
    // File transfer methods
    virtual void FT_OnSent(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, CmmUInt32 result);
    virtual void FT_OnProgress(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, CmmUInt32 ratio /*0-100*/, CmmUInt32 completeSize, CmmUInt32 bitPerSecond);
    virtual void FT_OnResumed(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, CmmUInt32 result);
    virtual void FT_OnAsyncRestrictionCheckResult(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex, ns_zoom_messager::FT_AsyncRestrictionResult result);
    virtual void FT_DownloadByFileID_OnProgress(const CString& reqID, const CString& webFileID, CmmUInt32 ratio /*0-100*/, CmmUInt32 completeSize, CmmUInt32 bitPerSecond);
    
    // File management methods
    virtual void Indicate_FileAttachInfoUpdate(const CString& reqID, const CString& webFileID, CmmUInt32 result);
    virtual void Indicate_FileDeleted(const CString& reqID, const CString& webFileID, CmmUInt32 result);
    virtual void Indicate_FileDownloaded(const CString& reqID, const CString& webFileID, CmmUInt32 result);
    virtual void Indicate_RenameFileResponse(CmmUInt32 result, const CString& reqID, const CString& fileID, const CString& newName);
    virtual void Indicate_PreviewDownloaded(const CString& reqID, const CString& webFileID, CmmUInt32 result);
    virtual void Indicate_FileStatusUpdated(const CString& fileID);
    virtual void Indicate_FileActionStatus(const ns_zoom_messager::FileActionSyncInfo& info);
    virtual void Indicate_FileMessageDeleted(const CString& sessionID, const CString& msgID);
    
    // File stream methods - IFileStreamDownloadUI
    virtual void Notify_StreamDownloadStarted(const CString& reqID, const NS_ZOOM_MESSAGER::MessageIndex& msgIdx);
    virtual void Notify_StreamDownloadProgress(const CString& reqID, const NS_ZOOM_MESSAGER::MessageIndex& msgIdx,
                                               CmmUInt32 ratio, CmmInt64 received, CmmInt64 total);
    virtual void Notify_StreamDownloadCompleted(const CString& reqID, const NS_ZOOM_MESSAGER::MessageIndex& msgIdx,
                                                CmmUInt32 reason, CmmUInt32 returnCode);
    
    // File transfer timeout methods
    virtual void FT_OnDownloadByMsgIDTimeOut(const CString& sessionID, const CString& messageID, CmmInt64 fileIndex);
    virtual void FT_OnDownloadByFileIDTimeOut(const CString& reqID, const CString& webFileID);
    virtual void FT_UploadFileInChatTimeOut(const CString& session, const CString& messageID, CmmInt64 fileIndex);
    
    // Message operation methods
    virtual void Indicate_RevokeMessageResult(const NS_ZOOM_MESSAGER::zMessageRevokeInfo& info, CmmBool result);
    virtual void Indicate_DownloadFileByUrl(const CString& reqID, CmmUInt32 result);
    virtual void Indicate_EditMessageResult(const NS_ZOOM_MESSAGER::zMessageEditInfo& info, CmmBool result);
    virtual void Indicate_MessageInfoUpdated(const CString& sessionID, const CString& messageID);
    
    // Link crawl and image download methods
    virtual void OnLinkCrawlResult(ns_im_crawler::CrawlLinkResponse& resp);
    virtual void OnDownloadImage(CmmUInt32 result, const CString& req_id);
    virtual void OnDownloadFavicon(CmmUInt32 result, const CString& req_id);
    
    // Giphy methods
    virtual void Indicate_GetHotGiphyInfoResult(const NS_ZOOM_MESSAGER::zGiphyInfo& result);
    virtual void Indicate_GetGIFFromGiphyResult(const NS_ZOOM_MESSAGER::zGiphyInfo& result);
    virtual void Indicate_DownloadGIFFromGiphyResult(const NS_ZOOM_MESSAGER::zGiphyDownloadInfo& result);
    virtual void Indicate_GetGiphyInfoByID(const NS_ZOOM_MESSAGER::GiphyMsgInfo& result, const CString& sessionID, const CString& messageID, const CString& reqID);
    
    // Thread data methods
    virtual void OnGetThreadData(const NS_ZOOM_MESSAGER::ThreadDataFilter& filter, NS_ZOOM_MESSAGER::ThreadDataResult& result);
    virtual void OnGetCommentData(const NS_ZOOM_MESSAGER::CommentDataFilter& filter, NS_ZOOM_MESSAGER::CommentDataResult& result);
    virtual void OnThreadContextUpdate(const NS_ZOOM_MESSAGER::ChannelID& channel, const NS_ZOOM_MESSAGER::ThreadIndex& thr);
    virtual void OnThreadContextSynced(const NS_ZOOM_MESSAGER::ChannelID& channel, const NS_ZOOM_MESSAGER::ThreadIndex& thr, const CString& xms_req_id);
    virtual void OnMSGDBExistence(const CString& req_id, const NS_ZOOM_MESSAGER::ChannelID& channel, const NS_ZOOM_MESSAGER::MessageID& msg, CmmBool exist);
    virtual void OnSyncThreadCommentCount(const CString& req_id, const ns_zoom_messager::ChannelID& channel, const ns_zoom_messager::MessageIDVec& synced_msg_id, CmmBool success);
    
    // Emoji methods
    virtual void OnFetchEmojiDetailInfo(const CString& xms_req_id, const NS_ZOOM_MESSAGER::ChannelID& channel, const NS_ZOOM_MESSAGER::MessageID& msg, const CString& emoji, CmmBool success);
    virtual void OnFetchEmojiCountInfo(const CString& xms_req_id, const CString& channel, const NS_ZOOM_MESSAGER::MessageIDVec& msgs, CmmBool success);
    virtual void OnMessageEmojiInfoUpdated(const NS_ZOOM_MESSAGER::ChannelID& channel, const NS_ZOOM_MESSAGER::MessageID& msg);
    virtual void OnEmojiCountInfoLoadedFromDB(const NS_ZOOM_MESSAGER::ChannelID& channel);
    
    // Link unfurling methods
    virtual void Notify_EditLinkUnfuringMessage(const ns_zoom_messager::LinkUnfuringEditInfo& info);
    virtual void Notify_RevokeLinkUnfuringMessage(const ns_zoom_messager::LinkUnfuringRevokeInfo& info);
    virtual void Notify_RefreshLinkUnfurlings(const ns_zoom_messager::zMsgInfoForLinkUnfurling& info);
    virtual void Indicate_FetchLinkInfoResult(const CmmChat::zLinkInfoResult& result);
    
    // Pin message methods
    virtual void Indicate_TopPinMessage(const ns_zoom_messager::PinMessageCallBackInfo& info);
    virtual void Indicate_UnTopPinMessage(const ns_zoom_messager::PinMessageCallBackInfo& info);
    virtual void Indicate_RemovePinMessage(const ns_zoom_messager::PinMessageCallBackInfo& info);
    virtual void Indicate_SyncTopPinMessages(const CString& reqID, CmmUInt32 result, const std::map<CString, ns_zoom_messager::PinMessageInfo>& pinMsgs);
    virtual void Indicate_QueryPinMessageHistory(const CString& reqID, CmmUInt32 result, const CString& sessionID, const std::vector<ns_zoom_messager::PinMessageInfo>& pinMsgs, CmmInt64 nextTimeIndex);
    
    // Bookmark mthods
    virtual void Notify_ChatSessionMarkUnreadUpdate(const ns_zoom_messager::SessionMessageInfoMap& sessionMsgs);
    virtual void Notify_StarMessageDataUpdate();
    virtual void Notify_MarkUnreadOrReadDone(ns_zoom_messager::MessageIDInfo& id);
    virtual void Notify_StarOrUnstarMsgDone(ns_zoom_messager::MessageIDInfo& id);
    
    // Shortcuts methods
    virtual void Notify_MessageShortcutsUpdate();
    virtual void Notify_ComposeShotcutsUpdate();
    virtual void Notify_ThreadShotcutsUpdate();
    virtual void Notify_SessionShortcutsUpdate();
    virtual void Notify_ThreadShotcutIconDownloaded(const CmmChat::OneChatAppShortcutIcon& icon);
    virtual void Notify_MessageShotcutIconDownloaded(const CmmChat::OneChatAppShortcutIcon& icon);
    virtual void Notify_ComposeShotcutIconDownloaded(const CmmChat::OneChatAppShortcutIcon& icon);
    virtual void Notify_CustomizedComposeShotcutsUpdate(const CString& req_id, const CmmUInt32 result);
    
    // Whiteboard and compatibility methods
    virtual void FT_OnGetWhiteboardPreviewInfoDone(const NS_ZOOM_MESSAGER::WhiteboardPreviewInfo& info, CmmUInt32 result);
    virtual void Notify_DelWhiteboardFromMessage(NS_ZOOM_MESSAGER::DelWhiteboardParam& param);
    virtual void Notify_BackwardCompatibilityInfoReady();
    
    // reply to bottom
    virtual void MoveMessageWithNewReplyToBottom(const CString& sessionId, const CString& threadId, const CmmInt64 msgSSTime);
    
    // third party file integration ZOOM-68763
    virtual void OnFileIntegrationShareSelected(const CString& sessionID, const NS_ZOOM_MESSAGER::FileIntegrationShareInfo& info);
    virtual void OnFileIntegrationShareSelectedV2(const NS_ZOOM_MESSAGER::FileIntegrationSessionData& sessionData, const NS_ZOOM_MESSAGER::FileIntegrationShareInfo& info);
    //ZOOM-81803
    virtual void OnRequestOpenUrlForFileIntegrationSave(const CString& reqID, const NS_ZOOM_MESSAGER::FileIntegrationSessionData& sessionData, const CString& openURL, NS_ZOOM_MESSAGER::FileIntegrationError error);
    virtual void OnFileIntegrationSaveFinished(const CString& reqID, const NS_ZOOM_MESSAGER::FileIntegrationSaveInfo& info);
    
private:
    void UpdateUnfurlingMessage(const CString& msgId, const CString& sessionId);
    void HandleBotGroupEvent(const NS_ZOOM_MESSAGER::zGroupCallBackInfo &info, MessageType msgType);
};

#endif /* ZMMessengerUISink_h */
