//
//  ZMSettingCustomViews.h
//  ZoomSetting
//
//  Created by Lester.Gong on 2026/10/4.
//

#import <Cocoa/Cocoa.h>
#import <Prism/ZMScrollView.h>

@class ZMSettingTabInfo;

NS_ASSUME_NONNULL_BEGIN

@interface ZMSettingWindowContentView : NSView

@property (nonatomic, readonly, getter=isFlipped) BOOL flipped;

@end

@interface ZMSettingRightScrollView : ZMScrollView

@end

@interface ZMSettingSideBarCellView : NSTableCellView

@property (nonatomic, strong, nullable) ZMSettingTabInfo *cellInfo;
@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL hovered;
@property (nonatomic, assign) BOOL inDarkBackground;
@property (nonatomic, copy, readonly, nullable) NSString *titleStringValue;

@end

NS_ASSUME_NONNULL_END
