//
//  ZMEmojiHoverableCollectionView.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/20.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMEmojiModel, ZMEmojiHoverableCollectionView, ZMEmojiViewItem;

@protocol ZMEmojiHoverableCollectionViewDelegate <NSCollectionViewDelegate>
@optional
- (BOOL)disableNavigationUpAndDownForEmojiCollectionView:(ZMEmojiHoverableCollectionView *)collectionView;
///default value is 8.
- (NSInteger)numberOfItemsInLineForEmojiCollectionView:(ZMEmojiHoverableCollectionView *)collectionView;
/// Optional per-section override for grids whose sections have different column counts.
- (NSInteger)emojiCollectionView:(ZMEmojiHoverableCollectionView *)collectionView
     numberOfItemsInLineForSection:(NSInteger)section;
- (void)emojiCollectionView:(ZMEmojiHoverableCollectionView *)collectionView didSelectModelByKeyboard:(ZMEmojiModel *)emojiModel;
/// Keyboard (Space / Return) confirm on the currently hovered cell, delivered by
/// index path. Preferred over -emojiCollectionView:didSelectModelByKeyboard: for
/// heterogeneous grids (e.g. the V2 Frequently Used tab) whose cells aren't all
/// `ZMEmojiModel` — the receiver maps the index path to its own model/action and
/// dispatches. When implemented it takes priority over the model variant.
- (void)emojiCollectionView:(ZMEmojiHoverableCollectionView *)collectionView didConfirmSelectionAtIndexPath:(NSIndexPath *)indexPath;
@end

@interface ZMEmojiHoverableCollectionView : NSCollectionView

@property (nonatomic, assign) BOOL isTrackingContent;
@property (nonatomic, assign) BOOL forceAcceptFirstResponderAndKeyView;
/// Default `NO`: when VoiceOver is running the view hands arrow / Space / Return
/// to NSCollectionView's own VoiceOver handling. Set `YES` to keep driving the
/// hover-based keyboard navigation even under VoiceOver — plain arrow keys move
/// the hovered cell and post a VoiceOver focus change so the VO cursor (black
/// box) follows and reads each cell, and Space / Return confirm the hovered
/// cell. Opt-in so legacy emoji surfaces keep their VoiceOver behavior.
@property (nonatomic, assign) BOOL enableVoiceOverKeyboardNavigation;

- (void)resetAllItemHoverStatus;
- (ZMEmojiModel *)currentHoveredEmojiModel;
- (NSIndexPath *)currentHoveredIndexPath;
- (NSArray<ZMEmojiViewItem *> *)visibleItemsInCurrentFrame;
- (ZMEmojiViewItem *)firstVisibleItem;
- (NSIndexPath *)firstVisibleIndexPathAndAllVisibleItems:(NSArray<ZMEmojiViewItem *> **)resultVisibleItems;

@end

NS_ASSUME_NONNULL_END
