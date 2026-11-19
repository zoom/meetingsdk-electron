//
//  ZMChatsSessionViewProxy.h
//  zChatBase
//
//  Moved from zChatComponent to zChatBase to avoid cyclic module deps.
//

#ifndef ZMChatsSessionViewProxy_h
#define ZMChatsSessionViewProxy_h

#import <AppKit/AppKit.h>

@protocol ZMChatsSessionViewProxy <NSObject>

- (void)embedContentViewIntoView:(NSView *)view;
- (void)restoreContentViewLayout;

@end

#endif /* ZMChatsSessionViewProxy_h */

