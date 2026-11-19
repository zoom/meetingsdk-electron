//
//  ZMIMVideoRecordWindowCtrl.h
//  ChatUI
//
//  Created by simon shang on 2022/1/12.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMIMVideoRecordWindowContentView : ZMNonLayerBaseView

- (void)willRemoveFromHostWindow;

@end

@interface ZMIMVideoRecordWindowCtrl : NSWindowController

@property (nonatomic, copy) NSString *sessionID;
@property (nonatomic, copy) NSString *threadID;

@property (nonatomic, assign) BOOL isFromWebChat;
@property (nonatomic, assign) BOOL isSendDirectly;
@property (nonatomic, copy) NSString *webChatVideoPath;
@property (nonatomic, copy) NSString *invokeId;
@property (nonatomic, copy) NSString *webViewId;

@property (nonatomic, copy, nullable) void (^dismissCompletionBlock)(void);

- (void)handleCancelAction;
- (void)cleanupSilently;

@end

NS_ASSUME_NONNULL_END
