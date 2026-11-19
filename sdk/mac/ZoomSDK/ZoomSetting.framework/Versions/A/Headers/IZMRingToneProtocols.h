//
//  IZMRingToneProtocols.h
//  ZoomSetting
//
//  Created by Lester Gong on 2025/10/11.
//

#ifndef IZMRingToneProtocols_h
#define IZMRingToneProtocols_h

NS_ASSUME_NONNULL_BEGIN

@protocol ZMSettingRingToneHelperEvent <NSObject>

@optional
- (void)onRingtoneDownloadDidFinished;
- (void)onRingtoneDownloadDidFailed;

@end

NS_ASSUME_NONNULL_END

#endif /* IZMRingToneProtocols_h */
