//
//  ZMBuddyAdapterTypes.h
//  zChatBase
//
//  Common enums/types extracted from zChatComponent's ZMBuddyAdapter to decouple consumers.
//

#ifndef ZMBuddyAdapterTypes_h
#define ZMBuddyAdapterTypes_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMBuddyUpdateState) {
    ZMBuddyUpdateNone                       = 0,
    ZMBuddyUpdateName                       = 1<<1,
    ZMBuddyUpdateEmail                      = 1<<2,
    ZMBuddyUpdatePhone                      = 1<<3,
    ZMBuddyUpdateAvatar                     = 1<<4,
    ZMBuddyUpdatePresence                   = 1<<5,
    ZMBuddyUpdatePersonNote                 = 1<<6,
    ZMBuddyUpdateSipPhone                   = 1<<7,
    ZMBuddyUpdateStatus                     = 1<<8,
    ZMBuddyUpdateDeactivatedOrTerminated    = 1<<9,
    ZMBuddyUpdateOthers                     = 1<<10,
    ZMBuddyUpdateManager                    = 1<<11,
    ZMBuddyUpdateSipDirectNumber            = 1<<12,
};

typedef NS_ENUM(NSUInteger, ZMWorkLocation) {
    ZMTurnOff = 0,
    ZMInOffice,
    ZMRemote
};

NS_ASSUME_NONNULL_END

#endif /* ZMBuddyAdapterTypes_h */

