//
//  ZMTabsRegisterCenter.h
//  ChatUI
//
//  Created by Kay Fu on 10/30/24.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/IZMMainTabsData.h>
#import <PTUIBridge/ZMTabPermission.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMTabsRegisterCenter : NSObject

+ (instancetype)defaultCenter;

#pragma mark - Tab Registration

/// Register tab corresponding to the node
/// @param tab data provider
- (void)registerTab:(id<ZMBaseTabsDataProtocol>)tab;

/// Unregister tab corresponding to the node
/// @param tab data provider
- (void)unregisterTab:(id<ZMBaseTabsDataProtocol>)tab;

/// Unregister all tabs
- (void)unregisterAllTab;

/// Get all currently registered tabs
- (nullable NSArray<id<ZMBaseTabsDataProtocol>> *)getCurrentTabs;

/// Get tab by identifier
- (nullable id<ZMBaseTabsDataProtocol>)getTabOfIdentifier:(NSString *)identifier;

#pragma mark - Permission Management

/// Register permission handler with Target/Selector pattern
/// @param target The target object (weak reference)
/// @param selector Selector signature: - (BOOL)checkPermissionForTabId:(NSString *)tabId 
///                                                      permissionType:(ZMTabPermissionType)type 
///                                                             context:(NSDictionary *)context;
/// @param tabId The tab identifier to register permission for
/// @param types Permission types to check (bitmask)
/// @return Handler ID for later unregistration, nil if registration failed
- (nullable NSString *)registerPermissionTarget:(id)target
                                       selector:(SEL)selector
                                       forTabId:(NSString *)tabId
                                permissionTypes:(ZMTabPermissionType)types;

/// Register permission handler with Block pattern
/// @param block Permission check block
/// @param tabId The tab identifier to register permission for
/// @param types Permission types to check (bitmask)
/// @return Handler ID for later unregistration, nil if registration failed
- (nullable NSString *)registerPermissionBlock:(ZMTabPermissionBlock)block
                                      forTabId:(NSString *)tabId
                               permissionTypes:(ZMTabPermissionType)types;

/// Unregister a specific permission handler by handler ID
/// @param handlerId The handler ID returned from registration
- (void)unregisterPermissionHandler:(NSString *)handlerId;

/// Unregister all permission handlers for a specific tab
/// @param tabId The tab identifier
- (void)unregisterAllPermissionHandlersForTabId:(NSString *)tabId;

/// Unregister all permission handlers for a specific target
/// @param target The target object
- (void)unregisterAllPermissionHandlersForTarget:(id)target;

/// Check permission for a tab
/// @param type Permission type to check
/// @param tabId The tab identifier
/// @param context Additional context for permission check (nullable)
/// @return YES if all handlers allow (or no handler registered), NO if any handler denies
- (BOOL)checkPermission:(ZMTabPermissionType)type
               forTabId:(NSString *)tabId
                context:(nullable NSDictionary *)context;

/// Check if tab has any permission handlers registered
/// @param tabId The tab identifier
/// @return YES if has handlers, NO otherwise
- (BOOL)hasPermissionHandlersForTabId:(NSString *)tabId;

/// Get all handler IDs for a specific tab
/// @param tabId The tab identifier
/// @return Array of handler IDs, or empty array if none
- (NSArray<NSString *> *)getHandlerIdsForTabId:(NSString *)tabId;

@end

NS_ASSUME_NONNULL_END
