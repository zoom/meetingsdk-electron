//
//  ZMTokenCellHelper.h
//  zChatUI
//
//  Created by groot Ding on 11/12/25.
//  Copyright © 2025 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Prism/ZMTokenTextAttachmentCell.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMBuddyAdapter;
@class ZMSessionGroupAdapter;

@interface ZMTokenCellHelper : NSObject

+ (ZMTokenTextAttachmentCell * _Nonnull)getTokenCellWithSessionID:(NSString * _Nonnull)sessionID;

+ (ZMTokenTextAttachmentCell *_Nonnull)getTokenCellWithBuddy:(ZMBuddyAdapter *_Nonnull)buddy;

+ (ZMTokenTextAttachmentCell * _Nonnull)getTokenCellWithGroup:(ZMSessionGroupAdapter *_Nonnull)group;

@end

NS_ASSUME_NONNULL_END
