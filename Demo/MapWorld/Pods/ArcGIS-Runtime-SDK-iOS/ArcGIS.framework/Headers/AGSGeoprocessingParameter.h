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

/** @file AGSGeoprocessingParameter.h */ //Required for Globals API doc

/** @brief A base class for geoprocessing parameters
 
 A base class for parameters that can be used as inputs or returned as results of a geoprocessing job.
 
 @since 100
 */
@interface AGSGeoprocessingParameter : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)geoprocessingParameter;

#pragma mark -
#pragma mark properties

/** The data type of the parameter.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingParameterType type;

NS_ASSUME_NONNULL_END
@end
