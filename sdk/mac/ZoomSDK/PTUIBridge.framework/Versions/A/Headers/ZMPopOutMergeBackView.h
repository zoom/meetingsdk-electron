//
//  ZMPopOutMergeBackView.h
//  ChatUI
//
//  Created by Kay Fu on 2023/12/26.
//  Copyright © 2023 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ZMPopOutWindowMgrDefine.h"
#import <PTUIBridge/ZMTabItem.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZMPopOutMergeBackView : ZMBaseView<ZMPopOutMergeBackViewProtocol>

@property (nonatomic, weak) ZMTabItem* currentItem;

@end

NS_ASSUME_NONNULL_END
