//
//  ZMWizardController.h
//  ZoomSetting
//
//  Created by javenlee on 2026/5/7.
//

#import <Foundation/Foundation.h>
#import "ZMWizardProtocol.h"
#import "ZMWizardEnvironmentDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMWizardController : NSObject <ZMWizardProtocol>

@property (nonatomic, weak) id<ZMWizardEnvironmentDelegate> delegate;

- (void)cleanUp;
- (void)onMyVideoStateDidChanged;

@end

NS_ASSUME_NONNULL_END
