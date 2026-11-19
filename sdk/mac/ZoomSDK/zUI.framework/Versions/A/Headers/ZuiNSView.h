//
//  ZuiNSView.h
//  zUI
//
//  Created by Rob Christenson on 8/27/24.
//

#ifndef ZuiNSView_h
#define ZuiNSView_h

#import <Cocoa/Cocoa.h>

#import <zUI/view.h>
#import <zUI/independent_callbacks.h>

ZUI_API
@interface ZuiNSView : NSView
@property (nonatomic, assign) std::shared_ptr<zui::ViewNode> viewPtr;
@property (nonatomic, assign, readonly) std::shared_ptr<zui::View> zuiView;//The blue print C++ class object

- (instancetype)initWithView:(const zui::View&)zuiView;
- (void)registerOnSizeCallback:(zui::OnSizeUpdateFunc)pFunc;
- (void)registerOnSizeCallbackSimple:(zui::OnSizeUpdateFuncSimple)pFunc;
- (void)registerOnSizeCallbackWithContext:(zui::OnSizeUpdateFuncWithContext)pFunc;

@end


#endif /* ZuiNSView_h */
