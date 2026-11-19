//
//  ZMSettingMgr.h
//  ZoomSetting
//
//  Created by Huxley Yang on 2018/1/30.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <ZoomUnit/ZoomUnit-Swift.h>
#import <ZoomUnit/ZPUICommonDef.h>
#import <ZoomSetting/ZMSettingConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingItemViewController;
@class ZMSettingGeneralViewController;
@class ZMSettingVirtualViewController;
@class ZMSettingAudioViewController;
@class ZMSettingNotificationViewController;
@class ZMSettingMeetingViewController;
@class ZMSettingRecordingViewController;
@class ZMSettingShareViewController;
@class ZMSettingAccountViewController;
@class ZMSettingAccessibilityViewController;
@class ZMSettingShortcutsViewController;
@class ZMSettingStatisticViewController;
@protocol IZMSettingPhoneViewController;

@class PZMToastCoordinator;

@interface ZMSettingMgr : NSWindowController

+ (instancetype)shared;

- (void)startUp;

- (void)onDemandComponentsDidDownload:(NSString*)workPath;

- (BOOL)reloadTabs;//Only reload if the window is visible
- (void)show;//If the window is visible, only showWindow: is called, else the general page is showed
- (void)showWithTabID:(ZMSettingTabID)tabID NS_SWIFT_NAME(show(tabID:));
- (void)showWithTabID:(ZMSettingTabID)tabID
           deeplinkID:(NSString* _Nullable)deeplinkID NS_SWIFT_NAME(show(tabID:deeplinkID:));
- (void)showSettingWithType:(kPTOpenSettingPageType)openSettingPageType
                    context:(nullable NSDictionary *)context;
- (void)showAccordingToMainTabs;

- (void)quitSearching;

- (void)close;

//Window
- (BOOL)isWindowLoadedAndVisible;

/// customize the window level of screen share window in current or next show.
/// Then will be reset to default window level after closing it.
/// - Parameter windowLevel: The screenshare window level, pass less than 0 will reset window level to default
- (void)setWindowLevel:(NSInteger)windowLevel;
- (BOOL)focusToSelectedResult;

@property (nonatomic, strong, readonly) PZMToastCoordinator *toastCoordinator;

@end

NS_ASSUME_NONNULL_END
