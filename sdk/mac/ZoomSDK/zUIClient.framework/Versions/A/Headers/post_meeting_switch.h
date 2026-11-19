#pragma once

// ---------------------------------------------------------------------------
// ZOOM-1174058 post-meeting dialog refactor — runtime gate.
// ---------------------------------------------------------------------------

#include "cmmlib/zp_client_consts.h"
#include "cmmlib/IFeatureToggleProvider.h"
#include "zPTApp/PTService/PTServiceHelper.h"
#include "zPTApp/PTService/IPTAccountService.h"
#include "zPTApp/PTService/zPTServiceIDs.h"

namespace zui {

inline bool IsZuiPostMeetingEnabled()
{
  auto account_service = GET_PT_SERVICE(IPTAccountService, zPTServiceID_Account);
  if (account_service == nullptr)
    return false;

  const bool is_logged_in = account_service->CanAccessZoomWebservice() == CmmTrue;
  Cmm::CAString str_value = "false";
  if (is_logged_in) {
    Cmm::QueryFeatureToggle(ENABLE_ZUI_POST_MEETING, "web", str_value);
  }
  else {
    str_value = CMM_T2UTF(account_service->GetConfigSettings(_T(ENABLE_ZUI_POST_MEETING)));
  }
  return str_value.CompareNoCase("true") == 0;
}

}  // namespace zui
