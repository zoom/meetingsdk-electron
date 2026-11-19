//
//  IZMPTClipsHelperAdapter.h
//  PTUIBridge
//
//  Protocol for Clips helper adapter used by PTUI Clips encapsulation.
//  ChatUI's ZMClipsHelperAdapter conforms; PTUI wrapper forwards via NSClassFromString.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#include "zPSApp/define/PSDefine.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol IZMPTClipsHelperAdapter <NSObject>

- (void)registerSinkIfNeeded;
- (BOOL)internalLaunchZoomClips:(NSString *)path dbKey:(NSString *)dbKey preload:(BOOL)preload type:(NSUInteger)type;
- (BOOL)launchZoomClips;

#ifdef __cplusplus
- (BOOL)launchZoomClipsWithRecordingToken:(ps::PSAsyncRecordingActionToken)token;
- (void)terminateActiveZoomClipsInstance:(ps::PSTerminateReason)reason;
#endif

- (BOOL)hasZoomClipsInstance;
- (void)sendCustomMessageToPS:(NSString *)message;

@end

NS_ASSUME_NONNULL_END
