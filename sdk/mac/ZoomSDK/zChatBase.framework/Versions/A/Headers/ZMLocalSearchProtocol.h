//
//  ZMLocalSearchProtocol.h
//  zChatBase
//
//  Chat-search methods whose implementation does NOT depend on ChatUI and can
//  therefore run in-process inside the Meeting subprocess. The concrete
//  implementation lives in zChatComponent (ZMLocalSearchModule) and is
//  registered via @routerable, so ZMShareLocalSearch resolves in both the PT
//  and the Meeting process.
//
//  Background: ZMChatSearchProtocol is implemented by ChatUI's ZMSearchModule,
//  which only exists in the PT process. In the Meeting subprocess
//  ZMShareChatSearchProtocol resolves to nil. The methods declared here were
//  split out so meeting-side chat search keeps working without crossing the
//  process boundary.
//
//  NOTE:
//  - Keep this header pure ObjC (no mandatory C++ includes), like
//    ZMChatSearchProtocol.h, so clients that only link zChatBase (e.g. VideoUIEx)
//    can import it.
//  - Signatures must match ZMChatSearchProtocol exactly so existing call sites
//    compile unchanged after switching to ZMShareLocalSearch.
//

#ifndef ZMLocalSearchProtocol_h
#define ZMLocalSearchProtocol_h

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>
#import <Prism/ZMCallbackImpl.h> // ZMCallbackBlock

@class ZMSearchBuddyParam;
@class ZMSessionGroupAdapter;
@class ZMSearchResultItem;
@class ZMExhaustiveMemberSearchFilter;
@class ZMExhaustiveMemberSearchResult;

NS_ASSUME_NONNULL_BEGIN

@protocol ZMLocalSearchProtocol <NSObject>

@optional

- (void)removeSearchCallBackByKey:(nonnull NSString *)callbackKey;

- (nullable NSString *)asyn_searchLocalContactsByKey:(nonnull NSString *)key
                                              fliter:(ZMLoacalContactSearchFilter)fliter
                                            callBack:(nonnull ZMCallbackBlock)callBack;

- (nullable NSString *)searchRemoteBuddy_V2:(nonnull NSString *)key
                                searchParam:(nullable ZMSearchBuddyParam *)searchParam
                                   callBack:(nonnull ZMCallbackBlock)callBack;

// if key is empty, will get recent groups
- (nullable NSArray<ZMSessionGroupAdapter *> *)searchGroupByKey:(nullable NSString *)key;

- (NSString *)exhaustiveSearchMember:(ZMExhaustiveMemberSearchFilter *)filter
                            callback:(void(^)(NSString *key, ZMExhaustiveMemberSearchResult *results, NSError *error))callback;

- (BOOL)searchChannelMember:(nonnull NSString *)channelId
                    keyword:(nonnull NSString *)keyword
                   callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

- (BOOL)searchArchivedChannelByKeyword:(nullable NSString *)keyword
                              callBack:(void(^)(NSString *key, NSArray<ZMSearchResultItem *> *items, NSError *error))callBack;

- (BOOL)queryIfUsersInChannelRequest:(nonnull NSString *)channelId
                                jids:(nonnull NSArray<NSString *> *)jidArray
                            callBack:(void(^)(NSString *key, NSArray<NSString *> *jidArray, NSError *error))callBack;

@end

#ifndef ZMShareLocalSearch
#define ZMShareLocalSearch (id<ZMLocalSearchProtocol>)ZMSharedFor(ZMLocalSearchProtocol)
#endif

NS_ASSUME_NONNULL_END

#endif /* ZMLocalSearchProtocol_h */
