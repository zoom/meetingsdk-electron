//
//  IZMPTMgr.h
//  PTUI
//
//  Created by fistice on 2024/10/12.
//

#ifndef IZMPTMgr_h
#define IZMPTMgr_h
#import <PTUIBridge/IZMHubTab.h>
#import <PTUIBridge/IZMTasksTab.h>
#import <PTUIBridge/IZMVodTab.h>
#import <PTUIBridge/IZMWhiteBoardTab.h>
#import <PTUIBridge/IZMWorkVivoTab.h>
#import <PTUIBridge/IZMClipsTab.h>

@protocol IZMPTMgr <NSObject>
- (void)initModule;
- (id<IZMHubTab>)getHubTabItem;
- (id<IZMTasksTab>)getTasksTabItem;
- (id<IZMVodTab>)getVodTabItem;
- (id<IZMWhiteBoardTab>)getWhiteBoardTabItem;
- (id<IZMWorkVivoTab>)getWorkvivoTabItem;
- (nullable id<IZMClipsTab>)getClipsTabItem;

- (void)updateHubTab;

//- (ZMPTUISink *)getPTUISink;
@end
#endif /* IZMPTMgr_h */
