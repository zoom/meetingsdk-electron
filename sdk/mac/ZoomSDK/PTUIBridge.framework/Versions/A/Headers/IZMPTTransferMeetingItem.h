//
//  IZMPTTransferMeetingItem.h
//  PTUIBridge
//
//  Created by fistice on 2025-10-17.
//  Copyright © 2025 Zoom. All rights reserved.
//

#ifndef IZMPTTransferMeetingItem_h
#define IZMPTTransferMeetingItem_h

@class ZPTransferDeviceInfo;

@protocol IZMPTTransferMeetingItem <NSObject>

@required
// Basic meeting info
@property (nonatomic, assign, readonly) long long meetingNumber;
@property (nonatomic, copy, readonly) NSString *topic;

// Device info
@property (nonatomic, strong, readonly) ZPTransferDeviceInfo *deviceInfo;

// Companion mode support
@property (nonatomic, assign, readonly) BOOL isSupportCompanionMode;

// Transfer switch support
@property (nonatomic, assign, readonly) BOOL isTransferMeetingSupportSwitch;
@property (nonatomic, assign, readonly) BOOL isTransferMeetingSupportSwitchComputerOnly;

// Multiple join support
@property (nonatomic, assign, readonly) BOOL isSupportMultipleJoin;

// Action methods
- (void)start;
- (void)JoinMeetingWithImprovedCompanionMode;

@end

#endif /* IZMPTTransferMeetingItem_h */

