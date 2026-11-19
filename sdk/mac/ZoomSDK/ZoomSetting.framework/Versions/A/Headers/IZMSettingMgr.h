//
//  IZMSettingMgr.h
//  ZoomSetting
//
//  Created by Lester Gong on 2025/10/11.
//

#ifndef IZMSettingMgr_h
#define IZMSettingMgr_h

NS_ASSUME_NONNULL_BEGIN

@protocol IZMSettingMgr <NSObject>

@optional

- (void)showChatTranslation;

@end

NS_ASSUME_NONNULL_END

#ifndef ZMSharedSettingMgr
#define ZMSharedSettingMgr ZMSharedFor(IZMSettingMgr)
#endif /* ZMSharedSettingMgr */

#endif /* IZMSettingMgr_h */
