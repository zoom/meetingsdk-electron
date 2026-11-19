#ifndef I_IPC_EVENT_HANDLER_PLATFORM_DELEGATE_H
#define I_IPC_EVENT_HANDLER_PLATFORM_DELEGATE_H

#include "zUI_stdafx.h"
#include "commonDef/CmmCommonStruct.h"        // Leave_Reason, CmmUInt64
#include "zPTApp/SaasBeePTAppInterface.h"     // ISBPTAppSink::ConfirmConfLeaveParam_t
#include "zUIClient/marketing_notice_types.h" // MarketingNoticeDialogType

// Platform hooks for ZUIIPCEventHandler's post-meeting orchestration.
// Injected via IPTMgrHub::GetLeaveMeetingMgrHub()->SetIPCEventHandlerDelegate().
// UI (main) thread only; implementations MUST be non-blocking.
// All methods provide empty default implementations.
class ZUIClient_API IIPCEventHandlerPlatformDelegate
{
public:
  virtual ~IIPCEventHandlerPlatformDelegate() = default;

  // ── Queries ──────────────────────────────────────────────────────────────
  // True if a pending update should pre-empt the post-meeting flow.
  virtual bool IsNeedHandleConfLeaveWithUpdate(Leave_Reason /*reason*/) { return false; }

  // True if the platform's update dialog is already on screen.
  virtual bool IsUpdateDialogShowing() { return false; }

  // Try to show the unauthenticated-user leave promo; true iff shown.
  virtual bool CheckAndShowUnLoginUserLeaveMeetingWnd(Leave_Reason /*reason*/) { return false; }

  // |gift_cnt| only consulted for the post-meeting-limit branch.
  virtual bool IsNeedShowMarketingNoticeDialog(MarketingNoticeDialogType /*type*/,
                                               unsigned int /*gift_cnt*/) { return false; }

  virtual bool IsCanShowPostMeetingAssets(
      const ISBPTAppSink::ConfirmConfLeaveParam_t& /*param*/) { return false; }

  // Fast pre-filter; final decision lives in IPromoteChatDialogMgr.
  virtual bool IsNeedShowChatAfterMeetingPromo() { return false; }

  // ── Actions ──────────────────────────────────────────────────────────────
  // Called only after IsNeedShowMarketingNoticeDialog returned true.
  virtual void ShowMarketingNoticeDialog(MarketingNoticeDialogType /*type*/) {}
  virtual void CloseSMCWindow() {}
  virtual void QuitApp() {}

  // No-op for a normal user-started PT.
  virtual void QuitIfSubProcess() {}
  virtual void StoreChatPromoteTime() {}

  // ── Notifications ────────────────────────────────────────────────────────
  // |meeting_number|!=0 also fires the per-meeting toaster on Win.
  virtual void NotifyIMShowPromoteChat(CmmUInt64 /*meeting_number*/ = 0) {}

  // ── Connected ZApps ──────────────────────────────────────────────────────
  // Returns 0 on non-ZAPP builds / platforms without ZApp support.
  virtual int GetUnhandledConnectedZappQuantity() { return 0; }
};

#endif  // I_IPC_EVENT_HANDLER_PLATFORM_DELEGATE_H
