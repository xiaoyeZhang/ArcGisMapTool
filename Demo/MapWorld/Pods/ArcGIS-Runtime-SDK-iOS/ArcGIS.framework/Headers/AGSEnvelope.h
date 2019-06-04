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
@class AGSEnvelopeBuilder;
@class AGSPoint;

/**
 @brief An envelope (rectangular) geometry.
 
 Instances of this class represent an envelope. An envelope is defined by a pair of x,y coordinates representing the lower-left and upper-right vertices of a rectangular bounding-box. The vertices may optionally contain z coordinates and/or m (measure) values.
 
 An envelope is associated with a spatial reference which specifies the coordinate system that its coordinate values use.
 
 An envelope is typically used to represent the minimum bounding rectangle for a geometry or to define a simple area of interest such as a map's extent. Ordinarily, the envelope object is a rectangle whose sides are oriented parallel to the x and y axes. These characteristics allow for simpler construction and manipulation of this object than is possible with a polygon.
 
 @since 100
 @note This class represents an immutable envelope geometry, it cannot be modified after being created. Use `#toBuilder:` to get an envelope builder using a copy of this geometry as a starting off point. The builder can then be modified to produce a new geometry.

 @see `AGSEnvelopeBuilder`  to construct or modify envelopes programmatically.
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map.
 @see `AGSGeometryEngine` to perform operations on geometries.
 */
@interface AGSEnvelope : AGSGeometry
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes an envelope geometry with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100.1
 */
-(instancetype)initWithCenter:(AGSPoint *)center width:(double)width height:(double)height;

/**
 Initializes an envelope geometry with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @param depth of the envelope (in meters)
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
@since 100.1
 */
-(instancetype)initWithCenter:(AGSPoint *)center width:(double)width height:(double)height depth:(double)depth;

/**
 Initializes an envelope geometry with the provided min and max points.
 
 The spatial reference of both input points must match and will be the spatial reference of the resulting envelope. The min and max points can be any opposing corners of the envelope and the resulting envelope will always have min less than or equal to max.

 @param min The min corner of the envelope
 @param max The max corner of the envelope
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithMin:(AGSPoint*)min max:(AGSPoint*)max;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithXMin:(double)xMin
             yMin:(double)yMin
             xMax:(double)xMax
             yMax:(double)yMax
 spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param zMin The min coordinate along z-axis
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param zMax The max coordinate along z-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithXMin:(double)xMin
             yMin:(double)yMin
             zMin:(double)zMin
             xMax:(double)xMax
             yMax:(double)yMax
             zMax:(double)zMax
 spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param mMin The min measure value
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param mMax The max measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithXMin:(double)xMin
             yMin:(double)yMin
             mMin:(double)mMin
             xMax:(double)xMax
             yMax:(double)yMax
             mMax:(double)mMax
 spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param zMin The min coordinate along z-axis
 @param mMin The min measure value
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param zMax The max coordinate along z-axis
 @param mMax The max measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
-(instancetype)initWithXMin:(double)xMin
             yMin:(double)yMin
             zMin:(double)zMin
             mMin:(double)mMin
             xMax:(double)xMax
             yMax:(double)yMax
             zMax:(double)zMax
             mMax:(double)mMax
 spatialReference:(nullable AGSSpatialReference *)spatialReference;


+(instancetype)envelopeWithCenter:(AGSPoint *)center width:(double)width height:(double)height;

+(instancetype)envelopeWithCenter:(AGSPoint *)center width:(double)width height:(double)height depth:(double)depth;

/**
 Initializes an envelope geometry with the provided min and max points.
 
 @param min The min coordinate along x-axis (lower left corner)
 @param max The min coordinate along y-axis (lower left corner)
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)envelopeWithMin:(AGSPoint*)min max:(AGSPoint*)max;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)envelopeWithXMin:(double)xMin
                           yMin:(double)yMin
                           xMax:(double)xMax
                           yMax:(double)yMax
               spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param zMin The min coordinate along z-axis
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param zMax The max coordinate along z-axis
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)envelopeWithXMin:(double)xMin
                           yMin:(double)yMin
                           zMin:(double)zMin
                           xMax:(double)xMax
                           yMax:(double)yMax
                           zMax:(double)zMax
               spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param mMin The min measure value
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param mMax The max measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)envelopeWithXMin:(double)xMin
                           yMin:(double)yMin
                           mMin:(double)mMin
                           xMax:(double)xMax
                           yMax:(double)yMax
                           mMax:(double)mMax
               spatialReference:(nullable AGSSpatialReference *)spatialReference;

/**
 Initializes an envelope geometry with the provided coordinate values.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param zMin The min coordinate along z-axis
 @param mMin The min measure value
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @param zMax The max coordinate along z-axis
 @param mMax The max measure value
 @param spatialReference The coordinate system that the coordinate values use.
 @return An initialized envelope geometry
 @note The envelope geometry is immutable, it cannot be modified after being created. Use `#toBuilder:` to get a builder to further modify the geometry.
 @since 100
 */
+(instancetype)envelopeWithXMin:(double)xMin
                           yMin:(double)yMin
                           zMin:(double)zMin
                           mMin:(double)mMin
                           xMax:(double)xMax
                           yMax:(double)yMax
                           zMax:(double)zMax
                           mMax:(double)mMax
               spatialReference:(nullable AGSSpatialReference *)spatialReference;

#pragma mark -
#pragma mark properties

/**
 The min coordinate along x-axis (lower left corner)
 
 @since 100
 */
@property (nonatomic, readonly) double xMin;

/**
 The max coordinate along x-axis (upper right corner)
 
 @since 100
 */
@property (nonatomic, readonly) double xMax;

/**
 The min coordinate along y-axis (lower left corner)
 
 @since 100
 */
@property (nonatomic, readonly) double yMin;

/**
 The max coordinate along y-axis (upper right corner)
 
 @since 100
 */
@property (nonatomic, readonly) double yMax;

/**
 The min coordinate along z-axis.
 Only applicable for 3D envelope geometries.
 
 @since 100
 @see `AGSGeometry#hasZ` to check if the geometry has z-values.
 */
@property (nonatomic, readonly) double zMin;

/**
 The max coordinate along z-axis.
 Only applicable for 3D envelope geometries.
 
 @since 100
 @see `AGSGeometry#hasZ` to check if the geometry has z-values.
 */
@property (nonatomic, readonly) double zMax;

/**
 The min measure value.
 
 @since 100
 @see `AGSGeometry#hasM` to check if the geometry has measure values.
 */
@property (nonatomic, readonly) double mMin;

/**
 The max measure value.
 
 @since 100
 @see `AGSGeometry#hasM` to check if the geometry has measure values.
 */
@property (nonatomic, readonly) double mMax;

/**
 The geographic center of the envelope.
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *center;

/**
 The width of the envelope (along x-axis).
 
 @since 100
 */
@property (nonatomic, assign, readonly) double width;

/**
 The height of the envelope (along y-axis)
 
 @since 100
 */
@property (nonatomic, assign, readonly) double height;

@property (nonatomic, assign, readonly) double depth;


#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point.
 The builder can then be modified to produce a new geometry.
 
 @return builder that can be used to build envelope geometries.
 @since 100
 @note Operations on the builder affect only its own internal copy of the geometry. They do not affect this geometry.
 */
-(AGSEnvelopeBuilder*)toBuilder;

/**
 Compares whether two envelope geometries are equal.
 
 @param other envelope to compare this envelope to
 @return YES if the envelopes are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSEnvelope*)other;

NS_ASSUME_NONNULL_END
@end

