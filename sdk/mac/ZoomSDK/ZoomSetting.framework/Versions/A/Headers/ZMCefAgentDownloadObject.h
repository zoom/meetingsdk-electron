//
//  ZMCefAgentDownloadObject.h
//  ZoomSetting
//
//  Created by Jax Wu on 2022/4/28.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMDownloadObject.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^CefAgentUpgradeStartHandler)(void);

#define zCefAppBundle @"ZoomCefAgent.app"

@interface ZMCefAgentDownloadObject : ZMDownloadObject

@property (nonatomic, copy, nullable) CefAgentUpgradeStartHandler upgradeStartHandler;

@end

NS_ASSUME_NONNULL_END
