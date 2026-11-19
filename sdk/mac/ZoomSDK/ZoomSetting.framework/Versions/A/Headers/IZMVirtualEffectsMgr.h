//
//  IZMVirtualEffectsMgr.h
//  VideoUIBridge
//
//  Created by Vinson Wang on 2024/4/11.
//

#import <Foundation/Foundation.h>
#import <events/client_ClientInteract_enum.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMVEScene) {
    ZMVESceneSetting = 1,
    ZMVESceneDialog,
    ZMVESceneMeetingPanel,
};

@class ZMVirtualEffectsViewController;
@class ZMVECollectionItemVBModel;

FOUNDATION_EXPORT NSString * const ZMVirtualBackgroundDownloadDidFinishNotification;
// Completion identity uses the SDK callback path. GUID is included when the
// matching SDK item is still available.
FOUNDATION_EXPORT NSString * const ZMVirtualBackgroundDownloadGUIDKey;
FOUNDATION_EXPORT NSString * const ZMVirtualBackgroundDownloadPathKey;
FOUNDATION_EXPORT NSString * const ZMVirtualBackgroundDownloadResultKey;

@protocol IZMVirtualEffectsMgr <ZMRoutableObject>

@optional

- (ZMVirtualEffectsViewController *)newViewControllerWithScene:(ZMVEScene)scene;
- (void)showVirtualEffectsWindow;
- (void)closeVirtualEffectsWindow;
- (void)showVB;
- (void)showFilters;
- (void)showAvatar;
- (void)showVirtualEffects;

- (void)reloadDataIfNeed;

- (NSMutableArray<ZMVECollectionItemVBModel *> *)vbItems;

#ifdef __cplusplus
- (void)onMyVideoDeviceRunStarted:(void*)hWnd type:(CMM_MY_VIDEO_RUN_TYPE)eRunType device:(PMediaDevice)pDeviceInfo;
- (void)save3DAvatarSetting:(const Cmm3DAvatarSetting &)setting;
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

- (void)saveVBSettingWithItem:(ZMVECollectionItemVBModel *)vbItemmodel;

- (BOOL)deleteVBItemWithModel:(ZMVECollectionItemVBModel *)vbItemModel;

- (void)downloadVBOriginalForItem:(ZMVECollectionItemVBModel *)vbItemModel;
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

- (BOOL)isImmersiveDisableVB;

- (BOOL)is3DAvatarOpened;

- (BOOL)isVBSettingEffective;

- (BOOL)vbSettingIsUseBlur;

- (BOOL)vbSettingIsUseSmartVB;

- (BOOL)isStudioEffectsEnabled;

- (BOOL)isFaceMakeupLocked;

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

- (BOOL)isPhotoGenerationAvatarEnabled;

- (BOOL)avatarSettingIsUsePhotorealisticAvatar;

#pragma mark - Deepfake
// Invoked by the conf-side sink (ICmmConfUIAPI::OnVideoEffectsDisabledForDeepfakeChanged).
// Triggers a UI reload so item models re-evaluate `showDisable` against the new state.
- (void)onVideoEffectsDisabledForDeepfakeChanged:(BOOL)disabled;

@end

NS_ASSUME_NONNULL_END
