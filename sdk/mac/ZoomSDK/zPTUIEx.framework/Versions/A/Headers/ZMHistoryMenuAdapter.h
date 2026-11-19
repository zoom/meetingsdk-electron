//
//  ZMSessionMenuItemView.h
//  ChatUI
//
//  Created by Cooper.Chen on 2024/6/28.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMTabDefineHeader.h>
#import <ZoomUnit/IZMThemeMgr.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMHistoryMenuAdapter : NSObject

+ (ZMThemeName)currentThemeName;

+ (ZMMainTabsType)tabTypeWithDeepLinkIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
