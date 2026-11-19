//
//  ZMDeviceStatusHelper.h
//  ZoomSetting
//
//  Created by Justin on 8/28/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMDeviceStatusHelper : NSObject

+ (instancetype)shared;
- (void)startup;
- (void)cleanup;
- (void)onAudioChanged:(unsigned int)value handle:(unsigned int)handle;
- (void)onMicStatusChanged:(unsigned int)value;
- (void)onSpeakerStatusChanged:(unsigned int)value;
- (void)onCameraStatusChanged:(unsigned int)value;
- (void)onMicSelectedChanged;
- (void)onSpeakerSelectedChanged;

@end
