//
//  ZMPSUploadResult+CPP.h
//  ZoomSetting
//
//  Created by Michael Lin on 2025/12/1.
//

#import <Foundation/Foundation.h>
#import "ZMPSUploadResult.h"
#import <zPSApp/product/IPSAsyncRecording.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSUploadResult (CPP)

- (instancetype)initWithCppResult:(const ps::PSAsyncRecordingUploadResult&)result;

@end

NS_ASSUME_NONNULL_END
