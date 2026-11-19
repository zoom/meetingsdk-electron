//
//  ZMVoicePrintViewController.h
//  ZoomSetting
//
//  Created by Javenlee Li on 2023/12/26.
//  Copyright © 2023 Zoom. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMVoicePrintState){
    ZMVoicePrintState_None = 0,
    ZMVoicePrintState_Recording,
    ZMVoicePrintState_Analyse,
    ZMVoicePrintState_Success,
    ZMVoicePrintState_Fail,
};

@interface ZMVoicePrintViewController : ZMBaseViewController

@property (nonatomic, copy) void(^dismissBlock)(BOOL showResult);

- (ZMVoicePrintState)voicePrintState;
- (void)updateUI;
- (void)cancelAndClose;

@end

NS_ASSUME_NONNULL_END
