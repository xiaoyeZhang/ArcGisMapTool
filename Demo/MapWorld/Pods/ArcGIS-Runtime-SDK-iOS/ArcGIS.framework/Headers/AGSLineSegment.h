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

#import "AGSSegment.h"

@class AGSPoint;
@class AGSSpatialReference;

/** @file AGSLineSegment.h */ //Required for Globals API doc

/** @brief A line segment
 
 Instances of this class represents a line segment. A line segment is a pair of start and end points.
 
 @since 100
 */
@interface AGSLineSegment : AGSSegment
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a line segment with the provided start and end points.
 
 @param startPoint The start point
 @param endPoint The end point
 @since 100
 */
-(instancetype)initWithStartPoint:(AGSPoint*)startPoint endPoint:(AGSPoint*)endPoint;

/**
 Initializes a line segment with the provided spatial reference, start and end points.
 
 @param startPoint The start point
 @param endPoint The end point
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
-(instancetype)initWithStartPoint:(AGSPoint*)startPoint endPoint:(AGSPoint*)endPoint spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided coordinate values.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @since 100
 */
-(instancetype)initWithXStart:(double)xStart yStart:(double)yStart xEnd:(double)xEnd yEnd:(double)yEnd;

/**
 Initializes a line segment with the provided coordinate values and spatial reference.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
-(instancetype)initWithXStart:(double)xStart yStart:(double)yStart xEnd:(double)xEnd yEnd:(double)yEnd spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided coordinate values.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param zStart The start coordinate along z-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param zEnd The end coordinate along z-axis
 @since 100
 */
-(instancetype)initWithXStart:(double)xStart yStart:(double)yStart zStart:(double)zStart xEnd:(double)xEnd yEnd:(double)yEnd zEnd:(double)zEnd;

/**
 Initializes a line segment with the provided coordinate values and spatial reference.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param zStart The start coordinate along z-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param zEnd The end coordinate along z-axis
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
-(instancetype)initWithXStart:(double)xStart yStart:(double)yStart zStart:(double)zStart xEnd:(double)xEnd yEnd:(double)yEnd zEnd:(double)zEnd spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided start point, angle and length.
 
 @param startPoint The start coordinate along x-axis
 @param angle The angle in radians
 @param length The length in the unit of start point's spatial reference
 @since 100
 */
-(instancetype)initWithStartPoint:(AGSPoint*)startPoint angle:(double)angle length:(double)length;

/**
 Initializes a line segment with the provided start and end points.
 
 @param startPoint The start point
 @param endPoint The end point
 @since 100
 */
+(instancetype)lineSegmentWithStartPoint:(AGSPoint*)startPoint endPoint:(AGSPoint*)endPoint;

/**
 Initializes a line segment with the provided spatial reference, start and end points.
 
 @param startPoint The start point
 @param endPoint The end point
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
+(instancetype)lineSegmentWithStartPoint:(AGSPoint*)startPoint endPoint:(AGSPoint*)endPoint spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided coordinate values.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @since 100
 */
+(instancetype)lineSegmentWithXStart:(double)xStart yStart:(double)yStart xEnd:(double)xEnd yEnd:(double)yEnd;

/**
 Initializes a line segment with the provided coordinate values.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
+(instancetype)lineSegmentWithXStart:(double)xStart yStart:(double)yStart xEnd:(double)xEnd yEnd:(double)yEnd spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided coordinate values.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param zStart The start coordinate along z-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param zEnd The end coordinate along z-axis
 @since 100
 */
+(instancetype)lineSegmentWithXStart:(double)xStart yStart:(double)yStart zStart:(double)zStart xEnd:(double)xEnd yEnd:(double)yEnd zEnd:(double)zEnd;


/**
 Initializes a line segment with the provided coordinate values and spatial reference.
 
 @param xStart The start coordinate along x-axis
 @param yStart The start coordinate along y-axis
 @param zStart The start coordinate along z-axis
 @param xEnd The end coordinate along x-axis
 @param yEnd The end coordinate along y-axis
 @param zEnd The end coordinate along z-axis
 @param spatialReference The spatial reference for the line segment to be constructed
 @since 100
 */
+(instancetype)lineSegmentWithXStart:(double)xStart yStart:(double)yStart zStart:(double)zStart xEnd:(double)xEnd yEnd:(double)yEnd zEnd:(double)zEnd spatialReference:(nullable AGSSpatialReference*)spatialReference;

/**
 Initializes a line segment with the provided start point, angle and length.
 
 @param startPoint The start coordinate along x-axis
 @param angle The angle in radians
 @param length The length in the unit of start point's spatial reference
 @since 100
 */
+(instancetype)lineSegmentWithStartPoint:(AGSPoint*)startPoint angle:(double)angle length:(double)length;

NS_ASSUME_NONNULL_END
@end
