#ifndef _SETTING_PANEL_NOTIFICATIONS_SOUNDS_H_
#define _SETTING_PANEL_NOTIFICATIONS_SOUNDS_H_

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
#include "zVideoApp/Confdef.h"
#include "cmmlib/IZMRingtoneMgr.h"
#include <vector>
#include "zui_client_data_define.h"

class ZUIClient_API IRingtonePlayer
{
public:
  virtual bool StartPlayRingtone(const Cmm::CString& file_path, CmmUInt32& handle, FLOAT volume) = 0;
  virtual bool StopPlayRingtone(CmmUInt32 handle) = 0;
};

class ZUIClient_API CNotifSoundsSettingDataModel : public IInitializable, IRingtonePlayer
{
public:

  //enum class RING_TONE_TYPE
  //{
  //  RINGTONE_DEFAULT = 0,
  //  RINGTONE_MEETING,
  //  RINGTONE_PHONE,
  //  RINGTONE_CONTACT_CENTER,
  //  RINGTONE_CONTACT,
  //};

  enum class RingToneType
  {
    kDefault,
    kVideoCalls,
    kPhone,
    kShareLineGroup,
    kCallQueues,
    kShareLineAppearance,
    kContactCenter,
    kCustomContactRingtones,
  };

  struct CustomRingtones
  {
    std::string _name;
    int _ringType;
    bool operator==(const CustomRingtones& other) const
    {
      return _name == other._name && _ringType == other._ringType;
    }
  };

  struct OsRecordingAppItem
  {
    std::string _key;
    std::string _name;
    bool _inBlacklist = false;
    bool _visible = true;
    bool _enable = true;

    bool operator==(const OsRecordingAppItem& other) const
    {
      return _key == other._key && _name == other._name && _inBlacklist == other._inBlacklist && _visible == other._visible && _enable == other._enable;
    }
  };

  zui::State<std::vector<zui::any>> _customRingtones;
  zui::State<bool> _isShowEmpyCustomRingTones = true;
  zui::State<std::string> _ringToneResourcePathForMac;   // only for mac

  static CNotifSoundsSettingDataModel& GetInstance();
#ifdef __MACOS__
  static CNotifSoundsSettingDataModel* GetInstanceIfExists();
#endif
  
  // Release singleton instance to avoid crash during DLL unload
  // Safe to call or not call - if not called, memory is reclaimed on process exit
  static void ReleaseInstance();
  
  CNotifSoundsSettingDataModel();
  ~CNotifSoundsSettingDataModel();

  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

  bool IsEnableZoomCCI();
  void GetRingToneInfo(std::vector<ZoomRingtone::RingtoneData>& ringtone_list);
  CString GetRingtonesFromCache(CNotifSoundsSettingDataModel::RingToneType type, const CString& phone_number = _T(""));

  void UpdateRingtoneList();
  void UpdateRingtoneVolume();
  void UpdateCallWaitingVolume();
  void RefreshActivityCenterSetting();
  void UpdateIMTeamChatFeatures();
#ifdef __MACOS__
  void RefreshUpcomingMeetingsNotificationPermission();
#endif

  CmmBool OnAudioDeviceStatusChanged(DEVICE_CMD cmd, CmmUInt32 ret, CmmUInt32 handle);
  void OnStartPlayRingtone(const CString& filePath);
  void OnStopPlayRingtone();
  void StopRingtone();
  void OnAudioChanged(CmmUInt32 ret, CmmUInt32 handle);
  // Routes the PS path-based completion event through the legacy UI-state
  // update used by ringtone preview buttons.
  void OnRingtonePlaybackStopped(const CString& file_path);

  CmmBool SyncRingtones2db(RingToneType type, const CString& sel_ringtone, const CString& phone_number = _T(""));
  int GetSelectRingtoneIndex(RingToneType type, const std::string& phone_number = "");
  void UpdateCCIInfo();
  void SetDNDTimeIndices(int startHour, int startMinute, int endHour, int endMinute, bool notify = true);
  std::string GetSelectedDNDTimeParam();
  void GetDNDTimerParam(int& startHour, int& startMinute, int& endHour, int& endMinute);
  void DownloadRingtone();
  void OnUnSelect();
    //OS recording setting
  void UpdateOsRecordingSetting();
  void UpdateAutoDetectedVoiceBlackList(const std::string& productKey, bool enable);
  void UpdateAllAutoDetectedVoiceActivityList();

private:
  static CNotifSoundsSettingDataModel* _instance;

  void InitCCINotificationItem();
  void InitNotiticationItem();
  void InitRemindUncomingMeeting();
  void InitNewRecordingNotify();
  void InitIMNotification();
  void InitRingTone();
  void InitSilenceNotificationWhenSharing();
  
  void InitLoadRingtoneConfig();
  void InitfirstParticipantJoinControl();

  CmmBool GetOsRecordingProductBlacklist(std::map<CAString, bool>& user_settings);

  // IRingtonePlayer
  virtual bool StartPlayRingtone(const Cmm::CString& file_path, CmmUInt32& handle, FLOAT volume) override;
  virtual bool StopPlayRingtone(CmmUInt32 handle) override;

public:
  SliderControl _ringtoneVolume;
  SliderControl _callWaitingVolume = {false,true,0.0f};

  CmmUInt32 _ringtoneHandle = NULL_AUDIO_FILE_HANDLE;
#if MULTI_MEETING_PROCESS_FOR_MAC
  CString _ringtoneFilePath;
#endif

  struct RingtoneData {
    zui::State<int> _selectIndex = 0;
    zui::State<bool> _deviceChange = false;
    std::string _label;
    std::string _phoneNumber;

    bool operator==(const RingtoneData& other) const {
      return _selectIndex == other._selectIndex &&
        _deviceChange == other._deviceChange && 
        _label == other._label &&
        _phoneNumber == other._phoneNumber;
    }
  };
  bool _is_downloading_ringtone = false;
  ZoomRingtone::RingtoneData _defaultRingtone;
  zui::State<bool> _needDownload = false;
  zui::State<std::vector<ZoomRingtone::RingtoneData>> _ringtoneList;
  zui::State<std::string> _currentPlayLabel;

  RingtoneData _videoCallsRingtone;
  
  zui::State<std::vector<zui::any>> _extensionRingtones;

  zui::State<bool> _isShareLineGroupVisble = false;
  zui::State<bool> _isCallQueuesVisble = false;
  zui::State<bool> _isShareLineAppearanceVisble = false;
  zui::State<bool> _isCciRingtoneVisble = false;
  zui::State<bool> _isVDIShowRingtones = true;

  RingtoneData _shareLineGroupRingtone;
  RingtoneData _callQueuesRingtone;
  RingtoneData _shareLineAppearanceRingtone;
  RingtoneData _cciRingtone;
  zui::State<bool> _customRingtoneVisible = true;
    
  //team Chat

  SwitchControl _palyNewChatMsgSound;
  SwitchControl _palyNewEmailSound;

  zui::State<bool> _is24TimerFormat = true;
  SwitchControl _setDoNotDisturbHours;
  zui::State<int> _doNotDisturbFromIndex = 0;
  zui::State<int> _doNotDisturbToIndex = 0;

  enum HidePhoneCallType
  {
    BlockActivity,
    AlertButContinueActivity,
  };

  DropDownProperty _hidePhoneCallType = { true,true,static_cast<int>(AlertButContinueActivity) };
  SwitchControl _hidePhoneCallsDuringMeetings;
  SwitchControl _hideIncomingCallsWhileOnCall;
  SwitchControl _muteChatDuringMeetings;
  SwitchControl _openChatOnPushNotification;
  SwitchControl _showMessagePreview;
  SwitchControl _showNotificationsUntilDismissed;
  SwitchControl _silenceNotificationsWhenSharing;
   
  //Send desktop notifications for:
  enum UnComingMeetingTimeType
  {
    UnComingMeetingAtEventTime,
    UnComingMeeting1Minutes,
    UnComingMeeting2Minutes,
    UnComingMeeting5Minutes,
    UnComingMeeting10Minutes,
    UnComingMeeting15Minutes,
  };

  zui::State<int> _upcomingMeetingsTimeType = static_cast<int>(UnComingMeeting5Minutes);
  SwitchControl _upcomingMeetings;
  SwitchControl _newRecordingsAvaiable;
  SwitchControl _newChatMessage;
  SwitchControl _autoDetectedVoiceActivity;
  zui::State<unsigned int> _autoDetectedVoiceActivityAppCount = 0;
  zui::State<std::vector<zui::any>> _autoDetectedVoiceActivityList;
  zui::State<bool> _voiceNoteEnbaled = false;
  zui::State<bool> _warningBannerVisible = false;
#ifdef __MACOS__
  zui::State<bool> _upcomingMeetingsPermissionWarningVisible = false;
#endif
  enum class SystemNotifForChatMessageType {
    kAllMessages = 0,
    kDirectMessages
  };
  zui::State<int> _systemNotifForChatMessageType = static_cast<int>(SystemNotifForChatMessageType::kAllMessages);
  zui::State<unsigned int> _exceptChatChannelCount = 0;
  zui::State<unsigned int> _keywordsMentionedCount = 0;
  zui::State<unsigned int> _contactsMentionedCount = 0;
  zui::State<bool> _exceptChatChannelVisible = true;
  zui::State<bool> _keywordsMentionedVisible = true;
  zui::State<bool> _contactsMentionedVisible = true;
    
  zui::State<bool> _activityCenterEnable = true;

  SwitchControl _newEmails;

  zui::State<bool> _showActiveCenterPanel = true;
  zui::State<bool> _activityNotiForMeetingRecordingReady;
  zui::State<bool> _activityNotiForMeetingTransReady;
  zui::State<bool> _activityNotiForMeetingMissedCalls;

  zui::State<bool> _isShowIncomingCallopts;

  enum CCINotificationType
  {
    AlwaysPlay,
    MuteDuringMeetingCalls,
    AlwaysMute,
  };
  RadioGroupProperty _contacCenterNotiGroup;

  zui::State<bool> _teamChatEnbaled = true;
  zui::State<bool> _teamChatNotificationVisible = false;
  zui::State<bool> _newChatEnabled = false;

  zui::State<IRingtonePlayer*> _ringtonePlayer = nullptr;
  enum class UpcomingMeetingsType
  {
    kAllMeetingsAndEvents,
    kZoomMeetingOnly,
  };
  zui::State<int> _upcomingMeetingType = static_cast<int>(UpcomingMeetingsType::kAllMeetingsAndEvents);

  // ABI STABILITY: Always append new cross-DLL state members at the end of the class.
  // NEVER insert, reorder, or change types of existing members - this breaks binary compatibility
  // across DLL boundaries when different modules are compiled at different times.
  //
  // COMPATIBILITY STRATEGY for _firstParticipantJoinControl:
  // - Added at class end to preserve all existing member offsets
  // - Initialization handled in constructor/InitfirstParticipantJoinControl()
  // - Cleanup handled in destructor (unregister update handler)
  // - Safe to use across DLL boundaries without recompilation of dependents
  //
  // MIGRATION NOTES: Older clients without this member will continue to work as long as
  // they don't access this field. New feature is opt-in via server settings (locked/visible flags).
  SwitchControl _firstParticipantJoinControl;
};


class ZUIClient_API SettingPanelNotifications : public zui::CustomView<SettingPanelNotifications>
{
public:

  SettingPanelNotifications() = default;
  ~SettingPanelNotifications() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelNotifications>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;

  zui::View GetSoundsView();

  zui::View GetNotificationsView();

  zui::View GetActivityCenterView();

  zui::View GetOtherView();

  zui::View GetLogoutView();

private:
  zui::Bind<bool> _showCustomRingtones = false;
  zui::State<std::string> _bkColor_notification = std::string("");
};


#define NotiPanelDataModel CNotifSoundsSettingDataModel::GetInstance()

#endif
