//
//  ZMMessageAdapterCompat.h
//  zChatBase
//
//  Types extracted from zChatComponent's ZMMessageAdapter to decouple consumers.
//  This file is compiled with ARC in zChatBase.
//

#ifndef ZMMessageAdapterCompat_h
#define ZMMessageAdapterCompat_h

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
#import <zChatApp/IZoomMessenger.h>
#endif

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMMarkUnreadMessageMentionType) {
    ZMMarkUnreadMessageMentionTypeNone,
    ZMMarkUnreadMessageMentionTypeMentionMe,
    ZMMarkUnreadMessageMentionTypeMentionGroup,
    ZMMarkUnreadMessageMentionTypeBoth
};

#if defined(__cplusplus)
@interface ZMMessageBackwardCompatibilityInfo : NSObject
@property (nonatomic, copy, nullable) NSString *content;
@property (nonatomic, copy, nullable) NSString *linkText;
@property (nonatomic, copy, nullable) NSString *link;
@property (nonatomic, assign) ns_zoom_messager::BCLinkType linkType;
@property (nonatomic, assign) BOOL isViewInWindowEnabled;
@end
#endif

@interface ZMOriginalMessageInfo : NSObject
@property (nonatomic, copy, nullable) NSString *sessionId;
@property (nonatomic, copy, nullable) NSString *msgId;
@property (nonatomic, assign) NSInteger timestamp;
@property (nonatomic, assign) BOOL showAttribute;
@property (nonatomic, assign) BOOL isGroup;
@property (nonatomic, assign) BOOL isFromPublicChannel;
@property (nonatomic, assign) BOOL viewMore;
@property (nonatomic, assign) NSInteger msgCount;
@end

@interface ZMMarkUnreadMessageMentionInfo : NSObject
@property (nonatomic, assign) NSInteger markUnreadCount;
@property (nonatomic, assign) NSInteger markUnreadMentionCount;
@property (nonatomic, assign) ZMMarkUnreadMessageMentionType mentionType;
@end

NS_ASSUME_NONNULL_END

#endif /* ZMMessageAdapterCompat_h */

