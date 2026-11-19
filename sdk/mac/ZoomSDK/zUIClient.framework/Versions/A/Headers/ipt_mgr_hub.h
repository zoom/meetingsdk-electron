#ifndef IPT_MGR_HUB_H
#define IPT_MGR_HUB_H

#include "zUI_stdafx.h"
#include <memory>

class IPTDialogHub;
class IZUILoginMgr;
class ILeaveMeetingMgrHub;

class ZUIClient_API IPTMgrHub
{
public:
  virtual ~IPTMgrHub() = default;

  // PT Dialog Hub APIs
  virtual void Init() = 0;
  virtual void Uninit() = 0;
  virtual IPTDialogHub* GetPTDialogHub() = 0;

  // Login Manager API
  virtual IZUILoginMgr* GetLoginMgr() = 0;

  // Post-meeting / leave-meeting dialog managers + IPC handler, grouped behind a
  // dedicated sub-hub so IPTMgrHub stays focused on top-level concerns.
  virtual ILeaveMeetingMgrHub* GetLeaveMeetingMgrHub() = 0;
};

#endif // IPT_MGR_HUB_H
