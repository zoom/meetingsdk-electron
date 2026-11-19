//
//  ZMIMMessageDraft.h
//  zChatComponent
//
//  Created by groot Ding on 9/22/25.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMessageFontInfo.h>
#import <zChatComponent/ZMFileEntity.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <ZoomUnit/ZoomUnit-Swift.h>
#import <Prism/Prism-Swift.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMIMMessageDraftSendability) {
    ZMIMMessageDraftSendabilityOK = 0,
    ZMIMMessageDraftSendabilityBadRecipient,
    ZMIMMessageDraftSendabilityAdminDisabledRecipient,
    ZMIMMessageDraftSendabilityBadThread,
    ZMIMMessageDraftSendabilityNoPermission,
    ZMIMMessageDraftSendabilityDMDisabled,
    ZMIMMessageDraftSendabilityRestrictedFile // ZOOM-786530
};


@interface ZMIMMessageDraft : NSObject

// NOTE: all int64_t timestamps are in *milliseconds* since epoch.

@property (nonatomic, copy, nullable)   NSAttributedString *draft;
@property (nonatomic, retain, nullable) NSArray<ZMFileEntity*> *fileList;
@property (nonatomic, copy, nullable)   NSArray<ZMMessageFontInfo*>  *fontStyleInfoList;
@property (nonatomic, assign) int64_t createdTime;
@property (nonatomic, assign) int64_t lastEditedTime;
@property (nonatomic, retain, nonnull)  NSString *sessionID;
@property (nonatomic, retain, nullable) NSString *threadID;
@property (nonatomic, assign) int64_t threadServerTime;
@property (nonatomic, assign) int64_t scheduledTime;

@property (nonatomic, retain, nonnull) NSString  *draftID;
@property (assign) BOOL isActive;
@property (assign) BOOL didFailSync;

@property (readonly) BOOL isScheduledMessage;

@property (readonly) BOOL isEmpty;
@property (readonly) BOOL isImageOnly;

/// ZOOM-786530 to simplify code of toast.
@property (nonatomic, retain) ZMToast *toast;

/* Draft display format, like "Hello. (x Files)", "Hello*********..." */
@property (nonatomic, readonly, copy, nullable) NSString *draftDesp;

/// Whether the draft this object represents can be sent as a message.
/// @note This is a calculated property that may invoke methods that do **not** run in O(1).
@property (readonly) ZMIMMessageDraftSendability sendability;

- (nullable NSAttributedString *)attributedDraftDesp;

- (BOOL)hasDraft;
- (nullable NSString *)plaintextDraft;

- (instancetype)initWithDraftID:(NSString *)draftID;

// does NOT add quotes by default.
+ (nullable NSString *)plaintextDraftForDraft:(nonnull NSAttributedString *)draft
                                fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList;

/// Plain text with custom emojis. So it has to use attributed string.
- (nullable NSAttributedString *)plainAttributedTextDraft;
/// Plain text with custom emojis. So it has to use attributed string.
- (nullable NSAttributedString *)plainAttributedTextDraftWithQuotes;

/// Plain text with custom emojis. So it has to use attributed string.
+ (nullable NSAttributedString *)plainAttributedTextDraftForDraft:(nonnull NSAttributedString *)draft
                                                    fontStyleInfo:(nullable NSArray<ZMMessageFontInfo *> *)fontStyleInfoList;


- (NSAttributedString *)plainAttributedStringDraft;

- (nonnull NSString *)getRecipientName;
- (BOOL)hasValidRecipient;
- (BOOL)isInE2EESession;
- (BOOL)isCSESession;

- (int64_t)getLastEditedTime;
- (int64_t)getScheduledTime;

- (void)update;

- (BOOL)canCopy;
- (NSArray <NSURL *> *)fileURLs;
@end

NS_ASSUME_NONNULL_END
