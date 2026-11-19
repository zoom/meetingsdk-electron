//
//  ZMToolPaletteController.h
//  ZMScreenCapture
//
//  Created by javenlee on 2018/2/13.
//  Copyright © 2018 ZOOM. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMSCConstants.h"
#import "ZMSCFeatureFlags.h"

typedef enum : NSUInteger {
    ZMAnnotationMode_Window,
    ZMAnnotationMode_View,
} ZMAnnotationMode;

@interface ZMToolPaletteView : NSView

@end

typedef NS_ENUM(NSInteger, ZMToolSelect){
    ZMPencilTool = 1001,
    ZMArrowTool,
    ZMRectangleTool,
    ZMCircleTool,
    ZMTextTool,
    ZMMosaicTool,
    ZMCutOutTool,
    ZMAITool,
    ZMAIEditTool,
    ZMOCRTool,
    ZMTranslateTool,
    ZMDownloadTool,
    ZMPinTool,
    ZMNoteTool,
    ZMUndoTool,
    ZMRedoTool,
    ZMRecordTool,
    ZMCancelTool,
    ZMCutTool,
    ZMDoneTool,
};

typedef NS_OPTIONS(NSUInteger, ZMToolSupportMask) {
    ZMToolSupportNone       = 0,
    ZMToolSupportRecord     = 1 << 0,
    ZMToolSupportAI         = 1 << 1,
    ZMToolSupportAIEdit     = 1 << 2,
    ZMToolSupportOCR        = 1 << 3,
    ZMToolSupportTranslate  = 1 << 4,
    ZMToolSupportPin        = 1 << 5,
    ZMToolSupportNote       = 1 << 6,
    ZMToolSupportCutOut     = 1 << 7,
    ZMToolSupportAll        = (ZMToolSupportRecord | ZMToolSupportAI | ZMToolSupportAIEdit
                              | ZMToolSupportOCR | ZMToolSupportTranslate | ZMToolSupportPin),
};

@protocol ZMToolPaletteDelegate <NSObject>
@optional
- (void)toolPaletteClicked:(ZMToolSelect)senderTag;
- (void)captureModeChange:(BOOL)recordMode;
@end

@class ZMCaptureButton, ZMBackgroundButton, ZMCancelButton, ZMSCDropButton;
@interface ZMToolPaletteController : NSViewController
@property (strong) ZMCaptureButton *pencilButton;
@property (strong) ZMCaptureButton *arrowButton;
@property (strong) ZMCaptureButton *recButton;
@property (strong) ZMCaptureButton *circleButton;
@property (strong) ZMCaptureButton *textButton;
@property (strong) ZMCaptureButton *mosaicButton;
#if ZM_FEATURE_AI
@property (strong) ZMCaptureButton *aiButton;
#endif
#if ZM_FEATURE_AI_EDIT
@property (strong) ZMCaptureButton *aiEditButton;
#endif
#if ZM_FEATURE_OCR
@property (strong) ZMCaptureButton *ocrButton;
#endif
#if ZM_FEATURE_TRANSLATE
@property (strong) ZMCaptureButton *translateButton;
#endif
@property (strong) ZMCaptureButton *downloadButton;
#if ZM_FEATURE_PIN
@property (strong) ZMCaptureButton *pinButton;
#endif
#if ZM_FEATURE_NOTE
@property (strong) ZMCaptureButton *noteButton;
#endif
#if ZM_FEATURE_CUTOUT
@property (strong) ZMCaptureButton *cutOutButton;
#endif
@property (strong) ZMCaptureButton *undoButton;
@property (strong) ZMCaptureButton *redoButton;
@property (strong) ZMCaptureButton *doneButton;
@property (strong) NSBox *line;
@property (strong) NSBox *line2;
@property (strong) ZMBackgroundButton *captureButton;
@property (strong) ZMCancelButton *cancelButton;

@property (assign) BOOL isRecordModeSelected; // NO: Capture mode, YES: Record mode

@property (nonatomic, strong) NSString *captureTitle;
@property (nonatomic, weak) id <ZMToolPaletteDelegate> delegate;
@property (nonatomic,assign) BOOL canUndo;
@property (nonatomic,assign) BOOL canRedo;
@property (nonatomic,assign) NSRectEdge popUpEdge;

@property (nonatomic, assign) ZMAnnotationMode annotationMode;

@property (nonatomic, assign, readonly) NSInteger selectedToolTag;
@property (nonatomic, assign) ZMToolSupportMask supportedTools;
@property (nonatomic, assign) BOOL pinMode;

#if ZM_FEATURE_TA
/// TA mode: the full toolbar stays visible but every item is disabled except
/// Capture and Cancel. Once set, all enable attempts for other tools are ignored.
@property (nonatomic, assign) BOOL taMode;
#endif

- (void)cleanUp;

extern NSNotificationName const ZMToolPaletteGraphicClassDidChangeNotification;

+ (id)sharedToolPaletteController;
+ (id _Nullable)currentSharedToolPaletteController;
+ (void)resetForNewSession;
- (void)updateCurrentGraphicClass:(ZMToolSelect)tool;
- (Class)currentGraphicClass;
- (void)popoverToTagButton:(NSInteger)tag;
- (void)closePopup;
- (void)checkPopupState;
- (void)reset;
- (void)relayoutUI;
- (void)resetButtonHoverStates;
- (void)preselectTool:(ZMToolSelect)tool;
- (void)switchToTool:(ZMToolSelect)tool;

- (void)updateTranslateButtonTooltip;

- (void)updateRecordButtonWithRecordingState:(NSUInteger)recordingState;
- (void)updateRecordButtonWithRecordingState:(NSUInteger)recordingState duration:(NSTimeInterval)duration;
- (void)resetRecordButton;
- (void)setRecordingMode:(BOOL)isRecording;
- (void)configureForCaptureMode:(ZMCaptureMode)mode;

#if ZM_FEATURE_TA
/// Switch the palette into TA mode: show all tools but disable everything except
/// Capture and Cancel.
- (void)configureForTAMode;
#endif

@end
