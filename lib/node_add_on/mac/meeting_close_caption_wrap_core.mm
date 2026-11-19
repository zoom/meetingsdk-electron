#include "Header_include.h"
#include "sdk_native_error.h"
#include "meeting_close_caption_wrap_core.h"
#include "meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"

ZMeetingCloseCaptionWrap &ZMeetingServiceWrap::GetMeetingCloseCaptionCtrl()
{
    return m_close_caption_ctrl;
}
ZMeetingCloseCaptionWrap::ZMeetingCloseCaptionWrap()
{
    m_pSink = 0;
}

ZMeetingCloseCaptionWrap::~ZMeetingCloseCaptionWrap()
{
    m_pSink = 0;
    [[[[ZoomSDK sharedSDK] getMeetingService] getMeetingCloseCaptionController] setDelegate:nil];
}

void ZMeetingCloseCaptionWrap::SetSink(ZNativeSDKCloseCaptionWrapSink *pSink)
{
    [[[[ZoomSDK sharedSDK] getMeetingService] getCloseCaptionController] setDelegate:[[meetingServiceCloseCaptionDelegate alloc] init]];
    m_pSink= pSink;
}

void ZMeetingCloseCaptionWrap::Init()
{

}
void ZMeetingCloseCaptionWrap::Uninit()
{
    
}

ZNList<ZNLiveTranscriptionLanguage> ZMeetingCloseCaptionWrap::GetAvailableMeetingSpokenLanguages()
{
    ZNList<ZNLiveTranscriptionLanguage> list;

    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return list;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return list;

    NSArray *arr = [closeCaptionController getAvailableMeetingSpokenLanguages];
    if (arr && arr.count > 0)
    {
        for (ZoomSDKLiveTranscriptionLanguage* languageInfo in arr)
        {
            if (languageInfo)
            {
                ZNLiveTranscriptionLanguage zn_languageInfo;

                // languageName
                ZoomSTRING zn_languageName;
                NSString *languageName = languageInfo.languageName;
                if (languageName)
                {
                    zn_languageName = [languageName UTF8String];
                }
                else
                {
                    zn_languageName = "";
                }
                zn_languageInfo.languageName = zn_languageName;

                // languageID
                zn_languageInfo.languageID = languageInfo.languageID;

                list.push_back(zn_languageInfo);
            }
        }
    }
    return list;
}

ZNList<ZNLiveTranscriptionLanguage> ZMeetingCloseCaptionWrap::GetAvailableTranslationLanguages()
{
    ZNList<ZNLiveTranscriptionLanguage> list;

    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return list;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return list;

    NSArray *arr = [closeCaptionController getAvailableTranslationLanguages];
    if (arr && arr.count > 0)
    {
        for (ZoomSDKLiveTranscriptionLanguage* languageInfo in arr)
        {
            if (languageInfo)
            {
                ZNLiveTranscriptionLanguage zn_languageInfo;

                // languageName
                ZoomSTRING zn_languageName;
                NSString *languageName = languageInfo.languageName;
                if (languageName)
                {
                    zn_languageName = [languageName UTF8String];
                }
                else
                {
                    zn_languageName = "";
                }
                zn_languageInfo.languageName = zn_languageName;

                // languageID
                zn_languageInfo.languageID = languageInfo.languageID;

                list.push_back(zn_languageInfo);
            }
        }
    }
    return list;
}

ZNLiveTranscriptionLanguage ZMeetingCloseCaptionWrap::GetTranslationLanguage()
{
    ZNLiveTranscriptionLanguage zn_languageInfo;

    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return zn_languageInfo;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return zn_languageInfo;

    ZoomSDKLiveTranscriptionLanguage *languageInfo = [closeCaptionController getTranslationLanguage];

    // languageName
    ZoomSTRING zn_languageName;
    NSString *languageName = languageInfo.languageName;
    if (languageName)
    {
        zn_languageName = [languageName UTF8String];
    }
    else
    {
        zn_languageName = "";
    }
    zn_languageInfo.languageName = zn_languageName;

    // languageID
    zn_languageInfo.languageID = languageInfo.languageID;

    return zn_languageInfo;
}

ZNSDKError ZMeetingCloseCaptionWrap::SetTranslationLanguage(int languageID)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController setTranslationLanguage:languageID];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingCloseCaptionWrap::SetMeetingSpokenLanguage(int languageID, bool isForAll)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController setMeetingSpokenLanguage:languageID isForAll:isForAll];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingCloseCaptionWrap::EnableCaptions(bool enable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController enableCaptions:enable];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingCloseCaptionWrap::StartLiveTranscription()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController startLiveTranscription];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingCloseCaptionWrap::StopLiveTranscription()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController stopLiveTranscription];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingCloseCaptionWrap::EnableReceiveSpokenLanguageContent(bool enable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return ZNSDKERR_SERVICE_FAILED;

    ZoomSDKError ret = [closeCaptionController enableReceiveSpokenLanguageContent:enable];

    nativeErrorTypeHelp Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZMeetingCloseCaptionWrap::IsReceiveSpokenLanguageContentEnabled()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return false;

    return [closeCaptionController isReceiveSpokenLanguageContentEnabled];
}

bool ZMeetingCloseCaptionWrap::IsLiveTranscriptionFeatureEnabled()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return false;

    return [closeCaptionController isLiveTranscriptionFeatureEnabled];
}

bool ZMeetingCloseCaptionWrap::IsMultiLanguageTranscriptionEnabled()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return false;

    return [closeCaptionController isMultiLanguageTranscriptionEnabled];
}

bool ZMeetingCloseCaptionWrap::IsTextLiveTranslationEnabled()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service)
        return false;

    ZoomSDKCloseCaptionController *closeCaptionController = [service getCloseCaptionController];
    if (!closeCaptionController)
        return false;

    return [closeCaptionController isTextLiveTranslationEnabled];
}

void ZMeetingCloseCaptionWrap::onLiveTranscriptionMsgInfoReceived(ZNLiveTranscriptionMessageInfo messageInfo)
{
    if (m_pSink)
    {
        m_pSink->onLiveTranscriptionMsgInfoReceived(messageInfo);
    }
}

void ZMeetingCloseCaptionWrap::onOriginalLanguageMsgReceived(ZNLiveTranscriptionMessageInfo messageInfo)
{
    if (m_pSink)
    {
        m_pSink->onOriginalLanguageMsgReceived(messageInfo);
    }
}