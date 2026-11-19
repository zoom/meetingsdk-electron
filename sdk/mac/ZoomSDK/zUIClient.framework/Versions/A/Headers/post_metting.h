#ifndef POST_MEETING_MODEL_H
#define POST_MEETING_MODEL_H

#include "zUI_stdafx.h"
#include "zui_client_data_define.h"

constexpr int kPostMeetingMaxShownAvatarCount = 8;

struct MeetingInfo
{
  zui::State<std::string> title;
  zui::State<std::string> date_time;
  zui::State<std::vector<zui::AvatarGroup::AvatarData>> participants;
  zui::State<int> maxShowAvatarCount = kPostMeetingMaxShownAvatarCount;
  zui::State<std::string> summary_text;
  zui::State<int> inviteesCount = 0;

  bool operator==(const MeetingInfo& other) const
  {
    return title == other.title &&
      date_time == other.date_time &&
      participants == other.participants &&
      maxShowAvatarCount == other.maxShowAvatarCount &&
      summary_text == other.summary_text;
  }
};

class ZUIClient_API CPostMeetingPopupModel : public IInitializable
{
public:
  CPostMeetingPopupModel();
  virtual ~CPostMeetingPopupModel() = default;
  /*virtual*/ void initializeState() override;
  /*virtual*/ void initializeStateHandler() override;

  void ShowDialog(void* parent = nullptr);
  void HideDialog();
  void CloseDialog();
  bool IsDialogVisible();
  void* GetNativeDialogHandle();
  void MakeKey();

  NS_ZOOM_MESSAGER::IZoomMessenger* GetZoomMessengerHelper();
  void UpdateAvatarInfo(CmmBool is_need_refresh);
  ISBMeetingItem* GetMeetingItem();
  CString GetJIDFromUserID(const CString& user_id);
  CString GetAvatarPathByUserID(const CString& str_jid);
  
  void NavigateWorkflowUrl();

public:
  zui::State<std::string> _title;
  MeetingInfo _meetingInfo;
  TextProperty _timerText;
  CheckBoxProperty2 _dontShowAgainProperty;
  zui::State<bool> _coachMarkVisible = true;
  BtnProperty2 _secondaryBtn;
  BtnProperty2 _primaryBtn;

  zui::State<bool> _isLoggedIn = true;
  zui::State<std::string> _unLoggedText;
  CString _workflowUrl;
  zui::State<std::vector<std::string>> _workflowImages;

  zui::State<bool> _iconAttachmentVisible = false;
  zui::State<bool> _iconFilmv2Visible = false;
  zui::State<bool> _iconSmartSummaryVisible = false;
  zui::State<bool> _iconRepeatVisible = false;
  zui::State<bool> _iconFlowVisible = false;

  // Event callbacks
  std::function<void()> _onClosedClicked;
  std::function<void(bool)> _onDontShowAgainChanged;

  MeetingAssetsInfo _meeting_assets_info;
  std::vector<CString> _vec_surcribe_ids;
  std::vector<MeetingInviteeParams> _vec_plist;
private:
  std::shared_ptr<zui::ZUIWindow> _dialog;
};

#endif
