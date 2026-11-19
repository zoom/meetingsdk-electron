//
//  IZMUpgradeMgr.h
//  PTUIBridge
//
//  Created by Cooper Chen on 2025/11/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kZMUpgradeUIFromMarketingBanner @"marketingbanner"
#define kZMUpgradeUIFromInMeetingDialog @"inmeetingdialog"
#define kZMUpgradeUIFromPostMeetingDialog @"postmeetingdialog"

typedef NS_ENUM(NSUInteger, ZMUpgradeUISource) {
    ZMUpgradeUISourceNone,
    ZMUpgradeUISourceScheduler,
    ZMUpgradeUISourcePTMenu,
    ZMUpgradeUISourceSettingsWindow,
    ZMUpgradeUISourceMarketingBanner,
    ZMUpgradeUISourceInMeetingDialog,
    ZMUpgradeUISourcePostMeetingDialog,
};

@protocol ZMUpgradeMgrProtocol <NSObject>

- (void)showUpgradeWindowIn:(NSWindow *)window;

- (void)showUpgradeWindowIn:(NSWindow *)window kvsExtra:(NSDictionary *)kvsExtra;

- (void)updateSource:(ZMUpgradeUISource)source;

- (void)eventTrackingFrom:(ZMUpgradeUISource)from showing:(BOOL)showing;

- (void)eventTrackingFrom:(ZMUpgradeUISource)from showing:(BOOL)showing message:(NSString*)msg;

- (void)upgradeSuccessVCShowOnHostWindow:(NSWindow *)hostWindow reqId:(NSString *)reqId eventId:(NSString *)eventId;

@end

NS_ASSUME_NONNULL_END
