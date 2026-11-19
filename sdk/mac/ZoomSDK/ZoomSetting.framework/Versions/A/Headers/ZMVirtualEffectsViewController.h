//
//  ZMVirtualEffectsViewController.h
//  ZoomSetting
//
//  Created by Vinson Wang on 2024/3/26.
//


#import "IZMVirtualEffectsMgr.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZMVESearchable : NSObject
@property (nonatomic, copy) NSString* stringToMatch;
@property (nonatomic, copy) NSString* stringToDisplay;
@property (nonatomic, assign) int tabItemType;// ZMVEItemType
@property (nonatomic, assign) BOOL toBottom;
@property (nonatomic, copy, nullable) BOOL (^howToMatch)(ZMVESearchable* targetSearchable, NSView* view);
@property (nonatomic, copy, nullable) void (^howToHighlight)(NSView* targetView, NSView* hightlightView);
@end

@interface ZMVirtualEffectsViewController : ZMBaseViewController

@property (nonatomic, assign) ZMVEScene scene;

- (void)reloadData;

- (void)updatePreview;

- (void)greenScreenStateChanged;

- (void)showVB;

- (void)showFilters;

- (void)showAvatar;

- (void)showVirtualEffects;

- (BOOL)isHumanAvatarWindowShowing;

- (void)stopPreview;

- (void)closeHumanAvatarWindowIfNeed;

@end

#pragma mark - Search

@interface ZMVirtualEffectsViewController (Search)

- (void)onSearchSelect:(NSString*)searchableKey;

@property (nonatomic, copy, readonly) NSDictionary<NSString*, ZMVESearchable*>* searchables;

- (void)collectSearchables;

@end

NS_ASSUME_NONNULL_END
