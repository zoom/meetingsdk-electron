//
//  ZMChatUIVCardLocalModule.h
//  zChatComponent
//
//  In-process implementation of the ChatUI-free vCard subset of
//  ZMChatUIInterfaceProtocol (see ZMChatUIVCardLocalProtocol). Registered via
//  @routerable in both the PT and Meeting process so meeting-side vCard code keeps
//  working when ChatUI's ZMChatUIInterface is absent.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMChatUIVCardLocalProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMChatUIVCardLocalModule : NSObject <ZMChatUIVCardLocalProtocol>

+ (instancetype)shared;

@end

NS_ASSUME_NONNULL_END
