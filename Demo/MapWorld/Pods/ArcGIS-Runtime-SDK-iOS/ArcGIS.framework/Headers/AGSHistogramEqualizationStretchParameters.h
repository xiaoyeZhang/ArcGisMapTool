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

#import "AGSStretchParameters.h"

/** @file AGSHistogramEqualizationStretchParameters.h */ //Required for Globals API doc

/** @brief Parameters to create a stretch renderer based on histogram equalization
 
 Instances of this class represent parameters that can be used to create an `AGSStretchRenderer` that is useful when there are a lot of pixel values that are closely grouped together
 
 @since 100
 */
@interface AGSHistogramEqualizationStretchParameters : AGSStretchParameters

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)histogramEqualizationStretchParameters;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

