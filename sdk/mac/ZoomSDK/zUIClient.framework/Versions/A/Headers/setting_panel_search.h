#ifndef _SETTING_PANEL_SEARCH_H_
#define _SETTING_PANEL_SEARCH_H_

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

enum settingTabType {
  kTabGeneral,
  kTabVideo,
  kTabAudo,
  kTabNotification,
  kTabMeetings,
  kTabRecordings,
  kTabShareScreen,
  kTabPhone,
  kTabSipIntegration,
  kTabTeamChat,
  kTabRooms,
  kTabAccessibility,
  kTabStatistic,
};


struct SettingItem {
  std::string id;
  std::string name;
  std::string description;
  std::string keywords;
};

struct SettingTab {
  std::string name;
  std::string id;
  std::vector<SettingItem> itmes;
};


struct SettingSearchOption {
  std::string id;
  std::string name;
  std::string description;
  std::string keywords;
  std::string tabName;
  std::string tabId;
  std::string groupName;
  std::string groupId;
  settingTabType tabType;
  int score = 0;

  bool operator==(const SettingSearchOption& other) const
  {
    return id == other.id;
  }
};


struct SearchResultItem {
  settingTabType settingType;
  std::string tabName;
  std::string itemId;
  bool isAdvanced = false;

  bool operator==(const SearchResultItem& other) const
  {
    return itemId == other.itemId;
  }
};

class ZUIClient_API CSettingSearchDataInterface
{
public:
  virtual void Search(const std::string& keyworkd) = 0;
  virtual void SetSettingsTabVisible(const settingTabType settingType, const bool visible) = 0;
  virtual void StopSearch() = 0;
  virtual void AddVideoSettingControlNodes(zui::ZUIControlNode& node) = 0;
};


class ZUIClient_API SettingPanelSearch : public zui::CustomView<SettingPanelSearch>
{
public:

  SettingPanelSearch() = default;;
  ~SettingPanelSearch() = default;

  std::shared_ptr<zui::View> Clone() const override { return std::make_shared<SettingPanelSearch>(*this); }
  std::shared_ptr<zui::ViewNode> Build() override;

};

#endif //_SETTING_PANEL_SEARCH_H_
