/*
 COPYRIGHT 2015 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

#import "AGSOpenGLView.h"

@class AGSSpatialReference;
@class AGSLayerViewState;
@class AGSViewpoint;
@class AGSLayer;
@class AGSPoint;
@class AGSGraphicsOverlay;
@class AGSGraphic;
@class AGSIdentifyGraphicsOverlayResult;
@class AGSIdentifyLayerResult;
@protocol AGSGeoElement;
@protocol AGSGeoViewTouchDelegate;
@class AGSCallout;
@class AGSSketchEditor;
@class AGSTimeExtent;
@class AGSBookmark;
@class AGSSelectionProperties;

NS_ASSUME_NONNULL_BEGIN

/*@file AGSGeoView.h */


/** @brief A base class for all views that can display geographic content on screen
 
 A base class for all views that can display geographic content on screen. Subclasses can
 display the content in either 2D (`AGSMapView`) or 3D (`AGSSceneView`). In an MVC architecture, this class and its subclasses represent the View tier. The Model tier is represented by the geographic content which could be a map (`AGSMap`) or scene (`AGSScene`).
 
 @since 100
 */
@interface AGSGeoView : AGSOpenGLView

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Current drawing status of the view's content (map or scene)
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDrawStatus drawStatus;

/** Attribution for the geographic data currently being displayed in the view. This information is displayed in a banner along the bottom edge of the view.
@since 100.1
*/
@property (nonatomic, copy, readonly) NSString *attributionText;

/** Specifies whether the attribution text banner (along the bottom edge of the view) should be visible .
 Defaults to true
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isAttributionTextVisible) BOOL attributionTextVisible;

/** Spatial reference defining the coordinate system in which the view's content is displayed.
 @since 100
 @see http://desktop.arcgis.com/en/arcmap/latest/map/projections/what-are-map-projections.htm
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Specifies whether the view is navigating, for example, when a pan or zoom animation is in progress or if a user is interacting with the view by dragging or pinching.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isNavigating) BOOL navigating;

/** Specifies whether the view's content wraps around the dateline.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isWrapAroundEnabled) BOOL wrapAroundEnabled;

/** A list of `AGSGraphicsOverlay` objects that can be used to display graphics on top of the view's content
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSGraphicsOverlay*> *graphicsOverlays;

/** A callout view for displaying information on the map.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSCallout *callout;

/** Delegate to be notified when touch events occur on the map.The delegate class must
 adopt the @c AGSGeoViewTouchDelegate protocol.
 @since 100
 */
@property (nullable, nonatomic, weak) IBOutlet id<AGSGeoViewTouchDelegate> touchDelegate;

/** Block that is invoked whenever any map or scene layer's view state changes
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^layerViewStateChangedHandler)(AGSLayer *layer, AGSLayerViewState *layerViewState);

/** Block that gets invoked whenever the viewpoint changes.
 @note This handler may get invoked up to 60 times per second, for example, when a pan or zoom animation is in progress. Do not perform any heavy-lifting in this handler as it may adversely impact the rendering performance.
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^viewpointChangedHandler)();

/** The `NSLayoutAnchor` you can use to layout views in relationship to the attribution text on the `AGSGeoView`.
 This is helpful if you want to place a view just above the attribution text. And when the attribution text is
 collapsed or expanded your view will automatically move to the correct location in relation to the attribution text.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSLayoutYAxisAnchor *attributionTopAnchor;

/** The Time Extent defines how time-enabled data is displayed. When a time extent is applied, participating layers will filter their data as configured.
 The time extent can be a range, or a single instant of time.
 @see `AGSTimeAware#timeFilteringEnabled` to see if time filtering is enabled on layers
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSTimeExtent *timeExtent;

@property (nonatomic, strong, readwrite) AGSSelectionProperties *selectionProperties;

#if (TARGET_OS_IPHONE)
#pragma mark - iOS Specific API
@property (nonatomic, assign) BOOL releaseHardwareResourcesWhenBackgrounded;
#endif

#if (TARGET_OS_MAC && !TARGET_OS_IPHONE)
#pragma mark - Mac OSX Specific API
/**
 Determines whether or not mouse movements are tracked.
 Because tracking mouse movements is potentially expensive you will need
 to set this to YES if you want to respond to the `AGSGeoViewTouchDelegate# geoView:didMoveCursorToPoint:mapPoint:` method
 @since 100
 */
@property (nonatomic, assign) BOOL trackCursorMovement;
#endif

#pragma mark -
#pragma mark methods

/** Provides an image depicting the view's current display.
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)exportImageWithCompletion:(void(^)(AGSImage *__nullable image, NSError *__nullable error))completion;

/** Gets the current viewpoint being displayed. For an `AGSMapView`, this takes into account the attribution bar and any `contentInset` that has been specified to return only the unobscured portion of the map.
 @param viewpointType specifying how the viewpoint should be represented
 @return viewpoint
 @since 100
 */
-(nullable AGSViewpoint*)currentViewpointWithType:(AGSViewpointType)viewpointType;

/** Get the current view state for a map or scene layer
 @param layer to get the view state for
 @return view state
 @since 100
 */
-(nullable AGSLayerViewState*)layerViewStateForLayer:(AGSLayer*)layer;

/** Identify (hit-test) which graphics appear at the specified screen coordinates in the provided graphics overlay.
 @param graphicsOverlay in which to identify graphics
 @param screenPoint at which to identify graphics
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those graphics appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means graphics appearing within a 44 pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only overlays with popups will be retured. If set to NO, all overlays (with or without popups) will be retured.
 @param maximumResults that should be returned as the result
 @param completion block that is invoked when the operation is complete with the result.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyGraphicsOverlay:(AGSGraphicsOverlay*)graphicsOverlay
                                 screenPoint:(CGPoint)screenPoint
                                   tolerance:(double)tolerance
                            returnPopupsOnly:(BOOL)returnPopupsOnly
                              maximumResults:(NSInteger)maximumResults
                                  completion:(void(^)(AGSIdentifyGraphicsOverlayResult *identifyResult))completion;

/** Identify (hit-test) the __top-most graphic__ that appears at the specified screen coordinates in the provided graphics overlay.
 @param graphicsOverlay in which to identify graphics
 @param screenPoint at which to identify graphics
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those graphics appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means graphics appearing within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only overlays with popups will be retured. If set to NO, all overlays (with or without popups) will be retured.
 @param completion block that is invoked when the operation is complete with the result.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyGraphicsOverlay:(AGSGraphicsOverlay*)graphicsOverlay
                                 screenPoint:(CGPoint)screenPoint
                                   tolerance:(double)tolerance
                            returnPopupsOnly:(BOOL)returnPopupsOnly
                                  completion:(void(^)(AGSIdentifyGraphicsOverlayResult *identifyResult))completion;

/** Identify (hit-test) which graphics appear at the specified screen coordinates in all the graphics overlays.
 @param screenPoint at which to identify graphics
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those graphics at that exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means graphics within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only overlays with popups will be retured. If set to NO, all overlays (with or without popups) will be retured.
 @param maximumResultsPerOverlay that should be returned for each overlay in the result
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyGraphicsOverlaysAtScreenPoint:(CGPoint)screenPoint
                                                 tolerance:(double)tolerance
                                          returnPopupsOnly:(BOOL)returnPopupsOnly
                                  maximumResultsPerOverlay:(NSInteger)maximumResultsPerOverlay
                                                completion:(void(^)(NSArray<AGSIdentifyGraphicsOverlayResult*> * __nullable identifyResults, NSError * __nullable error))completion;

/** Identify (hit-test) the __top-most graphic__ that appears at the specified screen coordinates in all the graphics overlays.
 @param screenPoint at which to identify graphics
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those graphics at that exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means graphics within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only overlays with popups will be retured. If set to NO, all overlays (with or without popups) will be retured.
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyGraphicsOverlaysAtScreenPoint:(CGPoint)screenPoint
                                                 tolerance:(double)tolerance
                                          returnPopupsOnly:(BOOL)returnPopupsOnly
                                                completion:(void(^)(NSArray<AGSIdentifyGraphicsOverlayResult*> * __nullable identifyResults, NSError * __nullable error))completion;

/** Identify (hit-test and/or spatially query) all features that appear at the specified screen coordinates in the provided layer.
 @param layer in which to identify features
 @param screenPoint at which to identify features
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those features appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means features appearing within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only layers with popups will be retured. If the layer does not have popups an error will be returned. If set to NO, all layers (with or without popups) will be retured.
 @param maximumResults to return
 @param completion block that is invoked when the operation is complete with the result.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyLayer:(AGSLayer*)layer
                       screenPoint:(CGPoint)screenPoint
                         tolerance:(double)tolerance
                  returnPopupsOnly:(BOOL)returnPopupsOnly
                    maximumResults:(NSInteger)maximumResults
                        completion:(void(^)(AGSIdentifyLayerResult *identifyResult))completion;

/** Identify (hit-test and/or spatially query) the __top-most feature__ that appears at the specified screen coordinates in the provided layer.
 @param layer in which to identify features
 @param screenPoint at which to identify features
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those features appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means features appearing within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only layers with popups will be retured. If the layer does not have popups an error will be returned. If set to NO, all layers (with or without popups) will be retured.
 @param completion block that is invoked when the operation is complete with the result.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyLayer:(AGSLayer*)layer
                       screenPoint:(CGPoint)screenPoint
                         tolerance:(double)tolerance
                  returnPopupsOnly:(BOOL)returnPopupsOnly
                        completion:(void(^)(AGSIdentifyLayerResult *identifyResult))completion;

/** Identify (hit-test and/or spatially query) which features appear at the specified screen coordinates in all the map's layers.
 @param screenPoint at which to identify features
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those features appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means features appearing within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only layers with popups will be retured. If the layer does not have popups an error will be returned. If set to NO, all layers (with or without popups) will be retured.
 @param maximumResultsPerLayer to return
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyLayersAtScreenPoint:(CGPoint)screenPoint
                                       tolerance:(double)tolerance
                                returnPopupsOnly:(BOOL)returnPopupsOnly
                          maximumResultsPerLayer:(NSInteger)maximumResultsPerLayer
                                      completion:(void(^)(NSArray<AGSIdentifyLayerResult*> * __nullable identifyResults, NSError * __nullable error))completion;

/** Identify (hit-test and/or spatially query) the __top-most feature__ that appears at the specified screen coordinates in each of the map's layers.
 @param screenPoint at which to identify features
 @param tolerance radius in points specifying how precise the identify operation should be. A value of 0 means that it should be extremely precise - only those features appearing at the exact coordinates should be returned. A value of 22 (a good default for touch displays which covers an average finger tap) means features appearing within a 44pt buffer can also be returned. Max value permitted is 100.
 @param returnPopupsOnly specifies what the identify results should contain. If set to YES, only layers with popups will be retured. If the layer does not have popups an error will be returned. If set to NO, all layers (with or without popups) will be retured.
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)identifyLayersAtScreenPoint:(CGPoint)screenPoint
                                       tolerance:(double)tolerance
                                returnPopupsOnly:(BOOL)returnPopupsOnly
                                      completion:(void(^)(NSArray<AGSIdentifyLayerResult*> * __nullable identifyResults, NSError * __nullable error))completion;


#pragma mark Viewpoint methods

/** Zoom or pan without animation to the specified viewpoint.
 @param viewpoint to zoom/pan to
 @since 100
 @see `#setViewpoint:completion:` to zoom/pan with animation.
 */
-(void)setViewpoint:(AGSViewpoint*)viewpoint;

/** Zoom or pan with animation to the specified viewpoint. Animates over 0.25 seconds. See `#setViewpoint:duration:completion:` to set viewpoint that animates over a specific duration.
 @param viewpoint to zoom/pan to
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether the animation continued until the end without any interruption.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)setViewpoint:(AGSViewpoint*)viewpoint completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan with animation to the specified viewpoint. Animates over the specified duration.
 @param viewpoint to zoom/pan to
 @param duration for the zoom/pan animation in seconds
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether the animation continued until the end without any interruption.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)setViewpoint:(AGSViewpoint*)viewpoint duration:(double)duration completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan with animation to the viewpoint specified by the provided bookmark
 @param bookmark whose viewpoint will be used to pan/zoom to.
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether the animation continued until the end without any interruption.
 @since 100.2
 */
-(id<AGSCancelable>)setBookmark:(AGSBookmark*)bookmark completion:(nullable void(^)(BOOL finished))completion;

@end



#pragma mark -
#pragma mark Touch Delegate Methods
#pragma mark -

/** @brief A touch delegate for @c AGSGeoView.
 
 A protocol which must be adopted by a class wishing to informed about touch events on `AGSMapView` or `AGSSceneView`. An instance of the
 class must then be set as @c AGSGeoView#touchDelegate .
 
 
 All of the methods of this protocol are optional.
 
 @define{AGSGeoView.h, ArcGIS}
 @since 100
 */
@protocol AGSGeoViewTouchDelegate <NSObject>
@optional


#pragma mark Tap

/** Tells the delegate that the user single-tapped at the specified location.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location where the user tapped in screen coordinates.
 @param mapPoint Location where the user tapped in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didTapAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint;

#pragma mark Touch

/** Tells the delegate that the user put a finger down at the specified location. This event is the precursor of a tap or a drag gesture. If the delegate would like to consume this event, it needs to invoke the provided completion block with `true` which will then prevent the geoview from handling the gesture (for e.g, it won't pan the map when the finger is dragged). It will then be the delgate's responsibility to appropriately respond to the gesture. This is useful, for instance, if you want to drag graphics on the map for which you would invoke `identify` on the graphics overlay and call the completion block with `true` if any graphic was returned.
 @note The completion block should be invoked as quickly as possible to keep the app responsive to user interaction
 @param geoView on which the user performed the interaction.
 @param screenPoint Location where the user put the finger down
 @param mapPoint Location where the user put the finger down. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @param completion block that the delegate needs to invoke with a boolean indicating whether or not they want to consume this event. If they consume this event, the geoview will disregard the entire gesture that begins with this event. It will then be the delgate's responsibility to appropriately respond to the gesture.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
-(void)geoView:(AGSGeoView*)geoView didTouchDownAtScreenPoint:(CGPoint)screenPoint
      mapPoint:(AGSPoint*)mapPoint
    completion:(void(^)(BOOL willHandleDrag))completion;


/** Tells the delegate that the user dragged their finger to specified location. This event is only raised if the delegate has indicated that they want to consume the immediately prior `#geoView:didTouchDownAtScreenPoint:mapPoint:completion:` event by passing `YES` to the completion block parameter.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location where the user dragged their finger to
 @param mapPoint Location where the user dragged their finger to. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
-(void)geoView:(AGSGeoView*)geoView didTouchDragToScreenPoint:(CGPoint)screenPoint
      mapPoint:(AGSPoint*)mapPoint;

/** Tells the delegate that the user lifted their finger from the screen. This event is only raised if the delegate has indicated that they want to consume the prior `#geoView:didTouchDownAtScreenPoint:mapPoint:completion:` event.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location where the user lifted their finger
 @param mapPoint Location where the user lifted their finger. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
 -(void)geoView:(AGSGeoView*)geoView didTouchUpAtScreenPoint:(CGPoint)screenPoint
      mapPoint:(AGSPoint*)mapPoint;

/** Tells the delegate the drag action was cancelled. This event is only raised if the delegate has indicated that they want to consume the prior `#geoView:didTouchDownAtScreenPoint:mapPoint:completion:` event.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
-(void)geoViewDidCancelTouchDrag:(AGSGeoView*)geoView;

#pragma mark Double Tap

/** Tells the delegate that the user double-tapped at the specified location. If the delegate would like to consume this event, it needs to invoke the provided completion block with `true` which will then prevent the geoview from handling the gesture (for eg, it won't zoom the map on double-tap).
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @param completion block that the delegate needs to invoke with a boolean indicating whether or not they want to consume this event. If they consume this event, the geoview will disregard the entire gesture that begins with this event. It will then be the delgate's responsibility to appropriately respond to the gesture.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
-(void)geoView:(AGSGeoView*)geoView didDoubleTapAtScreenPoint:(CGPoint)screenPoint
      mapPoint:(AGSPoint *)mapPoint
    completion:(void(^)(BOOL willHandleDoubleTap))completion;

#pragma mark Long Press

/** Tells the delegate that the user long-pressed at the specified
 location.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didLongPressAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint;

/** Tells the delegate that the user moved their finger during a long press interaction.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didMoveLongPressToScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint;

/** Tells the delegate that the long press interaction has ended.
 @param geoView on which the user performed the interaction.
 @param screenPoint Screen coordinates of where the user ended the tap and hold.
 @param mapPoint Map coordinates of where the user ended the tap and hold. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didEndLongPressAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint;

/** Tells the delegate that a long press interaction was canceled. This may happen, for instance, when you have the magnifier visible and attempt to take
 a screenshot using the home/lock button combination.
 @param geoView on which the user performed the interaction.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoViewDidCancelLongPress:(AGSGeoView *)geoView;

#ifdef TARGET_OS_IPHONE

#pragma mark Force Touch

/** Tells the delegate that the user force touched at the specified location.  The force touch gesture is recognized when a touch greater than
 average force is made for more than 300 miliseconds.  The average force of a touch is defined by the iOS operating system as a raw force
 value of 1.0.  The force reported by the gesture recognizer is a normalized value that ranges from the average force of a touch to the
 maximum force of a touch.  The force value's range is 0 to 1.0.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @param force Force with which the user touched the point. Force is a normalized value that ranges from 0 which represents the force
 of an average touch, to 1.0 which is the value of a maximum force touch.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didForceTouchAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint force:(double)force;

/** Tells the delegate that the user moved their finger during a force touch interaction.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @param force Force with which the user touched the point. Force is a normalized value that ranges from 0 which represents the force
 of an average touch, to 1.0 which is the value of a maximum force touch.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didChangeForceTouchAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint force:(double)force;

/** Tells the delegate that a force touch interaction ended.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @param force Force with which the user touched the point. Force is a normalized value that ranges from 0 which represents the force
 of an average touch, to 1.0 which is the value of a maximum force touch.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
- (void)geoView:(AGSGeoView *)geoView didEndForceTouchAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint force:(double)force;

/** Tells the delegate that a force touch interaction was canceled.
 @param geoView on which the user performed the interaction.
 @since 100
 */
- (void)geoViewDidCancelForceTouch:(AGSGeoView *)geoView;

#endif

#if (TARGET_OS_MAC && !TARGET_OS_IPHONE)

#pragma mark macOS specific delegate methods

/** Tells the delegate that the mouse was moved over the geoview. To get this delegate method called
 you must set the `trackCursorMovement` property on the AGSGeoView to YES. This is because tracking mouse
 movements can be somewhat expensive.
 @param geoView on which the user performed the interaction.
 @param screenPoint Location in screen coordinates.
 @param mapPoint Location in map coordinates. When using an `AGSSceneView`, the location will have a z-value corresponding to the intersection point on the scene's baseSurface.
 @since 100
 @see `AGSSceneView#screenToLocation:completion:` to get a location that intersects with any features/graphics on or above the baseSurface.
 */
-(void)geoView:(AGSGeoView *)geoView didMoveCursorToScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint*)mapPoint;

/** Tells the delegate that a keyDown event took place for the geoview.
 @param geoView on which the user performed the interaction.
 @since 100
 */
-(void)geoView:(AGSGeoView *)geoView didKeyDown:(NSEvent*)event;

/** Tells the delegate that a keyUp event took place for the geoview.
 @param geoView on which the user performed the interaction.
 @since 100
 */
-(void)geoView:(AGSGeoView *)geoView didKeyUp:(NSEvent*)event;

/** Asks the delegate whether to handle a performKeyEquivalent event or not.  These events
 are related to map panning, zooming and rotating.
 Default is <code>YES</code>.  A value of <code>NO</code> means the geoView will not process the event.
 @param geoView on which the user performed the interaction.
 @param event the event sent to the geoView.
 @return <code>BOOL</code> value whether event should be handled or not by the geoView.
 @since 100
 */
-(BOOL)geoView:(AGSGeoView *)geoView shouldProcessKeyEquivalentEvent:(NSEvent*)event;

#endif

@end

NS_ASSUME_NONNULL_END




