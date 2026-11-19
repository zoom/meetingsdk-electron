//
//  ZMNotifySettingItem.h
//  SaasBeePTUIModule
//
//  Created by Evelyn on 9/6/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMAutoNotifySettingItem : NSObject

@property(nonatomic,assign) BOOL  enableSetting;
@property(nonatomic,assign) NSInteger   startHour;
@property(nonatomic,assign) NSInteger   startMinute;
@property(nonatomic,assign) NSInteger   endHour;
@property(nonatomic,assign) NSInteger   endMinute;

+ (instancetype)getAutoNotifySettingItemWith:(NSInteger)startHr startMinute:(NSInteger)startMin endHour:(NSInteger)endHr endMinute:(NSInteger)endMin enableSetting:(BOOL)enable;

@end

@interface ZMGroupSettingItem : NSObject

@property (assign) NSInteger  settingType;
@property (copy) NSString*  groupId;
@property (copy) NSString* groupName;

+ (instancetype)getGroupSettingItemWith:(NSString *)groupId settingType:(NSInteger)type groupName:(NSString *)name;

@end
