#ifndef _SETTING_PANEL_TEAM_CHAT_H_
#define _SETTING_PANEL_TEAM_CHAT_H_

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


class ZUIClient_API SettingPanelBlockedUsers : public zui::CustomView<SettingPanelBlockedUsers>
{
public:
    SettingPanelBlockedUsers();
    ~SettingPanelBlockedUsers() = default;
    
    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelBlockedUsers>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;
    
private:
    
    zui::State<std::vector<zui::any>> _allBlockedUsers;
};

// Data model for chat channel storage item
struct ZUIClient_API ChatChannelStorageData
{
    std::string channelName;    // Chat channel name (person/group)
    std::string channelID;      // Session ID (may be empty for non-existent sessions)
    std::vector<std::string> folderPaths;  // Folder paths (for delete API)
    size_t storageSizeBytes;    // Storage size in bytes
    zui::Checkbox::Status checked = zui::Checkbox::Status::kUnselected;

    std::string GetFormattedSize() const;

    bool operator==(const ChatChannelStorageData& other) const
    {
        return channelName == other.channelName &&
        channelID == other.channelID &&
        folderPaths == other.folderPaths &&
        storageSizeBytes == other.storageSizeBytes &&
        checked == other.checked;
    }
};

// Callback type for checkbox state change in chat storage list
using ChatStorageCheckboxCallback = std::function<void(size_t index, bool isSelected)>;

class ZUIClient_API CTeamChatSettingDataModel : public IInitializable
{
private:
    
public:
    
    static CTeamChatSettingDataModel& GetInstance();
    static void ReleaseInstance();
    
    CTeamChatSettingDataModel();
    ~CTeamChatSettingDataModel();

    virtual void initializeState() override;
    virtual void initializeStateHandler() override;

private:
    void InitIMIdleTimeSetting();

public:
  zui::State<bool> _showWhiteSidebarThemeOption = true;
    //Parameters in base view
    RadioGroupProperty _exclusiveSidebarLook = RadioGroupProperty{true,
        true,
        0};//0 white, 1 black
    RadioGroupProperty _radioMessageGrouping = RadioGroupProperty{true,
        true,
        0};//"Message grouping"
    RadioGroupProperty _radioOpenSectionsOrFolders = RadioGroupProperty{true,
        true,
        0};//"When opening sections or folders:"
    RadioGroupProperty _radioWhenViewingUnreadMessages = RadioGroupProperty{true,
        true,
        0};//"When viewing unread messages in a channel:"
    
    SwitchControl _toggleMoveMessages = SwitchControl{true,
        true,
        false};//"Move messages with new replies to the bottom of the chat"
    
    SwitchControl _toggleReadReceipts = SwitchControl{true,
        true,
        false};//"Read receipts"
    zui::State<std::string> _readReceiptsDetail = zui::State<std::string>("") ;
    
    SwitchControl _toggleCheckSpellingWhileTyping = SwitchControl{true,
        true,
        true}; // check spelling while typing
    SwitchControl _toggleCheckGrammarWithSpelling = SwitchControl{true,
        true,
        true}; // check grammar with spelling
    SwitchControl _toggleCorrectSpellingAutomatically = SwitchControl{true,
        true,
        true}; // correct spelling automatically
    
    zui::State<bool> _changeStatusVisible = true;
    zui::State<bool> _changeStatusEnable = true;
    zui::State<bool> _toggleChangeStatusOn = false;//"Change status to "Away" when inactive for:"
    zui::State<int> _dropChangeStatusIndex = 0;//"Change status to "Away" when inactive for:" minutes in int of index
    
#ifdef __MACOS__
    zui::State<bool> _bounceApplicationVisible = true;
    zui::State<bool> _bounceApplicationEnable = true;
    zui::State<bool> _toggleBounceApplicationIcon = false;//"Bounce application icon when receiving a new message" whether the toggle is on
    zui::State<int> _dropIndexBounceApplicationIcon = 0;//"Bounce application icon when receiving a new message" the index of the drop box, 0 once, 1 continuously
#endif
    
    SwitchControl _toggleShowLinkPreview = {true,
        true,
        false};//"Show link preview"

    zui::State<bool> _blockedUsersVisible = true;
    
    zui::State<bool> _languageVisible = true;
    zui::State<bool> _languageEnable = true;
    zui::State<std::list<std::string>> _dropLanguageStrings;//"Preferred message translation language:" all languages
    zui::State<int> _dropIndexLanguage = 0;//"Preferred message translation language:"
    void SetChangeStatusMinutes(int minutes);

    //Parameters in badge viewf
    DropDownProperty _dropDMsIndex = {true,
        true,
        0};//"DMs", The index of dropview in int
    DropDownProperty _dropChannelsIndex = {true,
        true,
        0};//"Channels", The index of dropview in int
    DropDownProperty _dropMeetingChatsIndex = {true,
        true,
        0};//"Meeting chats", The index of dropview in int
    DropDownProperty _dropSharedSpacesIndex = {true,
        true,
        0};//"Shared spaces", The index of dropview in int
    DropDownProperty _dropAppsIndex = {true,
        true,
        0};//"Apps", The index of dropview in int
    DropDownProperty _dropStarredIndex = {true,
        true,
        0};//"Starred", The index of dropview in int
    DropDownProperty _dropFoldersIndex = {true,
        true,
        0};//"Folders", The index of dropview in int
    
    SwitchControl _toggleShowUnreadCountForChannels = {true,
        true,
        true};//"Show unread count for Channels", whether the toggle is on
    SwitchControl _toggleShowUnreadCountForMeetingChats = {true,
        true,
        true};//"Show unread count for meeting chats", whether the toggle is on
    
    //The page controller
    zui::State<bool> _managingBadgeSettings = false;

    //Team Chat enabled
    zui::State<bool> _teamChatEnabled = true;

    zui::State<int> _timeFormatIndex = 0;

    // Chat Storage Manager data
    zui::State<bool> _showChatStorageManager = true;  // default YES, will not use anymore
    zui::State<std::vector<zui::any>> _chatStorageData;
    zui::State<bool> _chatStorageHasSelection = false;
    zui::State<bool> _chatStorageHasData = true;           // Whether there is any data in the list
    zui::State<bool> _chatStorageNoData = true;             // Inverse of _chatStorageHasData (for visible binding)
    zui::State<std::string> _chatStorageTotalText;
    zui::State<std::string> _chatStorageSelectedText;
    zui::State<std::string> _chatStorageGroupName;
    zui::State<std::string> _chatStorageCleanupProgress;   // Progress text like "(Deleting 1/15)"
    zui::State<bool> _chatStorageIsDeleting = false;       // Whether deletion is in progress
    
    // Chat Storage Manager methods
    void OnChatStorageCheckboxChanged(size_t index, bool isSelected);
    void SelectAllChatStorage();
    void DeselectAllChatStorage();
    void ClearSelectedChatStorage();
    void RefreshChatStorageData();

private:
    void UpdateChatStorageSelectedText();  // Update storage text display (Total storage: X MB Selected: Y MB)
    void UpdateChatStorageHasSelection();
    
public:
    
    // Storage size formatter utility - used by both ChatChannelStorageData and data model
    static std::string FormatStorageSize(size_t bytes);
    
private:
    static CTeamChatSettingDataModel* _instance;
};

class ZUIClient_API SettingPanelTeamChatBase : public zui::CustomView<SettingPanelTeamChatBase>
{
public:
    SettingPanelTeamChatBase();
    ~SettingPanelTeamChatBase() = default;
    
    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelTeamChatBase>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;
    
private:
    zui::View BuildLeftSidebarBehaviorGroup();
    zui::View BuildUnreadMessagesGroup();
#ifdef __MACOS__
    zui::View BuildSpellCheckGroup();
#endif
    zui::Bind<bool> GetChatPreferencesVisible();
    zui::View BuildChatPreferencesGroup();
    zui::View BuildMessageTranslationGroup();
    zui::View BuildChatStorageManagerGroup();
  
    zui::State<std::string> _bkColor_translation = std::string("");

};

class ZUIClient_API SettingPanelTeamChatDisabled : public zui::CustomView<SettingPanelTeamChatDisabled>
{
public:
    SettingPanelTeamChatDisabled() = default;
    ~SettingPanelTeamChatDisabled() = default;

    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelTeamChatDisabled>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;

private:
    zui::View BuildChatPreferencesGroup();

};


class ZUIClient_API SettingPanelTeamChatBadge : public zui::CustomView<SettingPanelTeamChatBadge>
{
public:
    SettingPanelTeamChatBadge();
    ~SettingPanelTeamChatBadge() = default;
    
    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelTeamChatBadge>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;
    
private:
    zui::View BuildNotifierToggle(const zui::Bind<std::string>& label, const zui::Bind<std::string>& accLabel, const zui::Bind<unsigned int>& value, zui::State<std::string>& bkcolor, const SwitchControl& property, const zui::Bind<std::string>& help, const std::string& telemetryId, zui::TelemetryModule telemetryModule);
    
private:
    zui::State<std::string> _bkColorChannels = std::string("");
    zui::State<std::string> _bkColorMeetingChats = std::string("");
};

class ZUIClient_API SettingPanelTeamChat : public zui::CustomView<SettingPanelTeamChat>
{
public:
    SettingPanelTeamChat();
    ~SettingPanelTeamChat() = default;
    
    std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelTeamChat>(*this); }
    std::shared_ptr<zui::ViewNode> Build() override;
    
private:
    
};

#define TeamChatPanelDataModel CTeamChatSettingDataModel::GetInstance()

#endif
