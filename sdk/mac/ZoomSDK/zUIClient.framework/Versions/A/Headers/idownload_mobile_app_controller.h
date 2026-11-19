#ifndef IDOWNLOAD_MOBILE_APP_CONTROLLER_H
#define IDOWNLOAD_MOBILE_APP_CONTROLLER_H

#include "zUI_stdafx.h"

class ZUIClient_API IDownloadMobileAppController
{
public:
  virtual ~IDownloadMobileAppController() = default;

  // Dialog management APIs
  virtual void ShowDialog(void* parent = nullptr) = 0;
  virtual void HideDialog() = 0;
  virtual void CloseDialog() = 0;
  virtual bool IsDialogVisible() = 0;
  virtual void* GetNativeDialogHandle() = 0;
};

#endif // IDOWNLOAD_MOBILE_APP_CONTROLLER_H
