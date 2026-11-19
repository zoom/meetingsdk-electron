#ifndef _SETTING_PANEL_ROOMS_H_
#define _SETTING_PANEL_ROOMS_H_

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

class ZUIClient_API CRoomsSettingDataModel : public IInitializable
{
public:
  static CRoomsSettingDataModel& GetInstance();
  static void ReleaseInstance();

  CRoomsSettingDataModel();
  ~CRoomsSettingDataModel();

  virtual void initializeState() override;
  virtual void initializeStateHandler() override;

  void UpdateZREnabled();
  void UpdateShowPairRoomFeature();
  void UpdateZoomRoomSettings();

public:
  zui::State<bool> _isZREnabled = true;
  zui::State<bool> _useZRAutoDetection = false;
  zui::State<bool> _useZRAutoDetectionWarningVisible = false;
  SwitchControl _showZRPairIcon;
  RadioGroupProperty _ShowPairMethod;
  zui::State<bool> _showIconMethod = false;

  enum ZMC_BehaviorAfterTransferMeeting
  {
    ZMC_BehaviorAfterTransferMeeting_AskEveryTime = 0,
    ZMC_BehaviorAfterTransferMeeting_AutoConnect = 1,
    ZMC_BehaviorAfterTransferMeeting_DontConnect = 2
  };
  DropDownProperty _zmcBehaviorAfterTransferMeeting;

  enum ZMC_BehaviorWhenZRMeetingEnds
  {
    ZMC_BehaviorWhenZRMeetingEnds_AskEveryTime = 0,
    ZMC_BehaviorWhenZRMeetingEnds_StayConnected = 1,
    ZMC_BehaviorWhenZRMeetingEnds_Disconnect = 2
  };
  DropDownProperty _zmcBehaviorWhenZRMeetingEnds;

  SwitchControl _AutoEnableCompanionMic;

private:
  static CRoomsSettingDataModel* _instance;
};

class ZUIClient_API SettingPanelRooms : public zui::CustomView<SettingPanelRooms>
{
public:
  SettingPanelRooms(bool is_meeting_mode = false);
  ~SettingPanelRooms();

  std::shared_ptr<zui::ViewNode> Build() override;

private:
  zui::View GetZoomRoomsView();
  zui::View GetZoomRoomsMeetingView();

private:
  zui::State<std::string> _bk_pair_with_room = std::string("");

  bool _is_meeting_mode = false;
};

#define RoomsPanelDataModel CRoomsSettingDataModel::GetInstance()

#endif
