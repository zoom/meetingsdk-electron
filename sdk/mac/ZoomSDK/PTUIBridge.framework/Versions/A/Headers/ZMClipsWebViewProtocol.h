//
//  ZMClipsWebViewProtocol.h
//  PTUIBridge
//
//  Created by Michael Lin on 2026/3/9.
//

#ifndef ZMClipsWebViewProtocol_h
#define ZMClipsWebViewProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMClipsWebViewProtocol <NSObject>
- (void)bringClipsToFront;
- (void)onZoomLogoutFinished;
- (void)evaluateJavaScript:(nullable NSString *)jsStr;
- (void)openClipsWebViewInTabWithUrlString:(nullable NSString *)urlString;
- (void)openClipsWebViewWithUrlString:(nullable NSString *)urlString;
- (void)openClipsWebViewWithClipsID:(nullable NSString *)clipsID recordInfo:(nullable NSString *)recordInfo;
- (void)notifyCreateAvatarFinishedWithClipsID:(nullable NSString *)clipsID recordInfo:(nullable NSString *)recordInfo;
- (void)onOpenClipsLibraryInTab;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMClipsWebViewProtocol_h */
