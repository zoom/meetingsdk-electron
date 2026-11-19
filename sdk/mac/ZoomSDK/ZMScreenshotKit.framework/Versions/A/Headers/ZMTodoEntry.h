//
//  ZMTodoEntry.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMTodoStatus) {
    ZMTodoStatusOpen = 0,
    ZMTodoStatusInProgress,
    ZMTodoStatusDone,
};

@interface ZMTodoEntry : NSObject <NSSecureCoding>

@property (nonatomic, copy, readonly) NSString *entryID;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *note;
@property (nonatomic, assign) ZMTodoStatus status;
@property (nonatomic, assign) NSInteger sortOrder;
@property (nonatomic, strong) NSDate *createdDate;
@property (nonatomic, strong, nullable) NSDate *completedDate;

/// The ID of the associated ZMCanvasItem.
@property (nonatomic, copy) NSString *canvasItemID;

/// User-defined tag for categorization (e.g. "Work", "Bug").
@property (nonatomic, copy, nullable) NSString *tag;

/// The ZOOM account that created this entry (nil for legacy data).
@property (nonatomic, copy, readonly, nullable) NSString *accountId;

- (instancetype)initWithCanvasItemID:(NSString *)canvasItemID;
- (instancetype)initWithCanvasItemID:(NSString *)canvasItemID title:(nullable NSString *)title;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
