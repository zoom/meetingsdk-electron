//
//  ZMWindowListManager.h
//  ZMScreenCapture
//
//  Created by javenlee on 2018/2/6.
//  Copyright © 2018 ZOOM. All rights reserved.
//

@import Cocoa;
#import "ZMSCFeatureFlags.h"

@class ZMSCImageModel;
@interface ZMWindowListManager : NSObject

+ (ZMSCImageModel *)getScreenshot:(NSScreen *)screen;
+ (NSMutableArray <ZMSCImageModel *>*)getWindowInfo;
+ (NSMutableArray <ZMSCImageModel *>*)getWindowInfoExcludingWindowIDs:(NSSet<NSNumber *> *)excludeIDs;
+ (CGImageRef)getImageForWindow:(NSInteger)windowID;

#if ZM_FEATURE_TA
/// Populate the model's Accessibility attributes (axTitle/axIdentifier) by
/// matching its windowID inside its owning application's AX window list.
/// No-op when Accessibility permission is not granted.
+ (void)fillAccessibilityAttributesForModel:(ZMSCImageModel *)model;

/// Locate a single window by its identity carried in windowInfo:
/// stage 1 filters by ownerName, stage 2 refines with the
/// Accessibility attributes (axTitle + axIdentifier).
/// Returns the matching model, or nil with *error set when there is no match or
/// more than one match.
+ (ZMSCImageModel *)findWindowMatchingWindowInfo:(NSDictionary *)windowInfo
                                           error:(NSError **)error;
#endif


@end
