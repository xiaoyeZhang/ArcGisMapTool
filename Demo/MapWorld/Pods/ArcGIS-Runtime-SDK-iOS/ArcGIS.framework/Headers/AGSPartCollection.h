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

#import "AGSObject.h"
@class AGSPart;
@class AGSEnumerator;

/** @file AGSPartCollection.h */ //Required for Globals API doc

/**
 @brief Parts of a multipart geometry (`AGSMultipart`).
 
 Instances of this class represent the parts of a multipart geometry (`AGSMultipart`). For example, polygons have multiple parts where each part is a ring and polylines have multiple parts where each part is a line.
 
 This class adopts `%NSFastEnumeration` which permits the collection to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let collection:AGSPartCollection = ... //A collection of parts
 for part in collection {
 //do something
 }
 ```
 This class also provides subscripting support. So you can access segments using the subscript syntax. For example -
 
 ``` Swift
 let collection:AGSPartCollection = ... //A collection of parts
 let part = collection[0] //The part at 0th index
 ```

 
 @since 100
 @see `AGSMultipart` for multipart geometries
 */
@interface AGSPartCollection : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 The number of parts of the geometry.
 
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 The total number of points (vertices) across all parts of the geometry.
 
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger totalPointCount;

/**
 Indicates whether the collection is empty or not.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/**
 The spatial reference associated with parts in the collection. It specifies the coordinate system for each part's  x & y coordinate values. All parts in this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

/**
 Returns the part at the specified index.
 
 @param index An index within the bounds of the collection.
 @return The part located at the index
 @since 100
 */
-(AGSPart*)partAtIndex:(NSInteger)index;

/**
 Returns the index of the specified part.
 
 @param part The part whose index needs to be located.
 @return An index of specified part
 @since 100
 */
-(NSInteger)indexOfPart:(AGSPart*)part;

/**
 Returns the part at the specified index.
 Supports accessing an individual part using array-style subscript expressions.
 
 ~~~ Objective-C
 AGSPolygon* polygon = ... ; //polygon with 2 parts (rings)
 AGSPartCollection* parts = polygon.parts;
 AGSPointCollection* part = parts[0]; //The 0th part
 ~~~
 
 @param idx An index within the bounds of the collection.
 @return The part located at the index
 @since 100
 */
-(AGSPart*)objectAtIndexedSubscript:(NSInteger)idx;

/**
 Returns an enumerator object that lets you access each object in the part collection.
 @since 100
 */
-(AGSEnumerator*)partEnumerator;

/**
 Returns an array of parts.
 @since 100
 */
-(NSArray<AGSPart*>*)array;

NS_ASSUME_NONNULL_END
@end
