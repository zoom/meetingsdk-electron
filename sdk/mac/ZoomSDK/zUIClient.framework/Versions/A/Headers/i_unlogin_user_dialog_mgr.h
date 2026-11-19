#ifndef I_UNLOGIN_USER_DIALOG_MGR_H
#define I_UNLOGIN_USER_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include <string>
#include "zPTApp/SaasBeePTAppInterface.h"  // RequestMarketingDialogInfoParam
#include "zPTApp/PTService/IPTZoomConfService.h"  // Leave_Reason

// Pure C++ model structs — assembled by the platform from
// RequestMarketingDialogInfoParam / ZMCallUpgradeDialogInfo and passed
// to CheckAndShowDialog().
struct UnloginUserDialogButtonInfo {
  std::string text;
  std::string link;
};

struct UnloginUserDialogModel {
  // Window title — derived from Leave_Reason by the caller before Show().
  std::string title;

  std::string header;
  std::string body;
  std::string notice_id;

  // CTA buttons (Sign Up / Sign In). Either or both may be empty.
  UnloginUserDialogButtonInfo primary;
  UnloginUserDialogButtonInfo secondary;

  // Visibility / style flags. When only secondary is visible it should be
  // promoted to primary visual style.
  bool primary_visible = true;
  bool secondary_visible = true;
  bool secondary_use_primary_style = false;

  // Optional marketing image paths (light / dark theme).
  std::string light_image_path;
  std::string dark_image_path;
};

// Platform-specific side-effects for the unlogin-user post-meeting dialog.
// All methods provide empty default implementations.
class IUnloginUserDialogPlatformDelegate
{
public:
  virtual ~IUnloginUserDialogPlatformDelegate() = default;

  // Primary button click (typically Sign Up). |link| is the raw link from
  // the OP model (e.g. "1", an HTTP URL, or a zoomus:// deeplink).
  virtual void OnPrimaryClicked(const std::string& /*link*/) {}

  // Secondary button click (typically Sign In).
  virtual void OnSecondaryClicked(const std::string& /*link*/) {}

  // User closed the dialog without clicking any CTA.
  virtual void OnClosed() {}

  // ISO 3166-1 alpha-2 country code (e.g. "US"). Empty falls back to
  // IP-based geo on the server side.
  virtual std::string GetGeoName() const { return ""; }

  // True if |link| is a platform deep-link (e.g. zoomus:// router URL).
  // Mirrors PageDeepLinkHandler::IsDeepLink on Windows.
  virtual bool IsDeepLink(const std::string& /*link*/) const { return false; }

  // True if the deep-link requires CMC channel/meeting parameters to be
  // appended before navigation. Mirrors PageDeepLinkHandler::IsNeedJumpToCMC.
  virtual bool IsNeedJumpToCMC(const std::string& /*link*/) const { return false; }
};

// Manages the lifecycle of the unlogin-user post-meeting registration dialog:
// OP data request, caching, display, and dismissal.
// Accessible via IPTMgrHub::GetLeaveMeetingMgrHub()->GetUnloginUserDialogMgr().
class ZUIClient_API IUnloginUserDialogMgr
{
public:
  virtual ~IUnloginUserDialogMgr() = default;

  virtual void Init()   = 0;
  virtual void Uninit() = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IUnloginUserDialogPlatformDelegate* delegate) = 0;

  // Checks all conditions (non-empty OP content, IsCanShowUnauthenticatedWnd,
  // non-empty leave_meeting_number) and shows the dialog if all pass.
  // Returns true if shown (or already showing).
  virtual bool CheckAndShowDialog(Leave_Reason leave_reason) = 0;

  // Re-show if created but hidden (e.g. occluded by the login window).
  virtual void CheckNeedShowDialog() = 0;

  virtual void DismissDialog() = 0;

  // Cache the current meeting ID; used to gate CheckAndShowDialog.
  virtual void SetLeaveMeetingNumber(const Cmm::CString& meeting_number) = 0;

  // Increment leave-meeting counter for Normal/EndedByMyself/EndedByHost/
  // FreeMeetingTimeout. Skipped when user is currently logged in.
  virtual void UpdateLeaveMeetingCount(CmmInt32 leave_reason) = 0;

  // Fire GetNoAuthNumberOfMeetingsV2 if needed. Clears cached OP data first.
  virtual void RequestNoAuthLeaveMeetingDialogInfo() = 0;

  // Store server response
  virtual void SetUnLoginDialogInfo(const RequestMarketingDialogInfoParam& response) = 0;

  virtual const RequestMarketingDialogInfoParam& GetUnloginUserDialogInfo() const = 0;

  // True when cached OP data has non-empty header and body.
  virtual bool HasValidDialogContent() const = 0;
};

#endif  // I_UNLOGIN_USER_DIALOG_MGR_H
