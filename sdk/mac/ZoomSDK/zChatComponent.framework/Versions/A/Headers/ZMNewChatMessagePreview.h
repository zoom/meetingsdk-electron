//
//  ZMNewChatMessagePreview.h
//  zChatComponent
//
//  Created on 2026/01/08.
//  Copyright © 2026 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMNewChatMessagePreview : NSObject

+ (void)openPreviewWithMessageId:(NSString *)messageId
                       sessionId:(NSString *)sessionId
                        threadId:(nullable NSString *)threadId
                         baseUrl:(NSString *)baseUrl;

@end

NS_ASSUME_NONNULL_END


