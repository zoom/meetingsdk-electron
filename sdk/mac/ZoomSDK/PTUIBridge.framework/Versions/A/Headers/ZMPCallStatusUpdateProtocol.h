//
//  ZMPCallStatusUpdateProtocol.h
//  PTUIBridge
//
//  Created by Michael Lin on 9/10/25.
//

#ifndef ZMPCallStatusUpdateProtocol_h
#define ZMPCallStatusUpdateProtocol_h

@protocol ZMPCallStatusUpdateProtocol <NSObject>
@optional

- (void)onPhoneCallGenerate;
- (void)onActiveCallTerminate;

- (void)onPhoneCallStatusChanged;
- (void)onAutoStartMyNoteWithCallId:(nullable NSString *)callID;

@end

#endif /* ZMPCallStatusUpdateProtocol_h */
// ZMEventPosterFor(ZMPCallStatusUpdateProtocol)
