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

/** @file AGSPart.h */ //Required for Globals API doc

/** @brief A part of a multipart geometry
 
  Instances of this class represent an individual part of a multipart geometry such as polygon or polyline. A part is a collection of segments that define the shape of the part. As a convenience, you can
   access points that represent the vertices of the part, instead of working with segments.
 
 This class adopts `%NSFastEnumeration` which permits the part's segments to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let part:AGSPart = ... //A part containing segments
 for segment in part {
   //do something
 }
 ```
 
 This class also provides subscripting support. So you can access segments using the subscript syntax. For example -
 
 ``` Swift
 let part:AGSMutablePart = ... //A part containing segments
 let segment = part[0] //The segment at 0th index
 ```
 
 @since 100
 */
@interface AGSPart : AGSObject <NSFastEnumeration>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 Indicates whether this geometry has curves.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasCurves;

/** Indicates whether the part contains any segments
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/** Number of vertices in the part. Each segment contains 2 vertices (start and end). Connected segments can share a vertex.
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
@property (nullable, nonatomic, strong, readonly) AGSPoint *startPoint;

/** Ending vertex of the last segment in the part
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *endPoint;

/** All the vertices in this part
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPointCollection *points;

#pragma mark -
#pragma mark methods

/** Vertex at specified position in the part
 @param index of desired position. 0 is the first position
 @since 100
 */
-(AGSPoint*)pointAtIndex:(NSInteger)index;

/** Segment at specified position in the part
 @param index of desired position. 0 is the first position
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

/**
 Returns an enumerator object that lets you access each vertex in the part.
 @since 100
 */
-(AGSEnumerator*)pointEnumerator;

/**
 Returns an enumerator object that lets you access each segment in the part.
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
