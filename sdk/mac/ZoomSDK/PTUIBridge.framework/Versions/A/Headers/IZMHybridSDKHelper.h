//
//  IZMHybridSDKHelper.h
//  PTUIBridge
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#import <zHybridSDK/zoom_hybrid_sdk_export.h>
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * @router ZMShared
 */
@protocol IZMHybridSDKHelper <ZMRoutableObject>
@property(readonly, assign) BOOL isHybridSDKReady;
#ifdef __cplusplus
- (ZoomHybridSDK::IZoomHybridSDK *)createInstance:(ZoomHybridSDK::ZoomHybridSDKBusinessType)type;
- (void)destoryInstance:(ZoomHybridSDK::IZoomHybridSDK *)instance;
#endif
@end

@protocol ZMHybridSDKStatusProtocol <NSObject>
- (void)onHybridSDKLoadStatusChanged;
@end

NS_ASSUME_NONNULL_END
