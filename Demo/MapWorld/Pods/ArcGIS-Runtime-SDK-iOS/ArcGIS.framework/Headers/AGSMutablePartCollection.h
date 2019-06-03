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

@class AGSMutablePart;
@class AGSEnumerator;

/** @file AGSMutablePartCollection.h */ //Required for Globals API doc

/** @brief Mutable collection of parts of a multipart geometry builder.
 
 Instances of this class represent a mutable collection of parts of a multipart geometry builder (`AGSMultipartBuilder`). Not only is the collection modifiable, but it is made up of mutable parts and so the individual parts in the collection are also modifiable.
 
 This class adopts `%NSFastEnumeration` which permits the collection to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let collection:AGSMutablePartCollection = ... //A collection of parts
 for part in collection {
   //do something
 }
 ```
 This class also provides subscripting support. So you can access segments using the subscript syntax. For example -
 
 ``` Swift
 let collection:AGSMutablePartCollection = ... //A collection of parts
 let part = collection[0] //The part at 0th index
 collection[0] = newPart //Replace part at 0th index

 ```
 
 @since 100
 @see `AGSMultipartBuilder` for multipart geometry builders
 */

@interface AGSMutablePartCollection : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a collection with specified spatial reference. All parts that belong to this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the collection
 @return Initialized collection of parts
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
-(instancetype)initWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Initialize a collection with specified spatial reference. All parts that belong to this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the collection
 @return Initialized collection of parts
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
+(instancetype)partCollectionWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;

#pragma mark -
#pragma mark properties

/**
 Indicates whether the collection is empty or not.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL isEmpty;

/**
 The number of parts in the collection.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger count;

/**
 The spatial reference associated with parts in the collection. It specifies the coordinate system for each part's  x & y coordinate values. All parts in this collection must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/**
 The total number of points (vertices) across all parts of the geometry.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger totalPointCount;

#pragma mark -
#pragma mark methods

/** Add a part to the end of this collection
 @param part to add
 @return position where part was added. 0 is the first position
 @since 100
 */
-(NSInteger)addPart:(AGSMutablePart*)part;

/** Insert a part at the specified position
 @param part to insert
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPart:(AGSMutablePart*)part atIndex:(NSInteger)index;

/** Remove part at specified position
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)removePartAtIndex:(NSInteger)index;

/** Remove all parts from this collection
 @since 100
 */
-(void)removeAllParts;

/**
 Returns the index of the specified part.
 @param part whose index needs to be located.
 @return The index of specified part
 @since 100
 */
-(NSInteger)indexOfPart:(AGSMutablePart*)part;

/**
 Returns the part at the specified index.
 @param index An index within the bounds of the collection.
 @return The part located at the index
 @since 100
 */
-(AGSMutablePart*)partAtIndex:(NSInteger)index;

/** Replace existing part with the specified one
 @param part to replace with
 @param index of part to replace
 @since 100
 */
-(void)setPart:(AGSMutablePart*)part atIndex:(NSInteger)index;

/**
 Returns the part at the specified index.
 Supports accessing an individual part using array-style subscript expressions.
 
 ~~~ Objective-C
 AGSPolygonBuilder* polygonBldr = ... ; //polygon builder with 2 parts (rings)
 AGSMutablePartCollection* parts = polygonBldr.parts;
 AGSPart* part = parts[0]; //The 0th part
 ~~~
 
 @param idx An index within the bounds of the collection.
 @return The part located at the index
 @since 100
 */
-(AGSMutablePart*)objectAtIndexedSubscript:(NSInteger)idx;

/** Sets the part at the specified index.
 Supports assigning an individual part using array-style subscript expressions.
 For example -
 
 ~~~ Objective-C
 AGSPolygonBuilder* polygonBldr = ... ; //polygon builder with 2 parts (rings)
 AGSMutablePartCollection* parts = polygonBldr.parts;
 parts[0] = newPart //The 0th part
 ~~~
 
 @param obj part to set
 @param idx subscript index
 @since 100
 */
-(void)setObject:(AGSMutablePart*)obj atIndexedSubscript:(NSInteger)idx;

/**
 Returns an enumerator object that lets you access each object in the part collection.
 @since 100
 */
-(AGSEnumerator*)partEnumerator;

/**
 Returns an array of parts.
 @since 100
 */
-(NSArray<AGSMutablePart*>*)array;

NS_ASSUME_NONNULL_END
@end
