//
//  Header.h
//  ChatUI
//
//  Created by Kay Fu on 2023/12/26.
//  Copyright © 2023 Zoom. All rights reserved.
//

@protocol ZMPopOutWindowMgrProtocol <NSObject>

- (BOOL)isLoaded;

@optional
- (void)zmPopOutWindowWillPopOut;

- (void)zmPopOutWindowDidPopOut;

- (void)zmPopOutWindowWillMergeBack;

- (void)zmPopOutWindowDidMergeBack;

@end

@protocol ZMPopOutMergeBackViewEvent <NSObject>

- (void)onPopOutMergeBackButtonClick;

@end

@protocol ZMPopOutMergeBackViewProtocol <NSObject>

@property (nonatomic,weak) id<ZMPopOutMergeBackViewEvent> delegate;

@end

#define zmPopOutWindowCalendarHome @"zmPopOutWindowCalendarHome"
#define zmPopOutWindowMailHome @"zmPopOutWindowMailHome"
#define zmPopOutWindowPhoneHome @"zmPopOutWindowPhoneHome"
#define zmPopOutWindowFaxHome @"zmPopOutWindowFaxHome"
#define zmPopOutWindowCloseNotifacation @"zmPopOutWindowCloseNotifacation"

#define zmPopOutParamModuleType @"zmPopOutParamModuleType"
#define zmPopOutParamProcessName @"zmPopOutParamProcessName"
#define zmPopOutParamUserAgent @"zmPopOutParamUserAgent"
#define zmPopOutParamZoomControl @"zmPopOutParamZoomControl"
