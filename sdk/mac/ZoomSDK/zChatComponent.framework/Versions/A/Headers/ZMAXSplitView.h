//
//  ZMAXSplitView.h
//  zChatComponent
//
//  Created by groot.ding on 4/17/23.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMAXOrderDelegate <NSObject>

- (NSArray<id<NSAccessibilityElement>> *)adjustedChildrenInNavigationOrder:(NSArray<id<NSAccessibilityElement>> *)children;

@end

@interface ZMAXSplitView : NSSplitView

@property(nonatomic,retain) NSColor* dividerDrawColor;

@property (nonatomic,assign) BOOL isMouseDown;

@property (weak) id <ZMAXOrderDelegate> AXOrderDelegate;

@end

NS_ASSUME_NONNULL_END
