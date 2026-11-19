//
//  IZPPTMediaHelper.h
//  PTUIBridge
//
//  Created by fistice on 7/3/25.
//

#import <PTUIBridge/ZPPTAudioRingProtocol.h>

@protocol IZPPTBaseRingHelperProtocol <NSObject>
- (int)startRinging;
- (void)stopRinging;
@end
@protocol IZPPTMediaHelper <ZPPTAudioRingProtocol>
@property (readonly) id<IZPPTBaseRingHelperProtocol> cciRingHelper;
@end
