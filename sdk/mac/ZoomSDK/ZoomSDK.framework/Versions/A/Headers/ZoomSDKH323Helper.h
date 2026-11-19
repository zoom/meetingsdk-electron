/**
 * @file ZoomSDKH323Helper.h
 * @brief Interfaces for managing H.323 devices and integration in a Zoom meeting.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN


/**
 * @class H323DeviceInfo
 * @brief Represents H.323 device information used in Zoom meetings.
 */
@interface H323DeviceInfo : NSObject
{
    NSString* _name;
    NSString* _ip;
    NSString* _e164num;
    H323DeviceType _type;
    EncryptType  _encryptType;
}
/**
 * @brief Gets or set the H.323 device‘s name.
 */
@property(nonatomic, retain, nullable)NSString* name;
/**
 * @brief Gets or set the H.323 device‘s IP address.
 */
@property(nonatomic, retain, nullable)NSString* ip;
/**
 * @brief Gets or set the E.164 number of the H.323 device.
 */
@property(nonatomic, retain, nullable)NSString* e164num;
/**
 * @brief Gets or set the H.323 device‘s type.
 */
@property(nonatomic, assign)H323DeviceType type;
/**
 * @brief Gets or set the encryption type used by the H.323 device.
 */
@property(nonatomic, assign)EncryptType encryptType;
@end


/**
 * @protocol ZoomSDKH323HelperDelegate
 * @brief Protocol for receiving H.323 related event callbacks.
 */
@protocol ZoomSDKH323HelperDelegate <NSObject>
@optional
/**
 * @brief Receives outgoing call status of H.323 device.
 * @param calloutStatus Notify user if the outgoing call status changes.
 */
- (void) onCalloutStatusReceived:(H323CalloutStatus)calloutStatus;

/**
 * @brief Callback event of H.323 device pairing meeting.
 * @param pairResult Notify user if the paring status changes.
 * @param meetingNum The meeting number of the meeting.
 */
- (void) onPairCodeResult:(H323PairingResult)pairResult MeetingNumber:(long long)meetingNum;
@end

/**
 * @class ZoomSDKH323Helper
 * @brief Provides helper APIs for H.323 device management in Zoom meetings.
 */
@interface ZoomSDKH323Helper : NSObject
{
    id<ZoomSDKH323HelperDelegate> _delegate;
}
/**
 * @brief Sets or get the delegate to receive H.323 related events.
 */
@property (assign, nonatomic, nullable) id<ZoomSDKH323HelperDelegate> delegate;
/**
 * @brief Gets the H.323 device address of the current meeting.
 * @return If the function succeeds, it returns the address. Otherwise, this function fails and returns nil.
 */
- (NSArray*)getH323DeviceAddress;

 /**
 * @brief Gets the H.323 device password of the current meeting.
 * @return If the function succeeds, it returns the password. Otherwise, this function fails and returns nil.
 */
- (NSString*)getH323Password;

/**
 * @brief Sends meeting paring code.
 * @param pairCode Pairing code of the specified meeting.
 * @param meetingNum Meeting number for pairing.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendMeetingPairingCode:(NSString*)pairCode meetingNum:(long long)meetingNum;

/**
 * @brief Calls out a H.323 device.
 * @param deviceInfo The information of H.323 device that you want to call out.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)calloutH323Device:(H323DeviceInfo*)deviceInfo;

/**
 * @brief Gets the list of H.323 devices for the current meeting.
 * @return If the function succeeds, it returns the list. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getRoomH323DeviceArray;

/**
 * @brief Cancels the latest operation of calling out H.323 device. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancelCallOutH323;

/**
 * @brief Invites others to meeting by default email.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inviteToMeetingByDefaultMail;

/**
 * @brief Invites others to meeting by gmail.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inviteToMeetingByGmail;

/**
 * @brief Invites others to meeting by Yahoo mail.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)inviteToMeetingByYahooMail;
@end
NS_ASSUME_NONNULL_END
