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
@class AGSSpatialReference;
@class AGSPointBuilder;

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A point geometry
 
 Instances of this class represent a point geometry. A point is a pair of x,y coordinates, and optionally a z-coordinate and/or m-value (measure). 
 
 A point is associated with a spatial reference which specifies the coordinate system that its coordinate values use.
 
 @since 100
 @note This class represents an immutable point geometry, it cannot be modified after being created. Use `#toBuilder:` to get a point builder.
 @see `AGSPointBuilder`  to construct or modify points  programmatically.
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map.
 @see `AGSGeometryEngine` to perform operations on geometries.
 */
@interface AGSPoint : AGSGeometry

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithX:(double)x y:(double)y spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param z The position along z-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithX:(double)x y:(double)y z:(double)z spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param m The measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithX:(double)x y:(double)y m:(double)m spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param z The position along z-axis
 @param m The measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithX:(double)x y:(double)y z:(double)z m:(double)m spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided location information.
 
 @param locationCoordinate of the device
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithCLLocationCoordinate2D:(CLLocationCoordinate2D)locationCoordinate;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)pointWithX:(double)x y:(double)y spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param z The position along z-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)pointWithX:(double)x y:(double)y z:(double)z spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param m The measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)pointWithX:(double)x y:(double)y m:(double)m spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided coordinate values.
 
 @param x The position along x-axis
 @param y The position along y-axis
 @param z The position along z-axis
 @param m The measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)pointWithX:(double)x y:(double)y z:(double)z m:(double)m spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a point geometry with the provided location information.
 
 @param locationCoordinate of the device
 @return An initialized point geometry
 @note The point geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)pointWithCLLocationCoordinate2D:(CLLocationCoordinate2D)locationCoordinate;

#pragma mark -
#pragma mark properties

/**
 The position along x-axis.
 
 @since 100
 */
@property (nonatomic, assign, readonly) double x;

/**
 The position along y-axis.
 
 @since 100
 */
@property (nonatomic, assign, readonly) double y;

/**
 The measure value.
 
 @since 100
 @see `AGSGeometry#hasM` to check if the geometry has measure values.
 */
@property (nonatomic, assign, readonly) double m;

/**
 The position along z-axis.
 Only applicable for 3D point geometries.
 
 @since 100
 @see `AGSGeometry#hasZ` to check if the geometry has z values.
 */
@property (nonatomic, assign, readonly) double z;

#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point.
 The builder can be used to make modifications to the geometry.
 
 @return builder that can be used to modify or create point geometries.
 @since 100
 @note Operations on the builder affect only its own internal copy of the geometry. They do not affect this geometry.
 */
-(AGSPointBuilder*)toBuilder;

/**
 Compares whether two point geometries are equal.
 
 @param other point to compare this point to
 @return YES if the points are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSPoint*)other;

/**
 Converts current point into CLLocationCoordinate2D.

 @since 100
 */
-(CLLocationCoordinate2D)toCLLocationCoordinate2D;

@end


//
// The following are C-style factory methods
// Usage:
//    AGSPoint *p = AGSPointMake(-117.123, 34.123, [AGSSpatialReference spatialReferenceWithWKID:4326]);
//    AGSPoint *p = AGSPointMake3D(1.123e6, 234e6, 789, 987, [AGSSpatialReference webMercator]);
//    AGSPoint *p = AGSPointMakeWGS84(34.123, -117.123);
//    AGSPoint *p = AGSPointMakeWebMercator(1.123e6, 234e6);

AGS_EXTERN AGSPoint* AGSPointMake(double x, double y, AGSSpatialReference *__nullable spatialReference);
AGS_EXTERN AGSPoint* AGSPointMake3D(double x, double y, double z, double m, AGSSpatialReference *__nullable spatialReference);
AGS_EXTERN AGSPoint* AGSPointMakeWGS84(double latitude, double longitude);
AGS_EXTERN AGSPoint* AGSPointMakeWebMercator(double x, double y);

NS_ASSUME_NONNULL_END

