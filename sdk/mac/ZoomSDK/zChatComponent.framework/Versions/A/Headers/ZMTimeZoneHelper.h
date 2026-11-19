//
//  ZMTimeZoneHelper.h
//  ZoomUnit
//
//  Created by simon shang on 2022/4/24.
//

#import <Foundation/Foundation.h>

@interface ZMTimeZoneData : NSObject

@property (nonatomic, retain) NSTimeZone *timeZone;
@property (nonatomic, retain) NSString *formatDetail;
@property (nonatomic, retain) NSString *nameForSort;

- (id)initWithTimeZone:(NSTimeZone *)timeZone formatDetail:(NSString *)formatDetail nameForSort:(NSString *)nameForSort;

@end

@interface ZMTimeZoneHelper : NSObject

@property (nonatomic, retain) NSMutableArray<ZMTimeZoneData *> *timeZones;

+ (ZMTimeZoneHelper *)sharedInstance;

- (ZMTimeZoneData *)formatTimeZone:(NSTimeZone *)timeZone;
- (void)clearTimeZonesData;

@end

