//
//  ZMSCFeatureFlags.h
//  ZMScreenshotKit
//
//  Centralized feature gates for Screenshot.
//  Features gated here are internal-only and excluded from public releases.
//

#import <Foundation/Foundation.h>

// ─── Build environment detection ───
// BUILD_FOR_DOGFOOD: defined for dogfood/internal builds
// ZOOM_DEBUG: defined for debug/dev builds
// If neither is defined, this is a public release build.

// ZM_SCREENSHOT_INTERNAL_BUILD is normally supplied by the Xcode build setting
// ZM_SCREENSHOT_INTERNAL (default 0 = public, 1 = internal/dogfood) via
// GCC_PREPROCESSOR_DEFINITIONS. The same switch also drives
// EXCLUDED_SOURCE_FILE_NAMES so feature code and feature files stay in sync.
// The fallback below only applies if no value was provided by the build system.
#ifndef ZM_SCREENSHOT_INTERNAL_BUILD
    #if defined(BUILD_FOR_DOGFOOD) || defined(ZOOM_DEBUG)
        #define ZM_SCREENSHOT_INTERNAL_BUILD 0
    #else
        #define ZM_SCREENSHOT_INTERNAL_BUILD 0
    #endif
#endif

// ─── Per-feature compile-time gates ───
// Each feature has an independent toggle so they can be promoted to
// public release individually without touching other features.
// To override a single feature, define it in GCC_PREPROCESSOR_DEFINITIONS
// before this header is included (the #ifndef guard will preserve it).

#ifndef ZM_FEATURE_STATUS_MENU
    #define ZM_FEATURE_STATUS_MENU          ZM_SCREENSHOT_INTERNAL_BUILD
#endif

#ifndef ZM_FEATURE_CUTOUT
    #define ZM_FEATURE_CUTOUT               0
#endif

#ifndef ZM_FEATURE_AI
    #define ZM_FEATURE_AI                   0
#endif

#ifndef ZM_FEATURE_AI_EDIT
    #define ZM_FEATURE_AI_EDIT              0
#endif

#ifndef ZM_FEATURE_OCR
    #define ZM_FEATURE_OCR                  ZM_SCREENSHOT_INTERNAL_BUILD
#endif

#ifndef ZM_FEATURE_TRANSLATE
    #define ZM_FEATURE_TRANSLATE            ZM_SCREENSHOT_INTERNAL_BUILD
#endif

#ifndef ZM_FEATURE_PIN
    #define ZM_FEATURE_PIN                  ZM_SCREENSHOT_INTERNAL_BUILD
#endif

#ifndef ZM_FEATURE_NOTE
    #define ZM_FEATURE_NOTE                 0
#endif

#ifndef ZM_FEATURE_RECORD
    #define ZM_FEATURE_RECORD               1
#endif

// GIF export is independently gated because Record remains available in public builds.
#ifndef ZM_FEATURE_RECORD_GIF
    #define ZM_FEATURE_RECORD_GIF           0
#endif

#ifndef ZM_FEATURE_TA
    #define ZM_FEATURE_TA                   0
#endif
