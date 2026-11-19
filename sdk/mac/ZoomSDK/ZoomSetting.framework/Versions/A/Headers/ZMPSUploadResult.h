//
//  ZMPSUploadResult.h
//  ZoomSetting
//
//  Created by Michael Lin on 2025/12/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMPSUploadResultStatus) {
    ZMPSUploadResultStatusUnknown,
    ZMPSUploadResultStatusSuccess,
    ZMPSUploadResultStatusCanceled,
    ZMPSUploadResultStatusError
};

typedef NS_ENUM(NSInteger, ZMPSUploadResultErrorReason) {
    ZMPSUploadResultErrorReasonUnknown,
    ZMPSUploadResultErrorReasonInternalError,
    ZMPSUploadResultErrorReasonNoFragmentUploaded,
    ZMPSUploadResultErrorReasonNoFragmentRecorded,
    ZMPSUploadResultErrorReasonTokenNotAvailable,
    ZMPSUploadResultErrorReasonReadingCacheFileError,
    ZMPSUploadResultErrorReasonUndefinedWebFatalError,
    ZMPSUploadResultErrorReasonAdminExceedLimitationError,
    ZMPSUploadResultErrorReasonUserExceedLimitationError,
    ZMPSUploadResultErrorReasonClipsSettingError,
    ZMPSUploadResultErrorReasonEndedByServer,
    ZMPSUploadResultErrorReasonStartFailed,
    ZMPSUploadResultErrorReasonUploadFailed,
    ZMPSUploadResultErrorReasonEndFailed
};

@interface ZMPSUploadResult : NSObject

@property (nonatomic, assign) NSUInteger recordingID;
@property (nonatomic, copy, nullable) NSString *webRecordingID;
@property (nonatomic, assign) ZMPSUploadResultStatus status;
@property (nonatomic, assign) ZMPSUploadResultErrorReason errorReason;
@property (nonatomic, assign) NSInteger errorReasonValue;
@property (nonatomic, assign) BOOL retryable;

@end

NS_ASSUME_NONNULL_END
