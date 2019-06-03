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

#import "AGSGeometryBuilder.h"
@class AGSPoint;
@class AGSSpatialReference;
@class AGSEnvelope;

/**
 @brief A builder to build point geometries.
 
 Instances of this class represent a builder that can build point geometries.
 Point geometries are immutable, they cannot be modified after they are created. Use builders to create new geometries either from scratch, or by using an existing geometry as a starting off point. Modifications made through the builder affect only its own internal copy of the geometry. They do not affect the original geometry.
 
 @since 100
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map
 */
@interface AGSPointBuilder : AGSGeometryBuilder
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
+(instancetype)pointBuilderWithSpatialReference:(nullable AGSSpatialReference*)sr;

/**
 Initializes a point builder.
 
 @param point The geometry to be used as the starting point for further modifications. Can be nil.
 @since 100
 */
-(instancetype)initWithPoint:(nullable AGSPoint *)point;

/**
 Initializes a point builder.
 
 @param point The geometry to be used as the starting point for further modifications. Can be nil.
 @since 100
 */
+(instancetype)pointBuilderWithPoint:(nullable AGSPoint *)point;

#pragma mark -
#pragma mark properties

/**
 The position of the builder's point geometry along x-axis.
 
 @since 100
 */
@property (nonatomic, assign, readwrite) double x;

/**
 The position of the builder's point geometry along y-axis.
 
 @since 100
 */
@property (nonatomic, assign, readwrite) double y;

/**
 The measure value of the builder's point geometry.
 
 @since 100
 */
@property (nonatomic, assign, readwrite) double m;

/**
 The position of the builder's point geometry along z-axis.
 Only applicable for 3D point geometries.
 
 @since 100
 */
@property (nonatomic, assign, readwrite) double z;

#pragma mark -
#pragma mark methods

/**
 Update the builder's point geometry.
 
 @param x coordinate
 @param y coordinate
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)setX:(double)x y:(double)y;

/**
 Move the builder's point geometry.
 
 @param xOffset offset along x-axis (negative value moves the point east)
 @param yOffset offset along y-axis (negative value moves the point south)
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)offsetByX:(double)xOffset y:(double)yOffset;

/**
 Replaces the builder's geometry with the provided one.
 
 @param geometry to replace with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)replaceGeometry:(nullable AGSPoint*)geometry;

/**
 Returns the point geometry this builder is constructing or modifying.
 
 @return geometry
 @since 100
 */
-(AGSPoint*)toGeometry;

NS_ASSUME_NONNULL_END
@end
