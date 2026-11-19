//
//  ZMCCICallStatusProtocol.h
//  PTUIBridge
//
//  Created by Francis Zhuo on 2025/12/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMCCICallStatusProtocol <NSObject>
@optional
- (void)onCCICallStatusChanged;
@end

NS_ASSUME_NONNULL_END
