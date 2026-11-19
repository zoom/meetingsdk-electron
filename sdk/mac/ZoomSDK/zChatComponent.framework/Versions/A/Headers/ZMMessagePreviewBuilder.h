//
//  ZMMessagePreviewBuilder.h
//  zChatComponent
//
//  Created by Cyan.Yang on 2022/10/24.
//

#import <Foundation/Foundation.h>

#import <zChatComponent/ZMMessagePreviewContext.h>
#import <zChatComponent/ZMMessagePreview.h>

@class ZMMessageAdapter;
@class ZMIMMessageDraft;

NS_ASSUME_NONNULL_BEGIN

@interface ZMMessagePreviewBuilder : NSObject

@property (nonatomic, strong) ZMMessagePreviewContext *context;

@property (nonatomic, strong, nullable) NSAttributedString *RTFMessageAttributedString;

- (nullable ZMMessagePreview *)buildPreviewForMessage:(ZMMessageAdapter *)message;

- (nullable ZMMessagePreview *)buildPreviewForDraft:(ZMIMMessageDraft *)draft;


@end

NS_ASSUME_NONNULL_END
