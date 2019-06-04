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

/** @file AGSGeoprocessingMultiValue.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter containing multiple values
 
 Instances of this class represent a parameter that contains multiple values. It can be used as input to a geoprocessing job or returned as the result of the job.
 
 @since 100
 */
@interface AGSGeoprocessingMultiValue : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this parameter to contain values of the specified type
 @param parameterType type of values contained by the parameter
 @since 100
 */
-(instancetype)initWithParameterType:(AGSGeoprocessingParameterType)parameterType;

/** Initialize this parameter to contain values of the specified type
 @param parameterType type of values contained by the parameter
 @since 100
 */
+(instancetype)geoprocessingMultiValueWithParameterType:(AGSGeoprocessingParameterType)parameterType;

/** Initialize this parameter to contain values of the specified type
 @param parameterType type of values contained by the parameter
 @param values of the specified type
 @since 100
 */
-(instancetype)initWithParameterType:(AGSGeoprocessingParameterType)parameterType values:(NSArray<AGSGeoprocessingParameter*>*)values;

/** Initialize this parameter to contain values of the specified type
 @param parameterType type of values contained by the parameter
 @param values of the specified type
 @since 100
 */
+(instancetype)geoprocessingMultiValueWithParameterType:(AGSGeoprocessingParameterType)parameterType values:(NSArray<AGSGeoprocessingParameter*>*)values;

#pragma mark -
#pragma mark properties

/** Type of values contained by the parameter in `#values`
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingParameterType valueParameterType;

/** Values contained by this parameter of the type specified by `#valueParameterType`
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSGeoprocessingParameter*> *values;

NS_ASSUME_NONNULL_END
@end
