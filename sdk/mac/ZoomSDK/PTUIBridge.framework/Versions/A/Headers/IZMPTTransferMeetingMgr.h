//
//  IZMPTTransferMeetingMgr.h
//  PTUIBridge
//
//  Created by fistice on 2025-10-15.
//  Copyright © 2025 Zoom. All rights reserved.
//

#ifndef IZMPTTransferMeetingMgr_h
#define IZMPTTransferMeetingMgr_h

#import <PTUIBridge/ZMPTRouterCenter.h>

@protocol IZMPTTransferMeetingItem;
@protocol IZMPTTransferMeetingMgr <ZMPTRoutableObject>

// Data access methods
@property (nonatomic, strong, readonly) NSArray<id<IZMPTTransferMeetingItem> > *transferMeetings;

// Action methods
- (void)switchTransferMeeting:(id)item;
- (void)joinCompanionMode:(id)item;

@end


#endif /* IZMPTTransferMeetingMgr_h */
