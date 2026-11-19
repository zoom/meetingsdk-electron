//
//  ZMAICWebViewController.h
//  ZoomAIC
//
//  Created by Howie Xu on 2/13/26.
//

#import <ZoomKit/ZoomKit.h>
#import <Prism/Prism.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMAICWebContainerLoadBlock)(BOOL success);

@interface ZMAICWebViewController : ZMBaseViewController

@property (nonatomic, copy) ZMAICWebContainerLoadBlock loadBlock;
@property (nonatomic, copy) NSString *homeURL;

- (void)loadRemoteURL:(NSString *)url;
- (void)makeFirstResponderIfPossible;
- (BOOL)checkIsWebViewReady;
- (void)cleanUp;

@end

NS_ASSUME_NONNULL_END
