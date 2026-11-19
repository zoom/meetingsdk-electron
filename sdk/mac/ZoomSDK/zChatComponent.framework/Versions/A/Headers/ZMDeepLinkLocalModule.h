//
//  ZMDeepLinkLocalModule.h
//  zChatComponent
//
//  In-process implementation of ZMDeepLinkLocalProtocol (the ChatUI-free subset
//  of ZMDeepLinkProtocol). Registered via @routerable so ZMShareDeepLinkLocal
//  resolves in both the PT process and the Meeting subprocess.
//  ZMUniversalDeepLinkManager (ChatUI, PT-only) forwards the matching methods
//  here to keep a single source of truth.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMDeepLinkLocalProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMDeepLinkLocalModule : NSObject <ZMDeepLinkLocalProtocol>

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
