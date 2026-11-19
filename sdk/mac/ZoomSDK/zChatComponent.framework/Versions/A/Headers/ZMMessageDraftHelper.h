//
//  ZMMessageDraftHelper.h
//  zChatUI
//
//  Created by kevin.li on 10/10/19.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <zChatComponent/ZMFileEntity.h>
#import <ZoomUnit/ZoomUnit-Swift.h>
#import <Prism/Prism-Swift.h>

@class ZMMessageFontInfo;
@class ZMIMMessageDraft;

#ifdef __cplusplus
static constexpr NSUInteger kZMMessageDraftProtocol_saveDelay = 6;
#else
static const NSUInteger kZMMessageDraftProtocol_saveDelay = 6;
#endif // __cplusplus

@interface ZMDraftEventInfo : NSObject

@property (nonatomic, assign) NSUInteger error;
@property (nonatomic, assign) BOOL isEcho;
@property (nonnull, nonatomic, retain) NSString *sessionID;
@property (nullable, nonatomic, retain) NSString *threadID;
@property (nonnull, nonatomic, retain) NSString *draftID;
@property (nonatomic, assign) BOOL isArchival;
@property (nonatomic, assign) BOOL isLoadEvent;

@end

#define kIM_DraftsStartScheduledEdit @"kIM_DraftsStartSheduledEdit"

#define kIM_DraftsSetActiveViewController @"kIM_DraftsSetViewController"

#define kIM_DraftsViewControllerID @"kIM_DraftsViewController"
#define kIM_ScheduledViewControllerID @"kIM_ScheduledViewController"

#define kZMMessageDraftHelperNext90WarnDefaultsKey @"kZMDMT90pNextWarnDate"
#define kZMMessageDraftHelperNext95WarnDefaultsKey @"kZMDMT95pNextWarnDate"

typedef void(^ZMDraftEventCompletionHandler)(ZMDraftEventInfo *_Nonnull event);
typedef void(^ZMDraftConnectionStateCompletionHandler)(NSInteger err);
typedef void(^ZMDraftCountUpdateCompletionHandler)(ZMDraftEventInfo *_Nonnull event);

@protocol ZMMessageDraftHelperToastDelegate <NSObject>

- (void)showToast:(nonnull NSString *)toast withType:(ZMToastType)type header:(nullable NSString *)header
           target:(nullable id)target action:(nullable SEL)action actionText:(nullable NSString *)actionText
          context:(nullable id)context image:(nullable NSImage *)image;


- (void)showToast:(nonnull NSString *)toast withType:(ZMToastType)type header:(nullable NSString *)header
           target:(nullable id)target action:(nullable SEL)action actionText:(nullable NSString *)actionText
          context:(nullable id)context image:(nullable NSImage *)image autoDisappear:(BOOL) isAutoDisappear;

- (void)showAttributedToast:(nonnull NSAttributedString *)toast withType:(ZMToastType)type header:(nullable NSString *)header
           target:(nullable id)target action:(nullable SEL)action actionText:(nullable NSString *)actionText
          context:(nullable id)context image:(nullable NSImage *)image;

- (void)openDraftsTab;
- (void)openScheduledTab;

@end

@protocol ZMMessageDraftProtocol <NSObject>

// util

+ (BOOL)isDraftsTabEnabled;
+ (BOOL)isScheduledMessagesEnabled;
- (NSUInteger)draftCount;
- (NSUInteger)scheduledMessageCount;
- (BOOL)isDraftLoadingDone;

- (BOOL)hasDraftInSubCMCBySession:(nonnull NSString *)sessionID;

+ (nullable ZMIMMessageDraft *)constructDraftModelWithBody:(nullable NSAttributedString *)draft
                                                 sessionID:(nonnull NSString *)sessionID
                                                  threadID:(nullable NSString *)threadID
                                          threadServerTime:(unsigned long long)threadServerTime
                                                  fileList:(nullable NSArray<ZMFileEntity *> *)fileList;

// drafts

- (nonnull NSArray<ZMIMMessageDraft *> *)getAllDrafts;

- (nullable ZMIMMessageDraft *)draftForDraftID:(nonnull NSString *)draftID;

- (BOOL)isOnlyLocalDraft:(nonnull NSString *)draftID;

- (nonnull NSArray<ZMIMMessageDraft *> *)draftsForSession:(nonnull NSString *)sessionID;
- (nonnull NSArray<ZMIMMessageDraft *> *)activeDraftsForSession:(nonnull NSString *)sessionID;
- (nonnull NSArray<ZMIMMessageDraft *> *)activeDraftsForSession:(nonnull NSString *)sessionID
                                                 includeSubCMCs:(BOOL)includeSubCMCs;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID;
- (nullable ZMIMMessageDraft *)activeDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;
- (nullable NSString *)activeDraftIDForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;

- (BOOL)setActiveDraft:(nullable ZMIMMessageDraft *)draft;

- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID;
- (BOOL)archiveActiveDraftForSession:(nonnull NSString *)sessionID thread:(nullable NSString *)threadID;
- (nullable ZMIMMessageDraft *)getLastActiveDraftForSession:(nonnull NSString *)sessionID isReply:(BOOL)isReply;

- (BOOL)saveActiveDraft:(nonnull ZMIMMessageDraft *)draft forceCloudSync:(BOOL)forceCloudSync;
- (BOOL)saveActiveDraft:(nullable NSAttributedString *)draft sessionID:(nonnull NSString *)sessionID fileList:(nullable NSArray<ZMFileEntity *> *)fileList forceCloudSync:(BOOL)forceCloudSync;
- (BOOL)saveActiveDraft:(nullable NSAttributedString *)draft sessionID:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID threadServerTime:(unsigned long long)threadServerTime fileList:(nullable NSArray<ZMFileEntity *> *)fileList forceCloudSync:(BOOL)forceCloudSync;

- (BOOL)saveDraft:(nonnull ZMIMMessageDraft *)draft forceCloudSync:(BOOL)forceCloudSync;

- (BOOL)eraseActiveDraftForSession:(nonnull NSString *)sessionID threadID:(nullable NSString *)threadID;
- (BOOL)eraseActiveDraftWithDraftID:(nonnull NSString *)draftID;

- (BOOL)sendDraft:(nonnull ZMIMMessageDraft *)draft fromView:(NSView *_Nonnull)view;

- (BOOL)eraseDraftByID:(nonnull NSString *)draftID;
- (BOOL)eraseDraft:(nonnull ZMIMMessageDraft *)draft;
- (BOOL)eraseDrafts:(nonnull NSArray<ZMIMMessageDraft *> *)drafts;

// scheduled messages

- (nonnull NSArray<ZMIMMessageDraft *> *)getAllScheduledMessages;

- (nullable ZMIMMessageDraft *)scheduledMessageForID:(nonnull NSString *)draftID;
- (nonnull NSArray<ZMIMMessageDraft *> *)scheduledMessagesForSession:(nonnull NSString *)sessionID;

- (BOOL)scheduleDraftWithID:(nonnull NSString *)draftID date:(nonnull NSDate *)date;
- (BOOL)scheduleDraft:(nonnull ZMIMMessageDraft *)draft date:(nonnull NSDate *)date;
- (BOOL)cancelScheduledMessage:(nonnull NSString *)draftID;

- (BOOL)updateScheduledMessage:(nonnull ZMIMMessageDraft *)draft;
- (BOOL)updateScheduledMessage:(nonnull ZMIMMessageDraft *)draft
                     showToast:(BOOL)showToast;

- (BOOL)eraseScheduledMessage:(nonnull NSString *)draftID;

// callbacks

- (void)addDraftDeletionListener:(nonnull id)target
                      completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftDeletionListener:(nonnull id)target;

- (void)addDraftAdditionListener:(nonnull id)target
                      completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftAdditionListener:(nonnull id)target;

- (void)addDraftUpdateListener:(nonnull id)target
                    completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeDraftUpdateListener:(nonnull id)target;

- (void)addConnectionStateListener:(nonnull id)target
                        completion:(nonnull ZMDraftConnectionStateCompletionHandler)completionHandler;
- (void)removeConnectionStateListener:(nonnull id)target;

- (void)addDraftCountUpdateListener:(nonnull id)target
                         completion:(nonnull ZMDraftCountUpdateCompletionHandler)completionHandler;
- (void)removeDraftCountUpdateListener:(nonnull id)target;

- (void)addScheduledDeletionListener:(nonnull id)target
                          completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledDeletionListener:(nonnull id)target;

- (void)addScheduledAdditionListener:(nonnull id)target
                          completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledAdditionListener:(nonnull id)target;

- (void)addScheduledUpdateListener:(nonnull id)target
                        completion:(nonnull ZMDraftEventCompletionHandler)completionHandler;
- (void)removeScheduledUpdateListener:(nonnull id)target;

- (void)addScheduledCountUpdateListener:(nonnull id)target
                         completion:(nonnull ZMDraftCountUpdateCompletionHandler)completionHandler;
- (void)removeScheduledCountUpdateListener:(nonnull id)target;

- (void)onConnectionStateChange:(int)err;

- (BOOL)isDraftPendingOperation:(nonnull NSString *)draftID;

@end

@interface ZMMessageDraftHelper : NSObject <ZMMessageDraftProtocol>

@property (nullable, weak) id<ZMMessageDraftHelperToastDelegate> toastDelegate;

+ (instancetype _Nonnull)sharedInstance;
// to be called at log out - invalidates the request cache and all other session-specific information.
// callback subscriptions are left unmodified.
- (void)invalidate;

+ (BOOL)hasReplyDraftWithChannelID:(NSString * _Nonnull)channelID threadID:(NSString * _Nullable)threadID;

@end
