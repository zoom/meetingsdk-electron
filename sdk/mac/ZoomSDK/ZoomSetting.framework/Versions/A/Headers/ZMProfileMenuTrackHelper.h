//
//  ZMProfileMenuTrackHelper.h
//  ZoomUnit
//
//  Created by kay fu on 2025/4/22.
//

#import <Foundation/Foundation.h>
#import <ZoomUnit/ZMClientV2EventTelemetry.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZMProfileMenuTrackHelper : NSObject

// MARK: - AIC
+ (void)trackAICProductType:(e_client_ClientInteract_product_type)productType
                eventSource:(e_client_ClientInteract_event_source)eventSource
                featureName:(e_client_ClientInteract_feature_name)featureName
              eventLocation:(e_client_ClientInteract_event_location)eventLocation
                  eventType:(e_client_ClientInteract_event_type)eventType
                  eventName:(e_client_ClientInteract_event_name)eventName
                noticeTitle:(nullable NSString *)noticeTitle
              noticeMessage:(nullable NSString *)noticeMessage;

+ (void)trackPlansAndBillingProfileMenuItemShowAndClick:(BOOL)isShow;

@end

NS_ASSUME_NONNULL_END
