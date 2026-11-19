//
//  ZMPopOutWindowMgr.h
//  ChatUI
//
//  Created by Kay Fu on 2023/12/26.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPopOutWindowMgrDefine.h>
#import <PTUIBridge/ZMTabDefineHeader.h>
#import <ZoomUnit/ZoomUnit-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMPopOutWindow : NSWindow <ZMPopOutMergeBackViewEvent, ZMToastCoordinatorProvider>

@property (nonatomic,assign) ZMMainTabsType moduleType;

@property (nonatomic,copy) NSString *zmIdentifier;

@property (nonatomic,strong) PZMToastCoordinator *toastCoordinator;

- (void)setDefaultPopoutOriginWithOffset:(NSPoint)offset;
- (void)moveToDraggingScreenPoint:(NSPoint)screenPoint offsetX:(CGFloat)offsetX;

@end

@interface ZMPopOutWindowMgr : NSObject

+ (ZMPopOutWindowMgr*)shared;

- (nullable NSView<ZMPopOutMergeBackViewProtocol> *)popView:(NSView *)view atModule:(ZMMainTabsType)module identifier:(NSString *)identifier param:(NSDictionary *)param;

- (nullable ZMPopOutWindow *)mergeBackAtModule:(ZMMainTabsType)module identifier:(NSString *)identifier;

- (BOOL)popUrl:(NSString *)url atModule:(ZMMainTabsType)aModule param:(NSDictionary *)param;

- (void)registMaxPopoutCount:(NSInteger)maxCount atModule:(ZMMainTabsType)aModule;

- (void)bringPopOutWindowToFrondOfModule:(ZMMainTabsType)theModule;

/// Brings only the popped-out window matching `identifier` to the front. Required for
/// modules that host multiple popout windows under the same type (e.g. marketplace
/// zApp / dynamic tabs), where the type-only variant would front every window.
- (void)bringPopOutWindowToFrondOfModule:(ZMMainTabsType)theModule identifier:(NSString *)identifier;

- (BOOL)isPoppedOfModule:(ZMMainTabsType)theModule;

- (BOOL)isPoppedOfModule:(ZMMainTabsType)theModule identifier:(NSString *)identifier;

- (ZMPopOutWindow *)getPoppedWindowOfModule:(ZMMainTabsType)theModule identifier:(NSString *)identifier;

- (NSString *)getWebViewIdFromUrl:(NSString *)url;

- (void)didLogout;

@end

NS_ASSUME_NONNULL_END
