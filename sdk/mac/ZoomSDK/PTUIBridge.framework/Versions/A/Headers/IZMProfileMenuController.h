//
//  IZMProfileMenuController.h
//  PTUIBridge
//
//  Created by fistice on 7/25/25.
//

#ifndef IZMProfileMenuController_h
#define IZMProfileMenuController_h
#import <PTUIBridge/ZMPTRouterCenter.h>

@protocol IZMProfileMenuController <ZMPTRoutableObject>
- (void)popupAtPosition:(NSPoint)position inView:(nullable NSView *)view anchorCorner:(NSRectCorner)corner;
- (void)close;

// ZOOM-1269532: called when the common layer reports AI credit info changed.
- (void)onAICreditInfoUpdated;
@property (readonly) BOOL shown;

@property (assign) BOOL isStatusMessageEditable;

@property (copy, nonatomic) NSImage *imgUserAvatar;
@property (copy) NSImage *presenceImage;
@property (copy) NSString *presenceDes;

@end
#endif /* IZMProfileMenuController_h */
