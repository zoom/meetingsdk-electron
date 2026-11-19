//
//  IZMChatModulesLoaderProtocol.h
//  zChatBase
//
//  Created by Mario Rao on 2026/2/11.
//

#pragma once

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Notification posted when the chat module group finishes loading successfully.
/// Name kept unchanged for backward compatibility.
FOUNDATION_EXPORT NSString * const kNoti_ChatUIEx_Installed;

/// Load status + resource access for the chat module group ("chat").
/// This protocol lives in zChatBase for dependency inversion.
@protocol IZMChatModulesLoaderProtocol <NSObject>

/// Compatibility name: indicates whether the chat module group has been loaded.
@property (nonatomic, readonly) BOOL bundleLoaded;

/// Compatibility name: bundle used for ChatUIEx web resources.
@property (nonatomic, readonly, nullable) NSBundle *chatUIExtBundle;

/// Load the chat module group ("chat") using auto-discovered components path.
///
/// Notes:
/// - Components validation / codesign verification may be expensive and will be performed off the main thread.
/// - Dynamic library loading must happen on the main thread.
/// - `completion` is invoked on the main thread.
- (void)loadChatModulesWithCompletion:(void (^)(BOOL success))completion;

@end

NS_ASSUME_NONNULL_END

