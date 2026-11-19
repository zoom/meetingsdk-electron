//
//  ZMMeetingListWarningView.h
//  zChatUI
//
//  Created by wwd on 10/23/19.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMeetingListWarningView : NSView
- (void)setString:(NSString *)string;
- (void)setBtnTitle:(NSString *)attrStr;
@property (nonatomic, retain) NSString *btnLink;
@end

@interface ZMSingleTextView: ZMTextView

@end
NS_ASSUME_NONNULL_END
