//
//  ZMPSRenderStatusProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2026/5/11.
//

#ifndef ZMPSRenderStatusProtocol_h
#define ZMPSRenderStatusProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMPSRenderStatusProtocol <NSObject>

@optional
- (void)psRenderFrameSizeChanged;

@end

#endif /* ZMPSRenderStatusProtocol_h */
