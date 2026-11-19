#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingCloseCaptionWrap {
public:
	ZMeetingCloseCaptionWrap();
	virtual ~ZMeetingCloseCaptionWrap();

	void Init();
	void Uninit();
	void SetSink(ZNativeSDKCloseCaptionWrapSink* pSink);

	// interface methods
	ZNList<ZNLiveTranscriptionLanguage> GetAvailableMeetingSpokenLanguages();
	ZNList<ZNLiveTranscriptionLanguage> GetAvailableTranslationLanguages();
	ZNLiveTranscriptionLanguage GetTranslationLanguage();
	ZNSDKError SetTranslationLanguage(int languageID);
	ZNSDKError SetMeetingSpokenLanguage(int languageID, bool isForAll);
	ZNSDKError EnableCaptions(bool enable);
	ZNSDKError StartLiveTranscription();
	ZNSDKError StopLiveTranscription();
	ZNSDKError EnableReceiveSpokenLanguageContent(bool enable);
	bool IsReceiveSpokenLanguageContentEnabled();
	bool IsLiveTranscriptionFeatureEnabled();
	bool IsMultiLanguageTranscriptionEnabled();
	bool IsTextLiveTranslationEnabled();

	// callbacks
	void onLiveTranscriptionMsgInfoReceived(ZNLiveTranscriptionMessageInfo messageInfo);
	void onOriginalLanguageMsgReceived(ZNLiveTranscriptionMessageInfo messageInfo);
private:
	ZNativeSDKCloseCaptionWrapSink* m_pSink;
};