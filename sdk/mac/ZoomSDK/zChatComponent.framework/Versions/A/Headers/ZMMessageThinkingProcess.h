//
//  ZMMessageThinkingProcess.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2026/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMessageThinkingStatus) {
    ZMMessageThinkingStatusNone,
    ZMMessageThinkingStatusThinking,
    ZMMessageThinkingStatusThinkingStopped,
    ZMMessageThinkingStatusThought,
    ZMMessageThinkingStatusGeneratingStopped,
    ZMMessageThinkingStatusDone,
    ZMMessageThinkingStatusError,
};

@interface ZMMessageThinkingProcess : NSObject

@property (nonatomic, readonly, copy) NSString *thinkingText;
@property (nonatomic, readonly, assign) ZMMessageThinkingStatus status;
@property (nonatomic, readonly, assign) BOOL canStop;

+ (nullable instancetype)thinkingProcessFromMessage:(void *)message;

@end

NS_ASSUME_NONNULL_END
