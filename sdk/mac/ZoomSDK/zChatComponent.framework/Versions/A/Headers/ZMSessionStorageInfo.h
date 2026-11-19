//
//  ZMSessionStorageInfo.h
//  zChatComponent
//
//  Created by Yong Zhou on 2025/12/25.
//  Copyright © 2025 zoom.us. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Data model representing storage information for a chat session
@interface ZMSessionStorageInfo : NSObject

@property (nonatomic, copy) NSString *sessionId;

/// SHA256 hashed folder name (e.g., "55f0a70a2e6c6788584690ed5b198f33c3eb1cf754b1770badbb4bb379cbb369")
@property (nonatomic, copy) NSString *folderHash;

/// Display name of the session (group name or buddy screen name)
@property (nonatomic, copy, nullable) NSString *displayName;

@property (nonatomic, assign) unsigned long long sizeInBytes;

/// Full path to the session data folder (for single session)
@property (nonatomic, copy, nullable) NSString *folderPath;

/// Multiple folder paths (for merged UnExist Sessions)
@property (nonatomic, strong, nullable) NSArray<NSString *> *folderPaths;

/// Whether this folder exists on disk
@property (nonatomic, assign) BOOL folderExists;

/// UnExist = 0, Normal = 1, Merged = 2
@property (nonatomic, assign) NSInteger sortPriority;

/// Returns a formatted string of the file size (e.g., "70.6 MB")
- (NSString *)formattedSize;

@end

NS_ASSUME_NONNULL_END

