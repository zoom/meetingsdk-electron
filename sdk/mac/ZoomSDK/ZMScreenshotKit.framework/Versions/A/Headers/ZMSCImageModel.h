//
//  ZMCaptureModel.h
//  ZMScreenCapture
//
//  Created by javenlee on 2018/2/11.
//  Copyright © 2018 ZOOM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMSCImageModel : NSObject{
    CGImageRef _cgImage;
    NSImage *_image;
}
@property (assign) CGFloat              scaleFactor;
@property (assign) NSInteger            windowLayer;
@property (assign) NSRect               frame;
@property (assign) NSInteger            windowID;
@property (assign) CGDirectDisplayID    displayID;
@property (nonatomic ,strong) NSImage   *image;

// Window identity used by TA mode to re-locate the same window across sessions
// (windowID is unstable, so pid + ownerName + windowTitle form the case key).
@property (assign) pid_t                ownerPID;
@property (nonatomic, copy) NSString   *ownerName;
@property (nonatomic, copy) NSString   *windowTitle;
// Accessibility attributes, used to disambiguate windows that share the same
// ownerName (e.g. multiple untitled windows of the same app).
// Populated on demand via ZMWindowListManager (requires Accessibility permission).
@property (nonatomic, copy) NSString   *axTitle;
// Developer-assigned accessibility identifier (kAXIdentifierAttribute); when an app
// sets it, this is the most stable per-window identity available.
@property (nonatomic, copy) NSString   *axIdentifier;
// Original screen-coordinate frame (frame may be converted to window coords by callers).
@property (assign) NSRect               screenFrame;

- (void)refresh;

- (void)setCGImage:(CGImageRef)cgImage;

@end
