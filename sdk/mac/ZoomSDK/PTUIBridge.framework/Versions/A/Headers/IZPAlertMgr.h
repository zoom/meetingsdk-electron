//
//  IZPAlertMgr.h
//  PTUIBridge
//
//  Created by Francis Zhuo on 2026/5/27.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPTRouterCenter.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAlertInfo;
@class ZMAlertButtonInfo;
@class ZPAlertInfo;

@protocol IZPAlertMgrPresentation <NSObject>
- (void)installPresentationLifecycle;
- (void)uninstallPresentationLifecycle;
- (void)registerCoachMark:(ZPAlertInfo *)info;
- (void)unregisterCoachMark:(ZPAlertInfo *)info;
- (BOOL)isCoachMarkAvailable:(ZPAlertInfo *)info;
- (void)markCoachMarkShowing:(ZPAlertInfo *)info;
- (void)markCoachMarkShown:(ZPAlertInfo *)info;
- (void)updateBubbleWithInfo:(ZPAlertInfo *)info;
- (void)showBubbleWithInfo:(ZPAlertInfo *)info;
- (void)removeBubbleWithInfo:(ZPAlertInfo *)info;
@end

@protocol IZPAlertMgr <ZMPTRoutableObject>
- (void)showAlertWithInfo:(ZMAlertInfo *)info;
- (void)removeAlertWithInfo:(ZMAlertInfo *)info;
- (void)removeAlertWithIdentifier:(NSString *)identifier;
- (void)attachPresentation:(id<IZPAlertMgrPresentation>)presentation;
- (void)detachPresentation:(id<IZPAlertMgrPresentation>)presentation;
// Called by the ChatUI presentation layer after it is loaded and can render bubbles.
- (void)chatUIPresentationDidBecomeReady;
@end

// Presentation-only operations implemented by the alert manager and consumed by ChatUI.
@protocol IZPAlertMgrPresentationHost <IZPAlertMgr>
- (nullable ZPAlertInfo *)alertInfoForCoachmarkIdentifier:(NSString *)identifier;
- (void)showRegisteredAlertWithInfo:(ZPAlertInfo *)info;
- (void)handleBubbleButtonActionWithInfo:(ZPAlertInfo *)info button:(ZMAlertButtonInfo *)button;
- (void)handleBubbleDidDisplayForInfo:(ZPAlertInfo *)info;
- (void)handleBubbleCloseForInfo:(ZPAlertInfo *)info;
- (void)markBubbleShowing:(ZPAlertInfo *)info;
- (void)markBubbleShown:(ZPAlertInfo *)info;
@end

NS_ASSUME_NONNULL_END
