//
//  ZMPersonNoteActiveTimeBanner.h
//  ChatUI
//
//  Created by simon shang on 2021/8/17.
//  Copyright © 2021 Zoom. All rights reserved.
//


@class ZMBuddyAdapter;

NS_ASSUME_NONNULL_BEGIN

typedef void(^ChangeButtonClicked)(void);
typedef void(^EndTimeUpCallBack)(void);

@interface ZMPersonNoteActiveTimeBanner : ZMBaseView
- (instancetype)initWithBuddyJid:(NSString* _Nonnull)jid;
@property (nonatomic, copy) ChangeButtonClicked changeButtonClicked;
@property (nonatomic, copy) EndTimeUpCallBack endTimeUpCallBack;

@end

NS_ASSUME_NONNULL_END
