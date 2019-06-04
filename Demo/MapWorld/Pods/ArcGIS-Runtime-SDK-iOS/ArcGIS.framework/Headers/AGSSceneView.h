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

#import "AGSGeoView.h"
@class AGSScene;
@class AGSCamera;
@class AGSLocationToScreenResult;
@class AGSCameraController;
@class AGSAnalysisOverlay;

/*@file AGSSceneView.h */

/** @brief A base class for AGSSceneView
 
 A base class for `AGSSceneView` to facilitate code reuse between iOS and Mac platforms.
 
 @since 100
 */
@interface AGSSceneViewCommon : AGSGeoView

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The scene to be displayed by this sceneview. The sceneview loads the scene and all of its layers in order to display their content on screen.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSScene *scene;

/** The color of sceneview's ambient light.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *ambientLightColor;

/** The effect to the applied to the sceneview's atmosphere.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSAtmosphereEffect atmosphereEffect;

/** Position of the sun based on a specific date & time.
 @since 100
 */
@property (nonatomic, strong, readwrite) NSDate *sunTime;

/** The type of sun lighting to be applied to the sceneview. For example, this can be used to control whether the terrain and 3D models cast a shadow.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSLightingMode sunLighting;


/** The controller that manages the position, orientation, and movement of the camera for this scene view. The controller handles user interaction with the scene view and updates the camera accordingly. Defaults to `AGSGlobeCameraController` to allow free-form roaming around the globe.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSCameraController *cameraController;

/** A collection of analysis overlays that render the results of visual analysis on the scene view.
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSAnalysisOverlay*> *analysisOverlays;

#pragma mark -
#pragma mark methods

/** Converts the specified location in map units to a point in screen units.
 @param mapPoint to convert
 @return result
 @since 100
 */
-(AGSLocationToScreenResult*)locationToScreen:(AGSPoint *)mapPoint;

/** Converts the specified screen point to a location on the base surface i.e. ignoring any 3D features/graphics on or above the surface that may be intersecting the screen point. The location returned will have a z-value corresponding to the elevation at the intersecting surface.
 @param screenPoint point to convert
 @return location on the base surface
 @since 100
 @see `#screenToLocation:completion:` to get a location taking into account any features/graphics intersecting the input screen point
 */
-(AGSPoint*)screenToBaseSurface:(CGPoint)screenPoint;

/** Get the camera position for the current viewpoint being displayed.
 @return camera position for current viewpoing
 @since 100
 */
-(AGSCamera *)currentViewpointCamera;

/** Zoom or pan without animation to the viewpoint specified by the camera position.
 @param camera position
 @since 100
 */
-(void)setViewpointCamera:(AGSCamera*)camera;

/** Zoom or pan with animation to the viewpoint specified by the camera position. Animates over 0.25 seconds. See `#setViewpointCamera:duration:completion:` to set viewpoint that animates over a specific duration.
 @param camera position
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether the animation continued until the end without any interruption.
 @return operation that can be canceled
 @since 100
 */-(id<AGSCancelable>)setViewpointCamera:(AGSCamera*)camera
                             completion:(nullable void(^)(BOOL finished))completion;

/** Zoom or pan with animation to the viewpoint specified by the camera position. Animates over the specified duration.
 @param camera position
 @param duration in seconds to perform the animation over
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether the animation continued until the end without any interruption.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)setViewpointCamera:(AGSCamera*)camera
                               duration:(double)duration
                             completion:(nullable void(^)(BOOL finished))completion;

/** Converts the specified screen point to a map location. The location could be on the surface, on a building, or on a feature/graphic above ground (for e.g. an aircraft).
 This method checks for intersection between the input screen point and features/graphics in the Scene.
 It returns a point with X, Y and Z values matching the intersection point. If the input point does not
 intersect a visible feature/graphic, the Scene's surface is used to retrieve the intersection point.
 @param screenPoint point to convert
 @param completion block that is invoked with the result map location
 @return operation that can be canceled
 @since 100
 @see `#screenToBaseSurface:` to get a location on the surface ignoring any intersecting features/graphics
 */
-(id<AGSCancelable>)screenToLocation:(CGPoint)screenPoint completion:(void(^)(AGSPoint *location))completion;

NS_ASSUME_NONNULL_END

@end


/** @brief A View component to display 3D geographic content such as scenes.
 
 Instances of this class represent views that can display 3D geographic content such as scenes on screen. In an MVC architecture, this class represents the View tier and is a type of `UIView` on iOS or `NSView` on Mac. The Model tier is represented by `AGSScene` which contains the geographic content.
 
 
 To display a scene, add an `AGSSceneView` to your view controller's view heirarchy. You can do this either using Interface Builder and Storyboards, or programmatically in code. Next, assign an `AGSScene` to the sceneview. The sceneview will automatically load the scene, its basemap, and operational layers, and display their contents on screen.
 
 To navigate the scene, you can use touch gestures such as double-tap, drag, two-finger tap, etc on iOS, and the mouse/trackpad, and keyboard shortcuts on Mac OS. You can also programmatically [change the viewpoint](#setViewpoint:) with or without animation.
 
 
 
 @see `AGSMapView` to display 2D geographic content such as maps.
 @since 100
 */
@interface AGSSceneView : AGSSceneViewCommon

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
