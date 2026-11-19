//
//  ZMLocalSearchModule.h
//  zChatComponent
//
//  In-process implementation of ZMLocalSearchProtocol. Registered via
//  @routerable so ZMShareLocalSearch resolves in both the PT process and the
//  Meeting subprocess. ZMSearchModule (ChatUI, PT-only) forwards the matching
//  ZMChatSearchProtocol methods here to keep a single source of truth.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMLocalSearchProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMLocalSearchModule : NSObject <ZMLocalSearchProtocol>

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
