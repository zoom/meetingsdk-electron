//
//  ZMRecordingService.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMRecordingServiceState) {
    ZMRecordingServiceStateIdle = 0,
    ZMRecordingServiceStateRecording,
    ZMRecordingServiceStateStopped
};

@class ZMRecordConfig;

@protocol ZMRecordingServiceDelegate <NSObject>
@optional
- (void)recordingDidStart:(BOOL)success error:(NSError * _Nullable)error;
- (void)recordingDidFinish:(NSURL * _Nullable)outputURL error:(NSError * _Nullable)error;
- (void)recordingProgressUpdate:(NSTimeInterval)duration;
- (void)recordingStateUpdate:(ZMRecordingServiceState)state;
@end

@protocol ZMRecordingServicing <NSObject>
@property (nonatomic, weak) id<ZMRecordingServiceDelegate> delegate;
@property (nonatomic, readonly) ZMRecordingServiceState recordingState;
@property (nonatomic, readonly) NSTimeInterval currentDuration;

- (BOOL)startRecordingWithConfig:(ZMRecordConfig *)config;
- (void)stopRecording;
- (void)cancelRecordingAndDeleteFile;
@end

NS_ASSUME_NONNULL_END


