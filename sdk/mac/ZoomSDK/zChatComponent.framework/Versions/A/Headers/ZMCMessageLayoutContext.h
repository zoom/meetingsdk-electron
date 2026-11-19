//
//  ZMCMessageLayoutContext.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2023/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NSTextContainer;

/// A context object that provides information for during layout process of messages.
///
/// Clients can use `currentContext` method to retrieve the context object set in a
/// block that is being invoked. After the block ends, the context will also be removed.
@interface ZMCMessageLayoutContext : NSObject

@property (nonatomic, assign) CGFloat maxTextLayoutWidth;
@property (nonatomic, weak) NSTextContainer *textContainer;

+ (instancetype)currentContext;

+ (void)performWithContext:(void (^)(ZMCMessageLayoutContext *context))block;

@end

NS_ASSUME_NONNULL_END
