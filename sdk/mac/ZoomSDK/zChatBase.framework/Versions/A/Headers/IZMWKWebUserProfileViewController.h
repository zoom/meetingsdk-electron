//
//  IZMWKWebUserProfileViewController.h
//  zChatBase
//
//  Created by Mario Rao on 2026/1/27.
//

#import <AppKit/AppKit.h>
#import <ZoomUnit/ZMProfileConfig.h>

NS_ASSUME_NONNULL_BEGIN

/// A minimal protocol extracted for `ZMWKWebUserProfileViewController` usages in VideoUI.
@protocol IZMWKWebUserProfileViewController <NSObject>

@property (nonatomic, retain) ZMProfileConfig *floatConfig;
@property (nonatomic, copy, nullable) void (^updateComplete)(void);

- (void)updateCurrentProfileJid:(NSString *)jid
             dataUpdateComplete:(nullable void (^)(void))complete;

- (void)updateCurrentProfileJid:(NSString *)jid
             dataUpdateComplete:(nullable void (^)(void))complete
              tabSwithchComplete:(nullable void(^)(void))tabSwitchComplete;

@end

NS_ASSUME_NONNULL_END

