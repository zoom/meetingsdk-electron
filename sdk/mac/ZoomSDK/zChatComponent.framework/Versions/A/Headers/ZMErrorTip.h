//
//  ZMErrorTip.h
//  ChatUI
//
//  Created by groot.ding on 13/8/21.
//  Copyright © 2021 Zoom. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMErrorTipInfoType) {
    ZMErrorTipInfoTypeError,
    ZMErrorTipInfoTypeWarning
};

@interface ZMErrorTip : ZMBaseView

@property (nonatomic,copy) NSString *stringValue;
@property (nonatomic,copy) NSAttributedString *attributedStringValue;

@property (nonatomic,assign) NSLineBreakMode lineBreakMode;
@property (nonatomic, assign) ZMErrorTipInfoType infoType;
@property (nonatomic,assign) BOOL needShowIcon;

- (void)updateUI;

@end

NS_ASSUME_NONNULL_END
