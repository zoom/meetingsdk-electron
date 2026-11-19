//
//  ZMCustomEmojiView.h
//  zChatComponent
//
//  Created by Mario Rao on 2023/6/30.
//

#import <Cocoa/Cocoa.h>
#import <zChatBase/IZMCustomEmojiModel.h>
#import <Prism/ZMBaseView.h>
#import <Prism/ZMBaseTextAttachmentCell.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMCustomEmojiShowMode) {
    ZMCustomEmojiShowModeDownloadAndShow,
    ZMCustomEmojiShowModeOnlyLoading,
    ZMCustomEmojiShowModeShowWithoutDownload,
};

@interface ZMCustomEmojiView : ZMBaseView <ZMTextAttachmentContentViewProtocol>

/// You can use ZMCustomEmojiModel
@property (nonatomic, strong, nullable) id<IZMCustomEmojiModel> emojiModel;
@property (nonatomic, assign) NSEdgeInsets emojiInsets;
@property (nonatomic, assign) BOOL disableUserInteraction;
@property (nonatomic, assign) BOOL forceDarkMode;
@property (nonatomic, copy, nullable) dispatch_block_t notifyEmojiDeleted;
@property (nonatomic, copy, nullable) dispatch_block_t notifyEmojiShowed;
@property (nonatomic, copy, nullable) dispatch_block_t notifyShowErrorView;
@property (nonatomic, assign, readonly) BOOL isShowingErrorView;

- (instancetype)initWithEmojiInsets:(NSEdgeInsets)insets;

- (BOOL)isEmojiDeleted;

- (void)setCustomEmojiWidth:(CGFloat)width;

- (void)setErrorContentWidth:(CGFloat)width;

/// You can use ZMCustomEmojiModel
- (void)updateEmojiModel:(id<IZMCustomEmojiModel>)emojiModel showMode:(ZMCustomEmojiShowMode)showMode;

- (void)downloadAndShowEmojiIfNeeded;

@end

NS_ASSUME_NONNULL_END
