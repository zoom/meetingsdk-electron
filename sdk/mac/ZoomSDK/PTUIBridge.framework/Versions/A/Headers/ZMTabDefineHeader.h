//
//  ZMTabDefineHeader.h
//  ChatUI
//
//  Created by Cooper.Chen on 2024/7/9.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#ifndef ZMTabDefineHeader_h
#define ZMTabDefineHeader_h

typedef NS_OPTIONS(NSUInteger, ZMMainTabsType) {
    ZMMainTabsInvalid = 0,
    ZMMainTabsHome = 1 << 0,
    ZMMainTabsChat = 1 << 1,
    ZMMainTabsMeet = 1 << 2,
    ZMMainTabsPhone = 1 << 3,
    ZMMainTabsDirectory = 1 << 4,
    ZMMainTabsMail = 1 << 5,
    ZMMainTabsZapp = 1 << 6,
    ZMMainTabsCCI = 1 << 8,
    ZMMainTabsCalendar = 1 << 7,
    ZMMainTabsScheduler = 1 << 17,
    ZMMainTabsWhiteBoard = 1 << 9,
    ZMMainTabsZoomIQ = 1 << 10,
    ZMMainTabsLab =1 << 11,
    ZMMainTabsClips = 1 << 13,
    ZMMainTabsNotes = 1 << 14,
    ZMMainTabsWorkvivo = 1 << 15,
    ZMMainTabsDocs = 1 << 16,
    ZMMainTabsFax = 1 << 18,
    ZMMainTabsSpaces = 1 << 19,
    ZMMainTabsHub = 1 << 20,
    ZMMainTabsWorkFlow = 1 << 21,
    ZMMainTabsChatPWA = 1 << 22,
    ZMMainTabsTasks = 1 << 23,
    ZMMainTabsSurveys = 1 << 24,
    ZMMainTabsEvents = 1 << 25,
    ZMMainTabsClinicalNote = 1 << 26,
    ZMMainTabsVod = 1 << 27,
    ZMMainTabsUnifyWebView = 1 << 28,
    ZMMainTabsSMS = 1 << 29,
    ZMMainTabsDynamic = 1 << 30
};

NS_INLINE BOOL ZMIsEqualURL(NSString *lhs, NSString *rhs) {
    if ([lhs hasSuffix:@"/"]) lhs = [lhs substringToIndex:lhs.length - 1];
    if ([rhs hasSuffix:@"/"]) rhs = [rhs substringToIndex:rhs.length - 1];
    return rhs.length > 0 && [lhs isEqualToString:rhs];
}

typedef NS_ENUM(NSInteger, ZMWebViewUIAction) {
    ZMWebViewUIActionUnknown = 0,
    ZMWebViewUIActionShare,
    ZMWebViewUIActionPopout,
    ZMWebViewUIActionGetShareInfo,
};

APPKIT_EXTERN ZMWebViewUIAction ZMWebViewUIActionFromMessage(NSString * _Nullable message);

#endif /* ZMTabDefineHeader_h */
