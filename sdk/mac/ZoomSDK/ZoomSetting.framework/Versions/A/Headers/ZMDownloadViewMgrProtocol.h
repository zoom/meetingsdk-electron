//
//  ZMDownloadViewMgrProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2021/12/20.
//  Copyright © 2021 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMOndemandProtocol.h>
#import <AppKit/AppKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMDownloadPanelProtocol <NSObject>

- (void)download;
- (void)downloadWithProgress:(nullable ZMDownloadProgressBlock)progress completion:(nullable ZMDownloadCompletionBlock)completion;
- (void)downloadInWindow:(nullable NSWindow *)window
            withProgress:(nullable ZMDownloadProgressBlock)progress
              completion:(nullable ZMDownloadCompletionBlock)completion;
- (void)updateFrameCenter:(NSPoint)center;
- (void)close;
- (nullable NSWindow *)presentedInWindow;

@end

typedef NS_ENUM(NSUInteger, ZMDownloadViewType) {
    ZMDownloadViewTypeCodeSnippet,
    ZMDownloadViewTypeAomHostForVBSetting,
    ZMDownloadViewTypeAomHostForClipsVBSetting,
    ZMDownloadViewTypeAomHostForFaceMakeup,
    ZMDownloadViewTypeForAvatars,
    ZMDownloadViewTypeForClipsAvatars,
    ZMDownloadViewTypeAomHostForClipsImmersive,
    ZMDownloadViewTypeAomHostForStudioEffects,
    ZMDownloadViewTypeAomHostForShareVideo,
    ZMDownloadViewTypeAomHostForSharePPT,
    ZMDownloadViewTypeAomHostForZoomApp,
    ZMDownloadViewTypeAirHost,
    ZMDownloadViewTypeAirHostForBrowserTab,
    ZMDownloadViewTypeViperEX,
    ZMDownloadViewTypeViperEXForPSE,
    ZMDownloadViewTypeViperEXForSmartRecognition,
    ZMDownloadViewTypeAomHostForHandGesture,
    ZMDownloadViewTypeAomHostForForceVB,
    ZMDownloadViewTypeCefAgent,
    ZMDownloadViewTypeAomHostForClipsBioInfoVerify,
    ZMDownloadViewTypeAomHostForHandGestureInMeeting,
    ZMDownloadViewTypeAomHostForAttentionLight,
    ZMDownloadViewTypeAomHostForPoseCorrection,
    ZMDownloadViewTypeCefFrameworkPlugin,
    ZMDownloadViewTypeCefWebViewPlugin,
    ZMDownloadViewTypeAomHostForStudioPreviewVideo,
    ZMDownloadViewTypeClipsRecorder,
};

@protocol ZMDownloadViewMgrProtocol <ZMRoutableObject>

+ (instancetype)shared;

- (id<ZMDownloadPanelProtocol>)dialogueForType:(ZMDownloadViewType)type;

- (void)closeDialogueForDownloadType:(ZMDownloadType)downloadType inWindow:(nullable NSWindow *)window;
- (void)closeDialogueForType:(ZMDownloadViewType)viewType;

@end
NS_ASSUME_NONNULL_END
