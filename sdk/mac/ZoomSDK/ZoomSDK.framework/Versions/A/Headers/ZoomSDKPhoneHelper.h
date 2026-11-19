/**
 * @file ZoomSDKPhoneHelper.h
 * @brief Interface for Zoom SDK phone helper to manage telephone call-out, call-in and related features.
 */

#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

/**
 * @protocol ZoomSDKPhoneHelperDelegate
 * @brief Delegate protocol to receive phone call-out and call-me status updates.
 */
@protocol ZoomSDKPhoneHelperDelegate <NSObject>
/**
 * @brief Invite others by telephone call-out and send the response to the application according to the others’ status.
 * @param status The telephone’s status.
 * @param reason The reason for the failure if the status value is PhoneStatus_Failed.
 */
- (void)onInviteCalloutUserStatus:(PhoneStatus)status FailedReason:(PhoneFailedReason)reason;

/**
 * @brief Invite others to join the meeting by CALL ME and give the response to the application according to the status.
 * @param status The telephone’s status.
 * @param reason The reason for the failure if the status value is PhoneStatus_Failed.
 */
- (void)onCallMeStatus:(PhoneStatus)status FailedReason:(PhoneFailedReason)reason;
@end


/**
 * @class ZoomSDKPhoneSupportCountryInfo
 * @brief Provides information of countries that support calling out.
 */
@interface ZoomSDKPhoneSupportCountryInfo : NSObject
/**
 * @brief Gets the country's ID where a user can dial in.
 * @return If the function succeeds, it returns the country ID. (e.g. US, CA, etc.). Otherwise, this function fails and returns nil.
 */
- (NSString*)getCountryID;
/**
 * @brief Gets the country name.
 * @return If the function succeeds, it returns the country name. Otherwise, this function fails and returns nil.
 */
- (NSString*)getCountryName;
/**
 * @brief Gets the country code.
 * @return If the function succeeds, it returns the country code. (e.g. +1, +33, etc.). Otherwise, this function fails and returns nil.
 */
- (NSString*)getCountryCode;
@end


/**
 * @class ZoomSDKCallInPhoneNumInfo
 * @brief Represents call-in phone number information.
 */
@interface ZoomSDKCallInPhoneNumInfo : NSObject
/**
 * @brief Gets the current call-in number’s country ID.
 * @return If the function succeeds, it returns the country ID. Otherwise, this function fails and returns nil.
 */
- (NSString*) getID;
/**
 * @brief Gets the current call-in number’s country code.
 * @return If the function succeeds, it returns the country code. Otherwise, this function fails and returns nil.
 */
- (NSString*) getCode;
/**
 * @brief Gets the current call-in number’s country name.
 * @return If the function succeeds, it returns the country name. Otherwise, this function fails and returns nil.
 */
- (NSString*) getName;
/** 
 * @brief Gets the current call-in number’s telephone number.
 * @return If the function succeeds, it returns the telephone number. Otherwise, this function fails and returns nil.
 */
- (NSString*) getNumber;
/**
 * @brief Gets the current call-in number’s display number.
 * @return If the function succeeds, it returns the display number. Otherwise, this function fails and returns nil.
 */
- (NSString*) getDisplayNumber;
/**
 * @brief Gets the call-in number’s call type.
 * @return Call type.
 */
- (CallInNumberType) getType;
@end


/**
 * @class ZoomSDKPhoneHelper
 * @brief Provides APIs to manage Zoom phone call-in and call-out features.
 */
@interface ZoomSDKPhoneHelper : NSObject
{
    id<ZoomSDKPhoneHelperDelegate> _delegate;
    PhoneStatus _callMeStatus;
}
/**
 * @brief Sets the delegate to receive phone call status updates.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKPhoneHelperDelegate> delegate;
/**
 * @brief Query if current meeting support telephony.
 * @return YES if support. Otherwise, NO.
 */
- (BOOL)isSupportPhone;

/**
 * @brief Query if it is able to dial out in the current meeting.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isDialoutSupported;

/**
 * @brief Query if any phone dial-out action is in progress in the current meeting.
 * @return YES if a phone dial-out is in progress. Otherwise, NO.
 */
- (BOOL)isDialoutInProgress;

/**
 * @brief Gets the countries's list which support calling out.
 * @return An NSArray contains ZoomSDKPhoneSupportCountryInfoList objects of all countries supporting to call out. Otherwise, this function fails and returns nil.
 */
- (NSArray*)getSupportCountryInfo;

/**
 * @brief Gets the selected caller ID for phone call-out.
 * @return If the function succeeds, it returns the caller ID. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getCallOutCallerID;

/**
 * @brief Invite the specified user to join the meeting by calling out.
 * @param userName The specified user’s in-meeting screen name.
 * @param number The specified user’s phone number.
 * @param countryCode The specified user’s country code must be in the support list.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error. 
 */
- (ZoomSDKError)inviteCalloutUser:(NSString*)userName PhoneNumber:(NSString*)number CountryCode:(NSString*)countryCode;

/**
 * @brief Cancels the invitation that is being called out by phone.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancelCalloutUser;

/**
 * @brief  Gets the invited user's status by calling out.
 * @return The current callout process.
 */
- (PhoneStatus)getInviteCalloutUserStatus;

/**
 * @brief Invite myself to join audio to the meeting by phone. 
 * @param number The device’s phone number.
 * @param countryCode The country code.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)callMe:(NSString*)number CountryCode:(NSString*)countryCode;

/**
 * @brief Cancels the current CALL ME action.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)hangUp;

/**
 * @brief Gets the status of myself by CALL ME.
 * @return The invitation's process by CALL ME.
 */
- (PhoneStatus)getCallMeStatus;

/**
 * @brief Gets the participant's ID who joins the meeting by calling in.
 * @return If the function succeeds, it returns the ID of participant. Otherwise, returns 0.
 */
- (unsigned int)getCallInParticipantID;

/**
* @brief Gets the list of call-in numbers supported by the meeting.
* @return If the function succeeds, it returns an array of ZoomSDKCallInPhoneNumInfo objects. Otherwise, this function fails and returns nil.
*/
- (NSArray*_Nullable)getCallInNumberInfo;

@end
NS_ASSUME_NONNULL_END
