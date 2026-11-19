//
//  ZMPopoverController.h
//  ZMScreenshotKit
//
//  Created by javenlee on 2020/08/21.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZMPopoverAlignmentCenter,
    ZMPopoverAlignmentLeading,
    ZMPopoverAlignmentTrailing,
} ZMPopoverAlignment;

@interface ZMSCPopoverController : NSObject

@property (nullable, strong) NSViewController *contentViewController;
@property (nullable, strong) NSView *contentView;

@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, strong) NSColor *bgColor;

@property (nonatomic, assign) BOOL needShowArrow;
@property (nonatomic, assign) BOOL canBecomeKey;
@property (nonatomic, assign) BOOL autoClosePopover;
@property (nonatomic, assign) BOOL isAsChildWindow;

- (void)close;
- (BOOL)isVisible;

- (void)showRelativeToRect:(NSRect)positioningRect ofView:(NSView *)positioningView preferredEdge:(NSRectEdge)preferredEdge alignment:(ZMPopoverAlignment)alignment;

@end

NS_ASSUME_NONNULL_END
