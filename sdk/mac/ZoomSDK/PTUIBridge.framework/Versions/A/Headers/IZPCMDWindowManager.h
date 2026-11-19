//
//  IZPCMDWindowManager.h
//  PTUIBridge
//
//  Created by fistice on 7/9/25.
//

#ifndef IZPCMDWindowManager_h
#define IZPCMDWindowManager_h

#import <PTUIBridge/ZMPTRouterCenter.h>
@class ZPCMDWindowModel;
@protocol ZPCMDWindowProtocol;
@protocol ZPInvitationItemProtocol;
@protocol IZPCMDWindowManager <ZMPTRoutableObject>
- (void)resetManager;
- (void)stopRinging;
- (void)acceptCallFromDevice;//ZOOM-4319
- (void)denyCallFromDevice;//ZOOM-4319
- (BOOL)existsCMDWindow;//ZOOM-10528
- (BOOL)incomingVideoCall:(ZPCMDWindowModel*)model;
- (id<ZPCMDWindowProtocol>)getWindowControllerWithMeetingInfo:(id<ZPInvitationItemProtocol>)meetingInfo;
- (id<ZPCMDWindowProtocol>)getWindowControllerWithMeetingNumber:(NSNumber *)meetingNumber boRoomID:(NSString *)boRoomID;
- (id<ZPCMDWindowProtocol>)getWindowControllerWithFriendId:(NSString *)friendId;
- (void)removeCmdItems:(id<ZPCMDWindowProtocol>)item;
- (void)callHasBeenAnswered:(id<ZPCMDWindowProtocol>)currentController;
#ifdef __cplusplus
- (void)onDevicePresenceChanged:(const NS_ZOOM_MESSAGER::zDeviceInfo&)deviceInfo;
#endif
@end

#endif /* IZPCMDWindowManager_h */
