/**
 * @file ZoomSDKReactionController.h
 * @brief Interfaces for managing emoji reactions and feedback in Zoom SDK.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @protocol ZoomSDKReactionControllerDelegate
 * @brief Delegate protocol for receiving emoji reaction and feedback events.
 */
@protocol ZoomSDKReactionControllerDelegate <NSObject>

/**
 * @brief Notify receive the emoji reaction.
 * @param userid The user ID of the send emoji reaction.
 * @param type The send emoji reaction type.
 * @param skinTone The send emoji reaction skinstone.
 */
- (void)onEmojiReactionReceived:(unsigned int)userid reactionType:(ZoomSDKEmojiReactionType)type reactionSkinTone:(ZoomSDKEmojiReactionSkinTone)skinTone;

/**
 * @brief Emoji reaction callback. This callback notifies the user when an emoji is received in the webinar.
 * @param type Specify the received reaction's type.
 */
- (void)onEmojiReactionReceivedInWebinar:(ZoomSDKEmojiReactionType)type;

/**
 * @brief Emoji feedback received callback. Informs the user once the emoji feedback sent by others or user himself is received.
 * @param userid Specify the user ID of the emoji feedback sender.
 * @param type Specify the received emoji feedback's type.
 */
- (void)onEmojiFeedbackReceived:(unsigned int)userid emojiFeedbackType:(ZoomSDKEmojiFeedbackType)type;

/**
 * @brief Emoji feedback canceled callback. Informs the user once the received emoji feedback sent by others or user himself was canceled.
 * @param userid Specify the user ID of the emoji feedback sender.
 */
- (void)onEmojiFeedbackCanceled:(unsigned int)userid;

@end


/**
 * @class ZoomSDKReactionController
 * @brief Interface for managing emoji reactions and emoji feedback in Zoom SDK.
 */
@interface ZoomSDKReactionController : NSObject
{
    id<ZoomSDKReactionControllerDelegate> _delegate;
}
/**
 * @brief Sets or get the delegate to receive emoji reaction and feedback events.
 */
@property (assign, nonatomic, nullable) id<ZoomSDKReactionControllerDelegate> delegate;

/**
 * @brief Determines if the Reaction function is enabled.
 * @return YES if Reaction function is enable. Otherwise, NO.
 */
- (BOOL)isEmojiReactionEnabled;

/**
 * @brief Sends emoji reaction.
 * @param type The emoji reaction's type.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendEmojiReaction:(ZoomSDKEmojiReactionType)type;

/**
 * @brief Sets emoji reaction display type in webinar.
 * @param type The display type of the emoji reaction.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setWebinarEmojiReactionDisplayType:(ZoomSDKEmojiReactionDisplayType)type;

/**
 * @brief Gets emoji reaction display type in webinar.
 * @return If the function succeeds, it returns the display type of the emoji reaction. Otherwise, the function returns ZoomSDKEmojiReactionDisplayType_None.
 */
- (ZoomSDKEmojiReactionDisplayType)getWebinarEmojiReactionDisplayType;

/**
 * @brief Sends the emoji feedback.
 * @param type Specify the emoji feedback type to be sent.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendEmojiFeedback:(ZoomSDKEmojiFeedbackType)type;

/**
 * @brief Cancels the emoji feedback.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cancelEmojiFeedback;

@end

NS_ASSUME_NONNULL_END
