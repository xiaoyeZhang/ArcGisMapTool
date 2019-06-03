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
@class AGSSpatialReference;
@class AGSSegment;
@class AGSPointCollection;
@class AGSEnumerator;

/** @file AGSMutablePart.h */ //Required for Globals API doc

/** @brief A mutable part of a multipart geometry
 
 Instances of this class represent an individual, modifiable, part of a multipart geometry such as polygon or polyline. A part is a collection of segments that define the shape of the part. As a convenience, you can
 work with points that represent the vertices of the part, instead of working with segments. 
 
 The part is mutable so it can be modified which is useful when constructing or modifying geometries using builders.
 
 This class adopts `%NSFastEnumeration` which permits the part's segments to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let part:AGSMutablePart = ... //A part containing segments
 for segment in part {
   //do something
 }
 ```
 
 This class also provides subscripting support. So you can access and set segments using the subscript syntax. For example - 
 
 ``` Swift
 let part:AGSMutablePart = ... //A part containing segments
 let segment = part[0] //The segment at 0th index
 let part[1] = newSegment //Set new segment at 1st index
 ```
 
 
 @since 100
 */
@interface AGSMutablePart : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a part with specified spatial reference. All segments and vertices that belong to this part must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the part
 @return Initialized part
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.

 */
-(instancetype)initWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Initialize a part with specified spatial reference. All segments and vertices that belong to this part must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 @param spatialReference of the part
 @return Initialized part
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
+(instancetype)partWithSpatialReference:(nullable AGSSpatialReference*)spatialReference;


/** Initialize a part with points.
 @param points for the part to be constructed
 @since 100
 */
-(instancetype)initWithPoints:(NSArray<AGSPoint*>*)points;

/** Initialize a part with points.
 @param points for the part to be constructed
 @since 100
 */
+(instancetype)partWithPoints:(NSArray<AGSPoint*>*)points;

#pragma mark -
#pragma mark properties

/** Indicates whether the part contains any segments
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/** Number of vertices in the part.  Each segment contains 2 vertices (start and end). Connected segments can share a vertex.

 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger pointCount;

/** Number of segments in the part
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger segmentCount;

/**
 The spatial reference associated with segments and vertices in this part. It specifies the coordinate system for each segment and vertex's x & y coordinate values.
 All segments and vertices that belong to this part must have the same spatial reference, or if they don't have a spatial reference, it will be assumed that they contain coordinates that match this spatial reference.
 
 @since 100
 @note Geometries that represent geographic locations should always have a spatial reference. Otherwise the coordinates of the geometry are meaningless.
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Starting vertex of the first segment in the part
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) AGSPoint *startPoint;

/** Ending vertex of the last segment in the part
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) AGSPoint *endPoint;

/** All the vertices in this part
 @since 100
 */
@property (nonatomic, copy, readonly) AGSPointCollection *points;

#pragma mark -
#pragma mark methods

/** Add a vertex to the the end of this part
 @param point vertex to add
 @return position where vertex was added
 @since 100
 */
-(NSInteger)addPoint:(AGSPoint*)point;

/** Add a vertex to the the end of this part
 @param x coordinate of the vertex
 @param y coordiante of the vertex
 @return position where vertex was added
 @since 100
 */
-(NSInteger)addPointWithX:(double)x y:(double)y;

/** Add a vertex to the the end of this part
 @param x coordinate of the vertex
 @param y coordiante of the vertex
 @param z coordinate of the vertex
 @return position where vertex was added
 @since 100
 */
-(NSInteger)addPointWithX:(double)x y:(double)y z:(double)z;

/** Add points from the provided array to the end of this part
 @param points to add
 @since 100
 */
-(void)addPoints:(NSArray<AGSPoint*>*)points;

/** Add a segment to the the end of this part
 @param segment to add
 @return position where segment was added
 @since 100
 */
-(NSInteger)addSegment:(AGSSegment*)segment;

/** Insert a vertex at the specified position
 @param point vertext to add
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPoint:(AGSPoint*)point atIndex:(NSInteger)index;

/** Insert a vertex at the specified position
 @param x coordinate of the vertex
 @param y coordiante of the vertex
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPointWithX:(double)x y:(double)y atIndex:(NSInteger)index;

/** Insert a vertex at the specified position
 @param x coordinate of the vertex
 @param y coordiante of the vertex
 @param z coordinate of the vertex
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertPointWithX:(double)x y:(double)y z:(double)z atIndex:(NSInteger)index;

/** Insert a segment at the specified position
 @param segment to add
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)insertSegment:(AGSSegment*)segment atIndex:(NSInteger)index;

/** Remove vertex at specified position
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)removePointAtIndex:(NSInteger)index;

/** Remove segment at specified position
 @param index of desired position. 0 is the first position
 @since 100
 */
-(void)removeSegmentAtIndex:(NSInteger)index;

/** Remove all segments (and thereby also vertices) from the part
 @since 100
 */
-(void)removeAllSegments;

/** Replace existing vertex with the specified one
 @param point vertex to replace with
 @param index of vertex to replace
 @since 100
 */
-(void)setPoint:(AGSPoint*)point atIndex:(NSInteger)index;

/** Replace existing segment with the specified one
 @param segment to replace with
 @param index of segment to replace
 @since 100
 */
-(void)setSegment:(AGSSegment*)segment atIndex:(NSInteger)index;

/** Vertex at specified position in the part
 @param index of desired position. 0 is the first position
 @return vertex at specified index
 @since 100
 */
-(AGSPoint*)pointAtIndex:(NSInteger)index;

/** Segment at specified position in the part
 @param index of desired position. 0 is the first position
 @return segment at specified index
 @since 100
 */
-(AGSSegment*)segmentAtIndex:(NSInteger)index;

/** Position of segment that contains the specified vertex as its starting point
 @param pointIndex representing the position of vertex which serves as the starting point for the segment
 @return Position of segment. 0 is the first position
 @since 100
 */
-(NSInteger)segmentIndexForStartPointIndex:(NSInteger)pointIndex;

/** Position of segment that contains the specified vertex as its ending point
 @param pointIndex representing the position of vertex which serves as the ending point for the segment
 @return Position of segment. 0 is the first position
 @since 100
 */
-(NSInteger)segmentIndexForEndPointIndex:(NSInteger)pointIndex;

/** Position of staring vertex for the specified segment
 @param segmentIndex representing the position of the segment whose starting vertex is desired
 @return Position of the starting vertex. 0 is the first position
 @since 100
 */
-(NSInteger)startPointIndexForSegmentIndex:(NSInteger)segmentIndex;

/** Position of ending vertex for the specified segment
 @param segmentIndex representing the position of the segment whose ending vertex is desired
 @return Position of the ending vertex. 0 is the first position
 @since 100
 */
-(NSInteger)endPointIndexForSegmentIndex:(NSInteger)segmentIndex;

//I don't know what this is for or what it does
-(void)segmentIndexForPointIndex:(NSInteger)pointIndex outSegmentStartPointIndex:(NSInteger*)outSegmentStartPointIndex outSegmentEndPointIndex:(NSInteger*)outSegmentEndPointIndex;

/** Returns the segment at the specified index.
 Supports accessing an individual segment using array-style subscript expressions.
 
 For example -
 
 ``` Swift
 let part:AGSPart = ... //A part containing segments
 let segment = part[0] //The segment at 0th index
 ```
 
 @param idx subscript index
 @return segment at subscript index
 @since 100
 */
-(AGSSegment*)objectAtIndexedSubscript:(NSInteger)idx;

/** Sets the segment at the specified index.
 Supports assigning an individual segment using array-style subscript expressions.
 For example -
 
 ``` Swift
 let part:AGSPart = ... //A part containing segments
 let segment:AGSSegment = ... //A new segment
 let part[0] = segment //Set the new segment
 ```
 
 @param obj segment to set
 @param idx subscript index
 @since 100
 */

-(void)setObject:(AGSSegment*)obj atIndexedSubscript:(NSInteger)idx;

/**
 Returns an enumerator object that lets you access each point in the segment collection.
 @since 100
 */
-(AGSEnumerator*)pointEnumerator;

/**
 Returns an enumerator object that lets you access each segment in the segment collection.
 @since 100
 */
-(AGSEnumerator*)segmentEnumerator;

/**
 Returns an array of segments.
 @since 100
 */
-(NSArray<AGSSegment*>*)array;

NS_ASSUME_NONNULL_END
@end
