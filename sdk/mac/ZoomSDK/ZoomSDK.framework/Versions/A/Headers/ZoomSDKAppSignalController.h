/**
 * @file ZoomSDKAppSignalController.h
 * @brief Interface for controlling application signal and AI Companion panel UI in Zoom SDK.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKAppSignalController
 * @brief A controller that manages the display of App Signal and AI Companion panels.
 */
@interface ZoomSDKAppSignalController : NSObject

/**
 * @brief Shows app signal panel.
 * @param point The original point to display app signal panel.
 * @param parentWindow The parent window to locate the application signal panel.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)showAANPanel:(NSPoint)point parentWindow:(NSWindow*)parentWindow;

/**
 * @brief Closes app signal panel.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hideAANPanel;

/**
 * @brief Shows the dynamic notice for AI Companion panel window.
 * @param point The original point to display AICompanion panel.
 * @param parentWindow Show the AI companion panel's dynamic notice in this window.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)showDynamicNoticeForAICompanionPanel:(NSPoint)point parentWindow:(NSWindow*)parentWindow;

/**
 * @brief Hides the dynamic notice for AI Companion panel window.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hideDynamicNoticeForAICompanionPanel;
@end

NS_ASSUME_NONNULL_END
