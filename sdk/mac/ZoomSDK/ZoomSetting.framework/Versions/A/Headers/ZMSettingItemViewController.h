//
//  ZMSettingItemViewController.h
//  ZoomSetting
//
//  Created by Huxley Yang on 2018/2/2.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMSettingConstants.h"

// Forward declaration for settingTabType
#ifdef __cplusplus
#import <zUIClient/setting_panel_search.h>
#import <zUI/ZuiNSView.h>
#else
typedef int settingTabType;
#endif

@class ZMSettingMgr;
@protocol IZMSettingBaseTab;

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
@interface ZUIRootView : ZuiNSView

@property (nonatomic, copy, readonly, nullable) NSString *className;

- (instancetype)initWithView:(const zui::View &)zuiView
                     className:(nullable NSString *)className;

@end
#endif

@interface ZMSettingItemViewController : ZMBaseViewController

@property (nonatomic, assign, readonly) ZMSettingTabID tabID;

@property (nonatomic, weak, nullable) id<IZMSettingBaseTab> tab;

@property (nonatomic, copy, nullable) NSString *deeplinkID;

- (void)userWillSearch;

@end

@interface ZMSettingItemMainView : ZMBaseView

- (instancetype)initWithViewController:(NSViewController *)viewController;

@property (nonatomic, weak, readonly, nullable) NSViewController *enclosingViewController;

@end


NS_ASSUME_NONNULL_END

