#ifndef _SETTING_PANEL_PHONE_H_
#define _SETTING_PANEL_PHONE_H_

#include "signals/signals.h"
#include "ssb_media_client_def.h"
#include "zSipCallCommon/phone_field.h"
#include "zSipCallCommon/pbx_call_handling_settings_api.h"
#include "zSipCallCommon/pbx_efax_api.h"
#include "zPTApp/sip/sipcall_audio_file_player_api.h"
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
#include "zUIClient/zui_client_data_define.h"
#include "setting_panel_phone_dialog.h"
#include "zUIClient/zui_client_data_define.h"


namespace zui {
class ISettingPanelPhoneAudioPlayer;
class SettingPanelPhoneAudioPlayerImpl;
class ZUISyncService;
struct PhoneSyncServiceData;
struct PhoneSyncServiceEvent;
} // namespace zui

void ZUIClient_API InitPhoneSettingDataModel();

struct VoicemailGreetingPolicyAndOp{
  zui::State<bool> _enableVoicemailGreeting = true;
  zui::State<bool> _personalAudioLibrary = true;
  zui::State<bool> _personalVoicemailAndVideoMail = true;
  zui::State<bool> _enableToReachAnOperator = true;
  zui::State<bool> _enableToEditCallHandingSetting = true;
  zui::State<bool> _enableUploadFile = true;
  zui::State<bool> _enableCallOverflow = true;
  zui::State<NS_SIPCALL_APP::OverflowType> _callOverflowType;
  zui::State<bool> _checkVoicemailsOverPhone = true;
  // op
  zui::State<bool> _enableMultiTts = true;
  zui::State<bool> _enableExternalContact = true;
  zui::State<bool> _displayAdditionalIVR = true;
  zui::State<bool> _enableHolidayHours = false;
};

struct VoiceSetting{
  zui::State<CString> _value;
  zui::State<std::vector<NS_SIPCALL_APP::CmmCallHandlingVoice>> _voiceDtos;
  NS_SIPCALL_APP::CmmCallHandlingVoice _selectVoice;
  zui::State<bool> _isPlaying;
  zui::State<bool> _activityIndicator;
};

struct PhoneAudioDeviceUIState {
  DynDropdownProperty _dropdown = 0;
  BtnClickedProperty _testButton = false;
  zui::State<float> _level = 0.0f;
  AudioVolumeProperty _volume = 0.0f;
  zui::State<std::string> _helperText;
};

struct RoutingTypeData{
  zui::State<int> _actionIndex = 0;
  zui::State<std::vector<NS_SIPCALL_APP::RoutingAction>> _routingActions;

  // option
  zui::State<zui::Checkbox::Status> _allowToReachAnOperator;
  zui::State<zui::Checkbox::Status> _allowToCheckVoicemail;
  zui::State<zui::Checkbox::Status> _overflowPlayCalleeVmGreeting;
  CheckBoxProperty _playCalleeVmGreeting;
  ToggleProperty _pressOneBeforeConnect;
  zui::State<zui::Checkbox::Status> _forwardExtConnectToOperator;
  zui::State<zui::Checkbox::Status> _forwardExtCheckVoicemailOverPhone;

  // voiceSetting
  VoiceSetting _voicemailGreeting;
  VoiceSetting _disconnectGreeting;
  VoiceSetting _voicemailWelcome;

  // extension
  zui::State<int> _extensionLevel = 0;
  zui::State<CString> _extensionId;

  // ivr
  zui::State<int> _ivrExtensionLevel = 0;
  zui::State<CString> _ivrExtensionId;

  // external extension;
  zui::State<CString> _externalExtensionId;

  // external number
  zui::State<CString> _externalPhoneNumber;
  zui::State<CString> _externalPhoneNumberCountryCode;
  zui::State<CString> _externalPhoneNumberDesc;

  zui::State<std::string> _forwardText;
  TextProperty _forwardErrorText = {"", false};
  BtnProperty _saveForward = {true, false, false};

  TextProperty _updateRoutingErrorText = { "", false };

  void InitializeStateHandler(NS_SIPCALL_APP::RoutingType type);
  NS_SIPCALL_APP::RoutingAction GetSelectAction();
  void UpdateRoutingActionIndex(NS_SIPCALL_APP::RoutingAction action);
};

struct HolidayHoursEntry {
  enum class RepeatType {
    kNone,
    kAnnually,
  };

  std::string id;
  std::string name;
  std::string startDateTime;  // wire: yyyy-MM-dd HH:mm:ss
  std::string endDateTime;    // wire: yyyy-MM-dd HH:mm:ss
  bool isAllDay = false;
  RepeatType repeatType = RepeatType::kNone;
  std::string recurrenceRule;   // full list-row copy, e.g. "Annually on the fourth Thursday of August"
  std::string recurrenceBrief;  // compact settings copy, e.g. "Annually"
  bool isManagedByAdmin = false;
  bool canEdit = false;
  bool canDelete = false;
  bool isEnded = false;

  bool operator==(const HolidayHoursEntry&) const = default;
};

class ZUIClient_API CPhoneSettingDataModel 
  : public IInitializable,
    public NS_SIPCALL_APP::ICallHandlingSettingsAPI::CallHandlingSettingsListener,
    public NS_SIPCALL_APP::CmmFaxSetting::Listener
{
public:
  struct BlockedItem;

  enum class PlayObjType
  {
    kUnknow,
    kPlayVoicemail,
    kPlayVoicemailInMeeting,
    kPlayLocalFile,
    kPlayLocalRecord,
    kPlaySingleTts,
    kPlayAllTts,
    kPlayLeaveVoicemail
  };

  static CPhoneSettingDataModel& GetInstance();
  static void ReleaseInstance();
  
  CPhoneSettingDataModel();
  ~CPhoneSettingDataModel();

  virtual void initializeState() override;
  virtual void initializeStateHandler() override;

  // call handling
  void RequestAllCallHandlingSetting();

  // CallHandlingSettingsListener
  void OnRequestBusinessHourExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const NS_SIPCALL_APP::CmmBusinessHourEx& result) override;
  void OnGenerateBusinessHourExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const NS_SIPCALL_APP::CmmBusinessHourEx& result) override;
  void OnRequestCheckBusinessHourDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, bool has_conflict) override;
  void OnUpdateBusinessHourExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const NS_SIPCALL_APP::CmmBusinessHourEx& result) override;
  void OnRequestRoutingExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingRoutingEx>& result) override;
  void OnRequestAvailableLibrariesDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const NS_SIPCALL_APP::CmmCallHandlingVoiceInfo& libraries, const NS_SIPCALL_APP::CmmCallHandlingRequestAvailableLibrariesParam& param) override;
  void OnSearchExtensionInfoDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const NS_SIPCALL_APP::CmmCallHandlingExtensionInfo& result) override;
  void OnSearchExternalExtensionInfoExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingExternalExtensionInfoEx>& result) override;
  void OnUpdateRoutingExDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingRoutingEx>& result) override;
  void OnRequestTtsLanguageDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingTtsLanguage>& result) override;
  void OnRequestAudioLanguagesDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingAudioLanguage>& languages) override;
  void OnAddTtsLibraryDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const Cmm::CString& file_id) override;
  void OnUploadFileLibraryDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const Cmm::CString& file_id) override;
  void OnRequestPlayUrlDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const Cmm::CString& play_url) override;
  void OnRequestAllCountriesDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const std::vector<NS_SIPCALL_APP::CmmCallHandlingPhoneNumberCountry>& countries) override;
  void OnRequestFileUrlDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, const CString& file_url) override;
  void OnRequestCallOverflowPolicyDone(const CString& req_id, CmmUInt32 res, const CString& err_msg, NS_SIPCALL_APP::OverflowType data) override;

  // NS_SIPCALL_APP::CmmFaxSetting::Listener
  void OnOptionChanged(const CString& key, bool value) override;

  // dialog
  void AttachDialogView(zui::DialogType type, const DialogData& data, std::shared_ptr<zui::ZUIWindow> window);
  void NotifyPopupDialog(zui::DialogType type, const DialogData& data);
  std::shared_ptr<zui::ZUIWindow> PopupDialog(zui::DialogType type, const DialogData& data);
  void CloseDialog(zui::DialogType type);
  // business hour
  void RegisterCallHandingListenter();
  void RegisterFaxSettingListener();
  void RequestCheckBusinessHour();
  void RequestUpdateBusinessHours();
  void UpdateBusinessHoursText();
  // route option
  void InitVoicemailGreetingPlocyAndOp();
  void InitBlocklistFeatureOptions();
  void ApplyBlocklistFeatureOptions(bool enable_manage, bool enable_country);
  void InitRoutingAction();
  void UpdateRoutingSetting(const std::vector<NS_SIPCALL_APP::CmmCallHandlingRoutingSettingEx>& setting, RoutingTypeData& routingTypeData);
  void RequestUpdateVoiemail(NS_SIPCALL_APP::RoutingType routingType, const CString& fileId);
  void RequestUpdateRoutingAction(NS_SIPCALL_APP::RoutingType routingType);
  void QueryExtension(int level, const std::string& key, const CString& includeId);
  void QueryExternalExtension(const std::string& key, const CString& includeId);
  void SaveIVRMenuOption(NS_SIPCALL_APP::RoutingType routingType, bool connectToOperator, bool pressOneBeforeConnect, bool playCalleeVmGreeting, const Cmm::CString& extensionValue, const Cmm::CString& voicemailValue);
  void UpdateAvailableLibraries();
  void RequestVoicemailGreetingList(NS_SIPCALL_APP::RoutingType routingType, bool allowToReachAnOperator, bool allowToCheckVoicemail);
  void RequestDisonnectGreetingList(NS_SIPCALL_APP::RoutingType routingType);
  void RequestVoicelmailWelcomeList(NS_SIPCALL_APP::RoutingType routingType);
  RoutingTypeData& GetRoutingTypeData(NS_SIPCALL_APP::RoutingType routingType);
  std::vector<CmmInt32> GetCategoryListWhenForwardToVoicemail(bool allowToCheckVoicemail, bool allowToReachAnOperator);
  NS_SIPCALL_APP::RoutingKey GetRoutingKeyWhenForwardToVoicemail(bool allowToCheckVoicemail, bool allowToReachAnOperator);
  std::string GetInitForwardText(NS_SIPCALL_APP::RoutingAction routingAction);
  // audio player
  void InitPhoneAudioPlayer();
  void SetPhoneAudioPlayer(const std::shared_ptr<zui::ISettingPanelPhoneAudioPlayer>& player);
  void RequestPlayGreeting(NS_SIPCALL_APP::RoutingType routingType, const CString& fileId, const PlayObjType& type, const CString& cutomizedRoutingType);
  void PlayUrl(const CString& url);
  void StopPlayUrl();
  void StopPlayOtherGreeting(NS_SIPCALL_APP::RoutingType routingType);
  void ResetPlayGreetingActivityIndicator();
  int GetCurrentPlayDuration();
  // add voicemail greeting
  void RequestTtsLanguage();
  void RequestAudioLanguage();
  CString RequestAddTtsLibrary(const std::string assetName, const std::vector<CmmInt32>& categoryList, const std::vector<NS_SIPCALL_APP::CmmCallHandlingTtsDto>& singleTtsDtoList);
  CString RequestUploadFile(const CString& assetName, const CString& fileName, const CString& filePath, const Cmm::CString& language, const std::vector<CmmInt32>& categoryList, bool isRecording);
  void RequestPlayTts(NS_SIPCALL_APP::RoutingType routingType, const std::vector<NS_SIPCALL_APP::CmmCallHandlingTtsDto>& singleTtsDtoList);
  // save extension
  void RequestUpdateExtension(NS_SIPCALL_APP::RoutingType routingType);
  void RequestUpdateExternalExtension(NS_SIPCALL_APP::RoutingType routingType);
  void RequestRequestAllCountries();
  void RequestUpdateExternalPhoneNumber(NS_SIPCALL_APP::RoutingType routingType);
  //ipc
  void SyncRoutingTypeData(NS_SIPCALL_APP::RoutingType routingType);
  void SendIpcEventReqeustPlayGreeting(NS_SIPCALL_APP::RoutingType, const CString& fileId, const CString& custoRoutingType);
  void NotifyRequestCallOverflowPolicy();
  // Notifies the PT process that a Phone Audio settings device selection
  // (speaker/microphone/additional ringtone) changed, so it pushes the
  // resolved device id/name straight to AudioController::ConfigurePhoneAudioDeviceById
  // for any in-progress SIP call. deviceType is SSB_MC_DEVICE_TYPE_AUDIO_RENDERER
  // (speaker), _CAPTURE (microphone), or _RING (additional ringtone device);
  // pass empty id/name for RING to mean "no separate ringer". Calls directly
  // when already running in PT; otherwise routes through _phoneSyncService
  // (which broadcasts cross-process via zstref, unlike the in-process-only
  // ZUIClientMgr::NotifyEvent).
  void SendIpcEventSyncPhoneAudioDeviceSelection(SSB_MC_DEVICE_TYPE deviceType, const CString& id, const CString& name);
  void OnUnSelect();
  void UpdateBlockedItems(const std::vector<BlockedItem>& blockedItems);

  // helper
  std::string GetNextDay(const std::string& today);

  void InitShowFaxInToolbar();
  void InitPhoneAudioSettingsUI();
  void EnterPhoneAudioSettingsPage();
  void ExitPhoneAudioSettingsPage();

  // Holiday hours
  void InitHolidayHours();
  void LoadHolidayHours();
  void CreateHolidayHour(const HolidayHoursEntry& entry);
  void UpdateHolidayHour(const std::string& id, const HolidayHoursEntry& entry);
  void DeleteHolidayHour(const std::string& id);
  void UpdateHolidayHoursSummaries();
  std::string GenerateHolidayId();

private:
  // business hour
  void UnRegisterCallHandingListenter();
  void UnRegisterFaxSettingListener();
  void InitTimePoints();
  void InitCustomHours();
  std::string GetTimeCustomHoursList(int index);
  int GetCustomHoursListIndex(const std::string& hours);
  void GenerateBusinessHourEx();

  // routing
  void ConnectPhoneAudioPlayerSignal();
  void OnPlayStatus(NS_SIPCALL_APP::SIPAudioFilePlayerStatus, CmmUInt32);
  void OnPlayProgressChanged(CmmUInt32 curPos);
  void OnPlayTerminated();
  std::vector<NS_SIPCALL_APP::RoutingAction> GetRoutingAction(NS_SIPCALL_APP::RoutingType routingType);
  void UpdateForwardText(const std::string& forwardText, RoutingTypeData& routingData);
  void HandleRoutingOption(const NS_SIPCALL_APP::CmmCallHandlingRoutingOption& option, RoutingTypeData& routingTypeData);
  void UpdateVoicemailPrompt(const NS_SIPCALL_APP::CmmCallHandlingRoutingSettingEx& setting, VoiceSetting& promptSetting);
  void RequestUpdateVoicemailWelcome(NS_SIPCALL_APP::RoutingType, const CString& fileId);

  // ipc
  void InitPhoneSyncService();
  CString NotifyUpdateRoutingEx(const NS_SIPCALL_APP::CmmCallHandlingRoutingEx& param);
  void NotifyRequestAvailableLibraries(const NS_SIPCALL_APP::CmmCallHandlingRequestAvailableLibrariesParam& param);
  void OnIpcDataChaned(const zui::PhoneSyncServiceData& message);
  void OnIpcEventReceived(const zui::PhoneSyncServiceEvent& message);
  void SyncCallHandlingPhoneNumberCountries(const std::vector<NS_SIPCALL_APP::CmmCallHandlingPhoneNumberCountry>& countries);
  void HandleIpcEventRequestPlayGreeting(const Json::Value& message);
  void SendIpcEventRequestPlayGreetingDone(const CString& url);
  void HandleIpcEventRequestPlayGreetingDone(const Json::Value& message);
  void SendIpcEventMoveFaxInPhoneChanged(bool value, bool visible);
  void HandleIpcEventMoveFaxInPhoneChanged(const Json::Value& message);
  void SendIpcEventRequestMoveFaxInPhone();
  void HandleIpcEventRequestMoveFaxInPhone(const Json::Value& message);
  void HandleIpcEventRequestCallOverflowPolicy(const Json::Value& message);
  void HandleIpcEventSyncPhoneAudioDeviceSelection(const Json::Value& message);
  // Actual work for SendIpcEventSyncPhoneAudioDeviceSelection: forwards to
  // AudioController::ConfigurePhoneAudioDeviceById, which only ever touches
  // SpeakerID/SpeakerName, MicID/MicName, or RingerID/RingerName - never any
  // DSP field. Only runs on Windows (CMM_WIN) - see the .cpp for why.
  void ApplyPhoneAudioDeviceSelectionToActiveCall(SSB_MC_DEVICE_TYPE deviceType, const CString& id, const CString& name);
  
  // helper
  void UpdateVisibleHelper();

public:
  struct BlockedItem {
    std::string id;
    std::string e164number;
    std::string numberType;
    std::string numberName;
    std::string number;
    bool canUnblock = true;

    bool operator==(const BlockedItem& other) const {
      return id == other.id
        && e164number == other.e164number
        && numberType == other.numberType
        && numberName == other.numberName
        && number == other.number
        && canUnblock == other.canUnblock;
    }
  };

  zui::State<bool> _isPbxVisble = false;;

  // SMS auto-reply content is supplied by the phone data layer.
  zui::State<bool> _showTextMessaging = false;
  zui::State<bool> _smsAutoReplyBusinessHoursEnabled = false;
  zui::State<bool> _smsAutoReplyBusinessHoursToggleEnabled = false;
  zui::State<std::string> _smsAutoReplyBusinessHoursMessage;
  zui::State<bool> _smsAutoReplyClosedHoursEnabled = false;
  zui::State<bool> _smsAutoReplyClosedHoursToggleEnabled = false;
  zui::State<std::string> _smsAutoReplyClosedHoursMessage;

  // my account online link,just control it's visible.
  BtnProperty _settingLink;

  zui::State<bool> _isDirectNumberVisble;
  zui::State<std::vector<zui::any>> _directNumbers;

  // extension: or company number:.
  zui::State<bool> _hasMainCompanyNumber;  //if has not mian company number will show extension:
  
  zui::State<bool> _isExtNumberVisble;
  zui::State<std::string> _displayExtNumber;  // if has company number , will show company number#ext.

  // Local dialing
  zui::State<bool> _isDialingNumberVisble;
  zui::State<std::string> _localDialingNumber;  // conntry code , country_name

  zui::State<bool> _isAreaCodeVisble;
  zui::State<std::string> _areaCode;

  // Text : Dial local calls without dialing country and area code first. 
  zui::State<bool> _dialingTipVisible;

  // address status: may be Detected, Default.
  enum class AddressStatus {
    kNull,
    kDefault,
    kDetected,
  };
  struct EmergAddrStatusProperty : public ControlBasePropertyWithVisible<std::string> {
    zui::State<AddressStatus> _status = AddressStatus::kNull;

    EmergAddrStatusProperty() {}
    EmergAddrStatusProperty(AddressStatus status) {
      this->operator=(status);
    }

    EmergAddrStatusProperty& operator=(AddressStatus status) {
      _status = status;
      _visible = AddressStatus::kNull != status;
      if (AddressStatus::kDefault == status)
        _value = "DEFAULT";
      else if (AddressStatus::kDetected == status)
        _value = "DETECTED";
      return *this;
    }
  };
  EmergAddrStatusProperty _emergAddrStatus = AddressStatus::kNull;

  // address info with text and visible control
  EmergAddrProperty _emergAddr = std::string("111 S Grand Ave, \nLos Angeles, California 90012, \nUnited States");
  zui::State<std::string> _emergAddrTip;

  // address loading control
  zui::State<bool> _emergAddrLoading = true;

  // Address action: Update / Confirm / Personal Location or Addresses
  BtnProperty _updateAddress;    // btn,
  BtnProperty _confirmAddress;  // btn 
  zui::State<bool> _updateAndConfirmHelper;
  BtnProperty _manageAddress;  // Personal Location or Addresses , is a link. 
  BtnProperty _addAddress;  // btn 
  BtnProperty _textCoordinates;  // btn 
  EmergAddrProperty _coordinates;  // just show gray text, may be use text control

  // checkbox  allow location permission
  SwitchControl _locationPermission;
  zui::State<std::string> _locationPermissionText;  // location description
  zui::State<std::string> _locationPermissionTip;  // tip text,
  zui::State<bool> _locationHelperVisible = false;  // MAC only

  zui::State<std::string> _locationHelperDesc;
  zui::State<std::string> _locationHelperDL;
  zui::State<bool> _locationHelperDLVisible = false;
  zui::State<bool> _locationHelperDLLoadingVisible = false;
  StringVisibleProperty _locationHelperHelpButton;
  zui::State<bool> _callingPreferenceVisible = false; // MAC only

  // Blocklist management
  zui::State<bool> _showBlocklistManage = false;
  zui::State<bool> _hasBlockedItems = false;
  zui::State<std::vector<zui::any>> _blockedItems;
  zui::State<bool> _enableBlocklistManage = false;
  zui::State<bool> _enableBlocklistCountryType = false;

  /*
  @property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *bundleID;
@property (nonatomic, retain) NSImage *icon;
@property (nonatomic, assign) BOOL isDefult;
  */
  // MAC only
  struct CallPreferenceInfo{
    std::string app_name;
    std::string boudle_id;
    std::string icon;
    bool is_default;
    bool operator==(const CallPreferenceInfo& other) const {
      return app_name == other.app_name
        && boudle_id == other.boudle_id
        && icon == other.icon
        && is_default == other.is_default
        ;
    }
  };
  zui::State<std::vector<zui::any>> _callingPreferences;

  // Transcript lange setting.
  zui::State<bool> _transcriptLangeVisible = true;
  zui::State<int> _transcriptLangeListSelectIndex;
  zui::State<std::list<std::string>> _transcriptLanges;

  // Translation lange setting.
  zui::State<bool> _translationLangeVisible = true;
  zui::State<int> _translationLangeListSelectIndex;
  zui::State<std::list<std::string>> _translationLanges;

  // auto-answer call queue calls.
  zui::State<int> _autoAnswerCQPeriodSelectedIndex;
  zui::State<bool> _autoAnswerCQVisible;

  // Call Control
  BtnProperty _callControl;

  // Launch app or Url
  SwitchControl _launchAppForIncomingCalls;

  zui::State<bool> _editLaunchAppForIncomingCallsEnable;  // edit url  enable ?
  zui::State<std::string> _editLaunchAppForIncomingCalls;  // edit url content
  BtnProperty _browseBtn = { true,true};   // browse select file / exe.

  // hide zra = hideOutgoingCallsViaDialerFromHistory
  SwitchControl _hideZRACalls;

  // call me on panel 
  SwitchControl _callOut;

  //zui::State<bool> _callOutNumberVisible;
  zui::State<bool> _callOutNumberEnable;
  struct CallOutInfo {
    std::string label;
    std::string number;
    std::string id;  // Passed back to the UI layer
    bool operator==(const CallOutInfo& other) const{
      return label == other.label &&
        number == other.number
        && id == other.id;
    }
  };
  zui::State<std::vector<zui::any>> _callOutNumber;  // list show all call out number,  under number there are to button (edit / delete).

  zui::State<bool> _videoGreetingVisible = true;
  // greeting actions.  Record / Review / Delete
  SwitchControl _videoGreetingToggle;
  BtnProperty _videoGreetingRecord;
  BtnProperty _videoGreetingReview;
  BtnProperty _videoGreetingDelete;

  zui::State<bool> _showPhoneAudioSettings = false;
  zui::State<bool> _isPhoneAudioDetailPage = false;
  BtnProperty _phoneAudioResetToClientConfig = { false, true };
  PhoneAudioDeviceUIState _phoneSpeakerUI;
  ToggleProperty _phoneAdditionalRingtoneDevice = { false, false };
  DynDropdownProperty _phoneAdditionalRingtoneDropdown = 0;
  PhoneAudioDeviceUIState _phoneMicrophoneUI;
  ToggleProperty _phoneMicrophoneAutoAdjust = { false, false };

  // voicemail prioritization with AI companion, voicemail topic
  zui::State<bool> _hasVoicemailPriorityTopics = true;
  SwitchControl _voicemailPrioritization;    // toggle state.

  // all in notification page.
  //// hide incoming calls while in a zoom meeting.
  //zui::State<bool> _hideIncomingCallInMeetingEnable;
  //zui::State<bool> _hideIncomingCallInMeeting;
  // live transcript setting.
  SwitchControl _autoStartLiveTranscript;
  SwitchControl _autoStartMyNotes;
  NS_SIPCALL_APP::field<bool> _autoStartMyNotesValue{ "PhoneSettings._autoStartMyNotesValue" };
  NS_SIPCALL_APP::field<bool>::connection _autoStartMyNotesValueConnection;
  NS_SIPCALL_APP::field<bool> _autoStartMyNotesEnable{ "PhoneSettings._autoStartMyNotesEnable" };
  NS_SIPCALL_APP::field<bool>::connection _autoStartMyNotesEnableConnection;
  NS_SIPCALL_APP::field<bool> _autoStartMyNotesVisible{ "PhoneSettings._autoStartMyNotesVisible" };
  NS_SIPCALL_APP::field<bool>::connection _autoStartMyNotesVisibleConnection;
  // test function show webrtc.
  BtnProperty _showWebRTCWebview;
  BtnProperty _showWebview;

  // business hours
  std::list<std::string> _timePoints;
  std::vector<std::string> _weekdayNames;
  NS_SIPCALL_APP::CmmBusinessHourEx _businessHourData; // store https data
  zui::State<std::vector<zui::any>> _businessHoursText;
  zui::State<int> _businessHoursGroupValue = 1; // BusinessHourMode
  struct CustomHours
  {
    std::string title;
    zui::State<zui::Checkbox::Status> status = zui::Checkbox::Status::kUnselected;
    zui::State<std::string> openHour = std::string("10:30 AM");
    zui::State<std::string> closeHour = std::string("7:30 PM");

    bool operator==(const CustomHours& other) const
    {
      return title == other.title && status == other.status && 
        openHour == other.openHour && closeHour == other.closeHour;
    }
  };
  zui::State<std::vector<zui::any>> _customHours;

  // voicemail
  bool _isInPt = false;
  VoicemailGreetingPolicyAndOp _voicemailPolicyAndOp;
  std::map<zui::DialogType, std::shared_ptr<zui::ZUIWindow>> _dialogMap;

  friend struct RoutingTypeData;
  RoutingTypeData _busyOnCallBusinessHours;
  RoutingTypeData _unansweredOnCallBusinessHours;
  RoutingTypeData _busyOnCallClosedHours;
  RoutingTypeData _unansweredOnCallClosedHours;

  std::shared_ptr<zui::ISettingPanelPhoneAudioPlayer> _phoneAudioPlayer;
  signals2::connection _connectionPlayStatus;
  signals2::connection _connectionPlayProgress;
  signals2::connection _connectionPlayTerminated;

  PlayObjType _curPlayType;
  

  zui::State<float> _playRecordProgress = -1.0f; // 0.0 - 1.0
  zui::State<NS_SIPCALL_APP::SIPAudioFilePlayerStatus> _playRecordStatus;

  zui::State<float> _playTtsProgress = -1.0f;
  zui::State<NS_SIPCALL_APP::SIPAudioFilePlayerStatus> _playTtsStatus;
  zui::State<NS_SIPCALL_APP::SIPAudioFilePlayerStatus> _playSingleTtsStatus;

  zui::State<float> _playUploadFileProgress = -1.0f;
  zui::State<NS_SIPCALL_APP::SIPAudioFilePlayerStatus> _playUploadFileStatus;

  zui::State<NS_SIPCALL_APP::SIPAudioFilePlayerStatus> _playLeaveVoicemailStatus;

  zui::ZUISyncService* _phoneSyncService = nullptr;
  signals2::connection  _connectionDataChanged;
  signals2::connection  _connectionEvent;
  CString _meetingRequestUrlId;

  struct OperatorExtension
  {
    CString name;
    CString description;
    CString id;
    CString extensionNumber;

    bool operator==(const OperatorExtension& other) const{
      return name == other.name && description == other.description && id == other.id && extensionNumber == other.extensionNumber;
    }
  };
  // extension
  zui::State<std::vector<OperatorExtension>> _extensionOptions;
  std::vector<NS_SIPCALL_APP::CmmCallHandlingExtensionInfoEx> _extensionInfoEx;
  // external extension
  zui::State<std::vector<OperatorExtension>> _externalExtensionOptions;
  std::vector<NS_SIPCALL_APP::CmmCallHandlingExternalExtensionInfoEx> _externalExtensionInfoEx;
  // external phonenumber
  zui::State<std::vector<NS_SIPCALL_APP::CmmCallHandlingPhoneNumberCountry>> _countries;

  struct RequestData {
    NS_SIPCALL_APP::RoutingType routingType;
    CString reqId;
    bool isExternalExtension = false;
  };
  RequestData _lastRequest;

  // add voicemail greeting
  zui::State<std::vector<NS_SIPCALL_APP::CmmCallHandlingTtsLanguage>> _ttsLanguage;
  zui::State<bool> _isAddTtsLibrary = false;
  zui::State<std::vector<NS_SIPCALL_APP::CmmCallHandlingAudioLanguage>> _audioLanguage;

  // show fax in navigation bar
  SwitchControl _showFaxInToolbar;

  //delegation
  zui::State<bool> _showDelegation = false;
  zui::State<bool> _showSMSDegation = false;
  zui::State<bool> _enableSMSDelegation = false;
  zui::State<std::vector<zui::any>> _delegates;

  // visual update
  zui::State<bool> _showVisualUpdate = false;
  zui::State<bool> _isOnNewPhoneExperience = false;
  zui::State<bool> _isOnClassicPhoneExperience = false;

  // Phone web bundle version. _phoneWebVersionAvailable is false in the classic
  // experience or before the web reports a version (UI shows "unavailable" then).
  zui::State<bool> _phoneWebVersionAvailable = false;
  zui::State<std::string> _phoneWebVersion;

  zui::State<std::vector<zui::any>> _holidayHours;
  zui::State<std::vector<std::string>> _holidayHoursSummaries;
  zui::State<std::list<std::string>> _holidayHoursOptions;
  zui::State<bool> _holidayHoursAvailable = false;
  zui::State<std::string> _selectedHolidayId;

private:
  static CPhoneSettingDataModel* _instance;
};

class ZUIClient_API NewSettingPanelPhone : public zui::CustomView<NewSettingPanelPhone>
{
public:
  NewSettingPanelPhone();
  ~NewSettingPanelPhone() = default;

  std::shared_ptr<zui::ViewNode> Build() override;

private:
  void UpdateEmergencyAddresssLabel();
  void UpdateShowDirectNumberList();

  void OnClickZoomTechnicalSupport();

private:
    zui::State<bool> _showDirectNumberList = true;

    zui::State<std::string> _locationHelperVersion = std::string("Location helper (version 5.16.0.134) installed");
    
    zui::State<std::string> _emergencyAddressRoad = std::string("888 Monument Village Cir");
    zui::State<std::string> _emergencyAddressCityState = std::string("Grand Junction, Colorado 81507");
    zui::State<std::string> _emergencyAddressCountry = std::string("United States");
  
    zui::State<bool> _launchExternalApp = false;
    zui::State<bool> _recordVideoGreeting = false;
    zui::State<bool> _manageVoiceMail = false;

    zui::Bind<std::vector<zui::any>> _directNumbers;
};

class ZUIClient_API SettingPanelPhoneCallControl : public zui::CustomView<SettingPanelPhoneCallControl>
{
public:
    SettingPanelPhoneCallControl() = default;
  ~SettingPanelPhoneCallControl() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelPhoneCallControl>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;

};

#define PhoneDataModel CPhoneSettingDataModel::GetInstance()

#endif
