//
//  ZMTodoListWindowController.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMTodoListWindowController : NSObject

+ (instancetype)sharedController;

- (void)showWindow;
- (void)hideWindow;
- (BOOL)isVisible;

@end

NS_ASSUME_NONNULL_END
