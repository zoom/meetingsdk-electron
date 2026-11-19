/**
 * @file ZoomSDKReminderController.h
 * @brief Interfaces for managing meeting reminder notifications in Zoom SDK.
 * The AI Companion brand has been retired. AI-powered features are now more deeply integrated throughout Zoom Workplace. Existing APIs and SDKs that reference AI Companion will continue to function as before to ensure backward compatibility.
 */


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKReminderContent
 * @brief Represents the content of a reminder dialog.
 */
@interface ZoomSDKReminderContent : NSObject
/**
 * @brief Gets the reminder’s type.
 */
@property(nonatomic,assign,readonly)ZoomSDKReminderType type;
/**
 * @brief Gets the reminder dialog content’s title.
 */
@property(nonatomic,copy,readonly,nullable)NSString *title;
/**
 * @brief Gets the reminder's detail content dialog content.
 */
@property(nonatomic,copy,readonly,nullable)NSString *content;
/**
 * @brief Whether to block the user from joining or staying in the meeting.
 */
@property(nonatomic,assign,readonly)BOOL isBlocking;
/**
 * @brief Gets the action's type which user should take after receiving this reminder content.
 */
@property(nonatomic,assign,readonly)ZoomSDKReminderActionType actionType;
/**
 * @brief Gets a list of reminder’s type.
 */
@property(nonatomic,copy,readonly)NSArray *multiReminderTypes;
@end


/**
 * @class ZoomSDKReminderHandler
 * @brief Provides the interface to respond to a reminder dialog.
 */
@interface ZoomSDKReminderHandler : NSObject
/**
 * @brief Accept the reminder.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)accept;
/**
 * @brief Declined the reminder.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline;
/**
 * @brief Ignore the reminder.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)ignore;
/**
 * @brief Sets not show the disclaimer in subsequent meetings.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setHideFeatureDisclaimers;

/**
 * @brief Is need explicit consent for AI custom disclaimer. Only valid for  @c ZoomSDKReminderType_CustomAICompanionDisclaimer.
 * @return YES if explicit consent is required (before agreeing to AIC disclaimer, the video and audio will be blocked). Otherwise, NO (explicit consent is not required and video and audio will not be blocked).
 */
- (BOOL)isNeedExplicitConsent4AICustomDisclaimer;
@end


/**
 * @class ZoomSDKMeetingEnableReminderHandler
 * @brief Handles reminders related to enabling smart features (e.g., smart recording).
 */
@interface ZoomSDKMeetingEnableReminderHandler : NSObject

/**
 * @brief Sets the option indicating which meetings smart recording is enabled for.
 * @param option Specify the option.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setEnableOption:(ZoomSDKMeetingFeatureEnableOption)option;

/**
 * @brief Starts the smart recording.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)start;

/**
 * @brief Decline the reminder.
 * @param declineAll YES to decline all reminders, and participants cannot send requests again until the host changes the setting, NO to decline only this specific request, not all requests.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)decline:(BOOL)declineAll;

/**
 * @brief Ignore the reminder.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)ignore;

@end


/**
 * @protocol ZoomSDKReminderControllerDelegate
 * @brief Callback interface for receiving reminder dialog notifications.
 */
@protocol ZoomSDKReminderControllerDelegate <NSObject>
/**
 * @brief Callback event when the reminder dialog displays.
 * @param handle The helper to handle the reminder dialog.
 * @param content The detail content in the reminder dialog.
 */
- (void)onReminderNotify:(ZoomSDKReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content;

/**
 * @brief Callback event to enable showing the reminder dialog.
 * @param handle A pointer to the ZoomSDKMeetingEnableReminderHandler.
 * @param content The detail content in the reminder dialog.
 */
- (void)onEnableReminderNotify:(ZoomSDKMeetingEnableReminderHandler*)handle reminderContent:(ZoomSDKReminderContent*)content;

@end


/**
 * @class ZoomSDKCustomMultiReminderUIConfigItem
 * @brief UI configuration for a single type of reminder popup.
 */
@interface ZoomSDKCustomMultiReminderUIConfigItem : NSObject
/**
 * @brief Sets the customized center point position for multiple reminder pop-ups. You can modify the alert's position by calling setMultiReminderDisclaimerUIConfig when the alert is displayed. If the center you set is not enough for display, it is automatically corrected.
 */
@property(nonatomic,assign) NSPoint center;

/**
 * @brief Sets the customized backgroundColor for multiple reminder pop-ups.
 */
@property(nonatomic,retain, nullable) NSColor *backgroundColor;
@end


/**
 * @class ZoomSDKCustomMultiReminderUIConfig
 * @brief Configuration for customizing multiple reminder popups.
 */
@interface ZoomSDKCustomMultiReminderUIConfig : NSObject
/**
 * @brief Sets the customized config for multiple reminder alert pop-ups.
 */
@property(nonatomic,retain, nullable) ZoomSDKCustomMultiReminderUIConfigItem *alertConfig;

/**
 * @brief Sets the customized config for multiple reminder banner pop-ups.
 */
@property(nonatomic,retain ,nullable) ZoomSDKCustomMultiReminderUIConfigItem *bannerConfig;
@end


/**
 * @class ZoomSDKReminderController
 * @brief Controller for managing reminder-related behavior and UI customization.
 */
@interface ZoomSDKReminderController : NSObject
/**
 * @brief Delegate for receiving reminder-related callbacks.
 */
@property(nonatomic,assign, nullable) id<ZoomSDKReminderControllerDelegate> delegate;

/**
 * @brief Sets the customized config for multiple reminder pop-ups.
 * @param config The config object.
 * @return If the function succeeds, it returns ZoomSDKError_success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setMultiReminderDisclaimerUIConfig:(ZoomSDKCustomMultiReminderUIConfig *_Nullable)config;
@end
NS_ASSUME_NONNULL_END
