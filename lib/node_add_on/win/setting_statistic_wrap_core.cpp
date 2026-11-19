#include "setting_statistic_wrap_core.h"
#include "sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingStatisticWrap::ZSettingStatisticWrap()
{
}

ZSettingStatisticWrap::~ZSettingStatisticWrap()
{
	Uninit();
}

void ZSettingStatisticWrap::Init()
{
}

void ZSettingStatisticWrap::Uninit()
{
}

ZNSDKError ZSettingStatisticWrap::QueryOverallStatisticInfo(ZNOverallStatisticInfo& info)
{
	ZOOM_SDK_NAMESPACE::OverallStatisticInfo sdk_info;
	ZNSDKError err = ZNSDKERR_UNKNOWN;
	ZOOM_SDK_NAMESPACE::IStatisticSettingContext* pStatisticSettingContext = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().GetStatisticSettings();
	if (pStatisticSettingContext)
	{
		err = Map2WrapDefine(pStatisticSettingContext->QueryOverallStatisticInfo(sdk_info));
		info.net_work_type = Map2WrapDefine(sdk_info.net_work_type_);
		info.connection_type = Map2WrapDefine(sdk_info.connection_type_);
		if (NULL == sdk_info.proxy_addr_)
		{
			info.proxy_addr = L"";
		}
		else
		{
			info.proxy_addr = sdk_info.proxy_addr_;
		}
	}

	return err;
}
