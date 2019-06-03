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

/** @file AGSGeoprocessingUnknownParameter.h */ //Required for Globals API doc

/** @brief A geoprocessing parameter that is not currently supported
 
 Instances of this class represent a parameter whose type is not known and is currently not supported.
 
 @since 100
 */
@interface AGSGeoprocessingUnknownParameter : AGSGeoprocessingParameter
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

NS_ASSUME_NONNULL_END
@end
