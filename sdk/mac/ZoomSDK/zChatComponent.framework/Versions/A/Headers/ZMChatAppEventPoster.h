//
//  ZMChatAppEventPoster.h
//  zChatComponent
//
//  Created by Devl on 08/05/2026.
//  Copyright © 2026 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMChatAppWebViewService) {
    ZMChatAppWebViewService_Chat,
    ZMChatAppWebViewService_MeetingChat,
    ZMChatAppWebViewService_Common,
    ZMChatAppWebViewService_Phone,
};

@interface ZMChatAppEventPoster : NSObject

+ (void)notifyEventName:(NSString *)eventName result:(BOOL)result params:(NSDictionary *)params;
+ (void)notifyEventName:(NSString *)eventName params:(NSDictionary *)params;
+ (void)notifyEventName:(NSString *)eventName service:(ZMChatAppWebViewService)service result:(BOOL)result params:(NSDictionary *)params;
+ (void)notifyEventName:(NSString *)eventName service:(ZMChatAppWebViewService)service params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
