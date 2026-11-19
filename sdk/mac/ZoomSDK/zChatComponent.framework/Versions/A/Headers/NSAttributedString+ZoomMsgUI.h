//
//  NSAttributedString+Message.h
//  zChatUI
//
//  Created by groot.ding on 2019/5/30.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zEventTracker/PTEventTrackingHelper.h>
#include <zTelemetryBiz/zTelemetryBizInterface.h>
#include <zTelemetryBiz/SnowplowBiz/chat_v2/chat_v2_telemetry_interface.h>
#import <zChatComponent/NSAttributedString+ZoomMsgUI-Swift.h>
#import <zChatComponent/ZMEmojiModel.h>
#import <ZoomUnit/ZMFileConstants.h>

@class ZMDocUrlEntity;

@class ZMMessageFontInfo;
@class ZMCustomEmojiModel;

NS_ASSUME_NONNULL_BEGIN

@interface NSAttributedString (ZoomMsgUI)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"
- (NSString *)getMessageStringAndAtList:(NSArray **)atlist atListText:(NSArray **)atListText emojiExtension:(void **)emojiExtension sessionID:(NSString*)sessionID;
- (NSString *)getMessageStringAndAtList:(NSArray **)atlist emojiExtension:(void **)emojiExtension sessionID:(NSString*)sessionID;
#pragma clang diagnostic pop

- (NSAttributedString *)stringByExtractingAtMentionsToPasteboardItem:(nonnull NSPasteboardItem *)item;

- (NSArray*)fontStyleInfo;

/* attachment like "@name, #channel-name" should not parsed to plain-text to calculate the range of font-style when save to draft */
- (NSArray*)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment;

/// for telemetry
+ (ns_zoom_telemetry::ChatV2MessageEntityParams)messageEntityWithEntityV2:(ns_zoom_telemetry::ChatV2MessageEntityParams)entity fontStyleInfo:(NSArray<ZMMessageFontInfo *> *)fontStyleInfoList;
- (NSArray *)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment
                                  resultString:(NSAttributedString **)resultString
                                       atArray:(NSArray *)atArray;
- (NSArray *)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment
                                  resultString:(NSAttributedString **)resultString;
- (NSArray *)fontStyleInfoWithAttachmentParsed:(BOOL)needsParseAttachment
                                  resultString:(NSAttributedString **)resultString
                                ignoreFontSize:(BOOL)ignoreFontSize;
+ (NSAttributedString *)docIconAttsStringWithDocEntity:(ZMDocUrlEntity*)docEntity
                                            attributes:(NSDictionary *)attributes
                                            sourceType:(ZMFileSourceType)sourceType;
//custom emoji
+ (NSAttributedString *)customEmojiAttributedStringWithModel:(ZMCustomEmojiModel *)emojiModel attributes:(NSDictionary *)attributes;
+ (NSAttributedString *)customEmojiAttributedStringWithName:(NSString *)name fileID:(NSString *)fileID attributes:(NSDictionary *)attributes source:(ZMCustomEmojiSource)source;
+ (NSAttributedString *)customEmojiAttributedStringWithName:(NSString *)name fileID:(NSString *)fileID sessionID:(NSString *)sessionID messageID:(NSString *)messageID fileIndex:(NSInteger)fileIndex attributes:(NSDictionary *)attributes;
+ (NSMutableAttributedString *)plainStringWithCustomEmojiFromString:(NSString *)string fontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfoList source:(ZMCustomEmojiSource)source;

- (NSAttributedString *)filterInvalidAtMentionsForTargetSession:(NSString *)sessionId;

- (NSDictionary *)customEmojiAttributesAtIndex:(NSInteger)index;
- (NSMutableAttributedString *)attributedStringWithPlainCustomEmoji;
- (NSMutableAttributedString *)plainStringWithCustomEmoji;
- (NSMutableAttributedString *)attributedStringWithFixedCustomEmojiSize;
- (NSString *)stringWithPlainCustomEmoji;
- (NSInteger)customEmojiCount;
- (NSMutableAttributedString*)parsedAttributedStringToZMSupportedRTFWithFontSize:(CGFloat)fontSize sessionID:(NSString *)sessionID;

- (NSMutableAttributedString *)attributedStringWithFontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo
                                                  curAppFontSize:(CGFloat)appFontSize;
- (NSMutableAttributedString *)attributedStringWithFontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfoList
                                                   curAppFontSize:(CGFloat)appFontSize
                                                     usingRawList:(BOOL)usingRawList
                                                          source:(ZMCustomEmojiSource)source;
- (NSMutableAttributedString *)attributedStringWithFontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfoList
                                                   curAppFontSize:(CGFloat)appFontSize
                                                     usingRawList:(BOOL)usingRawList
                                                          source:(ZMCustomEmojiSource)source
                                                showDeletedEmoji:(BOOL)showDeletedEmoji;
- (NSMutableAttributedString *)attributedStringWithFontStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfoList
                                                   curAppFontSize:(CGFloat)appFontSize
                                                     usingRawList:(BOOL)usingRawList
                                                          source:(ZMCustomEmojiSource)source
                                                showDeletedEmoji:(BOOL)showDeletedEmoji
                                                       sourceType:(ZMFileSourceType)sourceType;
// provide public accessible RTF for 3rd apps
- (NSMutableAttributedString *)publicRTFFromZMStyleInfo:(NSArray<ZMMessageFontInfo*> *)fontStyleInfo sessionID:(NSString *)sessionID;

- (void)layoutAttchmentCellsWithMaxTextWidth:(CGFloat)maxWidth;

- (BOOL)checkMessageContainMentionAll;

- (nonnull NSString *)stringWithPlaintextAtMentions;

- (NSAttributedString *)attributedStringByTrimmingCharactersInSet:(NSCharacterSet *)characterSet;

/// In some occassions, whitespace(at beginning or end of content) adjacent to inline code is needed.
- (NSString *)stringByTrimmingUselessCharactersInSet:(NSCharacterSet *)characterSet;

/**
 * Compare two attributed strings by their content, ignoring trailing whitespace
 *
 * This method is useful when comparing draft content to avoid false inequality caused by
 * automatically appended trailing spaces (e.g., from appendSpaceAtTheEndOfSelectedRangeIfNeeded).
 *
 * @param otherAttributedString The attributed string to compare with
 * @return YES if the trimmed content is equal, NO otherwise
 */
- (BOOL)zm_isContentEqualToAttributedStringIgnoringTrailingWhitespace:(NSAttributedString *)otherAttributedString;

- (NSInteger)getComposeMessageLength;
- (NSArray<NSString *> *)zm_extractInsertLinksFromAttributedString;
- (NSArray<NSString *> *)zm_extractNSLinksFromAttributedString;
- (BOOL)zm_containInsertLinksFromAttributedString:(NSString *)link;
- (BOOL)zm_containsZMInsertLinkOrNSLink:(NSString *)link;

@end


@interface NSMutableAttributedString (ZMLink)

- (void)addZMLinkToolTip;
- (void)removeZMLinkToolTip;
- (void)removeLink;
- (void)removeCursor;

@end

@interface NSMutableAttributedString (Emoji)

- (void)changeEmojiStringFont;
- (void)changeEmojiStringFontForIMInputTextViewWithFontSize:(CGFloat)fontSize;
- (void)changeEmojiStringWitgEmojiOnlyFont:(NSFont *)emojiOnlyFont emojiCombinedWithTextFont:(NSFont *)emojiCombinedWithTextFont;
@end

@interface NSMutableAttributedString (Theme)

- (void)changePrismColorTheme:(ZMThemeName)theme appearance:(NSAppearance *)appearance;

@end


NS_ASSUME_NONNULL_END
