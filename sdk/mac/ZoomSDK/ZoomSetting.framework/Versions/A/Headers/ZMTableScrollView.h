//
//  ZMTableScrollView.h
//  ZoomSetting
//
//  Created by Cooper.Chen on 2024/8/10.
//  Copyright © 2024 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMTableScrollView : ZMTrackingScrollView

@property (nonatomic, strong) NSTableView *tableView;
@property (nonatomic, assign) NSUInteger maxLines;

@end

NS_ASSUME_NONNULL_END
