//
//  ZMPinWindowManager.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ZMPinWindowManagerDidChangeNotification;

@class ZMPinWindow;
@class ZMCaptureDocument;
@class ZMCanvasItem;

@interface ZMPinWindowManager : NSObject

+ (instancetype)sharedManager;

#pragma mark - Window Management

- (ZMPinWindow *)showWindowForItem:(ZMCanvasItem *)item onScreen:(NSScreen *)screen;
- (void)hideWindowForItem:(ZMCanvasItem *)item;
- (void)removePinWindow:(ZMPinWindow *)window;
- (void)removeAllPinWindows;

@property (nonatomic, readonly) NSArray<ZMPinWindow *> *activeWindows;

#pragma mark - Backward-Compatible API

@property (nonatomic, readonly) NSArray<ZMPinWindow *> *pinnedWindows;

#pragma mark - Arrange

- (void)arrangeLeftToRight;
- (void)arrangeTopToBottom;
- (void)arrangeCascade;

@end

NS_ASSUME_NONNULL_END
