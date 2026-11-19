/**
 * @file ZoomSDKMeetingWhiteboardController.h
 * @brief Defines the interface for controlling and managing the whiteboard feature in Zoom meetings.
 *
 * This file declares the ZoomSDKMeetingWhiteboardController class, which provides APIs for
 * managing whiteboard sharing, creation, view display, and user permissions during meetings.
 * It also defines the ZoomSDKMeetingWhiteboardControllerDelegate protocol to receive
 * whiteboard status updates and settings changes.
 *
 * This feature enhances collaboration by enabling dynamic whiteboard interaction within
 * Zoom meetings.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @protocol ZoomSDKMeetingWhiteboardControllerDelegate
 * @brief Delegate protocol to receive whiteboard status and settings changes.
 */
@protocol ZoomSDKMeetingWhiteboardControllerDelegate <NSObject>

/**
 * @brief Whiteboard status changed callback. Informs the user that the whiteboard has been started or stopped, and all users in the meeting can get the event.
 * @param status Specify current whiteboard status.
 */
- (void)onWhiteboardStatusChanged:(ZoomSDKWhiteboardStatus)status;

/**
 * @brief Callback event of whiteboard setting type changed.
 * @param shareOption Who can share their whiteboard.
 * @param createOption Who can create a new whiteboard.
 * @param bEnable Whether to enable the participants' ability to create a whiteboard without a host in the meeting.
 */
- (void)onWhiteboardSettingsChanged:(ZoomSDKWhiteboardShareOption)shareOption createOption:(ZoomSDKWhiteboardCreateOption)createOption enable:(BOOL)bEnable;

@end


/**
 * @class ZoomSDKMeetingWhiteboardController
 * @brief Controller to manage whiteboard functionality during Zoom meetings.
 *
 * This class provides interfaces to control whiteboard display, settings,
 * permissions, and status in a meeting environment.
 */
@interface ZoomSDKMeetingWhiteboardController : NSObject
@property(nonatomic,assign,nullable) id<ZoomSDKMeetingWhiteboardControllerDelegate> delegate;

/**
 * @brief Sets the whiteboard web view and dashboard web view owner window.
 * @param window Specify the owner window. If the window is nil, the desktop window will be the owner window.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @warning This function should be called before call ShowDashboardView. Call this function before calling showDashboardView. Call this function when receiving the meeting status ZoomSDKMeetingStatus_InMeeting. Valid only for user custom interface mode.
 */
- (ZoomSDKError)setParentWindow:(NSWindow *)window;

/**
 * @brief Determines whether the current meeting supports the whiteboard or not.
 * @return YES if support. Otherwise, NO.
 */
- (BOOL)isSupportWhiteBoard;

/**
 * @brief Determines whether the current meeting can start sharing the whiteboard.
 * @param reason The reason no one can start sharing the whiteboard.
 * @return YES if you can start sharing the whiteboard. Otherwise, NO.
 */
- (BOOL)canStartShareWhiteboard:(ZoomSDKCannotShareReasonType*)reason;

/**
 * @brief Determines whether the current user can create a new whiteboard.
 * @return YES if the current user can create a new whiteboard. Otherwise, this function returns NO.
 */
 - (BOOL)canStartShareNewWhiteboard;

/**
 * @brief Starts sharing a new whiteboard.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Valid only for user custom interface mode.
 */
- (ZoomSDKError)startNewWhiteboardShare;

/**
 * @brief Determines whether the current user can  stop whiteboard.
 * @return YES if the current user can stop sharing the new whiteboard. Otherwise, this function returns NO.
 */
- (BOOL)canStopWhiteboardShare;

/**
 * @brief When self sharing whiteboard, stop self; when self not sharing, stop all others.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Valid only for user custom interface mode.
 */
- (ZoomSDKError)stopWhiteboardShare;

/**
 * @brief Shows the dashboard web view window.
 * @param point The original point to display dashboard web view window. If the point is (-1,-1) the window positon will be in the screen's center where the owner window is located.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)showDashboardView:(NSPoint)point;

/**
 * @brief Sets the dashboard web view window size.
 * @param size The size of display dashboard web view window. If the size is (0,0) the window size will be default size.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setDashboardViewSize:(NSSize)size;

/**
 * @brief Sets the whiteboard web view window position.
 * @param point The original point to display dashboard web view window. If the point is (-1,-1) the window positon will be in the screen's center where the owner window is located.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setWhiteboardViewPos:(NSPoint)point;

/**
 * @brief Sets the whiteboard web view window size.
 * @param size The size of display whiteboard web view window. If the size is (0,0) the window size will be default size.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setWhiteboardViewSize:(NSSize)size;
/**
 * @brief Sets the option for who can share a whiteboard.
 * @param option New setting for who can share a whiteboard.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setWhiteboardShareOption:(ZoomSDKWhiteboardShareOption)option;

/**
 * @brief Gets the option for who can share whiteboards.
 * @return The setting option for who can share a whiteboard.
 */
- (ZoomSDKWhiteboardShareOption)getWhiteboardShareOption;

/**
 * @brief Sets the option for whiteboard who can initiate a new whiteboard.
 * @param option Setting option for who can initiate a new whiteboard.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setWhiteboardCreateOption:(ZoomSDKWhiteboardCreateOption)option;

/**
 * @brief Gets the option for whiteboard who can initiate a new whiteboard.
 * @return The setting option for whiteboard who can initiate a new whiteboard.
 */
- (ZoomSDKWhiteboardCreateOption)getWhiteboardCreateOption;

/**
 * @brief Enables the participants create a new whiteboard without the host in the meeting.
 * @param bEnable YES indicates to enable, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @deprecated This method is no longer applicable.
 */
- (ZoomSDKError)enableParticipantsCreateWithoutHost:(BOOL)bEnable DEPRECATED_MSG_ATTRIBUTE("This method is no longer applicable.");

/**
 * @brief Determines whether to enable the participants create a new whiteboard without the host in the meeting.
 * @return YES if that they have these permissions. Otherwise, NO.
 * @deprecated This method is no longer applicable.
 */
- (BOOL)isParticipantsCreateWithoutHostEnabled DEPRECATED_MSG_ATTRIBUTE("This method is no longer applicable.");

/**
 * @brief Query if other user is sharing a whiteboard.
 * @return YES if they are sharing. Otherwise, NO.
 */
- (BOOL)isOtherSharingWhiteboard;

/**
 * @brief If the current user is successfully sharing a whiteboard.
 * @return YES if they are sharing. Otherwise, NO.
 */
- (BOOL)isSharingWhiteboardOut;
@end

NS_ASSUME_NONNULL_END
