//
//  ZMGiphyMgr.h
//  SaasBeePTUIModule
//
//  Created by likevin on 7/20/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/zChatComponent-Swift.h>

#define HOT_GIPHY_NUM 30
#define SEARCH_GIPHY_NUM 30
#define MAX_DOWNLOAD_RETRY_COUNT 10

@class ZMPTGiphyData, ZMMessageAdapter, ZMGiphyView, ZMGiphyEmojiItemData;

@interface ZMGiphyMgr : NSObject <ZMCollectionViewDelegateWaterfallLayout>

@property(nonatomic,copy) NSString *currentSessionId;

/// Optional V2 hosting hook. When set, view-state notifications
/// (loading / normal / error) are routed to this `ZMGiphyView`
/// directly instead of `ZMStickerMgr.sharedInstance.emojiWindowController`.
/// V1 `ZMChatEmojiWindowController` keeps its existing behaviour by
/// leaving this nil — the V1 path continues to call into the singleton
/// emoji-window controller via `updateGiphyView:` / `isGiphyNormalView`.
/// V2's `ZMEmojiV2GifView` sets this to its embedded GiphyView before
/// kicking off `attach2GridView:` so updates land where it expects.
@property(nonatomic,weak) ZMGiphyView *hostGiphyView;

/// Snapshot of the items currently driving the attached collection view.
/// V2's Frequently Used "Trending GIFs" row consumes this instead of
/// owning a sibling `ZMGiphyMgr`, so a single network fetch backs both
/// the GIF tab and the trending strip.
@property(nonatomic,readonly,copy) NSArray<ZMGiphyEmojiItemData *> *currentGiphyDataItems;

/// `YES` when the current data is the hot list (default view), `NO` once
/// the user runs a search. Trending GIF consumers should ignore data
/// updates while this is `NO` so search results don't bleed into the
/// Frequently Used tab.
@property(nonatomic,readonly,assign) BOOL isShowingDefaultHotList;

/// Fires whenever `currentGiphyDataItems` changes — initial hot-list
/// load, search response, individual download completion. V2 consumers
/// (notably the Frequently Used trending row) hook this to refresh their
/// cached snapshot. V1 leaves this nil so behaviour is unchanged.
@property(nonatomic,copy,nullable) void (^dataDidChangeHandler)(void);

- (void)cleanUp;
- (void)initDefaultHotEmojis;
- (BOOL)downloadGiphy:(NSString*)giphyID andGiphyMsgGuid:(NSString*)giphyMsgGuid andSessionID:(NSString*)inSessionId;
- (void)attach2GridView:(id)inGridView;
- (BOOL)loadGiphyDataByString:(NSString*)string andGiphyNum:(NSUInteger)giphyNum;

- (void)updateGiphyDataWithMessageInfo:(ZMMessageAdapter*)msgInfo outGiphyData:(ZMPTGiphyData*)giphyData;
- (BOOL)downloadWithGiphyData:(ZMPTGiphyData*)giphyData;
@end
