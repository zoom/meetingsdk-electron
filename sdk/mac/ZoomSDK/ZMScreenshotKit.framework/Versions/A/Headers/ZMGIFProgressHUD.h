//
//  ZMGIFProgressHUD.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGIFProgressHUD : NSPanel

+ (instancetype)createHUD;

- (void)showWithFileName:(NSString *)fileName;
- (void)showWithFileName:(NSString *)fileName relativeToWindow:(nullable NSWindow *)parentWindow;
- (void)showWithFileName:(NSString *)fileName centeredOnScreen:(nullable NSScreen *)screen;
- (void)showWithFileName:(NSString *)fileName centeredOnScreen:(nullable NSScreen *)screen yOffset:(CGFloat)yOffset;
- (void)showFinalizingWithFileName:(NSString *)fileName centeredOnScreen:(nullable NSScreen *)screen;
- (void)showFinalizingWithFileName:(NSString *)fileName centeredOnScreen:(nullable NSScreen *)screen yOffset:(CGFloat)yOffset;
- (void)updateProgress:(double)progress;
- (void)dismissWithSuccess:(BOOL)success;

@end

NS_ASSUME_NONNULL_END
