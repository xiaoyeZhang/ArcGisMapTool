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

#import "AGSMultipartBuilder.h"
@class AGSPolyline;
@class AGSPoint;

/**
 @brief A builder to build polyline geometries
 
 Instances of this class represent a builder that can build polyline geometries.
 Polyline geometries are immutable, they cannot be modified after they are created. Use builders to create new geometries either from scratch, or by using an existing geometry as a starting off point. Modifications made through the builder affect only its own internal copy of the geometry. They do not affect the original geometry.
 
 @since 100
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map
 */
@interface AGSPolylineBuilder : AGSMultipartBuilder
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a builder.
 
 @param sr The spatial reference for the geometry to be constructed
 @since 100
 */
-(instancetype)initWithSpatialReference:(nullable AGSSpatialReference*)sr;

/**
 Initializes a builder.
 
 @param sr The spatial reference for the geometry to be constructed
 @since 100
 */
+(instancetype)polylineBuilderWithSpatialReference:(nullable AGSSpatialReference*)sr;

/**
 Initializes a polyline builder.
 
 @param polyline The geometry to be used as the starting point for further modifications. Can be nil.
 @since 100
 */
-(instancetype)initWithPolyline:(nullable AGSPolyline *)polyline;

/**
 Initializes a polyline builder.
 
 @param polyline The geometry to be used as the starting point for further modifications. Can be nil.
 @since 100
 */
+(instancetype)polylineBuilderWithPolyline:(nullable AGSPolyline *)polyline;

/**
 Initializes a polyline builder.
 
 @param points for the geometry to be constructed
 @since 100
 */
-(instancetype)initWithPoints:(NSArray<AGSPoint*>*)points;

/**
 Initializes a polyline builder.
 
 @param points for the geometry to be constructed
 @since 100
 */
+(instancetype)polylineBuilderWithPoints:(NSArray<AGSPoint*>*)points;

#pragma mark -
#pragma mark methods
/**
 Replaces the builder's geometry with the provided one.
 
 @param geometry to replace with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)replaceGeometry:(nullable AGSPolyline*)geometry;

/**
 Returns the polyline geometry this builder is constructing or modifying.
 
 @return geometry
 @since 100
 */
-(AGSPolyline*)toGeometry;

NS_ASSUME_NONNULL_END
@end
