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
@class AGSEnvelope;
@class AGSPoint;

/**
 @brief A builder to build envelope geometries.
 
 Instances of this class represent a builder that can build envelope geometries.
 Envelope geometries are immutable, they cannot be modified after they are created. Use builders to create new geometries either from scratch, or by using an existing geometry as a starting off point. Modifications made through the builder affect only its own internal copy of the geometry. They do not affect the original geometry.

 
 @since 100
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map
 */
@interface AGSEnvelopeBuilder : AGSGeometryBuilder
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes an envelope builder with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @return An initialized envelope builder
 @since 100.1
 */
-(instancetype)initWithCenter:(AGSPoint *)center width:(double)width height:(double)height;

/**
 Initializes an envelope builder with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @return An initialized envelope builder
 @since 100.1
 */
+(instancetype)envelopeBuilderWithCenter:(AGSPoint *)center width:(double)width height:(double)height;

/**
 Initializes an envelope builder with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @param depth of the envelope (in meters)
 @return An initialized envelope builder
 @since 100.1
 */
-(instancetype)initWithCenter:(AGSPoint *)center width:(double)width height:(double)height depth:(double)depth;

/**
 Initializes an envelope builder with the provided center and dimensions.
 
 @param center The coorinates of the envelope's center
 @param width of the envelope (in units specified by the center's spatial reference)
 @param height of the envelope (in units specified by the center's spatial reference)
 @param depth of the envelope (in meters)
 @return An initialized envelope builder
 @since 100.1
 */
+(instancetype)envelopeBuilderWithCenter:(AGSPoint *)center width:(double)width height:(double)height depth:(double)depth;

/**
 Initializes an empty envelope builder.
 
 @param sr The spatial reference for the geometry to be constructed
 @return An initialized envelope builder
 @since 100
 */
-(instancetype)initWithSpatialReference:(nullable AGSSpatialReference*)sr;

/**
 Initializes an empty envelope builder.
 
 @param sr The spatial reference for the geometry to be constructed
 @return An initialized envelope builder
 @since 100
 */
+(instancetype)envelopeBuilderWithSpatialReference:(nullable AGSSpatialReference*)sr;

/**
 Initializes an envelope builder with the provided envelope.
 
 @param envelope The geometry to be used as the starting point for further modifications. Can be nil.
 @return An initialized envelope builder
 @since 100
 */
-(instancetype)initWithEnvelope:(nullable AGSEnvelope *)envelope;

/**
 Initializes an envelope builder with the provided envelope.
 
 @param envelope The geometry to be used as the starting point for further modifications. Can be nil.
 @return An initialized envelope builder
 @since 100
 */
+(instancetype)envelopeBuilderWithEnvelope:(nullable AGSEnvelope *)envelope;

#pragma mark -
#pragma mark properties

/**
 The min coordinate of the builder's envelope geometry along x-axis (lower left corner)
 
 @since 100
 */
@property (nonatomic, readwrite) double xMin;

/**
 The max coordinate of the builder's envelope geometry along x-axis (upper right corner)
 
 @since 100
 */
@property (nonatomic, readwrite) double xMax;

/**
 The min coordinate of the builder's envelope geometry along y-axis (lower left corner)
 
 @since 100
 */
@property (nonatomic, readwrite) double yMin;

/**
 The max coordinate of the builder's envelope geometry along y-axis (upper right corner)
 
 @since 100
 */
@property (nonatomic, readwrite) double yMax;

/**
 The min coordinate of the builder's envelope geometry along z-axis.
 Only applicable for 3D envelope geometries.
 
 @since 100
 */
@property (nonatomic, readwrite) double zMin;

/**
 The max coordinate of the builder's envelope geometry along z-axis.
 Only applicable for 3D envelope geometries.
 
 @since 100
 */
@property (nonatomic, readwrite) double zMax;

/**
 The min measure value of the builder's envelope geometry.
 
 @since 100
 */
@property (nonatomic, readwrite) double mMin;

/**
 The max measure value of the builder's envelope geometry.
 
 @since 100
 */
@property (nonatomic, readwrite) double mMax;

/**
 The geographic center of the builder's envelope.
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *center;

/**
 The width of the builder's envelope (along x-axis).
 
 @since 100
 */
@property (nonatomic, assign, readonly) double width;

/**
 The height of the builder's envelope (along y-axis)
 
 @since 100
 */
@property (nonatomic, assign, readonly) double height;

@property (nonatomic, assign, readonly) double depth;

#pragma mark -
#pragma mark methods

/**
 Updates the builder's envelope geometry with given coordinates.
 
 @param xMin The min coordinate along x-axis (lower left corner)
 @param yMin The min coordinate along y-axis (lower left corner)
 @param xMax The max coordinate along x-axis (upper right corner)
 @param yMax The max coordinate along y-axis (upper right corner)
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)setXMin:(double)xMin yMin:(double)yMin xMax:(double)xMax yMax:(double)yMax;

/**
 Updates the builder's envelope geometry with given coordinates.
 
 @param mMin The min measure value
 @param mMax The max measure value
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)setMMin:(double)mMin mMax:(double)mMax;

/**
 Updates the builder's envelope geometry with given coordinates.
 
 @param zMin The min coordinate along z-axis
 @param zMax The max coordinate along z-axis
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)setZMin:(double)zMin zMax:(double)zMax;

/**
 Re-centers the builder's envelope geometry at the specified location. The point's spatial reference must be the same as the builder's.

 @param point to center at
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)centerAtPoint:(AGSPoint *)point;

/**
 Unions the builder's envelope with the given envelope. The envelope's spatial reference must be the same as the builder's.

 @param envelope to union with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)unionWithEnvelope:(AGSEnvelope *)envelope;

/**
 Unions the builder's envelope geometry with the given point.  The point's spatial reference must be the same as the builder's.

 @param point to union with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)unionWithPoint:(AGSPoint *)point;

/**
 Expands the builder's envelope geometry.
 A factor < 1.0 shrinks the envelope and > 1.0 expands it. The envelope's center remains unchanged, but its corners change. This is the same as calling `#expandByFactor:withAnchorPoint:` with the envelope's center.

 @param factor	The factor to scale envelope by.
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)expandByFactor:(double)factor;

/**
 Expands the builder's envelope geometry.
 A factor < 1.0 shrinks the envelope and > 1.0 expands it. The specified anchor point of the envelope remains unchanged, but the envelope's  corners change.
 
 @param factor	The factor to scale envelope by.
 @param anchorPoint	A point within the envelope to expand from.
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)expandByFactor:(double)factor withAnchorPoint:(AGSPoint*)anchorPoint;

/**
 Reaspect the builder's envelope geometry to match the given aspect ratio.
 The envelope's center remains unchanged, but its corners change.
 
 @param size to reaspect the envelope.
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)changeAspectRatio:(CGSize)size;

/**
 Move the builder's envelope geometry.
 
 @param offsetX offset along x-axis (negative value moves the envelope east)
 @param offsetY offset along y-axis (negative value moves the envelope south)
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)offsetByX:(double)offsetX y:(double)offsetY;

/**
 Replaces the builder's geometry with the provided one.
 
 @param geometry to replace with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)replaceGeometry:(nullable AGSEnvelope*)geometry;

/**
 Returns the envelope geometry this builder is constructing or modifying.
 
 @return geometry
 @since 100
 */
-(AGSEnvelope*)toGeometry;

NS_ASSUME_NONNULL_END
@end
