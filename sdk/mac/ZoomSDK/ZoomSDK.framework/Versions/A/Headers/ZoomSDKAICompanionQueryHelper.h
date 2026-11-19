/**
 * @file ZoomSDKAICompanionQueryHelper.h
 * @brief Interface declarations related to AI Companion query feature in Zoom SDK.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN


/**
 * @brief Enumeration of the types of feedback for AI Companion query responses.
 */
typedef enum {
    /** For initialization. */
    ZoomSDKAICompanionQueryFeedbackType_None = 0,
    /** Indicates the feedback is positive, the query response was good. */
    ZoomSDKAICompanionQueryFeedbackType_Good,
    /** Indicates the feedback is negative, the query response was bad. */
    ZoomSDKAICompanionQueryFeedbackType_Bad
}ZoomSDKAICompanionQueryFeedbackType;

/**
 * @brief Enumeration of the error types for AI Companion query requests.
 */
typedef enum {
    /** The request was successful, no error. */
    ZoomSDKAICompanionQueryRequestError_OK = 0,
    /** Invalid parameter provided in the query request. */
    ZoomSDKAICompanionQueryRequestError_InvalidParam,
    /** The request failed to be sent. */
    ZoomSDKAICompanionQueryRequestError_SendFailed,
    /** The web service is unavailable. */
    ZoomSDKAICompanionQueryRequestError_WebUnAvailable,
    /** Permission verification failed for the query request. */
    ZoomSDKAICompanionQueryRequestError_PermissionVerifyFailed,
    /** The query request exceeded the rate limit. */
    ZoomSDKAICompanionQueryRequestError_QueryRateLimitError,
    /** The query request timed out. */
    ZoomSDKAICompanionQueryRequestError_Timeout,
    /** An unknown error occurred. */
    ZoomSDKAICompanionQueryRequestError_Unknown = 100
}ZoomSDKAICompanionQueryRequestError;


/**
 * @brief Enumeration of configuration options for who in the meeting can interact with AI Companion by asking questions about the meeting.
 * For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0057748> and <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0079893>.
 */
typedef enum {
    /** For initialization. */
    ZoomSDKAICompanionQuerySettingOptions_None = 0,
    /** Allows all participants and attendee to ask questions about all discussions since AI Companion was active. */
    ZoomSDKAICompanionQuerySettingOptions_WhenQueryStarted,
    /** Allows all participants to ask questions about the discussion since they joined the current meeting. */
    ZoomSDKAICompanionQuerySettingOptions_WhenParticipantsJoin,
    /** Allows only the host, alternative host, and users with host privileges assigned before the meeting start time to ask questions about all discussions since AI Companion is active. */
    ZoomSDKAICompanionQuerySettingOptions_OnlyHost,
    /** Allows only participants and invitees from your organization to ask questions about all discussions since AI Companion is active. */
    ZoomSDKAICompanionQuerySettingOptions_ParticipantsAndInviteesInOurOrganization,
    /** Allows only participants from your organization to ask questions about the discussion since they joined the current meeting. */
    ZoomSDKAICompanionQuerySettingOptions_WhenParticipantsAndOrganizationJoin,
    /** Hosts and all panelists can ask questions, and answers are based on the meeting's start time until now. */
    ZoomSDKAICompanionQuerySettingOptions_HostAndPanelists = 10,
    /** Hosts and any panelists in our organization can ask questions, and answers are based on the meeting's start time until now. */
    ZoomSDKAICompanionQuerySettingOptions_HostAndPanelistsInOurOrganization
}ZoomSDKAICompanionQuerySettingOptions;


/**
 * @class ZoomSDKAICompanionQueryItem
 * @brief Represents a query item including question, answer, and error information for AI Companion.
 */
@interface ZoomSDKAICompanionQueryItem : NSObject
/**
 * @brief Gets the query question content.
 */
@property(nonatomic, copy, readonly, nullable) NSString* qustionContent;
/**
 * @brief Gets the query question ID.
 */
@property(nonatomic, copy, readonly, nullable) NSString* queryID;

/**
 * @brief Gets the query answer content.
 */
@property(nonatomic, copy, readonly, nullable) NSString* answerContent;

/**
 * @brief Gets the error code.
 */
@property(nonatomic, assign, readonly) ZoomSDKAICompanionQueryRequestError errorCode;

/**
 * @brief Gets the error message.
 */
@property(nonatomic, copy, readonly, nullable) NSString* errorMsg;

/**
 * @brief Gets the timestamp.
 */
@property(nonatomic, assign, readonly) time_t timestamp;

/**
 * @brief Sends feedback of query answer.
 * @param feedbackType The feedback type.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)feedback:(ZoomSDKAICompanionQueryFeedbackType)feedbackType;
@end


/**
 * @class ZoomSDKEnableQueryHandler
 * @brief Handler to enable the meeting query feature.
 */
@interface ZoomSDKEnableQueryHandler : NSObject
/**
 * @brief Enables meeting query.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableQuery;

/**
 * @brief Determines if this handler for request enable query.
 * @return YES if this handler is for request enable query. Otherwise it returns NO means this handler is for enable query directly.
 */
- (BOOL)isForRequest;
@end


/**
 * @class ZoomSDKStartQueryHandler
 * @brief Handler to start the meeting query feature.
 */
@interface ZoomSDKStartQueryHandler : NSObject
/**
 * @brief Starts meeting query.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startMeetingQuery;

/**
 * @brief Determines if this handler for request enable query.
 * @return YES if this handler is for request enable query. Otherwise it returns NO means this handler is for start query directly.
 */
- (BOOL)isForRequest;
@end

/**
 * @class ZoomSDKApproveEnableQueryHandler
 * @brief Handler to approve or continue enabling query request.
 */
@interface ZoomSDKApproveEnableQueryHandler : NSObject
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
 * @class ZoomSDKApproveStartQueryHandler
 * @brief Handler to approve or decline the start query request.
 */
@interface ZoomSDKApproveStartQueryHandler : NSObject
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
 * @brief Approve the request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)approve;

/**
 * @brief Decline the request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline;
@end


/**
 * @class ZoomSDKApproveSendQueryHandler
 * @brief Handler to approve or decline the send query request.
 */
@interface ZoomSDKApproveSendQueryHandler : NSObject
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
 * @brief Approve the request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)approve;

/**
 * @brief Decline the request.
 * @param declineAll YES to decline all request, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline:(BOOL)declineAll;
@end


/**
 * @class ZoomSDKSendQueryHandler
 * @brief Handler for sending queries during the meeting.
 */
@interface ZoomSDKSendQueryHandler : NSObject
/**
 * @brief Deterine if the current user can send query.
 * @return YES if can. Otherwise, NO.
 */
- (BOOL)canSendQuery;

/**
 * @brief Request send query privilege.
 * @return If the function succeeds, it returns ZoomSDKError_Success Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestSendQueryPrivilege;

/**
 * @brief Gets default query questions.
 * @return If the function succeeds, it returns the array of questions. Otherwise, this function fails and returns nil.
 */
- (NSArray<NSString*>*_Nullable)getDefaultQueryQuestions;

/**
 * @brief Sends query question.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendQueryQuestion:(NSString*)question;

/**
 * @brief Stops meeting query.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopMeetingQuery;
@end


/**
 * @class ZoomSDKEnableQueryActionHandler
 * @brief Handler for actions related to enabling meeting query.
 */
@interface ZoomSDKEnableQueryActionHandler : NSObject
/**
 * @brief Gets the tip's title.
 */
- (NSString*_Nullable)tipTitle;

/**
 * @brief Gets the tip string.
 */
- (NSString*_Nullable)tipString;

/**
 * @brief Confirms enable query.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)confirm;

/**
 * @brief Cancels enable query.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancel;
@end


/**
 * @protocol ZoomSDKAICompanionQueryHelperDelegate
 * @brief Delegate protocol for receiving AI Companion meeting query related events.
 */
@protocol ZoomSDKAICompanionQueryHelperDelegate <NSObject>
@optional
/**
 * @brief Notification that the meting does not support meeting query.
 */
- (void)onQueryStateNotSupported;

/**
 * @brief Notification that the meting supports query but query feature is disabled.
 * @param handler The handler to enable the query.
 */
- (void)onQueryStateSupportedButDisabled:(ZoomSDKEnableQueryHandler*)handler;

/**
 * @brief Notification that the query is not started.
 * @param handler The handler to start the query.
 */
- (void)onQueryStateEnabledButNotStarted:(ZoomSDKStartQueryHandler*)handler;

/**
 * @brief Notification that the query is started.
 * @param handler The handler to send the query.
 */
- (void)onQueryStateStarted:(ZoomSDKSendQueryHandler*)handler;

/**
 * @brief Notification that the query setting is changed.
 * @param setting The selected query setting.
 */
- (void)onQuerySettingChanged:(ZoomSDKAICompanionQuerySettingOptions)setting;

/**
 * @brief Notification of got or loss send query question privilege.
 * @param canSendQuery YES if can send, NO otherwise.
 */
- (void)onSendQueryPrivilegeChanged:(BOOL)canSendQuery;

/**
 * @brief Notification that the query failed to start.
 * @param bTimeout YES if timeout, NO if the user declines the request.
 */
- (void)onFailedToStartQuery:(BOOL)bTimeout;

/**
 * @brief Notification of receiving request to enable query.
 * @param handler The handler to handle the request.
 */
- (void)onReceiveRequestToEnableQuery:(ZoomSDKApproveEnableQueryHandler *)handler;

/**
 * @brief Notification of receiving request to start query.
 * @param handler The handler to handle the request.
 */
- (void)onReceiveRequestToStartQuery:(ZoomSDKApproveStartQueryHandler *_Nullable)handler;

/**
 * @brief Notification of receiving a request to send query.
 * @param handler The handler to handle the request.
 */
- (void)onReceiveRequestToSendQuery:(ZoomSDKApproveSendQueryHandler *_Nullable)handler;

/**
 * @brief Notification of receiving query answer.
 * @param queryItem The obect of ZoomSDKAICompanionQueryItem.
 */
- (void)onReceiveQueryAnswer:(ZoomSDKAICompanionQueryItem*)queryItem;

/**
 * @brief Notification that the request to send query failed.
 * @param bTimeout YES if the request timed out, No otherwise.
 */
- (void)onFailedToRequestSendQuery:(BOOL)bTimeout;

/**
 * @brief Notification of receiving query enable action callback.
 * @param handler The handler to enable the query.
 */
- (void)onQueryEnableActionCallback:(ZoomSDKEnableQueryActionHandler *)handler;
@end


/**
 * @class ZoomSDKAICompanionQueryHelper
 * @brief Helper class to manage AI Companion meeting query features and related legal notices.
 */
@interface ZoomSDKAICompanionQueryHelper : NSObject

/**
 * @brief Delegate to receive AI Companion query events.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKAICompanionQueryHelperDelegate> delegate;

/**
 * @brief Gets the selected query setting.
 * @return If the function succeeds, it returns the selected query setting. Otherwise, this function returns an error.
 */
- (ZoomSDKAICompanionQuerySettingOptions)getSelectedQuerySetting;

/**
 * @brief Determines whether the current user can change query setting.
 * @return YES if it can change the setting. Otherwise, NO.
 */
- (BOOL)canChangeQuerySetting;

/**
 * @brief Change query setting.
 * @param setting The new query setting to apply.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)changeQuerySettings:(ZoomSDKAICompanionQuerySettingOptions)setting;

/**
 * @brief Determines whether the legal notice for  the AI Companion query is available.
 * @return YES if the legal notice for the AI Companion query is available. Otherwise the legal notice is not available.
 */
- (BOOL)isAICompanionQueryLegalNoticeAvailable;

/**
 * @brief Gets the AI Companion query legal notices prompt.
 * @return If the function succeeds, it returns the AI Companion query legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getAICompanionQueryLegalNoticesPrompt;

/**
 * @brief Gets the AI Companion query legal notices explained.
 * @return If the function succeeds, it returns the AI Companion query legal notices explained. Otherwise, this function fails and returns nil.
 */
- (NSString *)getAICompanionQueryLegalNoticesExplained;

/**
 * @brief Determines whether the legal notice for the AI Companion query privacy is available.
 * @return YES if the legal notice for the AI Companion query privacy is available. Otherwise the legal notice is not available.
 */
- (BOOL)isAICompanionQueryPrivacyLegalNoticeAvailable;

/**
 * @brief Gets the AI Companion query privacy legal notices prompt.
 * @return If the function succeeds, it returns the AI Companion query privacy legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getAICompanionQueryPrivacyLegalNoticesPrompt;
@end
NS_ASSUME_NONNULL_END
