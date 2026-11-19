/**
 * @file ZoomSDKMeetingUIController.h
 * @brief Interfaces for customizing the Zoom meeting UI components and handling related user interactions.
 */


NS_ASSUME_NONNULL_BEGIN
/**
 * @protocol ZoomSDKMeetingUIControllerDelegate
 * @brief Protocol for receiving user interaction events in Zoom meeting UI.
 */
@protocol ZoomSDKMeetingUIControllerDelegate <NSObject>
/**
 * @brief Callback of clicking invite button in toolbar. If user wants to customize the invitation UI, set _disableToolbarInviteButtonClickOriginAction to YES in ZoomSDKMeetingConfiguration.
 */
- (void)onToolbarInviteButtonClick;

/**
 * @brief Notification when participant clicks LEAVE MEETING button. 
 * @param participantID The ID of participant who leaves meeting.
 */
- (void)onClickLeaveMeeting:(unsigned int)participantID;

/**
 * @brief Notification when SHARE button in toolbar is clicked.
 */
- (void)onToolbarShareButtonClick;

/**
 * @brief Notification when participant button is clicked.
 */
- (void)onParticipantButtonClicked;

/**
 * @brief Notification when custom LIVE button is clicked. 
 */
- (void)onCustomLiveButtonClicked;

/**
 * @brief Notification when audio menu button is clicked.
 */
- (void)onAudioSettingMenuButtonClicked;

/**
 * @brief Notification when audio button is clicked.
 * @param userid The userid of user unique identifier .
 * @param info The enum of audio action info.
 */
- (void)onAudioButtonClicked:(unsigned int)userid audioSession:(ZoomSDKAudioActionInfo)info;

/**
 * @brief Notification when breakout Rooms button is clicked.
 */
- (void)onBreakoutRoomsButtonClick;

/**
 * @brief Notification when CloseCaption button is clicked.
 */
- (void)onCloseCaptionButtonClick;
@end


/**
 * @class ZoomSDKMeetingUIController
 * @brief Class to control and customize Zoom meeting UI components.
 */
@interface ZoomSDKMeetingUIController :NSObject
{
    id<ZoomSDKMeetingUIControllerDelegate> _delegate;
}
/**
 * @brief Sets the delegate to receive meeting UI related events.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKMeetingUIControllerDelegate> delegate;

/**
 * @brief Whether to show components in meeting and meeting controls.
 * @param component The enum of meeting components.
 * @param window The pointer to the window. When the function calls successfully, the 'window' will be the meeting component window.
 * @param show YES to show the components, NO to hide
 * @param inPanel YES to show the components in panel, NO otherwise.
 * @param componentFrame The meeting component's frame.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */  
- (ZoomSDKError)showMeetingComponent:(MeetingComponent)component window:(NSWindow*_Nullable*_Nullable)window show:(BOOL)show InPanel:(BOOL)inPanel frame:(NSRect)componentFrame;

/**
 * @brief Enter full screen mode.
 * @param fullScreen YES to enter full screen, NO otherwise.
 * @param firstView YES to enter full screen mode on the first view, NO otherwise.
 * @param secondView YES to enter full screen mode on the second view, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */ 
- (ZoomSDKError)enterFullScreen:(BOOL)fullScreen firstMonitor:(BOOL)firstView DualMonitor:(BOOL)secondView;
/**
 * @brief Switch to video wall view.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */ 
- (ZoomSDKError)switchToVideoWallView;
/**
 * @brief Switch to the mode of showing the current speaker.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchToActiveSpeakerView;
/**
 * @brief Determines if the meeting is in minimize window mode.
 * @return YES if it is in minimize window mode. Otherwise, NO.
 */ 
- (BOOL)isInMiniVideoMode;

/**
 * @brief Switch UI between mini video and mini bar(without video), it works only when isInMiniVideoMode = YES.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchMiniVideoModeUI;

/**
 * @brief Switch float video display mode to minimize mode.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchFloatVideoToMinimizeMode;
/**
 * @brief Switch float video display mode to wall mode.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchFloatVideoToWallMode;
/**
 * @brief Switch float video display mode to active speaker.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchFloatVideoToActiveSpeakerMode;
/**
 * @brief Switch float video display mode to gallery view mode.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)switchFloatVideoToGalleryMode;

/**
 * @brief Display or not the user who does not turn on the video in the video wall mode.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hideOrShowNoVideoUserOnVideoWall:(BOOL)hide;

/**
 * @brief Gets the page information in video wall mode.
 * @param currentPageNum The number of current page.
 * @param totalPageNum The number of total pages.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getWallViewPageInfo:(int*)currentPageNum TotalPageNum:(int*)totalPageNum;

/**
 * @brief Display previous or following page of video wall in the meeting.
 * @param nextPage Set it to YES to display following page of video wall, NO to display previous page.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)showPreOrNextPageWallView:(BOOL)nextPage;

/**
 * @brief Active the principal window of meeting and place it on top.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)backToMeeting;

/**
 * @brief Determines when join meeting the video preview is display.
 * @return YES if it is display video preview. Otherwise, NO.
 */
- (BOOL)showVideoPreviewWhenJoinMeeting;

/**
 * @brief Display video preview when join meeting.
 * @param isShow YES to display video preview, NO otherwise.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)isShowVideoPreviewWhenJoinMeeting:(BOOL)isShow;

/**
 * @brief Display previous or following page of video view when in sharing.
 * @param nextPage Set it to YES to display following page of video view, NO to display previous page.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)pagingToPreOrNextViewWhenSharing:(BOOL)nextPage;

/**
 * @brief Sets the invitation domain.
 * @param invitationDomain Specify the invitation domain.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustomizedInvitationDomain:(NSString*)invitationDomain;

/**
 * @brief Allowing the developer to customize the URL of create or edit the polling.
 * @param urlString Customized URL.
 * @param bCreate YES to change the URL of creating a polling, NO to change the URL of editing a polling.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCustomizedPollingUrl:(NSString*)urlString bCreate:(BOOL)bCreate;

/**
 * @brief Sets the feedback url in the white board page.
 * @param feedbackUrl Specify the feedback url in the the white board page.
 * @return If the function succeeds, it returns the ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setCloudWhiteboardFeedbackUrl:(NSString*)feedbackUrl;

/**
 * @brief Sets the visibility of request local recording privilege dialog when attendee request local recording privilege. Default is displaying.
 * @param bHide YES indicates to hide the tab, NO to display the dialog.
 */
- (void)hideRequestRecordPrivilegeDialog:(BOOL)bHide;
@end
NS_ASSUME_NONNULL_END
