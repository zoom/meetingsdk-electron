//
//  ZMSettingTabInfo.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2026/4/14.
//

#ifndef ZMSettingTabInfo_h
#define ZMSettingTabInfo_h

#import <Foundation/Foundation.h>
#import "ZMSettingConstants.h"

#ifdef __cplusplus
#import <zUIClient/setting_panel_search.h>
#else
typedef int settingTabType;
#endif

typedef NS_ENUM(NSInteger, ZMSettingTabID);
typedef NS_ENUM(NSInteger, ZMSettingTabTrail);


NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingTabInfo : NSObject

@property (nonatomic, assign, readonly) ZMSettingTabID tabID;
@property (nonatomic, strong, readonly, nullable) NSString* tabTitle;
@property (nonatomic, assign, readonly) settingTabType zUITabType;
@property (nonatomic, assign, readonly) BOOL searchable;
@property (nonatomic, assign, readonly) NSInteger priority;
@property (nonatomic, assign, readonly) ZMSettingImplementedBy implementedBy;
@property (nonatomic, strong, readonly) NSNumber* visible;
@property (nonatomic, assign, readonly) ZMSettingTabTrail trail;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMSettingTabInfo_h */
