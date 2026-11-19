//
//  ZMSearchCallbackManager.h
//  
//
//  Created by Yong Zhou on 10/16/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSearchCallbackManager : NSObject

@property (nonatomic, strong) ZMCallbackImpl *callbackImpl;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
