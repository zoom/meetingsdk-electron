#ifndef _SETTING_PANEL_AUDIO_H_
#define _SETTING_PANEL_AUDIO_H_

#include <memory>

#include "zoom_client_conf.h"
#include "ssb_media_client_def.h"
#include "cmmlib/CmmTimer.h"
#include "zVideoApp/CmmConfAPI.h"

#include "zui_client_data_define.h"

#ifdef _WIN32
#include "zUI/view.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUI/checkbox.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "zUI_stdafx.h"
#endif

#if (defined BUILD_FOR_VDI) && (defined WIN32)
#include "vdi/vdi_interface.h"
#endif

#define MIC_MENU        1
#define SPK_MENU        2
#define RING_MENU       3

#define RECORD_USER_VOICE_MAX_TIME  300 //30S

typedef enum
{
  enuNoneNew = 1,
  enuRecordInfoNew,
  enuPlayInfoNew,
  enuSpkInfoNew,
  enuMicerrNew,
  enuRingInfoNew,
  enuSpkerrNew,
  enuRingerrNew
} NEW_TEST_AUDIO_INFO;

#if defined(ENABLE_UNIFIED_SETTING) && defined(__MACOS__)
class CAudioDeviceSink;
#endif

class ZUIClient_API CAudioPanelDataModel
  : public Cmm::CTimerProc
  , public IInitializable
{
public:
  static CAudioPanelDataModel& GetInstance();


  //virtual ICmmConfUIAPI* GetZmInterface(ICmmConfUIAPI*);


  virtual void initializeState() override;

  virtual void initializeStateHandler() override;

  void OnSelect();
  void OnUnSelect();

  void InitAudioSettingInfo();
  void InitAudioDevice();
  void InitSpks();
  void InitMics();
  void InitRingers();
  void UpdateVolumeUI();
  void UpdateSpatialAudioControl();
  void UpdateRingVolumeUI();
  void RefreshAudioSettingUI();
  void InitAudioAdvancedSettings();
  void RefreshAudioProfileUI();
  void RefreshOptimizedAudioSubOption();
  void UpdateManualRecordVoicePrintBtns();
  void OnPkgDownloadSuccess();
  void RefreshAudioInputChannels();
  void RefreshSelChannelNum();
  void RefreshUSBDevicePromptSetting();
  void OnManulRecordedWndClose();
  void UpdateWindowsSystemAudioEnhancement();
  void SetIsInMeeting(CmmBool is_in_meeting);
  void SetManualRecordWndIsShowing(CmmBool is_show = CmmTrue);
  void BindManualRecordWndVisible(zui::Bind<CmmBool>& is_visible);
  void OnTestMicEnd();
  void OnTestSpkEnd();

  CmmBool IsInMeeting() const;

  CmmBool OnAudioDeviceStatusChanged(DEVICE_CMD cmd, CmmUInt32 ret, CmmUInt32 handle) { return CmmFalse; };

  //ICmmDeviceUIAPI
  // Retained only as the legacy fallback for the voice-print / smart-recognition
  // commands that have no PS-sink equivalent yet; mic/spk/selection/profile/play
  // are now delivered directly by CAudioDeviceSink through the entry points below.
  void OnDeviceStatusChanged(DEVICE_CMD cmd, CmmUInt32 ret, CmmUInt32 handle);
  void ShowMyAudioLevel(CmmUInt32 level, CmmUInt32 handle, CmmBool isMic = CmmTrue);
  void OnVolumeChange(CmmUInt32 vol, CmmBool isMic);

  // Direct entry points used by CAudioDeviceSink (PS sink), replacing the legacy
  // DEVICE_CMD routing through OnDeviceStatusChanged.
  void OnMicDeviceChanged(CmmUInt32 ret);
  void OnSpkDeviceChanged(CmmUInt32 ret);
  void OnSelectedMicChanged();
  void OnSelectedSpkChanged();
  // Speaker embedding (voice print) info changed; manual==true also refreshes
  // the manual record voice-print buttons (see legacy CMD_*_SPK_EMB_INFO_UPDATE).
  void OnSpkEmbInfoChanged(bool manual);
  // PS stop callbacks carry no numeric file handle, so the data model resolves
  // its own stored handle (speaker test vs. recorded-mic playback) and forwards
  // it to OnAudioChanged.
  void OnTestPlaybackStopped(CmmBool isMic);

#if (defined BUILD_FOR_VDI) && (defined WIN32)
  ns_vdi::IVdiPluginCapacity* GetVDIPluginCapacity();
  CmmBool IsVDISupportSetAudioCapturePlaybackAPI();
#endif

private:
   bool GetChannelsNumAndState(CmmUInt32& channel_num, std::bitset<32>& channel_states, CmmUInt32* sel_channel_num = nullptr);

public:
  zui::State<bool> _showAdvanced = false;
  zui::State<bool> _isPAIEnable = false;
  zui::State<bool> _isPTLogin = false;
  zui::State<bool> _isPAIOPValue = false;
  zui::State<bool> _isVDISupportPlaybackAPI = true;
  zui::State<bool> _isVDIShowAudioProfile = true;
  zui::State<bool> _isVDIEnableNoiseSuppression = true;
  zui::State<bool> _isVDIShowSpeakerMicVolumeSlider = true;
  zui::State<bool> _isVDIShowAutoAdjustMicVolume = true;
  zui::State<bool> _isVDIShowSpecificAudioChannels = true;
  zui::State<bool> _isVDIShowRingtone = true;
  // only client sdk need
  zui::State<bool> _showLearnMore = true;

  // Monotonic counter bumped on any audio device list / default-device change
  // (see OnSpkDeviceChanged/OnMicDeviceChanged/OnSelectedSpkChanged/OnSelectedMicChanged).
  // Observers (e.g. the Phone audio settings page) watch this to refresh their own
  // device dropdowns; an incrementing value always notifies (unlike re-assigning an
  // identical list, which the State equality guard would drop).
  zui::State<int> _audioDeviceRevision = 0;

  // Speaker
  ToggleProperty _spatialAudio = false;
  ToggleProperty _ringtonesFromAdditionalDevice = false;
  DynDropdownProperty _speakerDropdown = 0;
  zui::State<float> _speakerLevel = 0; // float 0 - 1
  AudioVolumeProperty _speakerVolume = 0; // float 0 - 1
  BtnClickedProperty _speakerTesting = false;
  DynDropdownProperty _ringerDropdown = 0;
  zui::State<bool> _ringerDeviceAvailable = false;
  AudioVolumeProperty _ringerVolume = 0; // float 0 - 1

  // Microphone
  ToggleProperty _microphoneVolumeAutoAdjust = { false, false };
  DynDropdownProperty _microphoneDropdown = 0;
  zui::State<float> _microphoneLevel = 0; // float 0 - 1
  AudioVolumeProperty _microphoneVolume = 0; // float 0 - 1
  zui::State<int> _microphoneRecordingTime = -1;
  enum MicTestStatus {
    kReady,
    kRecording,
    kPlaying,
  };
  BtnAnyClickedProperty _microphoneTesting = static_cast<int>(MicTestStatus::kReady);
  SpecificAudioChannelsProperty _specificAudioChannels = 0;

  // Audio profile
  RadioButtonGroupProperty _audioProfile = static_cast<int>(CMM_AUDIO_PROFILE::kAudioProfileBackGroundNoise);
  zui::State<bool> _audioProfileRefreshTrigger = false;

  // background noise removal
  DropDownBaseProperty _bknoiseRemovalLevel = 0;

  // original sound for musicians
  CheckBoxBoolProperty _highFidelityMusicMode = false;
  CheckBoxBoolProperty _echoCancellation = true;
  CheckBoxBoolProperty _stereoAudio = false;

  // personalized audio isolation
  zui::State<bool> _isPAISmartRecogEnabled = false;
  PAIStatusProperty _PAIAutomaticRecording = false;
  PAIStatusProperty _PAIManualRecording = false;
  PAIStatusProperty _PAISmartRecogRecording = false;

  // Live performance
  ToggleProperty _livePerformance = false;

  // Advanced
  DropDownBaseProperty _echoCancellationAdv = 0;
#ifdef _WIN32
  DropDownBaseProperty _windowsSystemAudioEnhancementAdv = 0;
  DropDownBaseProperty _signalProcessingByWindowsAudioDeviceAdv = 0;
  DropDownBaseProperty _audioCaptureAndPlaybackAPI = 0;
#endif
  ToggleProperty _switchUSBDevice = false;
  SwitchControl _syncHeadsetButtons;
  CheckBoxProperty _syncAirPodsButtons;
    
  void StopMic();
  void StopSpk();
  void TestMic(CmmBool bDummy);

  // The Phone Audio settings page reuses this panel's test + level metering,
  // but must target the Phone-selected device without changing the Meeting
  // default device. When enabled, TestSpk/TestMic play/record on the supplied
  // device ids instead of the Meeting-selected devices.
  void SetPhoneAudioTestOverride(bool enable, const CString& spkId, const CString& micId);

private:
  void SwitchAudioDevice(const CString& deviceid, int menu_type);
  bool OnSelectMic(const CString& deviceid);
  bool OnSelectSpeaker(const CString& deviceid);
  bool OnSelectRinger(const CString& deviceid);

  void OnAdjustMicVolume(float volume);
  void OnAdjustSpkVolume(float volume);
  void OnAdjustRingVolume(float volume);

  void OnTestMicClicked();

  void SetTestMicStatus(CAudioPanelDataModel::MicTestStatus status);
  CmmBool PlayRecordedMic();
  void ResetTestMicStatus();
  void OnTestSpkClicked();
  void TestSpk();


  void OnSpkLevelChanged(CmmUInt32 level, CmmUInt32 handle);
  void OnMicLevelChanged(CmmUInt32 level, CmmUInt32 handle);
  void OnAudioChanged(CmmUInt32 ret, CmmUInt32 handle);

  void OnMicStatusChanged(CmmUInt32 ret);
  void OnSpkStatusChanged(CmmUInt32 ret);
  void OnRingStatusChanged(CmmUInt32 ret);

private:
  //CTimerProc
  virtual void OnTimer(void*, CmmUInt, CmmHTimer idEvent, CmmULong dwTime) override;

private:
  CString _selectSpkId;
  SSB_MC_AUDIO_DEVICE_API_TYPE selectSpkType = SSB_MC_AUDIO_DEVICE_API_TYPE_SYSTEM_DEFAULT;

  CString _selectMicId;
  SSB_MC_AUDIO_DEVICE_API_TYPE selectMicType = SSB_MC_AUDIO_DEVICE_API_TYPE_SYSTEM_DEFAULT;

  // Phone Audio test device override (see SetPhoneAudioTestOverride). Empty id
  // means the resolved system-default device.
  bool _usePhoneAudioTestDevice = false;
  CString _phoneAudioTestSpkId;
  CString _phoneAudioTestMicId;

  // Show Info
  NEW_TEST_AUDIO_INFO          m_last_SpkInfo_ = enuNoneNew;
  NEW_TEST_AUDIO_INFO          m_last_MicInfo_ = enuNoneNew;
  NEW_TEST_AUDIO_INFO          last_ring_info_ = enuNoneNew;

  BOOL                     m_bStartTestMic = FALSE;
  BOOL                     m_bMaunalTestMic = FALSE;
  BOOL                     m_bStartTestSpk = FALSE;
  BOOL                     need_replay_spk_handle_now_ = FALSE;
  BOOL                     need_replay_ring_handle_now_ = FALSE;
  CmmUInt32                m_SpkLevel = 0;
  CmmUInt32                test_spk_handle_ = NULL_AUDIO_FILE_HANDLE;
  CmmUInt32		          m_TestMicHandle = NULL_AUDIO_FILE_HANDLE;

  CmmUInt32             ring_level_ = 0;
  CmmUInt32             test_ring_handle_ = NULL_AUDIO_FILE_HANDLE;

  CmmUInt32		          m_MicLevel = 0;

  CmmUInt32		          m_MaunalTestTime = 0;
  zui::State<CmmBool>   is_manual_record_wnd_show_ = CmmFalse;
  CmmBool              is_in_meeting_ = CmmFalse;
  
  VOICE_TYPE test_spk_type_ = TYPE_TEST;

  Cmm::CTimerID audio_setting_timer_;
  Cmm::CTimerID audio_setting_ring_timer_;

#if defined(ENABLE_UNIFIED_SETTING) && defined(__MACOS__)
  std::shared_ptr<CAudioDeviceSink> device_sink_;
#endif

protected:
  CAudioPanelDataModel();
  ~CAudioPanelDataModel();
};

class ZUIClient_API SettingPanelAudio : public zui::CustomView<SettingPanelAudio>
{
public:

  SettingPanelAudio(bool is_meeting_mode = false);
  ~SettingPanelAudio() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelAudio>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;

private:
  bool is_meeting_mode_ = false;
};

#define AudioPanelDataModel CAudioPanelDataModel::GetInstance()

#endif
