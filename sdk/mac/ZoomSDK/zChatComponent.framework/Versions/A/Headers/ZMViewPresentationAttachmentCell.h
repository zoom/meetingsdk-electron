//
//  ZMViewPresentationAttachmentCell.h
//  zChatComponent
//
//  Created by Mario Rao on 2023/6/28.
//

#import <zChatComponent/ZMEmojiModel.h>
#import <zChatBase/ZMCustomEmojiView.h>
#import <zChatComponent/ZMViewAttachmentCellProtocol.h>
#import <ZoomUnit/ZMFileConstants.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMViewPresentationAttachmentType) {
    ZMViewPresentationAttachmentTypeUnknown = 0,
    ZMViewPresentationAttachmentTypeCustomEmoji = 1,
    ZMViewPresentationAttachmentTypeImage = 2,
};


@protocol ZMViewPresentationAttachmentHandlerProtocol <NSObject>
/// View for attachment
- (NSView *)makeContentViewWithSize:(CGSize)size;

/// text for sending message
- (NSString *)textRepresentation;

/// type of attachment
- (ZMViewPresentationAttachmentType)viewAttachmentType;

@optional
/// url for the image
- (NSString *)imageURL;

/// Source type for url-backed icon download. Only handlers backing url resources need to implement.
@property (nonatomic, assign) ZMFileSourceType sourceType;

@end


@interface ZMViewPresentationAttachmentCell : ZMBaseTextAttachmentCell

@property (nonatomic, strong, readonly) id<ZMViewPresentationAttachmentHandlerProtocol> handler;
@property (nonatomic, assign) CGFloat maxWidth;

@property (nonatomic, assign) BOOL isSelected;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEmojiModel:(ZMCustomEmojiModel *)emojiModel;
- (instancetype)initWithImage:(NSImage *)image tintColor:(NSColor *)tintColor;
- (instancetype)initWithImagePath:(NSString *)imagePath placeholder:(NSString *)placehodler url:(NSString *)url;
- (instancetype)initWithHandler:(id<ZMViewPresentationAttachmentHandlerProtocol>)handler;

/// Source type for url-backed icon download. Default IM; set right after init for Meeting paths.
- (void)setSourceType:(ZMFileSourceType)sourceType;

- (nonnull NSString *)textRepresentation;
- (nullable NSString *)imageURL;
- (ZMViewPresentationAttachmentType)attachmentType;

- (void)setMaxWidthByAttributes:(NSDictionary<NSAttributedStringKey, id> *)attributes;
- (void)setMaxWidthByFontPointSize:(CGFloat)pointSize;
- (void)setMaxWidthByFont:(NSFont *)font;

@end

NS_ASSUME_NONNULL_END
