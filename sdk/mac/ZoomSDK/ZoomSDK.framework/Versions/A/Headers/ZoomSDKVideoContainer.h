/**
 * @file ZoomSDKVideoContainer.h
 * @brief Interfaces for managing video render elements for customized UI in Zoom SDK.
 */


#import <Foundation/Foundation.h>
#import <ZoomSDK/ZoomSDKErrors.h>
NS_ASSUME_NONNULL_BEGIN

@class  ZoomSDKVideoContainer;

/**
 * @class ZoomSDKVideoElement
 * @brief Interface for video element rendering in custom UI.
 * @note This class is available only for custom UI.
 */
@interface ZoomSDKVideoElement : NSObject
{
    VideoRenderElementType _elementType;
    VideoRenderDataType    _dataType;
    unsigned int           _userid;
    NSView*                _videoView;
    NSRect                 _viewFrame;
}
/**
 * @brief The user ID for this video element.
 */
@property(nonatomic, assign)unsigned int userid;
/**
 * @brief The view used to render video.
 */
@property(nonatomic, retain, nullable)NSView* videoView;
/**
 * @brief Creates object of video elements for each user.
 * @param rect Frame of video view.
 */
- (id)initWithFrame:(NSRect)rect;
/**
 * @brief Sets whether to show video.
 * @param show YES if displaying video, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)showVideo:(BOOL)show;
/**
 * @brief Gets the video's type render element: preview, active, or normal.
 * @return The video render element's type.
 */
- (VideoRenderElementType)getElementType;
/**
 * @brief Gets data type of video render: avatar or video.
 * @return The data type of the video render.
 */
- (VideoRenderDataType)getDataType;
/**
 * @brief Gets NSView object in the element.  
 * @return The point of the video view. 
 */
- (NSView*)getVideoView;
/**
 * @brief Resize the video view according to your requirements.
 * @param frame Custom frame of video view.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)resize:(NSRect)frame;

/**
 * @brief Config the video view resolution.
 * @param resolution Custom resolution of video view.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setResolution:(ZoomSDKVideoRenderResolution)resolution;
@end


/**
 * @class ZoomSDKPreViewVideoElement
 * @brief Subclass of ZoomSDKVideoElement for preview video.
 */
@interface ZoomSDKPreViewVideoElement : ZoomSDKVideoElement
/**
 * @brief Sets whether to preview video.
 * @param start YES if starting preview, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startPreview:(BOOL)start;
@end


/**
 * @class ZoomSDKActiveVideoElement
 * @brief Subclass of ZoomSDKVideoElement for active speaker video.
 */
@interface ZoomSDKActiveVideoElement : ZoomSDKVideoElement
/**
 * @brief Sets whether to display active video.
 * @param start YES if starting active video, NO otherwise.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)startActiveView:(BOOL)start;
@end


/**
 * @class ZoomSDKNormalVideoElement
 * @brief Subclass of ZoomSDKVideoElement for normal participant video.
 */
@interface ZoomSDKNormalVideoElement : ZoomSDKVideoElement
/**
 * @brief Sets whether to display user's video. 
 * @param subscribe YES to display user's avatar or video, NO to display a black background.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)subscribeVideo:(BOOL)subscribe;
@end


/**
 * @protocol ZoomSDKVideoContainerDelegate
 * @brief Protocol for receiving callbacks from video container.
 */
@protocol ZoomSDKVideoContainerDelegate <NSObject>
/**
 * @brief Callback of user ID changes in the video container.
 * @param element Element of the new user.
 * @param userid The ID of changed user.
 */
- (void)onRenderUserChanged:(ZoomSDKVideoElement*_Nullable)element User:(unsigned int)userid;

/**
 * @brief Callback of user data changes in the video container.
 * @param element Element of the new user.
 * @param type Data type of the current user.
 */
- (void)onRenderDataTypeChanged:(ZoomSDKVideoElement*_Nullable)element DataType:(VideoRenderDataType)type;

/**
 * @brief Callback of user's subscription failed.
 * @param error The failed reason.
 * @param element The point of video element to the user.
 */
- (void)onSubscribeUserFail:(ZoomSDKVideoSubscribeFailReason)error videoElement:(ZoomSDKVideoElement*)element;
@end


/**
 * @class ZoomSDKVideoContainer
 * @brief Container class to manage multiple video elements.
 */
@interface ZoomSDKVideoContainer : NSObject
{
    id<ZoomSDKVideoContainerDelegate> _delegate;
    NSMutableArray*                          _elementArray;
}
/**
 * @brief Delegate for video container callbacks.
 */
@property(nonatomic,assign, nullable) id<ZoomSDKVideoContainerDelegate> delegate;

/**
 * @brief Creates a preview video element in the video container.
 * @param element An object of ZoomSDKPreViewVideoElement.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)createPreViewVideoElement:(ZoomSDKPreViewVideoElement*_Nonnull*_Nonnull)element;
 
/**
 * @brief Creates a normal video element in the video container.
 * @param element An object of ZoomSDKNormalVideoElement.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)createNormalVideoElement:(ZoomSDKNormalVideoElement*_Nonnull*_Nonnull)element;
 
/**
 * @brief Creates an active video element in the video container.
 * @param element An object of ZoomSDKActiveVideoElement.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)createActiveVideoElement:(ZoomSDKActiveVideoElement*_Nonnull*_Nonnull)element;

/**
 * @brief Destroy an existed video element in the video container.
 * @param element An object of ZoomSDKVideoElement.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cleanVideoElement:(ZoomSDKVideoElement*)element;

/**
 * @brief Gets the list of video element.
 * @return If the function succeeds, it returns an array containing ZoomSDKVideoElement object. Otherwise, this function fails and returns nil.
 */
- (NSArray*_Nullable)getVideoElementList;
@end
NS_ASSUME_NONNULL_END
