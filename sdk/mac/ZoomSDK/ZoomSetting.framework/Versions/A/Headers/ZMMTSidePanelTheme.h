//
//  ZMMTSidePanelTheme.h
//  ZoomSetting
//
//  Created by Codex on 2026/7/15.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/IZMMTTheme.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMMTSidePanelTheme : NSObject<ZMMTSidePanelTheme>
@property(nonatomic, strong) ZMPigment *floatFrame;
@property(nonatomic, strong) ZMPigment *sideFrame;
@property(nonatomic, strong) ZMPigment *content;

- (void)setTheme:(ZMMTSidePanelTheme *)theme;
@end

NS_ASSUME_NONNULL_END
