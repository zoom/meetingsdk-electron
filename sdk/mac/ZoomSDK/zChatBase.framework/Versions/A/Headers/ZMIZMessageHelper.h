//
//  ZMIZMessageHelper.h
//  ChatUI
//
//  Created by Groot Ding on 2022/5/18.
//  Copyright © 2022 Zoom. All rights reserved.
//

#ifndef ZMIZMessageHelper_h
#define ZMIZMessageHelper_h

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMFileConstants.h>
#if defined(__cplusplus)
#include <zPTApp/SaasBeePTAppInterface.h>
#include <zPTApp/PTService/IPTUrlActionService.h>
#endif

/// PT-only (resolves through `GetIMMessenger()`; nil in Meeting subprocess).
/// Meeting-reachable callers must use the matching `*InSession:` overload.
#define ZM_IM_ONLY __attribute__((annotate("zoom.process.im_only")))

extern void ClearZoomMeetChannelIDCache(void);
extern void ClearZoomMeetChannelIDCacheBySessionId(NSString * _Nonnull sessionId);

extern BOOL __attribute__((noinline)) IsZoomMeetChannelID (NSString * _Nonnull sessionId);
extern BOOL __attribute__((noinline)) IsZoomMeetSubChannelID (NSString * _Nonnull sessionId);

/// Meeting channel ID → ZMFileSourceType_Meeting; otherwise ZMFileSourceType_IM.
/// Use at ZMFileModule callsites when only a sessionId is available.
extern ZMFileSourceType __attribute__((noinline)) ZMFileSourceTypeForSessionID(NSString * _Nullable sessionId);

#if defined(__cplusplus)
extern ISBPTAppAPI * _Nullable __attribute__((noinline)) GetMeetingPTAppAPI(void);


extern NS_SIPCALL_APP::ISIPVMChatIntegration * _Nullable __attribute__((noinline)) GetSIPVoiceMailIntegration(void);

extern ISBPTAppAPI * _Nullable __attribute__((noinline)) GetPTAppAPIBySessionId (NSString * _Nullable sessionId);

extern BOOL __attribute__((noinline)) IsPTZappServiceReady(void);

#ifdef ENABLE_ZAPP
extern IZappService * _Nullable __attribute__((noinline)) GetConfAppAPI (void);
extern IZappJSRegister * _Nullable __attribute__((noinline)) GetConfAppJSRegister (void);
#endif

extern NS_ZOOM_MESSAGER::IZoomMessenger * _Nullable __attribute__((noinline)) GetIMMessenger(void) ZM_IM_ONLY;

extern NS_ZOOM_MESSAGER::IZoomMessenger * _Nullable __attribute__((noinline)) GetIZMessengerBySessionId (NSString * _Nullable sessionId);

/// Meeting → Meeting messenger; others → IM messenger.
extern NS_ZOOM_MESSAGER::IZoomMessenger * _Nullable __attribute__((noinline)) GetIZMessengerBySourceType(ZMFileSourceType sourceType);

extern NS_ZOOM_MESSAGER::ThreadDataProvider * _Nullable __attribute__((noinline)) GetThreadDataProviderBySessionId (NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomChatSession * _Nullable __attribute__((noinline)) GetIZSessionById (NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::IZoomGroup * _Nullable __attribute__((noinline)) GetIZGroupById (NSString * _Nonnull groupId);

extern NS_ZOOM_MESSAGER::IZoomBuddy * _Nullable __attribute__((noinline)) GetIZoomBuddy (NSString * _Nonnull jid,NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) GetIZoomMessage (NSString * _Nonnull messageId,NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) GetIZoomMessage (unsigned long long svrSideTime,NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) GetIZoomMessage (unsigned long long svrSideTime,NSString * _Nonnull sessionId,BOOL useDB);

//please attention!!!, this fuction will query message in cache, if cache not exist will sync query db,Please do not make frequent calls
extern NS_ZOOM_MESSAGER::IZoomMessage * _Nullable __attribute__((noinline)) QueryIZoomMessage (NSString * _Nonnull messageId,NSString * _Nonnull sessionId);

extern NS_ZOOM_MESSAGER::FileContentMgr * _Nullable __attribute__((noinline)) GetFileContentMgr(void);

extern NS_ZOOM_MESSAGER::FileContentMgr * _Nullable __attribute__((noinline)) GetFileContentMgrBySessoinId(NSString * _Nullable sessionId);

/// Meeting → kZMMTChatsNewChatSessionID's mgr; others → PT-global mgr.
extern NS_ZOOM_MESSAGER::FileContentMgr * _Nullable __attribute__((noinline)) GetFileContentMgrBySourceType(ZMFileSourceType sourceType);

extern NS_ZOOM_MESSAGER::IZoomMessageTemplate * _Nullable __attribute__((noinline)) GetZoomMessageTemplate(NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IMessageTemplate * _Nullable __attribute__((noinline)) GetMessageTemplateWithIndex(NSString * _Nullable messageId, NSString * _Nullable sessionId, int index);

extern NS_ZOOM_MESSAGER::IMessageTemplate * _Nullable __attribute__((noinline)) GetMessageTemplateWithIndexEx(NSString * _Nullable messageId, NSString * _Nullable sessionId, int index, BOOL async);

extern NS_ZOOM_MESSAGER::ISearchMgr * _Nullable __attribute__((noinline)) GetISearchMgr(void);
#ifdef ENABLE_ZAPP
extern UnifyWebView::IAppBridge * _Nullable __attribute__((noinline)) GetAppBridgeAPI(void);
#endif

extern ISBPTMeetingHelper * _Nullable __attribute__((noinline)) GetMeetingHelper(void);

extern NS_IM_NOTIFICATION::NotificationSettingMgr *_Nullable __attribute__((noinline)) GetNotificationSettingMgr(void);

extern NS_EMBEDDED_FILE_INTEGRATION::EmbeddedFileIntegrationMgr* _Nullable __attribute__((noinline))  GetEmbeddedFileIntegrationMgr(NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::PrivateStickerMgr * _Nullable __attribute__((noinline)) GetStickerMgr(NSString * _Nullable sessionId);

extern NS_IM_CRAWLER::LinkCrawler * _Nullable __attribute__((noinline)) GetLinkCrawler(NSString * _Nullable sessionId);

extern ISSBPTUserProfile * _Nullable __attribute__((noinline)) GetCurrentUserProfile(NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomPublicRoomSearchData * _Nullable __attribute__((noinline)) GetPublicRoomSearchData(NSString * _Nullable sessionId);

extern NS_ZOOM_MESSAGER::IZoomPersonalFolderMgr * _Nullable __attribute__((noinline)) GetPersonalFolderMgr (void);

extern CPTServicePtr <IPTUrlActionService> __attribute__((noinline)) GetPtUrlActionService(void) ZM_IM_ONLY;

extern NS_ZOOM_MESSAGER::ISidebarUnreadCountMgr * _Nullable __attribute__((noinline)) getSidebarUnreadMgr(void);

extern IAICPlusChatMgr * _Nullable __attribute__((noinline)) GetZoomAICPlusChatMgr(NSString *sessionId);
#endif

#endif /* ZMIZMessageHelper_h */
