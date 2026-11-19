//
//  ZMChatSearchProtocol.h
//  zChatBase
//
//  Moved from zChatComponent to zChatBase to decouple clients (e.g. zVideoUI)
//  from zChatComponent when only the search protocol is needed.
//
//  NOTE:
//  - Keep this header pure ObjC (no mandatory C++ includes).
//  - Avoid importing heavy chat component headers; use forward declarations.
//

#ifndef ZMChatSearchProtocol_h
#define ZMChatSearchProtocol_h

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <Prism/ZMCallbackImpl.h> // ZMCallbackBlock

@class ZMSearchBuddyParam;
@class ZMSessionGroupAdapter;
@class ZMSearchResultItem;
@class ZMExhaustiveMemberSearchFilter;
@class ZMExhaustiveMemberSearchResult;
@class ZMBatchContactSearchResult;
@class ZMChannelSearchFilter;

typedef NS_ENUM(NSUInteger, ZMGroupSearchType) {
    ZMGroupSearchTypeAll,
    ZMGroupSearchTypeMUC,
    ZMGroupSearchTypeGroup,
};

typedef NS_ENUM(NSUInteger, ZMNewChatsSearchType) {
    ZMNewChatsDefaultSearchType,
    ZMNewChatsContactSearchType,
    ZMNewChatsGroupSearchType,
    ZMNewChatsAllSearchType,
};

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatSearchProtocol <NSObject>

@optional

- (nullable NSString *)async_searchLocalContactsByKey:(NSString *)key;

- (nullable NSString *)asyn_searchLocalContactsByKey:(nonnull NSString *)key
                                             fliter:(ZMLoacalContactSearchFilter)fliter
                                           callBack:(nonnull ZMCallbackBlock)callBack;

- (nullable NSString *)searchContactAndChannelByKey:(nonnull NSString *)key
                                           sortType:(ZMContactAndChannelSortType)sortType
                                           callBack:(nonnull ZMCallbackBlock)callBack;

- (nullable NSString *)searchRemoteBuddy_V2:(nonnull NSString *)key
                                searchParam:(nullable ZMSearchBuddyParam *)searchParam
                                  callBack:(nonnull ZMCallbackBlock)callBack;

- (void)removeSearchCallBackByKey:(nonnull NSString *)callbackKey;
- (void)addContactsLocalSearchCallBackKey:(nonnull NSString *)callbackKey
                                      key:(nonnull NSString *)key
                                    block:(nonnull ZMCallbackBlock)completion;

- (BOOL)searchRemoteBuddy:(NSString *)key
                 callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

- (NSArray<ZMSearchResultItem *> *)searchChannelMembersByKey:(NSString *)key
                                                   channelId:(NSString *)channelId;

// if key is empty, will get recent groups
- (nullable NSArray<ZMSessionGroupAdapter *> *)searchGroupByKey:(nullable NSString *)key;

- (NSArray<ZMSearchResultItem *> *)recentChatAndStarredSessionItems;
- (NSArray<ZMSearchResultItem *> *)recentChatSessionItems;
- (NSArray<ZMSearchResultItem *> *)recentChatBuddiesItems;
- (NSArray<ZMSearchResultItem *> *)recentChatGroupsItems;
- (NSArray<ZMSearchResultItem *> *)mostFrequentSessionsWithType:(ZMNewChatsSearchType)type;
- (NSArray<ZMSearchResultItem *> *)getLocalStrictSearchBuddies;
- (NSArray<ZMSearchResultItem *> *)channelMembersByChannelId:(NSString *)channelId
                                      sortExternalUsersToEnd:(BOOL)bSortExternalUsersToEnd;

- (NSMutableDictionary *)recentForwardMsgSessionItems;

// Some files call this selector name (duplicate in legacy header). Keep for compatibility.
- (void)removeSearchCallBackByKey:(nonnull NSString *)key;

- (BOOL)searchChannelMember:(nonnull NSString *)channelId
                    keyword:(nonnull NSString *)keyword
                   callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

#ifdef __cplusplus
- (void)didSearchChannelMember:(NSInteger)result
                searchResponse:(const ns_zoom_messager::ChannelMemberSearchResponse &)searchResponse
                         reqId:(nullable NSString *)reqId;

- (void)didExhaustiveMemberSearch:(NSInteger)error
                           result:(ns_zoom_messager::ExhaustiveContactSearchResult const&)result
                            reqID:(NSString *)reqID;

- (void)didBatchContactSearch:(uint32_t)result
                     contacts:(ns_zoom_messager::arrContactSearchResult const&)contacts
                        reqId:(NSString*)reqId;

- (void)didSearchChannelByKeyword:(nullable NSString *)keyword
                           result:(NSInteger)result
                   searchResponse:(const NS_ZOOM_MESSAGER::ChannelSearchResponse&)response
                            reqId:(NSString *)reqId;
#endif

- (NSString*)exhaustiveSearchMember:(ZMExhaustiveMemberSearchFilter*)filter
                          callback:(void(^)(NSString* key, ZMExhaustiveMemberSearchResult* results, NSError* error))callback;

- (NSInteger)batchSearchContactMaxEmailAmount;
- (NSString*)batchSearchContactsByEmails:(NSArray<NSString*>*)emails
                                callback:(void(^)(NSString* reqId, NSArray<ZMBatchContactSearchResult*>* contacts, NSError* error))callback;

- (nullable NSString *)searchChannelByKeyword:(nullable NSString *)keyword
                                    callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

- (BOOL)searchChannelByKeyword:(nullable NSString *)keyword
                 channelFilter:(ZMChannelSearchFilter *)channelFilter
                      callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

- (BOOL)searchArchivedChannelByKeyword:(nullable NSString *)keyword
                              callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

// ZOOM-423027
- (BOOL)queryIfUsersInChannelRequest:(nonnull NSString *)channelId
                                jids:(nonnull NSArray<NSString*> *)jidArray
                            callBack:(void(^)(NSString *key, NSArray<NSString *> *jidArray, NSError *error))callBack;

- (void)didQueryIfUsersInChannelRequest:(nonnull NSString *)reqId
                                 result:(NSInteger)result
                                   jids:(nonnull NSArray<NSString*> *)jidArray;

- (NSString *)searchGroupsByBuddies:(NSArray<NSString *> *)jids
                          groupType:(NSInteger)type
                           maxCount:(NSInteger)maxCount
                         completion:(nonnull ZMCallbackBlock)completion;
- (void)didSearchGroupsByJids:(NSArray<NSString *> *)channelIds requestID:(NSString*)requestID;

// ZOOM-382630
- (void)disableInputContainerWhenSearchMUCs;
- (void)enableInputContainerWhenSearchMUCs;

- (BOOL)checkResults:(NSArray<ZMSearchResultItem *> *)results filter:(NSInteger)filter;
- (BOOL)supportSearchContactWithKey:(NSString*)key;

@end

#ifndef ZMShareChatSearchProtocol
#define ZMShareChatSearchProtocol (id<ZMChatSearchProtocol>)ZMSharedFor(ZMChatSearchProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMChatSearchProtocol_h */

