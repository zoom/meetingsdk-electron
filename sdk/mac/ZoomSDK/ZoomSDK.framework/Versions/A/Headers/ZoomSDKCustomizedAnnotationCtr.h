/**
 * @file ZoomSDKCustomizedAnnotationCtr.h
 * @brief Interface for customized UI  annotation functionality in Zoom SDK.
 */

#import <ZoomSDK/ZoomSDKErrors.h>

NS_ASSUME_NONNULL_BEGIN
@class ZoomSDKShareElement;

/**
 * @struct Color
 * @brief Represents an RGB color with float components.
 */
typedef struct{
    /**
     * @brief Red color component, range is 0 to 255.
     */
    float red;
    /**
     * @brief Green color component, range is 0 to 255.
     */
    float green;
    /**
     * @brief Blue color component, range is 0 to 255.
     */
    float blue;
}Color;

/**
 * @protocol ZoomSDKCustomizedAnnotationDelegate
 * @brief Delegate protocol to notify about annotation tool changes.
 */
@protocol ZoomSDKCustomizedAnnotationDelegate <NSObject>
/**
 * @brief Callback of that annotation tools change.
 * @param tool Specify the tool to annotate.
 */
- (void)onAnnotationToolChanged:(AnnotationToolType)tool;
@end


/**
 * @class ZoomSDKCustomizedAnnotation
 * @brief Provides interfaces to operate customized annotations on shared content.
 */
@interface ZoomSDKCustomizedAnnotation : NSObject
{
    ZoomSDKShareElement* _shareElement;
    id<ZoomSDKCustomizedAnnotationDelegate> _delegate;
}
/**
 * @brief Delegate to receive annotation events.
 */
@property(nonatomic, assign, nullable)id<ZoomSDKCustomizedAnnotationDelegate> delegate;
/**
 * @brief Query if it is able to clear annotations.
 * @param clearType Specify the ways to clear annotations.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canClear:(AnnotationClearType)clearType;
/**
 * @brief Clears annotations.
 * @param clearType Specify the way to clear annotations.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)clear:(AnnotationClearType)clearType;
/**
 * @brief Sets annotation tool type.
 * @param toolType The specify annotation tool type.
 * @return If the function succeeds, it returns @c ZoomSDKError_Success. Otherwise, this function returns an error.
 * @warning The tool type AnnotationToolType_Picker and AnnotationToolType_SpotLight are not support for viewer.
 */
- (ZoomSDKError)setTool:(AnnotationToolType)toolType;
/**
 * @brief Gets the current annotation tool type.
 * @param toolType The type of annotation tools.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getCurrentTool:(AnnotationToolType*)toolType;
/**
 * @brief Sets the colors of annotation tools.
 * @param color The structural object of Color.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setColor:(Color)color;
/**
 * @brief Gets the current's color annotation tools.
 * @param color The pointer to the object of color.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getCurrentColor:(Color*)color;
/**
 * @brief Sets the line width of annotation tools.
 * @param lineWidth Specify the line width to annotate.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)setLineWidth:(long)lineWidth;
/**
 * @brief Gets the current's line width annotation tool.
 * @param lineWidth The pointer to the object of long.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)getCurrentLineWidth:(long*)lineWidth;
/**
 * @brief Undo the last annotation.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)undo;
/**
 * @brief Redo the annotation having been deleted. 
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)redo;
/**
 * @brief Determines if it is enabled to save the snapshot.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canSaveSnapshot;

/**
 * @brief Saves the snapshot in the specified path
 * @param snapShotName Name of the snapshot.
 * @param savedType Sets the type of file to save the screenshot (PNG or PDF).
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)saveSnapshot:(NSString*)snapShotName  snapshotSaveType:(ZoomSDKAnnotationSavedType)savedType;
@end


/**
 * @protocol ZoomSDKCustomizedAnnotationCtrlDelegate
 * @brief Delegate protocol to notify annotation status and privilege changes.
 */
@protocol ZoomSDKCustomizedAnnotationCtrlDelegate <NSObject>
/**
 * @brief Notification of clearing up annotations in the meeting.
 * @param annotation The object of ZoomSDKCustomizedAnnotation.
 */
- (void)onAnnotationCleanUp:(ZoomSDKCustomizedAnnotation*)annotation;
/**
 * @brief Notify annotation status changes.
 * @param element The pointer to ZoomSDKShareElement.
 * @param status Annotation status.
 */
- (void)onAnnotationStatusChanged:(ZoomSDKShareElement*_Nullable)element Status:(AnnotationStatus)status;

/**
 * @brief Designated for Zoom Meeting notify that the sharing user's has changed the viewer's annotation privilege.
 * @param isSupportAnnotation YES if viewer annotations are enabled, NO otherwise.
 * @param shareSourceID The share source ID that is sharing.
 */
- (void)onAnnotationSupportPropertyChangedForCustom:(BOOL)isSupportAnnotation shareSourceID:(unsigned int)shareSourceID;
@end


/**
 * @class ZoomSDKCustomizedAnnotationCtr
 * @brief Controller class to create and manage customized annotations.
 */
@interface ZoomSDKCustomizedAnnotationCtr : NSObject
{
    id<ZoomSDKCustomizedAnnotationCtrlDelegate> _delegate;
}
/**
 * @brief Delegate to receive annotation control events.
 */
@property(nonatomic, assign, nullable) id<ZoomSDKCustomizedAnnotationCtrlDelegate> delegate;

/**
 * @brief Creates custom annotation.
 * @param annotation Specify the annotation that you want to create.
 * @param element The pointer to ZoomSDKShareElement .
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */  
- (ZoomSDKError)createCustomizedAnnotation:(ZoomSDKCustomizedAnnotation*_Nullable*_Nonnull)annotation ShareElement:(ZoomSDKShareElement*_Nullable)element;
/**
 * @brief Destroy custom annotations.
 * @param annotation Specify the annotation that you want to destroy.
 * @return If the function succeeds, it returns ZoomSDKError_Success. Otherwise, this function returns an error.
 */
- (ZoomSDKError)cleanCustomizedAnnotation:(ZoomSDKCustomizedAnnotation*)annotation;

/**
 * @brief This method uses for the sharing user to disable or enable viewer's privilege of annotation.
 * @param annotation Specify the annotation that you want to operate on.
 * @param disable YES to disable viewer's annotation privilege, NO to enable.
 * @return A ZoomSDKError to tell client function call successful or not. Otherwise, this function returns an error.
 */
- (ZoomSDKError)disableViewerAnnotation:(ZoomSDKCustomizedAnnotation*)annotation disable:(BOOL)disable;

/**
 * @brief Determines whether the viewer's annotate privilege is locked.
 * @param annotation Specify the annotation that you want to operate on.
 * @param locked A point to A BOOL, if function call successfully, the value of 'locked' means whether viewer's annotate privilege is locked, YES if viewer's annotate privilege is locked, NO otherwise.
 * @return A ZoomSDKError to tell client function call successful or not. Otherwise, this function returns an error.
 */
- (ZoomSDKError)isViewerAnnotationLocked:(ZoomSDKCustomizedAnnotation*)annotation isLocked:(BOOL*)locked;

/**
 * @brief Determines if it is able for user to disable viewer's annotation privilege.
 * @param annotation Specify the annotation that you want to operate on.
 * @param canDisable A point to A BOOL, if function call successfully, the value of 'canDisable' means whether the user can disable viewer's annotation, YES if can disable, NO if cannot.
 * @return A ZoomSDKError to tell client function call successful or not. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canDisableViewerAnnotation:(ZoomSDKCustomizedAnnotation*)annotation canDisabled:(BOOL*)canDisable;

/**
 * @brief Determines if it is able for user to do annotation.
 * @param annotation Specify the annotation that you want to operate on.
 * @param canAnnotate A point to A BOOL, if function call successfully, the value of 'canAnnotate' means whether the user can do annotation, YES if can do annotation, NO if cannot.
 * @return A ZoomSDKError to tell client function call successful or not. Otherwise, this function returns an error.
 */
- (ZoomSDKError)canDoAnnotation:(ZoomSDKCustomizedAnnotation*)annotation canAnnotate:(BOOL*)canAnnotate;
@end
NS_ASSUME_NONNULL_END
