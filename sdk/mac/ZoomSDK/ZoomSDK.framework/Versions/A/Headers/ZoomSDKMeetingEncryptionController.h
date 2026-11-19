/**
 * @file ZoomSDKMeetingEncryptionController.h
 * @brief Zoom SDK meeting encryption controller interface.
 *
 * This file defines the @c ZoomSDKMeetingEncryptionController interface and related protocols
 * for managing meeting encryption, including E2EE (end-to-end encryption), enhanced encryption,
 * and related security codes.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @brief Enumeration of meeting encryption type.
 * For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0065408#h_43255143224251715800543133>.
 */
typedef enum
{
    /** No encryption. */
    ZoomSDKEncryptionType_None,
    /** Enhanced encryption. */
    ZoomSDKEncryptionType_Enhanced,
    /** End-to-end encryption (E2EE). */
    ZoomSDKEncryptionType_E2EE
}ZoomSDKEncryptionType;

/**
 * @protocol ZoomSDKMeetingEncryptionDelegate
 * @brief Callback events for meeting encryption status.
 */
@protocol ZoomSDKMeetingEncryptionDelegate <NSObject>
/**
 * @brief This callback is called when the security code changes.
 */
- (void)onE2EEMeetingSecurityCodeChanged;
@end

/**
 * @class ZoomSDKMeetingEncryptionController
 * @brief Zoom SDK meeting encryption controller.
 */
@interface ZoomSDKMeetingEncryptionController : NSObject

/**
 * @brief The delegate object to receive encryption events.
 */
@property(nonatomic,assign, nullable) id<ZoomSDKMeetingEncryptionDelegate> delegate;

/**
 * @brief Gets meeting encryption type.
 * @return The encryption type.
 */
- (ZoomSDKEncryptionType)getEncryptionType;

/**
 * @brief Gets E2EE meeting security code.
 * @return If the function succeeds, it returns 40-digit security code. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getE2EEMeetingSecurityCode;

/**
 * @brief Gets security code passed seconds.
 * @return If the function succeeds, it returns the time the security code exists, in seconds. Otherwise, this function returns an error.
 */
- (unsigned int)getE2EEMeetingSecurityCodePassedSeconds;

/**
 * @brief Determines whether unencrypted exception data is valid,
 * @return YES if unencrypted exception data is valid. Otherwise, NO.
 * @note This method can only be called when the encryption type is ZoomSDKEncryptionType_Enhanced.
 */
- (BOOL)isUnencryptedExceptionDataValid;

/**
 * @brief Gets unencrypted exception count.
 * @return If the function succeeds, it returns the unencrypted exception count. Otherwise, this function returns an error.
 */
- (unsigned int)getUnencryptedExceptionCount;

/**
 * @brief Gets unencrypted exception info.
 * @return If the function succeeds, it returns unencrypted exception details. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getUnencryptedExceptionInfo;
@end
NS_ASSUME_NONNULL_END
