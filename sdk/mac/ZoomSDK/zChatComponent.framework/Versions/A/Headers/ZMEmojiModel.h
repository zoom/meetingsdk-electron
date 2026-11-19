//
//  ZMEmojiModel.h
//  zChatComponent
//
//  Created by Mario Rao on 4/24/23.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMEmojiModelProtocal.h>
#import <zChatBase/IZMCustomEmojiModel.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMChatFileItem, ZMSelectedEmojiModel, ZMUnicodeEmojiModel;

@interface ZMCustomEmojiModel : NSObject <IZMCustomEmojiModel>

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

- (instancetype)initWithEmojiName:(NSString *)emojiName fileID:(NSString *)fileID source:(ZMCustomEmojiSource)source;
- (instancetype)initWithCustomEmojiString:(NSString *)emojiString source:(ZMCustomEmojiSource)source;
- (NSString *)downloadIfNeededWithError:(NSError **)error;
- (void)getFileInfoWithCompletion:(void (^)(BOOL isDownloading, BOOL isSDKDownloaded, NSString *filePath))completion;
- (NSString *)stringValue;
- (NSString *)emojiNameWithoutColon;
- (NSString *)SDKFilePath;
- (NSString *)filePath;
- (BOOL)isValid;

@end

@interface ZMEmojiModel : NSObject<ZMEmojiModelProtocal>

@property (nonatomic, strong, readonly) ZMUnicodeEmojiModel *unicodeEmoji;
@property (nonatomic, strong, readonly) ZMCustomEmojiModel *customEmoji;

- (instancetype)initWithEmojiName:(NSString *)emojiName unicode:(NSString *)unicode skins:(nullable NSArray<NSString *> *)skins keywords:(nullable NSArray<NSString *> *)keywords;
- (instancetype)initWithEmojiString:(NSString *)emojiString source:(ZMCustomEmojiSource)source;;
- (instancetype)initWithEmojiName:(NSString *)emojiName fileID:(NSString *)fileID source:(ZMCustomEmojiSource)source;;
- (nullable id)getUnicodeEmoji;
- (nullable NSString *)unicodeEmojiAtToneIndex:(NSInteger)index;
- (BOOL)isCustomEmoji;
- (BOOL)isValid;
- (NSString *)emojiName;
- (NSString *)emojiNameWithoutColon;
- (NSString *)downloadIfNeeded;
- (NSString *)identifierWithToneIndex:(NSInteger)idx;
- (BOOL)isEqualToModel:(ZMEmojiModel *)model;

@end

NS_ASSUME_NONNULL_END
