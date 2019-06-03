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

/** @file AGSStandardDeviationStretchParameters.h */ //Required for Globals API doc

/** @brief Parameters to create a stretch renderer based on a standard deviation factor
 
 Instances of this class represent parameters that can be used to create an `AGSStretchRenderer` that applies a linear stretch between the values defined by the standard deviation (n) value
 
 @since 100
 */
@interface AGSStandardDeviationStretchParameters : AGSStretchParameters

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the parameters with the provided standard deviation factor
 @param factor The number of standard deviations that defines the range of pixel values for the stretch histogram
 @return Initialized parameters
 @since 100
 */
-(instancetype)initWithFactor:(double)factor;

/** Initialize the parameters with the provided standard deviation factor
 @param factor The number of standard deviations that defines the range of pixel values for the stretch histogram
 @return Initialized parameters
 @since 100
 */
+(instancetype)standardDeviationStretchParameterstWithFactor:(double)factor;

#pragma mark -
#pragma mark properties

/** The number of standard deviations that defines the range of pixel values for the stretch histogram
 @since 100
 */
@property (nonatomic, assign, readonly) double factor;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

