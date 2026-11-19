//
//  IZMH323CallViewController.h
//  PTUIBridge
//
//  Created by fistice on 11/14/25.
//

#ifndef IZMH323CallViewController_h
#define IZMH323CallViewController_h
#import <PTUIBridge/ZMPTRouterCenter.h>

@protocol IZMH323CallViewController<ZMPTRoutableObject>
- (void)showCallSipView;
- (BOOL)isShowing;
@end
#endif /* IZMH323CallViewController_h */
