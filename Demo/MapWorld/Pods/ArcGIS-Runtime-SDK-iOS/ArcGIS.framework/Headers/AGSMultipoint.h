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

#import "AGSGeometry.h"
@class AGSPoint;
@class AGSMultipointBuilder;
@class AGSPointCollection;

/**
 @brief Represents a multipoint geometry.
 
 A multipoint is defined by a collection of non-connected point locations. Each point is defined by a pair of x,y coordinates, and optionally a z-coordinate and/or m-value (measure).
 
 A multipoint is associated with a spatial reference which specifies the coordinate system that its coordinate values use.
 
 @since 100
 @note This class represents an immutable multipoint geometry, it cannot be modified after being created. Use `#toBuilder:` to get a multipoint builder using a copy of this geometry as a starting off point. The builder can then be modified to produce a new geometry.
 
 @see `AGSMultipointBuilder`  to construct or modify multipoints programmatically.
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map.
 @see `AGSGeometryEngine` to perform operations on geometries.
*/
@interface AGSMultipoint : AGSGeometry
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a multipoint.
 
 @param points for the geometry to be constructed
 @since 100
 */
+(instancetype)multipointWithPoints:(NSArray<AGSPoint*>*)points;

#pragma mark -
#pragma mark properties

/**
 The points that make up this multipoint.
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPointCollection *points;

#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point. 
 The builder can then be modified to produce a new geometry.
 
 @return builder that can be used to build multipoint geometries.
 @since 100
 @note Operations on the builder affect only its own internal copy of the geometry. They do not affect this geometry.
 */
-(AGSMultipointBuilder*)toBuilder;

/**
 Compares whether two multipoint geometries are equal.
 
 @param other multipoint to compare this multipoint to
 @return YES if the multipoints are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSMultipoint*)other;

NS_ASSUME_NONNULL_END
@end
