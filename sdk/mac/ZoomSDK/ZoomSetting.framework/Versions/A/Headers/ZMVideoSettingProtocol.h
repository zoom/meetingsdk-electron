//
//  ZMVideoSettingProtocol.h
//  ZoomSetting
//
//  Created by Javenlee Li on 2023/6/21.
//

#import <Foundation/Foundation.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMVideoSettingProtocol <ZMRoutableObject>

- (void)changeCameraDeviceId:(NSString*)deviceId deviceName:(NSString*)deviceName;

@end

NS_ASSUME_NONNULL_END
