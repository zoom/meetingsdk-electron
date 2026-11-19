//
//  ZMWebChatHandler.h
//  zChatComponent
//
//  Created by Zoro.Fu on 2025/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMIntegrationFile) {
    ZMIntegrationFile_None,
    ZMIntegrationFile_Dropbox,
    ZMIntegrationFile_MicrosoftOneDrive,
    ZMIntegrationFile_GoogleDrive,
    ZMIntegrationFile_Box,
    ZMIntegrationFile_MicrosoftSharePoint,
    ZMIntegrationFile_Count
};

@class ZMChatAppContext;

@interface ZMFilePickerAppContext : NSObject

@property (nonatomic, copy) NSString *sessionId;
@property (nonatomic, copy) NSString *threadId;
@property (nonatomic, assign) ZMIntegrationFile fileType;

@property (nonatomic, strong) NSWindow *hostWindow;

@end

@interface ZMWebChatHandler : NSObject

+ (instancetype)sharedInstance;

- (void)setWebChatViewId:(NSString *)webViewId;

- (BOOL)openChatAppWithChatAppContext:(ZMChatAppContext *)context;

- (void)receiveDLEv_RecvNotification:(NSDictionary *)payload;

- (void)sendDataToWebChat:(NSString *)payload;

- (BOOL)openIntegrationFilePickerWithContext:(ZMFilePickerAppContext *)context;

@end

NS_ASSUME_NONNULL_END
