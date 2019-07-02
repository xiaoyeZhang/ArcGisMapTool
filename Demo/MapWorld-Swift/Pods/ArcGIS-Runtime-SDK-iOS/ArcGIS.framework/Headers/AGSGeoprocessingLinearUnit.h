/*
 COPYRIGHT 2016 ESRI
 
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

#import "AGSGeoprocessingParameter.h"
#import "AGSLinearUnit.h"

/** @file AGSGeoprocessingLinearUnit.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter for linear distances
 
 Instances of this class represent a parameter for linear distances that can be used as input to a geoprocessing job or returned as the result of the job.
 
 @since 100
 */
@interface AGSGeoprocessingLinearUnit : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geoprocessingLinearUnit;

/** Intialize this parameter with the given distance value
 @param distance value
 @since 100
 */
-(instancetype)initWithDistance:(double)distance;

/** Intialize this parameter with the given distance value
 @param distance value
 @since 100
 */
+(instancetype)geoprocessingLinearUnitWithDistance:(double)distance;

/** Intialize this parameter with the given distance value
 @param distance value
 @param geoprocessingLinearUnit specifying unit of measurement for the distance value
 @since 100
 */
-(instancetype)initWithDistance:(double)distance geoprocessingLinearUnit:(AGSGeoprocessingLinearUnits)geoprocessingLinearUnit;

/** Intialize this parameter with the given distance value
 @param distance value
 @param geoprocessingUnit specifying unit of measurement for the distance value
 @since 100
 */
+(instancetype)geoprocessingLinearUnitWithDistance:(double)distance geoprocessingUnit:(AGSGeoprocessingLinearUnits)geoprocessingUnit;

/** Intialize this parameter with the given distance value
 @param distance value
 @param linearUnit specifying unit of measurement for the distance value
 @since 100
 */
-(instancetype)initWithDistance:(double)distance linearUnit:(AGSLinearUnit *)linearUnit;

/** Intialize this parameter with the given distance value
 @param distance value
 @param linearUnit specifying unit of measurement for the distance value
 @since 100
 */
+(instancetype)geoprocessingLinearUnitWithDistance:(double)distance linearUnit:(AGSLinearUnit*)linearUnit;

/** Intialize this parameter with the given distance value
 @param distance value
 @param unitID specifying unit of measurement for the distance value
 @since 100
 */
-(instancetype)initWithDistance:(double)distance unitID:(AGSLinearUnitID)unitID;

/** Intialize this parameter with the given distance value
 @param distance value
 @param unitID specifying unit of measurement for the distance value
 @since 100
 */
+(instancetype)geoprocessingLinearUnitWithDistance:(double)distance unitID:(AGSLinearUnitID)unitID;

#pragma mark -
#pragma mark properties

/** The distance value for this parameter
 @since 100
 */
@property (nonatomic, assign, readwrite) double distance;

/** The units of measurement for the distance value
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSGeoprocessingLinearUnits geoprocessingLinearUnit;

#pragma mark -
#pragma mark methods

/** The units of measurement for the distance value
 @since 100
 */
-(AGSLinearUnit*)linearUnit;

NS_ASSUME_NONNULL_END
@end
