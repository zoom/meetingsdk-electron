#pragma once
#include "rawdata_audio_helper_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKAudioRawDataHelper* InitIZoomSDKAudioRawDataHelperFunc(IZoomSDKAudioRawDataDelegate* pEvent)
{
	IZoomSDKAudioRawDataHelper* pObj(NULL);
	pObj = CSDKImpl::GetInst().GetAudioRawdataHelper();
	if (pObj)
	{
		SetEvent(pEvent);
	}
	return pObj;
}

void UninitIZoomSDKAudioRawDataHelperFunc(IZoomSDKAudioRawDataHelper* obj)
{
	
}

//virtual SDKError subscribe(IZoomSDKAudioRawDataDelegate* pDelegate, bool bWithInterpreters = false, ZoomSDKSessionSource sources = SessionSource_CurrentSession) = 0;
SDKError IZoomSDKAudioRawDataHelperWrap::subscribe(IZoomSDKAudioRawDataDelegate* pDelegate, bool bWithInterpreters, ZoomSDKSessionSource sources)
{
	SetEvent(pDelegate);
	if (m_obj)
		return m_obj->subscribe(pDelegate, bWithInterpreters, sources);
	return SDKERR_UNINITIALIZE;
}

//virtual SDKError unSubscribe(ZoomSDKSessionSource sources = SessionSource_CurrentSession) = 0;
SDKError IZoomSDKAudioRawDataHelperWrap::unSubscribe(ZoomSDKSessionSource sources)
{
	if (sources == SessionSource_CurrentSession)
		SetEvent(NULL);
	if (m_obj)
		return m_obj->unSubscribe(sources);
	return SDKERR_UNINITIALIZE;

}
END_ZOOM_SDK_NAMESPACE