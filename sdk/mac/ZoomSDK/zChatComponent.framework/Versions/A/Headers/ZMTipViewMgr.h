//
//  ZMTipViewMgr.h
//  zChatComponent
//
//  Created by groot.ding on 6/26/23.
//

#import <Foundation/Foundation.h>
#import <zChatBase/ZMIMCommonDefine.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMTipViewMgr : NSObject
@property (copy) NSString* sessionID;
@property (assign) ZMTipView_Type  tipType;

- (instancetype)initWithFrame:(NSRect)frameRect andTipViewType:(ZMTipView_Type)inType withSessionID:(NSString*)sessionID andUserName:(NSString*)name isNewChatStyle:(BOOL)isNewChatStyle;
- (NSView*)tipView;
- (BOOL)showType:(ZMTipView_Type)inType;
- (void)setExtraData:(NSDictionary* _Nullable)extraData;
- (void)updateUI;
- (void)updateBroadcastView:(ZMTipView_Type)type;
- (void)cleanUp;
@end

NS_ASSUME_NONNULL_END
