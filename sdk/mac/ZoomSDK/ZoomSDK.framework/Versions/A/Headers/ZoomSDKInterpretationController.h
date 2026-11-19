/**
 * @file ZoomSDKInterpretationController.h
 * @brief Interfaces for Zoom SDK Language Interpretation management.
 *
 * This file defines the interfaces for managing interpreters and interpretation channels in Zoom meetings,
 * including language info queries, interpreter management, and real-time callbacks.
 */


#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKInterpretationLanguageInfo
 * @brief Represent interpretation language information.
 */
@interface ZoomSDKInterpretationLanguageInfo : NSObject

/**
 * @brief Gets the language ID.
 * @return The language ID.
 */
- (int)getLanguageID;

/**
 * @brief Gets the language alias (abbreviation).
 * @return If the function succeeds, it returns the language abbreviation (e.g., "EN", "CN"). Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getLanguageAbbreviations;

/**
 * @brief Gets the language name.
 * @return If the function succeeds, it returns the full language name (e.g., "English", "Chinese"). Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getLanguageName;
@end

/**
 * @class ZoomSDKInterpreter
 * @brief Represent an interpreter user and their supported languages.
 */
@interface ZoomSDKInterpreter : NSObject

/**
 * @brief Gets the interpreter's user ID.
 * @return User ID of the interpreter.
 */
- (unsigned int)getUserID;

/**
 * @brief Gets the interpreter's first supported language ID.
 * @return Language ID.
 */
- (int)getLanguageID1;

/**
 * @brief Gets the interpreter's second supported language ID.
 * @return Language ID.
 */
- (int)getLanguageID2;

/**
 * @brief Determines is currently available in the meeting.
 * @return YES if the interpreter is available and had join meeting. Otherwise, NO.
 */
- (BOOL)isAvailable;
@end

/**
 * @protocol ZoomSDKInterpretationControllerDelegate
 * @brief Callback protocol for receiving interpretation-related events.
 */
@protocol ZoomSDKInterpretationControllerDelegate <NSObject>

/**
 * @brief Notify the interpretation is started.
 */
- (void)onInterpretationStart;

/**
 * @brief Notify the interpretation is stoped.
 */
- (void)onInterpretationStop;

/**
 * @brief Notify the interpreter role is changed.
 * @param userID The user ID of the interpreter role change.
 * @param interpreter YES if interpreter, NO otherwise.
 */
- (void)onInterpreterRoleChanged:(unsigned int)userID isInterpreter:(BOOL)interpreter;

/**
 * @brief Notify the interpreter role is changed.
 * @param userID The interpreter's user ID.
 * @param languageID The current active language ID.
 */
- (void)onInterpreterActiveLanguageChanged:(unsigned int)userID activeLanguageID:(int)languageID;

/**
 * @brief Notify the interpreter language changed.
 * @param lanID1 The language id of the first language id.
 * @param lanID2 The language id of the second language id.
 */
- (void)onInterpreterLanguageChanged:(int)lanID1  theLanguageID2:(int)lanID2;

/**
 * @brief Notify the available language.
 * @param availableLanguageArr The array contain available language object (The language object is ZoomSDKInterpretationLanguageInfo).
 */
- (void)onAvailableLanguageListUpdated:(NSArray*_Nullable)availableLanguageArr;

/**
 * @brief Notify the interpreter list changed.
 */
- (void)onInterpreterListChanged;

/**
 * @brief Notify the list of available languages that interpreters can hear has changed. When the list of available languages that interpreters can hear in a meeting is changed. All interpreters in the meeting can get this event.
 * @param availableLanguages The list of available languages that interpreters can hear.
 */
- (void)onInterpreterLanguagesUpdated:(NSArray<ZoomSDKInterpretationLanguageInfo *>*_Nullable)availableLanguages;
@end


/**
 * @class ZoomSDKInterpretationController
 * @brief Interface for managing interpretation in a Zoom meeting.
 */
@interface ZoomSDKInterpretationController : NSObject
/**
 * @brief Delegate for receiving interpretation-related events.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKInterpretationControllerDelegate>  delegate;

/**
 * @brief Determines if the interpretation function is enabled.
 * @return YES if interpretation function is enable. Otherwise, NO.
 */
- (BOOL)isInterpretationEnabled;

/**
 * @brief Determines if the interpretation function is started.
 * @return YES if interpretation is started. Otherwise, NO.
 */
- (BOOL)isInterpretationStarted;

/**
 * @brief Determines if self is interpreter.
 * @return YES if self is interpreter. Otherwise, NO.
 */
- (BOOL)isInterpreter;

/**
 * @brief Gets interpretation language info by language ID.
 * @param languageID The ID of language.
 * @return If the function succeeds, it returns ZoomSDKInterpretationLanguageInfo object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKInterpretationLanguageInfo*_Nullable)getInterpretationLanguageByID:(int)languageID;

/**
 * @brief Gets the full list of supported interpretation languages.
 * @return If the function succeeds, the return array contain language object.(The language object is ZoomSDKInterpretationLanguageInfo). Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAllLanguageList;

/**
 * @brief Gets the list of all interpreters in the meeting.
 * @return If the function succeeds, the return array contain interpreter object.(The language object is ZoomSDKInterpreter). Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAllInterpreterList;

/**
 * @brief Adds an interpreter.
 * @param userID User ID.
 * @param lanID1 First language ID.
 * @param lanID2 Second language ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addInterpreter:(unsigned int)userID languageID1:(int)lanID1 languageID2:(int)lanID2;

/**
 * @brief Removes an interpreter.
 * @param userID User ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)removeInterpreter:(unsigned int)userID;

/**
 * @brief Modify the supported languages of an interpreter.
 * @param userID User ID.
 * @param lanID1 First language ID.
 * @param lanID2 Second language ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)modifyInterpreter:(unsigned int)userID languageID1:(int)lanID1 languageID2:(int)lanID2;

/**
 * @brief Starts interppretation.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startInterpretation;

/**
 * @brief Stops interppretation.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)StopInterpretation;

/**
 * @brief Gets the list of available interpretation languages.
 * @return Array of ZoomSDKInterpretationLanguageInfo. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAvailableLanguageList;

/**
 * @brief Join an interpretation language channel.
 * @param languageID Language ID. -1 means join the major audio.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)joinLanguageChannel:(int)languageID;

/**
 * @brief Gets the language ID currently joined.
 * @return Language ID.
 */
- (int)getJoinedLanguageID;

/**
 * @brief Turn off the major meeting audio.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnOffMajorAudio;

/**
 * @brief Turn on the major meeting audio.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)turnOnMajorAudio;

/**
 * @brief Determines if major audio is turn off.
 * @return YES if major audio is turn off. Otherwise, NO.
 */
- (BOOL)isMajorAudioTurnOff;

/**
 * @brief Gets interpreter support language.
 * @param lanID1 The id is interpreter first language.
 * @param lanID2 The id is interpreter second language.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getInterpreterLans:(int*)lanID1 languageID2:(int*)lanID2;

/**
 * @brief Sets interpreter active language.
 * @param activeLanID Active language ID.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setInterpreterActiveLan:(int)activeLanID;

/**
 * @brief Gets interpreter current active language ID.
 * @return Active language ID.
 */
- (int)getInterpreterActiveLanID;

/**
 * @brief Gets the list of available languages that interpreters can hear.
 * @return If the function succeeds, the retuan value is an array of ZoomSDKInterpretationLanguageInfo. Otherwise, this function fails and returns nil.
 */
- (NSArray <ZoomSDKInterpretationLanguageInfo *>*_Nullable)getInterpreterAvailableLanguages;

/**
 * @brief Sets a language that I can hear as an interpreter.
 * @param languageID Specify the selected language that I can hear as an interpreter.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setInterpreterListenLan:(int)languageID;

/**
 * @brief Gets a language that I can hear as an interpreter.
 * @return Language ID.
 */
- (int)getInterpreterListenLanID;
@end

NS_ASSUME_NONNULL_END
