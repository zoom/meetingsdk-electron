//
//  ZMRingtoneHelper.h
//  PTUIBridge
//
//  Created by fistice on 7/3/25.
//

#ifndef ZMRingtoneHelper_h
#define ZMRingtoneHelper_h

#ifdef __cplusplus
#import <zVideoApp/Confdef.h>
#endif
@protocol IZMRingtoneHelper <NSObject>

- (NSString*)getMeetingRingtonePath:(NSString*)jid;
- (float)getRingtoneVolume;
- (NSString*)getCCIRingtonePath;
#ifdef __cplusplus
- (void)addAudioFeature:(Feature)feature;
- (void)releaseAudioFeature:(Feature)feature;
#endif
@end

#define ZMRingtoneHelper ZMSharedFor(IZMRingtoneHelper)
#endif /* ZMRingtoneHelper_h */
