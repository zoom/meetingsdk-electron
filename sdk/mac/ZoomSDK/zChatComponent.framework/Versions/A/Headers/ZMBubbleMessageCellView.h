//
//  ZMBubbleMessageCellView.h
//  ZCommonUI
//
//  Created by groot.ding on 21/07/2020.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <zChatComponent/ZMBaseMessageCellView.h>
#import <zChatComponent/ZMMessageBubbleView.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMAvatarView;
@class ZMMessageBubbleView;
@class ZMReactionContainarView;
@class ZMStackView;
@class ZMButton;
@class ZMIMImageButton;
@class ZMIMOnlyImageButton;
@class ZMCopyMessageInfo;
@class ZMMessageThinkingHeaderView;

#define kDefaultReminderBubbleTopToBottom 2

@interface ZMBubbleMessageCellView : ZMBaseMessageCellView <ZMBubbleMessageCellViewProtocol>

@property (nonatomic,retain) ZMIMAvatarView* avatarView;

@property (nonatomic,retain) NSTextView *nameTextView;

@property (nonatomic,retain) NSTextField *unreadTextField;

@property (nonatomic,retain) NSTextField* dateField;

@property (nonatomic,strong) ZMButton *readReceiptsBtn;

@property (nonatomic,retain) ZMMessageBubbleView *bubbleView;

@property (nonatomic,retain) ZMMessageThinkingHeaderView *thinkingHeaderView;

@property (nonatomic,retain) ZMReactionContainarView* reactionView;

@property (nonatomic, readonly, retain) NSTextField *commonErrorMessageLabel;

@property (nonatomic,assign,getter=isSelectedBubble) BOOL selectedBubble;

@property (nonatomic,readonly) BOOL isShowDecodeFail;

@property (nonatomic,readonly, retain) ZMStackView* buttonsView;

@property (readonly, assign) CGFloat bubbleTop;
@property (readonly, assign) CGFloat bubbleLeading;
@property (readonly, assign) CGFloat bubbleHeight;
@property (readonly, assign) CGFloat bubbleWidth;

- (BOOL)isUnreadViewVisible;

- (void)updateNameView;
- (void)updateAvatarView;
- (void)updateBubbleView;
- (void)updateThinkingHeaderView;
- (void)updateReactionView;
- (void)updateToolButtonsStatus;
- (void)updateCommonErrorMessageLabel;
- (void)updateDateField;

- (CGFloat)buttonsViewLeadingConstraintConstant;

- (void)mouseDownInBubbleView;

- (ZMCopyMessageInfo *)getCopyMessageInfo;

- (nullable NSString *)commonErrorMessage;

- (void)onMouseEntered;
- (void)onMouseExited;

/// Returns the VoiceOver body string announced between sender name and time.
/// Subclasses override this to provide message-type-specific content.
/// The default implementation returns nil (body is omitted from the announcement).
- (nullable NSString *)voiceOverMessageBody;

@end

NS_ASSUME_NONNULL_END
