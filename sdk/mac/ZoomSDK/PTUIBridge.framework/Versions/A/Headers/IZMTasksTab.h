//
//  IZMTasksTab.h
//  PTUIBridge
//
//  Created by Cursor on 2026/3/10.
//

#ifndef IZMTasksTab_h
#define IZMTasksTab_h

#import <PTUIBridge/ZMPTRouterCenter.h>
#import <PTUIBridge/IZMMainTabsData.h>

@protocol IZMTasksTab <ZMPTRoutableObject, ZMBaseTabsDataProtocol>

- (void)onToast:(id)toast;

@end

#endif
