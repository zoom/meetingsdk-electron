#ifndef I_ALERT_DIALOG_MGR_H
#define I_ALERT_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include <string>

// Platform-specific side-effects for PTAlertDialogMgr.
// All methods provide empty default implementations so platforms without
// post-meeting refactor enabled compile cleanly.
class IPTAlertDialogPlatformDelegate
{
public:
  virtual ~IPTAlertDialogPlatformDelegate() = default;

  // Connected-ZApp count used by ShowConfEndedByHostWithZappsDlg to decide
  // whether to offer the "Close all my connected apps" checkbox.
  virtual int GetConnectedZappCount() { return 0; }

  // OK click on Cmd_ConfHostAction dialogs (close_zapps reflects the
  // optional checkbox; false when the dialog has no checkbox).
  virtual void OnConfHostActionOkClicked(bool /*close_zapps*/) {}

  // OK click (or auto-fire) on Cmd_ConfAutoEndForInactivity dialogs.
  // no_auto_end reflects the "Do not automatically end" checkbox.
  virtual void OnConfAutoEndForInactivityOkClicked(bool /*no_auto_end*/) {}
};

// Manages the ZUI AlertDialogView for leave-meeting notification dialogs.
// Replaces CMessageDlgEx + MessageWnd.xml for the leave-meeting cases
// previously handled by SBWndContainer::ShowConf*Dlg().
class ZUIClient_API IPTAlertDialogMgr
{
public:
  virtual ~IPTAlertDialogMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Conf-ended dialogs (Cmd_ConfHostAction, 6s countdown).
  virtual void ShowConfEndedByHostDlg() = 0;
  virtual void ShowConfEndedByHostStartAnotherMeetingDlg() = 0;
  virtual void ShowConfEndedByAdminDlg() = 0;
  virtual void ShowConfEndedByNoneDlg() = 0;
  virtual void ShowConfEndedSimuliveFinish() = 0;
  virtual void ShowConfExpelledByHostDlg() = 0;
  virtual void ShowConfExpelledByWebinarHostDlg() = 0;
  virtual void ShowConfEndedJBHTimeoutDlg() = 0;
  virtual void ShowAttendeesWebinarEndedByTimeoutDlg() = 0;

  // No countdown, Cmd_ConfHostAction.
  virtual void ShowConfEndedSimuliveTimeout() = 0;
  virtual void ShowConfEndedMoreThan1MeetingDlg(const std::string& meeting_number) = 0;
  virtual void ShowConfEndedMoreThan1MeetingJBHDlg(const std::string& meeting_number) = 0;
  virtual void ShowConfEndedFreeMeetingTimeoutDlg() = 0;
  virtual void ShowPPMEarlyEndDlg() = 0;

  // Cmd_Unknow, 5-second countdown.
  virtual void ShowAutoAssignParticipantToWaitingRoomDlg() = 0;

  // Without-attendee pair (Cmd_ConfAutoEndForInactivity, with checkbox).
  virtual void ShowConfEndedWithoutAttendeeDlg() = 0;
  virtual void ShowWebinarEndedWithoutAttendeeDlg() = 0;

  // Meeting archiving failed. is_host selects host/attendee title variant.
  virtual void ShowMeetingArchivingFailedDlg(bool is_host, CmmUInt64 archiving_option) = 0;

  virtual void DismissAlertDialog() = 0;
  virtual bool IsAlertDialogShowing() const = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IPTAlertDialogPlatformDelegate* delegate) = 0;
};

#endif  // I_ALERT_DIALOG_MGR_H
