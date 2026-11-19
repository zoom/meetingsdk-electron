//
//  ZMEmojiViewItem.h
//  ZoomUnit
//
//  Created by Mario Rao on 2023/7/19.
//

#import <Cocoa/Cocoa.h>
#import <zChatComponent/ZMSysEmojiItemView.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMEmojiViewItem : NSCollectionViewItem

@property (nonatomic, readonly) __kindof ZMSysEmojiItemView *contentView;
@property (nonatomic) BOOL isHovered;

@property (nonatomic, copy) void (^itemDidClick)(ZMEmojiModel *model);
@property (nonatomic, copy) NSString *(^accessibilityLabelString)(void);

/// Routes a VoiceOver activation (VO+Space / Space / Return reaching the cell's
/// -accessibilityPerformPress) to the same dispatch a mouse click uses: the
/// `itemDidClick` block when set, otherwise the enclosing collection view's
/// `-collectionView:didSelectItemsAtIndexPaths:` delegate call. V2 emoji items
/// call this from -accessibilityPerformPress so that, with
/// `ZMEmojiHoverableCollectionView` suppressing selection-follows-VoiceOver,
/// cursor movement no longer sends an emoji — only explicit activation does.
/// Returns YES when an activation was dispatched.
- (BOOL)zmDispatchAccessibilityActivation;

@end

@interface ZMMTEmojiViewItem: ZMEmojiViewItem

@end

NS_ASSUME_NONNULL_END
