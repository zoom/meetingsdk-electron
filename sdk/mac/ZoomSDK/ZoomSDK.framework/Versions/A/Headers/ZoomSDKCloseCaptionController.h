/**
 * @file ZoomSDKCloseCaptionController.h
 * @brief Interface for managing closed caption and live transcription features in Zoom meetings.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKCCRequestHandler
 * @brief The helper to handle the requested of start captions.
 * @note When isRequestTranslationOn is YES, use \link ZoomSDKCCRequestTranslationOnHandler::approveStartCaptionsRequest \endlink to approve start captions request.
       When isRequestTranslationOn is NO, use \link ZoomSDKCCRequestTranslationOffHandler::approveStartCaptionsRequest: \endlink to approve start captions request.
 */
@interface ZoomSDKCCRequestHandler : NSObject
/**
 * @brief The user's user ID who send the start captions request.
 */
@property (nonatomic, assign, readonly) unsigned int senderUserID;

/**
 * @return YES if request to start captions with translation on. Otherwise, NO.
 */
@property (nonatomic, assign, readonly) BOOL isRequestTranslationOn;
/**
 * @brief Deny the request to start captions.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)deny;
@end


/**
 * @class ZoomSDKCCRequestTranslationOnHandler
 * @brief Subclass of ZoomSDKCCRequestHandler for requests with translation enabled.
 */
@interface ZoomSDKCCRequestTranslationOnHandler : ZoomSDKCCRequestHandler
/**
 * @brief Approve the start captions request.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)approveStartCaptionsRequest;
@end

/**
 * @class ZoomSDKCCRequestTranslationOffHandler
 * @brief Subclass of ZoomSDKCCRequestHandler for requests without translation.
 */
@interface ZoomSDKCCRequestTranslationOffHandler : ZoomSDKCCRequestHandler
/**
 * @brief Approve the start captions request.
 * @param languageID The language to be set for all participants in meeting.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)approveStartCaptionsRequest:(int)languageID;
@end

/**
 * @class ZoomSDKLiveTranscriptionMessageInfo
 * @brief Interface representing a live transcription message.
 */
@interface ZoomSDKLiveTranscriptionMessageInfo : NSObject
/**
 * @brief Gets the message ID of the current message.
 */
@property (nonatomic, copy, readonly, nullable) NSString *messageID;

/**
 * @brief Gets the speaker's ID.
 */
@property (nonatomic, assign, readonly) unsigned int speakerID;

/**
 * @brief Gets the speaker's name.
 */
@property (nonatomic, copy, readonly, nullable) NSString *speakerName;

/**
 * @brief Gets the current message's content.
 */
@property (nonatomic, copy, readonly, nullable) NSString *messageContent;

/**
 * @brief Gets the time stamp of the current message.
 */
@property (nonatomic, assign, readonly) time_t timeStamp;

/**
 * @brief Gets the current message's type.
 */
@property (nonatomic, assign, readonly) ZoomSDKLiveTranscriptionOperationType messageType;

@end


/**
 * @class ZoomSDKLiveTranscriptionLanguage
 * @brief Represents a language supported for live transcription.
 */
@interface ZoomSDKLiveTranscriptionLanguage : NSObject
/**
 * @brief The language ID.
 */
@property(nonatomic, assign, readonly) int languageID;
/**
 * @brief The language name.
 */
@property(nonatomic, copy, readonly, nullable) NSString* languageName;
@end


/**
 * @protocol ZoomSDKCloseCaptionControllerDelegate
 * @brief Delegate protocol to receive closed caption and live transcription related events.
 */
@protocol ZoomSDKCloseCaptionControllerDelegate <NSObject>
@optional

/**
 * @brief Callback of getting the privilege of close caption. 
 */
- (void)onGetCCPrivilege;

/**
 * @brief Callback of losing privilege of close caption. 
 */
- (void)onLostCCPrivilege;

/**
 * @brief Notify the current user that close caption is received.
 * @param inString The close caption message's content.
 * @param senderID The sender ID of a closed caption message.
 * @note If the meeting supports multi-language transcription and the host sets manual captions to YES, attendees must set the translation language ID to -1 to receive closed captioned messages.
 */
- (void)onReceiveCCMessageWithString:(NSString*)inString senderID:(unsigned int)senderID;

/**
 * @brief Notify the current user of realtime message.
 * @param realtimeMessage The message that is being input.
 */
- (void)onReceiveCCRealtimeMessage:(NSString *)realtimeMessage;

/**
 * @brief Notify the live transcription status changed.
 * @param status The type of live transcription status.
 * @note This callback is triggered when the live transcription status changes. It can be triggered by calling startLiveTranscription or by calling setTranslationLanguage: for the first time before calling startLiveTranscription.
 */
- (void)onLiveTranscriptionStatus:(ZoomSDKLiveTranscriptionStaus)status;

/**
 * @brief Callback: Invoked when a live transcription message is received.
 * @param messageInfo The live transcription message.
 */
- (void)onLiveTranscriptionMsgInfoReceived:(ZoomSDKLiveTranscriptionMessageInfo*_Nullable)messageInfo;

/**
 * @brief Callback: Original language message received callback.
 * @param messageInfo The spoken language message.
 */
- (void)onOriginalLanguageMsgReceived:(ZoomSDKLiveTranscriptionMessageInfo*_Nullable)messageInfo;

/**
 * @brief The translation message error callback.
 * @param spokenLanguage An object of the spoken message language.
 * @param transcriptLanguage An object of the message language you want to translate.
 */
- (void)onLiveTranscriptionMsgError:(ZoomSDKLiveTranscriptionLanguage*_Nullable)spokenLanguage transcriptLanguage:(ZoomSDKLiveTranscriptionLanguage*_Nullable)transcriptLanguage;

/**
 * @brief Notify the request for live transcript received.
 * @param requesterID The user ID of requester.
 * @param bAnonymous Request anonymously of not, if bAnonymous is YES, requesterID has no meanings, NO otherwise.
 * @note only host can retrieve this callback
 */
- (void)onRequestForLiveTranscriptReceived:(unsigned int)requesterID anonymous:(BOOL)bAnonymous;

/**
 * @brief Notify the request for live transcript status changed.
 * @param bEnabled YES if enabled, NO otherwise.
 */
- (void)onRequestLiveTranscriptionStatusChange:(BOOL)bEnabled;

/**
 * @brief Sink the event of captions enabled status changed.
 * @param enable YES if the host enables the captions, NO if the host disables the captions.
 */
- (void)onCaptionStatusChanged:(BOOL)enable;

/**
 * @brief Sink the event to start captions request.
 * @param handler The helper to handle the start captions request.
 */
- (void)onStartCaptionsRequestReceived:(ZoomSDKCCRequestHandler *)handler;

/**
 * @brief Sink the event to start captions request was approved.
 */
- (void)onStartCaptionsRequestApproved;

/**
 * @brief Sink the event of manual captions enablement status change.
 * @param bEnabled YES if the host enables manual captions, NO if the host disables them.
 */
- (void)onManualCaptionStatusChanged:(BOOL)bEnabled;

/**
 * @brief Callback when the spoken language is changed.
 * @param spokenLanguage A pointer to the current spoken language object.
 */
- (void)onSpokenLanguageChanged:(ZoomSDKLiveTranscriptionLanguage*_Nullable)spokenLanguage;
@end


/**
 * @class ZoomSDKCloseCaptionController
 * @brief Controller interface to manage closed captions and live transcription in meetings.
 */
@interface ZoomSDKCloseCaptionController : NSObject
{
    id<ZoomSDKCloseCaptionControllerDelegate> _delegate;
}

/**
 * @brief The delegate to receive closed caption events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKCloseCaptionControllerDelegate> delegate;

/**
 * @brief Query if Close Caption is supported in the current meeting.
 * @return YES if supported. Otherwise, NO.
 */
- (BOOL)isMeetingSupportCloseCaption;

/**
 * @brief Query if it is able to assign others to send Close Caption.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)canAssignOthersToSendCC;

/**
 * @brief Query if the specified user can be assigned to send close caption.
 * @param userID The ID of user who you want to assign to send close caption
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)canBeAssignedToSendCC:(unsigned int)userID;

/**
 * @brief Query if the current user can send Close Caption.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)canSendClosedCaption;

/**
 * @brief Query if user can save Close Caption.
 * @return YES if able. Otherwise, NO.
 */
- (BOOL)isCanSaveClosedCaption;

/**
 * @brief Query if the third party close caption server is available.
 * @return YES if available. Otherwise, NO.
 */
- (BOOL)is3rdPartCCServerAvailable;

/**
 * @brief Withdraws CC privilege from another user (host only).
 * @param userID The ID of user that you want to withdraw CC privilege.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)withdrawCCPrivilegeForUser:(unsigned int)userID;

/**
 * @brief Assigns CC privilege to another user (host only).
 * @param userID The ID of user whom you want to assign CC privilege to.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)assignCCPrivilegeTo:(unsigned int)userID;

/**
 * @brief Sends CC message.
 * @param ccString The content of CC.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)sendClosedCaptionMessage:(NSString*)ccString;

/**
 * @brief Saves CC.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)saveCCHistory;

/**
 * @brief Gets the path where the CC is saved.
 * @return If the function succeeds, it returns a NSString. Otherwise, this function fails and returns nil.
 */
- (NSString*)getClosedCaptionHistorySavedPath;

/**
 * @brief Gets the third party URL for inputting CC.
 * @param thirdPartyURL The third party service's URL.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getClosedCaptionUrlFor3rdParty:(NSString*_Nullable*_Nonnull)thirdPartyURL;

/**
 * @brief Determines whether the legal notice for Live transcript is available.
 * @return YES if the legal notice for Live transcript is available. Otherwise, NO.
 */
- (BOOL)isLiveTranscriptLegalNoticeAvailable;

/**
 * @brief Gets the CC legal notices prompt.
 * @return If the function succeeds, it returns the CC legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getLiveTranscriptLegalNoticesPrompt;

/**
 * @brief Gets the CC legal notices explained.
 * @return If the function succeeds, it returns the CC legal notices explained. Otherwise, this function fails and returns nil.
 */
- (NSString *)getLiveTranscriptLegalNoticesExplained;

/**
 * @brief Determines whether the live transcription feature is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isLiveTranscriptionFeatureEnabled;

/**
 * @brief Determines whether the multi-language transcription feature is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isMultiLanguageTranscriptionEnabled;

/**
 * @brief Determines whether the translated captions feature is enabled.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isTextLiveTranslationEnabled;

/**
 * @brief Query the status of live transcription.
 * @return The status of live transcription with type ZoomSDKLiveTranscriptionStaus.
 */
- (ZoomSDKLiveTranscriptionStaus)getLiveTranscriptionStatus;

/**
 * @brief Query if it is able to start live transcription.
 * @return ZoomSDKError_Success means able. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canStartLiveTranscription;

/**
 * @brief Starts live transcription.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the meeting allows multi- language transcription, all users can start live transcription. Otherwise, only the host can start it.
 */
- (ZoomSDKError)startLiveTranscription;

/**
 * @brief Stops live transcription.
 * @return If the function succeeds,  it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the meeting allows multi- language transcription, all users can stop live transcription. Otherwise only the host can stop it.
*/
- (ZoomSDKError)stopLiveTranscription;

/**
 * @brief Enables or disable the ability for attendees to request live transcriptions.
 * @param bEnable YES to enable, NO otherwise.
 * @return If the function succeeds,  it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the meeting allows multi- language transcription, it returns ZoomSDKError_WrongUsage.
 */
- (ZoomSDKError)enableRequestLiveTranscription:(BOOL)bEnable;

/**
 * @brief Determines whether the request to start live transcription is enabled.
 * @return @c ZoomSDKError_Success  means enabled. Otherwise, this function returns an error.
 * @note If the meeting allows multi-language transcription, it returns ZoomSDKError_WrongUsage.
 */
- (ZoomSDKError)isRequestToStartLiveTranscriptionEnabled;

/**
 * @brief Request the host to start ive transcription.
 * @param bAnonymous YES indicates the user anonymous request, NO otherwise.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If the meeting allows multi-language transcription, it returns ZoomSDKError_WrongUsage.
 */
- (ZoomSDKError)requestToStartLiveTranscription:(BOOL)bAnonymous;

/**
 * @brief Enables or disable manual captions for the meeting.
 * @param bEnable YES to enable, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableMeetingManualCaption:(BOOL)bEnable;

/**
 * @brief Determines whether manually added closed captions are enabled for the meeting.
 * @return YES if enabled. Otherwise, NO.
 */
- (BOOL)isMeetingManualCaptionEnabled;

/**
 * @brief Gets the list of all available spoken languages in a meeting.
 * @return If the function succeeds, it returns an array contains the available spoken languages in a meeting. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKLiveTranscriptionLanguage*>*)getAvailableMeetingSpokenLanguages;

/**
 * @brief Sets the spoken language.
 * @param languageID The spoken language ID.
 * @param isForAll YES to set spoken language for all users, NO to set the language only for myself.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setMeetingSpokenLanguage:(int)languageID isForAll:(BOOL)isForAll;

/**
 * @brief Gets the current user's spoken language.
 * @return If the function succeeds, it will an object of ZoomSDKLiveTranscriptionLanguage. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKLiveTranscriptionLanguage*)getMeetingSpokenLanguage;

/**
 * @brief Gets the list of all available translation languages in a meeting.
 * @return If the function succeeds, it returns an array contains all available translation languages in a meeting. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKLiveTranscriptionLanguage*>*)getAvailableTranslationLanguages;

/**
 * @brief Sets the current user's translation language.
 * @param languageID The translation language ID. If the language ID is set to -1, live translation will be disabled. You can receive closed captions if the host sets manual captions to YES for the meeting, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 * @note If you call this method before calling startLiveTranscription, it will trigger the onLiveTranscriptionStatus: callback when the translation status changes. If translation is already enabled, calling this method again will not trigger the onLiveTranscriptionStatus: callback.
 */
- (ZoomSDKError)setTranslationLanguage:(int)languageID;

/**
 * @brief Gets the current user's translation language.
 * @return If the function succeeds, it will an object of ZoomSDKLiveTranscriptionLanguage. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKLiveTranscriptionLanguage*)getTranslationLanguage;

/**
 * @brief Enables or disable to receive original and translated content.If enable this feature,you need start live transcription.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableReceiveSpokenLanguageContent:(BOOL)enable;

/**
 * @brief Determines whether receive original and translated is available.
 * @return YES if receive original and translated is available. Otherwise, NO.
 */
- (BOOL)isReceiveSpokenLanguageContentEnabled;

/**
 * @brief Query if the user can disable captions.
 * @return YES if the host can disable captions. Otherwise, NO.
 */
- (BOOL)canDisableCaptions;

/**
 * @brief Enables or disable captions.
 * @param enable YES if captions are enabled, NO if captions are disabled.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableCaptions:(BOOL)enable;

/**
 * @brief Query if the captions enabled.
 * @return YES if captions are enabled. Otherwise, NO.
 */
- (BOOL)isCaptionsEnabled;

/**
 * @brief Determines whether users can request to start captions.
 * @return YES if users can request to start captions. Otherwise, NO.
 */
- (BOOL)isSupportRequestCaptions;

/**
 * @brief Determines whether support translation when users request to start captions.
 * @return YES if translation is available when users request to start captions. Otherwise, NO.
 */
- (BOOL)isSupportTranslationWhenRequestToStartCaptions;

/**
 * @brief Request the host to start captions. If the host approves your request, you receive the callback \link ZoomSDKCloseCaptionControllerDelegate::onStartCaptionsRequestApproved \endlink, and you should start captions or translation there.
 * @param enableTranslation YES indicates to enable translation at the same time, NO to disable.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestToStartCaptions:(BOOL)enableTranslation;
@end
NS_ASSUME_NONNULL_END
