//
//  ZMPresenceUtil.h
//  zChatBase
//

#ifndef ZMPresenceUtil_h
#define ZMPresenceUtil_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPresenceUtil : NSObject

+ (NSString *)buddyPresenceToolTip:(NSUInteger)presenceType;
+ (NSString *)buddyPresenceString:(NSUInteger)presenceType;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMPresenceUtil_h */

