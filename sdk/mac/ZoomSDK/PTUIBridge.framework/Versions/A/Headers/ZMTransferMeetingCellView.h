//
//  ZMTransferMeetingCellView.h
//  PTUIBridge
//
//  Created by fistice on 2025-10-22.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "IZMPTTransferMeetingItem.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZMTransferMeetingCellViewDelegate <NSObject>
@optional
- (void)onMoreButton:(NSButton *)sender;
- (void)onStartOrJoinOrView:(NSButton *)sender;
@end

@interface ZMTransferMeetingCellView : NSTableCellView

@property (weak) id<ZMTransferMeetingCellViewDelegate> delegate;

// Transfer Item
@property (nonatomic, strong, nullable) id<IZMPTTransferMeetingItem> transferItem;

- (void)updateWithTransferItem:(id<IZMPTTransferMeetingItem>)item;
 
@end

NS_ASSUME_NONNULL_END

