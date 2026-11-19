//
//  ZMWebViewBaseView.h
//  zChatUI
//
//  Created by Jed Zheng on 29/11/2022.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import "zoom_client_conf.h"
#ifdef ENABLE_ZAPP
#import <zUnifyWebViewApp/ZMUnifyWebViewProtocol.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewDefine.h>
#import <zUnifyWebViewApp/ZMUnifyWebView.h>
#endif

@interface ZMWebViewBaseView : ZMBaseView
@property (nonatomic, retain) NSString *moduleIdentifier;
@property (nonatomic, retain) NSString *identifierValue;
@property (nonatomic, retain) ZMProfileConfig *floatConfig;
@property (nonatomic, assign) NSInteger resourceType;
@property (nonatomic, assign) NSSize zm_intrinsicContentSize;

#ifdef ENABLE_ZAPP
@property(nonatomic, retain)id<ZMUnifyWebViewProtocol> zAppWebView;
#endif

@end
