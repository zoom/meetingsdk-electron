/**
 * @file ZoomSDKAICompanionSmartSummaryHelper.h
 * @brief Interfaces for managing Smart Summary feature in Zoom AI Companion.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKEnableSmartSummaryHandler
 * @brief Handler to enable smart summary feature or handle enable requests.
 */
@interface ZoomSDKEnableSmartSummaryHandler : NSObject
/**
 * @brief Enables smart summary.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableSmartSummary;
/**
 * @brief Determines if this handler for request enable smart summary.
 * @return YES if this handler is for request enable smart summary. Otherwise, NO.
 */
- (BOOL)isForRequest;
@end

/**
 * @class ZoomSDKStartSmartSummaryHandler
 * @brief Handler to start smart summary feature or handle start requests.
 */
@interface ZoomSDKStartSmartSummaryHandler : NSObject
/**
 * @brief Starts meeting summary.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startSmartSummary;
/**
 * @brief Determines if this handler for request enable smart summary.
 * @return YES if this handler is for request start smart summary. Otherwise, NO.
 */
- (BOOL)isForRequest;
@end

/**
 * @class ZoomSDKStopSmartSummaryHandler
 * @brief Handler to stop the smart summary feature.
 */
@interface ZoomSDKStopSmartSummaryHandler : NSObject
/**
 * @brief Stops meeting summary.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopSmartSummary;
@end


/**
 * @class ZoomSDKEnableSmartSummaryActionHandler
 * @brief Handler to confirm or cancel enabling smart summary, and provide related tips.
 */
@interface ZoomSDKEnableSmartSummaryActionHandler : NSObject
/**
 * @brief Gets the title of tip.
 */
@property (nonatomic, copy, readonly, nullable) NSString *tipTitle;
/**
 * @brief Gets the tip string.
 */
@property (nonatomic, copy, readonly, nullable) NSString *tipString;
/**
 * @brief Confirms enabling smart summary.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)confirm;
/**
 * @brief Cancels enabling smart summary.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @class ZoomSDKApproveStartSmartSummaryHandler
 * @brief Handler to approve or decline requests to start smart summary.
 */
@interface ZoomSDKApproveStartSmartSummaryHandler : NSObject
/**
 * @brief Gets the requester's user ID.
 * @note Returns 0 when the requester is from a user in the main meeting who is not in the host's local participant cache
 * (e.g., a participant in the main meeting requesting while the host is in a breakout room).
 * In this case, use requesterUserName to obtain the requester's display name.
 */
@property (nonatomic, assign, readonly) unsigned int senderUserID;
/**
 * @brief Gets the requester's user name.
 * @note This value is always valid, even when senderUserID returns 0.
 */
@property (nonatomic, copy, readonly) NSString *requesterUserName;
/**
 * @brief Approve request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)approve;
/**
 * @brief Decline request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline;
@end


/**
 * @class ZoomSDKApproveEnableSmartSummaryHandler
 * @brief Handler to continue approval for enabling smart summary.
 */
@interface ZoomSDKApproveEnableSmartSummaryHandler : NSObject
/**
 * @brief Gets the requester's user ID.
 */
@property (nonatomic, assign, readonly) unsigned int senderUserID;
/**
 * @brief Continue approve action.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)continueApprove;
@end


/**
 * @protocol ZoomSDKAICompanionSmartSummaryHelperDelegate
 * @brief Delegate protocol to receive Smart Summary feature status updates and requests.
 */
@protocol ZoomSDKAICompanionSmartSummaryHelperDelegate <NSObject>

/**
 * @brief Notify the meting does not support smart summary at the meeting's start.
 */
- (void)onSmartSummaryStateNotSupported;

/**
 * @brief Notify the meting support smart summary but smart summary feature is disabled.
 * @param handler The handler to enable smart summary.
 */
- (void)onSmartSummaryStateSupportedButDisabled:(ZoomSDKEnableSmartSummaryHandler* _Nullable)handler;

/**
 * @brief Notify the meeting smart summary is not started.
 * @param handler The handler to start smart summary.
 */
- (void)onSmartSummaryStateEnabledButNotStarted:(ZoomSDKStartSmartSummaryHandler* _Nullable)handler;

/**
 * @brief Notify the meeting smart summary is started.
 * @param handler The handler to stop smart summary. If the user can not stop smart summary, the handler will be null.
 */
- (void)onSmartSummaryStateStarted:(ZoomSDKStopSmartSummaryHandler* _Nullable)handler;

/**
 * @brief Notify failed to start the smart summary.
 * @param timeout YES if timeout, otherwise no timeout. May be declined by host or cohost.
 */
- (void)onFailedToStartSmartSummary:(BOOL)timeout;

/**
 * @brief Notify receive request to enable smart summary.
 * @param handler The handler to handle enable smart summary request.
 */
- (void)onSmartSummaryEnableRequestReceived:(ZoomSDKApproveEnableSmartSummaryHandler* _Nullable)handler;

/**
 * @brief Notify receive request to start smart summary.
 * @param handler The handler to handle request.
 */
- (void)onSmartSummaryStartRequestReceived:(ZoomSDKApproveStartSmartSummaryHandler* _Nullable)handler;

/**
 * @brief Notify receive smart summary enable action callback.
 * @param handler The handler to enable smart summary.
 */
- (void)onSmartSummaryEnableActionCallback:(ZoomSDKEnableSmartSummaryActionHandler* _Nullable)handler;

@end


/**
 * @class ZoomSDKAICompanionSmartSummaryHelper
 * @brief Helper class to manage AI Companion smart summary features.
 */
@interface ZoomSDKAICompanionSmartSummaryHelper : NSObject
/**
 * @brief Delegate to receive smart summary related events.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKAICompanionSmartSummaryHelperDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
