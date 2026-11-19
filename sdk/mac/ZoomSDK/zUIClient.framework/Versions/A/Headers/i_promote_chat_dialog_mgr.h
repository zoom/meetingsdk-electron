#ifndef I_PROMOTE_CHAT_DIALOG_MGR_H
#define I_PROMOTE_CHAT_DIALOG_MGR_H

#include "zUI_stdafx.h"

// Platform-specific side-effects for the "Promote Chat After Meeting" dialog.
// All methods provide empty default implementations.
class ZUIClient_API IPromoteChatDialogPlatformDelegate
{
public:
  virtual ~IPromoteChatDialogPlatformDelegate() {}

  // Navigate to chat UI and record the FTE option.
  virtual void OnStartChatClicked() {}
};

// Manages the ZUI "Promote Chat After Meeting" modal dialog.
// Replaces CPromoteChatAfterMeetingWnd (Win) and ZMPromoteChatWindow (Mac).
class ZUIClient_API IPromoteChatDialogMgr
{
public:
  virtual ~IPromoteChatDialogMgr() {}

  virtual void Init() = 0;
  virtual void Uninit() = 0;

  // Show the promote-chat modal. Brings to front if already showing.
  virtual void ShowPromoteChatDlg() = 0;

  virtual void DismissDialog() = 0;
  virtual bool IsDialogShowing() const = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IPromoteChatDialogPlatformDelegate* delegate) = 0;
};

#endif  // I_PROMOTE_CHAT_DIALOG_MGR_H
