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

/** @file AGSPercentClipStretchParameters.h */ //Required for Globals API doc

/** @brief Parameters to create a stretch renderer based on percentile min/max pixel values
 
 Instances of this class represent parameters that can be used to create an `AGSStretchRenderer` that applies a linear stretch between the percentile minimum and maximum pixel values defined
 
 
 @since 100
 */
@interface AGSPercentClipStretchParameters : AGSStretchParameters

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the parameters with the provided values
 @param min Percentile cutoff below which values in the raster dataset are to be clipped. Valid values are 0 - 100.
 @param max Percentile cutoff above which pixel values in the raster dataset are to be clipped. Valid values are 0 - 100.
 @return Initialized parameters
 @since 100
 */
-(instancetype)initWithMin:(double)min max:(double)max;

/** Initialize the parameters with the provided values
 @param min Percentile cutoff below which values in the raster dataset are to be clipped. Valid values are 0 - 100.
 @param max Percentile cutoff above which pixel values in the raster dataset are to be clipped. Valid values are 0 - 100.
 @return Initialized parameters
 @since 100
 */
+(instancetype)percentClipStretchParametersWithMin:(double)min max:(double)max;

#pragma mark -
#pragma mark properties

/** Percentile cutoff above which pixel values in the raster dataset are to be clipped. Valid values are 0 - 100.
 
 For example: Consider an 8-bit raster containing pixel values in the range from 33 to 206, and you've defined a percent clip minimum and maximum of 2. If 2 percent at the low end is values 33 to 45 and 2 percent at the high end is 198 to 206, the histogram will be redistributed to spread the values from 0 to 255, all values 33 to 45 becoming 0 and 198 to 206 becoming 255, with all other values spread in between.
 @since 100
 */
@property (nonatomic, assign, readonly) double max;

/** Percentile cutoff below which values in the raster dataset are to be clipped. Valid values are 0 - 100. 
 
 For example: Consider an 8-bit raster containing pixel values in the range from 33 to 206, and you've defined a percent clip minimum and maximum of 2. If 2 percent at the low end is values 33 to 45 and 2 percent at the high end is 198 to 206, the histogram will be redistributed to spread the values from 0 to 255, all values 33 to 45 becoming 0 and 198 to 206 becoming 255, with all other values spread in between.
 @since 100
 */
@property (nonatomic, assign, readonly) double min;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

