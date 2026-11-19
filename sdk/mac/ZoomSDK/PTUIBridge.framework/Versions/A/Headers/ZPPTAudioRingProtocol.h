//
//  ZPPTAudioRingProtocol.h
//  SaasBeePTUIModule
//
//  Created by Justin Fang on 3/31/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZPPTAudioRingProtocol <NSObject>

- (BOOL)isRinging;
- (void)startRinging;
- (void)stopRinging;
- (void)stopRingWithoutClean;
- (void)onAudioChanged:(unsigned int)ret handle:(unsigned int)handle;
- (void)startRingingWithJid:(NSString*)jid; //[ZOOM-353886]

@end
