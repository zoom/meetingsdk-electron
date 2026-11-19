//
//  IZMHomeTab.h
//  PTUIBridge
//
//  Created by Slevin Zhang on 2025/4/25.
//

#ifndef IZMHomeTab_h
#define IZMHomeTab_h

#import <AppKit/AppKit.h>

typedef NS_ENUM(NSInteger, ZMHomeTabStartMeeting) {
    ZMHomeTabStartMeeting_Available = 0,
    ZMHomeTabStartMeeting_Disabled,
    ZMHomeTabStartMeeting_Invisible
};

@protocol IZMOnBoardingController;
@protocol IZMHomeTab <ZMPTRoutableObject, ZMBaseTabsDataProtocol>

- (NSTouchBar *)makeTouchBar;
- (id)listMgr;
- (void)sidebarViewDidChange;
- (void)onCalendarUIReady;
- (void)setupOnboardingChecklist;
- (id<IZMOnBoardingController>)onboardingController;
@optional
- (ZMHomeTabStartMeeting)canStartMeeting;
- (void)startMeeting;
- (BOOL)canScheduleMeeting;
- (void)scheduleMeeting;
- (void)updateMeetingInfo;
- (void)updateButtons;
- (void)activityCenterButtonClicked:(BOOL)isVisible;
/// Returns YES when the Home Tab is rendered by the WebView implementation.
/// Native ZMHomeViewController does not implement this, so respondsToSelector: returns NO.
- (BOOL)isWebViewHomeTab;
/// Returns YES when the Home Tab's WebView should act as the calendar sidebar (FT-gated).
/// Decoupled from isWebViewHomeTab so the sidebar reuse policy can evolve independently
/// of how the Home Tab itself is rendered.
- (BOOL)useHomeWebViewSidebar;
- (nullable NSView *)homeWebViewSidebarView;
- (void)attachWebViewToCalendarSidebar:(BOOL)attach;

@end

#endif
