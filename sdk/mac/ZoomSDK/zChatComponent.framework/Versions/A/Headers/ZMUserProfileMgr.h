//
//  ZMUserProfileMgr.h
//  zChatComponent
//
//  Created by Jed Zheng on 8/6/2023.
//

#import <AppKit/AppKit.h>
#import <ZoomUnit/ZMProfileConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMUserProfileMgr : NSObject

+ (NSViewController *)getNewVcardViewController:(NSString *)uid floatConfig:(ZMProfileConfig *)config;

// Web profile-card popover presentation (ChatUI-free; usable in the Meeting process).
// Exposed so ZMBuddyProfileCardModule can drive the in-process profile card.
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView autoClose:(BOOL)autoClose;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView autoClose:(BOOL)autoClose sessionId:(nullable NSString *)sessionId;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView autoClose:(BOOL)autoClose sessionId:(nullable NSString *)sessionId trackType:(ZMUserProfileTrackType)trackType;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView autoClose:(BOOL)autoClose sessionId:(nullable NSString *)sessionId profileConfig:(nullable ZMProfileConfig *)profileConfig;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView autoClose:(BOOL)autoClose panelSourceType:(int)sourceType;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect autoClose:(BOOL)autoClose;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect byMousePoint:(BOOL)mouse;
- (void)showUser:(NSString *)uid positioningView:(NSView *)positioningView relativeRect:(NSRect)rect byCenterPoint:(BOOL)center;

// YES when the mouse is over the visible profile-card popover window.
- (BOOL)isMouseOnVcard;

@end

NS_ASSUME_NONNULL_END
