#ifndef _SETTING_PANEL_ACCESSIBILITY_H_
#define _SETTING_PANEL_ACCESSIBILITY_H_

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
#include "zui_client_data_define.h"

class ZUIClient_API CAccessibilitySettingDataModel : public IInitializable
{
public:
  
    virtual void initializeState() override;

    virtual void initializeStateHandler() override;

    static CAccessibilitySettingDataModel& GetInstance();
    static void ReleaseInstance();
    
    CAccessibilitySettingDataModel();
    ~CAccessibilitySettingDataModel();
   
    void InitializeReaderAlertValue();
    void initiateChatDisplaySize(int initialChatDisplaySize);

    int GetCpationColorIndex();

    CmmUInt32 GetCaptionBackgroundColor(int index);

    void OnThemeChanged();
    void UpdateFontType();
    void UpdateCaptionTheme();
    void UpdateCaptionFontSize();
private:
  void InitializeReaderAlertNotify();
    void GetFontType(const int index, std::string& font);
    int GetFontIndex(const std::string& font);
    void InitCaptionColor(const int index);
public:
    zui::State<int> _chatDisplaySizeIndex = 1;//0 - 5
    zui::State<bool> _enableShareContentFlashDetection = false;
    zui::State<float> _closedCaptioningFontSize = 18.0f;//14.0f - 64.0f
    zui::State<bool> _alwaysShowCaptions = false;
    
    zui::State<int> _captionColorIndex = 0; //The caption color index 0 - 7

    zui::State<std::string> _captionColor = std::string("#FFFFFF");
    zui::State<std::string> _translationColor = std::string("#FFDC64FF");
    zui::State<std::string> _backgroundColor = std::string("#131619FF");

    zui::State<std::string> _captionFontType;

    DropDownBaseProperty _positionType;
    std::vector<std::string> _fonts; // need set fonts first
    DropDownBaseProperty _fontType;

    zui::State<bool> _readerIMChatReceived = true;
    zui::State<bool> _readerParticipantHasJoinedLeftMeeting = true;
    zui::State<bool> _readerParticipantHasJoinedLeftWaitingRoom = true;
    zui::State<bool> _readerAudioMutedByHost = true;
    zui::State<bool> _readerVideoStoppedByHost = true;
    zui::State<bool> _readerScreenSharing = true;
    zui::State<bool> _readerRecordingPermission = true;
    zui::State<bool> _readerPublicInMeetingChatReceived = true;
    zui::State<bool> _readerPrivateInMeetingChatReceived = true;
    zui::State<bool> _readerInMeetingFileReceived = true;
    zui::State<bool> _readerClosedCaptioningIsAvailable = true;
    zui::State<bool> _readerClosedCaptioningTypingPrivilege = true;
    zui::State<bool> _readerHostPrivilegeGranted = true;
    zui::State<bool> _readerCohostPrivilegeGranted = true;
    zui::State<bool> _readerRemoteControlGranted = true;
    zui::State<bool> _readerParticipantHasRaised = true;
    zui::State<bool> _readerLivestreamStarted = true;

#ifdef WIN32
    zui::State<bool> _readerQReceived= true;
    zui::State<bool> _readerAReceived = true;
    zui::State<bool> _readerChangeToPanelist = true;
    zui::State<bool> _readerChangeToAttendee = true;
#elif defined(__LINUX_CLIENT__)
    zui::State<int> _webFontSizeIndex = 0;
    zui::State<bool> _useCefGpu = false;            // WebView hardware acceleration (read from PARA_ENABLE_CEFGPU)
    zui::State<bool> _useSystembar = false;
    zui::State<bool> _hideCrashReport = false;
    zui::State<bool> _waylandSession = false;           // running in a Wayland session (controls parent visibility)
    zui::State<bool> _useNativeWayland = false;         // QtWayland platform plugin (vs XWayland)
    zui::State<bool> _useDesktopNotifications = false;  // visible only when _useNativeWayland is true
#endif


    SwitchControl _enableGIF{ true,true,false };

    unsigned int _captionColorsArray[8] = { 0x131619FF, 0xFFFFFFFF, 0x0F3433FF, 0xD5FFFDFF, 0x0D2151FF, 0xF0F5FFFF, 0x561221FF, 0xFFF1F2FF };
private:
    static CAccessibilitySettingDataModel* _instance;
};

class ZUIClient_API SettingPanelAccessibility : public zui::CustomView<SettingPanelAccessibility>
{
public:

  SettingPanelAccessibility(bool is_meeting_mode = false);
  ~SettingPanelAccessibility() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelAccessibility>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;
    
private:
    
    void onButtonRestore();
    zui::State<std::string> _bkColor_chat_size = std::string("");
    bool is_meeting_mode_ = false;
};

#define AccessibilityPanelDataModel CAccessibilitySettingDataModel::GetInstance()

#endif
