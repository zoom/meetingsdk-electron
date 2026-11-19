//
//  ZMGIFConversionManager.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ZMGIFConversionProgressNotification;
extern NSNotificationName const ZMGIFConversionDidFinishNotification;
extern NSNotificationName const ZMShowRecordSettingsNotification;

@interface ZMGIFConversionManager : NSObject

+ (instancetype)sharedManager;

- (void)convertMP4AtURL:(NSURL *)mp4URL
               toGIFURL:(NSURL *)gifURL
              frameRate:(NSUInteger)fps
                  scale:(CGFloat)scale;

- (void)convertMP4AtURL:(NSURL *)mp4URL
               toGIFURL:(NSURL *)gifURL
              frameRate:(NSUInteger)fps
                  scale:(CGFloat)scale
               onScreen:(nullable NSScreen *)screen;

@property (nonatomic, readonly) BOOL hasActiveConversions;
@property (nonatomic, readonly) NSUInteger activeConversionCount;

@end

NS_ASSUME_NONNULL_END
