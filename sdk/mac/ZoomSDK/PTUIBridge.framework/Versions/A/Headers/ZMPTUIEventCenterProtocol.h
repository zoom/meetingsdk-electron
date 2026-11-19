//
//  ZMPTUIEventCenterProtocol.h
//  PTUIBridge
//
//  Created by fistice on 2025/2/5.
//

#ifndef ZMPTUIEventCenterProtocol_h
#define ZMPTUIEventCenterProtocol_h

@protocol ZMPTUIEventCenterProtocol <NSObject>
@optional
- (void)machineWillSleep;
- (void)machineDidWake;
- (void)chatUIDidLoad;
- (void)sipUIDidLoad;
@end
#endif /* ZMPTUIEventCenterProtocol_h */
