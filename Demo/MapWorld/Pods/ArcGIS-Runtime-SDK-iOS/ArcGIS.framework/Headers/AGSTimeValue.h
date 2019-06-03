/*
 COPYRIGHT 2017 ESRI
 
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

#import "AGSObject.h"

/** @file AGSTimeValue.h */ //Required for Globals API doc

/** @brief Defines a period of time
 
 Instances of this class define a period of time.
 
 @since 100.2
 */
@interface AGSTimeValue : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with the specified time period
 @param duration representing the amount of time
 @param unit for the duration
 @return Initialized time value
 @since 100.2
 */
-(instancetype)initWithDuration:(double)duration unit:(AGSTimeUnit)unit;

/** Initialize this object with the specified time period
 @param duration representing the amount of time
 @param unit for the duration
 @return Initialized time value
 @since 100.2
 */
+(instancetype)timeValueWithDuration:(double)duration unit:(AGSTimeUnit)unit;

#pragma mark -
#pragma mark properties

/** The amount of time in the specified `#unit`
 @since 100.2
 */
@property (nonatomic, assign, readonly) double duration;


/** The unit of time used to specify the `#duration`
 @since 100.2
 */
@property (nonatomic, assign, readonly) AGSTimeUnit unit;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
