#pragma once

#include <chrono>
#include <cstdint>
#include "zPTApp/SaasBeePTAppInterface.h"  // brings in NS_ZOOM_DATA::UnLimitedMeetingNoticeInfo + CString

// Cross-platform mirror of Win MeetingGiftData (chat_defines.h).
// Populated by ZUIMeetingStatusObserver on PT_EVENT_ON_CALLSTATUSCHANGE / ConfState_OnCall.
// Lives in common/include/zUIClient/ to remain platform-agnostic.
struct MarketingMeetingStatusData {
  MarketingMeetingStatusData()
    : is_webinar(false)
    , is_upgrade_from_sip(false)
    , is_host(false)
    , is_save_time(false)
    , meeting_start_time(MAX_INT32_VAL) {
    str_meetingID.clear();
  }

  // Monotonic seconds since an unspecified epoch. Use this (NOT clock()) to
  // stamp/measure elapsed meeting time: steady_clock measures real wall-clock
  // elapsed time and is immune to system-time adjustments, whereas clock()
  // returns process CPU time on POSIX (it would massively under-count an
  // idle-waiting meeting).
  static int64_t NowSteadySecs() noexcept {
    return std::chrono::duration_cast<std::chrono::seconds>(
      std::chrono::steady_clock::now().time_since_epoch())
      .count();
  }

  void Clear() {
    is_webinar = false;
    is_upgrade_from_sip = false;
    is_host = false;
    is_save_time = false;
    str_meetingID.clear();
    meeting_start_time = MAX_INT32_VAL;
    info.title_.clear();
    info.description_.clear();
    info.btn_text_.clear();
    info.has_url_ = CmmFalse;
    info.btn_url_.clear();
    info.notice_id_.clear();
  }

  bool         is_upgrade_from_sip = false;  // true if meeting was upgraded from a SIP call
  bool         is_host             = false;  // true if the local user is the meeting host
  bool         is_webinar          = false;  // true if this is a webinar meeting
  bool         is_save_time        = false;  // true if meeting start time should be cached (SIP host)
  int64_t      meeting_start_time  = MAX_INT32_VAL;      // NowStea() value at meeting start; valid only if is_save_time
  Cmm::CString str_meetingID;               // active meeting ID (needed by post-meeting dialogs)
  NS_ZOOM_DATA::UnLimitedMeetingNoticeInfo info;  // unlimited-meeting notice data from server
};
