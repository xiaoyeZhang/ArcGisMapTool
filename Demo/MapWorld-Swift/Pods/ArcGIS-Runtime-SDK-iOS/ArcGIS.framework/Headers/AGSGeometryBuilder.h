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

@class AGSGeometry;
@class AGSSpatialReference;
@class AGSEnvelope;

/**
 @brief A builder to build geometries.
 
 Instances of this class represent a builder that can build geometries.
 Geometries are immutable, they cannot be modified after they are created. Use builders to create new geometries either from scratch, or by using an existing geometry as a starting off point. Modifications made through the builder affect only its own internal copy of the geometry. They do not affect the original geometry.

 
 @since 100
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map
 */
@interface AGSGeometryBuilder : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/**
 Factory method to create a geometry builder from a geometry.
 
 @param geometry The geometry to be used as the starting point for further modifications
 @since 100
 */
+(AGSGeometryBuilder*)builderWithGeometry:(nullable AGSGeometry*)geometry;

/**
 Factory method to create a geometry builder from a geometry type and spatial reference.
 
 @param geometryType The type of geometry to be constructed
 @param sr The spatial reference for the geometry to be constructed
 @since 100
 */
+(AGSGeometryBuilder*)builderWithGeometryType:(AGSGeometryType)geometryType spatialReference:(nullable AGSSpatialReference*)sr;

#pragma mark -
#pragma mark properties

/**
 The spatial reference associated with the builder's gometry. It specifies the coordinate system for the geometry's x, y, and z coordinate values.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 @see `AGSGeometry#spatialReference`
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/**
 Smallest, rectangular bounding-box that covers the builder's geometry.
 
 @since 100
 @see `AGSGeometry#extent`
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/**
 Indicates whether the builder's geometry contains z coordinate values.
 
 @since 100
 @see `AGSGeometry#hasZ`
 */
@property (nonatomic, assign, readonly) BOOL hasZ;

/**
 Indicates whether the builder's geometry contains m (measure) values.
 
 @since 100
 @see `AGSGeometry#hasM`
 */
@property (nonatomic, assign, readonly) BOOL hasM;

/**
 The type of geometry the builder will construct or modify.
 
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

#pragma mark -
#pragma mark methods

/**
 Indicates whether the builder's geometry is empty.
 
 @return YES if the geometry is empty
 @since 100
 @see `AGSGeometry#isEmpty`
 */
-(BOOL)isEmpty;

/**
 Replaces the builder's geometry with the provided one.
 
 @param geometry to replace with
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)replaceGeometry:(nullable AGSGeometry*)geometry;

/**
 Returns the geometry this builder is constructing or modifying.
 
 @return geometry
 @since 100
 */
-(AGSGeometry*)toGeometry;

NS_ASSUME_NONNULL_END
@end
