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

@class AGSObject;
@class AGSUnit;
@class AGSPoint;

/**
 @brief Represents the spatial reference of a geometry.
 
 A spatial reference determines how map coordinates, or the x,y,z-coordinates in the vertices of geometries, correspond to locations in real-world space. Therefore, it is very important to associate geometries representing spatial data with corresponding spatial references.
 
 Each spatial reference can be represented by either a well-known ID (WKID), or a well-known text (WKT). Spatial references define the spatial properties of a geometry, for instance the coordinate system it uses. There are 2 broad classes of coordinate systems - Geographic & Projected. A Geographic Coordinate system uses a 3-dimensional spherical surface to define locations on the earth. A Projected Coordinate system on the other hand uses a flat, 2-dimensional surface.
 
 [Learn more about coordinate systems](http://help.arcgis.com/en/arcgisdesktop/10.0/help/index.html#/What_are_map_projections/003r00000001000000/)
 
 
 @since 100
 @see `AGSGeometry` for geometry types
 @see `AGSGeometryEngine#projectGeometry:toSpatialReference:` to project geometries from one spatial reference to another
 */
@interface AGSSpatialReference : AGSObject <NSCopying, AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available. You must initialize with a WKID or WKT string.")));

/**
 Initializes a spatial reference with the given well-known ID (WKID).
 
 @param WKID The well-known ID
 @since 100
 */
-(nullable instancetype)initWithWKID:(NSInteger)WKID;

/**
 Initializes a spatial reference with the given well-known text (WKT).
 
 @param WKText The well-known text
 @since 100
 */
-(nullable instancetype)initWithWKText:(NSString*)WKText;

/** Initializes a spatial reference with the given well-known ID (WKID) and a vertical well-known ID.
 @since 100
 */
-(nullable instancetype)initWithWKID:(NSInteger)WKID verticalWKID:(NSInteger)verticalWKID;

/**
 Initializes a spatial reference with the given well-known ID (WKID).
 
 @param WKID The well-known ID
 @since 100
 */
+(nullable instancetype)spatialReferenceWithWKID:(NSInteger)WKID;

/**
 Initializes a spatial reference with the given well-known text (WKT).
 
 @param WKText The well-known text
 @since 100
 */
+(nullable instancetype)spatialReferenceWithWKText:(NSString *)WKText;

/** Initializes a spatial reference with the given well-known ID (WKID) and a vertical well-known ID.
 @since 100
 */
+(nullable instancetype)spatialReferenceWithWKID:(NSInteger)WKID verticalWKID:(NSInteger)verticalWKID;

/**
 A spatial reference representing the Web Mercator coordinate system (WKID:3857, equivalent to WKID:102113)
 @since 100
 */
+(AGSSpatialReference*)webMercator;

/**
 A spatial reference representing the WGS84 coordinate system (WKID:4326)
 @since 100
 */
+(AGSSpatialReference*)WGS84;

#pragma mark -
#pragma mark properties

/**
 The well-known ID of the spatial reference.
 
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger WKID;

/**
 The well-known text of the spatial reference.
 
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *WKText;

/**
 The units of geometry's coordinates for geometries that use this spatial reference.
 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSUnit *unit;

@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *baseGeographic;
@property (nonatomic, assign, readonly, getter=isGeographic) BOOL geographic;
@property (nonatomic, assign, readonly, getter=isPannable) BOOL pannable;
@property (nonatomic, assign, readonly, getter=isProjected) BOOL projected;
@property (nonatomic, assign, readonly) NSInteger verticalWKID;

#pragma mark -
#pragma mark methods

/**
 Calculate the grid convergence for a spatial reference at a given point.
 
 Remarks
 The grid convergence is the angle between True North and Grid North at a point on a map. The grid convergence can be used to convert a horizontal direction expressed as an azimuth in a geographic coordinate system (relative to True North) to a direction expressed as a bearing in a projected coordinate system (relative to Grid North), and vice versa.
 
 Sign convention
 The grid convergence returned by this method is positive when Grid North lies east of True North. The following formula demonstrates how to obtain a bearing (b) from an azimuth (a) using the grid convergence (c) returned by this method:
 b = a - c
 This sign convention is sometimes named the Gauss-Bomford convention.
 
 Other Notes
 - Returns 0 if the spatial reference is a geographic coordinate system.
 - Returns NAN if the point is outside the projection's horizon or on error.
 - If the point has no spatial reference, it is assumed to be in the given spatial reference.
 - If the point's spatial reference differs from the spatial reference given, it's location will be transformed automatically to the given spatial reference.
 @param point at which to calculate the convergence angle
 @return The grid convergence in degrees.
 @since 100.3
 */
-(double)convergenceAngleWithPoint:(AGSPoint*)point;

/**
 Compares whether two spatial references are equal. They are equal if they have the same `#WKID` or `#WKT`.
 
 @param other spatial reference to compare this one to
 @return YES if the spatial references are equal
 @since 100
 */
-(BOOL)isEqualToSpatialReference:(AGSSpatialReference*)other;

NS_ASSUME_NONNULL_END
@end
