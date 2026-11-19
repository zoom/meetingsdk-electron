//
//  ZMLegacyRecorderService.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>
#import "ZMRecordingService.h"

@class ZMScreenRecorder, ZMRecordConfig;

@interface ZMLegacyRecorderService : NSObject <ZMRecordingServicing>

@property (nonatomic, weak) id<ZMRecordingServiceDelegate> delegate;

- (instancetype)initWithRecorder:(ZMScreenRecorder *)recorder NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end


