//
//  ZMTodoFilter.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMTodoFilterType) {
    ZMTodoFilterTypeAll = 0,
    ZMTodoFilterTypeOpen,
    ZMTodoFilterTypeCompleted,
    ZMTodoFilterTypeTag,
};

@interface ZMTodoFilter : NSObject

@property (nonatomic, assign) ZMTodoFilterType type;
@property (nonatomic, copy, nullable) NSString *tag;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, strong, nullable) NSImage *icon;
@property (nonatomic, strong, nullable) NSColor *tintColor;

+ (instancetype)allFilter;
+ (instancetype)openFilter;
+ (instancetype)completedFilter;
+ (instancetype)filterWithTag:(NSString *)tag;

@end

NS_ASSUME_NONNULL_END
