//
//  IZMMailHelper.h
//  PTUIBridge
//
//  Created by Lester.Gong on 2025/10/9.
//

#ifndef IZMMailHelper_h
#define IZMMailHelper_h

@protocol IZMMailHelper <NSObject>

- (void)onMailKBServiceFinishInit:(BOOL)success isFirstDevice:(BOOL)isFirstDevice;

@end
#endif /* IZMMailHelper_h */
