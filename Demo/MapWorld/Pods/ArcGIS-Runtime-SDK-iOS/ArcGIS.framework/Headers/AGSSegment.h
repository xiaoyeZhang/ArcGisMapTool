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

/** @file AGSSegment.h */ //Required for Globals API doc

/** @brief Base class for all segment types.
 
 Base class for all segment types.
 
 @since 100
 */
@interface AGSSegment : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The start point of the segment.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *startPoint;

/** The end point of the segment.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *endPoint;

/** Determines whether the segment is closed or not.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isClosed) BOOL closed;

/** The spatial reference of the segment.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

/** Determines whether or not two time segments are equal.
 @param other The segment to compare the current segment with.
 @since 100
 */
-(BOOL)isEqualToSegment:(AGSSegment*)other;

NS_ASSUME_NONNULL_END
@end
