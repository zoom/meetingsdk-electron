//
//  ZMCanvasItem.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

@class ZMCaptureDocument;
@class ZMPinWindow;

NS_ASSUME_NONNULL_BEGIN

@interface ZMCanvasItem : NSObject <NSSecureCoding>

@property (nonatomic, copy, readonly) NSString *itemID;
@property (nonatomic, strong) NSDate *createdDate;
@property (nonatomic, strong) ZMCaptureDocument *document;
@property (nonatomic, assign) NSRect lastScreenRect;
@property (nonatomic, strong, readonly) NSImage *thumbnail;

@property (nonatomic, weak, nullable) ZMPinWindow *activeWindow;

/// Whether this item is stored in persistent storage (ZMCanvasItemStore).
/// Transient items (e.g. pure Pin captures) have this set to NO.
@property (nonatomic, assign) BOOL persisted;

/// The ZOOM account that created this item (nil for legacy data).
@property (nonatomic, copy, readonly, nullable) NSString *accountId;

- (instancetype)initWithDocument:(ZMCaptureDocument *)document screenRect:(NSRect)screenRect;
- (instancetype)init NS_UNAVAILABLE;

- (void)invalidateThumbnail;

/// Returns the account-scoped directory where individual image files are stored.
+ (NSString *)imageStorageDirectory;

/// Writes the item's original image to disk as a JPEG (no-op if already persisted).
/// Call this after creating a new item before the item is saved.
- (void)persistImageIfNeeded;

/// Deletes the item's image file from disk. Call this when removing the item.
- (void)removeImageFromDisk;

/// Releases the in-memory `document` if it can be reloaded from disk.
/// Call after closing the pin window so the full NSImage is reclaimable.
- (void)releaseDocumentIfUnused;

@end

NS_ASSUME_NONNULL_END
