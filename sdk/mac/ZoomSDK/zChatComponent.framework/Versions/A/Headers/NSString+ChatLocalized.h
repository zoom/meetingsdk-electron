//
//  NSString+ChatLocalized.h
//  zChatComponent
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (ChatLocalized)

/// Read localized string from zChatComponent Localizable.strings.
@property (readonly) NSString *localizedStringChat;

@end

NS_ASSUME_NONNULL_END

