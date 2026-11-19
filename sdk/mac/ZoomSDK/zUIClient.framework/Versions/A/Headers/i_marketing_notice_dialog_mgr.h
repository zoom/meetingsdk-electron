#ifndef I_MARKETING_NOTICE_DIALOG_MGR_H
#define I_MARKETING_NOTICE_DIALOG_MGR_H

#include "zUI_stdafx.h"
#include "zUIClient/marketing_notice_types.h"  // MarketingNoticeDialogType
#include <string>

// Cross-platform, std::string-based version of RequestMarketingDialogInfoParam.
struct MarketingNoticeInfo {
  std::string notice_id;
  std::string header;
  std::string body;
  struct ButtonInfo {
    std::string text;
    std::string link;
  };
  ButtonInfo  primary_cta;
  ButtonInfo  secondary_cta;
  std::string light_image_path;  // local path; empty = no dynamic image
  std::string dark_image_path;   // local path; empty = no dynamic image
  std::string video_image_url;   // preview thumbnail; empty if no video
  std::string video_url;         // local video path; empty if no video

  // Only set for MarketingDialog_on_click; empty otherwise.
  std::string bottom_text;
};

// Platform-specific side-effects and data access for MarketingNoticeDialog.
// All methods provide empty default implementations.
class ZUIClient_API IMarketingNoticeDialogPlatformDelegate
{
public:
  virtual ~IMarketingNoticeDialogPlatformDelegate() {}

  // Open a URL in the system browser.
  virtual void OnJumpToBrowser(const std::string& /*url*/) {}

  // Announce accessibility notification text.
  virtual void OnAccNotifyAlert(const std::string& /*msg*/) {}

  // Primary/Secondary CTA was clicked but has no URL — platform decides.
  virtual void OnPrimaryCTAWithoutLink(MarketingNoticeDialogType /*type*/) {}
  virtual void OnSecondaryCTAWithoutLink(MarketingNoticeDialogType /*type*/) {}

  // Retrieve cached PBX marketing dialog info; returns false if unavailable.
  virtual bool GetPBXDialogInfo(MarketingNoticeDialogType /*type*/,
                                MarketingNoticeInfo& /*out_info*/) { return false; }
};

// Manages the ZUI Marketing Notice (Phone Upgrade) dialog.
// Replaces CPTMarketingNoticeHelper + CMarketingNoticeManager (Win-client).
class ZUIClient_API IMarketingNoticeDialogMgr
{
public:
  virtual ~IMarketingNoticeDialogMgr() {}

  virtual void Init()   = 0;
  virtual void Uninit() = 0;

  // Show the dialog. If on_click or post_after_meeting is already visible,
  // skips (they are mutually exclusive).
  virtual void ShowMarketingNoticeDialog(MarketingNoticeDialogType type) = 0;

  virtual void CloseMarketingNoticeDialog(MarketingNoticeDialogType type) = 0;

  // Update content of an already-visible dialog (e.g. on theme change).
  virtual void UpdateMarketingNoticeDialog(MarketingNoticeDialogType type) = 0;

  // Returns true if this type (or its mutual-exclusion partner) is shown.
  virtual bool IsMarketingNoticeDialogShown(MarketingNoticeDialogType type) = 0;

  // gift_cnt is only meaningful for MarketingDialog_post_meeting_limit_dialog.
  virtual bool IsNeedShowMarketingNoticeDialog(MarketingNoticeDialogType type,
                                               unsigned int gift_cnt = 0) = 0;

  // Delegate lifetime must exceed that of this manager.
  virtual void SetPlatformDelegate(IMarketingNoticeDialogPlatformDelegate* delegate) = 0;
};

#endif  // I_MARKETING_NOTICE_DIALOG_MGR_H
