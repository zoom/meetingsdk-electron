//
//  ZMIMSinkProtocol.h
//  zChatBase
//
//  Moved from zChatComponent to zChatBase to avoid cyclic module deps.
//

#ifndef ZMIMSinkProtocol_h
#define ZMIMSinkProtocol_h

#import <Foundation/Foundation.h>

@protocol ZMIMSinkProtocol <NSObject>
@optional
- (void)zmIMMessageHelper_registerPhoneUISink;
- (void)zmIMMessageHelper_unregisterPhoneUISink;

- (void)zmIMMessageHelper_registerPreMeetingUISink;
- (void)zmIMMessageHelper_unregisterPreMeetingUISink;

- (void)registerPTWebserviceSink;
- (void)unregisterPTWebserviceSink;

- (void)zmIMMessageHelper_registerSipVoiceMailChatIntegrationSink;

@end

#endif /* ZMIMSinkProtocol_h */
