#ifndef I_LEAVE_MSG_DIALOG_MGR_H
#define I_LEAVE_MSG_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include <string>

class ZUIClient_API ILeaveMsgDialogMgr
{
public:
  virtual ~ILeaveMsgDialogMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Show the ZUI leave-message dialog.
  // meeting_info is the string received from the PT side via IPC_SENDFEEDBACK_KEY;
  // it is appended to the feedback string on submit.
  virtual void ShowLeaveMsgDialog(const std::string& meeting_info) = 0;
  virtual void DismissLeaveMsgDialog() = 0;
  virtual bool IsLeaveMsgDialogShowing() const = 0;
  virtual void BringLeaveMsgDialogToTop() = 0;
};

#endif  // I_LEAVE_MSG_DIALOG_MGR_H
