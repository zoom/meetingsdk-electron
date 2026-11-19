//
//  ZMCEventTrackerProtocol.h
//  zChatComponent
//
//  Created by Mario Rao on 3/17/23.
//

@class ZMChatMsgItemInfo;

#import <Foundation/Foundation.h>
#import <Prism/ZMRoutableObject.h>

#ifdef __cplusplus
#include <zTelemetryBiz/zTelemetryBizInterface.h>
#include <zTelemetryBiz/SnowplowBiz/chat_v2/chat_v2_telemetry_interface.h>
#include <zEventTracker/SettingEventTrackingConst.h>
#import <zEventTracker/PTEventTrackingHelper.h>
#endif
// Avoid importing PTUIBridge headers here (non-modular/ordering issues under module builds).
@protocol ZMCEventTrackerProtocol <ZMRoutableObject>

#ifdef __cplusplus

+ (void)trackClientInteractInfoWithEventType:(e_client_ClientInteract_event_type)eventType
                                 eventSource:(e_client_ClientInteract_event_source)eventSource
                                 featureName:(e_client_ClientInteract_feature_name)featureName
                               eventLocation:(e_client_ClientInteract_event_location)eventLocation
                                   eventName:(e_client_ClientInteract_event_name)eventName
                                     context:(nullable NSString *)context
                                      reason:(nullable NSString *)reason
                               meetingNumber:(NSInteger)meetingNumber
                                         jid:(nullable NSString *)jid;

+ (void)trackChatEventWithNameV2:(e_Interaction_event_name)name
                     featureName:(e_Interaction_feature_name)featureName
                      subFeature:(e_Interaction_sub_feature_name)subFeatureName
                          source:(e_Interaction_event_source)source
                        location:(e_Interaction_event_location)location
                       eventType:(e_Interaction_event_type)eventType
                             jid:(NSString *)jid
                         context:(NSString *)context;

+ (void)trackChatEventWithNameV2:(e_Interaction_event_name)name
                   featureName:(e_Interaction_feature_name)featureName
                    subFeature:(e_Interaction_sub_feature_name)subFeatureName
                        source:(e_Interaction_event_source)source
                      location:(e_Interaction_event_location)location
                     eventType:(e_Interaction_event_type)eventType
                           jid:(NSString *)jid
                         msgID:(NSString *)msgID
                       context:(NSString *)context;

+ (void)trackChatFileEventWithNameV2:(e_Interaction_event_name)name
                         featureName:(e_Interaction_feature_name)featureName
                          subFeature:(e_Interaction_sub_feature_name)subFeatureName
                              source:(e_Interaction_event_source)source
                            location:(e_Interaction_event_location)location
                           eventType:(e_Interaction_event_type)eventType
                                 jid:(NSString *)jid
                           msgStruct:(ChatV2FileTransferEntityParams)msg
                             context:(NSString *)context;

+ (void)trackChatEventWithNameV2:(e_Interaction_event_name)name
                     featureName:(e_Interaction_feature_name)featureName
                      subFeature:(e_Interaction_sub_feature_name)subFeatureName
                          source:(e_Interaction_event_source)source
                        location:(e_Interaction_event_location)location
                       eventType:(e_Interaction_event_type)eventType
                             jid:(NSString *)jid
                       msgStruct:(ChatV2MessageEntityParams)msg
                         context:(NSString *)context;

// Chat App
+ (void)trackingChatAppEventWithName:(e_Interaction_event_name)name
                         featureName:(e_Interaction_feature_name)featureName
                          subFeature:(e_Interaction_sub_feature_name)subFeatureName
                              source:(e_Interaction_event_source)source
                            location:(e_Interaction_event_location)location
                           eventType:(e_Interaction_event_type)eventType
                               botId:(NSString *)botId
                             botName:(NSString *)botName
                         actionValue:(NSString *)actionValue;

+ (void)trackSettingInteractionOfCategory:(PAAPSettingCategory)category
                              subcategory:(PAAPSettingSubcategory)subcategory
                              settingName:(PAAPSettingName)name
                              settingType:(PAAPSettingType)type
                                 oldValue:(NSString *)oldValue
                                 newValue:(NSString *)newValue
                                  context:(NSString *)context;

#endif

+ (void)trackPresenceWithPresenceType:(ZMIMBuddyPresenceType)presenceType;


// Settings
+ (void)trackSettingInteractionWithSource:(NSUInteger)source
                                  feature:(NSUInteger)feature
                                 location:(NSUInteger)location
                                     name:(NSUInteger)name
                                  context:(nullable NSString *)context;
//header button
+ (void)trackingNavigationClickEventWithButtonType:(NSUInteger)buttonType;

@end
