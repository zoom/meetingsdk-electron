//
//  ZMEmojiUnicodeData.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/11/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMEmojiModel.h>

#define FAVORITE_EMOJI_MAX_COUNT 16

extern NSString *FavoriteEmojiKey(ZMCustomEmojiSource source);
@class ZMEmojiUnicodeData;

@protocol ZMEmojiUnicodeDataDelegate <NSObject>
@optional
- (BOOL)canShowTWFlagEmoji;
- (ZMCustomEmojiSource)emojiSourceForEmojiUnicodeData:(ZMEmojiUnicodeData *)unicodeData;
- (BOOL)isCustomEmojiDisabledForEmojiUnicodeData:(ZMEmojiUnicodeData *)unicodeData;
@end

@interface ZMEmojiUnicodeData : NSObject

@property (nonatomic, retain, readonly) NSMutableArray<ZMEmojiModel *> *frequentArray;
@property (nonatomic, retain, readonly) NSMutableArray<ZMEmojiModel *> *frequentWithoutCustomEmojiArray;

//unicode emoji for more emoji infomation,pls refer to https://www.unicode.org/Public/17.0.0/emoji/emoji-test.txt
//In the website you can learn more about what're unqulified/mini-qulified/fully qulified emoji.
//
// Note: scenario membership (which emojis are allowed to show / send) is intentionally
// kept private — query it through `isEmojiAllowedToShow:` / `isEmojiAllowedToSend:` /
// `unicodeForSendAllowedEmojiName:`. Internally we store either a per-instance positive
// allow-list (meeting / huddle) or no per-instance set at all (chat / OldChat — those
// scenarios consult the shared global `ZMEmojiStorage.shared.systemUnsupportedUnicodeSet`
// as a tiny deny list, saving ~50 KB vs. holding a positive system-supported set).

@property (nonatomic, weak) id<ZMEmojiUnicodeDataDelegate> delegate;

- (void)initDataWithAllowedEmojis:(NSArray<NSString *> *)allowedEmojis;
- (BOOL)shouldShowCompactTab;
+ (NSArray *)skinToneEmojiArray;
- (ZMCustomEmojiSource)currentCustomEmojiSource;
- (NSArray *)categoryArrayWithCustomEmoji:(BOOL)withCustomEmoji;
- (void)scheduleSaveFavoriteEmojiList;
/// Get the selected emojis setting by admin
- (NSArray<ZMEmojiModel *> *)selectedEmojiStringArray;
- (BOOL)isEmojiAllowedInSelectedEmoji:(NSString *)emoji;
- (BOOL)isEmojiNameAllowedInSelectedEmoji:(NSString *)emoji;
- (NSMutableArray<ZMEmojiModel *> *)getFrequentMutableArray;
- (NSArray<ZMEmojiModel *> *)getLottieArray;
- (NSArray<ZMEmojiModel *> *)getEmojiArrayByCategory:(NSString*)category;

/// All system-unicode `ZMEmojiModel`s allowed in the current scenario (a flat
/// concatenation of every category's filtered model list). Custom emojis are
/// **not** included — fetch those via `ZMCustomEmojiManager`. Use this for
/// full-scan operations like substring search; for per-category enumeration
/// prefer `getEmojiArrayByCategory:`.
///
/// Replaces the legacy `unicodeEmojiName2ModelMap.allValues` pattern. Each base
/// model appears exactly once (skin-tone variants are not separate entries — get
/// them via `-[ZMEmojiModel unicodeEmojiAtToneIndex:]`).
- (NSArray<ZMEmojiModel *> *)allScenarioUnicodeEmojiModels;
- (void)addFavorite:(ZMEmojiModel *)model;
- (void)removeFavoriteCustomEmojiWithFileID:(NSString *)fileID;
- (BOOL)contains1CharacterEmojiStr:(NSString *)emojiStr;
- (NSString *)tryReplaceCusEmojiWithSystemEmoji:(NSString *)emojiStr;
- (NSArray<ZMEmojiModel *> *)availableFrequentlyUsedEmojiWithCustomEmoji:(BOOL)withCustomEmoji;
- (void)cleanUp;

- (BOOL)isEmojiAllowedToShow:(NSString *)emoji;
- (BOOL)isEmojiAllowedToSend:(NSString *)emoji;

/// Resolve a `:emoji_name:` (incl. skin-tone variants like `:thumbsup_tone3:`) to
/// its unicode form, gated by the scenario's send-allow rules. Returns nil when
/// the name is unknown or the resolved unicode is not allowed to be sent in the
/// current scenario. This is the canonical replacement for the previous
/// `[emojiUnicodeData.emojiName2UnicodeMap objectForKey:name]` pattern — it does
/// the lookup in one step against `ZMEmojiStorage.shared.emojiName2UnicodeMap`
/// without materialising any per-instance dictionary.
- (nullable NSString *)unicodeForSendAllowedEmojiName:(NSString *)name;

- (NSMutableArray<NSString *> *)convertToEmojiStringWithModelArray:(NSArray<ZMEmojiModel *> *)emojiModelArr;
- (NSMutableArray<ZMEmojiModel *> *)convertToModelWithEmojiStringArray:(NSArray<NSString *> *)emojiStrArr;

@end
