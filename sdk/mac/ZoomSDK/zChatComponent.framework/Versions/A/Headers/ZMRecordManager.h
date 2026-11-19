//
//  ZMRecordManager.h
//  zChatComponent
//
//  Created by groot.ding on 10/13/23.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMAudioRecordCallback <NSObject>

- (NSString *)outputRecordFilePath;

- (void)didStartRecord;

- (void)didStopRecord;

- (NSView *)dispalyUIView;

- (void)updateRecordSample:(unichar)sampleValue sampleIndex:(NSUInteger)sampleIdx audioLenght:(NSUInteger)audioLenght;

- (NSString *)identifier;

@end

@interface ZMRecordManager : NSObject
+ (ZMRecordManager*)sharedInstance;
+ (void)releaseInstance;

@property (nonatomic, copy, readonly) NSString* rcdFilePath;

- (BOOL)checkAudioRecord;

//get record file path if can record audio
- (NSString *)startRecordWithCallback:(id<ZMAudioRecordCallback>)callback;

- (void)discardRecordCallback:(id<ZMAudioRecordCallback>)callback;

- (void)stopRecord;
- (void)stopRecordWithCallback:(id<ZMAudioRecordCallback>)callback;

- (void)interruptRecordWithCallback:(id<ZMAudioRecordCallback>)callback;
- (void)interruptRecord;

- (BOOL)isRecording;

- (BOOL)checkHadRecordingByIdentifier:(NSString *)identifier;
- (NSDate *)recordDateByIdentifier:(NSString *)identifier;

- (void)onRecordMessageSettingChanged;

@end

@interface ZMRecordVideoManger : NSObject

- (void)openVirtualBackgroundSettiing;

@end


typedef NS_ENUM(NSInteger, ZMVoiceRecordResult) {
    ZMVoiceRecordResult_Success = 0,    // Recording success
    ZMVoiceRecordResult_Error,          // Recording error
    ZMVoiceRecordResult_Timeout,        // Recording timeout
    ZMVoiceRecordResult_InMeeting,      // Currently in meeting
    ZMVoiceRecordResult_InPhone,        // Currently in phone call
    ZMVoiceRecordResult_NoMic           // No microphone available
};


@interface ZMVoiceRecordManager : NSObject

+ (ZMVoiceRecordManager*)sharedInstance;
+ (void)releaseInstance;
+ (BOOL)isRecording;
+ (BOOL)isPlaying;
+ (BOOL)playVoiceRecordWithFile:(NSString *)voiceFilePath invokeId:(NSString *)invokeId;
+ (BOOL)stopPlayVoiceRecord;
+ (unichar)getMicLevel;

- (ZMVoiceRecordResult)startRecordingWithInvokeId:(NSString*)invokeId voiceFilePath:(NSString*)voiceFilePath sessionId:(NSString*)sessionId webViewId:(nullable NSString*)webViewId rcdTimeout:(NSInteger)rcdTimeout;

- (BOOL)stopRecordingAndKeepFile:(BOOL)keepFile;
- (void)cancelRecording;


@end



NS_ASSUME_NONNULL_END
