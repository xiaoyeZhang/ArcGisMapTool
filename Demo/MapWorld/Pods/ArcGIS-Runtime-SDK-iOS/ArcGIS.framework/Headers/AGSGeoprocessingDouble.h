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

/** @file AGSGeoprocessingDouble.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter for double data type
 
 Instances of this class represent a parameter for double data type that can be used as input to a geoprocessing job or returned as the result of the job.
 
 @since 100
 */
@interface AGSGeoprocessingDouble : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geoprocessingDouble;

/** Initialize the parameter with the given value
 @param value for the parameter
 @since 100
 */
-(instancetype)initWithValue:(double)value;

/** Initialize the parameter with the given value
 @param value for the parameter
 @since 100
 */
+(instancetype)geoprocessingDoubleWithValue:(double)value;

#pragma mark -
#pragma mark properties

/** Value of the parameter
 @since 100
 */
@property (nonatomic, assign, readwrite) double value;

NS_ASSUME_NONNULL_END
@end
