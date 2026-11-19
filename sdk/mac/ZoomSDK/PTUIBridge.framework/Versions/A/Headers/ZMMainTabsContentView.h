//
//  ZMMainTabsContentView.h
//  ChatUI
//
//  Created by fistice on 2024/11/7.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <PTUIBridge/ZMTabItem.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ZMTabWidgetDragAction) {
    ZMTabWidgetDragActionNone = 0,
    ZMTabWidgetDragPopout = 1,
    ZMTabWidgetDragMergeBack = 2
};

@protocol ZMMainTabsContentViewDelegate <NSObject>
@optional
- (void)moveItemView:(NSView *)view toView:(NSView *)targetView;
/// Insert the item immediately BEFORE the target in the nav order. Unlike moveItemView:toView: (direction-dependent, toolbar live-drag), this always inserts before the target regardless of original positions, the semantic MorePanel reorder needs.
- (void)moveItemView:(NSView *)view beforeView:(NSView *)targetView;
/// Move the item to the end of its current section (pinned/unpinned) when there is no following item to insert before.
- (void)moveItemViewToSectionEnd:(NSView *)view;
/// Commit a More-panel item dropped onto the bar at the visible-slot index resolved during preview: pins it and inserts into the nav order so the deterministic relayout shows it there, displacing a non-active neighbor into overflow. The single commit point for the preview-only incoming-drag model (live drag does not mutate the model).
- (void)commitIncomingItem:(ZMTabItem *)item atVisibleIndex:(NSInteger)visibleIndex;
- (void)updateViewDraggingState:(NSView *)view isDraggingFromTab:(BOOL)isDraggingFromTab;
- (BOOL)isViewCanDrag:(NSView *)view;
- (void)draggingSessionEnd:(NSView *)view toView:(NSView *)targetView;
- (void)onTabDraggingMergeBack:(ZMTabItem *)tabItem;
- (void)onTabDraggingPopOut:(ZMTabItem *)tabItem;
- (BOOL)isTabCanPop:(ZMTabItem *)tabItem;
- (BOOL)isTabPopped:(ZMTabItem *)tabItem;
- (BOOL)isInMoreMenu;
- (ZMTabWidgetDragAction)checkpopOutTab:(NSDraggingSession *)session;
- (BOOL)isTemporaryTabItem:(ZMTabItem *)tabItem;

@end

@interface ZMMainTabsContentView : NSView <ZMTabItemDataDragSource>

@property (weak) id <ZMMainTabsContentViewDelegate> delegate;
@property (weak) ZMTabItemView *draggingView;
@end

NS_ASSUME_NONNULL_END
