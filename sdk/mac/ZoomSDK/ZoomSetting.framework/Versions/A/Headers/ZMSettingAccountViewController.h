//
//  ZMSettingAccountViewController.h
//  ZoomSetting
//
//  Created by Huxley Yang on 2018/2/2.
//  Copyright © 2018 Zipow. All rights reserved.
//

#import <ZoomSetting/ZMSettingItemViewController.h>

@class ZMPTRoundImageView, ZMButton, ZMMyPresenceInfo, PZMButton, ZMSAccountWhereSignListView, ZMTableScrollView, ZMEncryptDetailWindowCtrl, ZMEditAvatarPanel, ZMPopoverController, PZMIconButton, PZMLine, ZMVideoRecognitionWebView, ZMAlertPanel, ZMVoicePrintViewController, ZMSettingMgr, ZMSettingAccountTab;
@interface ZMSettingAccountViewController : ZMSettingItemViewController

@property (nonatomic, assign, readonly, class, getter = isVisible) BOOL visible;
@property (nonatomic, weak, readonly, nullable) ZMSettingAccountTab *settingTab;

@property (strong, nonatomic) ZMMyPresenceInfo *presenceInfo;
@property (nonatomic, strong) ZMPTRoundImageView *avatarImageView;
@property (nonatomic, strong) NSTextField *nameTextField;
@property (nonatomic, strong) NSTextField *emailTextField;
@property (nonatomic, strong) PZMButton *updateAccountButton;
@property (nonatomic, strong) PZMButton *viewMyProfileButton;
@property (nonatomic, strong) PZMButton *accountAdvanceFeatureButton;
@property (strong, nonatomic) ZMButton *btnUserInfoType;
@property (strong, nonatomic) NSImageView *dlpIcon;
@property (nonatomic, strong) NSImageView *presenceImageView;
@property (nonatomic, strong) ZMButton *maskEmailButton;
@property (nonatomic, strong) ZMButton* avatarEditButton;
@property (nonatomic, strong) ZMSAccountWhereSignListView *whereSignListView;
@property (nonatomic, strong) PZMLine *horizontalLine;
@property (nonatomic, strong) NSTextField *txtDeviceTitle;
@property (nonatomic, strong) NSTextField *txtDeviceName;
@property (nonatomic, strong) NSTextField *txtDeviceStatus;
@property (nonatomic, strong) PZMButton *btnSignOutAll;
@property (nonatomic, strong) NSTableView *tabDeviceList;
@property (nonatomic, strong) ZMTableScrollView *tabDeviceListScrollView;
@property (nonatomic, strong) PZMIconButton *refreshButton;
@property (nonatomic, strong) ZMBaseView* devicesListBaseView;
@property (nonatomic, strong) PZMLine* advanceLineView;
@property (nonatomic, strong) ZMButton *encryptButton;
@property (nonatomic, strong) ZMEncryptDetailWindowCtrl *windowCtrl;
@property (nonatomic, strong) ZMEditAvatarPanel* editAvatarPanel;
@property (strong, nonatomic) ZMPopoverController *popoverController;
@property (strong, nonatomic) NSTextField *textField;
@property (nonatomic, assign) BOOL hasAppeared;
@property (strong, nonatomic) NSMutableArray *signDeviceArray;
@property (strong) ZMButton *btnLearnMore;

@property (nonatomic, strong) ZMBaseView *smartRecognitionView;
@property (nonatomic, strong) PZMIconButton *downloadSmartRecognitionButton;
@property (nonatomic, strong) ZMHLine *smartRecognitionBeginLine;
@property (nonatomic, strong) ZMLabel *smartRecognitionLabel;
@property (nonatomic, strong) PZMTextBadge *badgeView;
@property (nonatomic, strong) ZMBaseView *videoRecognitionView;
@property (nonatomic, strong) ZMLabel *videoRecognitionLabel;
@property (nonatomic, strong) ZMLabel *videoRecognitionDescription;
@property (nonatomic, strong) ZMHelpButton *videoHelpBtn;
@property (nonatomic, strong) PZMBannerView *videoBannerView;
@property (nonatomic, strong) ZMButton *uploadImageButton;
@property (nonatomic, strong) ZMButton *deleteImageButton;
@property (nonatomic, strong) ZMBaseView *audioRecognitionView;
@property (nonatomic, strong) ZMLabel *voiceRecognitionLabel;
@property (nonatomic, strong) ZMLabel *voiceRecognitionDescription;
@property (nonatomic, strong) ZMHelpButton *voiceHelpBtn;
@property (nonatomic, strong) PZMBannerView *voiceBannerView;
@property (nonatomic, strong) ZMButton *uploadVoiceButton;
@property (nonatomic, strong) ZMButton *deleteVoiceButton;
@property (nonatomic, strong) ZMHLine *smartRecognitionEndLine;
@property (nonatomic, strong) ZMVideoRecognitionWebView *videoRecognitionWebview;
@property (nonatomic, strong) ZMAlertPanel *personalizedVoicePrivicy;
@property (nonatomic, strong) ZMVoicePrintViewController *voicePrintVewCtrl;
@property (nonatomic, assign) BOOL isVoicePrint;
@property (nonatomic, assign) BOOL isReuseSmartVoice;
@property (nonatomic, assign) BOOL isCreateNewVoiceReuse;
@property (nonatomic, assign) BOOL isLayoutSingleLogin;

- (void)update;
- (void)updateUserButton;
- (void)reloadListWithRefresh:(BOOL)bRefresh;
- (void)reloadWhereYouSignListWithRefresh;
- (void)onRevokeXmppToken:(BOOL)success;
- (void)showUserInfoPopover;
- (void)onUserInfoHover:(ZMButton *)sender;
- (void)onUpdateAccount;
- (void)onViewMyProfileButtonClicked;
- (void)onAccountAdvancedFeatureButtonClicked;
- (void)clickOnEditAvatar;
- (void)onRefresh;
- (void)reloadDeviceLlistInfo:(BOOL)bRefresh;
- (void)setDeviceListView;
- (BOOL)canUpgrade;
- (void)onSignOutAll:(id)sender;

// Smart recognition
// Video
- (void)uploadVideoImage;
- (void)deletVideoImage;
// Audio
- (void)updateVoiceRecording;
- (void)deletVoiceRecording;

- (void)showSmartRecognitionImageDisclaimer;
- (void)reuseVoiceRecordingForOthers;
- (void)downloadSmartRecognition;
- (void)closeDownloadIfNeed;
- (BOOL)canShowDownloadSmartRecognition;

@end
