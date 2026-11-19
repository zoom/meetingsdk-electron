//
//  ZMPTTabNavigationProtocol.h
//  ChatUI
//
//  Created by Kay Fu on 10/30/24.
//  Copyright © 2024 Zoom. All rights reserved.
//

@protocol ZMPTTabNavigationProtocol
@optional
- (void)navigationToURL:(NSString *)url;
- (void)navigationToURL:(NSString *)url isNavigateAction:(BOOL)isNavigateAction;
- (void)navigationWithExtParams:(NSDictionary *)extParams;
@end
