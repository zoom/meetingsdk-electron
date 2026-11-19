/**
 * @file ZoomSDKSignInterpretationController.h
 * @brief Interfaces for managing sign language interpretation in Zoom meetings.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKSignInterpretationLanguageInfo
 * @brief Information of a supported sign interpretation language.
 */
@interface ZoomSDKSignInterpretationLanguageInfo : NSObject
/**
 * @brief Gets the sign language ID.
 */
@property (copy,nonatomic,readonly,nullable) NSString *signLanguageID;
/**
 * @brief Gets the sign language name.
 */
@property (copy,nonatomic,readonly,nullable) NSString *signLanguageName;
@end

/**
 * @class ZoomSDKSignInterpreter
 * @brief Represent a sign language interpreter user and their assigned language.
 */
@interface ZoomSDKSignInterpreter : NSObject
/**
 * @brief Gets the user ID of the sign interpreter.
 */
@property (assign,nonatomic,readonly) unsigned int userID;
/**
 * @brief Gets the language ID supported by the sign interpreter.
 */
@property (copy,nonatomic,readonly,nullable) NSString *signLanguageID;
/**
 * @brief Determines if the interpreter is currently available in the meeting.
 * @return YES if available. Otherwise, NO.
 */
@property (assign,nonatomic,readonly) BOOL isAvailable;
@end


/**
 * @protocol ZoomSDKSignInterpretationControllerDelegate
 * @brief Delegate callbacks for sign language interpretation events.
 */
@protocol ZoomSDKSignInterpretationControllerDelegate <NSObject>
@optional

/**
 * @brief Sign interpretation staus change callback. Informs the user that sign interpretation has been started or stopped, and all users in the meeting can get the event.
 * @param status Specify current sign interpretation status.
 */
- (void)onSignInterpretationStatusChanged:(ZoomSDKSignInterpretationStatus)status;

/**
 * @brief Sign interpreter list changed callback. When an interpreter leaves the meeting, preset interpreter joins the meeting, or the host adds or removes an interpreter, this triggers.
 * @note Only the host will receive this event.
 */
- (void)onSignInterpreterListChanged;

/**
 * @brief Interpreters role changed callback. when myself role changed(participant <-> interpreter), and only myself in meeting can get the event.
 */
- (void)onSignInterpreterRoleChanged;

/**
 * @brief Sign interpreter languages changed callback. when a sign interpreter's languages changed
 * @note Only the sign interpreter self can get the event.
 */
- (void)onSignInterpreterLanguageChanged;

/**
 * @brief Available sign languages changed callback. When the available sign languages in a meeting change, all users in the meeting can get the event.
 * @param availableSignLanguageList List the available sign languages.
 */
- (void)onAvailableSignLanguageListUpdated:(NSArray<ZoomSDKSignInterpretationLanguageInfo *> *_Nullable)availableSignLanguageList;

/**
 * @brief Callback event of the requirement to unmute the audio.
 */
- (void)onRequestSignInterpreterToTalk;

/**
 * @brief Callback event for the user talk privilege changed. When the interpreter role changed, host changed, host allow or disallow interpreter talk, this triggers.
 * @param hasPrivilege Specify whether the user has talk privilege or not.
 * @note Only the sign interpreter itself can receives the event.
 */
- (void)onTalkPrivilegeChanged:(BOOL)hasPrivilege;
@end

/**
 * @class ZoomSDKSignInterpretationController
 * @brief Manage sign interpretation status, interpreters, and available languages in a Zoom meeting.
 */
@interface ZoomSDKSignInterpretationController : NSObject
/**
 * @brief Delegate for receiving sign interpretation events.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKSignInterpretationControllerDelegate>  delegate;

/**
 * @brief Determines if the sign interpretation function is enabled.
 * @return YES if sign interpretation function is enabled. Otherwise, NO.
 */
- (BOOL)isSignInterpretationEnabled;

/**
 * @brief Gets the sign interpretation status of current meeting.
 * @return The current meeting's sign interpretation status.
 */
- (ZoomSDKSignInterpretationStatus)getSignInterpretationStatus;

/**
 * @brief Determines if myself is interpreter.
 * @return YES if self is sign language interpreter. Otherwise, NO.
 */
- (BOOL)isSignInterpreter;

/**
 * @brief Gets the sign language object of the specified sign language ID.
 * @param signLanguageID Specify the sign language ID for which you want to get the information.
 * @return If the function succeeds, it returns ZoomSDKSignInterpretationLanguageInfo object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKSignInterpretationLanguageInfo *)getSignInterpretationLanguageInfoByID:(NSString *)signLanguageID;

/**
 * @brief Gets the available sign interpretation language list.
 * @return If the function succeeds, the return array contain available language object. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKSignInterpretationLanguageInfo *> *)getAvailableSignLanguageInfoList;

/**
 * @brief Gets all supported sign interpretation language list.
 * @return If the function succeeds, the return array contain support language object. Otherwise, this function fails and returns nil.
 * @note Only available for host.
 */
- (NSArray<ZoomSDKSignInterpretationLanguageInfo *> *_Nullable)getAllSupportedSignLanguageInfoList;

/**
 * @brief Gets the sign interpreters list.
 * @return If the function succeeds, the return array contain sign interpreter object. Otherwise, this function fails and returns nil.
 */
- (NSArray<ZoomSDKSignInterpreter *> *_Nullable)getSignInterpreterList;

/**
 * @brief Adds someone as a sign interpreter.
 * @param userID The user’s ID.
 * @param signLanguageId The sign language ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addSignInterpreter:(unsigned int)userID signLanguageId:(NSString *)signLanguageId;

/**
 * @brief Removes someone from the list of sign interpreters.
 * @param userID Specify the user.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeSignInterpreter:(unsigned int)userID;

/**
 * @brief Modify the language of some sign interpreter.
 * @param userID The user's unique identity.
 * @param signLanguageId The ID of sign language.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)modifySignInterpreter:(unsigned int)userID signLanguageId:(NSString *)signLanguageId;

/**
 * @brief Determines if I can start the sign interpretation in the meeting.
 */
- (BOOL)canStartSignInterpretation;

/**
 * @brief Starts sign interpretation.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startSignInterpretation;

/**
 * @brief Stops sign interppretation.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)stopSignInterpretation;

/**
 * @brief Host allow or disallow sign language interpreter to talk.
 * @param userID The interpreter's user ID.
 * @param allowToTalk YES indicates allow to talk, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)requestSignLanguageInterpreterToTalk:(unsigned int)userID allowToTalk:(BOOL)allowToTalk;

/**
 * @brief Determines if the sign language interpreter be allowed to talk.
 * @param userID The user's unique identity.
 * @return YES if allow to talk. Otherwise, NO.
 */
- (BOOL)canSignLanguageInterpreterTalk:(unsigned int)userID;

/**
 * @brief Gets sign language ID if myself is a sign interpreter. Only for interpreter.
 * @return If the function succeeds, it returns the current assigned sign language ID. Otherwise, this function fails and returns nil.
 */
- (NSString *_Nullable)getSignInterpreterAssignedLanID;

/**
 * @brief Join a sign language channel if myself is not a sign interpreter.
 * @param signLanguageId Specify the sign language channel ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)joinSignLanguageChannel:(NSString *)signLanguageId;

/**
 * @brief Off sign language if myself is not a sign interpreter.Only for non-interpreter. Available only for customized ui.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)leaveSignLanguageChannel;
@end

NS_ASSUME_NONNULL_END
