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

@class AGSSpatialReference;
@class AGSObject;
@class AGSGeometryBuilder;
@class AGSEnvelope;

/**
 @brief Base class for all geometry types.
 
 A base class for all geometry types. Geometries define a spatial location and an associated geometric shape. Types of geometries include points, polylines, polygons, envelopes, and so on. Geometries may be two-dimensional (x,y coordinates) or three-dimensional (x,y,z coordinates). They may also include an m (measure) value for each vertex.
 
 Every non-empty geometry has an inherent dimension (sometimes called the topological dimensionality) that indicates the general class of the geometry.
 
 - 0 for points and multipoints.
 - 1 for lines and polylines.
 - 2 for polygons and envelopes.
 - 3 for objects with volume.
 
 Geometries are associated with a spatial reference which specifies the coordinate system that its coordinate values use.
 
 @since 100
 @note This class represents an immutable geometry, it cannot be altered after being created. Use `#toBuilder:` to get a builder using a copy of this geometry as a starting off point. The builder can then be modified to produce a new geometry.
 @see `AGSGeometryBuilder` for constructing or modifying geometries.
 @see `AGSGeometryEngine` for performing operations on geometries.
 */
@interface AGSGeometry : AGSObject <NSCopying, AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 Indicates whether this geometry has curves.
 
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasCurves;

/**
 Indicates whether this geometry contains z coordinate values.
 Only 3D geometries contain z values.
 
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasZ;

/**
 Indicates whether this geometry contains m (measure) values.
 
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasM;

/**
 Indicates whether this geometry has any vertices.
 
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/**
 The spatial reference associated with the gometry. It specifies the coordinate system for the geometry's x, y, and z coordinate values.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/**
 Smallest, rectangular bounding-box that covers the geometry.
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/**
 The type of this geometry.
 
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;


@property (nonatomic, assign, readonly) AGSGeometryDimension dimension;

#pragma mark -
#pragma mark methods

/**
 Returns a builder using a copy of this geometry as a starting off point.
 The builder can be used to make modifications to the geometry.
 
 @return builder
 @since 100
 @note Any changes you make using the builder modifies its own internal copy of the geometry. It does not affect this geometry.
 */
-(AGSGeometryBuilder*)toBuilder;

/**
 Compares whether two geometries are equal.
 
 @param other geometry to compare this geometry to
 @return YES if the geometries are equal
 @since 100
 */
-(BOOL)isEqualToGeometry:(AGSGeometry*)other;

-(BOOL)isEqualToGeometry:(AGSGeometry*)other tolerance:(double)tolerance;

NS_ASSUME_NONNULL_END
@end

