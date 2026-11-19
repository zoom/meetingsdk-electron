//
//  ZMSettingRingToneHelper.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2025/2/24.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingRingToneHelper : NSObject

+ (instancetype)shared;

- (BOOL)isDownloading;
- (void)retryDownload;
- (void)checkUpdate;
- (void)updateRingToneResourcePath;

- (void)onRingtoneCheckUpdated:(NSString*)lastVersion
                   downloadUrl:(NSString*)downloadUrl
                     requestId:(NSString*)requestId
                        result:(NSInteger)result;

@end

NS_ASSUME_NONNULL_END
