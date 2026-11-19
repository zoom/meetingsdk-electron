//
//  ZMTodoManager.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ZMTodoListDidChangeNotification;

@class ZMTodoEntry;
@class ZMCanvasItem;
@class ZMTodoFilter;

@interface ZMTodoManager : NSObject

+ (instancetype)sharedManager;

#pragma mark - Entries

@property (nonatomic, readonly) NSArray<ZMTodoEntry *> *allEntries;
@property (nonatomic, readonly) NSArray<ZMTodoEntry *> *openEntries;
@property (nonatomic, readonly) NSArray<ZMTodoEntry *> *doneEntries;

#pragma mark - CRUD

- (ZMTodoEntry *)addEntryWithCanvasItem:(ZMCanvasItem *)item;
- (ZMTodoEntry *)addEntryWithCanvasItem:(ZMCanvasItem *)item title:(nullable NSString *)title;
- (void)removeEntry:(ZMTodoEntry *)entry;
- (void)clearDoneEntries;

#pragma mark - Status

- (void)markDone:(ZMTodoEntry *)entry;
- (void)markOpen:(ZMTodoEntry *)entry;

#pragma mark - Ordering

- (void)moveEntry:(ZMTodoEntry *)entry toIndex:(NSInteger)index;

#pragma mark - Query

- (nullable ZMTodoEntry *)entryForCanvasItemID:(NSString *)canvasItemID;
- (nullable ZMCanvasItem *)canvasItemForEntry:(ZMTodoEntry *)entry;

#pragma mark - Filter

- (NSArray<ZMTodoEntry *> *)entriesMatchingFilter:(ZMTodoFilter *)filter;
- (NSInteger)countForFilter:(ZMTodoFilter *)filter;

#pragma mark - Tags

@property (nonatomic, readonly) NSArray<NSString *> *allTags;

- (void)addTag:(NSString *)tag;
- (void)removeTag:(NSString *)tag;
- (void)setTag:(nullable NSString *)tag forEntry:(ZMTodoEntry *)entry;

#pragma mark - Update

- (void)updateTitle:(NSString *)title forEntry:(ZMTodoEntry *)entry;
- (void)updateNote:(NSString *)note forEntry:(ZMTodoEntry *)entry;

#pragma mark - Persistence

- (void)save;
- (void)load;

@end

NS_ASSUME_NONNULL_END
