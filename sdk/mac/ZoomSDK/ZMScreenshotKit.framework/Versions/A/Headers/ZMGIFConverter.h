//
//  ZMGIFConverter.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMGIFConverter : NSObject

+ (void)convertMP4AtURL:(NSURL *)mp4URL
               toGIFURL:(NSURL *)gifURL
              frameRate:(NSUInteger)fps
                  scale:(CGFloat)scale
               progress:(nullable void(^)(double progress))progressBlock
             finalizing:(nullable void(^)(void))finalizingBlock
             completion:(void(^)(BOOL success, NSError * _Nullable error))completion;

/// Convenience method without progress
+ (void)convertMP4AtURL:(NSURL *)mp4URL
               toGIFURL:(NSURL *)gifURL
              frameRate:(NSUInteger)fps
                  scale:(CGFloat)scale
             completion:(void(^)(BOOL success, NSError * _Nullable error))completion;

/// Remove the GIF file and any hidden ImageIO temp files (e.g. ".Foo.gif-6d54") left behind on failure.
+ (void)cleanupGIFArtifactsForURL:(NSURL *)gifURL;

@end

NS_ASSUME_NONNULL_END
