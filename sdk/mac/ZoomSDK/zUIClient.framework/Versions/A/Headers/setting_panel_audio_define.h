#pragma once

#include "ssb_media_client_def.h"
#include "cmmlib/CmmDef.h"
#include "cmmlib/CmmString.h"

typedef struct SettingAudioDevice
{
  Cmm::CString  device_id_;
  Cmm::CString  device_name_;
  CmmBool  select_device_ = CmmFalse;
  SSB_MC_AUDIO_DEVICE_API_TYPE device_type_ = SSB_MC_AUDIO_DEVICE_API_TYPE_SYSTEM_DEFAULT;
}CSettingAudioDevice;

