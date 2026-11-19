#ifndef _CONF_VOICE_TRANSLATION_H_
#define _CONF_VOICE_TRANSLATION_H_

#ifdef _WIN32
#include "zUI/view.h"
#include "zUI/basic_button.h"
#include "zUIClient/zUI_stdafx.h"
#elif defined __MACOS__
#import <zUI/view.h>
#import <zUI/basic_button.h>
#import <zUIClient/zUI_stdafx.h>
#else
#include "view.h"
#include "basic_button.h"
#include "zUI_stdafx.h"
#endif
#include "zUIClient/zui_client_data_define.h"
#include "zVideoApp/CmmAIInterpretation.h"
#include "zm_conf_universal_ui/zm_conf_universal_ui_interface.h"
#include "zm_conf_universal_ui/zm_conf_uui_ai_interpretation_interface.h"
class CVoiceTranslationDataModel;

class ZUIClient_API ZuiAIInterpretationUniversalUiSink : public NS_ZM_CONF_UNIVERSAL_UI::IAiInterpretationUniversalUiSink
{
public:
  ZuiAIInterpretationUniversalUiSink(CVoiceTranslationDataModel* model);
  virtual ~ZuiAIInterpretationUniversalUiSink();
  
  virtual void OnAIInterpretationStart() override;
  virtual void OnAIInterpretationStop() override;
  virtual void OnAIInterpretationSpeakerModeStart() override;
  // Only override the WithReason variant; the no-arg variant is intentionally
  // not overridden so the same stop event isn't handled twice.
  virtual void OnAIInterpretationSpeakerModeStopWithReason(NS_ZM_CONF_UNIVERSAL_UI::UuiVoiceTranslationStopReason stop_reason) override;
  virtual void OnLivePerformanceAudioStatusChanged() override;
  virtual void OnAIInterpSpeakingLanguageChanged() override;
  virtual void OnMeetingAIInterpSpeakingLanguageChanged(CMM_USERID user_id, CmmBool is_speak_on, LTT::LTTLanguageID speak_lang, CmmBool is_translatable) override;

  virtual void OnTestVoiceStarted() override;
  virtual void OnTestVoiceStopped() override;
  virtual void OnTestVoicePaused() override;
  virtual void OnTestVoiceResumed() override;
  virtual void OnTestVoiceProgressChanged(float progress, CmmInt64 current_time, CmmInt64 duration) override;
  virtual void OnVoiceResourceReadyChanged(bool is_ready) override;
  virtual void OnAIInterpretationVoiceResourceDownloaded(const std::vector<CmmInt32>& list) override;
  virtual void OnMyAudioTypeChanged() override;
  virtual void OnVoiceTranslatorEngineUpdated(const CString& engine_name, CmmInt32 result, const CString& error_msg, CmmBool write_user_profile_ret) override;
  virtual void OnHideFeedbackEntrance() override;

private:
  CVoiceTranslationDataModel* model_;
};

class ZUIClient_API CVoiceTranslationDataModel : public IInitializable
{
public:
  
  virtual void initializeState() override;
  virtual void initializeStateHandler() override;

  static CVoiceTranslationDataModel& GetInstance();
  CVoiceTranslationDataModel();
  ~CVoiceTranslationDataModel();
  
  void StopTranslation();
  void RefreshSpeakingLanguage();
  bool IsJoinByTelephone();

  zui::State<std::vector<std::string>> _speakingLanguageOptions;
  zui::State<std::vector<std::string>> _languageOptions;
  zui::State<std::vector<std::string>> _voiceOptions;
  zui::State<std::vector<std::string>> _voiceEngineOptions;
  zui::State<std::vector<std::string>> _speakermodeLanguageOptions;
  zui::State<int> _selectedSpeakingLanguageIndex;
  zui::State<int> _selectedLanguageIndex;
  zui::State<int> _selectedVoiceIndex;
  zui::State<int> _selectedVoiceEngineIndex = 0;
  zui::State<bool> _showVoiceEngineSelector = false;
  zui::State<int> _selectedSpeakermodeLanguageIndex;
  zui::State<bool> _isSpeakerModeEnabled = false;
  zui::State<float> _balanceVolume;
  zui::State<std::string> _originalVolumePercent = std::string("30%");
  zui::State<std::string> _translatedVolumePercent = std::string("70%");
  zui::State<std::string> _originalVolumeIcon;
  zui::State<std::string> _translatedVolumeIcon;
  zui::State<bool> _enableCaptions;
  zui::State<bool> _isTestVoicePlaying = false;
  zui::State<bool> _isTestVoicePaused = false;
  zui::State<bool> _isVoiceResourceReady = false;
  zui::State<bool> _isDownloadingVoice = false;
  zui::State<float> _testVoiceProgress = 0.0f;
  zui::State<std::string> _stopButtonLabel = std::string("");
  zui::State<zui::BasicButton::Style> _stopButtonStyle = zui::BasicButton::Style::kPrimary;
  zui::State<std::string> _testVoiceTime = std::string("00:00 / 00:00");
  zui::State<std::string> _testVoiceAxDescription = std::string("");
  zui::State<std::string> _playPauseButtonIcon = std::string("");
  zui::State<std::string> _playPauseButtonAxLabel = std::string("");
  zui::State<std::string> _pauseButtonIdObserver = std::string("");
  zui::State<std::string> _stopButtonIdObserver = std::string("");
  zui::State<bool> _showTrialBanner = false;
  zui::State<std::string> _trialBannerTitle = std::string("");
  zui::State<std::string> _trialBannerDescription = std::string("");
  zui::State<bool> _hasVoiceTranslatorPanelCoachmark = false;
  CmmZpnsCoachmark _voiceTranslatorPanelCoachmark;
  zui::State<bool> _isJoinByTelephone = false;
  zui::State<bool> _isAnyTranslationStarted = false;
  // True when Live Performance Audio (Original Sound for Musicians) is on.
  // While true, "Translate your voice" must be disabled and an info icon
  // explains why next to the dropdown label.
  zui::State<bool> _isLivePerformanceAudioEnabled = false;
  // Mirrors the persistent zPolicy_HasShownVoiceTranslatePopover flag — once
  // the "Try translate your voice" popover has been shown to the user, this is
  // flipped to true so it won't re-appear within the same view lifetime. The
  // policy is updated in parallel so the choice survives app restarts.
  zui::State<bool> _hasShownVoiceTranslatePopover = false;
  zui::State<std::string> _popupTitle = std::string("");
  zui::State<std::string> _popupDescription = std::string("");
  zui::State<bool> _showPopupDescription = false;
  zui::State<bool> _showPopupSpeakingLangSection = false;
  zui::State<bool> _showPopupStopButton = false;
  zui::State<bool> _showFeedbackUi = false;
  zui::State<NS_ZM_CONF_UNIVERSAL_UI::UuiVoiceTranslationFeedbackStatus> _feedbackStatus =
      NS_ZM_CONF_UNIVERSAL_UI::UuiVoiceTranslationFeedbackStatus::kNone;
  CmmUInt32 _testVoiceHandle = NULL_AUDIO_FILE_HANDLE;
  CmmInt64 _testVoiceDuration = 0;
  bool _focusStopButtonOnTestVoiceStoppedAx = true;

  void CheckVoiceResourceReady();
  void CheckAndDownloadVoiceResource();
  void StartTestVoice();
  void StopTestVoice(bool focusStopButtonOnStoppedAx = true);
  void PauseTestVoice();
  void ResumeTestVoice();
  void SubmitThumbsUpFeedback();
  void SubmitThumbsDownFeedback();
  void NotifyVoiceTranslationPanelHide();

  void SetVoiceTranslatorPanelCoachmark(const CmmZpnsCoachmark& coachmark,
                                        const std::string& title,
                                        const std::string& description);
    
  NS_ZM_CONF_UNIVERSAL_UI::ConfInstParam GetConfInstParam();
  
private:
  void EnsureUuiSinkRegistered();
  CmmInt32 GetCurrentVoiceIndex();
  void UpdateVolumePercentLabels();
  void InitializeVoiceEngineSelector(NS_ZM_CONF_UNIVERSAL_UI::IAiInterpretationUi* uui,
                                     const NS_ZM_CONF_UNIVERSAL_UI::ConfInstParam& param);
  
  std::shared_ptr<ZuiAIInterpretationUniversalUiSink> uui_sink_ = nullptr;
  NS_ZM_CONF_UNIVERSAL_UI::IAiInterpretationUi* last_uui_instance_ = nullptr; 
};

class ZUIClient_API CTrialBannerView : public zui::CustomView<CTrialBannerView>
{
public:
  CTrialBannerView(zui::State<std::string> title, zui::State<std::string> description, std::function<void()> onClose);
  ~CTrialBannerView() = default;

  std::shared_ptr<zui::View> Clone() const override;
  std::shared_ptr<zui::ViewNode> Build() override;

private:
  zui::State<std::string> _title;
  zui::State<std::string> _description;
  std::function<void()> _onClose;
};

class ZUIClient_API CConfVoiceTranslationView : public zui::CustomView<CConfVoiceTranslationView>
{
public:
  CConfVoiceTranslationView();
  ~CConfVoiceTranslationView() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<CConfVoiceTranslationView>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;
};

#define VoiceTranslationDataModel CVoiceTranslationDataModel::GetInstance()

#endif
