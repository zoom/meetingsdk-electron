/**
 * @file ZoomSDKRealNameAuthentication.h
 * @brief Interface for Zoom SDK Real Name Authentication module.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

/**
 * @brief Enumeration of SMS verification code error.
 */
typedef enum
{
    /** Unknown error */
    ZoomSDKSMSError_Unknown,
    /** Operation success */
    ZoomSDKSMSError_Success,
    /** Failed to send SMS */
    ZoomSDKSMSError_Retrieve_SendSMSFailed,
    /** Invalid phone number */
    ZoomSDKSMSError_Retrieve_InvalidPhoneNum,
    /** Phone number already bound */
    ZoomSDKSMSError_Retrieve_PhoneNumAlreadyBound,
    /** SMS sending too frequent */
    ZoomSDKSMSError_Retrieve_PhoneNumSendTooFrequent,
    /** Verification code incorrect */
    ZoomSDKSMSError_Verify_CodeIncorrect,
    /** Verification code expired */
    ZoomSDKSMSError_Verify_CodeExpired,
    /** Unknown verification error */
    ZoomSDKSMSError_Verify_UnknownError,
}ZoomSDKSMSVerificationCodeError;

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKRetrieveSMSVerificationCodeController
 * @brief Controller for sending SMS verification code.
 */
@interface ZoomSDKRetrieveSMSVerificationCodeController : NSObject

/**
 * @brief Sends message to mobile phone.
 * @param code International area code for mobile phone number.
 * @param phoneNumber User phone number.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)retrieveWithCountryCode:(NSString *)code PhoneNum:(NSString *)phoneNumber;

/**
 * @brief Cancels and leave meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancelAndLeaveMeeting;
@end


/**
 * @class ZoomSDKVerifySMSVerificationCodeController
 * @brief Controller for verifying SMS verification code.
 */
@interface ZoomSDKVerifySMSVerificationCodeController : NSObject

/**
 * @brief Verifies SMS verification code.
 * @param countryCode International area code for mobile phone number.
 * @param number User phone number.
 * @param code The SMS verification code.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)verifyWithCountryCode:(NSString *)countryCode  withPhoneNumber:(NSString *)number  withCode:(NSString *)code;

/**
 * @brief Cancels and leave meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancelAndLeaveMeeting;
@end


/**
 * @class ZoomSDKRealNameAuthCountryInfo
 * @brief Model class to represent real-name authentication country info.
 */
@interface ZoomSDKRealNameAuthCountryInfo : NSObject
/**
 * @brief Gets the country ID of mobile phone number.
 * @return If the function succeeds, it returns the mobile phone number country ID. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getCountryID;

/**
 * @brief Gets the country Name of mobile phone number.
 * @return If the function succeeds, it returns the mobile phone number country Name. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getCountryName;

/**
 * @brief Gets the country code of mobile phone number.
 * @return If the function succeeds, it returns the mobile phone number country code. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getCountryCode;
@end


/**
 * @protocol ZoomSDKRealNameAuthenticationDelegate
 * @brief Delegate to receive real-name authentication events.
 */
@protocol ZoomSDKRealNameAuthenticationDelegate <NSObject>

/**
 * @brief Notify support the Real-name authentication
 * @param supportCountryList The sdk support country list.
 * @param privacyURL The privacy url about Real-name authentication meeting
 * @param handler Object of ZoomSDKRetrieveSMSVerificationCodeController.
 */
- (void)onNeedRealNameAuthMeetingWithSupportCountryList:(NSArray *_Nullable)supportCountryList  withPrivacyURL:(NSString *)privacyURL withRetrieveSMSVerificationCodeHandler:(ZoomSDKRetrieveSMSVerificationCodeController *)handler;

/**
 * @brief Notify the send MSM verification code result
 * @param result The MSM send is success or not.
 * @param handler The handle work only when the result is ZoomSDKSMSError_Success.
 */
- (void)onRetrieveSMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)result  withVerifySMSVerificationCodeHandle:(ZoomSDKVerifySMSVerificationCodeController *_Nullable)handler;

/**
 * @brief Notify the MSM verification code verify result.
 * @param result The SMS verification code is correct or not.
 */
- (void)onVerifySMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)result;
@end



/**
 * @class ZoomSDKRealNameAuthenticationController
 * @brief Controller to manage Zoom SDK Real Name Authentication.
 */
@interface ZoomSDKRealNameAuthenticationController : NSObject
{
    id<ZoomSDKRealNameAuthenticationDelegate> _delegate;
}
/**
 * @brief Delegate to receive authentication events.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKRealNameAuthenticationDelegate>  delegate;

/**
 * @brief Enables to show the zoom Real-name authentication meeting UI
 * @param enable Yes means show the zoom Real-name authentication meeting UI, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableZoomAuthRealNameMeetingUIShown:(BOOL)enable;

/**
 * @brief Gets the country for mobile phone number supported by the SDK.
 * @return If the function succeeds, will get the support country list. Otherwise, this function fails and returns nil.
 */
- (NSArray *)getSupportPhoneNumberCountryList;

/**
 * @brief  Gets the resend Verification Code Controller.
 * @return If the function succeeds, it returns an object of ZoomSDKRetrieveSMSVerificationCodeController. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKRetrieveSMSVerificationCodeController *)resendSMSVerificationCodeController;

/**
 * @brief  Gets the reVerify Code Controller.
 * @return If the function succeeds, it returns an object of ZoomSDKVerifySMSVerificationCodeController. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKVerifySMSVerificationCodeController *)reVerifySMSVerificationCodeController;

/**
 * @brief  Sets the default cell phone information.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setDefaultCellPhoneInfo:(NSString*)countryCode phoneNumber:(NSString*)phoneNumber;
@end
NS_ASSUME_NONNULL_END
