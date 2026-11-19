//
//  IZMReceiveCallProtocol.h
//  PTUIBridge
//
//  Created by kay.fu on 2025/09/17.
//

#import <Foundation/Foundation.h>

@protocol ZMReceiveCallSettingResult <NSObject>

- (void)reloadConfigList:(NSMutableArray <ZMHMenuItem *> *)items;

@end

@protocol IZMReceiveCallProtocol <NSObject>

@property (weak) id<ZMReceiveCallSettingResult> settingResult;

@end
