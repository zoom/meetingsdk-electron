//
//  ZMMessageBodyImageView.h
//  zChatComponent
//
//  Created by Yong Zhou on 4/23/24.
//
//  This class is used to render the picture icon inside the message. 
//  Doc icons and other new features with an icon in the message body could use this class with ZMViewPresentationAttachmentCell.

#import <ZoomUnit/ZMFileConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMessageBodyImageView : ZMBaseView

@property (nonatomic, copy) NSString *urlString;
@property (nonatomic, assign) ZMFileSourceType sourceType; // default ZMFileSourceType_IM; must be set before urlString
@property (nonatomic, assign) NSEdgeInsets iconInsets;
@property (nonatomic, assign) BOOL disableUserInteraction;

@property (nonatomic, strong) NSImage *image;

@property (nonatomic, strong) NSColor *tintColor;

@property (nonatomic, strong) NSColor *selectedTintColor;

@property (nonatomic, assign, setter=setSelected:) BOOL isSelected;

- (instancetype)initWithIconInsets:(NSEdgeInsets)insets;

@end

NS_ASSUME_NONNULL_END
