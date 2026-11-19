//
//  zChatBase.h
//  zChatBase
//
//  Created by Mario Rao on 2026/1/13.
//

#import <Foundation/Foundation.h>

//! Project version number for zChatBase.
FOUNDATION_EXPORT double zChatBaseVersionNumber;

//! Project version string for zChatBase.
FOUNDATION_EXPORT const unsigned char zChatBaseVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <zChatBase/PublicHeader.h>

// NOTE: To avoid C++ module definition conflicts in Swift builds, headers containing
// C++ includes (even if guarded by __cplusplus) should not be exposed in this umbrella header.
// ObjC++ files can directly import those headers as needed.

// Public headers - Pure ObjC only
#import <zChatBase/ZMBuddyAdapterTypes.h>
#import <zChatBase/ZMBuddyBaseProtocol.h>
#import <zChatBase/ZMBuddyProtocal.h>
#import <zChatBase/ZMChatMessageCheckerUtilProtocol.h>
#import <zChatBase/ZMMessageBaseProtocol.h>
#import <zChatBase/ZMIMInputCustomButtonMgrProtocol.h>
#import <zChatBase/ZMIMSinkProtocol.h>
#import <zChatBase/ZMChatsSessionViewProxy.h>
#import <zChatBase/ZMMessageUIMgrProtocol.h>
#import <zChatBase/ZMIMAvatarHelperProtocol.h>
#import <zChatBase/ZMIMScreenShotMgrProtocol.h>
#import <zChatBase/ZMIMAvatarView.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <zChatBase/ZMOPConfigHelper.h>
#import <zChatBase/ZMPresenceUtil.h>

// The following headers contain C++ and should be imported directly in .mm files:
// - ZMCommonAPI.h
// - ZMIZMessageHelper.h
// - ZMMessageAdapterCompat.h
// - ZMMessageProtocol.h
// - ZMPTAppProtocol.h
// - ZMCEventTrackerProtocol.h
 
