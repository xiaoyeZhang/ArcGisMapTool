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
@class AGSPoint;
@class AGSMutablePartCollection;

/**
 @brief A builder to construct or modify multipart geometries.
 
 Instances of this class represent a builder that can construct or modify multipart geometries such as `AGSPolygon` and `AGSPolyline` which are otherwise immutable.
 
 @since 100
 @see `AGSSketchEditor` to construct or modify geometries interactively by sketching on a map
 */
@interface AGSMultipartBuilder : AGSGeometryBuilder
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 The parts of the builder's geometry.
 Can be iterated through a for-in loop.
 
 ~~~ Objective-C
 AGSPolygonBuilder* polygonBuilder = ... ; //builder whose polygon contains 2 parts (rings)
 for (AGSMutablePart *part in polygonBuilder.parts){
   ...
 }
 
 ~~~
 
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSMutablePartCollection *parts;

#pragma mark -
#pragma mark methods

/**
 Add new part with given points to the builder's multipart geometry.
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)addPartWithPoints:(NSArray<AGSPoint*>*)points;

/**
 Appends a vertex to the builder's multipart geometry
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)addPoint:(AGSPoint*)point;

/**
 Appends a vertex to the builder's multipart geometry
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)addPointWithX:(double)x y:(double)y;

/**
 Appends a vertex to the builder's multipart geometry
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)addPointWithX:(double)x y:(double)y z:(double)z;

/**
 Add points to the builder's multipart geometry at given part index.
 @return the builder so you can easily chain method calls
 @since 100
 */
-(instancetype)addPoints:(NSArray<AGSPoint*>*)points toPartAtIndex:(NSInteger)partIndex;

NS_ASSUME_NONNULL_END
@end
