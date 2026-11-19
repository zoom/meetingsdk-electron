//
//  ZMHTabViewDelegate.h
//  ChatUI
//
//  Created by Kay Fu on 10/30/24.
//  Copyright © 2024 Zoom. All rights reserved.
//

@class ZMHTabView;
@protocol ZMHTabViewDelegate <NSObject>
@optional
- (void)tabView:(ZMHTabView *)tabView willSelectItem:(ZMTabItem *)item;
- (void)tabView:(ZMHTabView *)tabView willShowItem:(ZMTabItem *)item;
- (void)tabView:(ZMHTabView *)tabView didShowItem:(ZMTabItem *)item updateCache:(BOOL)updateCache;
- (void)tabView:(ZMHTabView *)tabView willDismissItem:(ZMTabItem *)item;
- (void)tabView:(ZMHTabView *)tabView didDismissItem:(ZMTabItem *)item;
- (BOOL)tabView:(ZMHTabView *)tabView availabilityOfItem:(ZMTabItem *)item;
- (void)tabView:(ZMHTabView *)tabView showUpgradeDialogForItem:(ZMTabItem *)item;
- (void)tabViewDidChangeTabItems;
- (void)tabViewWillMoveItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker;
- (void)tabViewWillMoveItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker toLast:(BOOL)toLast;
- (void)tabViewDidMoveItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker;
- (void)tabViewDidMoveItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker needSave:(BOOL)needSave;
- (void)tabViewWillMoveItem:(NSString *)targetStr toItem:(NSString *)toItemString toLeft:(BOOL)toLeft;
@end
