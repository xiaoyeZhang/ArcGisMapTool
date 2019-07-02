/*
 COPYRIGHT 2013 ESRI
 
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
@class AGSLinearUnit;
@class AGSAngularUnit;

/** @file AGSGeodeticDistanceResult.h */ //Required for Globals API doc

/** @brief A result of @c AGSGeometryEngine#geodeticDistanceBetweenPoint1:point2:inUnits: method
 
Instances of this class represent results of the geodetic distance search using AGSGeometryEngine.
 
 @define{AGSGeodeticDistanceResult.h, ArcGIS}
 @since 100
 */
@interface AGSGeodeticDistanceResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark properties

/** The geodetic distance from the two input points.
 @since 100
 */
@property (nonatomic, assign, readonly) double distance;

/** The units that the distance is in
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLinearUnit *distanceUnit;

/**
Output azimuth1 in degrees at the point 1 towards point 2 (clockwise angle between tangent vector at point1 in the direction of the curve towards point2 and meridian passing through the point1).
 @since 100
 */
@property (nonatomic, assign, readonly) double azimuth1;

/**
 Output azimuth2 in degrees at the point 2 towards point 1 (clockwise angle between tangent vector at point2 in the direction of the curve towards point2 and meridian passing through the point2).
 @since 100
 */
@property (nonatomic, assign, readonly) double azimuth2;

/** The unit that the azimuth is in
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSAngularUnit *azimuthUnit;

NS_ASSUME_NONNULL_END
@end
