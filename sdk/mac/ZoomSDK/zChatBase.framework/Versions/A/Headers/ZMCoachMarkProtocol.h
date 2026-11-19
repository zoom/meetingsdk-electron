//
//  ZMCoachMarkProtocol.h
//  zChatComponent
//
//  Created by Jed Zheng on 26/9/2023.
//

#import <Foundation/Foundation.h>
#import <PTUIBridge/ZMPTRouterCenter.h>
#import <zChatBase/ZMCoachMarkIdentifier.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZMCoachMarkButtonClick) {
    ZMCoachMarkButtonClickNone,
    ZMCoachMarkButtonClickClose,
    ZMCoachMarkButtonClickPrimary,
    ZMCoachMarkButtonClickSecondary
};

///Prority is moved to common file `pt_coach_mark_define.h`

@protocol ZMCoachMarkListenerProtocol <NSObject>

- (void)didReceiveCoachMarkTimerWithIdentifier:(NSString *)identifier;
- (void)addListenReceiveCoachMarkTimerByTarget:(id)target completion:(ZMCallbackBlock)completion;

- (void)removeListenByTarget:(id)target;
@end

@protocol ZMCoachMarkActionProtocol
- (void)registerChatCoachMark;

- (BOOL)isCoachMarkAvailableWithIdentifier:(NSString *)identifier;

- (void)markCoachMarkShowingWithIdentifier:(NSString *)identifier;

- (NSString *)GetShowingCoachMark;

- (void)markCoachMarkShownWithIdentifier:(NSString *)identifier;

- (void)trackCoachMarkCloseWithIdentifier:(NSString *)identifier clickButtonType:(ZMCoachMarkButtonClick)clickButtonType;

- (BOOL)registerCoachMark:(NSString *)coach_mark_id priority:(NSUInteger)priority min_version:(NSString *)min_version max_version:(NSString *)max_version count:(NSUInteger)count;

- (BOOL)registerCoachMark:(NSString *)coach_mark_id priority:(NSUInteger)priority min_version:(NSString *)min_version max_version:(NSString *)max_version count:(NSUInteger)count showForNewUser:(BOOL)showForNewUser;

- (void)unRegisterCoachMark:(NSString *)coach_mark_id;

- (int)getCoachMarkShownCount:(NSString *)coach_mark_id;
@end

@protocol ZMCoachMarkProtocol <ZMPTRoutableObject, ZMCoachMarkListenerProtocol, ZMCoachMarkActionProtocol>
@end


#define ZMPTCoachMarkHelper ZMPTSharedFor(ZMCoachMarkProtocol)
NS_ASSUME_NONNULL_END
