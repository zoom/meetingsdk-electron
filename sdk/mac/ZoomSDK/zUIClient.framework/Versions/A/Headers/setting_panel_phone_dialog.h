#ifndef _SETTING_PANEL_PHONE_DIALOG_H_
#define _SETTING_PANEL_PHONE_DIALOG_H_

namespace zui
{
enum DialogType {
  kBusinessHour,
  kCheckBusinessHour,
  kAddVoicemail,
  kIVRMenu,
  kForwardToAnotherExtension,
  kForwardToExternalContact,
  kForwardToExternalNumber,
  kAddBlocklistRule,
  kHolidayHour,
  kHolidayHourEditor,
  kHolidayHourDelete,
  kHolidayHourAlert,
};
}

struct DialogData
{
  bool show = true;
  NS_SIPCALL_APP::RoutingType routingType;

  bool operator==(const DialogData& other) const
  {
    return show == other.show && routingType == other.routingType;
  }
};

#endif
