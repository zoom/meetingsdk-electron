#ifndef _SETTING_PANEL_MEETING_H_
#define _SETTING_PANEL_MEETING_H_

#ifdef _WIN32
#include "zUI/view.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "zUI_stdafx.h"
#endif

#ifdef ENABLE_ZAPP
#include "zApp/ZappBase.h"
#endif // ENABLE_ZAPP

#if (defined BUILD_FOR_VDI) && (defined WIN32)
#include "vdi/util/VdiHelper.h"
#endif
#include "zUIClient/zui_client_data_define.h"
#include "cmmlib/CmmEmojiReactionDefine.h"

class ZUIClient_API CMeetingSettingDataModel : public IInitializable
{
public:

  static CMeetingSettingDataModel& GetInstance();
  static void ReleaseInstance();
  
  CMeetingSettingDataModel();
  ~CMeetingSettingDataModel();

  // overall page

  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

  zpref::zPolicyIds GetPolicyIds();
  void OnPolicyUpdated(zpref::zPolicyId policeId);
  
public:
#ifdef ENABLE_ZAPP
  bool IsZoomAppSelected();
  void SwitchToZoomAppItem();
  void UpdateAppsItemShowState(NS_ZOOM_APPS::ZappEnableState pt_state);
  void OnManageApps(bool is_from_manage_app = false);
  void SetSelectedZoomApps(const std::vector<zui::any>& newData);
  void MarkCallbackDataReceived(bool hasReceived);
#endif // ENABLE_ZAPP
  void UpdateDisplayPreviewWhenJoinMeeting();
  void UpdateAutoJoinVOIP();
  void UpdateWindowModeControls();
  void UpdateDualModeSettingValue(bool is_enable_dual_stream);
  void UpdateShowMeetingTimers();
  void UpdateAlwaysShowToolbarUI();
  void UpdateAlwayDisplayParticipantName();
  void UpdateShowNoVideoParticipants();
  void UpdateOpenSelectedZoomApps();

#ifdef ENABLE_ZAPP
  void GetOpenSelectedZoomApps(int& selected, int& web_selected,  int& count);
  void UpdateAppItemChecked(const std::string& app_id, NS_ZOOM_APPS::AutoOpenSettingType type);
  void OnIconDownloaded(const CString& app_id, const CString& icon_path);
#endif

  void RefreshStopIncomingVideo();
  void RefreshHandGestureRecognitionSetting();
  void RefreshAnimateEmojisSetting();
  void RefreshRaiseHandChimeSetting();
  void UpdateResetDisclaimerUI();
  void UpdatePersonalWallpaperVisibility();
  void UpdateAllowedUnmuteAudiolistPanel();
  void UpdatePerformancePanel();
  void UpdateNotAutoEndInactiveMeeting();
  
  void UpdateHideMyVideoUI();
  void UpdateSelfViewDisplayModeUI();
  void UpdateHideNoVideoUI();
#if (defined BUILD_FOR_VDI) && (defined WIN32)
  bool IsVDISupportDualMonitor();
  ns_vdi::IVdiPluginCapacity* GetVDIPluginCapacity();
  void ApplyVDIHardwareAccelConstraints();
  void ApplyVDIVideoControlConstraints();
#endif
  void UpdateAutoStartMyNotes();
public:
  SwitchControl _showVideoPreview;
  SwitchControl _keepMyCameraOff;
  SwitchControl _muteMyMicro;
  SwitchControl _autoJoinAudio;
  SwitchControl _enterFullScreenAuto;
  SwitchControl _autoStartMyNotes;

  zui::State<bool> _showManageSelectedApps = false;
  zui::State<bool> _showSelectedZappOverview = true;

  enum class MeetingWindowsView {
    kSingleWindowWithTbas,
    kDualWindow
  };
  RadioGroupProperty _meetingWindowView;

  SwitchControl _useDualMonitors;
  SwitchControl _keepParticipantNamesVisible;
  SwitchControl _showMeetingTimer;
  SwitchControl _showParticipantProfilePicInChat;
  SwitchControl _showPMIOnMeetingTab;
  
  SwitchControl _keepMeetingControlsVisible;
  SwitchControl _useSpaceBarToMute;
  SwitchControl _playSoundForMuteUnmute;
  SwitchControl _copyInviteLinkToClipboard;

  BtnProperty _whoCanUnmuteYou;

  SwitchControl _hideSelfView;

  // Values match NS_ZOOM_DATA::CmmSelfViewMode so the selection can be handed
  // straight to MeetingUIHelper::SetSelfViewMode. CmmSelfViewMode::Minimized (3)
  // has no radio of its own and folds into kCollapseSelfView -- see
  // UpdateSelfViewDisplayModeUI.
  enum class SelfViewDisplayMode
  {
    kShowInGallery = 0,
    kHideSelfView = 1,
    kCollapseSelfView = 2,
  };
  RadioGroupProperty _selfViewDisplayMode;

  SwitchControl _showMeAsActiveSpeaker;
  SwitchControl _stopVideoWhenComputerLocks;

  SwitchControl _showNoVideoParticipants;

  zui::State<bool> _wallpaperVisible = true;
  zui::State<bool> _showPersonalWallpaper = false;
  zui::State<bool> _showAdvancedButton = true;
  zui::State<std::string> _personalWallpaper;
  
  enum class MaxParticipantsPerScreen
  {
    k25Participants,
    k49Participants
  };
  RadioGroupProperty _maxParticipantsPerScreen;

  SwitchControl _showReactionsAboveToolbar;
  SwitchControl _animateEmojis;
  SwitchControl _useHandGestures;
  SwitchControl _palyChimeWithHandRaise;
  
  SwitchControl _showLeaveConfConfirmation;
  SwitchControl _keepMyZAppsOpen;

  SwitchControl _showStopIncomingVideo;
  SwitchControl _skipAudioPromptsInThirdPartMeetings;
  BtnProperty _resetMeetingDisclaimer;
  zui::State<bool> _advancedMeetingVisible = true;

  SwitchControl _optimzieIncomingVideoQuality;
  SwitchControl _optimizeOutgoingVideoQuality;

  DropDownProperty _videoRenderingMethod;
  DropDownProperty _videoRenderingPostProcessing;
  DropDownProperty _videoCaputringMethod;

  SwitchControl _hardwareAcceForRecvVideo;
  SwitchControl _hardwareAcceForSendVideo;
  SwitchControl _hardwareAcceForVideoProcessing;
  SwitchControl _hardwareAcceForVB;

  zui::State<bool> _showAdvanced = false;
  zui::State<std::string> _animateEmojisClap;
  zui::State<std::string> _animateEmojisThumbsUp;

#ifdef ENABLE_ZAPP
  struct AppData
  {
    std::string icon;
    std::string name;
    std::string app_id;
    NS_ZOOM_APPS::AutoOpenAppInfoForUI auto_open_app_info;

    bool operator==(const AppData& other) const{
      return icon == other.icon 
        && name == other.name
        && auto_open_app_info.appId == other.auto_open_app_info.appId
        && auto_open_app_info.isFromWeb == other.auto_open_app_info.isFromWeb
        && auto_open_app_info.isLocked == other.auto_open_app_info.isLocked
        && auto_open_app_info.showType == other.auto_open_app_info.showType
        && auto_open_app_info.webType == other.auto_open_app_info.webType;
    }
  };
#endif
  zui::State<std::vector<zui::any>> _selectedZoomApps;
  zui::State<std::string> _selectedZoomAppsText = std::string("Selected(0/0)");
  zui::State<bool> _showSelectZoomAppsLimit = false;
  zui::State<bool> _hasReceivedCallbackData = false;

  zui::State<bool> _showOpenSelectedZoomApps = false;

  zui::State<std::string> _strUseSpaceBarToMute;

#ifdef _WIN32
  SwitchControl _optimizeOutgoingVideoStability;
  SwitchControl _turnOnEfficiencyMode;
  zui::State<bool> _turnOnEfficiencyModeTipVisible = false;
#endif
  SwitchControl _doNotAutoEndMeeting;

private:
  static CMeetingSettingDataModel* _instance;
  bool _ignore_update_limit_text = false;
};

class ZUIClient_API SettingPanelMeetings : public zui::CustomView<SettingPanelMeetings>
{
public:
    SettingPanelMeetings();
    ~SettingPanelMeetings() = default;

    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelMeetings>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;
};

#define MeetingPanelDataModel CMeetingSettingDataModel::GetInstance()

#endif //_SETTING_PANEL_MEETING_H_
