//
//  NSString+Chat.h
//  zChatComponent
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Chat)
- (NSArray <NSString *> *)splitString;
- (NSArray<NSString*>* _Nullable)tryParsingAsGoogleCalendarEmails;
- (NSString *)trimLeadingWhitespaceAndNewlines;
- (BOOL)checkValidEmail;

+ (const char *)safeUTF8String:(NSString *)string;

- (NSString *)replaceTWFlagEmojiIfNeed;

@end

NS_ASSUME_NONNULL_END

