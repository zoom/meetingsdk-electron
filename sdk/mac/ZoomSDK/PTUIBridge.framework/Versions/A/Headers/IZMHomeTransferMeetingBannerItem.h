//
//  IZMHomeTransferMeetingBannerItem.h
//  PTUIBridge
//
//  Created by Slevin Zhang on 2025/4/25.
//

#ifndef IZMHomeTransferMeetingBannerItem_h
#define IZMHomeTransferMeetingBannerItem_h

@protocol IZMPTTransferMeetingItem;
@class ZMBannerItem;
@protocol IZMHomeTransferMeetingBannerItem <ZMRoutableObject>

- (ZMBannerItem *)item;
- (void)meetingStateChange;
- (void)setTransferMeetings:(NSArray<id<IZMPTTransferMeetingItem> >*)meetings;

@end

#endif
