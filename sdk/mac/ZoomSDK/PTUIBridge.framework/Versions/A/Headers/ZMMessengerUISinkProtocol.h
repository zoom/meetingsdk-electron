//
//  ZMMessengerUISinkProtocol.h
//  PTUIBridge
//
//  Created by fistice on 7/25/25.
//

#ifndef ZMMessengerUISinkProtocol_h
#define ZMMessengerUISinkProtocol_h

@protocol ZMMessengerUISinkProtocol <NSObject>
@optional
- (void)Indicate_BuddyBigPictureDownloaded:(const CString&)jid result:(CmmUInt32)result;
- (void)Indicate_BuddyAccountStatusChange:(const CString&)jid status:(AccountStatus)status;
- (void)Indicate_BlockedUsersAdded:(const std::vector<CString>&)users;
- (void)Indicate_AddAvailableAlert:(const CString&)jid result:(CmmUInt32)result;
- (void)Indicate_AvailableAlert:(const CString&)jid resource:(const CString&)resource;
- (void)Indicate_BuddyInfoUpdatedWithJID:(const CString&)jid;
- (void)On_SearchBuddyByKey_v2:(const ns_zoom_messager::SearchBuddyByTypeParam&)param result:(CmmUInt32)result;
- (void)Indicate_RemoveAvailableAlert:(const CString&)jid result:(CmmUInt32)result;
- (void)Indicate_BlockedUsersRemoved:(const std::vector<CString>&)users;
- (void)Indicate_SyncAvailableAlert:(const CString&)jid;
- (void)On_RemovedPendingContact:(const ns_zoom_messager::zGroupPendingContactCallBackInfo&)info;
- (void)Indicate_BuddyGroupMembersChanged:(const std::vector<NS_ZOOM_MESSAGER::BuddyGroupMemberChangeList>&)vecChangedBuddyGroups lastPage:(CmmBool)bLastPage;
- (void)Indicate_BuddyGroupMembersUpdated:(const CString&)groupID jidList:(const std::vector<CString>&)jidList;
- (void)Indicate_OnlineBuddies:(const std::vector<CString>&)jidList;
- (void)On_BeginConnect;
- (void)On_ConnectReturn:(XmppConnectionError)err;
- (void)Indicate_MobileOnlineBuddiesFromDB:(const std::vector<CString>&)jidList;
- (void)Indicate_BuddyPresenceChanged:(const CString&)jid;
- (void)On_MyPresenceChanged:(ZoomIMPresence)presence presenceStatus:(ZoomIMPresenceStatus)presenceStatus;
- (void)Indicate_BuddyListUpdated;
- (void)Indicate_VCardInfoReady:(const CString&)jid;
- (void)Indicate_SignatureSet:(const CString&)reqID result:(CmmUInt32)result;
- (void)Indicate_CallActionResponded:(const NS_ZOOM_MESSAGER::ZoomIMCallActionInfo &)imCallActionInfo;
//device
- (void)Notify_MyDeviceListInfoReady;
- (void)Notify_MyDeviceListPresenceChange:(const NS_ZOOM_MESSAGER::zDeviceInfo&)info;
- (void)Notify_MyDeviceListMultiPresenceChange:(const std::vector<NS_ZOOM_MESSAGER::zDeviceInfo>&)info;
- (void)Notify_DeviceSignedOut:(CmmBool)isSuccess info:(const NS_ZOOM_MESSAGER::zDeviceInfo&)info;
- (void)Notify_MyDeviceListNeedRefresh;
#if defined(ZOOM_DEBUG)
// Debug: one response for a repeat fired by IZoomMessenger::SendHttpRatelimitRequest.
// (ObjC types so the debug UI can consume it without C++ conversions.)
- (void)On_HttpRatelimitResponse:(NSString *)reqID
                         apiName:(NSString *)apiName
                    requestIndex:(NSInteger)requestIndex
                         success:(BOOL)success
                        httpCode:(NSInteger)httpCode
                        curlCode:(NSInteger)curlCode
                        zoomCode:(NSInteger)zoomCode
                            path:(NSString *)path
                            body:(NSString *)body;
#endif
@end
#endif /* ZMMessengerUISinkProtocol_h */
