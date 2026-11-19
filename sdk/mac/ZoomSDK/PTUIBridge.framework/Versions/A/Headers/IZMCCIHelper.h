//
//  IZMCCIHelper.h
//  PTUIBridge
//
//  Created by fistice on 2024/10/25.
//

#ifndef IZMCCIHelper_h
#define IZMCCIHelper_h

@protocol IZMCCIHelper <NSObject>

- (BOOL)isCCIEnabled;
- (BOOL)handleKeyboardShortcut:(NSInteger)action;
- (BOOL)IsInCCICall;
- (BOOL)isInCCINativeVideo;
- (void)leaveNativeVideoWhenPTQuit;
- (BOOL)hasIncomingCCICall;
- (BOOL)isCCIUsingAudio;
- (void)notifyMuteUnmuteMic:(CmmBool)isMute;
- (void)SyncCCIDevcieCmd:(CmmUInt32)cmd;
- (void)SyncMuteStatusToZZHost;
- (void)onClosedCaptionChanged;
- (BOOL)isCCIWindowShowing;
- (NSWindow *)getCCIWindow;

// CCI Hybrid Meeting
- (BOOL)isInCCIHybridMeeting;
- (void)endHybridMeeting:(void (^)(BOOL success))completion;

@end

#define ZMCCIHelper ZMSharedFor(IZMCCIHelper)

#endif /* IZMCCIHelper_h */
