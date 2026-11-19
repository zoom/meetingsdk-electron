//
//  ZMSessionStorageManager.h
//  zChatComponent
//
//  Created by Yong Zhou on 2025/12/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMSessionStorageInfo.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSessionStorageInfo;

/// Completion handler for async storage info retrieval
typedef void(^ZMSessionStorageCompletionHandler)(NSArray<ZMSessionStorageInfo *> * _Nullable storageInfos, NSError * _Nullable error);

/// Completion handler for cleanup operations
typedef void(^ZMSessionStorageCleanupHandler)(BOOL success, NSError * _Nullable error);

/// Progress handler for long-running operations
/// @param processedCount Number of items processed so far
/// @param totalCount Total number of items to process
/// @param currentItem Current item being processed (can be nil)
typedef void(^ZMSessionStorageProgressHandler)(NSUInteger processedCount, NSUInteger totalCount, ZMSessionStorageInfo * _Nullable currentItem);

/// Manager class for handling chat session storage operations
/// 
/// Thread Safety:
/// - All async operations execute on a background serial queue
/// - SDK calls are dispatched to main thread internally
/// - Completion handlers are always called on main thread
/// - Multiple concurrent calls are serialized to prevent conflicts
///
/// Performance Notes:
/// - Designed for accounts with 1000-10000+ sessions
/// - Storage folders may contain tens of GB of data
/// - All potentially slow operations are async with progress callbacks
@interface ZMSessionStorageManager : NSObject

/// Shared singleton instance
+ (instancetype)sharedInstance;

#pragma mark - Operation State

/// Whether a storage scan operation is currently in progress
@property (nonatomic, readonly) BOOL isScanning;

/// Whether a cleanup operation is currently in progress
@property (nonatomic, readonly) BOOL isCleaning;

/// Cancel any ongoing operation
- (void)cancelCurrentOperation;

#pragma mark - Storage Info Retrieval (Async Only - Recommended)

/// Get storage information for all sessions asynchronously
/// @param progress Progress handler called on main thread (can be nil)
/// @param completion Completion handler called on main thread
/// @note This is the recommended API for UI usage
- (void)getAllSessionStorageInfosWithProgress:(nullable ZMSessionStorageProgressHandler)progress
                                   completion:(ZMSessionStorageCompletionHandler)completion;

/// Get storage information for all sessions asynchronously (simple version)
/// @param completion Completion handler called on main thread
- (void)getAllSessionStorageInfosAsync:(ZMSessionStorageCompletionHandler)completion;

/// Get storage info for a specific session asynchronously
/// @param sessionId The session ID to query
/// @param completion Completion handler called on main thread
- (void)getStorageInfoForSession:(NSString *)sessionId
                      completion:(void(^)(ZMSessionStorageInfo * _Nullable info, NSError * _Nullable error))completion;

#pragma mark - Cleanup Operations

/// Delete storage folders by folder paths directly
/// @param folderPaths Array of full folder paths to cleanup
/// @param progress Progress handler called on main thread
/// @param completion Completion handler called on main thread with overall success status
/// @note Use this API when sessionId may not exist (e.g., deleted sessions)
- (void)cleanupStorageForFolderPaths:(NSArray<NSString *> *)folderPaths
                            progress:(nullable ZMSessionStorageProgressHandler)progress
                          completion:(nullable ZMSessionStorageCleanupHandler)completion;

/// Delete storage folders by folder paths directly (simple version)
/// @param folderPaths Array of full folder paths to cleanup
/// @param completion Completion handler called on main thread
/// @note Use this API when sessionId may not exist (e.g., deleted sessions)
- (void)cleanupStorageForFolderPaths:(NSArray<NSString *> *)folderPaths
                          completion:(nullable ZMSessionStorageCleanupHandler)completion;

/// Delete ALL session storage folders in user data directory
/// @param progress Progress handler called on main thread
/// @param completion Completion handler called on main thread
/// @warning This will delete all cached files for all sessions!
- (void)cleanupAllSessionStorageWithProgress:(nullable ZMSessionStorageProgressHandler)progress
                                  completion:(nullable ZMSessionStorageCleanupHandler)completion;

#pragma mark - Utility Methods

/// Get SHA256 hash for a session ID (folder name)
/// @param sessionId The session ID to hash
/// @return SHA256 hash string (64 characters hex)
- (nullable NSString *)sha256HashForSessionId:(NSString *)sessionId;

/// Get the base data folder path for current user
/// @return Path to the user's data folder
- (nullable NSString *)getUserDataFolderPath;

/// Print all session storage info to console (for debugging)
/// @note Executes asynchronously to avoid blocking
- (void)printAllSessionStorageInfo;

/// Calculate the total size of a folder recursively
/// @warning This can be slow for large folders. Consider using async APIs.
/// @param folderPath Path to the folder
/// @return Total size in bytes
- (unsigned long long)calculateFolderSize:(NSString *)folderPath;

@end

NS_ASSUME_NONNULL_END
