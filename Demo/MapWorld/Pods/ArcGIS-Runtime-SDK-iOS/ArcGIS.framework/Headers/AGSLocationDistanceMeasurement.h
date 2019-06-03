/*
 COPYRIGHT 2018 ESRI
 
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

#import "AGSAnalysis.h"

@class AGSPoint;
@class AGSDistance;

/** @file AGSLocationDistanceMeasurement.h */ //Required for Globals API doc

/** @brief Analysis of distance between two locations.
 
 Instances of this class represent an analysis object that evaluates direct, vertical, and horizontal distances between two points defined by start and end point locations.
 
 @since 100.3
 */
@interface AGSLocationDistanceMeasurement : AGSAnalysis
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));
    
/** Initialize a measurement analysis object based on the provided locations.
 @param startLocation A point that defines the start location of the measurement.
 @param endLocation A point that defines the end location of the measurement.
 @since 100.3
 */
-(instancetype)initWithStartLocation:(AGSPoint*)startLocation endLocation:(AGSPoint*)endLocation;
    
/** Initialize a measurement analysis object based on the provided locations.
 @param startLocation A point that defines the start location of the measurement.
 @param endLocation A point that defines the end location of the measurement.
 @since 100.3
 */
+(instancetype)locationDistanceMeasurementWithStartLocation:(AGSPoint*)startLocation endLocation:(AGSPoint*)endLocation;

#pragma mark -
#pragma mark properties
    
/** Point that defines the start location of the measurement.
 @since 100.3
 */
@property (nonatomic, strong, readwrite) AGSPoint *startLocation;
    
/** Point that defines the end location of the measurement.
 @since 100.3
 */
@property (nonatomic, strong, readwrite) AGSPoint *endLocation;
    
/** The direct distance length measurement component.
 @since 100.3
 */
@property (nullable, nonatomic, strong, readonly) AGSDistance *directDistance;
    
/** The horizontal distance length measurement component.
 @since 100.3
 */
@property (nullable, nonatomic, strong, readonly) AGSDistance *horizontalDistance;
    
/** The vertical distance length measurement component.
 @since 100.3
 */
@property (nullable, nonatomic, strong, readonly) AGSDistance *verticalDistance;
    
/** Unit system under which distances are calculated.
 @since 100.3
 */
@property (nonatomic, assign, readwrite) AGSUnitSystem unitSystem;
    
/** Block that is invoked when distance components become available or change, for instance if the start/end locations are changed.
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100.3
 */
@property (nullable, nonatomic, copy, readwrite) void (^measurementChangedHandler)(AGSDistance *directDistance, AGSDistance *horizontalDistance, AGSDistance *verticalDistance);

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
