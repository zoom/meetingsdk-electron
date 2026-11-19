//
//  ZMCanvasItemStore.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ZMCanvasItemStoreDidChangeNotification;

@class ZMCanvasItem;
@class ZMCaptureDocument;

@interface ZMCanvasItemStore : NSObject

+ (instancetype)sharedStore;

#pragma mark - Item Management

@property (nonatomic, readonly) NSArray<ZMCanvasItem *> *allItems;

- (ZMCanvasItem *)addItemWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (void)addExistingItem:(ZMCanvasItem *)item;
- (void)removeItem:(ZMCanvasItem *)item;
- (void)removeAllItems;
- (nullable ZMCanvasItem *)itemForID:(NSString *)itemID;

#pragma mark - Persistence

- (void)save;
- (void)load;
- (void)scheduleSave;

@end

NS_ASSUME_NONNULL_END
