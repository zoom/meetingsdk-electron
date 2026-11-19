//
//  ZMSettingBaseTab.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2026/3/31.
//

#import <Foundation/Foundation.h>
#import <ZoomSetting/ZMSettingConstants.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSettingItemViewController;
@class ZMSettingItemController;
@class ZMSettingTabInfo;
typedef NS_ENUM(NSInteger, ZMSettingTabTrail);
@protocol IZMSettingBaseTab;

@interface ZMSettingBaseTab : NSObject

- (BOOL)registerWithTabID:(ZMSettingTabID)tabID
                    title:(NSString *)title
                 priority:(NSInteger)priority
               zUITabType:(NSInteger)zUITabType
               searchable:(BOOL)searchable
            implementedBy:(ZMSettingImplementedBy)implementedBy
               normalIcon:(nullable NSImage *)normalIcon
             selectedIcon:(nullable NSImage *)selectedIcon;

@property (nonatomic, strong, readwrite, nullable) ZMSettingItemViewController* item;
@property (nonatomic, strong, readwrite, nullable) ZMSettingTabInfo *info;

- (void)onSettingUIEvent:(void*_Nonnull)event;

- (void)setVisible:(NSNumber* _Nullable)visible
    orVisibleBlock:(BOOL (^ _Nullable)(ZMSettingTabID))visibleBlock
            reload:(BOOL)reload;

- (void)setTrail:(ZMSettingTabTrail)trail
          reload:(BOOL)reload;

- (void)windowWillActivate;

- (void)windowDidBecomeKey;

- (void)windowWillAppear;

- (void)windowDidAppear;

- (void)windowWillClose:(NSNotification *)notification;

#ifdef __cplusplus
class CSettingSearchDataInterface;
- (void)userWillSearch:(CSettingSearchDataInterface*)searchInterface;
#else
- (void)userWillSearch:(void *)searchInterface;
#endif

- (void)unregister;

@property (nonatomic, strong, readonly, nullable) ZMSettingItemController *itemSettingController;

@property (nonatomic, assign, readonly) BOOL isSelected;

@property (nonatomic, assign, readonly) BOOL isShowing;

@property (nonatomic, assign, readonly) BOOL isRegistered;

- (void)cleanUp;

- (void)sync;

@end

NS_ASSUME_NONNULL_END
