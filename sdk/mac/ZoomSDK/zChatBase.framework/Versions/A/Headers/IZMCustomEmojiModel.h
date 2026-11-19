//
//  IZMCustomEmojiModel.h
//  zChatBase
//
//  A lightweight protocol abstraction for custom emoji model.
//  Keep this header independent from zChatComponent concrete model types.
//
//  Created by Mario Rao on 2026/1/27.
//

#ifndef IZMCustomEmojiModel_h
#define IZMCustomEmojiModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CustomEmojiDownloadErrorCode) {
    CustomEmojiDownloadErrorCodeNone = 0,
    CustomEmojiDownloadErrorCodeUnknown = -1000,
    CustomEmojiDownloadErrorCodeNoFileID = -1001,
    CustomEmojiDownloadErrorCodeDuplicate = -1002,
    CustomEmojiDownloadErrorCodeNoExist = -1003,
    CustomEmojiDownloadErrorCodeDuplicateRequest = -1004,
    CustomEmojiDownloadErrorCodeImageSizeExcceed = -1005,
    CustomEmojiDownloadErrorCodeInvalid = -1006,
    CustomEmojiDownloadErrorCodeTimeOut = -1007
};

typedef NS_ENUM(NSUInteger, ZMCustomEmojiSource) {
    ZMCustomEmojiSourceNone = 0,
    ZMCustomEmojiSourceChat = 1,
    ZMCustomEmojiSourceMeeting = 2
};

@protocol IZMCustomEmojiModel <NSObject>

@property (nonatomic, strong) NSString *emojiName;
@property (nonatomic, strong) NSString *fileID;
@property (nonatomic, assign) ZMCustomEmojiSource source;

//for message custom emoji downloading
@property (nonatomic, strong) NSString *sessionID;
@property (nonatomic, strong) NSString *messageID;
@property (nonatomic, assign) NSInteger fileIndex;

@property (nonatomic, assign, readonly) BOOL isDeleted;
@property (nonatomic, assign, readonly) BOOL isDownloading;
@property (nonatomic, assign, readonly) BOOL isDownloaded;
@property (nonatomic, assign, readonly) BOOL isSDKDownloaded;

- (NSString *)downloadIfNeededWithError:(NSError **)error;
- (void)getFileInfoWithCompletion:(void (^)(BOOL isDownloading, BOOL isSDKDownloaded, NSString *filePath))completion;
- (NSString *)stringValue;
- (NSString *)emojiNameWithoutColon;
- (NSString *)SDKFilePath;
- (NSString *)filePath;
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMCustomEmojiModel_h */

