#include "meeting_close_caption_wrap_core.h"
#include "meeting_service_components_wrap/meeting_closedcaption_ctrl_wrap.h"
#include "sdk_events_wrap_class.h"
#include "sdk_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

// Helper function to convert zchar_t* to ZoomSTRING.
// Note: Returns an empty string if zchar_t* is NULL.
ZoomSTRING ZCharToZoomSTRING_close_caption(const zchar_t *zstr)
{
	return zstr ? ZoomSTRING(zstr) : ZoomSTRING();
}

// Helper function to convert ILiveTranscriptionLanguage to ZNLiveTranscriptionLanguage.
ZNLiveTranscriptionLanguage GetZNLiveTranscriptionLanguage(ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *language_info)
{
	ZNLiveTranscriptionLanguage zn_language_info;
	if (NULL == language_info) {
		return zn_language_info;
	}

	zn_language_info.languageName = ZCharToZoomSTRING_close_caption(language_info->GetLTTLanguageName());
	zn_language_info.languageID = language_info->GetLTTLanguageID();

	return zn_language_info;
}

ZMeetingCloseCaptionWrap::ZMeetingCloseCaptionWrap() : m_pSink(NULL)
{
	SDKEventWrapMgr::GetInst().m_closeCaptionControllerEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingCloseCaptionWrap::~ZMeetingCloseCaptionWrap() 
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_closeCaptionControllerEvent.SetOwner(NULL);
}

void ZMeetingCloseCaptionWrap::Init() 
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().SetEvent(&SDKEventWrapMgr::GetInst().m_closeCaptionControllerEvent);
}
void ZMeetingCloseCaptionWrap::Uninit() 
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().Uninit_Wrap();
}
void ZMeetingCloseCaptionWrap::SetSink(ZNativeSDKCloseCaptionWrapSink *pSink) 
{
	m_pSink = pSink;
}

void ZMeetingCloseCaptionWrap::onLiveTranscriptionMsgInfoReceived(ZNLiveTranscriptionMessageInfo messageInfo) 
{
	if (m_pSink) {
		m_pSink->onLiveTranscriptionMsgInfoReceived(messageInfo);
	}
}
void ZMeetingCloseCaptionWrap::onOriginalLanguageMsgReceived(ZNLiveTranscriptionMessageInfo messageInfo) 
{
	if (m_pSink) {
		m_pSink->onOriginalLanguageMsgReceived(messageInfo);
	}
}
ZNList<ZNLiveTranscriptionLanguage> ZMeetingCloseCaptionWrap::GetAvailableMeetingSpokenLanguages()
{
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *> *language_list;
	language_list = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().GetAvailableMeetingSpokenLanguages();

	ZNList<ZNLiveTranscriptionLanguage> zn_language_list;
	if (language_list == nullptr) {
		return zn_language_list;
	}
	for (int i = 0; i < language_list->GetCount(); ++i) {
		ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *language_info = language_list->GetItem(i);
		zn_language_list.push_back(GetZNLiveTranscriptionLanguage(language_info));
	}
	return zn_language_list;
}

ZNList<ZNLiveTranscriptionLanguage> ZMeetingCloseCaptionWrap::GetAvailableTranslationLanguages()
{
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *> *language_list;
	language_list = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().GetAvailableTranslationLanguages();

	ZNList<ZNLiveTranscriptionLanguage> zn_language_list;
	if (language_list == nullptr) {
		return zn_language_list;
	}
	for (int i = 0; i < language_list->GetCount(); ++i) {
		ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *language_info = language_list->GetItem(i);
		zn_language_list.push_back(GetZNLiveTranscriptionLanguage(language_info));
	}
	return zn_language_list;
}

ZNLiveTranscriptionLanguage ZMeetingCloseCaptionWrap::GetTranslationLanguage()
{
	ZOOM_SDK_NAMESPACE::ILiveTranscriptionLanguage *language;
	language = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().GetTranslationLanguage();

	ZNLiveTranscriptionLanguage zn_language;
	if (language == nullptr) {
		return zn_language;
	}

	zn_language = GetZNLiveTranscriptionLanguage(language);
	return zn_language;
}

ZNSDKError ZMeetingCloseCaptionWrap::SetTranslationLanguage(int languageID)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().SetTranslationLanguage(languageID);
	return Map2WrapDefine(sdkerr);
}

ZNSDKError ZMeetingCloseCaptionWrap::SetMeetingSpokenLanguage(int languageID, bool isForAll)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().SetMeetingSpokenLanguage(languageID, isForAll);
	return Map2WrapDefine(sdkerr);
}

ZNSDKError ZMeetingCloseCaptionWrap::EnableCaptions(bool enable)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().EnableCaptions(enable);
	return Map2WrapDefine(sdkerr);
}

ZNSDKError ZMeetingCloseCaptionWrap::StartLiveTranscription()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().StartLiveTranscription();
	return Map2WrapDefine(sdkerr);
}

ZNSDKError ZMeetingCloseCaptionWrap::StopLiveTranscription()
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().StopLiveTranscription();
	return Map2WrapDefine(sdkerr);
}

ZNSDKError ZMeetingCloseCaptionWrap::EnableReceiveSpokenLanguageContent(bool enable)
{
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN;
	sdkerr = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().EnableReceiveSpokenLanguageContent(enable);
	return Map2WrapDefine(sdkerr);
}

bool ZMeetingCloseCaptionWrap::IsReceiveSpokenLanguageContentEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().IsReceiveSpokenLanguageContentEnabled();
}

bool ZMeetingCloseCaptionWrap::IsLiveTranscriptionFeatureEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().IsLiveTranscriptionFeatureEnabled();
}

bool ZMeetingCloseCaptionWrap::IsMultiLanguageTranscriptionEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().IsMultiLanguageTranscriptionEnabled();
}

bool ZMeetingCloseCaptionWrap::IsTextLiveTranslationEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingClosedCaptionController().IsTextLiveTranslationEnabled();
}