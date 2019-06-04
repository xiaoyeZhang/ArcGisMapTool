/*
 COPYRIGHT 2014 ESRI
 
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

#import "AGSMultipart.h"
@class AGSPolygonBuilder;
@class AGSPolyline;
@class AGSPoint;

/**
 @brief A polygon geometry representing an area or collection of areas.
 
 Instances of this class represent a polygon geometry. A polygon is defined by a collection of parts (closed rings). Each ring is a bounded area represented by a collection of points. The first and last points of a ring must coincide so that the ring is closed. Each point represents a vertex of the polygon, defined by a pair of x,y coordinates, and optionally a z-coordinate and/or m-value (measure).
 
 A polygon is associated with a spatial reference which specifies the coordinate system that its coordinate values use.

 @since 100
 @note This class represents an immutable polygon geometry, it cannot be modified after being created. Use `#toBuilder:` to get a polygon builder using a copy of this geometry as a starting off point. The builder can then be modified to produce a new geometry.

 @see `AGSPolygonBuilder`  to construct or modify polygons programmatically.
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map.
 @see `AGSGeometryEngine` to perform operations on geometries.
*/
@interface AGSPolygon : AGSMultipart
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a polygon.
 @param points for the geometry to be constructed
 @since 100
 */
+(instancetype)polygonWithPoints:(NSArray<AGSPoint*>*)points;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point.
 The builder can then be modified to produce a new geometry.
 
 @return builder that can be used to build polygon geometries.
 @since 100
 @note Operations on the builder affect only its own internal copy of the geometry. They do not affect this geometry.
 */
-(AGSPolygonBuilder*)toBuilder;

/**
 Compares whether two polygon geometries are equal.
 
 @param other polygon to compare this polygon to
 @return YES if the polygons are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSPolygon*)other;

-(AGSPolyline*)toPolyline;

NS_ASSUME_NONNULL_END
@end
