//
//  ZMHTabView.h
//  NewUI
//
//  Created by Huxley Yang on 2018/1/17.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <PTUIBridge/ZMTabWidgets.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN
@class ZMTabItem;
@protocol ZMHTabViewDelegate;

@protocol ZMHTabViewLifecycleDelegate <NSObject>
@optional
- (void)tabViewControllerViewWillAppear:(ZMHTabView *)tabViewController;
- (void)tabViewControllerViewDidAppear:(ZMHTabView *)tabViewController;
- (void)tabViewControllerViewWillDisappear:(ZMHTabView *)tabViewController;
- (void)tabViewControllerViewDidDisappear:(ZMHTabView *)tabViewController;
- (void)tabViewControllerViewDidLayout:(ZMHTabView *)tabViewController;
@end

@interface ZMHTabView : ZMBaseViewController
{
    NSMutableArray *_tabItems;
    ZMTabItem *_selectedTabItem;
}

@property (nonatomic, assign) BOOL allowEmptySelection;
@property (readonly) NSUInteger indexOfSelectedTabItem;
@property (readonly) NSRect contentRect;

- (void)selectTabItemAtIndex:(NSUInteger)index;//deselect item when Index out of bounds
- (void)selectTabItem:(ZMTabItem *)item;
- (void)selectTabItem:(ZMTabItem *)item updateCache:(BOOL)updateCache;
- (void)moveTabViewItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker;
- (void)moveTabViewItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(nullable id)maker toLast:(BOOL)toLast;
- (void)moveTabViewItemAtIndex:(NSUInteger)indexA toIndex:(NSUInteger)indexB maker:(id)maker toLast:(BOOL)toLast slim:(BOOL)slim;
- (void)moveTabViewItem:(ZMTabItem *)itemA toItem:(ZMTabItem *)itemB inFront:(BOOL)inFront;
- (BOOL)isAvailabeTabItemAtIndex:(NSInteger)index;
- (void)relayoutWith:(ZMTabItem *)tabItem customizedView:(NSView *)customizedView;
- (void)showUpgradeDialogForTabItemAtIndex:(NSInteger)index;

@property (nullable, weak) IBOutlet id<ZMHTabViewDelegate> delegate;
@property (nullable, weak) id<ZMHTabViewLifecycleDelegate> lifecycleDelegate;

@end
NS_ASSUME_NONNULL_END
