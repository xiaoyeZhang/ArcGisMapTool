/*
 COPYRIGHT 2016 ESRI
 
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

/*@file AGSLayerSceneProperties.h */

/** @brief Layer properties that apply to 3D scenes
 
 Instances of this class represent properties that apply to layers when rendered by `AGSSceneView` in a 3D scene. These properties are ignored by `AGSMapView` for 2D maps.
 
 @since 100
 */
@interface AGSLayerSceneProperties : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize this object with the provided surface placement
 @param surfacePlacement that specifies how data belonging to the layer should be placed in relation to the scene's surface.
 @since 100
 @return Initialized layer scene properties object
 */
-(instancetype)initWithSurfacePlacement:(AGSSurfacePlacement)surfacePlacement;

/** Initialize a default layer scene properties object
 @return Initialized layer scene properties object
 @since 100
 */
+(instancetype)layerSceneProperties;

/** Initialize this object with the provided surface placement
 @param surfacePlacement
 @since 100
 @return Initialized layer scene properties object
 */
+(instancetype)layerScenePropertiesWithSurfacePlacement:(AGSSurfacePlacement)surfacePlacement;

#pragma mark -
#pragma mark properties

/** Specifies how data that belongs to the layer should be placed in relation to the scene's surface.
 @since 100
 */
@property(nonatomic, assign, readwrite) AGSSurfacePlacement surfacePlacement;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
