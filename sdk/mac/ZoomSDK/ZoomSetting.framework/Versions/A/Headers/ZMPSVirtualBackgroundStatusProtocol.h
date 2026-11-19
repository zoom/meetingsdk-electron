//
//  ZMPSVirtualBackgroundStatusProtocol.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/15.
//

#ifndef ZMPSVirtualBackgroundStatusProtocol_h
#define ZMPSVirtualBackgroundStatusProtocol_h

#import <Appkit/Appkit.h>
#import <ZoomSetting/ZMPSObject.h>

typedef NS_ENUM(NSInteger, ZMPSVBDownloadResult) {
    ZMPSVBDownloadResultFailed = 0,
    ZMPSVBDownloadResultSuccess = 1,
    ZMPSVBDownloadResultDeleted = 2,
};

@protocol ZMPSVirtualBackgroundStatusProtocol <NSObject>

- (void)psNotifyVirtualBackgroundEnableChangedForScene:(ZMPSScene)scene;
- (void)psOnVBConfigChanged;
- (void)psOnVBItemsChanged;
- (void)psVBGreenScreenColorChanged:(nullable NSColor *)color;
- (void)psVBDownloadResult:(NSString *_Nonnull)strPath
                     result:(ZMPSVBDownloadResult)result;

@end

#endif /* ZMPSVirtualBackgroundStatusProtocol_h */
