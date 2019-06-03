/*
 COPYRIGHT 2018 ESRI
 
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

#import "AGSObject.h"

/** @file AGSKMLGeometry.h */ //Required for Globals API doc

/** @brief A KML Geometry element
 
 An instance of this class represents a KML `<Geometry>` element which could be a Point, LineString,
 LinearRing or Polygon. For MultiGeometry, see `AGSKMLPlacemark#geometries`.
 @since 100.4
 */
@interface AGSKMLGeometry : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The underlying geometry.
 @since 100.4
 */
@property (nonatomic, strong, readonly) AGSGeometry *geometry;

/** Specifies how the altitude contained in the geometry's z-value is interpreted.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLAltitudeMode altitudeMode;

/** The KML geometry type.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLGeometryType type;

/** Specifies whether to extrude the geometry, i.e connect it to the ground in a 3D view.
 @since 100.4
 */
@property (nonatomic, assign, readonly, getter=isExtruded) BOOL extruded;

/** Specifies whether to tessellate the geometry. Tessellated geometry can follow the terrain.
 @note In order for tessellated geometry to follow the terrain, the `#altitudeMode` must be set to `AGSKMLAltitudeModeClampToGround`.
 @since 100.4
 */
@property (nonatomic, assign, readonly, getter=isTessellated) BOOL tessellated;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
