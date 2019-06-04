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

@class AGSPoint;
@class AGSEnumerator;

/**
 @brief Vertices of a single part of a multipart geometry (`AGSMultipart`).
 
 Instances of this class represent the vertices of a single part of a multipart geometry (`AGSMultipart`). For example, polygons have multiple parts where each part is a ring and polylines have multiple parts where each part is a line. Each part is composed of a sequence of points. All points must have the same spatial reference.
 
 @since 100
 @see `AGSMultipart` for multipart geometries
 @see `AGSPartCollection` for parts of a multipart geometry
 */
@interface AGSPointCollection : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 The number of points in this collection.
 
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 Determinse whether the collection is empty or not.
 
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/**
 The spatial reference associated with the collection. It specifies the coordinate system for the geometry's x, y, and z coordinate values.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

/**
 Returns the vertex at the specified index.
 
 @param index An index within the bounds of the collection.
 @return The vertex located at the index
 @since 100
 */
-(AGSPoint*)pointAtIndex:(NSInteger)index;

/**
 Returns the index of the specified point.
 
 @param point The point whose index needs to be located.
 @return An index of specified point
 @since 100
 */
-(NSInteger)indexOfPoint:(AGSPoint*)point;

/**
 Returns the vertex at the specified index.
 Supports accessing an individual vertex using array-style subscript expressions.
 
 ~~~ Objective-C
 AGSPolygon* polygon = ... ; //polygon with 2 parts (rings)
 AGSPartCollection* parts = polygon.parts;
 AGSPointCollection* part = [parts partAtIndex:0]; //The 0th part
 AGSPoint* vertex = part[0]; //The 0th vertex in the part
 ~~~
 
 @param idx An index within the bounds of the collection.
 @return The vertex located at the index
 @since 100
 */
-(AGSPoint*)objectAtIndexedSubscript:(NSInteger)idx;

/**
 Returns an enumerator object that lets you access each object in the point collection.
 @since 100
 */
-(AGSEnumerator*)pointEnumerator;

/**
 Returns an array of points.
 @since 100
 */
-(NSArray<AGSPoint*>*)array;

NS_ASSUME_NONNULL_END
@end
