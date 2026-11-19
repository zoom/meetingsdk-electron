#ifndef _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#define _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingConfigCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >;
private:
	ZoomNodeMeetingConfigCtrlWrap();
	~ZoomNodeMeetingConfigCtrlWrap();
public:
	/**
	 * @brief Set the visibility of the INVITE button in the panelist action bar during the meeting. Default value: true.
	 * @param bEnable true indicates to display the button. Otherwise, false.
	 * @note The user will receive the IMeetingUIControllerEvent::onInviteBtnClicked() callback event when he clicks the INVITE button. If the callback event is not handled, the SDK will pop up a ZOOM custom invitation dialog.
	 * The user will receive the IMeetingUIControllerEvent::onZoomInviteDialogFailed() callback event if the dialog box is failed to display.
	 */
	static void EnableInviteButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the position of the floating video window when sharing.
	 * @param left(string) Specifies the X-axis coordinate of the top-left corner of the window
	 * @param top(string) Specifies the Y-axis coordinate of the top-left of the window.
	 * @param Just for Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	 * @param Just for Windows: hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	 * @return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	 * Otherwise, this function returns an error. To get extended error information, see ZNSDKError enum.
	 * @note The value shall be set before the sharing begins. If you set the value during the process of share, the function will not be valid until the next share.
	 */
	static void SetFloatVideoPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the toolbar at the bottom of the meeting window. Default value: true.
	 * @param bShow true indicates to enable the feature to display always the toolbar at the bottom. Otherwise, false.
	 */ 
	static void SetBottomFloatToolbarWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the sharing toolbar. Default value: true.
	 * @param bShow true indicates to enable the display sharing toolbar. Otherwise, false.
	 * @note This function works only before the meeting or the sharing starts.
	 */ 
	static void SetSharingToolbarVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the shared device ID when sharing directly.
	 * @param monitorID Specify the device ID to be shared. You may get the device ID by the system API EnumDisplayMonitors().
	 */ 
	static void SetDirectShareMonitorID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the position of the primary view meeting window.
	 * @param left(string) Specifies the X-axis coordinate of the top-left corner of the window
	 * @param top(string) Specifies the Y-axis coordinate of the top-left of the window.
	 * @param Just for Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	 * @param Just for Windows: hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	 */
	static void SetMeetingUIPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box of waiting for the host after joining the meeting. Only invalidate when the host is not in the meeting. Default: false.
	 * @param bDisable true indicates to hide the dialog box. Otherwise, false.
	 */
	static void DisableWaitingForHostDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box if the password is wrong when join the meeting. Default: false.
	 * @param bDisable true indicates to hide the dialog box of wrong password.
	 * @note If it is disabled to display the dialog box of wrong password, the system will directly exit the state of trying to join the meeting.
	 */
	static void DisablePopupMeetingWrongPSWDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to end automatically another ongoing meeting when joining a new meeting. Default: false.
	 * @param bEnable true indicates to end the other ongoing meetings. Otherwise, false.
	 */
	static void EnableAutoEndOtherMeetingWhenStartMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to switch between the full screen mode and normal mode by double-click. Default value: true.
	 * @param bEnable true indicates to switch. Otherwise, false.
	 */
	static void EnableLButtonDBClick4SwitchFullScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the floating video window when sharing in the meeting. Default value: true.
	 * @param bShow true indicates to display the floating video window. Otherwise, false.
	 */
	static void SetFloatVideoWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Pre-set email and username information before joining the webinar.
	 * @param email Configure the default email.
	 * @param username Configure default username.
	 */
	static void PrePopulateWebinarRegistrationInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback of upgrading the free meeting.
	 * @param type_ Type of upgrading the free meeting.
	 * @param gift_url Upgrade the free meeting by the gift link. When and only when the value of type_ is FreeMeetingNeedUpgradeType_BY_GIFTURL, this parameter is meaningful.
	 */
	static void SetFreeMeetingNeedToUpgradeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback function of starting to upgrade the free meeting by the gift link.
	 */
	static void SetFreeMeetingUpgradeToGiftFreeTrialStartCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback function of ending upgrade the free meeting by the gift link.
	 */
	static void SetFreeMeetingUpgradeToGiftFreeTrialStopCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback function of free meting upgrades successfully.
	 */
	static void SetFreeMeetingUpgradeToProMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Reset the meeting configuration and back to the default state.
	 */
	static void Reset(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Configure DSCP(Differential services code point) values.
	 * @param dscpAudio Configure DSCP value for audio.
	 * @param dscpVideo Configure DSCP value for video.
	 * @param bReset Reset DSCP values.
	 * @note This interface satisfies some users who have other requirements. It is not recommended to configure it. Contact the support engineer for more details.
	 */ 
	static void ConfigDSCP(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to limit the length of meeting ID. Default: false.
	 * @param bEnable true indicates to limit the length of meeting ID. Otherwise, false.
	 * @note If it is enabled, the length of the meeting ID depends on the ID type. The ID shall be more than nine(9) figures or five(5) letters. Also, The meeting ID will be displayed as it is (not formatted).
	 */
	static void EnableLengthLimitationOfMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to share IOS device. Default: false.
	 * @param bEnable true indicates to enable to share. Otherwise, false.
	 */
	static void EnableShareIOSDevice(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to share white board. Default: true.
	 * @param bEnable true indicates to enable to share on the white board. Otherwise, false.
	 */
	static void EnableShareWhiteBoard(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to forbid multi-share. Default: false.
	 * @param bDisable true indicates to forbid multi-share. Otherwise, false.
	 */
	static void ForceDisableMultiShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enable or disable zoom docs features in custom UI. This is disabled by default.
	 * @param bEnable true indicates to enable the zoom docs feature. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise the function fails.
	 */
	static void EnableZoomDocs(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the maximum duration of the meeting when there is no attendee in the meeting. Default: 24*60.
	 * @param nDuration Specify the maximum duration in minutes.
	 */
	static void SetMaxDurationForOnlyHostInMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the local recording convert progress bar dialog. Default: true.
	 * @param bShow true indicates to show the dialog box. Otherwise, false.
	 */
	static void EnableLocalRecordingConvertProgressBarDialog(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the visibility of the dialog box when receiving the request of remote control during the meeting. Default value: true.
	 * @param bEnable true indicates to display the dialog box. Otherwise, false.
	 * If it is false, the user can deal with this request in the IMeetingRemoteCtrlEvent::onRemoteControlStatus() callback event sent by SDK 
	 * when receiving the request of the remote control and then enters the sharing status at the end of callback event.
	 */
	static void EnableApproveRemoteControlDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box when the request of the remote control is refused. Default value: true.
	 * @param bEnable true indicates to display the dialog box. Otherwise, false.
	 * If it is false, the user can deal with this request in the IMeetingRemoteCtrlEvent::onRemoteControlStatus() callback event sent by SDK 
	 * when receiving the decline request of the remote control and then exists the sharing status at the end of callback event.
	 */
	static void EnableDeclineRemoteControlResponseDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the LEAVE MEETING button on the pop-up dialogue box when the host leaves the meeting. Default value: true.
	 * @param bEnable true indicates to display the button. Otherwise, false.
	 */
	static void EnableLeaveMeetingOptionForHost(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the Video button in the toolbar during the meeting. Default value: true.
	 * @param bEnable true indicates to display the button. Otherwise, false.
	 */
	static void EnableVideoButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the Audio button in the toolbar during the meeting. Default value: true.
	 * @param bEnable true indicates to display the button. Otherwise, false.
	 */
	static void EnableAudioButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the buttons to enter or exit the full screen in the meeting window. Default value: true.
	 * @param bEnable true indicates to display the button. Otherwise, false.
	 */
	static void EnableEnterAndExitFullScreenButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with user's own program by clicking START SHARE button in the meeting. Default value: false.
	 * @param bRedirect true indicates to deal with the event with user's own program. Otherwise, false.
	 * @note The SDK won't enable the share if the user calls this function and sets to convert. The user will deal with the subsequent logic 
	 * after receiving the IMeetingUIControllerEvent::onStartShareBtnClicked() callback event.
	 */
	static void RedirectClickShareBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with user's own program by clicking END MEETING button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note The SDK won't end the meeting if the user calls this function and set to convert. The user will deal with the subsequent logic 
	 * after receiving the IMeetingUIControllerEvent::onEndMeetingBtnClicked() callback event.
	 */
	static void RedirectClickEndMeetingBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief An upgrade dialog box will pop up when the free meeting is over. Use this function to set if it is able to handle the reminder message with user's own program. Default value: false.
	 * @param bRedirect true indicates to handle the reminder message with user's own program. Otherwise, false.
	 * @note The SDK will trigger the IMeetingConfigurationEvent::onFreeMeetingEndingReminderNotification() callback event when the meeting is over if the user calls this function to set the conversion.
	 */
	static void RedirectFreeMeetingEndingReminderDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking CUSTOM LIVE STREAM button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingUIControllerEvent::onCustomLiveStreamMenuClicked() 
	 * instead of jumping to the live video page when clicking on the custom live stream, then deal with the subsequent logic.
	 */
	static void RedirectClickCustomLiveStreamMenuEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking PARTICIPANT LIST button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note The list won't unfold by clicking participant list button if the user calls this function to set to convert. 
	 * The SDK will trigger the IMeetingUIControllerEvent::onParticipantListBtnClicked(), and the user shall deal with the subsequent logic himself.
	 */
	static void RedirectClickParticipantListBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking Closed Caption button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingUIControllerEvent::onCCBTNClicked(), and the user shall deal with the subsequent logic himself.
	 */
	static void RedirectClickCCBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking Audio button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingUIControllerEvent::onAudioBtnClicked(AudioBtnClickedCallbackInfo info), and the user shall deal with the subsequent logic himself.
	 */
	static void RedirectClickAudioBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking Audio Menu button in the meeting. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingUIControllerEvent::onAudioMenuBtnClicked(), and the user shall deal with the subsequent logic himself.
	 */
	static void RedirectClickAudioMenuBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the warning message with SDK user's own program in the meeting. Default value: None.
	 * @param redirectOption The parameter indicates the warning messages to be handled with user's own program.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingServiceEvent::onMeetingStatisticsWarningNotification(), and the user shall deal with the subsequent logic himself.
	 */
	static void RedirectMeetingWarningMsg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to temporarily show tooltip of the button in the toolbar of the meeting and user can close it by click the "x". Default value: true.
	 * @param bEnable true indicates to enable to show the tooltip in the meeting. Otherwise, false.
	 */
	static void EnableToolTipsShow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to retrieve the permission of host (when the original host gives up the host permission). Default value: true.
	 * @param bEnable true indicates that he can retrieve the permission of host. Otherwise, false.
	 * @note The original host can always claim host and is not affected by this API.
	 */
	static void EnableClaimHostFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box of choosing audio when joining the meeting. Default value: false.
	 * @param bEnable true indicates to hide the dialog box of choosing audio when joining the meeting. Otherwise, false.
	 */
	static void EnableAutoHideJoinAudioDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to display the preview window of the Meeting Controls on the task bar during sharing. Default value: false.
	 * @param bAlwaysShow true indicates to display always the icon on the task-bar.
	 */
	static void AlwaysShowIconOnTaskBar(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to enable split screen during the meeting. Default value: false.
	 * @param bDisable true indicates to disable the split screen. Otherwise, false.
	 * @note This function is valid only on the primary screen. Set the value to false does not mean to enable the split screen due to other restrictions.
	 */
	static void DisableSplitScreenModeUIElements(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the SHARE COMPUTER SOUND check-box in the sharing window. Default value: true.
	 * @param bShow true indicates to display. Otherwise, false.
	 */
	static void SetShowAudioUseComputerSoundChkbox(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of PHONE CALL tab in the audio dialog box when joining the meeting. Default value: true.
	 * @param bShow true indicates to display the tab. Otherwise, false.
	 */
	static void SetShowCallInTab(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of CALL ME tab in the audio dialog box when joining the meeting. Default value: true.
	 * @param bShow true indicates to display the tab. Otherwise, false.
	 */
	static void SetShowCallMeTab(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Whether to remove the topmost attribute of setting dialog. Default is not removed.
	 * @param bDisable true indicates to remove. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void DisableTopMostAttr4SettingDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to close the current sharing of another user without prompt and directly beginning a new sharing content by the closer. Default value: false(prompt).
	 * @param bEnable true indicates no prompt. Otherwise, false.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EnableGrabShareWithoutReminder(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the SWITCH TO SINGLE PARTICIPANT SHARE dialog box when multiple participants are sharing and the user try to change the setting to single share. Default: TURE.
	 * @param bEnable true indicates to show dialog box if the multishare option is changed. Otherwise, false.
	 * @note If the dialog is disabled to show, you will retrieve IMeetingShareCtrlEvent::onMultiShareSwitchToSingleShareNeedConfirm callback event.
	 */
	static void EnableShowShareSwitchMultiToSingleConfirmDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the REMAINING MEETING TIME button in the meeting. Default: false.
	 * @param bDisable true indicates to hide the button when the free meeting need be reminded. Otherwise, false.
	 * @note If the button is disabled to show, you will retrieve IMeetingConfigurationEvent::onFreeMeetingRemainTime callback event.
	 */
	static void DisableFreeMeetingRemainTimeNotify(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to display the button CHAT and menu item. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 */
	static void HideChatItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to display the button RECORD and menu item. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 */
	static void HideRecordItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to display the button UPGRADE when prompt the tooltip of free meeting counts down. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 */
	static void HideUpgradeFreeMeetingButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of some specified tabs in the invite dialog. Default: Show all the content.
	 * @param tabPage Specify a tab page.
	 * @param bShow true indicates to display the tab. Otherwise, false.
	 */
	static void SetShowInviteDlgTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of some specified tabs in the Room System invitation dialog. Default: show all the content.
	 * @param tabPage Specify a tab.
	 * @param bShow true indicates to display the tab. Otherwise, false.
	 */
	static void SetShowH323SubTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of Switch Camera button on 2nd camera share window,Default: true.
	 * @param bHide true indicates to hide the Switch Camera button. Otherwise, false.
	 */
	static void HideSwitchCameraButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of CopyURL button on invite window, Default: true.
	 * @param bHide true indicates to hide. Otherwise, false.
	 */
	static void HideCopyUrlOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of CopyInvitation button on invite window, Default: true.
	 * @param bHide true indicates to hide. Otherwise, false.
	 */
	static void HideCopyInvitationOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of Keypad button on meeting window, Default: true.
	 * @param bHide true indicates to hide. Otherwise, false.
	 */
	static void HideKeypadButtonOnMeetingWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set whether to display the button REMOTE CONTROL and menu item. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 * @note If the calling of API with parameter true is successful, SDK will call EnableApproveRemoteControlDlg(false) by default.
	 */
	static void HideRemoteControlOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of Q&A on meeting UI. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 */
	static void HideQAOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of poll on meeting UI. Default is displaying.
	 * @param bHide true indicates hiding. Otherwise, false.
	 */
	static void HidePollOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box to input the password. Default: true.
	 * @param bEnable true indicates to display the dialog box to input password. Otherwise, false.
	 * @note If it is disabled, the SDK will trigger IMeetingConfigurationEvent::onInputMeetingPasswordAndScreenNameNotification()callback event 
	 * when the user is asked to re-enter the password, then the user shall deal with the subsequent logic.
	 */
	static void EnableInputMeetingPasswordDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box to input the screen name. Default: true.
	 * @param bEnable true indicates to display the dialog box to input the screen name which is to be displayed in the meeting. Otherwise, false.
	 * @note If it is false, the SDK will trigger IMeetingConfigurationEvent::onInputMeetingPasswordAndScreenNameNotification()callback event 
	 * when the user is asked to re-enter the screen name, then the user shall deal with the subsequent logic.
	 */
	static void EnableInputMeetingScreenNameDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the webinar register process with user's own program in the meeting. Default: false.
	 * @param bRedirect true indicates to redirect. Otherwise, false.
	 * @note If it is true, the SDK will trigger the IMeetingConfigurationEvent::onWebinarNeedRegisterNotification()callback event.
	 */
	static void RedirectWebinarNeedRegister(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to redirect the process to end another meeting by user's own program. Default: false.
	 * @param bRedirect true indicates to redirect. Otherwise, false. If it is true, the SDK will trigger the  IMeetingConfigurationEvent::onEndOtherMeetingToJoinMeetingNotification().
	 * @note This function doesn't work if the IJoinMeetingBehaviorConfiguration::EnableAutoEndOtherMeetingWhenStartMeeting(true) is also called. 
	 * If redirect successfully, the SDK will trigger the IMeetingConfigurationEvent::onEndOtherMeetingToJoinMeetingNotification() callback event.
	 */
	static void RedirectEndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to force to turn on the video when join meeting. Default: false.
	 * @param bEnable true indicates to force to start video.
	 * @note The default behavior depends on the configuration of the meeting.
	 */
	static void EnableForceAutoStartMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to force turn off video when joining the meeting. Default: false.
	 * @param bEnable true indicates to force to turn off the video.
	 * @note The default behavior depends on the configuration of the meeting.
	 */
	static void EnableForceAutoStopMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog  SELECT JOIN AUDIO when joining meeting. Default: false.
	 * @param bDisable true indicates to hide the dialog box.
	 */
	static void DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the dialog box of joining a meeting. Default: false.
	 * @param bDisable true indicates to hide the dialog box. Otherwise, false.
	 */
	static void DisableShowJoinMeetingWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the event with SDK user's own program by clicking INVITE button in the toolbar. Default value: false.
	 * @param bRedirect true indicates to handle with user's own program. Otherwise, false.
	 * @note If the user calls this function to convert, the SDK will trigger the IMeetingUIControllerEvent::onInviteBtnClicked(), and the user shall deal with the subsequent logic himself.
	 */
	static void DisableToolbarInviteButtonClickOriginAction(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the visibility of the INVITE link during the meeting. Default value: true.
	 * @param bEnable true indicates to display the link. Otherwise, false.
	 */
	static void EnableInviteLinkOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Enables or disable the new Zoom Whiteboard feature (different from Classic Whiteboard). This is enabled by default.
	 * @param [in] bEnable true indicates enabled, otherwise not.
	 */
	static void EnableCloudWhiteboard(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set Leave Feedback button's visibility on cloud whiteboard. Default is displaying.
	 * @param [in] bHide true indicates hiding, otherwise means displaying.
	 */
	static void HideCloudWhiteboardFeedbackButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set Share button's visibility on cloud whiteboard. Default is displaying.
	 * @param [in] bHide true indicates hiding, otherwise means displaying.
	 */
	static void HideCloudWhiteboardShareButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the About button's visibility on cloud whiteboard. Default is displaying.
	 * @param [in] bHide true indicates hiding, otherwise means displaying.
	 */
	static void HideCloudWhiteboardAboutButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Sets the Helper center button's visibility on cloud whiteboard. Default is displaying.
	 * @param [in] bHide true indicates hiding, otherwise means displaying.
	 */
	static void HideCloudWhiteboardHelperCenterButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Sets the Open in browser button's visibility on cloud whiteboard. Default is displaying.
	 * @param [in] bHide true indicates hiding, otherwise means displaying.
	 */
	static void HideCloudWhiteboardOpenInBrowserButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Custom the menu items show or hide for panelist.
	 * @param bNotShowDowngradePanelist true indicates to hide the corresponding menu item.
	 */
	static void DisablePanelistMenuItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Custom the menu items show or hide for attendee.
	 * @param bNotShowPromoteToPanelist true indicates to hide the corresponding menu item.
	 */
	static void DisableAttendeeMenuItem(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Hides the register webinar window when joining a webinar.
	 * @param bHide true indicates to hide. Otherwise, false.
	 */
	static void HideRegisterWebinarInfoWindow(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Set the visibility of the OPTIMIZE FOR FULL SCREEN VIDEO CLIP check-box in the sharing window. Default value: true.
	 * @param bShow true indicates to display. Otherwise, false.
	 */
	static void SetShowVideoOptimizeChkbox(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the type of required information to be completed.
	 * @return If the function succeeds, the return is enumerated in RequiredInfoType enum.
	 */
	static void GetRequiredInfoType(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Complete the password and screen name information.
	 * @note The SDK will destroy the object instance after calling this function. Supplement with the correct information.
	 */
	static void InputMeetingPasswordAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Complete the meeting id and screen name information.
	 * @note The SDK will destroy the object instance after calling this function. Supplement with the correct information.
	 */
	static void InputMeetingIDAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Complete the screen name.
	 * @note The SDK will destroy this object instance after calling this function. Complete the information by the correct function.
	 */
	static void InputMeetingScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the prompt of completing the information.
	 * @note The SDK will destroy this object instance after calling this function.
	 */
	static void MeetingPasswordAndScreenNameHandler_Cancel(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the type to register.
	 */
	static void GetWebinarNeedRegisterType(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Get the URL to register webinar.
	 * @return If the function succeeds, the return value is an URL.
	 */
	static void GetWebinarRegisterUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Release object.
	 */
	static void ReleaseRegisterWebinarByUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Configure the information of email and screen name.
	 * @note The SDK will destroy this object instance after calling this function. Supplement with the correct information.
	 */
	static void InputWebinarRegisterEmailAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the prompt of the register.
	 * @note The SDK will destroy this object instance after calling this function.
	 */
	static void CancelRegisterWebinarByEmail(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the display name and email input dlg with user's own program in the meeting. Default: false.
	 * @param bRedirect true indicates to redirect. Otherwise, false.
	 * @note If it is true, the SDK will trigger the IMeetingConfigurationEvent::onJoinMeetingNeedUserInfo()callback event.
	 */
	static void RedirectMeetingInputUserInfoDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set if it is able to handle the confirm start archive dialog dlg with user's own program in the meeting. Default: false.
	 * @param bRedirect true indicates to redirect. Otherwise, false.
	 * @note If it is true, the SDK will trigger the IMeetingConfigurationEvent::onUserConfirmToStartArchive()callback event.
	 */
	static void RedirectConfirmStartArchiveDialog(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Input screen name to join webinar.
	 * @param screenName The display name for the webinar.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The SDK will destroy this object instance after calling this function. Supplement with the correct information.
	 */
	static void InputScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Cancel to join webinar.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The SDK will destroy this object instance after calling this function.
	 */
	static void CancelJoinWebinar(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief Get default display name.
	 */
	static void GetDefaultDisplayName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check whether the user can modify default display name.
	 * @return true indicates can modify default display name
	 */
	static void CanModifyDefaultDisplayName(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Check whether the inputed email is a valid email format. The email must meet the email format requirements.The email input by the logged in user must be the email of the logged in account.
	 * @return true if the email input is valid
	 */
	static void IsValidEmail(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Complete the name and email information.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 * @note The SDK will destroy this object instance after calling this function. Supplement with the correct information.
	 */
	static void InputUserInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignore the prompt of completing the information.
	 * @note The SDK will destroy this object instance after calling this function.
	 */
	static void CancelInputUserInfo(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The content that notifies the user to confirm starting to archive when joining the meeting.
	 */
	static void GetArchiveConfirmContent(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Join the meeting.
	 * @param bStartArchive true indicates start the archive when joining the meeting, false indicates do not start the archive when joining the meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void JoinWithArchive(const v8::FunctionCallbackInfo<v8::Value>& args);

	/**
	 * @brief The SDK will trigger the callback event if the password or screen name is required.
	 * @param pHandler A pointer to the instance, the user may use this object to operate.
	 */
	static void SetInputMeetingPasswordAndScreenNameNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Set the callback for AirPlay instruction window notification.
	 */
	static void SetAirPlayInstructionWndNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief During the webinar, this callback event will be triggered if the user needs to register.
	 * @param handler_ An object pointer used by user to complete all the related operations.
	 */
	static void SetonWebinarNeedRegisterNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The user will receive this callback event if the user wants to join the new meeting while the ongoing meeting is not ended.
	 * @param handler_ An object pointer used by user to complete all the related operations.
	 */
	static void SetonEndOtherMeetingToJoinMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The SDK will trigger this callback event during the free meeting to inform the user how much time is left for a free meeting.
	 * @param leftTime The left time of meeting calculated in seconds.
	 */
	static void SetonFreeMeetingRemainTimeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief The callback of free meeting stops the countdown.
	 */
	static void SetonFreeMeetingRemainTimeStopCountDownCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief When joining the webinar, this callback is triggered if the user needs to input a username.
	 * @param pHandler An object pointer used by user to complete all the related operations.
	 */
	static void SetonWebinarNeedInputScreenNameCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief When joining the meeting, this callback is triggered if the user needs to input a username and email.
	 * @param pHandler An object pointer used by user to complete all the related operations.
	 */
	static void SetonJoinMeetingNeedUserInfoCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Callback event when joining a meeting if the admin allows the the user to choose to archive the meeting.
	 * @param pHandler An object pointer the user to choose whether archive the meeting when joining the meeting.
	 */
	static void SetonUserConfirmToStartArchiveCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Closes another ongoing meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void EndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/**
	 * @brief Ignores the prompt of closing another ongoing meeting.
	 * @return If the function succeeds, the return value is SDKERR_SUCCESS. Otherwise, this function returns an error.
	 */
	static void CancelEndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingConfigCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingConfigCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInviteButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableInviteButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoPos", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetBottomFloatToolbarWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetBottomFloatToolbarWndVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSharingToolbarVisibility", ZoomNodeMeetingConfigCtrlWrap::SetSharingToolbarVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDirectShareMonitorID", ZoomNodeMeetingConfigCtrlWrap::SetDirectShareMonitorID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUIPos", ZoomNodeMeetingConfigCtrlWrap::SetMeetingUIPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableWaitingForHostDialog", ZoomNodeMeetingConfigCtrlWrap::DisableWaitingForHostDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisablePopupMeetingWrongPSWDlg", ZoomNodeMeetingConfigCtrlWrap::DisablePopupMeetingWrongPSWDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoEndOtherMeetingWhenStartMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableAutoEndOtherMeetingWhenStartMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLButtonDBClick4SwitchFullScreenMode", ZoomNodeMeetingConfigCtrlWrap::EnableLButtonDBClick4SwitchFullScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoWndVisibility);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableApproveRemoteControlDlg", ZoomNodeMeetingConfigCtrlWrap::EnableApproveRemoteControlDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDeclineRemoteControlResponseDlg", ZoomNodeMeetingConfigCtrlWrap::EnableDeclineRemoteControlResponseDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLeaveMeetingOptionForHost", ZoomNodeMeetingConfigCtrlWrap::EnableLeaveMeetingOptionForHost);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableVideoButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAudioButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableAudioButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableEnterAndExitFullScreenButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickShareBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickShareBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickEndMeetingBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickEndMeetingBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectFreeMeetingEndingReminderDlg", ZoomNodeMeetingConfigCtrlWrap::RedirectFreeMeetingEndingReminderDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickCustomLiveStreamMenuEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickCustomLiveStreamMenuEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickParticipantListBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickParticipantListBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickCCBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickCCBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickAudioBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickAudioMenuBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioMenuBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectMeetingWarningMsg", ZoomNodeMeetingConfigCtrlWrap::RedirectMeetingWarningMsg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableToolTipsShow", ZoomNodeMeetingConfigCtrlWrap::EnableToolTipsShow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableClaimHostFeature", ZoomNodeMeetingConfigCtrlWrap::EnableClaimHostFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoHideJoinAudioDialog", ZoomNodeMeetingConfigCtrlWrap::EnableAutoHideJoinAudioDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AlwaysShowIconOnTaskBar", ZoomNodeMeetingConfigCtrlWrap::AlwaysShowIconOnTaskBar);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableSplitScreenModeUIElements", ZoomNodeMeetingConfigCtrlWrap::DisableSplitScreenModeUIElements);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowAudioUseComputerSoundChkbox", ZoomNodeMeetingConfigCtrlWrap::SetShowAudioUseComputerSoundChkbox);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowCallInTab", ZoomNodeMeetingConfigCtrlWrap::SetShowCallInTab);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowCallMeTab", ZoomNodeMeetingConfigCtrlWrap::SetShowCallMeTab);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableTopMostAttr4SettingDialog", ZoomNodeMeetingConfigCtrlWrap::DisableTopMostAttr4SettingDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableGrabShareWithoutReminder", ZoomNodeMeetingConfigCtrlWrap::EnableGrabShareWithoutReminder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowShareSwitchMultiToSingleConfirmDlg", ZoomNodeMeetingConfigCtrlWrap::EnableShowShareSwitchMultiToSingleConfirmDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableFreeMeetingRemainTimeNotify", ZoomNodeMeetingConfigCtrlWrap::DisableFreeMeetingRemainTimeNotify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideChatItemOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideChatItemOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideRecordItemOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideRecordItemOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideUpgradeFreeMeetingButton", ZoomNodeMeetingConfigCtrlWrap::HideUpgradeFreeMeetingButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowInviteDlgTabPage", ZoomNodeMeetingConfigCtrlWrap::SetShowInviteDlgTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowH323SubTabPage", ZoomNodeMeetingConfigCtrlWrap::SetShowH323SubTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideSwitchCameraButton", ZoomNodeMeetingConfigCtrlWrap::HideSwitchCameraButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCopyUrlOnInviteWindow", ZoomNodeMeetingConfigCtrlWrap::HideCopyUrlOnInviteWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCopyInvitationOnInviteWindow", ZoomNodeMeetingConfigCtrlWrap::HideCopyInvitationOnInviteWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideKeypadButtonOnMeetingWindow", ZoomNodeMeetingConfigCtrlWrap::HideKeypadButtonOnMeetingWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideRemoteControlOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideRemoteControlOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideQAOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideQAOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HidePollOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HidePollOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInputMeetingPasswordDlg", ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingPasswordDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInputMeetingScreenNameDlg", ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingScreenNameDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectWebinarNeedRegister", ZoomNodeMeetingConfigCtrlWrap::RedirectWebinarNeedRegister);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectEndOtherMeeting", ZoomNodeMeetingConfigCtrlWrap::RedirectEndOtherMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableForceAutoStartMyVideoWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStartMyVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableForceAutoStopMyVideoWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStopMyVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableShowJoinMeetingWnd", ZoomNodeMeetingConfigCtrlWrap::DisableShowJoinMeetingWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableToolbarInviteButtonClickOriginAction", ZoomNodeMeetingConfigCtrlWrap::DisableToolbarInviteButtonClickOriginAction);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInviteLinkOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableInviteLinkOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableCloudWhiteboard", ZoomNodeMeetingConfigCtrlWrap::EnableCloudWhiteboard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCloudWhiteboardFeedbackButton", ZoomNodeMeetingConfigCtrlWrap::HideCloudWhiteboardFeedbackButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCloudWhiteboardShareButton", ZoomNodeMeetingConfigCtrlWrap::HideCloudWhiteboardShareButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCloudWhiteboardAboutButton", ZoomNodeMeetingConfigCtrlWrap::HideCloudWhiteboardAboutButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCloudWhiteboardHelperCenterButton", ZoomNodeMeetingConfigCtrlWrap::HideCloudWhiteboardHelperCenterButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCloudWhiteboardOpenInBrowserButton", ZoomNodeMeetingConfigCtrlWrap::HideCloudWhiteboardOpenInBrowserButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisablePanelistMenuItem", ZoomNodeMeetingConfigCtrlWrap::DisablePanelistMenuItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAttendeeMenuItem", ZoomNodeMeetingConfigCtrlWrap::DisableAttendeeMenuItem);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideRegisterWebinarInfoWindow", ZoomNodeMeetingConfigCtrlWrap::HideRegisterWebinarInfoWindow);

	NODE_SET_PROTOTYPE_METHOD(tpl, "PrePopulateWebinarRegistrationInfo", ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingNeedToUpgradeCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStartCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStopCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToProMeetingCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Reset", ZoomNodeMeetingConfigCtrlWrap::Reset);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfigDSCP", ZoomNodeMeetingConfigCtrlWrap::ConfigDSCP);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLengthLimitationOfMeetingNumber", ZoomNodeMeetingConfigCtrlWrap::EnableLengthLimitationOfMeetingNumber);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShareIOSDevice", ZoomNodeMeetingConfigCtrlWrap::EnableShareIOSDevice);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShareWhiteBoard", ZoomNodeMeetingConfigCtrlWrap::EnableShareWhiteBoard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ForceDisableMultiShare", ZoomNodeMeetingConfigCtrlWrap::ForceDisableMultiShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableZoomDocs", ZoomNodeMeetingConfigCtrlWrap::EnableZoomDocs);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMaxDurationForOnlyHostInMeeting", ZoomNodeMeetingConfigCtrlWrap::SetMaxDurationForOnlyHostInMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLocalRecordingConvertProgressBarDialog", ZoomNodeMeetingConfigCtrlWrap::EnableLocalRecordingConvertProgressBarDialog);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowVideoOptimizeChkbox", ZoomNodeMeetingConfigCtrlWrap::SetShowVideoOptimizeChkbox);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequiredInfoType", ZoomNodeMeetingConfigCtrlWrap::GetRequiredInfoType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingPasswordAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingPasswordAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingIDAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingIDAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MeetingPasswordAndScreenNameHandler_Cancel", ZoomNodeMeetingConfigCtrlWrap::MeetingPasswordAndScreenNameHandler_Cancel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWebinarNeedRegisterType", ZoomNodeMeetingConfigCtrlWrap::GetWebinarNeedRegisterType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWebinarRegisterUrl", ZoomNodeMeetingConfigCtrlWrap::GetWebinarRegisterUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ReleaseRegisterWebinarByUrl", ZoomNodeMeetingConfigCtrlWrap::ReleaseRegisterWebinarByUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputWebinarRegisterEmailAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputWebinarRegisterEmailAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelRegisterWebinarByEmail", ZoomNodeMeetingConfigCtrlWrap::CancelRegisterWebinarByEmail);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectMeetingInputUserInfoDialog", ZoomNodeMeetingConfigCtrlWrap::RedirectMeetingInputUserInfoDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectConfirmStartArchiveDialog", ZoomNodeMeetingConfigCtrlWrap::RedirectConfirmStartArchiveDialog);

	NODE_SET_PROTOTYPE_METHOD(tpl, "InputScreenName", ZoomNodeMeetingConfigCtrlWrap::InputScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelJoinWebinar", ZoomNodeMeetingConfigCtrlWrap::CancelJoinWebinar);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetDefaultDisplayName", ZoomNodeMeetingConfigCtrlWrap::GetDefaultDisplayName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanModifyDefaultDisplayName", ZoomNodeMeetingConfigCtrlWrap::CanModifyDefaultDisplayName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsValidEmail", ZoomNodeMeetingConfigCtrlWrap::IsValidEmail);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputUserInfo", ZoomNodeMeetingConfigCtrlWrap::InputUserInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelInputUserInfo", ZoomNodeMeetingConfigCtrlWrap::CancelInputUserInfo);

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetArchiveConfirmContent", ZoomNodeMeetingConfigCtrlWrap::GetArchiveConfirmContent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "JoinWithArchive", ZoomNodeMeetingConfigCtrlWrap::JoinWithArchive);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetInputMeetingPasswordAndScreenNameNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetInputMeetingPasswordAndScreenNameNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetAirPlayInstructionWndNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetAirPlayInstructionWndNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonWebinarNeedRegisterNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetonWebinarNeedRegisterNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonEndOtherMeetingToJoinMeetingNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetonEndOtherMeetingToJoinMeetingNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonFreeMeetingRemainTimeCB", ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonFreeMeetingRemainTimeStopCountDownCB", ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeStopCountDownCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonWebinarNeedInputScreenNameCB", ZoomNodeMeetingConfigCtrlWrap::SetonWebinarNeedInputScreenNameCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonJoinMeetingNeedUserInfoCB", ZoomNodeMeetingConfigCtrlWrap::SetonJoinMeetingNeedUserInfoCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonUserConfirmToStartArchiveCB", ZoomNodeMeetingConfigCtrlWrap::SetonUserConfirmToStartArchiveCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EndOtherMeeting", ZoomNodeMeetingConfigCtrlWrap::EndOtherMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelEndOtherMeeting", ZoomNodeMeetingConfigCtrlWrap::CancelEndOtherMeeting);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingConfigCtrlWrap >() {
	return &ZoomNodeMeetingConfigCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
