//
//  ZMAICMgr.h
//  ZoomAIC
//
//  Created by Howie Xu on 1/14/24.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAICAppViewController;

@interface ZMAICMgr : NSObject

@property (nonatomic, retain) ZMAICAppViewController *webViewController;

- (void)addViewToParentView:(NSView *)parentView;

- (NSView *)contentView;

- (void)loadAppWithMakeFirstResponder:(BOOL)on inMeeting:(BOOL)inMeeting;

- (void)cleanUp;

@end

NS_ASSUME_NONNULL_END
