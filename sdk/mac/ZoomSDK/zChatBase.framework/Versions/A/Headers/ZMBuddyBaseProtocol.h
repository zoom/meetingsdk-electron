//
//  ZMBuddyBaseProtocol.h
//  zChatBase
//
//  Minimal buddy model protocol for decoupling UI modules from zChatComponent's ZMBuddyAdapter.
//

#ifndef ZMBuddyBaseProtocol_h
#define ZMBuddyBaseProtocol_h

#import <Foundation/Foundation.h>
#import <zChatBase/ZMBuddyAdapterTypes.h>
#import <ZoomUnit/ZPUICommonDef.h>

NS_ASSUME_NONNULL_BEGIN

#if defined(__cplusplus)
namespace NS_ZOOM_MESSAGER { class IZoomBuddy; }
#endif

@protocol ZMBuddyBaseProtocol <NSObject>

// Core identity / display
@property (nonatomic, readonly, nullable) NSString *m_jID;
@property (nonatomic, readonly, nullable) NSString *m_screenName;
@property (nonatomic, readonly, nullable) NSString *m_email;
@property (nonatomic, readonly, nullable) NSString *m_phoneNumber;
@property (nonatomic, readonly, nullable) NSString *m_jobTitle;
@property (nonatomic, readonly, nullable) NSString *m_pronoun;

// Presence / user state
@property (nonatomic, readonly) ZMWorkLocation workLocation;
@property (nonatomic, readonly) ZMIMBuddyPresenceType presenceType;

// Avatar
@property (nonatomic, readonly) BOOL m_isPictureDownloaded;
@property (nonatomic, readonly, nullable) NSString *m_localPicturePath;
@property (nonatomic, readonly, nullable) NSString *m_localBigPicturePath;
// Remote profile picture URL (http(s)); usable by file:// origin webviews where local paths are sandboxed.
@property (nonatomic, readonly, nullable) NSString *m_pictureURL;

// Status flags (commonly used by UI)
@property (nonatomic, readonly) BOOL isBuddy;
@property (nonatomic, readonly) BOOL isRobot;
@property (nonatomic, readonly) BOOL isZoomRoom;
@property (nonatomic, readonly) BOOL isDeactivated;
@property (nonatomic, readonly) BOOL isTerminated;
@property (nonatomic, readonly) BOOL isBlocked;
@property (nonatomic, readonly) BOOL canChat;

// Signature helpers (used by Settings/Profile UI)
@property (nonatomic, readonly) BOOL isSignatureOutOfDate;
- (void)updateSignatureOutOfDate;

// Capability helpers (kept as methods to match existing adapter APIs)
- (BOOL)isChatDisable;

@end

NS_ASSUME_NONNULL_END

#endif /* ZMBuddyBaseProtocol_h */

