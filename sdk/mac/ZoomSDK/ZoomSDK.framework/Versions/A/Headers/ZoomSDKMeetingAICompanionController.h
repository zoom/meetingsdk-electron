/**
 * @file ZoomSDKMeetingAICompanionController.h
 * @brief Zoom SDK AI Companion feature control interface.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 *
 * This file defines interfaces for managing AI Companion features during meetings,
 * including smart summary, query helper, and controlling feature states.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
#import <ZoomSDK/ZoomSDKAICompanionQueryHelper.h>
#import <ZoomSDK/ZoomSDKAICompanionSmartSummaryHelper.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKAICompanionFeatureTurnOnAgainHandler
 * @brief Handler to turn on AI Companion features again.
 */
@interface ZoomSDKAICompanionFeatureTurnOnAgainHandler : NSObject
/**
 * @brief Gets the list of features that the attendee turns off. For more information, see \link ZoomSDKAICompanionFeature \endlink.
 */
@property(nonatomic,retain,readonly,nullable)NSArray *featuresList;
/**
 * @brief Gets the feature list that the assets are deleted when the feature is turned off by attendee. For more information, see \link ZoomSDKAICompanionFeature \endlink.
 */
@property(nonatomic,retain,readonly,nullable)NSArray *assetsDeletedFeatureList;
/**
 * @brief Turn on the auto AI Companion feature which was stopped by the attendee before the host or cohost joined meeting.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnOnAgain;

/**
 * @brief Agree the auto AI Companion feature turn off status. Keep the AI Companion feature off.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)agreeTurnOff;
@end

/**
 * @class ZoomSDKAICompanionFeatureSwitchHandler
 * @brief Handler to respond to requests for turning AI Companion features on or off.
 */
@interface ZoomSDKAICompanionFeatureSwitchHandler : NSObject
/**
 * @brief The user ID who requests the host to turn the AI Companion features on or off.
 * @note This value may return 0 in some cross-context scenarios, such as when the host is in a breakout room,
 *       or when the requester is not in the host's local participant cache).
 *       In these cases, use requesterUserName to obtain the requester's display name.
 */
@property(nonatomic,assign,readonly)unsigned int requestUserID;
/**
 * @brief Gets the requester's user name.
 * @note This value is always valid, even when requestUserID returns 0.
 */
@property (nonatomic, copy, readonly) NSString *requesterUserName;
/**
 * @brief Turn the AI Companion features on or off.
 */
@property(nonatomic,assign,readonly)BOOL isTurnOn;
/**
 * @brief Agree to the request to turn  the AI Companion features on or off.
 * @param deleteAssets YES to delete the meeting assets when turning off the AI Companion features, NO otherwise.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)agree:(BOOL)deleteAssets;

/**
 * @brief Decline the request to turn the AI Companion features on or off.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline;
@end


/**
 * @protocol ZoomSDKMeetingAICompanionControllerDelegate
 * @brief Callback events for AI Companion feature control.
 */
@protocol ZoomSDKMeetingAICompanionControllerDelegate <NSObject>

/**
 * @brief Sink the event when the auto start AI Companion feature is turned off by an attendee before the host joins. Only the host or cohost can receive the callback.
 * @param handler The handler to turn on the AI feature again or leave the feature turned off.
 */
- (void)onAICompanionFeatureTurnOffByParticipant:(ZoomSDKAICompanionFeatureTurnOnAgainHandler*)handler;

/**
 * @brief Sink the event when the host receives the request to turn the AI Companion features on or off.
 * @param handler The handler to turn the AI Companions features on or off.
 */
- (void)onAICompanionFeatureSwitchRequested:(ZoomSDKAICompanionFeatureSwitchHandler*)handler;

/**
 * @brief Sink the event when the host handles the request to turn  the AI Companion features on or off.
 * @param timeout Specify the host not handle the request until timeout.
 * @param agree Specify the host agrees to the request to turn the AI companion features on or off.
 * @param turnOn Specify the host respond the request of turn on or off.
 */
- (void)onAICompanionFeatureSwitchRequestResponse:(BOOL)timeout isAgree:(BOOL)agree isTurnOn:(BOOL)turnOn;

/**
 * @brief Sink the event when the started AI Companion feature can't be turned off.
 * @param features The AI features that can't be turned off. For more information, see \link ZoomSDKAICompanionFeature \endlink.
 */
- (void)onAICompanionFeatureCanNotBeTurnedOff:(NSArray*)features;

/**
 * @brief Sink the event when the host's client does not support handling the stop Notes request.
 * @note This callback is triggered when a participant requests to stop Notes, but the meeting host's client version does not support processing this request.
 */
- (void)onHostUnsupportedStopNotesRequest;
@end


/**
 * @class ZoomSDKMeetingAICompanionController
 * @brief AI Companion feature control class.
 */
@interface ZoomSDKMeetingAICompanionController : NSObject

/**
 * @brief Delegate to receive AI Companion feature callbacks.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKMeetingAICompanionControllerDelegate> delegate;

/**
 * @brief Gets the smart summary controller.
 * @return If the function succeeds, it returns a pointer to ZoomSDKAICompanionSmartSummaryHelper. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAICompanionSmartSummaryHelper*)getSmartSummaryHelper;
/**
 * @brief Gets object of ZoomSDKAICompanionQueryHelper.
 * @return If the function succeeds, it returns a ZoomSDKAICompanionQueryHelper object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAICompanionQueryHelper*)getQueryHelper;

/**
 * @brief Whether the meeting supports turning off the AI Companion features.
 * @return YES if the meeting can support turning off the AI Companion features. Otherwise, NO.
 */
- (BOOL)isTurnoffAllAICompanionsSupported;

/**
 * @brief Whether the current user can turn off the AI Companion features.
 * @return YES if the user can turn off the AI Companion features. Otherwise, NO.
 */
- (BOOL)canTurnOffAllAICompanions;

/**
 * @brief Turn off the AI Companion features.
 * @param deleteMeetingAssets YES whether delete the meeting assets when turn off the AI Companion features, NO otherwise.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note All AI features including \link ZoomSDKAICompanionFeature \endlink can be turned off at once.
 */
- (ZoomSDKError)turnOffAllAICompanion:(BOOL)deleteMeetingAssets;

/**
 * @brief Whether the meeting supports turning on the AI Companion features.
 * @return YES if the meeting does support turn on the AI Companion features. Otherwise, NO.
 */
- (BOOL)isTurnOnAllAICompanionSupported;

/**
 * @brief Whether the current user can turn off the AI Companion features.
 * @return YES if the user can turn off the AI Companion features. Otherwise, NO.
 */
- (BOOL)canTurnOnAllAICompanion;

/**
 * @brief Turn on all the AI Companion features. Only \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_Query \endlink and \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartSummary \endlink  can be turned on at once.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnOnAllAICompanion;

/**
 * @brief Whether the current user can ask the  host to turn off all started AI Companion features.
 * @return YES if the user can request host to turn off the AI Companion features. Otherwise, NO.
 * @note if the current user joins the meeting before the host, they can check \link ZoomSDKMeetingAICompanionController::canTurnOffAllAICompanions \endlink to turn off the AI Companion features by himself or herself.
 * All AI features include \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_Query \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartSummary \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartRecording \endlink can be requested to turn off at once.
 */
- (BOOL)canRequestTurnoffAllAICompanion;

/**
 * @brief Request host to turn off all started AI Companion features.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note All AI features include \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_Query \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartSummary \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartRecording \endlink can be turned off at once.
 */
- (ZoomSDKError)requestTurnoffAllAICompanion;

/**
 * @brief Whether the current user can ask the host to turn on all AI Companion features if they are enabled for the current meeting.
 * @return YES if the user can ask the host to turn on the AI Companion features. Otherwise, NO.
 * @note Only \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_Query \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartSummary \endlink can be turned on at once.
 */
- (BOOL)canRequestTurnOnAllAICompanion;

/**
 * @brief Ask the host to turn on all AI Companion features if they are enabled for the current meeting.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note Only \link @c ZoomSDKAICompanionFeature:ZoomSDKAICompanionFeature#ZoomSDKAICompanionFeature_Query \endlink , \link @c ZoomSDKAICompanionFeature::ZoomSDKAICompanionFeature_SmartSummary \endlink can be turned on at once.
 */
- (ZoomSDKError)requestTurnOnAllAICompanion;
@end

NS_ASSUME_NONNULL_END
