#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingStatisticWrap
{
public:
	ZSettingStatisticWrap();
	virtual ~ZSettingStatisticWrap();
	void Init();
	void Uninit();

	ZNSDKError QueryOverallStatisticInfo(ZNOverallStatisticInfo& info_);
};
