//
//  ZMTabPermission.h
//  PTUIBridge
//
//  Permission types and handler model for tab access control.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Permission Types

/// Tab permission types (bitmask)
typedef NS_OPTIONS(NSUInteger, ZMTabPermissionType) {
    ZMTabPermissionTypeNone       = 0,
    ZMTabPermissionTypeVisible    = 1 << 0,  // Tab visibility in tab bar
    ZMTabPermissionTypeAccessible = 1 << 1,  // Tab can be selected/accessed
    ZMTabPermissionTypeAll        = 0xFFFF,
};

#pragma mark - Permission Handler Block

/// Permission check block type
/// @param tabId The tab identifier being checked
/// @param permissionType The type of permission being checked
/// @param context Additional context for permission check (nullable)
/// @return YES if permission granted, NO if denied
typedef BOOL(^ZMTabPermissionBlock)(NSString *tabId, 
                                     ZMTabPermissionType permissionType, 
                                     NSDictionary * _Nullable context);

#pragma mark - Permission Handler Model

/// Represents a registered permission handler (Target/Selector or Block)
@interface ZMTabPermissionHandler : NSObject

/// Unique identifier for this handler
@property (nonatomic, copy, readonly) NSString *handlerId;

/// The tab ID this handler is registered for
@property (nonatomic, copy, readonly) NSString *tabId;

/// Permission types this handler checks
@property (nonatomic, assign, readonly) ZMTabPermissionType permissionTypes;

/// Weak reference to target (for Target/Selector pattern)
@property (nonatomic, weak, readonly, nullable) id target;

/// Selector to invoke (for Target/Selector pattern)
/// Signature: - (BOOL)checkPermissionForTabId:(NSString *)tabId 
///                            permissionType:(ZMTabPermissionType)type 
///                                   context:(NSDictionary *)context;
@property (nonatomic, assign, readonly, nullable) SEL selector;

/// Block for permission check (for Block pattern)
@property (nonatomic, copy, readonly, nullable) ZMTabPermissionBlock permissionBlock;

/// Create handler with Target/Selector
+ (instancetype)handlerWithTarget:(id)target
                         selector:(SEL)selector
                            tabId:(NSString *)tabId
                  permissionTypes:(ZMTabPermissionType)types;

/// Create handler with Block
+ (instancetype)handlerWithBlock:(ZMTabPermissionBlock)block
                           tabId:(NSString *)tabId
                 permissionTypes:(ZMTabPermissionType)types;

/// Check if this handler is still valid (target not deallocated for target/selector pattern)
- (BOOL)isValid;

/// Execute permission check
/// @param type Permission type to check
/// @param context Additional context for the check
/// @return YES if permission granted, NO if denied
- (BOOL)checkPermissionForType:(ZMTabPermissionType)type 
                       context:(nullable NSDictionary *)context;

@end

NS_ASSUME_NONNULL_END

