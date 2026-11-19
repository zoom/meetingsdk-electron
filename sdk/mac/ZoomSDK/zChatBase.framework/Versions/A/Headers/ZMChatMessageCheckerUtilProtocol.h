//
//  ZMChatMessageCheckerUtilProtocol.h
//  zChatBase
//
//  Protocolized interface for ZMChatMessageCheckerUtil.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMFileConstants.h>
#import <Prism/ZMRouterCenterProtocols.h>

@class ZMFileEntity;
@class ZMMessageAdapter;
@class ZMChatAppMessagePreviewInfo;
@class ZMToast;
@class ZMMessageFontInfo;

@protocol ZMAlertProtocol;

#ifdef __cplusplus
namespace ns_zoom_messager {
    class IZoomFileInterface;
}
#endif

NS_ASSUME_NONNULL_BEGIN

@class ZMAppearance;
@protocol ZMSecurityAlertProxy <NSObject>

- (nullable ZMAppearance *)drawingAppearance;
- (BOOL)needAlertForFileEntity:(ZMFileEntity *)fileEntity;
- (BOOL)needShowAlwaysTrustCheckButton:(ZMFileEntity *)fileEntity;

@optional
- (void)didSelectedConfirmButton:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;
- (void)didSelectedCancelButton:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;
- (void)didClosedAlertWithESC:(id<ZMAlertProtocol>)alert forFileEntity:(ZMFileEntity *)fileEntity;

- (NSPoint)alertCenterPosition;

@end

@protocol ZMChatMessageCheckerUtilProtocol <NSObject>

- (BOOL)checkIfBeyondMaximunMessageLength:(NSUInteger)msgLength;

- (BOOL)checkIfBeyondMaximunMessageLength:(NSUInteger)msgLength
            isPersistentMeetingOnPregress:(BOOL)isPersistentMeetingOnPregress
                              whenSending:(BOOL)whenSendingMessage
                                sessionId:(NSString *)sessionId;

- (BOOL)checkIfBeyondMaximunShortAppCardPayloadLength:(ZMChatAppMessagePreviewInfo *)previewInfo
                                        existAppCards:(NSArray<ZMChatAppMessagePreviewInfo *> *)appCardListInfoArr;

- (BOOL)checkWithToastWhenAddingToEmojiWithFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *)sessionID toastInView:(NSView *)view;

- (BOOL)checkWithToastWhenSharingFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *)sessionID toastInView:(NSView *_Nullable)view;

- (NSArray<NSString *> *)validFilesFilterSendingFiles:(NSArray<NSString *> *)filePaths sessionId:(NSString *)sessionId toastInView:(NSView *_Nullable)view;

- (NSArray<NSString *> *)expectedFilePathsWithValidCheckFromOriginalPaths:(NSArray<NSString *> *)filePaths
                                                               sessionID:(NSString *_Nullable)sessionID
                                                 copyValidImageToDataDir:(BOOL)copyValidImageToDataDir
                                                          errorToastView:(NSView *_Nullable)toastView;

- (ZMFileCheckResult)checkValidFileAtPath:(NSString *)path sessionID:(nullable NSString*)sessionID isSkipExtensionCheck:(BOOL)isSkipExtensionCheck;
- (ZMFileCheckResult)checkValidFileSizeInSession:(NSString *)sessionID fileSize:(unsigned long long)fileSize;
- (ZMFileCheckResult)checkFileTypeAndSizeWithFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *_Nullable)sessionID;
- (ZMFileCheckResult)checkFileTypeAndViewSizeWithFileItem:(ZMFileEntity *)fileItem sessionID:(NSString *_Nullable)sessionID;

#ifdef __cplusplus
- (BOOL)checkValidFileExtInSession:(NSString *)sessionID
                              file:(ns_zoom_messager::IZoomFileInterface *)zoomFile;
- (BOOL)checkValidFileSizeInSession:(NSString *)sessionID
                               file:(ns_zoom_messager::IZoomFileInterface *)zoomFile;
#endif

- (ZMToast *)toastForInvalidFileWithErrorType:(ZMFileCheckResult)errorType filePath:(NSString*)filePath inSession:(NSString*_Nullable)sessionID;

- (BOOL)checkWithToastWhenSaveAsWithFileItem:(nonnull ZMFileEntity *)fileItem fromView:(nullable NSView *)fromView;

- (BOOL)checkWithToastIfValidFileAtPath:(NSString *)path sessionID:(NSString *)sessionID fromView:(nullable NSView *)fromView isSkipExtensionCheck:(BOOL)isSkipExtensionCheck;

- (BOOL)checkIfNeedsShowingTipForSuspiciousLink:(NSString*)suspiciousLink
                                    displayLink:(NSString *_Nullable *_Nullable)displayLink
                                    textStorage:(NSTextStorage*)textStorage
                                      charIndex:(NSInteger)charIndex
                                      sessionId:(NSString *)sessionId;

- (void)showTipForSuspiciousLink:(NSString *)suspiciousLink
                     displayLink:(NSString *)displayLink
                           allow:(void(^)(BOOL result))allowed
                       sessionId:(NSString *)sessionId;

- (void)closeSuspiciousLinkAlert:(NSString *)sessionId;

- (BOOL)needToShowAtAllWarningForMessageBody:(NSAttributedString*)message inSession:(NSString*)session;
- (void)showAtAllWarningInWindow:(NSWindow*)window forSession:(NSString*)session onConfirm:(void (^)(void))userConfirmedSend;

- (BOOL)needShowPotentialRiskDetectedAlertForFileEntity:(ZMFileEntity *)fileEntity;
- (void)showPotentialRiskDetectedAlertForFileEntity:(ZMFileEntity *)fileEntity
                                           allowed:(void(^)(BOOL result))allowed;
- (void)closePotentialRiskDetectedAlertForSession:(NSString *)sessionId;

- (BOOL)canSendMessage:(nullable ZMMessageAdapter*)messageAdapter withSessionId:(NSString*)sessionId fromView:(NSView*)fromView;

/* NSString Util */
- (NSString *)getPathExtensionWithDotFromFile:(NSString *)fileName;

- (NSString *)convertLongStringByTruncatingTai:(NSString *)aString toMaxLength:(NSUInteger)maxLength;

- (NSUInteger)getTotalLengthFromInsertLink:(NSArray<ZMMessageFontInfo*> *)fontInfoArray;

/* SuspiciousLink */
- (BOOL)hasAuthorizedVisitForSuspiciousLink;
- (void)setAuthorizedVisitForSuspiciousLink;

- (void)registerSecurityAlertProxy:(id<ZMSecurityAlertProxy>)proxy forSession:(NSString *)sessionId;
- (void)removeSecurityAlertProxyForSession:(NSString *)sessionId;

- (void)precheckSendMessage:(NSAttributedString *)attributedString fileList:(NSArray<ZMFileEntity *> *)fileList sessionId:(NSString *)sessionId fromView:(NSView *)view completion:(void (^)(BOOL))completion;

- (NSUInteger)maxChatComposeTextLength;
- (NSUInteger)maxChatMessageLength;

@end

#ifndef ZMShareChatMessageCheckerUtil
#define ZMShareChatMessageCheckerUtil (id<ZMChatMessageCheckerUtilProtocol>)ZMSharedFor(ZMChatMessageCheckerUtilProtocol)
#endif

NS_ASSUME_NONNULL_END

