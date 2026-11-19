//
//  ZMChatsCommandListWindowCtrl.h
//  zChatUI
//
//  Created by Ryan Shen on 2019/5/8.
//  Copyright © 2019 Zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef NS_ENUM(NSInteger, ZMChatsCommandSelectionType) {
    ZMChatsCommandSelectionTypeClick,    // Mouse click selection
    ZMChatsCommandSelectionTypeKeyboard, // Keyboard (Enter) selection
};

@protocol ZMChatsCommandListWindowCtrlDelegate <NSObject>
- (void)selectCommand:(NSString*)command;
@optional
// Callback for command selection in mention mode, providing selection type
- (void)commandListController:(NSWindowController *)controller didSelectInMentionModeWithType:(ZMChatsCommandSelectionType)type;
@end

@class ZMChatsCommandData;
@interface ZMChatsCommandListWindowCtrl : NSWindowController <NSTableViewDelegate, NSTableViewDataSource>

@property (weak) id<ZMChatsCommandListWindowCtrlDelegate> delegate;
@property (assign) BOOL isMentionMode;
@property (assign) BOOL isHoverSelect;

+ (instancetype)defaultWindowController;
+ (void)releaseDefaultWindowController;
+ (ZMChatsCommandData*)getCommandForCommandString:(NSString*)cmdString forSession:(NSString*)sessionID;
+ (ZMChatsCommandData*)getCommandForCommandString:(NSString*)cmdString forSession:(NSString*)sessionID exactMatch:(BOOL)exactMatch;

- (void)reset;

- (NSString*)selectedCommandString;
- (BOOL)updateDataWithSessionID:(NSString*)sessionID key:(NSString*)key isRobot:(BOOL)isRobot isSelfChat:(BOOL)isSelfChat;
- (void)selectNextCommand;
- (void)selectPreviousCommand;

// Select and close with keyboard (Enter key) - triggers telemetry callback for mention mode
- (void)selectAndCloseViaKeyboard;

//mention mode logic
- (BOOL)updateDataWithSessionID:(NSString*)sessionID jid:(NSString*)botJid key:(NSString*)key;

@end
