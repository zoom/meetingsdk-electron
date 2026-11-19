/**
 * @file ZoomSDKMeetingDocsController.h
 * @brief Defines interfaces for controlling and managing Zoom Docs sharing in meetings.
 *
 * This file declares the ZoomSDKMeetingDocsController class and related delegate protocol
 * for managing Zoom Docs sharing, permissions, and view control during a meeting.
 * It also defines the ZoomSDKDocsSharingSourceInfo class, which provides information about
 * docs sharing sources.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomSDKDocsSharingSourceInfo
 * @brief Zoom Docs sharing source information class.
 */
@interface ZoomSDKDocsSharingSourceInfo: NSObject
/**
 * @brief Gets the share source ID of who is sharing Zoom docs.
 */
@property(nonatomic, assign, readonly) unsigned int shareSourceID;
/**
 * @brief Gets the user ID of who is sharing Zoom docs.
 */
@property(nonatomic, assign, readonly) unsigned int userID;
/**
 * @brief Gets the status of Zoom docs sharing.
 */
@property(nonatomic, assign, readonly) ZoomSDKDocsStatus status;
/**
 * @brief Gets the shared Zoom docs's title.
 */
@property(nonatomic, copy, readonly) NSString *docTitle;
@end



/**
 * @protocol ZoomSDKMeetingDocsControllerDelegate
 * @brief Callback event for Zoom Docs sharing events.
 */
@protocol ZoomSDKMeetingDocsControllerDelegate <NSObject>
/**
 * @brief Docs status changed callback. Informs that the user docs status changed, and all users in the meeting can get the event.
 * @param shareSourceInfo Share source info of Zoom docs.
 */
- (void)onDocsSharingSourceInfoChanged:(ZoomSDKDocsSharingSourceInfo *)shareSourceInfo;

/**
 * @brief Callback event of docs share setting type changed.
 * @param createOption Docs who can create new docs type.
 * @param shareOption Docs who can share type.
 */
- (void)onDocsPermissionChanged:(ZoomSDKDocsCreateOption)createOption shareOption:(ZoomSDKDocsShareOption)shareOption;
@end


/**
 * @class ZoomSDKMeetingDocsController
 * @brief Zoom SDK meeting docs sharing controller.
 */
@interface ZoomSDKMeetingDocsController : NSObject
/**
 * @brief The delegate object to receive docs sharing events.
 */
@property(nonatomic,assign,nullable) id<ZoomSDKMeetingDocsControllerDelegate> delegate;

/**
 * @brief Determines whether the current meeting supports docs or not.
 * @return YES if that the current meeting supports docs. Otherwise, NO.
 */
- (BOOL)isSupportDocs;

/**
 * @brief Determines whether the current user can start sharing the docs or not.
 * @param reason The reason why no one can start sharing the docs.
 * @return YES if you can start sharing the docs. Otherwise, NO.
 */
- (BOOL)canStartShareDocs:(ZoomSDKCannotShareReasonType*)reason;

/**
 * @brief Determines whether the current user can set docs options or not.
 * @return YES if the current user can set docs options. Otherwise, NO.
 */
- (BOOL)canSetDocsOption;

/**
 * @brief Query if other user is sharing docs.
 * @return YES if sharing. Otherwise, NO.
 */
- (BOOL)isOtherSharingDocs;

/**
 * @brief Query if the current user is sharing docs successfully.
 * @return YES if sharing successfully. Otherwise, NO.
 */
- (BOOL)isSharingDocsOut;

/**
 * @brief Sets the docs'setting option for who can share docs.
 * @param option The setting for who can share docs.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setDocsShareOption:(ZoomSDKDocsShareOption)option;

/**
 * @brief Gets the setting option indicating who can share documents.
 * @return The docs share option.
 */
- (ZoomSDKDocsShareOption)getDocsShareOption;

/**
 * @brief Sets the setting option for who can initiate new docs.
 * @param option Docs setting option for who can initiate new docs.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setDocsCreateOption:(ZoomSDKDocsCreateOption)option;

/**
 * @brief Gets the setting option indicating whether the user can initiate new docs.
 * @return The docs creation option.
 */
- (ZoomSDKDocsCreateOption)getDocsCreateOption;

/**
 * @brief Shows the dashboardView web view window.
 * @param point The original point to display dashboard web view window. Default is (0,0).
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only available for the custom UI.
 */
- (ZoomSDKError)showDashboardWindow:(NSPoint)point;

/**
 * @brief Sets the docs web view window position.
 * @param point The original point to display docs web view window. Default is (0,0).
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only available for the custom UI.
 */
- (ZoomSDKError)setDocsWindowPos:(NSPoint)point;

/**
 * @brief Sets the docs web view window size.
 * @param size The size of display docs web view window. If the size is (0,0), the window size will be default size.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only available for the custom UI.
 */
- (ZoomSDKError)setDocsWindowSize:(NSSize)size;

/**
 * @brief Shows the docs web view window.
 * @param shareSourceID The share source ID that is sharing.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only available for the custom UI.
 */
- (ZoomSDKError)showDocsWindow:(unsigned int)shareSourceID;

/**
 * @brief Closes the docs web view window.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only available for the custom UI.
 */
- (ZoomSDKError)closeDocsWindow;

/**
 * @brief Gets the ID of users who are sharing docs.
 * @return A list of userID of all users who are sharing docs. Otherwise, this function fails and returns nil.
 */
- (NSArray<NSNumber *>* _Nullable)getViewableSharingUserList;

/**
 * @brief Gets the list of docs sharing source info.
 * @param userID The user's ID who is sharing docs.
 * @return If the function succeeds, it returns a pointer to the NSArray<ZoomSDKDocsSharingSourceInfo*>. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKDocsSharingSourceInfo *>* _Nullable)getSharingSourceInfoList:(unsigned int)userID;
@end

NS_ASSUME_NONNULL_END
