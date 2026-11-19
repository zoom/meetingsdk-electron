//
//  ZMLoadingButton.h
//  ZoomSetting
//
//  Created by Ben Xiao on 2023/5/6.
//  Copyright © 2023 Zoom. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@interface ZMLoadingButton : ZMButton

+ (instancetype)createComfirmButton;

- (void)showLoadingIndicator:(BOOL)show;

- (BOOL)isLoading;

@end

NS_ASSUME_NONNULL_END
