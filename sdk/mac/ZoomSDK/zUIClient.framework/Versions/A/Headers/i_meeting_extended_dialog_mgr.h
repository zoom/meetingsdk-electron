#ifndef I_MEETING_EXTENDED_DIALOG_MGR_H
#define I_MEETING_EXTENDED_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include <string>

// Manages the ZUI "Meeting Extended" dialog.
// Replaces CMeetingExtendedWnd (Win) and ZMExtendMeetingEndAlertPanel (Mac).
class ZUIClient_API IMeetingExtendedDialogMgr
{
public:
  virtual ~IMeetingExtendedDialogMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Show the meeting-extended dialog. If already visible, closes old
  // and reopens with new data.
  //   duration_secs  — elapsed meeting time (rounded up to minutes)
  //   expire_date    — credits expiry date string (pre-formatted)
  //   upgrade_url    — URL to open when user clicks Upgrade
  //   credits_all    — total BP credits
  //   credits_remain — remaining credits after this meeting
  virtual void ShowMeetingExtendedDlg(unsigned int duration_secs,
                                      const std::string& expire_date,
                                      const std::string& upgrade_url,
                                      unsigned int credits_all,
                                      unsigned int credits_remain) = 0;

  virtual void DismissDialog() = 0;
  virtual bool IsDialogShowing() const = 0;
};

#endif  // I_MEETING_EXTENDED_DIALOG_MGR_H
