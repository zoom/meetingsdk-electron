//
//  ZMPSActionToken.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMPSActionType) {
    ZMPSActionTypeUnset,
    ZMPSActionTypeRecordClips,
    ZMPSActionTypeCreateAvatar,
};

@interface ZMPSActionToken : NSObject

@property (nonatomic, assign) ZMPSActionType actionType;
@property (nonatomic, strong, nullable) NSString *webRecordInfo;
@property (nonatomic, strong, nullable) NSString *from;

@end

NS_ASSUME_NONNULL_END
