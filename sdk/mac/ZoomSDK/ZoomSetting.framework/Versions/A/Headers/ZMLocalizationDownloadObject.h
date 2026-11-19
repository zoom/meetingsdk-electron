//
//  ZMLocalizationDownloadObject.h
//  ZoomSetting
//
//  Created on 2026/1/22.
//  Copyright © 2026 zoom.us. All rights reserved.
//

#import "ZMDownloadObject.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Language Code Mapping

/// Mapping between system language code and i18n resource name
/// System: de, es, fr, id, it, ja, ko, nl, pl, pt, ru, sv, tr, vi, zh-Hans, zh-Hant
/// Resource: i18n_de, i18n_es, i18n_fr, i18n_id, i18n_it, i18n_ja, i18n_ko-KR, i18n_nl, i18n_pl, i18n_pt-PT, i18n_ru, i18n_sv, i18n_tr, i18n_vi, i18n_zh-Hans, i18n_zh-Hant

/// Supported language codes for localization download
typedef NS_ENUM(NSInteger, ZMLocalizationLanguage) {
    ZMLocalizationLanguageUnknown = 0,
    ZMLocalizationLanguageGerman,       // de -> i18n_de
    ZMLocalizationLanguageSpanish,      // es -> i18n_es
    ZMLocalizationLanguageFrench,       // fr -> i18n_fr
    ZMLocalizationLanguageIndonesian,   // id -> i18n_id
    ZMLocalizationLanguageItalian,      // it -> i18n_it
    ZMLocalizationLanguageJapanese,     // ja -> i18n_ja
    ZMLocalizationLanguageKorean,       // ko -> i18n_ko-KR
    ZMLocalizationLanguageDutch,        // nl -> i18n_nl
    ZMLocalizationLanguagePolish,       // pl -> i18n_pl
    ZMLocalizationLanguagePortuguese,   // pt -> i18n_pt-PT
    ZMLocalizationLanguageRussian,      // ru -> i18n_ru
    ZMLocalizationLanguageSwedish,      // sv -> i18n_sv
    ZMLocalizationLanguageTurkish,      // tr -> i18n_tr
    ZMLocalizationLanguageVietnamese,   // vi -> i18n_vi
    ZMLocalizationLanguageChineseSimplified,  // zh-Hans -> i18n_zh-Hans
    ZMLocalizationLanguageChineseTraditional, // zh-Hant -> i18n_zh-Hant
    ZMLocalizationLanguageFull,         // Full package -> i18n_full
};

#pragma mark - Download State

typedef NS_ENUM(NSInteger, ZMLocalizationDownloadState) {
    ZMLocalizationDownloadStateIdle = 0,
    ZMLocalizationDownloadStateCheckingVersion,
    ZMLocalizationDownloadStatePending,
    ZMLocalizationDownloadStateDownloading,
    ZMLocalizationDownloadStateExtracting,
    ZMLocalizationDownloadStateVerifying,
    ZMLocalizationDownloadStateInstalling,
    ZMLocalizationDownloadStateFinished,
    ZMLocalizationDownloadStateFailed,
    ZMLocalizationDownloadStateCancelled,
};

#pragma mark - Delegate Protocol

@class ZMLocalizationDownloadObject;

@protocol ZMLocalizationDownloadDelegate <NSObject>
@optional
- (void)localizationDownloader:(ZMLocalizationDownloadObject *)downloader didUpdateState:(ZMLocalizationDownloadState)state;
- (void)localizationDownloader:(ZMLocalizationDownloadObject *)downloader didUpdateProgress:(CGFloat)progress;
- (void)localizationDownloader:(ZMLocalizationDownloadObject *)downloader didFinishWithError:(nullable NSError *)error;
@end

#pragma mark - ZMLocalizationDownloadObject

@interface ZMLocalizationDownloadObject : ZMDownloadObject

/// The language code for this download object (e.g., "zh-Hans", "de", "fr")
@property (nonatomic, copy, readonly) NSString *languageCode;

/// The i18n resource name (e.g., "i18n_zh-Hans", "i18n_de")
@property (nonatomic, copy, readonly) NSString *i18nResourceName;

/// Current download state
@property (nonatomic, assign, readonly) ZMLocalizationDownloadState downloadState;

/// Delegate for download callbacks
@property (nonatomic, weak) id<ZMLocalizationDownloadDelegate> downloadDelegate;

/// Expected SHA256 checksum (reserved for future use)
@property (nonatomic, copy, nullable) NSString *expectedSHA256;

/// Initialize with language code
/// @param languageCode The language code (e.g., "zh-Hans", "de", "fr")
- (instancetype)initWithLanguageCode:(NSString *)languageCode;

/// Initialize with localization language enum
/// @param language The language enum value
- (instancetype)initWithLanguage:(ZMLocalizationLanguage)language;

/// Initialize with i18n resource name
/// @param i18nResourceName The i18n resource name (e.g., "i18n_zh-Hans", "i18n_de")
- (instancetype)initWithI18nResourceName:(NSString *)i18nResourceName;

#pragma mark - Class Methods

/// Get all supported language codes
+ (NSArray<NSString *> *)allSupportedLanguageCodes;

/// Get i18n resource name from language code
/// @param languageCode The language code (e.g., "zh-Hans")
/// @return The i18n resource name (e.g., "i18n_zh-Hans")
+ (nullable NSString *)i18nResourceNameForLanguageCode:(NSString *)languageCode;

/// Get language code from system locale
/// @return The matched language code, or nil if not supported
+ (nullable NSString *)currentSystemLanguageCode;

/// Check if a language code is supported
+ (BOOL)isLanguageCodeSupported:(NSString *)languageCode;

#pragma mark - Download Control

/// Check if download is needed and start download if necessary
- (void)checkAndDownloadIfNeeded;

/// Check if the local bundle version matches the latest version
- (BOOL)isLocalVersionUpToDate;

/// Get the local bundle version for this language
- (nullable NSString *)localBundleVersion;

/// Get the destination path for this language bundle
/// Format: ~/Library/Application Support/zoom.us/Plugins/{appVersion}/
/// Bundle will be installed as: {destPath}/{i18nResourceName}.bundle
- (nullable NSString *)localizationDestinationPath;

@end

NS_ASSUME_NONNULL_END

