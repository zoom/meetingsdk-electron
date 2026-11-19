//
//  ZMTodoItemCellView.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

@class ZMTodoEntry;
@class ZMCanvasItem;

NS_ASSUME_NONNULL_BEGIN

@interface ZMTodoItemCellView : NSTableCellView

@property (nonatomic, copy, nullable) void (^checkboxToggled)(ZMTodoEntry *entry);

- (void)configureWithEntry:(ZMTodoEntry *)entry canvasItem:(nullable ZMCanvasItem *)canvasItem;

@end

NS_ASSUME_NONNULL_END
