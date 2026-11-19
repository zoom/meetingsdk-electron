//
//  ZMClipsProtocol.h
//  PTUIBridge
//
//  Copyright © 2023 Zoom. All rights reserved.
//

#ifndef PTUIBridge_ZMClipsProtocol_h
#define PTUIBridge_ZMClipsProtocol_h

#import <ZoomUnit/ZMClipsProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMClipsWebViewProtocol <ZMRoutableObject>
- (void)openClipsWebViewWithClipsID:(nullable NSString *)clipsID recordInfo:(nullable NSString *)recordInfo;
- (void)notifyCreateAvatarFinishedWithClipsID:(nullable NSString *)clipsID recordInfo:(nullable NSString *)recordInfo;
- (void)onOpenClipsLibraryInTab;
- (void)openClipsWebViewWithUrlString:(nullable NSString *)urlString;
- (void)openClipsWebViewInTabWithUrlString:(nullable NSString *)urlString;
- (void)bringClipsToFront;
- (void)evaluateJavaScript:(nullable NSString *)jsStr;
- (void)onClipsEnableUpdated;
- (void)onZoomLogoutFinished;
@end

NS_ASSUME_NONNULL_END

#endif /* PTUIBridge_ZMClipsProtocol_h */
