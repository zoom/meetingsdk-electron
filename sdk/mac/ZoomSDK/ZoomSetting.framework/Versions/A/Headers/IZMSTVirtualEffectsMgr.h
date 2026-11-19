//
//  IZMSTVirtualEffectsMgr.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2024/4/11.
//

#import <Foundation/Foundation.h>
#import <events/client_ClientInteract_enum.h>

#ifdef __cplusplus
namespace ps { struct PS3dAvatarConfig; }
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMSTVirtualEffectsScene) {
    ZMSTVirtualEffectsSceneSetting = 1,
    ZMSTVirtualEffectsSceneDialog,
    ZMSTVirtualEffectsSceneMeetingPanel,
};

@class ZMSTVirtualEffectsViewController;
@class ZMSTVirtualEffectsCollectionItemVBModel;

@protocol IZMSTVirtualEffectsMgr <ZMRoutableObject>

@optional

- (ZMSTVirtualEffectsViewController *)newViewControllerWithScene:(ZMSTVirtualEffectsScene)scene;
- (void)showVirtualEffectsWindow;
- (void)closeVirtualEffectsWindow;
- (void)showVB;
- (void)showFilters;
- (void)showAvatar;
- (void)showVirtualEffects;

- (void)reloadDataIfNeed;

- (NSMutableArray<ZMSTVirtualEffectsCollectionItemVBModel *> *)vbItems;

#ifdef __cplusplus
- (void)onMyVideoDeviceRunStarted:(void*)hWnd type:(CMM_MY_VIDEO_RUN_TYPE)eRunType device:(PMediaDevice)pDeviceInfo;
- (void)save3DAvatarSetting:(const ps::PS3dAvatarConfig &)setting;
#endif

- (void)onVirtualBkgndCheckDuplicateAddResult:(BOOL)success filePath:(NSString *)filePath sha256Str:(NSString *)sha256Str eventId:(NSString *)eventId;

- (void)onNeedPromptBiometricDisclaimer;

- (void)greenScreenStateChanged;

- (BOOL)enableGreenVB:(BOOL)enable forView:(NSView *)view;
- (BOOL)enableSmartVB:(BOOL)enable forView:(NSView *)view;

- (void)invalidateAllMakeup:(NSView *)view;

- (void)closeAvatarLegalAlertIfNeed;

#pragma mark - Avatar Apply / VideoModel Download (PT-side, no meeting)
- (void)showAvatarApplyFailedAlert;
- (void)closeAvatarApplyFailedAlert;
- (void)showVideoModelDownloadingAlert;
- (void)closeVideoModelDownloadingAlert;

- (NSString *)checkAndResolveSizeImage:(NSString *)imagePath thumbnail:(NSImage *_Nullable *_Nullable)pThumbnail;

- (nullable NSString *)resizeImageProportionally:(NSImage *)image maxLongSide:(CGFloat)maxLongSide;

@property (nonatomic, assign) BOOL isPickingVBColor;

- (void)myselfMergedStatusChangedWhenSharingDoc;

- (void)tmpCancelVB;

- (void)reflectAllVirtualEffects;

- (void)onImmersiveVideoUpdated;

- (BOOL)canAutoApplyAvatarButNotAgreeLegal;

- (BOOL)isHumanAvatarWindowShowing;

- (void)onCustom3DAvatarDataUpdated;

- (void)saveVBSettingForIsUseSmartVB:(BOOL)isUseSmartVB;

- (void)saveVBSettingToNoneIfNeed;

- (void)saveVBSettingWithItem:(ZMSTVirtualEffectsCollectionItemVBModel *)vbItemmodel;

- (BOOL)deleteVBItemWithModel:(ZMSTVirtualEffectsCollectionItemVBModel *)vbItemModel;

- (void)downloadVBOriginalForItem:(ZMSTVirtualEffectsCollectionItemVBModel *)vbItemModel;
- (void)onVirtualBkgndDownloadResult:(NSString *)strPath
                               result:(NSInteger)result;

- (void)resetFaceMakeupSetting;

- (void)resetStudioEffectSetting;

- (void)resetAvatarSetting;

- (void)refreshEffects;

- (void)closeColorPanelIfNeed;

//zapp vb
- (void)setZappVBWithPath:(NSString *)filePath imageName:(NSString *)VBimageName isVBGen:(BOOL)isVBGen eventId:(NSString *)eventId;
- (void)selectVBItemById:(NSString *)vbId eventId:(NSString *)reqId;
- (void)onRemoveVirtualBackground;
- (void)onSetVirtualBackgroundBlur;
- (void)onUpdateVideoMirrorStatus;
- (void)checkAomHostUpdateCompletion:(void(^)(BOOL, NSUInteger))completion;
- (void)selectLastVBItem;
//zapp video filter
- (void)onAddMakeupFilter;
- (void)onDeleteMakeupFilter;
- (void)selectMakeupFilterWithType:(NSInteger)type andIndex:(NSInteger)index;
- (void)makeApplyAllButtonChecked:(BOOL)check;
- (BOOL)couldSelectVideoFilter;

#pragma mark - Event Tracker
- (void)trackVESettingInteractionWithName:(e_client_ClientInteract_event_name)name checkboxChecked:(BOOL)checked;
- (void)trackVESettingInteractionWithName:(e_client_ClientInteract_event_name)name context:(nullable NSString *)context;

#pragma mark - Calculate Video Setting Height
- (CGFloat)calculateVideoSettingHeight;

#pragma mark - Calculate item size
- (NSSize)dynamicItemSizeWithMinItemWidth:(CGFloat)minItemWidth maxItemWidth:(CGFloat)maxItemWidth aspectRatio:(CGFloat)aspectRatio contentWidth:(CGFloat)contentWidth;

#pragma mark - Common Api

- (BOOL)isVideoVBEnable;

- (BOOL)isVideoVirtualBkgndLocked;

- (BOOL)is3DAvatarEnabled;

- (BOOL)isAnimal3DAvatarEnabled;

- (BOOL)isCustom3DAvatarEnabled;

- (BOOL)canSupport3DAvatarEffect;

- (BOOL)isFaceMakeupEnabled;

- (BOOL)canSupportFaceMakeup;

- (BOOL)isMeetingDisableMirror;

- (BOOL)isImmersiveDisableVB;

- (BOOL)isVideoCutout;

- (BOOL)isVideoEnableAlphaMask;

- (BOOL)is3DAvatarOpened;

- (BOOL)isVBSettingEffective;

- (BOOL)vbSettingIsUseBlur;

- (BOOL)vbSettingIsUseSmartVB;

- (BOOL)isStudioEffectsEnabled;

- (BOOL)isDynamicVideoVirtualBkgndEnabled;

- (BOOL)isSupportGreenVirtualBackgroundVideo;

- (BOOL)isSupportSmartVirtualBackgroundVideo;

- (BOOL)isSupportSmartVirtualBackground;

- (BOOL)isSupportBlurVirtualBackground;

- (BOOL)isGenerativeAIVBEnabled;

- (BOOL)isForceEnableVideoVirtualBkgnd;

- (BOOL)isLipsyncOpened;

- (BOOL)shouldShowPoseCorrectionSetting;

- (BOOL)isPoseCorrectionEnabled;

- (void)enablePoseCorrection:(BOOL)enable;

- (BOOL)isDeviceSupportAttentionLight;

- (BOOL)isAttentionLightEnabled;

- (void)enableAttentionLight:(BOOL)enable;

- (NSColor *)getVBReplaceColor;

- (NSInteger)humanCartoonAvatarCount;

- (BOOL)isCartoonAvatarReachedLimit;

- (BOOL)isDeepfakeEffectsDisabled;

- (BOOL)avatarSettingIsUsePhotorealisticAvatar;

#pragma mark - Deepfake
- (void)onVideoEffectsDisabledForDeepfakeChanged:(BOOL)disabled;

@end

NS_ASSUME_NONNULL_END
