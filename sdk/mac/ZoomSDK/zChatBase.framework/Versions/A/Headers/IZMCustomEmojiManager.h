//
//  IZMCustomEmojiManager.h
//  zChatBase
//
//  A lightweight protocol abstraction for custom emoji manager.
//  Intended for decoupling UI modules (e.g. VideoUI) from zChatComponent.
//
//  Created by Mario Rao on 2026/1/27.
//

#ifndef IZMCustomEmojiManager_h
#define IZMCustomEmojiManager_h

#import <Foundation/Foundation.h>
#import <zChatBase/IZMCustomEmojiModel.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZMCustomEmojiManager <NSObject>

//MARK: - OP
- (BOOL)isDisableCustomEmojiGIFAnimation;
- (BOOL)isEnableCustomEmojiMeetingDatabase;
- (BOOL)isCustomEmojiEnabledForSource:(ZMCustomEmojiSource)source;
- (BOOL)isChatCustomEmojiEnabledForSource:(ZMCustomEmojiSource)source;
- (BOOL)isEditCustomEmojiEnabledForSource:(ZMCustomEmojiSource)source;

- (BOOL)isCustomEmojiEnabledForSession:(NSString *)sessionID messageID:(NSString *)messageID;
- (BOOL)isEditCustomEmojiEnabledForSession:(NSString *)sessionID;

//MARK: - Util
- (BOOL)isValidCustomEmojiNameInput:(NSString *)name;
- (NSString *)emojiOwnerIDWithFileID:(NSString *)fileID source:(ZMCustomEmojiSource)source;
- (BOOL)canLoadMoreWithSource:(ZMCustomEmojiSource)source;
- (BOOL)isLoadingWithSource:(ZMCustomEmojiSource)source;
- (NSString *)myCustomEmojiJidForSource:(ZMCustomEmojiSource)source;
- (NSDictionary *)customEmojiName2ModelMapWithSource:(ZMCustomEmojiSource)source;
- (NSString *)fixedEmojiFilePathWithPath:(NSString *)path;
- (NSString *)generateCustomEmojiPathWithExtension:(NSString *)extension fileID:(NSString *)fileID source:(ZMCustomEmojiSource)source;
- (BOOL)isEmojiDeletedWithFileID:(NSString *)fileID;

- (NSString *)emojiOwnerIDWithFileID:(NSString *)fileID session:(NSString *)sessionID;
- (NSString *)customEmojiNameWithFileID:(NSString *)fileID source:(ZMCustomEmojiSource)source;
- (BOOL)canLoadMoreWithSession:(NSString *)sessionID;
- (BOOL)isLoadingWithSession:(NSString *)sessionID;
- (NSString *)myCustomEmojiJidForSession:(NSString *)sessionID;
- (NSDictionary *)customEmojiName2ModelMapWithSession:(NSString *)sessionID;
- (nullable id<IZMCustomEmojiModel>)customEmojiModelWithEmojiName:(NSString *)emojiName
                                                         fileID:(NSString *)fileID
                                                          source:(ZMCustomEmojiSource)source;
@end

NS_ASSUME_NONNULL_END

#endif /* IZMCustomEmojiManager_h */

