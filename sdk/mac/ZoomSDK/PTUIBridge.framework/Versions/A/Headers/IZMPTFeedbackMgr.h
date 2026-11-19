//
//  IZMPTFeedbackMgr.h
//  PTUIBridge
//
//  Created by fistice on 7/16/25.
//

#ifndef IZMPTFeedbackMgr_h
#define IZMPTFeedbackMgr_h

@protocol IZMPTFeedbackMgr <ZMPTRoutableObject>

- (void)showWindow:(nullable id)sender;

- (void)showWindow:(nullable id)sender activeTab:(nullable NSString *)activeTab;

- (void)showWindow:(nullable id)sender activeTab:(nullable NSString *)activeTab featureName:(nullable NSString *)featureName;

- (void)close;
@end
#endif /* IZMPTFeedbackMgr_h */
//ZMPTSharedFor(IZMPTFeedbackMgr)
