//
//  ZMStartupCheckerProtocol.h
//  PTUIBridge
//
//  Migrated from ChatUI for ZOOM-1147722 (Clips ChatUI → PTUI migration).
//

#ifndef ZMStartupCheckerProtocol_h
#define ZMStartupCheckerProtocol_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ZMStartupType) {
    ZMStartupTypeInvalid = 0,
    ZMStartupTypeMeeting,
    ZMStartupTypePhone,
    ZMStartupTypeAudioMessage,
    ZMStartupTypeVideoMessage,
    ZMStartupTypeClips,
    ZMStartupTypeCCHybridMeeting,
};

typedef NS_ENUM(NSUInteger, ZMStartupTargetScene) {
    ZMStartupTargetSceneDefault,
    ZMStartupTargetSceneCreateAIAvatar,
};

@protocol ZMStartupCheckerProtocol <NSObject>

+ (BOOL)checkStartupAvailableWithType:(ZMStartupType)type;
+ (BOOL)checkStartupAvailableWithType:(ZMStartupType)type conflictType:(ZMStartupType *)conflictType;
+ (BOOL)checkStartupAvailableWithAlertViewWithType:(ZMStartupType)type;
+ (BOOL)checkStartupAvailableWithAlertViewWithType:(ZMStartupType)type targetScene:(ZMStartupTargetScene)targetScene;

@end

#endif /* ZMStartupCheckerProtocol_h */
