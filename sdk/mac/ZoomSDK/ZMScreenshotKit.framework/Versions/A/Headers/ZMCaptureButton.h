//
//  ZMCaptureButton.h
//  ScreenCapture
//
//  Created by javenlee on 2018/3/20.
//  Copyright © 2018 ZOOM. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMCaptureButtonCell : NSButtonCell

@end

#pragma mark -- ZMBackgroundButton
@interface ZMBackgroundButton : NSButton
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
}
@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, strong) NSTrackingArea* trackingArea;
@property(nonatomic, copy) NSString *customTooltip;
@property(nonatomic, copy) NSString *customAccLabel;

@property(nonatomic, strong) NSColor *normalColor;
@property(nonatomic, strong) NSColor *hoverColor;
@property(nonatomic, strong) NSColor *selectColor;
@property(nonatomic, strong) NSColor *hoverSelectColor;
@property(nonatomic, strong) NSColor *pressColor;
@property(nonatomic, strong) NSColor *pressSelectColor;

- (void)refreshTooltip:(NSString *)tooltip;

@end

#pragma mark *** Cancel Button ***
@interface ZMCancelButton: ZMBackgroundButton

@end

#pragma mark -- ZMCaptureButton
@interface ZMCaptureButton : ZMBackgroundButton

@property(nonatomic, assign) BOOL isSelected;
@property(nonatomic, strong) NSImage *selectImage;
@property(nonatomic, strong) NSFont *customFont;

@end

#pragma mark -- ZMSCDropButton
@interface ZMSCDropButton : ZMCaptureButton

@property(nonatomic, assign) BOOL isPopup;
@property(nonatomic, strong) NSImage *dropImage;

@end

#pragma mark -- ZMColorButton
@interface ZMColorButton : ZMBackgroundButton

@property(nonatomic, strong)NSColor *fillColor;
@property(nonatomic, assign) BOOL isSelected;
@property(nonatomic, strong)NSColor *borderColor;
@property(nonatomic, strong)NSColor *selectBorderColor;
@property(nonatomic, strong)NSColor *arrowColor;
@end

#pragma mark -- ZMIconTextButton
@interface ZMIconTextButton : ZMBackgroundButton

@property(nonatomic, assign) CGFloat iconSize;

@end

#pragma mark -- ZMDropRightButton
@interface ZMDropRightButton : ZMBackgroundButton

@end

#pragma mark -- ZMStrokeWidthButton
@interface ZMStrokeWidthButton : ZMColorButton

@property(nonatomic, assign)float strokeWidth;
@end

#pragma mark -- ZMStrokeWidthButton
@interface ZMMosaicStrokeWidthButton : ZMColorButton

@property(nonatomic, assign)float strokeWidth;
@end

