#pragma once

// Cross-platform enum definitions for the Marketing Notice (Phone Upgrade) dialog.
// Shared by both win-client (MarketingNoticeDef.h) and client-zui (i_marketing_notice_dialog_mgr.h).
// Keep this header dependency-free so it can be included from any layer.

enum MarketingNoticeDialogType {
  MarketingDialog_unknown                    = -1,
  MarketingDialog_on_click                   = 0,
  MarketingDialog_post_after_meeting         = 1,
  MarketingDialog_in_meeting_limit_dialog    = 2,
  MarketingDialog_post_meeting_limit_dialog  = 3,
};

enum class MarketingDialogTrackingType {
  type_show,
  type_click_primary,
  type_click_secondary,
  type_click_close,
};
