/**
 * @file ZoomSDKQAController.h
 * @brief Interfaces for the Zoom SDK Q&A module.
 *
 * This file provides the definitions for Q&A related objects, including questions, answers, and the Q&A controller.
 */

#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * @class ZoomSDKAnswerInfo
 * @brief Represents an answer object in the Q&A module.
 */
@interface ZoomSDKAnswerInfo :NSObject
/**
 * @brief Gets the answer ID.
 * @return If the function succeeds, it returns the current answer's ID. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getAnswerID;

/**
 * @brief Gets the question answer is send myself.
 * @return Yes means the answer is send by self. Otherwise, NO.
 */
- (BOOL)isSenderMyself;

/**
 * @brief Gets the current answer's timestamps.
 * @return The current answer's timestamps.
 */
- (time_t)getTimeStamp;

/**
 * @brief Gets the answer content.
 * @return If the function succeeds, it returns the answer's content. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getAnswerContent;

/**
 * @brief Gets the answer's sender name.
 * @return If the function succeeds, it returns the person's name answering the question. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getSendName;

/**
 * @brief Gets the question ID.
 * @return If the function succeeds, it returns the questionID. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getQuestionId;

/**
 * @brief Gets the answer is private.
 * @return Yes means the answer is private. Otherwise, NO.
 */
- (BOOL)isPrivate;

/**
 * @brief Gets the answer is live.
 * @return Yes means the answer is live. Otherwise, NO.
 */
- (BOOL)isLiveAnswer;
@end

/**
 * @class ZoomSDKQuestionInfo
 * @brief Represents a question object in the Q&A module.
 */
@interface ZoomSDKQuestionInfo : NSObject

/**
 * @brief Gets the question ID.
 * @return If the function succeeds, it returns the current question's ID. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getQuestionId;
/**
 * @brief Gets the question is send by self.
 * @return Yes means the question is send by self. Otherwise, NO.
 */
- (BOOL)isSenderMyself;

/**
 * @brief Gets the current question's timestamps.
 * @return The current question's timestamps.
 */
- (time_t )getTimeStamp;

/**
 * @brief Gets the question content.
 * @return If the function succeeds, it returns the current question's content. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getQuestionContent;

/**
 * @brief Gets the question's sender name.
 * @return If the function succeeds, it returns the person's name send the question. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getSendName;

/**
 * @brief Gets the question is anonymous.
 * @return YES if the question is anonymous. Otherwise, NO.
 */
- (BOOL)isAnonymous;

/**
 * @brief Gets the question is marked as answer.
 * @return YES if the question is marked as answer. Otherwise, NO.
 */
- (BOOL)isMarkedAsAnswered;

/**
 * @brief Gets the question is marked as dismissed.
 * @return YES if the question is marked as dismissed. Otherwise, NO.
 */
- (BOOL)isMarkedAsDismissed;

/**
 * @brief Gets the question vote number.
 * @return The question vote number.
 */
- (int)upVoteNum;

/**
 * @brief Gets the question has live answer.
 * @return YES if the question has live answer. Otherwise, NO.
 */
- (BOOL)hasLiveAnswers;

/**
 * @brief Gets the question has text answer.
 * @return YES if the question has text answer. Otherwise, NO.
 */
- (BOOL)hasTextAnswers;

/**
 * @brief Gets the question is myself vote.
 * @return YES if the question is myself vote. Otherwise, NO.
 */
- (BOOL)isMySelfUpvoted;

/**
 * @brief Gets the question is myself live answered.
 * @return YES if the question is myself live answered. Otherwise, NO.
 */
- (BOOL)amILiveAnswering;

/**
 * @brief Gets the question answer list.
 * @return If the function succeeds, it returns the answer list of question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAnswerList;

/**
 * @brief Gets the person name of live answered question.
 * @return If the function succeeds, it returns the person's name live answered the question. Otherwise, this function fails and returns nil.
 */
- (NSString*_Nullable)getLiveAnswerName;

/**
 * @brief Gets the queestion is answered living.
 * @return Yes means the answer is living. Otherwise, NO.
 */
- (BOOL)isLiveAnswering;
@end


/**
 * @protocol ZoomSDKQAControllerDelegate
 * @brief Callback events for Q&A controller.
 */
@protocol ZoomSDKQAControllerDelegate <NSObject>

/**
 * @brief This callback returns the connect status.
 * @param status The Q&A connect status.
 */
- (void)onQAConnectStatus:(ZoomSDKQAConnectStatus)status;

/**
 * @brief If add question receives the callback.
 * @param questionID The unique ID of question.
 * @param success If the success is YES imeans add question success, NO otherwise.
 */
- (void)onAddQuestion:(NSString *)questionID  isSuccess:(BOOL)success;

/**
 * @brief If add answer receives the callback.
 * @param answerID The unique ID of answer.
 * @param success If the success is YES means add answer success, NO otherwise.
 */
- (void)onAddAnswer:(NSString *)answerID  isSuccess:(BOOL)success;

/**
 * @brief If the question marked as dismiss receives the callback.
 * @param questionID The question's unique ID marked as dismissed.
 */
- (void)onQuestionMarkedAsDismissed:(NSString*)questionID;

/**
 * @brief If reopen question receives the callback.
 * @param questionID The reopen question ID.
 */
- (void)onReopenQuestion:(NSString*)questionID;

/**
 * @brief If receive question receives the callback.
 * @param questionID The receive question ID.
 */
- (void)onReceiveQuestion:(NSString*_Nullable)questionID;

/**
 * @brief If receive answer receives the callback.
 * @param answerID The receive answer ID.
 */
- (void)onReceiveAnswer:(NSString*_Nullable)answerID;

/**
 * @brief If user living reply receives the callback.
 * @param questionID The user living reply questionID.
 */
- (void)onUserLivingReply:(NSString*)questionID;

/**
 * @brief If user end living receives the callback.
 * @param questionID The user end living questionID.
 */
- (void)onUserEndLiving:(NSString*)questionID;

/**
 * @brief If vote queation receives the callback.
 * @param questionID The vote questionID.
 * @param isChanged If YES means the question order changed, NO otherwise.
 */
- (void)onVoteupQuestion:(NSString*)questionID orderChanged:(BOOL)isChanged;

/**
 * @brief If revoke vote queation receives the callback.
 * @param questionID The revoke vote question ID.
 * @param isChanged If YES means the question order changed, NO otherwise.
 */
- (void)onRevokeVoteupQuestion:(NSString*)questionID orderChanged:(BOOL)isChanged;

/**
 * @brief Notify host or cohost has changed the status of ask question.
 * @param bEnabled Can ask question or not.
 */
- (void)onAllowAskQuestionStatus:(BOOL)bEnabled;

/**
 * @brief Notify host or cohost has changed the status of ask question anonymous.
 * @param bEnabled Can ask question anonymous or not.
 */
- (void)onAllowAskQuestionAnonymousStatus:(BOOL)bEnabled;

/**
 * @brief Notify host or cohost has changed the status of attendee can view all question.
 * @param bEnabled Attendee can aview all question or not.
 */
- (void)onAllowAttendeeViewAllQuestionStatus:(BOOL)bEnabled;

/**
 * @brief Notify host or cohost has change the status of attendee can voteup question.
 * @param bEnabled Attendee can ask voteup question or not.
 */
- (void)onAllowAttendeeVoteupQuestionStatus:(BOOL)bEnabled;

/**
 * @brief Notify host or cohost has change the status of attendee comment question.
 * @param bEnabled Attendee can comment question.
 */
- (void)onAllowAttendeeCommentQuestionStatus:(BOOL)bEnabled;

/**
 * @brief Notify the question has been deleted.
 * @param questions The array contain deleted question ID (The question ID is NSString type).
 */
- (void)onDeleteQuestions:(NSArray *)questions;

/**
 * @brief Notify the answer has been deleted.
 * @param answer The array contain deleted answer ID (The answer ID is NSString type).
 */
- (void)onDeleteAnswers:(NSArray *)answer;
@end


/**
 * @class ZoomSDKQAController
 * @brief Provide interfaces to manage Q&A session in Zoom meeting.
 */
@interface ZoomSDKQAController : NSObject
{
    id<ZoomSDKQAControllerDelegate> _delegate;
}
/**
 * @brief Delegate to receive Q&A-related callback events.
 */
@property(nonatomic,assign,nullable)id<ZoomSDKQAControllerDelegate> delegate;

/**
 * @brief Q&A function is available.
 * @return If returns YES, Q&A is available. Otherwise, NO.
 */
- (BOOL)isQAEnable;
/**
 * @brief Gets all question list.
 * @return If the function succeeds, it returns array of all question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAllQuestionList;

/**
 * @brief Gets my question list.
 * @return If the function succeeds, it returns array of my question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getMyQuestionList;

/**
 * @brief Gets open question list.
 * @return If the function succeeds, it returns array of open question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getOpenQuestionList;

/**
 * @brief Gets dismissed question list.
 * @return If the function succeeds, it returns array of dismissed question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getDismissedQuestionList;

/**
 * @brief Gets anwered question list.
 * @return If the function succeeds, it returns array of answered question. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getAnsweredQuestionList;

/**
 * @brief Attendee to send question.
 * @param content The question content of user send.
 * @param Anonymous If YES means can anonymous send question, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)addQuestionWithQuestionContent:(NSString*)content isAnonymous:(BOOL)Anonymous;

/**
 * @brief Answer questions in private.
 * @param questionID The answer question ID.
 * @param content The answer content.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)answerQuestionPrivateWithQuestionID:(NSString*)questionID answerContent:(NSString*)content;

/**
 * @brief Answer questions in public.
 * @param questionID The answer question ID.
 * @param content The answer content.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)answerQuestionPublicWithQuestionID:(NSString*)questionID answerContent:(NSString*)content;

/**
 * @brief Dismiss question.
 * @param questionID The dismiss question is;
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)dismissQuestionWithQuestionID:(NSString*)questionID;

/**
 * @brief Reopen the question.
 * @param questionID The reopen question is.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)reopenQuestionWithQuestionID:(NSString*)questionID;

/**
 * @brief Comment the question.
 * @param questionID The comment question ID.
 * @param content The comment on the content.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)commentQuestionWithQuestionID:(NSString*)questionID commentContent:(NSString*)content;

/**
 * @brief Vote the question.
 * @param questionID The vote question ID.
 * @param enable If YES, vote the question, Otherwise cancel vote.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)voteupQuestionWithQuestionID:(NSString*)questionID  isEableVokeup:(BOOL)enable;

/**
 * @brief Sets attendee can ask question.
 * @param enable If set YES means attendee can ask question, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableAskQuestion:(BOOL)enable;
/**
 * @brief Sets attendee can anonnymous send question.
 * @param enable If set YES means attendee can anonnymous send question, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableAnonymousSendQuestion:(BOOL)enable;

/**
 * @brief Sets attendee comment.
 * @param enable If set YES means attendee can comment, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableQAComment:(BOOL)enable;

/**
 * @brief Sets attendee vote.
 * @param enable If set YES means attendee can vote, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)enableQAVoteup:(BOOL)enable;

/**
 * @brief Sets attendee view question type.
 * @param type The enumeration of AttendeeViewQuestionType,if type is viewType_OnlyAnswered_Question,attendee only view the answered question,if type is viewType_All_Question,attendee can view all question
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setAttendeeViewQuestionType:(AttendeeViewQuestionType)type;

/**
 * @brief Gets the question object.
 * @param questionID The ID of question.
 * @return If the function succeeds, it returns question object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKQuestionInfo*)getQuestionByQuestionID:(NSString*)questionID;

/**
 * @brief Determines if the ask question is allowed by the host or co-host.
 * @return If return YES if can ask question. Otherwise, NO.
 */
- (BOOL)isAskQuestionEnabled;
/**
 * @brief Determines if the Q&A vote is allowed by the host or co-host.
 * @return If return YES if can vote. Otherwise, NO.
 */
- (BOOL)isQAVoteupEnable;

/**
 * @brief Determines if the Q&A comment is allowed by the host or co-host.
 * @return If return YES if can comment. Otherwise, NO.
 */
- (BOOL)isQACommentEnabled;

/**
 * @brief Determines if the ask question anonymous is allowed by the host or co-host.
 * @return If return YES if can ask question anonymously. Otherwise, NO.
 */
- (BOOL)isAllowAskQuestionAnonymously;

/**
 * @brief Determines if the Q&A attendee can view all question.
 * @return If return YES if attendee can view all queation. Otherwise, NO.
 */
- (BOOL)isAttendeeCanViewAllQuestions;

/**
 * @brief Gets the answer object.
 * @param answerID The ID of answer.
 * @return If the function succeeds, it returns answer object. Otherwise, this function fails and returns nil.
 */
- (ZoomSDKAnswerInfo *)getAnswerByAnswerID:(NSString *)answerID;

/**
 * @brief Starts answer question on living.
 * @param questionId The ID of question.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startLiving:(NSString *)questionId;

/**
 * @brief End answer question on living.
 * @param questionId The ID of question.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)endLiving:(NSString *)questionId;

/**
 * @brief Gets open question count.
 * @return The open question count.
 */
- (int)getOpenQuestionCount;

/**
 * @brief Gets dismiss question count.
 * @return The dismiss question count.
 */
- (int)getDismissedQuestionCount;

/**
 * @brief Gets answered question count.
 * @return The answered question count.
 */
- (int)getAnsweredQuestionCount;

/**
 * @brief Gets my question count.
 * @return The my question count.
 */
- (int)getMyQuestionCount;

/**
 * @brief Deleted question.
 * @param questionID The ID of question.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)deleteQuestion:(NSString *)questionID;

/**
 * @brief Deleted answer.
 * @param answerID The ID of answer.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)deleteAnswer:(NSString *)answerID;

/**
 * @brief Determines whether the legal notice for QA is available.
 * @return YES if the legal notice for QA is available. Otherwise, NO.
 */
- (BOOL)isQALegalNoticeAvailable;

/**
 * @brief Gets the QA legal notices prompt.
 * @return If the function succeeds, it returns the QA legal notices prompt. Otherwise, this function fails and returns nil.
 */
- (NSString *)getQALegalNoticesPrompt;

/**
 * @brief Gets the QA legal notices explained.
 * @return If the function succeeds, it returns the QA legal notices explained. Otherwise, this function fails and returns nil.
 */
- (NSString *)getQALegalNoticesExplained;
@end
NS_ASSUME_NONNULL_END
