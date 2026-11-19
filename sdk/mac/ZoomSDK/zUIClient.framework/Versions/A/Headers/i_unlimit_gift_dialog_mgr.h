#ifndef I_UNLIMIT_GIFT_DIALOG_MGR_H
#define I_UNLIMIT_GIFT_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include "dataModule/zDataConstants.h"  // BilledType
#include <string>

// Platform-specific navigation side-effects for the "Free Meeting Gift" dialog.
// SnowPlow event tracking is handled internally by the manager.
// All methods provide empty default implementations.
class ZUIClient_API IUnlimitGiftDialogPlatformDelegate
{
public:
  virtual ~IUnlimitGiftDialogPlatformDelegate() {}

  // Open upgrade URL (PT_NAV_BUY) in the default browser.
  virtual void OnNavigateToBuyUrl(const std::string& /*url*/) {}

  // Open a user-specified URL (PT_NAV_USER_SPECIFIED) in the default browser.
  virtual void OnNavigateToUserUrl(const std::string& /*url*/) {}

  // Open the secondary CTA URL (Mac ZMGiftV2Panel secondary button).
  virtual void OnNavigateToSecondaryUrl(const std::string& /*url*/) {}

  // Open the schedule-meeting window (gift_cnt==1 "Schedule a Meeting" CTA).
  virtual void OnOpenScheduleMeeting() {}
};

// Manages the ZUI "Free Meeting Gift" and "PPM Post-Meeting" dialogs.
// Replaces CUnlimitedGroupMeetingWnd (Win), ZMGiftPanel/ZMGiftV2Panel (Mac),
// and QML GiftDialog (Linux).
class ZUIClient_API IUnlimitGiftDialogMgr
{
public:
  virtual ~IUnlimitGiftDialogMgr() {}

  virtual void Init()   = 0;
  virtual void Uninit() = 0;

  // Show the gift dialog after a free meeting ends.
  //   gift_cnt      — free meetings used (1, 2, >=3; 0 = UnUpgrade)
  //   upgrade_url   — URL for the Upgrade CTA
  //   in_meeting_url — source URL; PPM early-return when it contains
  //                    "zonemext" or "zonemextp"
  // Reopens if already visible.
  virtual void Show(CmmUInt32 gift_cnt,
                    const std::string& upgrade_url,
                    const std::string& in_meeting_url) = 0;

  // Show the PPM post-meeting dialog (is_ppm_extended scenario).
  //   elapsed_time_secs — meeting duration (displayed as minutes)
  virtual void ShowPPM(CmmUInt32 elapsed_time_secs) = 0;

  virtual bool IsShown() const noexcept = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IUnlimitGiftDialogPlatformDelegate* delegate) = 0;
};

#endif  // I_UNLIMIT_GIFT_DIALOG_MGR_H
