//
//  IZMPTMessengerSinkMgr.h
//  PTUIBridge
//
//  Created by fistice on 7/24/25.
//

#ifndef IZMPTMessengerSinkMgr_h
#define IZMPTMessengerSinkMgr_h


@protocol IZMPTMessengerSinkMgr <NSObject>
- (void)setIMMsgSink:(ns_zoom_messager::IZoomMessengerUI*)sink;
@end

#endif /* IZMPTMessengerSinkMgr_h */
