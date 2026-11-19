//
//  ZMPSMgr.h
//  ZoomSetting
//
//  Created by Michael Lin on 2024/1/10.
//

#import <ZoomSetting/ZMPSObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMPSAppMgr, ZMPSSceneContext;
@interface ZMPSMgr : NSObject

+ (instancetype)shared;
+ (void)uninstall;

+ (ZMPSAppMgr *)appMgrForScene:(ZMPSScene)scene;
+ (void)enumerateAppMgrsUsingBlock:(void (NS_NOESCAPE ^)(ZMPSAppMgr *appMgr, BOOL *stop))block;

+ (void)enumerateSceneContextsUsingBlock:(void (NS_NOESCAPE ^)(ZMPSSceneContext *sceneContext, BOOL *stop))block;

+ (ZMPSSceneContext *)sceneContextForScene:(ZMPSScene)scene;

@end

NS_ASSUME_NONNULL_END
