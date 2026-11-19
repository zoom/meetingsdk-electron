//
//  ZMChatSessionProtocols.h
//  zChatBase
//
//  Created for decoupling ZoomSetting from zChatComponent.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatUISessionGroupAdapterProtocol <NSObject>
@property (nonatomic, readonly, nullable) NSString *m_gID;
@end

@protocol ZMChatUISessionAdapterProtocol <NSObject>
- (BOOL)isGroup;
- (nullable id<ZMChatUISessionGroupAdapterProtocol>)getSessionGroup;
@end

@protocol ZMChatUISessionStorageInfoProtocol <NSObject>
@property (nonatomic, readonly, nullable) NSString *displayName;
@property (nonatomic, readonly, nullable) NSString *sessionId;
@property (nonatomic, readonly, nullable) NSString *folderPath;
@property (nonatomic, readonly, nullable) NSArray<NSString *> *folderPaths;
@property (nonatomic, readonly) unsigned long long sizeInBytes;
@end

NS_ASSUME_NONNULL_END

