//
//  ZMUnifyWebViewExtraData.h
//  zChatComponent
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMProfileConfig.h>
#import <zUnifyWebViewApp/ZMUnifyWebViewService.h>
#import <ZoomUnit/ZMProfileConfig.h>

NS_ASSUME_NONNULL_BEGIN

/// Mostly the same data as `ZMWebViewBaseView`. For webview v1/v2 compatability
@interface ZMUnifyWebViewExtraData : NSObject
@property (nullable, nonatomic, retain) NSString* identifierValue;
@property (nullable, nonatomic, retain) ZMProfileConfig* floatConfig;
@property (nonatomic, assign) NSInteger resourceType;
@end


@interface NSObject (ZMUnifyWebViewProtocolExtraData)
@property (nullable, nonatomic, strong) ZMUnifyWebViewExtraData* unifyWebViewExtraData;
@end

NS_ASSUME_NONNULL_END
