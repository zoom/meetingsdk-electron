#ifndef _ZUI_CLIENT_MGR_H_
#define _ZUI_CLIENT_MGR_H_

#ifdef _WIN32
#include "zUIClient/zUI_stdafx.h"
#else
#include "zUI_stdafx.h"
#endif
#include "zui_new_setting_event.h"
#include "zUIClient/RecordMeeting/IMRecordMeetingZuiEventHandler.h"
#include "setting_panel_search.h"

#include "cmmlib/CmmPrefBase.h"
#include "cmmlib/CmmPrefConsts.h"
#include "cmmlib/CmmMessageQueueBase.h"
#include "ipt_mgr_hub.h"
#include <memory>
#include "cmmlib/CmmSettingTransfer.h"

class IZuiVideoMgrHub;
class IPTDialogHub;
class IPTMgrHub;
class IZUIPopupDialogMgr;
#if defined(__MACOS__)
class IZUIJsonPageRenderer;
#endif

class ZUIClient_API ZUIClientMgr: public zpref::IPolicyUpdateObserver, public zstref::ISettingTransferObserver
{
public:
  static ZUIClientMgr* getInstance();

  ZUIClientMgr(const ZUIClientMgr&) = delete;
  ZUIClientMgr& operator=(const ZUIClientMgr&) = delete;
    
  //> zpref::IPolicyUpdateObserver
  virtual void OnPolicyUpdated(const zpref::zPolicyList& policies) override;

  //> zstref::ISettingTransferObserver
  virtual CmmBool InterestedIn(zstref::MessageType message) override;
  virtual void OnTransferSettingUpdated(zpref::zPolicyScene scene, CmmUInt32 message_type, const Cmm::CAString& key) override;

  void InitLanguage(zoom_data::CMM_LANGUAGE_ID_VALUE languageId);
  zoom_data::CMM_LANGUAGE_ID_VALUE GetLanguageID();
  bool IsFullWidthPunctuation();

  void SetSystemColorMode(bool isDark);

  void SetNewSettingEventHandler(CZUINewSettingEventHandler* handler);
  CZUINewSettingEventHandler* GetNewSettingEventHandler();

  void SetRecordMeetingEventHandler(IZuiRecordMeetingEventHandler* handler);
  IZuiRecordMeetingEventHandler* GetRecordMeetingEventHandler();

  CSettingSearchDataInterface* GetSettingSearchInterface();

  static void NotifyEvent(ZUIClientSettingEventParam& event);
  static void NotifyEvent(ZUINewSettingEvent event_type);
  static void NotifyEvent(ZUINewSettingEvent event_type, zui::any& wparam);
  static void NotifyEvent(ZuiRecordMeetingEvent event_type, const zui::any& param);

  //> ICmmMessageQueueClient related events
  void DoInitAfterObjCreated(ICmmMessageQueueClient* pMQClient = nullptr);
  void DoUninitBeforeObjDestroyed(ICmmMessageQueueClient* pMQClient = nullptr);

  void InitVideoMgrHub();
  void UninitVideoMgrHub();

  IZuiVideoMgrHub* GetVideoMgrHub() { return video_mgr_hub_; }
  
  // PT Manager Hub APIs
  void InitPtMgrHub();
  void UninitPtMgrHub();
  IPTMgrHub* GetPTMgrHub();

  // Generic popup dialog manager (shared by PT/Meeting/Settings)
  IZUIPopupDialogMgr* GetPopupDialogMgr();

#if defined(__MACOS__)
  // Lazily created. It has no effect until a caller supplies JSON through
  // IZUIJsonPageRenderer::SetPageJson().
  IZUIJsonPageRenderer* GetJsonPageRenderer();
#endif

private:
  ZUIClientMgr() = default;
  ~ZUIClientMgr();

  CZUINewSettingEventHandler* _eventHandler = nullptr;
  IZuiRecordMeetingEventHandler* _recordMeetingHandler = nullptr;

  zoom_data::CMM_LANGUAGE_ID_VALUE _languageId = zoom_data::CMM_LANGUAGE_ID_VALUE::Unknow;

  std::map<ICmmMessageQueueClient*, int> _uuiRegSinkMap;

  IZuiVideoMgrHub* video_mgr_hub_ = nullptr;
  std::unique_ptr<IPTMgrHub> _ptMgrHub;
  IZUIPopupDialogMgr* _popupDialogMgr = nullptr;
#if defined(__MACOS__)
  std::unique_ptr<IZUIJsonPageRenderer> _jsonPageRenderer;
#endif
};

#endif //_ZUI_CLIENT_MGR_H_
