//
//  ZMSCStorageMigrator.h
//  ZMScreenshotKit
//
//  Per-kind schema registry and chained migration for on-disk payloads.
//  Each kind (e.g. "TodoEntries", "TodoTags", "CanvasItems") carries its
//  own current version and a set of step migrators "fromVersion->toVersion".
//  Callers pass the already-unarchived payload object and the version they
//  read off disk; migrate: walks the chain to currentVersion and returns
//  the upgraded payload. Version 0 is reserved for legacy (pre-wrapper)
//  files: if no v0->v1 migrator is registered, v0 is treated as identical
//  to v1 (envelope-only change).
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef id _Nullable (^ZMSCMigratorBlock)(id _Nullable payload);

@interface ZMSCStorageMigrator : NSObject

/// Call once at app launch. Registers current versions for the three kinds.
+ (void)bootstrap;

/// Registers a kind with its current schema version and step migrators.
/// `stepMigrators` keys are @"N->M" where M = N + 1.
+ (void)registerKind:(NSString *)kind
      currentVersion:(NSInteger)currentVersion
       stepMigrators:(nullable NSDictionary<NSString *, ZMSCMigratorBlock> *)stepMigrators;

/// Chains the appropriate step migrators from `fromVersion` up to currentVersion.
/// Returns nil if the chain is incomplete (caller should fall back to empty).
+ (nullable id)migratePayload:(nullable id)payload
                         kind:(NSString *)kind
                  fromVersion:(NSInteger)fromVersion;

+ (NSInteger)currentVersionForKind:(NSString *)kind;

@end

#pragma mark - Kind constants

FOUNDATION_EXPORT NSString *const ZMSCStorageKindTodoEntries;
FOUNDATION_EXPORT NSString *const ZMSCStorageKindTodoTags;
FOUNDATION_EXPORT NSString *const ZMSCStorageKindCanvasItems;

NS_ASSUME_NONNULL_END
