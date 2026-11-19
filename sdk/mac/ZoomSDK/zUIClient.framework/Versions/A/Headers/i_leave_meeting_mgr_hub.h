#ifndef I_LEAVE_MEETING_MGR_HUB_H
#define I_LEAVE_MEETING_MGR_HUB_H

#include "zUI_stdafx.h"

class IFeedbackDialogMgr;
class ILeaveMsgDialogMgr;
class IPTAlertDialogMgr;
class IPostMeetingAssetMgr;
class IPromoteChatDialogMgr;
class IMeetingExtendedDialogMgr;
class IMarketingNoticeDialogMgr;
class IUnlimitGiftDialogMgr;
class IUnloginUserDialogMgr;
class ISBPTAppSink;
class IIPCEventHandlerPlatformDelegate;

// Aggregates the post-meeting / leave-meeting dialog managers together with the
// IPC event handler that drives them. Owned by IPTMgrHub via composition so the
// leave-meeting concern is isolated from the login / generic PT-dialog concerns
// that also live on IPTMgrHub.
//
// Lifetime: created and Init()'d by the owning IPTMgrHub; torn down in its
// Uninit(). All managers are eagerly created in Init() and destroyed in reverse
// order in Uninit().
class ZUIClient_API ILeaveMeetingMgrHub
{
public:
  virtual ~ILeaveMeetingMgrHub() = default;

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Feedback Dialog Manager (UberLike 👍/👎 + BadExperience)
  virtual IFeedbackDialogMgr* GetFeedbackDialogMgr() = 0;

  // Leave-Message Dialog Manager (IPC_SENDFEEDBACK_KEY)
  virtual ILeaveMsgDialogMgr* GetLeaveMsgDialogMgr() = 0;

  // Alert Dialog Manager — ZUI replacements for MessageWnd.xml leave-meeting dialogs
  virtual IPTAlertDialogMgr* GetAlertDialogMgr() = 0;

  // Post-meeting asset panel manager
  virtual IPostMeetingAssetMgr* GetPostMeetingAssetMgr() = 0;

  // Promote-chat-after-meeting dialog manager
  virtual IPromoteChatDialogMgr* GetPromoteChatDialogMgr() = 0;

  // Meeting-extended notification dialog manager
  virtual IMeetingExtendedDialogMgr* GetMeetingExtendedDialogMgr() = 0;

  // Marketing Notice (Phone Upgrade) dialog manager
  virtual IMarketingNoticeDialogMgr* GetMarketingNoticeDialogMgr() = 0;

  // Free-Meeting Gift / PPM post-meeting dialog manager
  virtual IUnlimitGiftDialogMgr* GetUnlimitGiftDialogMgr() = 0;

  // Unlogin-user post-meeting registration dialog manager
  virtual IUnloginUserDialogMgr* GetUnloginUserDialogMgr() = 0;

  // Returns the ZUI post-meeting IPC observer as its public sink interface
  virtual ISBPTAppSink* GetZUIIPCEventHandler() = 0;
  virtual void SetIPCEventHandlerDelegate(IIPCEventHandlerPlatformDelegate* delegate) = 0;

  // Brings the feedback dialog (or leave-message dialog) to the front on window
  // activation; returns true when handled so the caller can skip its own logic.
  virtual bool OnMainFrameWindowActivate() { return false; }

  // Post-meeting asset panel (leave-meeting-with-asset / conf-ended panel).
  virtual bool IsPostMeetingAssetPanelShowing() { return false; }
  virtual void DismissPostMeetingAssetPanel() {}

  virtual bool IsLeaveMsgDialogShowing() { return false; }
  virtual bool IsAnyLeaveMeetingDlgsShowing() { return false; }

  // Close all ZUI post-meeting dialogs on logout.
  virtual void CloseAllDialogWhenLogout() {}
};

#endif // I_LEAVE_MEETING_MGR_HUB_H
