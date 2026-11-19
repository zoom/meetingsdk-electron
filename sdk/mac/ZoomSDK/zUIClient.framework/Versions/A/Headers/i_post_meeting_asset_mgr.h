#ifndef I_POST_MEETING_ASSET_MGR_H
#define I_POST_MEETING_ASSET_MGR_H

#include "zUI_stdafx.h"
#include "post_meeting_param.h"
#include "zPTApp/SaasBeePTAppInterface.h"
#include "commonDef/CmmCommonStruct.h"  // MeetingAssetsInfo

// Platform-specific side-effects for the post-meeting asset panel.
// All methods provide empty default implementations.

class ZUIClient_API IPostMeetingAssetPlatformDelegate
{
public:
  virtual ~IPostMeetingAssetPlatformDelegate() {}

  virtual bool IsLoggedIn() const { return false; }
  virtual bool IsSupportSignUp() const { return false; }
  virtual bool HasCMCChat(const MeetingAssetsInfo& /*info*/) const { return false; }

  virtual void OnOpenMeetingDetails(const MeetingAssetsInfo& /*info*/) {}
  virtual void OnSignIn() {}
  virtual void OnOpenChat(const MeetingAssetsInfo& /*info*/) {}
  virtual void OnSignUp() {}

  // Checkbox-on-close actions. OnCloseZapps when conn_zapp_size > 0,
  // OnDisablePostMeetingPopup otherwise.
  virtual void OnCloseZapps() {}
  virtual void OnDisablePostMeetingPopup() {}

  // Fills |param2.formatted_date_time| using platform-native date/time
  // formatting. Other fields are populated by IPostMeetingAssetMgr::BuildParam.
  virtual void BuildParam(const ISBPTAppSink::ConfirmConfLeaveParam_t& /*param1*/,
                          PostMeetingParam& /*param2*/) {}
};

// Manages the ZUI post-meeting asset panel.
// Replaces AfterMeetingWndBase (Win), MeetingAssetsWndMgr (Linux),
// and ZMPostMeetingAssetsMgr (Mac) orchestration logic.
class ZUIClient_API IPostMeetingAssetMgr
{
public:
  virtual ~IPostMeetingAssetMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Host ended the meeting (conn_zapp_size>0 ⇒ "Close apps" checkbox;
  // ==0 ⇒ "Don't show again" checkbox when is_host).
  virtual void ShowConfEndedByHostWnd(int conn_zapp_size) = 0;

  // Local user leaves normally with assets available. Always shows
  // "Don't show again" checkbox.
  virtual void ShowLeaveMeetingWithAssetWnd() = 0;

  virtual void DismissPanel() = 0;
  virtual bool IsPanelShowing() = 0;

  // Re-queries IsLoggedIn() and refreshes login-dependent UI.
  virtual void RefreshLoginState() = 0;

  // Buddy avatar refreshed; no-op if panel hidden / logged-out / jid not subscribed.
  virtual void OnBuddyInfoUpdated(const CString& jid) = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IPostMeetingAssetPlatformDelegate* delegate) = 0;

  virtual void BuildParam(const ISBPTAppSink::ConfirmConfLeaveParam_t& param1) = 0;
};

#endif  // I_POST_MEETING_ASSET_MGR_H
