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
@class AGSPolylineBuilder;
@class AGSPoint;

/**
 @brief A polyline geometry representing a line or collection of lines.
 
 Instances of this class represent a polyline geometry. A polyline is defined by a collection of parts (linear paths). Each path is a continuous line represented by a collection of points. Each point represents a vertex of the polyline, defined by a pair of x,y coordinates, and optionally a z-coordinate and/or m-value (measure).
 
 A polyline is associated with a spatial reference which specifies the coordinate system that its coordinate values use.
 
 @since 100
 @note This class represents an immutable polyline geometry, it cannot be modified after being created. Use `#toBuilder:` to get a polyline builder using a copy of this geometry as a starting off point. The builder can then be modified to produce a new geometry.
 
 @see `AGSPolylineBuilder`  to construct or modify polylines programmatically.
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map.
 @see `AGSGeometryEngine` to perform operations on geometries.
*/
@interface AGSPolyline : AGSMultipart
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init not available.")));

/**
 Initializes a polyline.
 @param points for the geometry to be constructed
 @since 100
 */
+(instancetype)polylineWithPoints:(NSArray<AGSPoint*>*)points;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point.
 The builder can then be modified to produce a new geometry.
 
 @return builder that can be used to build polyline geometries.
 @since 100
 @note Operations on the builder affect only its own internal copy of the geometry. They do not affect this geometry.
 */
-(AGSPolylineBuilder*)toBuilder;

/**
 Compares whether two polyline geometries are equal.
 
 @param other polyline to compare this polyline to
 @return YES if the polylines are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSPolyline*)other;

NS_ASSUME_NONNULL_END
@end
