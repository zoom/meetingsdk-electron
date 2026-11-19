//
//  ZMTabItem.h
//  ZoomDemo
//
//  Created by Huxley Yang on 10/01/2018.
//  Copyright © 2018 Yang. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <PTUIBridge/ZMUnreadView.h>
#import <ZoomUnit/ZoomUnit.h>
#import <PTUIBridge/IZMMainTabsData.h>
#import <PTUIBridge/ZMPTTabNavigationProtocol.h>
#import <Prism/ZMTabItemData.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMTabItemView, ZMTabItem;
@protocol ZMBaseTabsDataProtocol;

@protocol ZMTabItemContentDelegate <NSObject>

- (void)tabItemDidChangeEffectiveStyle:(ZMTabItem *)item;
- (void)onRightMouseDownTabItem:(ZMTabItem *)itemA event:(NSEvent *)event;

- (NSString *)getAccessibilityValue:(ZMTabItem *)item;

@optional
- (void)tabItemDidUpdateIcon:(ZMTabItem *)item;
@end

//MARK: - ZMTabItem
@interface ZMTabItem : ZMTabItemData

@property (copy) NSString *toolTip;
@property (nonatomic, assign) NSInteger tag;

@property (nonatomic, weak) id<ZMBaseTabsDataProtocol,ZMPTTabNavigationProtocol> zmtabItemDelegate;
@property (nonatomic, weak) id <ZMTabItemContentDelegate> contentDelegate;

@property (nonatomic, assign) BOOL isLine;
@property (nonatomic, assign) BOOL isEmpty;
@property (nonatomic, assign) BOOL isSetting;
@property (nonatomic, assign) BOOL isPopout;
@property (nonatomic, assign) BOOL isAlreadyPopout;
@property (nonatomic, assign) BOOL isRegisterTab;
@property (nonatomic, assign) BOOL isZappTab;
@property (nonatomic, assign) BOOL zAppIconReady;

+ (instancetype)itemWithText:(NSString *)text image:(NSImage *)image identifier:(NSString *)identifier isPin:(BOOL)isPin;
+ (instancetype)itemWithText:(NSString *)text image:(NSImage *)image;
+ (instancetype)lineItem;
+ (instancetype)emptyItem;

- (ZMTabItemView *)itemView;
- (ZMUnreadStyle)effectiveStyle;

- (void)notifyIconUpdated;

- (BOOL)isNewBadgeConsumed;
- (void)markNewBadgeConsumed;

@end

//MARK: - ZMTabItemView
@interface ZMTabItemView : PZPTrackingButton

@property (nonatomic, weak, readonly) ZMTabItem *tabItem;
@property (nonatomic, strong, readonly) ZMUnreadView *unreadView;
@property (nonatomic, strong, readonly) __kindof NSView *informativeView;

@property (nonatomic, assign) BOOL selected;

@property (nonatomic, assign) BOOL isDefaultItem;
@property (nonatomic, assign) BOOL isMoreItem;

@property (nonatomic, strong, nullable) NSImage *capture;
@property (nonatomic, assign) CGFloat popoutStartOffSetX;

- (instancetype)initWithTabItem:(ZMTabItem *)tabItem;
- (void)setupSubviews;
- (CGFloat)getFittingWidth;
- (CGFloat)getFittingHeight;
- (NSRect)draggingTrackingRect;

@end

NS_ASSUME_NONNULL_END
