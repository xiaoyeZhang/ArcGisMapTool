/*
 COPYRIGHT 2015 ESRI
 
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

#import "AGSObject.h"

@class AGSPoint;
@class AGSPointCollection;
@class AGSEnumerator;


/** @file AGSMutablePointCollection.h */ //Required for Globals API doc

/** @brief Mutable collection of points of a multipoint geometry builder.
 
 Instances of this class represent a mutable collection of points of a multipoint geometry builder (`AGSMultipointBuilder`). 
 
 This class adopts `%NSFastEnumeration` which permits the collection to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let collection:AGSMutablePointCollection = ... //A collection of points
 for point in collection {
   //do something
 }
 ```
 This class also provides subscripting support. So you can access points using the subscript syntax. For example -
 
 ``` Swift
 let collection:AGSMutablePointCollection = ... //A collection of points
 let point = collection[0] //The point at 0th index
 collection[0] = newPoint //Replace point at 0th index
 ```
 
 @since 100
 @see `AGSMultipointBuilder` for multipoint geometry builder
 */

@interface AGSMutablePointCollection : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a collection with specified spatial reference. All points that belong to this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the collection
 @return Initialized collection of points
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
-(instancetype)initWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Initialize a collection with specified spatial reference. All points that belong to this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the collection
 @return Initialized collection of points
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
+(instancetype)pointCollectionWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;

#pragma mark -
#pragma mark properties

/**
 Indicates whether the collection is empty or not.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL isEmpty;

/**
 The number of points in the collection.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 The spatial reference associated with points in the collection. It specifies the coordinate system for each point's  x & y coordinate values. All points in this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

/** Add a point to the end of this collection
 @param point to add
 @return position where point was added. 0 is the first position
 @since 100
 */
-(NSInteger)addPoint:(AGSPoint*)point;

/** Add a point to the end of this collection
 @param x coordinate of the point
 @param y coordinate of the point
 @return position where point was added. 0 is the first position
 @since 100
 */
-(NSInteger)addPointWithX:(double)x y:(double)y;

/** Add a point to the end of this collection
 @param x coordinate of the point
 @param y coordinate of the point
 @param z coordinate of the point
 @return position where point was added. 0 is the first position
 @since 100
 */
-(NSInteger)addPointWithX:(double)x y:(double)y z:(double)z;

/** Add points from the provided array to the end of this collection
 @param points to add
 @since 100
 */
-(void)addPoints:(NSArray<AGSPoint*>*)points;

/** Insert a point at the specified position
 @param point to insert
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPoint:(AGSPoint*)point atIndex:(NSInteger)index;

/** Insert a point at the specified position
 @param x coordinate of the point
 @param y coordinate of the point
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPointWithX:(double)x y:(double)y atIndex:(NSInteger)index;

/** Insert a point at the specified position
 @param x coordinate of the point
 @param y coordinate of the point
 @param z coordinate of the point
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPointWithX:(double)x y:(double)y z:(double)z atIndex:(NSInteger)index;

/** Remove point at specified position
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)removePointAtIndex:(NSInteger)index;

/** Remove all points from this collection
 @since 100
 */
-(void)removeAllPoints;

/**
 Returns the index of the specified point.
 @param point whose index needs to be located.
 @return An index of specified point
 @since 100
 */
-(NSInteger)indexOfPoint:(AGSPoint*)point;

/**
 Returns the point at the specified index.
 @param index An index within the bounds of the collection.
 @return The point located at the index
 @since 100
 */
-(AGSPoint*)pointAtIndex:(NSInteger)index;

/** Replace existing point with the specified one
 @param point to replace with
 @param index of point to replace
 @since 100
 */
-(void)setPoint:(AGSPoint*)point atIndex:(NSInteger)index;

/**
 Returns the point at the specified index.
 Supports accessing an individual point using array-style subscript expressions.
 
 ``` Swift
 let collection:AGSMutablePointCollection = ... //A collection of points
 let point = collection[0] //The point at 0th index
 ```
 
 @param idx An index within the bounds of the collection.
 @return The point located at the index
 @since 100
 */
-(AGSPoint*)objectAtIndexedSubscript:(NSInteger)idx;

/** Sets the point at the specified index.
 Supports assigning an individual point using array-style subscript expressions.
 For example -
 
 ``` Swift
 let collection:AGSMutablePointCollection = ... //A collection of points
 collection[0] = newPoint //Replace point at 0th index
 ```
 
 @param obj segment to set
 @param idx subscript index
 @since 100
 */
-(void)setObject:(AGSPoint*)obj atIndexedSubscript:(NSInteger)idx;

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
