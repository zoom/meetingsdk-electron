//
//  IZMWorkVivoTab.h
//  PTUIBridge
//
//  Created by Cursor on 2026/3/6.
//

#ifndef IZMWorkVivoTab_h
#define IZMWorkVivoTab_h

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/IZMMainTabsData.h>

@protocol IZMWorkVivoTab <ZMPTRoutableObject, ZMBaseTabsDataProtocol>

@property (nonatomic, readonly) NSString *helperCenterLink;

@end

#endif
