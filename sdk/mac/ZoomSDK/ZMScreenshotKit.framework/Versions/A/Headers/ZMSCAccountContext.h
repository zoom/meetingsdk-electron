//
//  ZMSCAccountContext.h
//  ZMScreenshotKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Manages the current ZOOM account context for storage isolation.
/// Storage paths include an account-derived subdirectory so that
/// different accounts never share persisted data (Todo entries,
/// Canvas items, tags, etc.).
@interface ZMSCAccountContext : NSObject

@property (nonatomic, copy, readonly, nullable) NSString *currentAccountId;

/// SHA-256-based subdirectory name derived from `currentAccountId`.
/// Returns @"default" when no account has been set.
@property (nonatomic, copy, readonly, nonnull) NSString *accountStorageSubpath;

/// Per-account UserDefaults using suite name derived from accountStorageSubpath.
/// Falls back to `[NSUserDefaults standardUserDefaults]` when no account is set.
@property (nonatomic, strong, readonly, nonnull) NSUserDefaults *accountDefaults;

+ (instancetype)sharedContext;

/// Call once after parsing launch configuration.
/// Passing nil or an empty string resets to the "default" subpath.
- (void)switchToAccount:(nullable NSString *)accountId;

@end

NS_ASSUME_NONNULL_END
