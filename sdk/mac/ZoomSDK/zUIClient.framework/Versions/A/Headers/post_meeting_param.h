#ifndef POST_MEETING_PARAM_H
#define POST_MEETING_PARAM_H

#include "zUI_stdafx.h"
#include <string>
#include <vector>
#include "commonDef/CmmCommonStruct.h"  // MeetingAssetsInfo, MeetingInviteeParams

// Cross-platform parameter struct passed to IPostMeetingAssetMgr::Show*Wnd.
// All string fields are pre-converted to UTF-8 std::string by the caller.
// Date/time is pre-formatted by the caller (platform-native formatting).
struct PostMeetingParam {
  bool        is_host             = false;
  bool        is_recurring_meeting = false;   // drives _iconRepeatVisible
  std::string meeting_topic;                  // UTF-8
  std::string formatted_date_time;            // pre-formatted: "Mon, Jan 1 10:00 - 11:00"
  int         invitees_count      = 0;

  MeetingAssetsInfo                 assets_info;
  std::vector<MeetingInviteeParams> invitees;

  void clear() {
    is_host = false;
    is_recurring_meeting = false;
    meeting_topic.clear();
    formatted_date_time.clear();
    invitees_count = 0;
    assets_info = MeetingAssetsInfo{};
    invitees.clear();
  }
};

#endif  // POST_MEETING_PARAM_H
