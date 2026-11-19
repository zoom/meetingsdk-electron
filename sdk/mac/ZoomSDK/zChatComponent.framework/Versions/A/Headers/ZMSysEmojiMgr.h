//
//  ZMSysEmojiMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/3/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <zChatComponent/ZMEmojiUnicodeData.h>
#import <zChatComponent/ZMEmojiModel.h>
#import <zChatComponent/ZMSysEmojiView.h>
#import <zChatComponent/ZMSkinToneButton.h>

@class ZMBaseView;
@class ZMCustomEmojiView;
@class ZMSysEmojiToolbarItemModel;
@class ZMSysEmojiMgr;

@protocol ZMSysEmojiMgrDelegate <ZMEmojiUnicodeDataDelegate>
- (void)sysEmojiMgrDidSelectedEmoji:(ZMEmojiModel *)emojiModel atIndex:(NSInteger)index;
- (void)sysEmojiMgrDidAddFavorite:(ZMEmojiModel *)emojiModel;
- (int)sysEmojiMgrDidGetSkinTone;
@optional
- (void)sysEmojiMgrDidEnterEditCustomEmoji;
- (NSString *)currentSelectedEmojiForSysEmojiMgr:(ZMSysEmojiMgr *)sysEmojiMgr;
@end

@interface ZMSysEmojiMgr : NSObject 
@property (nonatomic, weak) id<ZMSysEmojiMgrDelegate> delegate;
@property (nonatomic, assign) BOOL forceDarkMode;
@property (nonatomic, copy) NSString *currentSelectedEmoji;

//* Custom Emoji Related *//
@property (nonatomic, strong, readonly) NSString *currentSessionID;
@property (nonatomic, assign, readonly) ZMCustomEmojiSource customEmojiSource;
/// Resolved source the manager actually consults for custom emojis — derived
/// from `setSessionID:orEmojiSource:` (sessionID branch maps to its session's
/// source; emojiSource branch passes through). Exposed so subclasses /
/// external panels can call `customEmojisWithSource:` / `fetchCustomEmojiForSource:`
/// without hardcoding the meeting source.
@property (nonatomic, assign, readonly) ZMCustomEmojiSource emojiSourceToUse;
@property (nonatomic, assign) BOOL disableCustomEmoji;
/// Authoritative gate for whether custom emoji may be shown. Folds in
/// `disableCustomEmoji`, login state, and per-session policy; subclasses
/// override it (e.g. `ZMMTSysEmojiMgr` returns NO in meeting selected-emoji
/// mode). Consult this — not `disableCustomEmoji` alone — when deciding
/// whether to surface custom emoji.
- (BOOL)canShowCustomEmoji;
//* Custom Emoji Related *//

@property (nonatomic, strong, readonly) ZMEmojiUnicodeData *emojiUnicodeData;

- (instancetype)initWithDelegate:(id<ZMSysEmojiMgrDelegate>)delegate allowedEmojis:(NSArray<NSString *> *)allowedEmojis;
- (void)onSearch:(NSString*)searchString;
- (void)onTagSelected:(NSUInteger)tag;
- (void)addFavorite:(ZMEmojiModel *)emojiModel;
- (void)clickedItem:(ZMEmojiModel *)emojiModel;
- (void)resetEmojiView;
- (void)makeSearchFiledFirstResponder;
- (NSView*)getUnicodeEmojiView:(NSRect)inRect;
- (void)releaseEmojiView;
- (void)reloadSysEmojiData;
- (Class)emojiItemViewClass;
- (NSArray<ZMSysEmojiToolbarItemModel *> *)tableBarDataSource;
- (void)setSessionID:(NSString *)sessionID orEmojiSource:(ZMCustomEmojiSource)emojiSource;
- (void)createEmojiDataWhenLogin;
- (BOOL)shouldShowCompactTab;
- (BOOL)canShowCustomEmoji;
@end
