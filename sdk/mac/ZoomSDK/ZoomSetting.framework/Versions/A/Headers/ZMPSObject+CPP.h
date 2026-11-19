//
//  ZMPSObject+CPP.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/12.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMPSObject.h>
#import <zPSApp/define/PSDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPSObject (CPP)

- (ps::PSScene)psScene;

@end

NS_ASSUME_NONNULL_END
