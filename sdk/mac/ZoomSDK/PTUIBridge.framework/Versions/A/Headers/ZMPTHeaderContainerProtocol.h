//
//  ZMPTHeaderContainerProtocol.h
//  PTUIBridge
//
//  Created by fistice on 6/12/25.
//

#ifndef ZMPTHeaderContainerProtocol_h
#define ZMPTHeaderContainerProtocol_h

typedef NS_ENUM(NSUInteger, ZMPTNavigationType) {
    ZMPTNavigationTypeNone,
    //left
    ZMPTNavigationTypeLeftBegin,
    ZMPTNavigationTypeLogo,
    ZMPTNavigationTypeLeftEnd,
    //center
    ZMPTNavigationTypeCenterBegin,
    ZMPTNavigationTypeBack,
    ZMPTNavigationTypeForward,
    ZMPTNavigationTypeHistory,
    ZMPTNavigationTypeSearch,
    ZMPTNavigationTypeNewBusiness,
    ZMPTNavigationTypeCenterEnd,
    //right
    ZMPTNavigationTypeRightBegin,
    ZMPTNavigationTypePersistentUpgradeBtn,
    ZMPTNavigationTypeDisasterModeBtn,
    ZMPTNavigationTypeZrDetectBtn,
//    ZMPTNavigationTypeHelpBtn,
    ZMPTNavigationTypeNotificationBtn,
    ZMPTNavigationTypeCalendarBtn,
    ZMPTNavigationTypeAICBtn,
    //profile
    ZMPTNavigationTypeProfileBtn,
    ZMPTNavigationTypeUpdateBtn,
    ZMPTNavigationTypeRightEnd,
    
    ZMPTNavigationTypeEnd,

};

@protocol ZMPTHeaderContainerProtocol <ZMPTRoutableObject>

- (void)addView:(NSView *)view forType:(ZMPTNavigationType)type;
- (void)removeViewForType:(ZMPTNavigationType)type;
- (NSView *)viewForType:(ZMPTNavigationType)type;
@property (nonatomic, assign) BOOL needsLayout;
@property (readonly) NSView *view;
@end

#endif /* ZMPTHeaderContainerProtocol_h */
