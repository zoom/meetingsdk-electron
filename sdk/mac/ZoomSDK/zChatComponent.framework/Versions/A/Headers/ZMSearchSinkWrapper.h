//
//  ZMSearchSinkWrapper.h
//  zChatComponent
//
//  Created by Yong Zhou on 10/27/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * ZMSearchSinkWrapper - Objective-C wrapper for managing ZMSearchSink lifecycle
 * This class provides a convenient way to manage the C++ ZMSearchSink instance from Objective-C code.
 */
@interface ZMSearchSinkWrapper : NSObject

+ (instancetype)sharedInstance;
/**
 * Register the search sink to receive search callbacks
 */
- (void)registerSearchSink;
/**
 * Unregister the search sink
 */
- (void)unregisterSearchSink;

- (void)setSinkDelegate:(nullable ns_zoom_messager::SearchMgrUICallBack*)sink;

@end

NS_ASSUME_NONNULL_END

