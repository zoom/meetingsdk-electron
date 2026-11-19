//
//  ZMSearchHelper.h
//  zChatComponent
//
//  Created by groot.ding on 8/7/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ZMSearchResultItem;
@class ZMBuddyAdapter;
@class ZMPersonalFolderMemberMode;
@class ZMPersonalFolderItemMode;

@interface ZMSearchHelper : NSObject

+ (void)addContactsLocalSearchCallBackKey:(NSString *)callbackKey
                                      key:(NSString *)key
                                    block:(ZMCallbackBlock)completion;

+ (void)removeSearchCallBackByKey:(NSString *)callbackKey;

+ (void)addSearchCallBackByKey:(NSString *)callBackKey key:(NSString*)key block:(ZMCallbackBlock)completion;

+ (void)searchCallBackByKey:(NSString *)callBackKey key:(NSString*)key param:(id)param error:(nullable NSError*)error;

+ (NSString *)async_searchLocalContactsByKey:(NSString *)key;

+ (nullable NSString *)asyn_searchLocalContactsByKey:(NSString *)key
                                            maxCount:(NSInteger)maxCount
                                              fliter:(NSInteger)fliter;

+ (NSArray <ZMSearchResultItem *> *)recentChatBuddiesItems;

+ (NSArray<ZMPersonalFolderMemberMode *> *)getPersonalFolderMemberListWithFolderId:(NSString *)folderId;

+ (NSArray<ZMPersonalFolderItemMode *> *)getPersonalFolderList;

+ (NSArray <NSString *> *)getLastOpenSessionId;

+ (NSArray<NSString *> *)getLastOpenSessionAndFolderedSessionItemsWithSort:(BOOL)sort;

+ (NSArray <ZMSearchResultItem *> *)getResultItemsByBuddyIds:(NSArray <NSString *>*)ids
                                                      filter:(NSInteger)filter
                                                   searchKey:(NSString *)searchKey;

+ (NSArray *)getAssignGroupSearchData;

+ (void)onAssignGroupSearchBuddyByKey:(NSString*)key result:(unsigned int)result;

+ (void)onSearchBuddyByKey:(NSString*)key result:(unsigned int)result reqId:(NSString *)reqId;

+ (void)didSearchBuddy:(NSUInteger)result key:(NSString*)key jids:(NSArray <NSString *> *)jids reqId:(NSString *)reqId;

+ (void)onLocalContactsBackWithRequestID:(NSString*)requestID results:(NSArray*)results;

+ (nullable NSString *)searchContactFromAsyncWithKey:(NSString *)key
                                         contactType:(NSString *)contactType
                                           reqSource:(NSString *)reqSource
                                              siteId:(nullable NSString *)siteId
                                            callBack:(ZMCallbackBlock)callBack;

+ (NSArray <ZMSearchResultItem *> *)sortContactResultByKeyAndMsgTimeWithItems:(NSArray <ZMSearchResultItem *> *)items;

+ (NSArray <ZMSearchResultItem *> *)sortContactResultByKeyAndMsgTimeWithItemsV2:(NSArray <NSString *> *)results key:(NSString *)key;
+ (NSArray <ZMSearchResultItem *> *)sortResultByKeyAndMsgTimePreservingItems:(NSArray<ZMSearchResultItem *> *)items;

+ (NSArray <ZMSearchResultItem *> *)getResultItemsBySessionIds:(NSArray <NSString *> *)sessionIds;

+ (NSArray <NSString *> *)getResultItemsIds:(NSArray <ZMSearchResultItem *> *)items;

+ (NSArray <ZMSearchResultItem *> *)sortContactResultByKeyAndMsgTimeWithSessionIds:(NSArray <NSString *> *)results;

+ (NSArray <NSString *> *)sortContactSearchResultWithResults:(NSArray *)resluts withFilter:(NSInteger)filterValue;

+ (void)sortSearchResultItemsByName:(NSMutableArray <ZMSearchResultItem *> *)items;

+ (BOOL)match:(NSString *)key buddy:(ZMBuddyAdapter *)buddy;

+ (BOOL)isPassed:(ZMBuddyAdapter*)buddyAdapter withFilter:(NSInteger)filterValue;

@end

NS_ASSUME_NONNULL_END
