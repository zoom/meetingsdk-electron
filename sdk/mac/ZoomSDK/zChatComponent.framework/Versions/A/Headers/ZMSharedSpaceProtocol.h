//
//  ZMSharedSpaceProtocol.h
//  zChatComponent
//
//

#import <Foundation/Foundation.h>
#import <zChatComponent/ZMMemberInformationProtocol.h>

#ifndef ZMSharedSpaceProtocol_h
#define ZMSharedSpaceProtocol_h

NS_ASSUME_NONNULL_BEGIN

@class ZMPublicRoomInfo;
extern ZMMemberInformationSourceType const kZMMemberInformationSourceType_SharedSpace;

@protocol ZMSharedSpaceInfoProtocol <ZMMemberInformationProtocol>
@property (nonatomic, readonly, assign) BOOL currentUserIsAdmin;
@property (nonatomic, readonly, assign) BOOL currentUserCanAddMembers;
- (BOOL)userIsAdmin:(NSString*)jid;
- (BOOL)userIsOwner:(NSString*)jid;
- (NSArray <ZMPublicRoomInfo *> *)localSearchOpenChannelWithKeywords:(NSString *)keywords;
- (NSArray <ZMPublicRoomInfo *> *)allOpenChannels;

@end

@protocol ZMSharedSpaceProtocol <NSObject>
@property (nonatomic, readonly, assign) BOOL isSharedSpaceEnabled;
/// OP flag. YES iff external, non-contact users can be added to shared spaces by just their email.
- (BOOL)isAddPendingEmailEnabled;
- (BOOL)isSharedSpaceAdminInheritChannelAdminPermissionEnabled;
- (id<ZMSharedSpaceInfoProtocol> _Nullable)spaceByID:(NSString* _Nullable)spaceID;
- (NSString* _Nullable)spaceIDForSessionID:(NSString*)sessionID;
- (BOOL)addUsersByJID:(NSArray<NSString*>*)jids channelID:(NSArray<NSString*>*)channels email:(NSArray<NSString*>*)emails toSpace:(NSString*)spaceID;
- (void)fetchChannelInfosFromXMS:(NSString *)spaceId;
@end

#ifndef ZMShareSharedSpaceProtocol
#define ZMShareSharedSpaceProtocol ((id <ZMSharedSpaceProtocol>)ZMSharedFor(ZMSharedSpaceProtocol))
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMSharedSpaceProtocol_h */
