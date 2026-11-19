//
//  ZMChatUIEXInterfaceProtocol.h
//  zChatBase
//
//  Moved from ChatUIEx to zChatBase for dependency inversion.
//

#pragma once

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZMChatUIEXInterfaceProtocol <NSObject>

- (void)onZoomLoginFinished;
- (void)onZoomLogoutFinished;

/// Legacy callback after chat UI extension resources become available.
- (void)onInstallbuddle;

@end

NS_ASSUME_NONNULL_END

