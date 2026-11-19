

#include "meeting_video_wrap_core.h"
#include "meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
#import "meetingServiceDelegate.h"
ZMeetingVideoWrap  &ZMeetingServiceWrap::GetMeetingVideoCtrl()
{
    return m_meeting_video_ctrl;
}

ZMeetingVideoWrap::ZMeetingVideoWrap()
{
    m_pSink = 0;
    
}

ZMeetingVideoWrap::~ZMeetingVideoWrap()
{
    m_pSink = 0;
}

void ZMeetingVideoWrap::Init()
{

}

void ZMeetingVideoWrap::Uninit()
{
    
}

void ZMeetingVideoWrap::SetSink(ZNativeSDKMeetingVideoWrapSink *pSink)
{
    m_pSink = pSink;
}

ZNSDKError ZMeetingVideoWrap::MuteVideo(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_MuteVideo userID:userId onScreen:ScreenType_First];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnMuteVideo(unsigned int userId)
{
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_UnMuteVideo userID:userId onScreen:ScreenType_First];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::CanPinToFirstView(unsigned int userId, ZNPinResult& result)
{
    result = ZN_PinResult_Unknown;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKPinResult nativeResult = ZoomSDKPinResult_Unknown;
        ZoomSDKError ret = [action canPinToFirstView:userId result:&nativeResult];
        result = (ZNPinResult)nativeResult;
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::PinVideoToFirstView(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action pinVideoToFirstView:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnPinAllVideosFromFirstView()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action unPinAllVideosFromFirstView];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<unsigned int> ZMeetingVideoWrap::GetPinnedUserListFromFirstView()
{
    ZNList<unsigned int> zn_list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return zn_list;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        NSArray* list = [action getPinnedUserListFromFirstView];
        if (list) {
            for (NSNumber *num in list) {
                zn_list.push_back([num unsignedIntValue]);
            }
        }
    }
    return zn_list;
}

ZNSDKError ZMeetingVideoWrap::CanPinToSecondView(unsigned int userId, ZNPinResult& result)
{
    result = ZN_PinResult_Unknown;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKPinResult nativeResult = ZoomSDKPinResult_Unknown;
        ZoomSDKError ret = [action canPinToSecondView:userId result:&nativeResult];
        result = (ZNPinResult)nativeResult;
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::PinVideoToSecondView(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action pinVideoToSecondView:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<unsigned int> ZMeetingVideoWrap::GetPinnedUserListFromSecondView()
{
    ZNList<unsigned int> zn_list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return zn_list;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        NSArray* list = [action getPinnedUserListFromSecondView];
        if (list) {
            for (NSNumber *num in list) {
                zn_list.push_back([num unsignedIntValue]);
            }
        }
    }
    return zn_list;
}

ZNSDKError ZMeetingVideoWrap::CanSpotlight(unsigned int userId, ZNSpotlightResult& result)
{
    result = ZN_SpotResult_Unknown;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKSpotlightResult nativeResult = ZoomSDKSpotlightResult_Unknown;
        ZoomSDKError ret = [action canSpotlight:userId result:&nativeResult];
        result = (ZNSpotlightResult)nativeResult;
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::CanUnSpotlight(unsigned int userId, ZNSpotlightResult& result)
{
    result = ZN_SpotResult_Unknown;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKSpotlightResult nativeResult = ZoomSDKSpotlightResult_Unknown;
        ZoomSDKError ret = [action canUnSpotlight:userId result:&nativeResult];
        result = (ZNSpotlightResult)nativeResult;
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::SpotlightVideo(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action spotlightVideo:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnSpotlightVideo(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action unSpotlightVideo:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnSpotlightAllVideos()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action unSpotlightAllVideos];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<unsigned int> ZMeetingVideoWrap::GetSpotlightedUserList()
{
    ZNList<unsigned int> zn_list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return zn_list;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        NSArray<NSNumber*>* list = [action getSpotlightedUserList];
        if (list) {
            for (NSNumber *num in list) {
                zn_list.push_back([num unsignedIntValue]);
            }
        }
    }
    return zn_list;
}

ZNSDKError ZMeetingVideoWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *action = [service getMeetingUIController];
    if (action) {
        ZoomSDKError ret = [action hideOrShowNoVideoUserOnVideoWall:bHide];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnPinVideoFromFirstView(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action unPinVideoFromFirstView:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnPinVideoFromSecondView(unsigned int userId)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action unPinVideoFromSecondView:userId];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<unsigned int> ZMeetingVideoWrap::GetLocalVideoOrderList()
{
    ZNList<unsigned int> zn_list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return zn_list;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        NSArray<NSNumber*>* list = [action getLocalVideoOrderList];
        if (list) {
            for (NSNumber *num in list) {
                zn_list.push_back([num unsignedIntValue]);
            }
        }
    }
    return zn_list;
}

bool ZMeetingVideoWrap::IsSupportFollowHostVideoOrder()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return false;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        return [action isSupportFollowHostVideoOrder] ? true : false;
    }
    return false;
}

ZNSDKError ZMeetingVideoWrap::EnableFollowHostVideoOrder(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action enableFollowHostVideoOrder:bEnable];
        nativeErrorTypeHelp Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

bool ZMeetingVideoWrap::IsFollowHostVideoOrderOn()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return false;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        return [action isFollowHostVideoOrderOn] ? true : false;
    }
    return false;
}

ZNList<unsigned int> ZMeetingVideoWrap::GetVideoOrderList()
{
    ZNList<unsigned int> zn_list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return zn_list;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        NSArray<NSNumber*>* list = [action getVideoOrderList];
        if (list) {
            for (NSNumber *num in list) {
                zn_list.push_back([num unsignedIntValue]);
            }
        }
    }
    return zn_list;
}

ZNSDKError ZMeetingVideoWrap::SetVideoQualityPreference(ZNSDKVideoPreferenceMode zn_mode, uint32_t minimumFrameRate, uint32_t maximumFrameRate)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }

    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }

    ZoomSDKVideoPreferenceSetting *preferenceSetting = [[ZoomSDKVideoPreferenceSetting alloc] init];
    nativeErrorTypeHelp Help_type;
    preferenceSetting.mode = Help_type.SDKVideoPreferenceModeMap(zn_mode); 
    preferenceSetting.minimumFrameRate = minimumFrameRate;
    preferenceSetting.maximumFrameRate = maximumFrameRate;
    ZoomSDKError ret = [video setVideoQualityPreference:preferenceSetting];
    return Help_type.ZoomSDKErrorType(ret);
}

//callback
void ZMeetingVideoWrap::onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status)
{
    if (m_pSink) {
        m_pSink->onUserVideoStatusChange(userId, status);
    }
}

void ZMeetingVideoWrap::onActiveVideoUserChanged(unsigned int userid)
{
    if (m_pSink) {
        m_pSink->onActiveVideoUserChanged(userid);
    }
}

void ZMeetingVideoWrap::onActiveSpeakerVideoUserChanged(unsigned int userid)
{
    if (m_pSink) {
        m_pSink->onActiveSpeakerVideoUserChanged(userid);
    }
}

void ZMeetingVideoWrap::onSpotlightedUserListChangeNotification(ZNList<unsigned int> lstSpotlightedUserID)
{
    if (m_pSink) {
        m_pSink->onSpotlightedUserListChangeNotification(lstSpotlightedUserID);
    }
}
