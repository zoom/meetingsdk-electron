//
//  ZMVideoEventProtocol.h
//  ZoomSetting
//
//  Created by Vinson Wang on 2024/2/24.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMVideoEventProtocol <ZMRoutableObject>

@optional
- (void)onCameraStatusChanged:(unsigned int)value;

- (void)onCameraSelectedChanged;

- (void)onChangeMirror;

- (void)startPreview;

- (void)stopPreview;

- (void)updatePreview;

- (void)onVirtualBackgroundSettingStatusChanged;

@end

NS_ASSUME_NONNULL_END
