//
//  ZMTodoListViewController.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

@class ZMTodoFilter;

NS_ASSUME_NONNULL_BEGIN

@interface ZMTodoListViewController : NSViewController

@property (nonatomic, strong, nullable) ZMTodoFilter *activeFilter;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
