//
//  ZMSettingMgr+ZMToastCoordinatorProvider.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2025/11/3.
//

#import <ZoomSetting/ZMSettingMgr.h>
#import <ZoomUnit/ZoomUnit-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingMgr (ZMToastCoordinatorProvider) <ZMToastCoordinatorProvider>

@property (nonatomic, strong, readonly) PZMToastCoordinator *toastCoordinator;

@end

NS_ASSUME_NONNULL_END

