#ifndef IPT_DIALOG_HUB_H
#define IPT_DIALOG_HUB_H

#include "zUI_stdafx.h"

#include "idownload_mobile_app_controller.h"
#include "iversion_dialog_controller.h"

class ZUIClient_API IPTDialogHub
{
public:
  virtual ~IPTDialogHub() = default;

  // DownloadMobileApp Controller APIs
  virtual IDownloadMobileAppController* GetDownloadMobileAppController() = 0;
  virtual IVersionDialogController* GetVersionDialogController() = 0;

  virtual void CloseAllDialogWhenLogout() = 0;
};

#endif // IPT_DIALOG_HUB_H
