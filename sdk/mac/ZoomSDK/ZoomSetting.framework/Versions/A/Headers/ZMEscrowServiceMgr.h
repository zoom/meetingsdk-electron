//
//  ZMEscrowServiceMgr.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/4/24.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMEscrowServiceAPI.h>

@class ZMEscrowUIActionData, ZMEscrowWindowCtrl;

NS_ASSUME_NONNULL_BEGIN

@interface ZMEscrowServiceMgr : NSObject<ZMEscrowServiceAPI>

@property (nonatomic, strong) ZMEscrowWindowCtrl *windowCtrl;

- (void)cleanUp;

@end


NS_ASSUME_NONNULL_END
