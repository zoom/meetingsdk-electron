/**
 * @file ZoomSDKRemoteController.h
 * @brief Interface for Zoom SDK remote control feature, including delegate callbacks and control methods.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @protocol ZoomSDKRemoteControllerDelegate
 * @brief The delegate protocol to receive remote control related callbacks.
 */
@protocol ZoomSDKRemoteControllerDelegate <NSObject>
/**
 * @brief Notification of remote control status.
 * @param status The remote control's status.
 * @param userID The ID of user who can control others remotely.
 * @param shareSourceID The source ID of user who is sharing.
 */
- (void)onRemoteControlStatus:(ZoomSDKRemoteControlStatus)status User:(unsigned int)userID shareSourceID:(unsigned int)shareSourceID;

/**
 * @brief Callback event when the request of remote control is forbidden for guest user.
 * @param userId The remote control user ID.
 */
- (void)onUserRemoteControlForbidden:(unsigned int)userId;
@end


/**
 * @class ZoomSDKRemoteControllerHelper
 * @brief Helper class to manage remote control operations in Zoom meeting.
 */
@interface ZoomSDKRemoteControllerHelper : NSObject
{
    id<ZoomSDKRemoteControllerDelegate> _delegate;
    
}
/**
 * @brief The delegate to receive remote control status updates.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKRemoteControllerDelegate> delegate;
/**
 * @brief Determines if the current user to request to control others remotely.
 * @param shareSourceID The user's source ID to be controlled remotely.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note For custom style mode, this interface is only valid after subscribing the sharing content from the specified user by successfully calling "- (ZoomSDKError)createShareElement:(ZoomSDKShareElement**)element" and set the share element userid.
 */
- (ZoomSDKError)canRequestRemoteControl:(unsigned int)shareSourceID;

/**
 * @brief Determines if user has privilege to control the specified user remotely.
 * @param shareSourceID The source ID of user to be checked.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)haveRemoteControlPrivilege:(unsigned int)shareSourceID;

/**
 * @brief Determines if the current user is controlling the specified user remotely.
 * @param shareSourceID The source ID of user to be checked.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)isInRemoteControlling:(unsigned int)shareSourceID;

/**
 * @brief Starts remotely controlling the specified user's computer.
 * @param shareSourceID The source ID of user to be controlled remotely.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startRemoteControl:(unsigned int)shareSourceID;

/**
 * @brief Stops controlling remotely.
 * @param shareSourceID The source ID of user who is controlled remotely by the current user.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopRemoteControl:(unsigned int)shareSourceID;

/**
 * @brief Request remotely control the specified user.
 * @param shareSourceID The source ID of user to be controlled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestRemoteControl:(unsigned int)shareSourceID;

/**
 * @brief Give up remotely controlling the specified user.
 * @param shareSourceID The source ID of user that was remotely controlled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)giveUpRemoteControl:(unsigned int)shareSourceID;

/**
 * @brief Give the remote control privilege to the specified user.
 * @param userid The ID of user that you ask to control yourself remotely.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)giveRemoteControlPrivilegeTo:(unsigned int)userid;

/**
 * @brief Refuse the request to remote control from the specified user.
 * @param userid The ID of demander.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)declineRemoteControlRequest:(unsigned int)userid;

/**
 * @brief Gets back the authority of remote control.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)revokeRemoteControl;

/**
 * @brief Gets the identity of current controller. 
 * @param userid The pointer to unsigned int. If the function calls successfully, it returns the user ID of current remote controller.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getCurrentRemoteController:(unsigned int*)userid;

/**
 * @brief Sends remote control action. 
 * @param theEvent The mouse or keyboard event.
 * @param shareView The view that you want to control remotely.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendRemoteControlEvent:(NSEvent *)theEvent ShareView:(NSView*)shareView;

/**
 * @brief Determines if the auto accept remote control requests feature is enabled in the meeting.
 * @return YES if the feature enabled. Otherwise, NO.
 */
- (BOOL)IsAutoAcceptRemoteControlFeatureEnabled;

/**
 * @brief Whether the current user can enable the auto accept remote control requests feature.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canEnableAutoAcceptRemoteControlFeature;

/**
 * @brief Enables or disable auto accept remote control requests feature.
 * @param enable YES if auto accept remote control requests are enabled, NO if disabled.
 * @return If the function succeeds, it returns the @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Before using this interface, it is necessary to give the app accessibility permissions in the System Settings.
 */
- (ZoomSDKError)enableAutoAcceptRemoteControlFeature:(BOOL)enable;
@end
NS_ASSUME_NONNULL_END
