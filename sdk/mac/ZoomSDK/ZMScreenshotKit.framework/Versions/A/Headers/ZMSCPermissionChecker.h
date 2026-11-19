//
//  ZMSCPermissionChecker.h
//  ZMScreenshotKit
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

/// Runs a pre-flight Screen Recording permission check before the capture
/// window is shown.  All completion callbacks are dispatched on the main queue.
@interface ZMSCPermissionChecker : NSObject

/// Check Screen Recording permission.
/// Prompts the user if not yet determined.
/// For already-denied permissions an informational alert is shown directing
/// the user to System Settings.
/// `completion(granted)` is **always** called so the caller can decide
/// whether to proceed or abort.
+ (void)runPreflightWithCompletion:(void (^)(BOOL granted))completion;

@end

NS_ASSUME_NONNULL_END
