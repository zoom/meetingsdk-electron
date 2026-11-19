//
//  IZPGDPRConfirmDlg.h
//  PTUIBridge
//
//  Created by AI Assistant.
//  Copyright © 2024 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IZPGDPRConfirmDlg <NSObject>
- (void)showGDPRWithServiceUrl:(NSString *)serviceUrl privacy:(NSString *)privacyUrl;
@end

NS_ASSUME_NONNULL_END

