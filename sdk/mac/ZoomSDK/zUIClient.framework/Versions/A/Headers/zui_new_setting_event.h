#pragma once
#include "zUI/zui_base.h"

enum class SmsAutoReplyActionType : CmmInt32
{
  kBusinessHours = 0, // Do Not Disturb
  kClosedHours = 1
};

enum class ZUINewSettingEvent
{
  // common event
  kEventCopyBtnClicked, // wParam: CString

  // general
  kEventGeneralPageBegin,
  kEventClearZoomAppsCache,//zUIClient does nothing but calling out
  kEventResetNavigationBar,//zUIClient calles zpref::zPolicy_TopNavigationOrderVisibility
  kEventAppearanceChanged,//zUIClient calles Cmm::GetAppContext()::SetInt before calling out
  kEventGeneralCopyCurrentVersionClicked, // wParam: CString
  kEventGeneralCopyAllVersionsClicked, // wParam: CString
  kEventGeneralRequestZoomWorkplaceVersions, // native should provide versions through CGeneralSettingDataModel::SetZoomWorkplaceVersions
  KEventReationSkinChanged,
  kEventPinZoomToStatusbar,
  KEventOpenDiagnosticDataViewer,
  KEventShowZRPairIcon,
  KEventShowZRPairMethod,
  KEventAutoDetectionZR,
  KEventMeetingAssistant,
  KEventPhoneAssistant,
  KEventHidePhoneAssistantWhenNoCall,
  KEventOpenBluetoothSystemSettings,
  KEventDebugRuntimeTestChanged, // toogle on / off 
  KEventDebugSwitchChanged, // toogle on / off 
  KEventDebugAutoMationChanged, // toogle on / off 
  KEventDebugOpenUnifiedSettings, // toogle on / off
  KEventDebugOpenNewHomePage, // toogle on / off
  kEventDebugEnableStandaloneMeeting, // toogle on / off
  kEventManageAICompanion,
  kEventGeneralPageEnd,

  // meeting
  kEventMeetingPageBegin,
  KEventOpenSettings, // Open the standalone settings window from meeting settings panel
  kEventKeepZoomAppsOpen,
  kEventAutoEnableDualMonitor,
  kEventShowNameTagInRender,
  kEventShowMeetingTimer,
  kEventShowAvatarInMeetingChat,
  kEventAlwaysShowMeetingControl,
  kEventHideMeetingSelfView,
  kEventEnableSpotlightSelf,
  kEventAutoHideNoVideoUsers,
  kEventEnable49Video,
  kEventShowMyReactionOnToolBar,
  kEventEnableMeetingAnimatedReactions,
  kEventEnableHandGestureCapture,
  kEventShowIncommingVideo,
  kEventResetMeetingDisclaimers,
  KEventAppItemSelectedChange,
  kEventAppsManageBtnClicked,
  kEventAppsPageBackBtnClicked,
  kEventGeneralLinkClicked,
  kEventEnablePushToTalk,
  KEventSetWallpaper,
  KEventWhoCanUnmuteYou,
  KEventClickManageApps,
  kEventMeetingPageEnd,

  // audio
  kEventAudioPageBegin,
  kEventMicDeviceChanged,
  kEventSpeakerDeviceChanged,
  kEventTestSpeakerVolumeChanged,
  kEventRingerDeviceChanged,
  kEventSpatialAudioChanged,
  kEventSyncAudioDeviceInfo,
  kEventEnableSuppressBackgroundNoiseHigh,
  kEventVoicePrintCreate,
  kEventVoicePrintUpdate,
  kEventVoicePrintDeleteAll,
  kEventVoicePrintDeleteAuto,
  kEventSyncAudioDeviceInfoForSipCall,
  kEventEnablePAI,
  kEventBtnAudioInputChannelsClicked,
  kEventAudioProfileChanged,
  kEventSpatialAudioSettingChanged,
  kEventVoicePrintSmartRecognitionCreate,
  kEventVoicePrintSmartRecognitionUpdate,
  kEventSmartRecognitionSettingClicked,
  kEventNotSupportLivePerformance,
  kEventEnableHIDControl,
  kEventAirPodsHIDControl,
  kEventAudioPageEnd,

  // phone
  kEventPhonePageBegin,
  kEventMyAccountLinkClicked,
  kEventDirectNumberCopyClicked,
  kEventCompanyNumberCopyClicked,
  kEventPersonalLocationOrLinkClicked,
  kEventLocationPermissionChanged,
  kEventSipModeLocationPermissionChanged,
  kEventCallDefaultChanged,// MAC call perference
  kEventTransLanguageChanged,
  kEventTranslationLanguageChanged,
  kEventAutoAnswerCQPeriodChanged,
  kEventCallControlManageClicked,
  kEventLaunchAppForIncomingCallsChanged,  // toggle on / off
  kEventLaunchAppForIncomingUrlParamChanged,   // edit control URL changed.
  kEventLaunchAppForIncomingUrlBrowseClicked,  // Launch app Or Url ,browse to select url 
  kEventLaunchAppForIncomingUrlTestClicked,    // Launch app Or Url , test 
  kEventHideZRAChanged, // Hide ZRA, toggle on /off
  kEventEditCallOutClicked,   // Call me on , list item edit
  kEventDeleteCallOutClicked,   // Call me on , list item edit
  kEventCallOutChanged,   // call me on , toggle on / off
  kEventAutoLiveTranscriptChange,  // Live transcript setting, toggle change.
  kEventAutoMyNotesChange, // Auto-start My notes setting, toggle change.
  kEventManageEmergencyAddressClicked,
  kEventUpdateEmergencyAddressClicked,
  kEventConfirmEmergencyAddressClicked,
  kEventAddEmergencyAddressClicked,
  kEventVideoGreetingRecordClicked,
  kEventVideoGreetingViewClicked,
  kEventVideoGreetingDeleteClicked,
  kEventVoicemailPrioritizationChanged,  // toogle on / off 
  kEventVoicmailManagePrioritizationClicked,  // manage button.
  kEventReportProblemClicked,
  kEventShowWebRTCClicked,   // show webrtc controller button.
  kEventShowPhoneWebviewClicked,
  kEventRingToneSetUpClicked,  // jump to ringtone page.
  kEventLocationHelperDLClicked, // MAC only, download and install location helper
  kEventVideoGreetingToggleChanged,
  kEventForwardToAnExternaleNumber,
  kEventSMSDelegationReplyToggleChanged,
  kEventSmsAutoReplySetMessage,
  kEventSmsAutoReplyEditMessage,
  kEventSmsAutoReplyDeleteMessage,
  kEventSmsAutoReplyToggleChanged,
  kEventMyPhoneSettingUrlClicked,
  kEventRestorePreviousVersionClicked,
  kEventUpgradeToNewExperienceClicked,
  // Phone audio detail page. The native Phone audio controller owns these
  // operations so they cannot fall through to the Meeting Audio controller.
  kEventPhoneAudioSettingsPageEntered,
  kEventPhoneAudioSettingsPageExited,
  kEventPhoneAudioTestSpeakerClicked,
  kEventPhoneAudioTestMicrophoneClicked,
  kEventPhoneAudioSpeakerVolumeChanged, // wParam: CmmUInt32, 0-255
  kEventPhoneAudioMicrophoneVolumeChanged, // wParam: CmmUInt32, 0-255
  // Fired after the Phone audio device policy is updated, so the native layer can
  // re-apply the Phone device to the SIP call engine (ConfigureSIPCallAudioDevice).
  kEventPhoneAudioDeviceChanged,
  kEventBlocklistManageClicked,  // Blocklist manage button clicked
  kEventBlocklistAddClicked,  // Blocklist add button clicked
  kEventBlocklistUnblockClicked,  // Blocklist unblock button clicked

  // Window only
  kEventOpenDialogInPT,
  kEventRequestBusinessHourEx,
  kEventRequestRoutingEx,
  kEventRequestAvailableLibraries,
  kEventUpdateRoutingEx,
  kEventRequestPlayUrl,
  kEventOnRequestPlayUrlDone,
  kEventPhonePageEnd,

  // statistic
  kEventStatisticPageBegin,
  kEventRegisterIDCopyClicked,
  KEventGetPhoneStatisticData,
  KEventGetSIPPhoneStatisticData,
  KEventGetCPUDataForZoom,
  kEventStatisticsReportProblemClicked,
  kEventStatisticsTestMeetingClicked,
  kEventStatisticPageEnd,
  
  //Accessibility
  kEventAccessibilityPageBegin,
  kEventChatDisplaySize,//zUIClient does nothing but calling out, wParam is the selected index from 0 to 5, lParam is the chat display size: 80 - 200
  kEventEnableShareContentFlashDetection,//zUIClient calles ICmmShareConfig::EnableShareContentFlashDetection and then call out, wParam is the check status
  kEventClosedCaptioningFontSize,//zUIClient calles Cmm::GetAppContext()::SetInt(kZoomClosedCaptionFontSize) before calling out, wParam is the font size in CmmInt32 from 14 to 32
  kEventCaptionColorIndex,//zUIClient calles Cmm::ISSBAppContext::SetKeyValue before calling out, wParam is the selected index from 0 to 4, lParam is the color value in unsigned int
  kEventCaptionColorPicker,//zUIClient does nothing but calling out, lParam is the current color value of index 5 in int, wParam indicates whether the customized caption color is selected in bool
  
  kEventTranslationColorIndex,//zUIClient calles Cmm::ISSBAppContext::SetKeyValue before calling out, wParam is the selected index from 0 to 4, lParam is the color value in unsigned int
  kEventTranslationColorPicker,//zUIClient does nothing but calling out, lParam is the current color value of index 5 in int, wParam indicates whether the customized caption color is selected in bool

  kEventBackgroundColorIndex,
  kEventBackgroundColorPicker,

  kEventWebviewFontSizeIndex,
  kEventUseCefGpuChanged,
  kEventUseSystemBarChanged,
  kEventHideCrashReportChanged,
  kEventUseNativeWaylandChanged,
  kEventUseDesktopNotificationsChanged,

  kEventAlwaysShowCaption,//zUIClient calles Cmm::GetAppContext::SetBool before calling out, wParam is the check status in bool
  kEventRestoreDefaults,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, no parameters are filled
  
  kEventIMChatReceived,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventParticipantHasJoinedMeeting,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventParticipantHasJoinedWaitingRoom,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventAudioMutedByHost,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventVideoStoppedByHost,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventScreenSharingStartedStopped,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventRecordingPermission,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventPublicInMeetingChatReceived,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventPrivateInMeetingChatReceived,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventInMeetingFileUploadCompleted,//zUIClient calles zpref::zPolicy_SetAccEventsOptions before calling out, wParam is the check status
  kEventAccessibilityPageEnd,


  //recording
  kEventRecordingPageBegin,
  kEventOpenStorePath,
  kEventChangeStorePath,
  kEventKeepUnconvertedFilesStatusChanged,
  kEventRecordingPageEnd,

  //share screen
  kEventShowZoomWindowWhenSharingChanged,
  kEventWayLandShareModeChanged,
  kEventAutoGrabRemoteControlChanged,
  kEventRemoteControlSecondsChanged,

    //Team chat
    kEventTeamChatPageBegin,
    kEventSidebarLook,//wParam is the index of the buttons, 0 white, 1 black
    kEventSidebarMessageGrouping,//wParam is the index of the radio 0 or 1, int
    kEventSidebarOpenSectionsOrFolders,//wParam is the index of the radio 0 or 1, int
    //kEventManageBadgeSettings,//Handled in zUI
    kEventResetLeftSidebarToDefault,
    kEventWhenViewingUnreadMessages,//wParam is the index of the radio 0 or 1, int
    kEventMoveMessages,//wParam is the status of the toggle true or false, bool
    kEventReadReceipts,//wParam is the status of the toggle true or false, bool
    kEventManageBlockedUsers,
    kEventChangeStatusMinutes,//wParam is the minutes in int, -1 indicates toggle is off
#ifdef __MACOS__
    kEventBounceApplicationIcon,//Mac only, wParam is the toggle true or false in bool, lParam is the index of drop box, 0 once, 1 continuously in int
    kEventCheckSpellingWhileTyping,
    kEventCheckGrammarWithSpelling,
    kEventCorrectSpellingAutomatically,
#endif
    kEventCleanupSelectedSessionsMediaCache,
    kEventCleanupProgress,        // wParam: current count (size_t), lParam: total count (size_t)
    kEventCleanupCompleted,       // wParam: total freed bytes (size_t), lParam: success (bool)
    kEventShowLinkPreview,//wParam is the toggle true or false, bool
    kEventPreferedLanguage,//wParam is the name of the language, std::string, like: Chinese, lParam is the index in int
    kEventTimeFormat,
    
    //Below are events of badge view
    kEventBadgeDMs,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeChannels,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeMeetingChats,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeSharedSpaces,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeApps,//wParam is the index of the dropview in int, 0 "All messages", 1 "Off"
    kEventBadgeStarred,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeFolders,//wParam is the index of the dropview in int, 0 "All messages", 1 "Mentions only", 2 "Off"
    kEventBadgeShowUnreadCountForChannels,//"Show unread count for Channels", wParam is the bool of the toggle value in bool
    kEventBadgeShowUnreadCountForMeetingChats,//"Show unread count for Channels", wParam is the bool of the toggle value in bool
    kEventTeamChatPageEnd,

    //notifications and sounds
    kEventNotificationsPageBegin,
    kEventShareLineGroupContactClick,
    kEventCallQueuesContactClick,
    kEventShareLineAppearanceContactClick,
    kEventCustomRingToneManageClick,
    kEventPlayNewChatMsgSoundSwitchChanged,
    kEventPlayNewEmailSoundSwitchChanged,
    kEventRingtoneSyncRingtonesSetting,

    kEventSetDoNotDisturbSwitchChanged,
    kEventSetDoNotDisturbStartTimeChanged,
    kEventSetDoNotDisturbStopTimeChanged,

    kEventHidePhoneCallsSwitchChanged,
    kEventHidePhoneCallsOptionsChanged,

    kEventHideChatNotiDuringMeetingsSwitchChanged,
    kEventOpenNewChatWindowSwitchChanged,
    kEventShowMsgPreviewSwitchChanged,
    kEventShowDesktopNotiUntilDismissedSwitchChanged,

    kEventNewChatMessagesSwitchChanged,
    kEventNewChatMessagesOptionChagned,

    kEventChatManageClick,
    kEventChatKeywordsManageClick,
    kEventChatContactsManageClick,
    kEventNewEmailsSwitchChanged,
    KEventOpenActiveCenter,
    KEventOpenSystemNotifications,
    KEventCCINotificationsChange,
    kEventNotificationsPageEnd,
    
    //Accessibility
    kEventSelectCustomColor,// wParam is the color type, 0 caption color, 1 translation color, int

    kEventSearchJump,
    kEventNotifyFocusResult,
    kEventNotifySearchResult,
    
    kEventGetWindowHandle,
    kEventStatisticsLaunchVDIToolClicked,

    // Phone: copy the phone web version to the clipboard. Appended at the END so no existing
    // enum value shifts (ABI-safe). Falls OUTSIDE the kEventPhonePageBegin..kEventPhonePageEnd
    // range, so ZMSettingEventHandler routes it to the phone tab via an explicit case.
    kEventCopyPhoneWebVersionClicked, // copy the phone web version to the clipboard
};
struct ZUIClientSettingEventParam {
  ZUINewSettingEvent messageType;
  zui::any wParam;
  zui::any lParam;
};

class CZUINewSettingEventHandler
{
public:
  virtual void OnSettingUIEvent(ZUIClientSettingEventParam& event) = 0;
};
