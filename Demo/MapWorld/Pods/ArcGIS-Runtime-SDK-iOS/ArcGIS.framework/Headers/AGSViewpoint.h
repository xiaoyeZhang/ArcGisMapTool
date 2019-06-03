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

@class AGSGeometry;
@class AGSEnvelope;
@class AGSPoint;
@class AGSCamera;

/*@file AGSViewpoint.h */

/** @brief Represents the view location of `AGSMapView` or `AGSSceneView`
 
 Instances of this class represent a view location of `AGSMapView` or `AGSSceneView`

 
 @since 100
 */

@interface AGSViewpoint : AGSObject <AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the viewpoint with center & scale
 @param center of the map/scene
 @param scale at which the map/scene should be displayed
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithCenter:(AGSPoint *)center scale:(double)scale;

/** Initialize the viewpoint with center, scale, and rotation
 @param center of the map/scene
 @param scale of the map/scene
 @param rotation angle by which the map/scene should be rotated (in counter-clockwise direction)
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithCenter:(AGSPoint *)center scale:(double)scale rotation:(double)rotation;

/** Initialize the viewpoint with an extent
 @param targetExtent at which the map/scene should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map/scene.
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithTargetExtent:(AGSEnvelope *)targetExtent;

/** Initialize the viewpoint with an extent and rotation
 @param targetExtent at which the map/scene should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map/scene.
 @param rotation angle by which the map/scene should be rotated (in counter-clockwise direction)
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithTargetExtent:(AGSEnvelope *)targetExtent rotation:(double)rotation;

/** Initialize the viewpoint with latitude, longitude, and scale.
 @param latitude the map/scene should be centered at
 @param longitude the map/scene should be centered at
 @param scale at which the map/scene should be displayed
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithLatitude:(double)latitude longitude:(double)longitude scale:(double)scale;

/** Initialize the viewpoint with center, scale and camera.
 @note Center and scale will be used when working with a map, Camera will be used when working with a scene.
 @param center of the map
 @param scale at which the map should be displayed
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithCenter:(AGSPoint *)center scale:(double)scale camera:(AGSCamera*)camera;

/** Initialize the viewpoint with center, scale, rotation and camera
 @note Center, scale, and rotation will be used when working with a map, Camera will be used when working with a scene.
 @param center of the map
 @param scale of the map
 @param rotation angle by which the map should be rotated (in counter-clockwise direction)
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithCenter:(AGSPoint *)center scale:(double)scale rotation:(double)rotation camera:(AGSCamera*)camera;

/** Initialize the viewpoint with an extent and camera
 @note Target extent & rotation will be used when working with a map, Camera will be used when working with a scene.
 @param targetExtent at which the map should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map.
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100.4
 */
- (instancetype)initWithTargetExtent:(AGSEnvelope *)targetExtent camera:(AGSCamera*)camera;

/** Initialize the viewpoint with an extent, rotation and camera
 @note Target extent & rotation will be used when working with a map, Camera will be used when working with a scene.
 @param targetExtent at which the map should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map.
 @param rotation angle by which the map should be rotated (in counter-clockwise direction)
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithTargetExtent:(AGSEnvelope *)targetExtent rotation:(double)rotation camera:(AGSCamera*)camera;

/** Initialize the viewpoint with latitude, longitude, scale and camera
 @note Latitude, longitude, and scale will be used when working with a map, Camera will be used when working with a scene.
 @param latitude the map should be centered at
 @param longitude the map should be centered at
 @param scale at which the map should be displayed
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
- (instancetype)initWithLatitude:(double)latitude longitude:(double)longitude scale:(double)scale camera:(AGSCamera*)camera;

/** Initialize the viewpoint with center and scale
 @param center of the map/scene
 @param scale of the map/scene
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithCenter:(AGSPoint *)center scale:(double)scale;

/** Initialize the viewpoint with center, scale, and rotation
 @param center of the map/scene
 @param scale of the map/scene
 @param rotation angle by which the map/scene should be rotated (in counter-clockwise direction)
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithCenter:(AGSPoint *)center scale:(double)scale rotation:(double)rotation;

/** Initialize the viewpoint with an extent
 @param targetExtent at which the map/scene should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map/scene.
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithTargetExtent:(AGSEnvelope *)targetExtent;

/** Initialize the viewpoint with an extent and rotation
 @param targetExtent at which the map/scene should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map/scene.
 @param rotation angle by which the map/scene should be rotated (in counter-clockwise direction)
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithTargetExtent:(AGSEnvelope *)targetExtent rotation:(double)rotation;

/** Initialize the viewpoint with latitude, longitude, and scale.
 @param latitude the map/scene should be centered at
 @param longitude the map/scene should be centered at
 @param scale at which the map/scene should be displayed
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithLatitude:(double)latitude longitude:(double)longitude scale:(double)scale;

/** Initialize the viewpoint with center, scale and camera
 @note Center and scale will be used when working with a map, Camera will be used when working with a scene.
 @param center of the map
 @param scale of the map
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithCenter:(AGSPoint *)center scale:(double)scale camera:(AGSCamera*)camera;

/** Initialize the viewpoint with center, scale, and rotation
 @note Center, scale, and rotation will be used when working with a map, Camera will be used when working with a scene.
 @param center of the map
 @param scale of the map
 @param rotation angle by which the map should be rotated (in counter-clockwise direction)
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithCenter:(AGSPoint *)center scale:(double)scale rotation:(double)rotation camera:(AGSCamera*)camera;

/** Initialize the viewpoint with an extent and camera
 @note Target extent will be used when working with a map, Camera will be used when working with a scene.
 @param targetExtent at which the map should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map.
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100.4
 */
+(instancetype)viewpointWithTargetExtent:(AGSEnvelope *)targetExtent camera:(AGSCamera*)camera;
    
/** Initialize the viewpoint with an extent, rotation and camera
 @note Target extent & rotation will be used when working with a map, Camera will be used when working with a scene.
 @param targetExtent at which the map should be displayed. The final extent may be different depending upon the difference in aspect ratio of the targetExtent and the map.
 @param rotation angle by which the map should be rotated (in counter-clockwise direction)
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithTargetExtent:(AGSEnvelope *)targetExtent rotation:(double)rotation camera:(AGSCamera*)camera;

/** Initialize the viewpoint with latitude, longitude, scale and camera
 @note Latitude, longitude, and scale will be used when working with a map, Camera will be used when working with a scene.
 @param latitude the map should be centered at
 @param longitude the map should be centered at
 @param scale at which the map should be displayed
 @param camera A Camera to look at the scene
 @return Initialized viewpoint
 @since 100
 */
+(instancetype)viewpointWithLatitude:(double)latitude longitude:(double)longitude scale:(double)scale camera:(AGSCamera*)camera;

#pragma mark -
#pragma mark properties

/** A camera represented by this viewpoint.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSCamera* camera;
    
/** The type of information contained in this viewpoint
 @since 100
 */
@property (nonatomic, assign, readonly) AGSViewpointType viewpointType;

/** The map rotation angle represented by this viewpoint
 @since 100
 */
@property (nonatomic, assign, readonly) double rotation;

/** The geometry represented by this viewpoint.
 If `#viewpointType` is `AGSViewpointTypeCenterAndScale`, this contains a point geometry
 If `#viewpointType` is `AGSViewpointTypeBoundingGeometry`, this contains an envelope geometry

 @since 100
 */
@property (nonatomic, strong, readonly) AGSGeometry *targetGeometry;
 
/** The map scale represented by this viewpoint.
 Only applicable if `#viewpointType` is `AGSViewpointTypeCenterAndScale`
 @since 100
 */
@property (nonatomic, assign, readonly) double targetScale;

#pragma mark -
#pragma mark methods

/** Compares whether this viewpoint is equal to another
 @param other viewpoint to compare this one to
 @return whether the two viewpoints are equal
 @since 100
 */
-(BOOL)isEqualToViewpoint:(AGSViewpoint*)other;

NS_ASSUME_NONNULL_END
@end
