//
//  ZMForwardedMessagesResponse.h
//  zChatComponent
//
//  Created by Zoro.Fu on 2025/12/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMForwardedMessagesResponse : NSObject

@property (nonatomic, copy) NSString *reqId;
@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *noteMsgId;
@property (nonatomic, copy) NSArray *forwardedMsgs;


@end

NS_ASSUME_NONNULL_END
