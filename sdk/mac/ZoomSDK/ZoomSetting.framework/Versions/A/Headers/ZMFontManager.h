//
//  ZMFontManager.h
//  ZoomSetting
//
//  Created by martin yu on 2025/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMFontManager : NSObject
+ (instancetype)sharedInstance;

@property (nonatomic, assign) NSInteger fontSizeRate;
- (void)zoomInFontSizeRate;
- (void)zoomOutFontSizeRate;
- (void)resetFontSizeRateToDefault;
@end

NS_ASSUME_NONNULL_END
