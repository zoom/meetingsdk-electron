
#import "Header_include.h"
#import "sdk_native_error.h"
#include "meeting_service_wrap_core.h"
#import "preMeetingServiceDelegate.h"

ZMeetingReminderWrap &ZMeetingServiceWrap::GetMeetingReminderCtrl()
{
    return m_meeting_reminder_ctrl;
}

ZMeetingReminderWrap::ZMeetingReminderWrap()
{
    m_pSink = 0;
}
ZMeetingReminderWrap::~ZMeetingReminderWrap()
{
    m_pSink = 0;
    [[[ZoomSDK sharedSDK] getReminderHelper] setDelegate:nil];
}
void ZMeetingReminderWrap::Init()
{
}
void ZMeetingReminderWrap::Uninit()
{
    m_pSink = 0;
    [[[ZoomSDK sharedSDK] getReminderHelper] setDelegate:nil];

}
void ZMeetingReminderWrap::SetSink(ZNativeSDKMeetingReminderWrapSink* pSink)
{
    m_pSink = pSink;
    [[[ZoomSDK sharedSDK] getReminderHelper] setDelegate:[ZoomSDKRemindDelegate share]];
}

ZNSDKError ZMeetingReminderWrap::Ignore()
{
    ZoomSDKReminderHandler *handler = [ZoomSDKRemindDelegate share].reminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler ignore];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::Accept()
{
    ZoomSDKReminderHandler *handler = [ZoomSDKRemindDelegate share].reminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler accept];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::Decline()
{
    ZoomSDKReminderHandler *handler = [ZoomSDKRemindDelegate share].reminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler decline];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}

//callback
void ZMeetingReminderWrap::onReminderNotify(ZNMeetingReminderContent content)
{
    if (m_pSink)
    {
        m_pSink->onReminderNotify(content);
    }
}

ZNSDKError ZMeetingReminderWrap::SetEnableOption(ZNFeatureEnableOption zn_option)
{
    ZoomSDKMeetingEnableReminderHandler *handler = [ZoomSDKRemindDelegate share].enableReminderHandler;
    if (handler) {
        nativeErrorTypeHelp Help_type;
        ZoomSDKMeetingFeatureEnableOption option = Help_type.FeatureEnableOptionMap(zn_option);
        ZoomSDKError ret = [handler setEnableOption:option];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::StartEnable()
{
    ZoomSDKMeetingEnableReminderHandler *handler = [ZoomSDKRemindDelegate share].enableReminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler start];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::DeclineEnable(bool declineAll)
{
    ZoomSDKMeetingEnableReminderHandler *handler = [ZoomSDKRemindDelegate share].enableReminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler decline:declineAll];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::IgnoreEnable()
{
    ZoomSDKMeetingEnableReminderHandler *handler = [ZoomSDKRemindDelegate share].enableReminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler ignore];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::SetHideFeatureDisclaimers()
{
    ZoomSDKReminderHandler *handler = [ZoomSDKRemindDelegate share].reminderHandler;
    if (handler) {
        ZoomSDKError ret = [handler setHideFeatureDisclaimers];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::SetMultiReminderDisclaimerUIConfig(int left, int top, ZoomSTRING parentWindowHandle, unsigned long backgroundColor)
{
    ZoomSDKReminderController *controller = [[ZoomSDK sharedSDK] getReminderHelper];
    if (controller) {
        ZoomSDKCustomMultiReminderUIConfig *config = [[[ZoomSDKCustomMultiReminderUIConfig alloc] init] autorelease];
        ZoomSDKCustomMultiReminderUIConfigItem *item = [[[ZoomSDKCustomMultiReminderUIConfigItem alloc] init] autorelease];
        item.center = NSMakePoint(left, top);
        item.backgroundColor = [NSColor colorWithRed:((backgroundColor >> 16) & 0xFF) / 255.0
                                               green:((backgroundColor >> 8) & 0xFF) / 255.0
                                                blue:(backgroundColor & 0xFF) / 255.0
                                               alpha:1.0];
        config.alertConfig = item;
        ZoomSDKError ret = [controller setMultiReminderDisclaimerUIConfig:config];
        nativeErrorTypeHelp help_type;
        return help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_WRONG_USAGE;
}
ZNSDKError ZMeetingReminderWrap::UpdateMultiReminderDisclaimerUI()
{
    return ZNSDKERR_NO_IMPL;
}

void ZMeetingReminderWrap::onEnableReminderNotify(ZNMeetingReminderContent content)
{
    if (m_pSink)
    {
        m_pSink->onEnableReminderNotify(content);
    }
}
