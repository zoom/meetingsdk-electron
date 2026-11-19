//
//  ZMMessageBaseProtocol.h
//  zChatBase
//
//  Minimal message model protocol for decoupling UI modules from zChatComponent's ZMMessageAdapter.
//

#ifndef ZMMessageBaseProtocol_h
#define ZMMessageBaseProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMMessageBaseProtocol <NSObject>

// Identity / routing
@property (nonatomic, copy, nonnull, readonly) NSString *m_msgID;
@property (nonatomic, copy, nullable, readonly) NSString *sessionID;

// Basic fields commonly used by UI
@property (nonatomic, copy, nullable, readonly) NSString *m_msgBody;
@property (nonatomic, copy, nullable, readonly) NSString *m_senderID;
@property (nonatomic, copy, nullable, readonly) NSString *m_senderName;
@property (nonatomic, retain, nullable, readonly) NSDate *m_timeStamp;

// Status helper (MeetingAssistantUI uses this)
@property (nonatomic, readonly) BOOL isSendFailMessage;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMMessageBaseProtocol_h */

