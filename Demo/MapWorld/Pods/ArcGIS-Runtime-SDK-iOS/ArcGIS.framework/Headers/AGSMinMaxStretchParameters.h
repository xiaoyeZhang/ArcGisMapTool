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

/** @file AGSMinMaxStretchParameters.h */ //Required for Globals API doc

/** @brief Parameters to create a stretch renderer based on output min/max pixel values.
 
 Instances of this class represent parameters that can be used to create an `AGSStretchRenderer` that applies a linear stretch based on the output minimum and output maximum pixel values which are used as the endpoints for the histogram
 

 @since 100
 */
@interface AGSMinMaxStretchParameters : AGSStretchParameters

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the parameters with the provided values
 @param minValues The minimum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset lesser than this value will be pushed to the minimum end of the histogram.
 @param maxValues The maximum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset greater than this value will be pushed to the maximum end of the histogram.
 @return Initialized parameters
 @since 100
 */
-(instancetype)initWithMinValues:(NSArray<NSNumber*> *)minValues maxValues:(NSArray<NSNumber*> *)maxValues;

/** Initialize the parameters with the provided values
 @param minValues The minimum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset lesser than this value will be pushed to the maximum end of the histogram.
 @param maxValues The maximum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset greater than this value will be pushed to the maximum end of the histogram.
 @return Initialized parameters
 @since 100
 */
+(instancetype)minMaxStretchParametersWithMinValues:(NSArray<NSNumber*> *)minValues maxValues:(NSArray<NSNumber*> *)maxValues;

#pragma mark -
#pragma mark properties

/** The maximum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset greater than this value will be pushed to the maximum end of the histogram.
 
 For example: Consider an 8-bit raster containing pixel values in the range from 33 to 206, and you've defined a max of 50 and min of 180. The histogram will be redistributed to spread the values from 0 to 255, all values 33 to 50 becoming 0 and 180 to 206 becoming 255, with all other values spread in between.
 
 The array must contain a max value for each band in the raster, the 0th element for the 0th band, and so on.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *maxValues;

/** The minimum pixel value which serves as an endpoint for the histogram used for the stretch. All pixel values in the dataset lesser than this value will be pushed to the maximum end of the histogram.
 
 For example: Consider an 8-bit raster containing pixel values in the range from 33 to 206, and you've defined a max of 50 and min of 180. The histogram will be redistributed to spread the values from 0 to 255, all values 33 to 50 becoming 0 and 180 to 206 becoming 255, with all other values spread in between.
 
 The array must contain a min value for each band in the raster, the 0th element for the 0th band, and so on.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *minValues;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

